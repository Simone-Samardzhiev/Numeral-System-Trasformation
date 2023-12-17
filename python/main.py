import sys
from PyQt6.QtWidgets import QWidget, QApplication, QLabel, QLineEdit, QPushButton, QGridLayout, QComboBox, QMessageBox
from functions import *


class Window(QWidget):
    result: QLabel
    num1: QLineEdit
    num2: QLineEdit
    type1: QComboBox
    type2: QComboBox
    button: QPushButton
    layout: QGridLayout
    types: list[str] = ['2', '8', '10', '16']

    def __init__(self):
        super().__init__()
        self.setWindowTitle('Numeral System transformation')
        self.setGeometry(100, 100, 500, 500)

        # creating objects
        self.result = QLabel()
        self.num1 = QLineEdit()
        self.num2 = QLineEdit()
        self.type1 = QComboBox()
        self.type2 = QComboBox()
        self.button = QPushButton("Transform")
        self.layout = QGridLayout()

        # adding the types to the ComboBoxes
        for t in self.types:
            self.type1.addItem(t)
            self.type2.addItem(t)

        # connecting button to function
        self.button.clicked.connect(self.on_transform_pressed)

        # adding the objects to the window
        self.layout.addWidget(self.num1, 0, 0)
        self.layout.addWidget(self.type1, 1, 0)

        self.layout.addWidget(self.num2, 0, 2)
        self.layout.addWidget(self.type2, 1, 2)

        self.layout.addWidget(self.button, 0, 1)
        self.layout.addWidget(self.result, 1, 1)

        self.setLayout(self.layout)

    # function that will be activated when the button is pressed
    def on_transform_pressed(self):
        # getting the selected types
        type1 = self.type1.currentText()
        type2 = self.type2.currentText()

        # getting the inputed number
        num1 = self.num1.text()

        if type1 == '2':
            if is_binary(num1):
                if type2 == '8':
                    self.result.setText(binary_to_octal(num1))
                elif type2 == '10':
                    self.result.setText(binary_to_decimal(num1))
                elif type2 == '16':
                    self.result.setText(binary_to_hexadecimal(num1))
                else:
                    QMessageBox.information(self, "Error", "Invalid type")
            else:
                QMessageBox.information(self, "Error", "Ivalid number")
        elif type1 == '8':
            if is_binary(num1):
                if type2 == '2':
                    self.result.setText(octal_to_binary(num1))
                elif type2 == '10':
                    self.result.setText(octal_to_decimal(num1))
                elif type2 == '16':
                    self.result.setText(octal_to_hexadecimal(num1))
                else:
                    QMessageBox.information(self, "Error", "Invalid type")
            else:
                QMessageBox.information(self, "Error", "Invalid number")
        elif type1 == '10':
            if is_decimal(num1):
                if type2 == '2':
                    self.result.setText(decimal_to_binary(num1))
                elif type2 == '8':
                    self.result.setText(decimal_to_octal(num1))
                elif type2 == '16':
                    self.result.setText(decimal_to_hexadecimal(num1))
                else:
                    QMessageBox.information(self, "Error", "Invalid type")
            else:
                QMessageBox.information(self, "Error", "Invalid number")
        elif type1 == '16':
            if is_binary(num1):
                if type2 == '2':
                    self.result.setText(hexadecimal_to_binary(num1))
                elif type2 == '8':
                    self.result.setText(hexadecimal_to_octal(num1))
                elif type2 == '10':
                    self.result.setText(hexadecimal_to_decimal(num1))
                else:
                    QMessageBox.information(self, "Error", "Invalid type")
            else:
                QMessageBox.warning(self, "Error", "Invalid number")


if __name__ == '__main__':
    app = QApplication(sys.argv)
    window = Window()
    window.show()
    sys.exit(app.exec())
