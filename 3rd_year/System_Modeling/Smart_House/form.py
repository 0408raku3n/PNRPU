# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'form.ui'
##
## Created by: Qt User Interface Compiler version 6.9.0
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide6.QtCore import (QCoreApplication, QDate, QDateTime, QLocale,
    QMetaObject, QObject, QPoint, QRect,
    QSize, QTime, QUrl, Qt)
from PySide6.QtGui import (QBrush, QColor, QConicalGradient, QCursor,
    QFont, QFontDatabase, QGradient, QIcon,
    QImage, QKeySequence, QLinearGradient, QPainter,
    QPalette, QPixmap, QRadialGradient, QTransform)
from PySide6.QtWidgets import (QAbstractSpinBox, QApplication, QComboBox, QDoubleSpinBox,
    QFrame, QGridLayout, QHBoxLayout, QLCDNumber,
    QLabel, QLayout, QPushButton, QSizePolicy,
    QSlider, QSpinBox, QVBoxLayout, QWidget)

class Ui_Main(object):
    def setupUi(self, Main):
        if not Main.objectName():
            Main.setObjectName(u"Main")
        Main.resize(800, 800)
        Main.setFocusPolicy(Qt.NoFocus)
        Main.setAutoFillBackground(False)
        Main.setStyleSheet(u"Main {\n"
"background-color: rgb(175, 255, 253);\n"
"}")
        self.widget = QWidget(Main)
        self.widget.setObjectName(u"widget")
        self.widget.setGeometry(QRect(0, 0, 800, 800))
        self.widget.setFocusPolicy(Qt.StrongFocus)
        self.widget.setAutoFillBackground(False)
        self.widget.setStyleSheet(u"QWidget {\n"
"background-color: rgb(175, 255, 253);\n"
"}\n"
"QFrame.panel {\n"
"border: 2px solid black;\n"
"}\n"
"QPushButton {\n"
"border-radius: 1px;\n"
"font: bold 10pt \"Roboto\";\n"
"color: rgb(0, 0, 0);\n"
"min-width: 30px;\n"
"max-width: 30px;\n"
"min-height: 30px;\n"
"max-height: 30px;\n"
"}\n"
"QPushButton.door {\n"
"background-color: rgb(160, 43, 31);\n"
"}\n"
"QPushButton.door:hover {\n"
"background-color: rgb(130, 43, 31);\n"
"}\n"
"QPushButton.window {\n"
"background-color: rgb(85, 255, 255);\n"
"}\n"
"QPushButton.window:hover {\n"
"background-color: rgb(85, 225, 255);\n"
"}\n"
"QPushButton.regHeater {\n"
"background-color: rgb(255, 0, 0);\n"
"}\n"
"QPushButton.regHeater:hover {\n"
"background-color: rgb(220, 0, 0);\n"
"}\n"
"QPushButton.unregHeater {\n"
"background-color: rgb(255, 255, 76);\n"
"}\n"
"QPushButton.unregHeater:hover {\n"
"background-color: rgb(255, 235, 76);\n"
"}\n"
"QPushButton.conditioner {\n"
"background-color: rgb(103, 139, 255);\n"
"}\n"
"QPushButton.conditioner:hover {\n"
""
                        "background-color: rgb(84, 115, 255);\n"
"}")
        self.regulatorsFrame = QFrame(self.widget)
        self.regulatorsFrame.setObjectName(u"regulatorsFrame")
        self.regulatorsFrame.setGeometry(QRect(40, 130, 281, 241))
        self.regulatorsFrame.setStyleSheet(u"QLabel {\n"
"font: bold 12pt \"Roboto\";\n"
"color: rgb(0, 0, 0);\n"
"}\n"
"QSlider::groove {\n"
"height: 6px;\n"
"background: #ccc;\n"
"border-radius: 2px;\n"
"}\n"
"QSlider::handle {\n"
"width: 6px;\n"
"height: 20px;\n"
"background-color: rgb(0, 0, 0);\n"
"margin: -5px 0; \n"
"}\n"
"QLCDNumber {\n"
"color: black;\n"
"border: 2px solid gray;\n"
"border-radius: 5px;\n"
"}")
        self.regulatorsFrame.setFrameShape(QFrame.NoFrame)
        self.regulatorsFrame.setLineWidth(3)
        self.verticalLayout_4 = QVBoxLayout(self.regulatorsFrame)
        self.verticalLayout_4.setObjectName(u"verticalLayout_4")
        self.verticalLayout = QVBoxLayout()
        self.verticalLayout.setObjectName(u"verticalLayout")
        self.label_2 = QLabel(self.regulatorsFrame)
        self.label_2.setObjectName(u"label_2")

        self.verticalLayout.addWidget(self.label_2)

        self.horizontalLayout = QHBoxLayout()
        self.horizontalLayout.setObjectName(u"horizontalLayout")
        self.regHeater_1_slider = QSlider(self.regulatorsFrame)
        self.regHeater_1_slider.setObjectName(u"regHeater_1_slider")
        self.regHeater_1_slider.setMaximum(100)
        self.regHeater_1_slider.setOrientation(Qt.Horizontal)

        self.horizontalLayout.addWidget(self.regHeater_1_slider)

        self.regHeater_1_num = QLCDNumber(self.regulatorsFrame)
        self.regHeater_1_num.setObjectName(u"regHeater_1_num")

        self.horizontalLayout.addWidget(self.regHeater_1_num)


        self.verticalLayout.addLayout(self.horizontalLayout)


        self.verticalLayout_4.addLayout(self.verticalLayout)

        self.verticalLayout_2 = QVBoxLayout()
        self.verticalLayout_2.setObjectName(u"verticalLayout_2")
        self.label_3 = QLabel(self.regulatorsFrame)
        self.label_3.setObjectName(u"label_3")

        self.verticalLayout_2.addWidget(self.label_3)

        self.horizontalLayout_2 = QHBoxLayout()
        self.horizontalLayout_2.setObjectName(u"horizontalLayout_2")
        self.regHeater_2_slider = QSlider(self.regulatorsFrame)
        self.regHeater_2_slider.setObjectName(u"regHeater_2_slider")
        self.regHeater_2_slider.setMaximum(100)
        self.regHeater_2_slider.setOrientation(Qt.Horizontal)

        self.horizontalLayout_2.addWidget(self.regHeater_2_slider)

        self.regHeater_2_num = QLCDNumber(self.regulatorsFrame)
        self.regHeater_2_num.setObjectName(u"regHeater_2_num")

        self.horizontalLayout_2.addWidget(self.regHeater_2_num)


        self.verticalLayout_2.addLayout(self.horizontalLayout_2)


        self.verticalLayout_4.addLayout(self.verticalLayout_2)

        self.verticalLayout_3 = QVBoxLayout()
        self.verticalLayout_3.setObjectName(u"verticalLayout_3")
        self.label_4 = QLabel(self.regulatorsFrame)
        self.label_4.setObjectName(u"label_4")

        self.verticalLayout_3.addWidget(self.label_4)

        self.horizontalLayout_3 = QHBoxLayout()
        self.horizontalLayout_3.setObjectName(u"horizontalLayout_3")
        self.conditioner_slider = QSlider(self.regulatorsFrame)
        self.conditioner_slider.setObjectName(u"conditioner_slider")
        self.conditioner_slider.setMaximum(100)
        self.conditioner_slider.setOrientation(Qt.Horizontal)

        self.horizontalLayout_3.addWidget(self.conditioner_slider)

        self.conditioner_num = QLCDNumber(self.regulatorsFrame)
        self.conditioner_num.setObjectName(u"conditioner_num")

        self.horizontalLayout_3.addWidget(self.conditioner_num)


        self.verticalLayout_3.addLayout(self.horizontalLayout_3)


        self.verticalLayout_4.addLayout(self.verticalLayout_3)

        self.indicatorsFrame = QFrame(self.widget)
        self.indicatorsFrame.setObjectName(u"indicatorsFrame")
        self.indicatorsFrame.setGeometry(QRect(380, 50, 381, 191))
        self.indicatorsFrame.setStyleSheet(u"QLabel.state {\n"
"background-color: red;\n"
"color: rgb(0, 0, 0);\n"
"border-radius: 10px;  /* \u0438\u043b\u0438 50% */\n"
"min-width: 20px;\n"
"min-height: 20px;\n"
"max-width: 20px;\n"
"max-height: 20px;\n"
"}\n"
"QLabel.name {\n"
"font: bold 12pt \"Roboto\";\n"
"color: rgb(0, 0, 0);\n"
"}")
        self.indicatorsFrame.setFrameShape(QFrame.NoFrame)
        self.indicatorsFrame.setLineWidth(3)
        self.horizontalLayout_14 = QHBoxLayout(self.indicatorsFrame)
        self.horizontalLayout_14.setObjectName(u"horizontalLayout_14")
        self.horizontalLayout_14.setContentsMargins(5, -1, 5, -1)
        self.verticalLayout_5 = QVBoxLayout()
        self.verticalLayout_5.setObjectName(u"verticalLayout_5")
        self.horizontalLayout_15 = QHBoxLayout()
        self.horizontalLayout_15.setObjectName(u"horizontalLayout_15")
        self.door_1_label = QLabel(self.indicatorsFrame)
        self.door_1_label.setObjectName(u"door_1_label")
        self.door_1_label.setMinimumSize(QSize(0, 20))

        self.horizontalLayout_15.addWidget(self.door_1_label)

        self.door_1_state = QLabel(self.indicatorsFrame)
        self.door_1_state.setObjectName(u"door_1_state")

        self.horizontalLayout_15.addWidget(self.door_1_state)


        self.verticalLayout_5.addLayout(self.horizontalLayout_15)

        self.horizontalLayout_4 = QHBoxLayout()
        self.horizontalLayout_4.setObjectName(u"horizontalLayout_4")
        self.door_2_label = QLabel(self.indicatorsFrame)
        self.door_2_label.setObjectName(u"door_2_label")
        self.door_2_label.setMinimumSize(QSize(0, 20))

        self.horizontalLayout_4.addWidget(self.door_2_label)

        self.door_2_state = QLabel(self.indicatorsFrame)
        self.door_2_state.setObjectName(u"door_2_state")

        self.horizontalLayout_4.addWidget(self.door_2_state)


        self.verticalLayout_5.addLayout(self.horizontalLayout_4)

        self.horizontalLayout_5 = QHBoxLayout()
        self.horizontalLayout_5.setObjectName(u"horizontalLayout_5")
        self.door_3_label = QLabel(self.indicatorsFrame)
        self.door_3_label.setObjectName(u"door_3_label")
        self.door_3_label.setMinimumSize(QSize(0, 20))

        self.horizontalLayout_5.addWidget(self.door_3_label)

        self.door_3_state = QLabel(self.indicatorsFrame)
        self.door_3_state.setObjectName(u"door_3_state")

        self.horizontalLayout_5.addWidget(self.door_3_state)


        self.verticalLayout_5.addLayout(self.horizontalLayout_5)

        self.horizontalLayout_6 = QHBoxLayout()
        self.horizontalLayout_6.setObjectName(u"horizontalLayout_6")
        self.door_4_label = QLabel(self.indicatorsFrame)
        self.door_4_label.setObjectName(u"door_4_label")
        self.door_4_label.setMinimumSize(QSize(0, 20))

        self.horizontalLayout_6.addWidget(self.door_4_label)

        self.door_4_state = QLabel(self.indicatorsFrame)
        self.door_4_state.setObjectName(u"door_4_state")

        self.horizontalLayout_6.addWidget(self.door_4_state)


        self.verticalLayout_5.addLayout(self.horizontalLayout_6)

        self.horizontalLayout_7 = QHBoxLayout()
        self.horizontalLayout_7.setObjectName(u"horizontalLayout_7")
        self.window_1_label = QLabel(self.indicatorsFrame)
        self.window_1_label.setObjectName(u"window_1_label")
        self.window_1_label.setMinimumSize(QSize(0, 20))

        self.horizontalLayout_7.addWidget(self.window_1_label)

        self.window_1_state = QLabel(self.indicatorsFrame)
        self.window_1_state.setObjectName(u"window_1_state")

        self.horizontalLayout_7.addWidget(self.window_1_state)


        self.verticalLayout_5.addLayout(self.horizontalLayout_7)

        self.horizontalLayout_8 = QHBoxLayout()
        self.horizontalLayout_8.setObjectName(u"horizontalLayout_8")
        self.window_2_label = QLabel(self.indicatorsFrame)
        self.window_2_label.setObjectName(u"window_2_label")
        self.window_2_label.setMinimumSize(QSize(0, 20))

        self.horizontalLayout_8.addWidget(self.window_2_label)

        self.window_2_state = QLabel(self.indicatorsFrame)
        self.window_2_state.setObjectName(u"window_2_state")

        self.horizontalLayout_8.addWidget(self.window_2_state)


        self.verticalLayout_5.addLayout(self.horizontalLayout_8)


        self.horizontalLayout_14.addLayout(self.verticalLayout_5)

        self.verticalLayout_12 = QVBoxLayout()
        self.verticalLayout_12.setObjectName(u"verticalLayout_12")
        self.horizontalLayout_9 = QHBoxLayout()
        self.horizontalLayout_9.setObjectName(u"horizontalLayout_9")
        self.regHeater_1_label = QLabel(self.indicatorsFrame)
        self.regHeater_1_label.setObjectName(u"regHeater_1_label")
        self.regHeater_1_label.setMinimumSize(QSize(0, 20))

        self.horizontalLayout_9.addWidget(self.regHeater_1_label)

        self.regHeater_1_state = QLabel(self.indicatorsFrame)
        self.regHeater_1_state.setObjectName(u"regHeater_1_state")

        self.horizontalLayout_9.addWidget(self.regHeater_1_state)


        self.verticalLayout_12.addLayout(self.horizontalLayout_9)

        self.horizontalLayout_10 = QHBoxLayout()
        self.horizontalLayout_10.setObjectName(u"horizontalLayout_10")
        self.regHeater_2_label = QLabel(self.indicatorsFrame)
        self.regHeater_2_label.setObjectName(u"regHeater_2_label")
        self.regHeater_2_label.setMinimumSize(QSize(0, 20))

        self.horizontalLayout_10.addWidget(self.regHeater_2_label)

        self.regHeater_2_state = QLabel(self.indicatorsFrame)
        self.regHeater_2_state.setObjectName(u"regHeater_2_state")

        self.horizontalLayout_10.addWidget(self.regHeater_2_state)


        self.verticalLayout_12.addLayout(self.horizontalLayout_10)

        self.horizontalLayout_11 = QHBoxLayout()
        self.horizontalLayout_11.setObjectName(u"horizontalLayout_11")
        self.unregHeater_1_label = QLabel(self.indicatorsFrame)
        self.unregHeater_1_label.setObjectName(u"unregHeater_1_label")
        self.unregHeater_1_label.setMinimumSize(QSize(0, 20))

        self.horizontalLayout_11.addWidget(self.unregHeater_1_label)

        self.unregHeater_1_state = QLabel(self.indicatorsFrame)
        self.unregHeater_1_state.setObjectName(u"unregHeater_1_state")

        self.horizontalLayout_11.addWidget(self.unregHeater_1_state)


        self.verticalLayout_12.addLayout(self.horizontalLayout_11)

        self.horizontalLayout_12 = QHBoxLayout()
        self.horizontalLayout_12.setObjectName(u"horizontalLayout_12")
        self.unregHeater_2_label = QLabel(self.indicatorsFrame)
        self.unregHeater_2_label.setObjectName(u"unregHeater_2_label")
        self.unregHeater_2_label.setMinimumSize(QSize(0, 20))

        self.horizontalLayout_12.addWidget(self.unregHeater_2_label)

        self.unregHeater_2_state = QLabel(self.indicatorsFrame)
        self.unregHeater_2_state.setObjectName(u"unregHeater_2_state")

        self.horizontalLayout_12.addWidget(self.unregHeater_2_state)


        self.verticalLayout_12.addLayout(self.horizontalLayout_12)

        self.horizontalLayout_13 = QHBoxLayout()
        self.horizontalLayout_13.setObjectName(u"horizontalLayout_13")
        self.conditioner_1_label = QLabel(self.indicatorsFrame)
        self.conditioner_1_label.setObjectName(u"conditioner_1_label")
        self.conditioner_1_label.setMinimumSize(QSize(0, 20))

        self.horizontalLayout_13.addWidget(self.conditioner_1_label)

        self.conditioner_1_state = QLabel(self.indicatorsFrame)
        self.conditioner_1_state.setObjectName(u"conditioner_1_state")

        self.horizontalLayout_13.addWidget(self.conditioner_1_state)


        self.verticalLayout_12.addLayout(self.horizontalLayout_13)


        self.horizontalLayout_14.addLayout(self.verticalLayout_12)

        self.gridLayoutWidget = QWidget(self.widget)
        self.gridLayoutWidget.setObjectName(u"gridLayoutWidget")
        self.gridLayoutWidget.setGeometry(QRect(30, 460, 741, 331))
        self.squaresLayout = QGridLayout(self.gridLayoutWidget)
        self.squaresLayout.setSpacing(15)
        self.squaresLayout.setObjectName(u"squaresLayout")
        self.squaresLayout.setSizeConstraint(QLayout.SetDefaultConstraint)
        self.squaresLayout.setContentsMargins(0, 0, 0, 0)
        self.tempFrame = QFrame(self.widget)
        self.tempFrame.setObjectName(u"tempFrame")
        self.tempFrame.setGeometry(QRect(380, 260, 381, 191))
        self.tempFrame.setStyleSheet(u"QSpinBox, QDoubleSpinBox {\n"
"font: 12pt \"Roboto\";\n"
"color: black;\n"
"border: 2px solid gray;\n"
"border-radius: 4px;\n"
"}\n"
"QLCDNumber {\n"
"font: 12pt \"Roboto\";\n"
"color: black;\n"
"border: 2px solid gray;\n"
"border-radius: 4px;\n"
"}\n"
"QLabel {\n"
"font: bold 12pt \"Roboto\";\n"
"color: rgb(0, 0, 0);\n"
"}\n"
"QComboBox {\n"
"font: bold 12pt \"Roboto\";\n"
"color: rgb(0, 0, 0);\n"
"border: 2px solid gray;\n"
"border-radius: 4px;\n"
"}\n"
"QPushButton {\n"
"font: bold 12pt \"Roboto\";\n"
"color: rgb(0, 0, 0);\n"
"border: 2px solid gray;\n"
"border-radius: 4px;\n"
"background-color: white;\n"
"min-width:100px;\n"
"max-width:200px;\n"
"}\n"
"QPushButton:hover {\n"
"background-color: rgb(236, 236, 236);\n"
"}\n"
"")
        self.tempFrame.setFrameShape(QFrame.NoFrame)
        self.tempFrame.setLineWidth(3)
        self.gridLayout = QGridLayout(self.tempFrame)
        self.gridLayout.setObjectName(u"gridLayout")
        self.gridLayout.setHorizontalSpacing(80)
        self.gridLayout.setVerticalSpacing(2)
        self.gridLayout.setContentsMargins(0, 0, 0, 0)
        self.temp_outside_label = QLabel(self.tempFrame)
        self.temp_outside_label.setObjectName(u"temp_outside_label")
        sizePolicy = QSizePolicy(QSizePolicy.Policy.Minimum, QSizePolicy.Policy.Minimum)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.temp_outside_label.sizePolicy().hasHeightForWidth())
        self.temp_outside_label.setSizePolicy(sizePolicy)
        self.temp_outside_label.setStyleSheet(u"")

        self.gridLayout.addWidget(self.temp_outside_label, 0, 0, 1, 1)

        self.avg_temp_spin = QDoubleSpinBox(self.tempFrame)
        self.avg_temp_spin.setObjectName(u"avg_temp_spin")
        sizePolicy1 = QSizePolicy(QSizePolicy.Policy.Preferred, QSizePolicy.Policy.Fixed)
        sizePolicy1.setHorizontalStretch(0)
        sizePolicy1.setVerticalStretch(0)
        sizePolicy1.setHeightForWidth(self.avg_temp_spin.sizePolicy().hasHeightForWidth())
        self.avg_temp_spin.setSizePolicy(sizePolicy1)
        self.avg_temp_spin.setAlignment(Qt.AlignCenter)
        self.avg_temp_spin.setButtonSymbols(QAbstractSpinBox.NoButtons)
        self.avg_temp_spin.setMinimum(-50.000000000000000)
        self.avg_temp_spin.setMaximum(50.000000000000000)

        self.gridLayout.addWidget(self.avg_temp_spin, 1, 1, 1, 1)

        self.plan_temp_label = QLabel(self.tempFrame)
        self.plan_temp_label.setObjectName(u"plan_temp_label")
        sizePolicy.setHeightForWidth(self.plan_temp_label.sizePolicy().hasHeightForWidth())
        self.plan_temp_label.setSizePolicy(sizePolicy)
        self.plan_temp_label.setStyleSheet(u"")

        self.gridLayout.addWidget(self.plan_temp_label, 2, 0, 1, 1)

        self.plan_temp_spin = QSpinBox(self.tempFrame)
        self.plan_temp_spin.setObjectName(u"plan_temp_spin")
        sizePolicy1.setHeightForWidth(self.plan_temp_spin.sizePolicy().hasHeightForWidth())
        self.plan_temp_spin.setSizePolicy(sizePolicy1)
        self.plan_temp_spin.setStyleSheet(u"")
        self.plan_temp_spin.setWrapping(False)
        self.plan_temp_spin.setAlignment(Qt.AlignRight|Qt.AlignTrailing|Qt.AlignVCenter)
        self.plan_temp_spin.setReadOnly(False)
        self.plan_temp_spin.setButtonSymbols(QAbstractSpinBox.PlusMinus)
        self.plan_temp_spin.setCorrectionMode(QAbstractSpinBox.CorrectToNearestValue)
        self.plan_temp_spin.setKeyboardTracking(False)
        self.plan_temp_spin.setMinimum(-50)
        self.plan_temp_spin.setMaximum(50)

        self.gridLayout.addWidget(self.plan_temp_spin, 2, 1, 1, 1)

        self.avg_temp_label = QLabel(self.tempFrame)
        self.avg_temp_label.setObjectName(u"avg_temp_label")
        sizePolicy.setHeightForWidth(self.avg_temp_label.sizePolicy().hasHeightForWidth())
        self.avg_temp_label.setSizePolicy(sizePolicy)

        self.gridLayout.addWidget(self.avg_temp_label, 1, 0, 1, 1)

        self.temp_outside_spin = QSpinBox(self.tempFrame)
        self.temp_outside_spin.setObjectName(u"temp_outside_spin")
        sizePolicy1.setHeightForWidth(self.temp_outside_spin.sizePolicy().hasHeightForWidth())
        self.temp_outside_spin.setSizePolicy(sizePolicy1)
        self.temp_outside_spin.setStyleSheet(u"")
        self.temp_outside_spin.setWrapping(False)
        self.temp_outside_spin.setAlignment(Qt.AlignRight|Qt.AlignTrailing|Qt.AlignVCenter)
        self.temp_outside_spin.setReadOnly(False)
        self.temp_outside_spin.setButtonSymbols(QAbstractSpinBox.PlusMinus)
        self.temp_outside_spin.setCorrectionMode(QAbstractSpinBox.CorrectToNearestValue)
        self.temp_outside_spin.setKeyboardTracking(False)
        self.temp_outside_spin.setMinimum(-50)
        self.temp_outside_spin.setMaximum(50)

        self.gridLayout.addWidget(self.temp_outside_spin, 0, 1, 1, 1)

        self.choose_regulator = QComboBox(self.tempFrame)
        self.choose_regulator.addItem("")
        self.choose_regulator.addItem("")
        self.choose_regulator.addItem("")
        self.choose_regulator.setObjectName(u"choose_regulator")
        sizePolicy2 = QSizePolicy(QSizePolicy.Policy.Ignored, QSizePolicy.Policy.Fixed)
        sizePolicy2.setHorizontalStretch(0)
        sizePolicy2.setVerticalStretch(0)
        sizePolicy2.setHeightForWidth(self.choose_regulator.sizePolicy().hasHeightForWidth())
        self.choose_regulator.setSizePolicy(sizePolicy2)

        self.gridLayout.addWidget(self.choose_regulator, 3, 1, 1, 1)

        self.choose_regulator_label = QLabel(self.tempFrame)
        self.choose_regulator_label.setObjectName(u"choose_regulator_label")

        self.gridLayout.addWidget(self.choose_regulator_label, 3, 0, 1, 1)

        self.start_regulation_btn = QPushButton(self.tempFrame)
        self.start_regulation_btn.setObjectName(u"start_regulation_btn")
        sizePolicy1.setHeightForWidth(self.start_regulation_btn.sizePolicy().hasHeightForWidth())
        self.start_regulation_btn.setSizePolicy(sizePolicy1)

        self.gridLayout.addWidget(self.start_regulation_btn, 4, 0, 1, 1)

        self.open_graph_btn = QPushButton(self.tempFrame)
        self.open_graph_btn.setObjectName(u"open_graph_btn")
        self.open_graph_btn.setEnabled(False)

        self.gridLayout.addWidget(self.open_graph_btn, 4, 1, 1, 1)

        self.stop_regulation_btn = QPushButton(self.tempFrame)
        self.stop_regulation_btn.setObjectName(u"stop_regulation_btn")
        self.stop_regulation_btn.setEnabled(False)
        sizePolicy1.setHeightForWidth(self.stop_regulation_btn.sizePolicy().hasHeightForWidth())
        self.stop_regulation_btn.setSizePolicy(sizePolicy1)

        self.gridLayout.addWidget(self.stop_regulation_btn, 5, 0, 1, 1)

        self.mode_label = QLabel(self.widget)
        self.mode_label.setObjectName(u"mode_label")
        self.mode_label.setGeometry(QRect(240, 20, 291, 16))
        sizePolicy3 = QSizePolicy(QSizePolicy.Policy.MinimumExpanding, QSizePolicy.Policy.Preferred)
        sizePolicy3.setHorizontalStretch(0)
        sizePolicy3.setVerticalStretch(0)
        sizePolicy3.setHeightForWidth(self.mode_label.sizePolicy().hasHeightForWidth())
        self.mode_label.setSizePolicy(sizePolicy3)
        self.mode_label.setStyleSheet(u"color: rgb(0, 0, 0);\n"
"font: bold, 12pt \"Roboto\";")
        self.mode_label.setFrameShape(QFrame.NoFrame)
        self.mode_label.setLineWidth(2)

        self.retranslateUi(Main)
        self.conditioner_slider.valueChanged.connect(self.conditioner_num.display)
        self.regHeater_1_slider.valueChanged.connect(self.regHeater_1_num.display)
        self.regHeater_2_slider.valueChanged.connect(self.regHeater_2_num.display)

        QMetaObject.connectSlotsByName(Main)
    # setupUi

    def retranslateUi(self, Main):
        Main.setWindowTitle(QCoreApplication.translate("Main", u"Main", None))
        self.regulatorsFrame.setProperty(u"class", QCoreApplication.translate("Main", u"panel", None))
        self.label_2.setText(QCoreApplication.translate("Main", u"\u0420\u0435\u0433\u0443\u043b\u0438\u0440\u0443\u0435\u043c\u044b\u0439 \u043d\u0430\u0433\u0440\u0435\u0432\u0430\u0442\u0435\u043b\u044c 1", None))
        self.label_3.setText(QCoreApplication.translate("Main", u"\u0420\u0435\u0433\u0443\u043b\u0438\u0440\u0443\u0435\u043c\u044b\u0439 \u043d\u0430\u0433\u0440\u0435\u0432\u0430\u0442\u0435\u043b\u044c 2", None))
        self.label_4.setText(QCoreApplication.translate("Main", u"\u041a\u043e\u043d\u0434\u0438\u0446\u0438\u043e\u043d\u0435\u0440", None))
        self.indicatorsFrame.setProperty(u"class", QCoreApplication.translate("Main", u"panel", None))
        self.door_1_label.setText(QCoreApplication.translate("Main", u"\u0414\u0432\u0435\u0440\u044c 1", None))
        self.door_1_label.setProperty(u"class", QCoreApplication.translate("Main", u"name", None))
        self.door_1_state.setText("")
        self.door_1_state.setProperty(u"class", QCoreApplication.translate("Main", u"state", None))
        self.door_2_label.setText(QCoreApplication.translate("Main", u"\u0414\u0432\u0435\u0440\u044c 2", None))
        self.door_2_label.setProperty(u"class", QCoreApplication.translate("Main", u"name", None))
        self.door_2_state.setText("")
        self.door_2_state.setProperty(u"class", QCoreApplication.translate("Main", u"state", None))
        self.door_3_label.setText(QCoreApplication.translate("Main", u"\u0414\u0432\u0435\u0440\u044c 3", None))
        self.door_3_label.setProperty(u"class", QCoreApplication.translate("Main", u"name", None))
        self.door_3_state.setText("")
        self.door_3_state.setProperty(u"class", QCoreApplication.translate("Main", u"state", None))
        self.door_4_label.setText(QCoreApplication.translate("Main", u"\u0414\u0432\u0435\u0440\u044c 4", None))
        self.door_4_label.setProperty(u"class", QCoreApplication.translate("Main", u"name", None))
        self.door_4_state.setText("")
        self.door_4_state.setProperty(u"class", QCoreApplication.translate("Main", u"state", None))
        self.window_1_label.setText(QCoreApplication.translate("Main", u"\u041e\u043a\u043d\u043e 1", None))
        self.window_1_label.setProperty(u"class", QCoreApplication.translate("Main", u"name", None))
        self.window_1_state.setText("")
        self.window_1_state.setProperty(u"class", QCoreApplication.translate("Main", u"state", None))
        self.window_2_label.setText(QCoreApplication.translate("Main", u"\u041e\u043a\u043d\u043e 2", None))
        self.window_2_label.setProperty(u"class", QCoreApplication.translate("Main", u"name", None))
        self.window_2_state.setText("")
        self.window_2_state.setProperty(u"class", QCoreApplication.translate("Main", u"state", None))
        self.regHeater_1_label.setText(QCoreApplication.translate("Main", u"\u0420\u0435\u0433. \u043d\u0430\u0433\u0440\u0435\u0432\u0430\u0442\u0435\u043b\u044c 1", None))
        self.regHeater_1_label.setProperty(u"class", QCoreApplication.translate("Main", u"name", None))
        self.regHeater_1_state.setText("")
        self.regHeater_1_state.setProperty(u"class", QCoreApplication.translate("Main", u"state", None))
        self.regHeater_2_label.setText(QCoreApplication.translate("Main", u"\u0420\u0435\u0433. \u043d\u0430\u0433\u0440\u0435\u0432\u0430\u0442\u0435\u043b\u044c 2", None))
        self.regHeater_2_label.setProperty(u"class", QCoreApplication.translate("Main", u"name", None))
        self.regHeater_2_state.setText("")
        self.regHeater_2_state.setProperty(u"class", QCoreApplication.translate("Main", u"state", None))
        self.unregHeater_1_label.setText(QCoreApplication.translate("Main", u"\u041d\u0435\u0440\u0435\u0433. \u043d\u0430\u0433\u0440\u0435\u0432\u0430\u0442\u0435\u043b\u044c 1", None))
        self.unregHeater_1_label.setProperty(u"class", QCoreApplication.translate("Main", u"name", None))
        self.unregHeater_1_state.setText("")
        self.unregHeater_1_state.setProperty(u"class", QCoreApplication.translate("Main", u"state", None))
        self.unregHeater_2_label.setText(QCoreApplication.translate("Main", u"\u041d\u0435\u0440\u0435\u0433. \u043d\u0430\u0433\u0440\u0435\u0432\u0430\u0442\u0435\u043b\u044c 2", None))
        self.unregHeater_2_label.setProperty(u"class", QCoreApplication.translate("Main", u"name", None))
        self.unregHeater_2_state.setText("")
        self.unregHeater_2_state.setProperty(u"class", QCoreApplication.translate("Main", u"state", None))
        self.conditioner_1_label.setText(QCoreApplication.translate("Main", u"\u041a\u043e\u043d\u0434\u0438\u0446\u0438\u043e\u043d\u0435\u0440", None))
        self.conditioner_1_label.setProperty(u"class", QCoreApplication.translate("Main", u"name", None))
        self.conditioner_1_state.setText("")
        self.conditioner_1_state.setProperty(u"class", QCoreApplication.translate("Main", u"state", None))
        self.tempFrame.setProperty(u"class", QCoreApplication.translate("Main", u"panel", None))
        self.temp_outside_label.setText(QCoreApplication.translate("Main", u"\u0422\u0435\u043c\u043f\u0435\u0440\u0430\u0442\u0443\u0440\u0430 \u0441\u043d\u0430\u0440\u0443\u0436\u0438", None))
        self.avg_temp_spin.setPrefix("")
        self.avg_temp_spin.setSuffix(QCoreApplication.translate("Main", u"\u00b0C", None))
        self.plan_temp_label.setText(QCoreApplication.translate("Main", u"\u041f\u043b\u0430\u043d\u043e\u0432\u0430\u044f \u0442\u0435\u043c\u043f\u0435\u0440\u0430\u0442\u0443\u0440\u0430", None))
        self.plan_temp_spin.setSpecialValueText("")
        self.plan_temp_spin.setSuffix(QCoreApplication.translate("Main", u"\u00b0C", None))
        self.plan_temp_spin.setPrefix("")
        self.avg_temp_label.setText(QCoreApplication.translate("Main", u"\u0422\u0435\u043c\u043f\u0435\u0440\u0430\u0442\u0443\u0440\u0430 \u0432\u043d\u0443\u0442\u0440\u0438", None))
        self.temp_outside_spin.setSpecialValueText("")
        self.temp_outside_spin.setSuffix(QCoreApplication.translate("Main", u"\u00b0C", None))
        self.temp_outside_spin.setPrefix("")
        self.choose_regulator.setItemText(0, QCoreApplication.translate("Main", u"\u0420\u0435\u043b\u0435", None))
        self.choose_regulator.setItemText(1, QCoreApplication.translate("Main", u"\u041f-\u0440\u0435\u0433\u0443\u043b\u044f\u0442\u043e\u0440", None))
        self.choose_regulator.setItemText(2, QCoreApplication.translate("Main", u"\u041f\u0418-\u0440\u0435\u0433\u0443\u043b\u044f\u0442\u043e\u0440", None))

        self.choose_regulator.setCurrentText(QCoreApplication.translate("Main", u"\u0420\u0435\u043b\u0435", None))
        self.choose_regulator_label.setText(QCoreApplication.translate("Main", u"\u0412\u044b\u0431\u043e\u0440 \u0440\u0435\u0433\u0443\u043b\u044f\u0442\u043e\u0440\u0430", None))
        self.start_regulation_btn.setText(QCoreApplication.translate("Main", u"\u041d\u0430\u0447\u0430\u0442\u044c \u0440\u0435\u0433\u0443\u043b\u044f\u0446\u0438\u044e", None))
        self.open_graph_btn.setText(QCoreApplication.translate("Main", u"\u0413\u0440\u0430\u0444\u0438\u043a", None))
        self.stop_regulation_btn.setText(QCoreApplication.translate("Main", u"\u041e\u0441\u0442\u0430\u043d\u043e\u0432\u0438\u0442\u044c \u0440\u0435\u0433\u0443\u043b\u044f\u0446\u0438\u044e", None))
        self.mode_label.setText(QCoreApplication.translate("Main", u"\u0422\u0435\u043a\u0443\u0449\u0438\u0439 \u0440\u0435\u0436\u0438\u043c \u0440\u0430\u0431\u043e\u0442\u044b:", None))
    # retranslateUi

