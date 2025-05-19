from PySide6.QtWidgets import QApplication, QWidget, QVBoxLayout, QLabel, QDialog
from PySide6.QtCore import Qt, QTimer, QDateTime
import form
import pyqtgraph as pg
from square_widgets import WallSquare, ObjectSquare, DoorSquare, WindowSquare, RegHeaterSquare, UnregHeaterSquare, ConditionerSquare, TemperatureSquare


class Smart_House(QWidget, form.Ui_Main):
    def __init__(self):
        super(Smart_House, self).__init__()
        self.setupUi(self)

        self.timer = QTimer()
        self.timer.timeout.connect(self.update_ui)
        self.timer.start(100)  # Обновление каждую 0.1 с (100 мс)

        self.width = 16
        self.height = 7
        self.heat_transfer_coef = 0.1
        self.outside_temperature = 0
        self.avg_temperature = 20
        self.plan_temperature = 0
        self.temp_outside_spin.setValue(self.outside_temperature)
        self.avg_temp_spin.setValue(self.avg_temperature)
        self.current_mode = "Стандартный режим"
        self.current_regulator = 'Реле'
        self.integral = 0

        self.walls = []
        ### Добавляем горизонтальные стены
        self.walls += [(0, i) for i in range(0, self.width)] + [(self.height - 1, i) for i in range(0, self.width)] + [(3, i) for i in range(9, self.width)] 
        ### Добавляем вертикальные стены
        self.walls += [(i, 0) for i in range(0, self.height)] + [(i, 4) for i in range(0, self.height + 1)] + [(i, 9) for i in range(0, 3 + 1)] + [(i, 13) for i in range(0, 3 + 1)] + [(i, self.width - 1) for i in range(0, self.height)]
        
        self.objects = {
            (3, 0): "door_1",
            (3, 4): "door_2",
            (3, 11): "door_3",
            (3, 14): "door_4",
            (6, 2): "window_1",
            (0, 6): "window_2",
            (0, 11): "regHeater_1",
            (1, 15): "regHeater_2",
            (0, 2): "unregHeater_1",
            (6, 6): "unregHeater_2",
            (6, 14): "conditioner_1"
        }

        ### Исключаем из стен элементы
        self.walls = list(set(self.walls) - set(self.objects.keys()))

        self.squares = []
        self.squaresLayout.setContentsMargins(0, 0, 0, 0)
        self.squaresLayout.setSpacing(0)
        self.buttons = []
        for y in range(self.height):
            row = []
            for x in range(self.width):
                if (y, x) in self.objects.keys():
                    widget = ObjectSquare(self.objects[(y, x)])
                    match widget.type:
                        case "door":
                            widget = DoorSquare(widget.name)
                        case "window":
                            widget = WindowSquare(widget.name)
                        case "regHeater":
                            widget = RegHeaterSquare(widget.name)
                        case "unregHeater":
                            widget = UnregHeaterSquare(widget.name, 50)
                        case "conditioner": 
                            widget = ConditionerSquare(widget.name)
                    
                    self.buttons.append(widget)
                elif (y, x) in self.walls:
                    widget = WallSquare()
                else:
                    widget = TemperatureSquare(self.avg_temperature)
                
                row.append(widget)
                self.squaresLayout.addWidget(widget, y, x)
            self.squares.append(row)

        self.plot_dialog = None

        ### Подключение слотов и сигналов
        self.regHeater_1_slider.valueChanged.connect(self.change_regHeater_1_power)
        self.regHeater_2_slider.valueChanged.connect(self.change_regHeater_2_power)
        self.conditioner_slider.valueChanged.connect(self.change_conditioner_power)
        self.temp_outside_spin.valueChanged.connect(self.change_outside_temperature)
        self.plan_temp_spin.valueChanged.connect(self.change_plan_temperature)
        self.choose_regulator.currentTextChanged.connect(self.change_current_regulator)
        self.start_regulation_btn.clicked.connect(self.start_regulation)
        self.stop_regulation_btn.clicked.connect(self.stop_regulation)
        self.open_graph_btn.clicked.connect(self.open_graph)
        for btn in self.buttons:
            btn.clicked.connect(lambda checked, b=btn: self.change_state(b))
    
    def update_ui(self):
        self.update_temperatures()
        self.avg_temp_spin.setValue(self.avg_temperature)
        self.send_data()
        match self.current_mode:
            case 'Реле':
                self.rele_regulation()

            case 'П-регулятор':
                self.p_regulation()

            case 'ПИ-регулятор':
                self.pi_regulation()

        self.mode_label.setText("Текущий режим работы: "+ self.current_mode)

    def update_temperatures(self):
        sum_temperature = 0
        count = 0
        for y in range(self.height):
            for x in range(self.width):
                if not isinstance(self.squares[y][x], TemperatureSquare):
                    continue
                
                sum_temperature += self.squares[y][x].temperature
                count += 1
                # Соседние температуры(верх, низ, лево, право)
                neighbors_temp = []
                if y > 0:  # верхний сосед
                    neighbor_temp = self.check_neighbor(self.squares[y - 1][x], y - 1, x, -1, 0)
                    if neighbor_temp != 'void':
                        neighbors_temp.append(neighbor_temp)

                if y < self.height - 1 :  # нижний сосед
                    neighbor_temp = self.check_neighbor(self.squares[y + 1][x], y + 1, x, 1, 0)
                    if neighbor_temp != 'void':
                        neighbors_temp.append(neighbor_temp)

                if x > 0:  # левый сосед
                    neighbor_temp = self.check_neighbor(self.squares[y][x - 1], y, x - 1, 0, -1)
                    if neighbor_temp != 'void':
                        neighbors_temp.append(neighbor_temp)

                if x < self.width - 1:  # правый сосед
                    neighbor_temp = self.check_neighbor(self.squares[y][x + 1], y, x + 1, 0, 1)
                    if neighbor_temp != 'void':
                        neighbors_temp.append(neighbor_temp)
                
                if neighbors_temp:
                    new_temp = self.squares[y][x].temperature - self.heat_transfer_coef * (self.squares[y][x].temperature * len(neighbors_temp) - sum(neighbors_temp))
                    self.squares[y][x].set_temperature(new_temp)
        self.avg_temperature = sum_temperature / count
    
    def send_data(self):
        if self.plot_dialog and self.plot_dialog.isVisible():
            current_time = QDateTime.currentDateTime()
            self.plot_dialog.add_data_point(current_time, self.avg_temperature)

    def check_neighbor(self, neighbor, y, x, next_y, next_x):
        neighbor_temp = 0
        if isinstance(neighbor, (DoorSquare, WindowSquare)) and neighbor.state:
            if (x == 0 or x == self.width - 1 or y == 0 or y == self.height - 1):
                # Если находится на границах дома (значит выход на улицу)
                neighbor_temp = self.outside_temperature * neighbor.bandwidth
            else:
                neighbor_temp = self.squares[y + next_y][x + next_x].temperature * neighbor.bandwidth
                            
        elif isinstance(neighbor, (UnregHeaterSquare, RegHeaterSquare, ConditionerSquare)) and neighbor.state:
            neighbor_temp = neighbor.power * 1.5

        elif isinstance(neighbor, TemperatureSquare):
            neighbor_temp = neighbor.temperature
        
        else:
            return 'void'

        return neighbor_temp

    def rele_regulation(self):
        heaters = []
        conditioner_btn = ConditionerSquare('plain')
        for btn in self.buttons:
            if btn.type == 'unregHeater' or btn.type == 'regHeater':
                heaters.append(btn)
            if btn.name == 'conditioner_1':
                conditioner_btn = btn
        E = self.avg_temperature - self.plan_temperature

        if E > 0:
            E = self.avg_temperature - self.plan_temperature
            for heater in heaters:
                if heater.state:
                    heater.click()
            if not conditioner_btn.state:
                conditioner_btn.click()
            self.conditioner_slider.setValue(100)
        else:
            for heater in heaters:
                if not heater.state:
                    heater.click()
            self.regHeater_1_slider.setValue(100)
            self.regHeater_2_slider.setValue(100)
            if conditioner_btn.state:
                conditioner_btn.click()
    
    def p_regulation(self):
        heaters = []
        conditioner_btn = ConditionerSquare('plain')
        for btn in self.buttons:
            if btn.type == 'unregHeater' or btn.type == 'regHeater':
                heaters.append(btn)
            if btn.name == 'conditioner_1':
                conditioner_btn = btn
        K = 0.05
        E = self.plan_temperature - self.avg_temperature
        Z = K * E

        if E > 0:
            for heater in heaters:
                if not heater.state:
                    heater.click()
            self.conditioner_slider.setValue(0)
            self.regHeater_1_slider.setValue(100 * Z)
            self.regHeater_2_slider.setValue(100 * Z)
            if conditioner_btn.state:
                conditioner_btn.click()
        else:
            for heater in heaters:
                if heater.state:
                    heater.click()
            self.regHeater_1_slider.setValue(0)
            self.regHeater_2_slider.setValue(0)
            
    def pi_regulation(self):
        heaters = []
        conditioner_btn = ConditionerSquare('plain')
        for btn in self.buttons:
            if btn.type == 'unregHeater' or btn.type == 'regHeater':
                heaters.append(btn)
            if btn.name == 'conditioner_1':
                conditioner_btn = btn
        K1 = 0.5
        K2 = 0.3
        E = self.plan_temperature - self.avg_temperature
        self.integral += E
        Z = K1 * E + K2 * self.integral

        print(Z)
        if Z < 0:
            Z = 1
        for heater in heaters:
            if not heater.state:
                heater.click()
        self.conditioner_slider.setValue(0)
        self.regHeater_1_slider.setValue(Z)
        self.regHeater_2_slider.setValue(Z)
        if conditioner_btn.state:
            conditioner_btn.click()
       
    def change_state(self, btn):
        btn.change_state()
        for label in self.widget.findChildren(QLabel, btn.name + "_state"):
            if btn.state == 0:
                label.setStyleSheet("background-color: red")
            else:
                label.setStyleSheet("background-color: green")
    
    def change_regHeater_1_power(self):
        for btn in self.buttons:
            if btn.name == "regHeater_1":
                btn.change_power(self.regHeater_1_slider.value())
                break
        
    def change_regHeater_2_power(self):
        for btn in self.buttons:
            if btn.name == "regHeater_2":
                btn.change_power(self.regHeater_2_slider.value())
                break
    
    def change_conditioner_power(self):
        for btn in self.buttons:
            if btn.name == "conditioner_1":
                btn.change_power(self.conditioner_slider.value())
                break
    
    def change_outside_temperature(self):
        self.outside_temperature = self.temp_outside_spin.value()

    def change_plan_temperature(self):
        self.plan_temperature = self.plan_temp_spin.value()

    def change_current_regulator(self):
        self.current_regulator = self.choose_regulator.currentText()

    def start_regulation(self):
        self.current_mode = self.current_regulator
        self.stop_regulation_btn.setEnabled(True)
        self.open_graph_btn.setEnabled(True)
    
    def stop_regulation(self):
        self.current_mode = "Стандартный режим"
        for btn in self.buttons:
            if btn.state:
                btn.click()
        self.regHeater_1_slider.setValue(0)
        self.regHeater_2_slider.setValue(0)
        self.conditioner_slider.setValue(0)

        self.integral = 0
        self.plot_dialog = None
        self.stop_regulation_btn.setEnabled(False)
        self.open_graph_btn.setEnabled(False)
    
    def open_graph(self):
        if self.plot_dialog is None or not self.plot_dialog.isVisible():
            self.plot_dialog = RealTimePlot(self)
            self.plot_dialog.plan_temperature = self.plan_temperature
            self.plot_dialog.show()

class RealTimePlot(QDialog):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.setWindowTitle("График изменения температуры")
        self.setGeometry(100, 100, 800, 600)

        self.plot_widget = pg.PlotWidget()
        self.plot_widget.setBackground('w')
        self.plot_widget.setLabel('left', 'Температура')
        self.plot_widget.setLabel('bottom', 'Время (сек)')
        self.plot_widget.showGrid(x=True, y=True)
        self.plot_widget.addLegend()  # Добавляем легенду

        self.plot_curve = self.plot_widget.plot(pen=pg.mkPen('r', width=2), name="Текущая температура (°C)", style=Qt.DashLine)
        self.plan_curve = self.plot_widget.plot(pen=pg.mkPen('g', width=2), name="Плановая температура (°C)")

        self.time_data = []
        self.temp_data = []
        self.plan_temperature = 0
        # self.max_points = 100  # Лимит точек на графике

        layout = QVBoxLayout()
        layout.addWidget(self.plot_widget)
        self.setLayout(layout)
    
    def add_data_point(self, timestamp, temperature):
        """Добавляет новую точку на график"""
        self.time_data.append(timestamp)
        self.temp_data.append(temperature)
        
        # Ограничиваем количество точек
        # if len(self.time_data) > self.max_points:
        #     self.time_data = self.time_data[-self.max_points:]
        #     self.temp_data = self.temp_data[-self.max_points:]
        
        # Преобразуем время в секунды для отображения
        time_seconds = [(t.toMSecsSinceEpoch() - self.time_data[0].toMSecsSinceEpoch()) / 1000.0
                       for t in self.time_data]
        
        self.plot_curve.setData(time_seconds, self.temp_data)
        self.plan_curve.setData(time_seconds, [self.plan_temperature] * len(time_seconds))
        # Автоматическое масштабирование
        self.plot_widget.autoRange()

if __name__ == "__main__":
    app = QApplication([])
    QApplication.setStyle("Fusion")
    house = Smart_House()
    house.show()
    app.exec()