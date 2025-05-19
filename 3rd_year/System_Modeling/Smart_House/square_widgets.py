from PySide6.QtGui import QColor, QPainter
from PySide6.QtWidgets import QWidget, QPushButton
import matplotlib.cm as cm
import matplotlib.colors as mcolors
        
class WallSquare(QWidget):
    def __init__(self):
        super().__init__()
        self.setFixedSize(30, 30)
    
    def paintEvent(self, event):
        painter = QPainter(self)
        painter.fillRect(self.rect(), 'black')

class ObjectSquare(QPushButton):
    def __init__(self, name, state=0):
        super().__init__(text=name[-1])
        self.name = name
        self.state = state
        self.type = name[:-2]
        self.setProperty("class", self.type)
    
    def change_state(self):
        self.state ^= 1
    
class DoorSquare(ObjectSquare):
    def __init__(self, name, state=0):
        super().__init__(name, state)
        self.bandwidth = 1

class WindowSquare(ObjectSquare):
    def __init__(self, name, state=0):
        super().__init__(name, state)
        self.bandwidth = 0.8

class UnregHeaterSquare(ObjectSquare):
    def __init__(self, name, power, state=0):
        super().__init__(name, state)
        self.power = power

class RegHeaterSquare(ObjectSquare):
    def __init__(self, name, power=0, state=0):
        super().__init__(name, state)
        self.power = power
    
    def change_power(self, power):
        self.power = power

class ConditionerSquare(RegHeaterSquare):
    def __init__(self, name, power=0, state=0):
        super().__init__(name, power, state)
        self.power = -power

    def change_power(self, power):
        self.power = -power


class TemperatureSquare(QWidget):
    def __init__(self, temp=0):
        super().__init__()
        self.temperature = temp
        self.setFixedSize(30, 30)

    def set_temperature(self, temp):
        self.temperature = temp
        self.update()  # Перерисовать квадрат при изменении значения

    def paintEvent(self, event):
        painter = QPainter(self)
        color = self.temperature_to_color(self.temperature)
        painter.fillRect(self.rect(), color)

    def temperature_to_color(self, temp, min_temp=-50, max_temp=50):
        # Ограничиваем диапазон
        temp = max(min_temp, min(temp, max_temp))

        # Нормализация в [0, 1]
        norm = mcolors.Normalize(vmin=min_temp, vmax=max_temp)
        cmap = cm.get_cmap('coolwarm')

        # Получаем цвет из colormap в формате RGBA [0..1]
        rgba = cmap(norm(temp))

        # Переводим в QColor с компонентами от 0 до 255
        r = int(rgba[0] * 255)
        g = int(rgba[1] * 255)
        b = int(rgba[2] * 255)

        return QColor(r, g, b)