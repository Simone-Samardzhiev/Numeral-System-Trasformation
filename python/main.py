import sys

from PyQt6.QtWidgets import (QApplication, QWidget, QMessageBox, QGridLayout, QVBoxLayout, QFrame,
                             QComboBox, QLineEdit, QLabel, QPushButton, QTableWidget, QTableWidgetItem)


# Class that will transform numerals systems.
# noinspection DuplicatedCode
class TransformNumeralSystem:
    # Method that is used to transform binary to octal
    @staticmethod
    def binary_to_octal(num: str) -> [QTableWidget, str]:
        values = {
            "000": "0",
            "001": "1",
            "010": "2",
            "011": "3",
            "100": "4",
            "101": "5",
            "110": "6",
            "111": "7"
        }
        result = ''
        table = QTableWidget()

        while len(num) % 3 != 0:
            num = '0' + num

        split_num = [num[i:i + 3] for i in range(0, len(num), 3)]

        table.setRowCount(len(split_num))
        table.setColumnCount(2)
        table.setHorizontalHeaderLabels(["Binary Number", "Octal Number"])
        table.setStyleSheet("QTableWidget::item { border: 1px solid white; }")
        table.verticalHeader().setVisible(False)
        table.setEditTriggers(QTableWidget.EditTrigger.NoEditTriggers)

        for i in range(len(split_num)):
            binary_item = QTableWidgetItem(split_num[i])
            octal_item = QTableWidgetItem(values[split_num[i]])

            table.setItem(i, 0, binary_item)
            table.setItem(i, 1, octal_item)

            result += values[split_num[i]]

        return table, result

    # Method that is used to transform binary to decimal.
    @staticmethod
    def binary_to_decimal(num: str) -> [QTableWidget, str]:
        table = QTableWidget()
        result = 0

        table.setRowCount(len(num))
        table.setColumnCount(2)
        table.setHorizontalHeaderLabels(["Binary Number", "Decimal Number"])
        table.setStyleSheet("QTableWidget::item { border: 1px solid white; }")
        table.verticalHeader().setVisible(False)
        table.setEditTriggers(QTableWidget.EditTrigger.NoEditTriggers)

        for i in range(len(num)):
            binary_item = QTableWidgetItem(f"2 ^ {len(num) - 1 - i} * {num[i]}")
            decimal_item = QTableWidgetItem(str(2 ** (len(num) - i - 1) * int(num[i])))
            table.setItem(i, 0, binary_item)
            table.setItem(i, 1, decimal_item)
            result += 2 ** (len(num) - i - 1) * int(num[i])

        return table, str(result)

    # Method that is used to transform binary to hexadecimal.
    @staticmethod
    def binary_to_hexadecimal(num: str) -> [QTableWidget, str]:
        values = {
            "0000": "0",
            "0001": "1",
            "0010": "2",
            "0011": "3",
            "0100": "4",
            "0101": "5",
            "0110": "6",
            "0111": "7",
            "1000": "8",
            "1001": "9",
            "1010": "A",
            "1011": "B",
            "1100": "C",
            "1101": "D",
            "1110": "E",
            "1111": "F"
        }

        result = ''
        table = QTableWidget()

        while len(num) % 4 != 0:
            num = '0' + num

        split_num = [num[i:i + 4] for i in range(0, len(num), 4)]

        table.setRowCount(len(split_num))
        table.setColumnCount(2)
        table.setHorizontalHeaderLabels(["Binary Number", "Hexadecimal Number"])
        table.setStyleSheet("QTableWidget::item { border: 1px solid white; }")
        table.verticalHeader().setVisible(False)
        table.setEditTriggers(QTableWidget.EditTrigger.NoEditTriggers)

        for i in range(len(split_num)):
            binary_item = QTableWidgetItem(split_num[i])
            hexadecimal_item = QTableWidgetItem(values[split_num[i]])

            table.setItem(i, 0, binary_item)
            table.setItem(i, 1, hexadecimal_item)

            result += values[split_num[i]]

        return table, result

    # Method that is used to transform octal to binary.
    @staticmethod
    def octal_to_binary(num: str) -> [QTableWidget, str]:
        values = {
            "0": "000",
            "1": "001",
            "2": "010",
            "3": "011",
            "4": "100",
            "5": "101",
            "6": "110",
            "7": "111"
        }

        result = ''
        table = QTableWidget()

        table.setRowCount(len(num))
        table.setColumnCount(2)
        table.setHorizontalHeaderLabels(["Octal Number", "Binary Number"])
        table.setStyleSheet("QTableWidget::item { border: 1px solid white; }")
        table.verticalHeader().setVisible(False)
        table.setEditTriggers(QTableWidget.EditTrigger.NoEditTriggers)

        for i in range(len(num)):
            octal_item = QTableWidgetItem(num[i])
            binary_item = QTableWidgetItem(values[num[i]])

            table.setItem(i, 0, octal_item)
            table.setItem(i, 1, binary_item)

            result += values[num[i]]

        return table, result

    # Method used to transform octal to decimal.
    @staticmethod
    def octal_to_decimal(num: str) -> [QTableWidget, str]:
        table = QTableWidget()
        result = 0

        table.setRowCount(len(num))
        table.setColumnCount(2)
        table.setHorizontalHeaderLabels(["Octal Number", "Decimal Number"])
        table.setStyleSheet("QTableWidget::item { border: 1px solid white; }")
        table.verticalHeader().setVisible(False)
        table.setEditTriggers(QTableWidget.EditTrigger.NoEditTriggers)

        for i in range(len(num)):
            octal_item = QTableWidgetItem(f"8 ^ {len(num) - 1 - i} * {num[i]}")
            decimal_item = QTableWidgetItem(str(8 ** (len(num) - 1 - i) * int(num[i])))

            table.setItem(i, 0, octal_item)
            table.setItem(i, 1, decimal_item)

            result += 8 ** (len(num) - 1 - i) * int(num[i])

        return table, str(result)

    # Method that is used to transform octal to hexadecimal.
    @staticmethod
    def octal_to_hexadecimal(num: str) -> [QTableWidget, str, QTableWidget, str]:
        binary_table, binary_result = TransformNumeralSystem.octal_to_binary(num)
        hexadecimal_table, hexadecimal_result = TransformNumeralSystem.binary_to_hexadecimal(binary_result)

        return binary_table, binary_result, hexadecimal_table, hexadecimal_result

    # Method used to transform decimal to binary
    @staticmethod
    def decimal_to_binary(num: str) -> [QTableWidget, str]:
        table = QTableWidget()
        num = int(num)
        copy_num = num
        row = 0
        result = ''

        while copy_num > 0:
            copy_num //= 2
            row += 1

        table.setRowCount(row)
        table.setColumnCount(3)
        table.setHorizontalHeaderLabels(["Decimal Number", "Quotient Number", "Binary Number"])
        table.setStyleSheet("QTableWidget::item { border: 1px solid white; }")
        table.verticalHeader().setVisible(False)
        table.setEditTriggers(QTableWidget.EditTrigger.NoEditTriggers)

        row = 0
        while num > 0:
            decimal_item = QTableWidgetItem(f"{num} / 2")
            quotient_item = QTableWidgetItem(str(num // 2))
            binary_item = QTableWidgetItem(str(num % 2))

            table.setItem(row, 0, decimal_item)
            table.setItem(row, 1, quotient_item)
            table.setItem(row, 2, binary_item)

            result = str(num % 2) + result

            row += 1
            num //= 2

        return table, result

    # Method used to transform decimal to octal.
    @staticmethod
    def decimal_to_octal(num: str) -> [QTableWidget, str]:
        table = QTableWidget()
        num = int(num)
        copy_num = num
        row = 0
        result = ''

        while copy_num > 0:
            copy_num //= 8
            row += 1

        table.setRowCount(row)
        table.setColumnCount(3)
        table.setHorizontalHeaderLabels(["Decimal Number", "Quotient Number", "Octal Number"])
        table.setStyleSheet("QTableWidget::item { border: 1px solid white; }")
        table.verticalHeader().setVisible(False)
        table.setEditTriggers(QTableWidget.EditTrigger.NoEditTriggers)

        row = 0
        while num > 0:
            decimal_item = QTableWidgetItem(f"{num} / 8")
            quotient_item = QTableWidgetItem(str(num // 8))
            binary_item = QTableWidgetItem(str(num % 8))

            table.setItem(row, 0, decimal_item)
            table.setItem(row, 1, quotient_item)
            table.setItem(row, 2, binary_item)

            result = str(num % 8) + result

            row += 1
            num //= 8

        return table, result

    # Method used to transform decimal to hexadecimal.
    @staticmethod
    def decimal_to_hexadecimal(num: str) -> [QTableWidget, str]:
        values = {
            0: '0',
            1: '1',
            2: '2',
            3: '3',
            4: '4',
            5: '5',
            6: '6',
            7: '7',
            8: '8',
            9: '8',
            10: 'A',
            11: 'B',
            12: 'C',
            13: 'D',
            14: 'E',
            15: 'F'
        }
        table = QTableWidget()
        num = int(num)
        copy_num = num
        row = 0
        result = ''

        while copy_num > 0:
            copy_num //= 16
            row += 1

        table.setRowCount(row)
        table.setColumnCount(3)
        table.setHorizontalHeaderLabels(["Decimal Number", "Quotient Number", "Hexadecimal Number"])
        table.setStyleSheet("QTableWidget::item { border: 1px solid white; }")
        table.verticalHeader().setVisible(False)
        table.setEditTriggers(QTableWidget.EditTrigger.NoEditTriggers)

        row = 0
        while num > 0:
            decimal_item = QTableWidgetItem(f"{num} / 16")
            quotient_item = QTableWidgetItem(str(num // 16))
            binary_item = QTableWidgetItem(values[num % 16])

            table.setItem(row, 0, decimal_item)
            table.setItem(row, 1, quotient_item)
            table.setItem(row, 2, binary_item)

            result = values[num % 16] + result

            row += 1
            num //= 16

        return table, result

    # Method used to transform hexadecimal to binary.
    @staticmethod
    def hexadecimal_to_binary(num: str) -> [QTableWidget, str]:
        values = {
            "0": "0000",
            "1": "0001",
            "2": "0010",
            "3": "0011",
            "4": "0100",
            "5": "0101",
            "6": "0110",
            "7": "0111",
            "8": "1000",
            "9": "1001",
            "A": "1010",
            "B": "1011",
            "C": "1100",
            "D": "1101",
            "E": "1110",
            "F": "1111"
        }
        result = ""

        table = QTableWidget()
        table.setRowCount(len(num))
        table.setColumnCount(2)
        table.setHorizontalHeaderLabels(["Hexadecimal Number", "Binary Number"])
        table.setStyleSheet("QTableWidget::item { border: 1px solid white; }")
        table.verticalHeader().setVisible(False)
        table.setEditTriggers(QTableWidget.EditTrigger.NoEditTriggers)

        for i in range(len(num)):
            hexadecimal_item = QTableWidgetItem(num[i])
            binary_item = QTableWidgetItem(values[num[i]])

            table.setItem(i, 0, hexadecimal_item)
            table.setItem(i, 1, binary_item)

            result += values[num[i]]

        return table, result

    # Method used to transform hexadecimal to octal.
    @staticmethod
    def hexadecimal_to_octal(num: str) -> [QTableWidget, str, QTableWidget, str]:
        binary_table, binary_result = TransformNumeralSystem.hexadecimal_to_binary(num)
        octal_table, octal_result = TransformNumeralSystem.binary_to_octal(binary_result)

        return binary_table, binary_result, octal_table, octal_result

    # Method used to transform hexadecimal to decimal.
    @staticmethod
    def hexadecimal_to_decimal(num: str) -> [QTableWidget, str]:
        values = {
            "0": 0,
            "1": 1,
            "2": 2,
            "3": 3,
            "4": 4,
            "5": 5,
            "6": 6,
            "7": 7,
            "8": 8,
            "9": 9,
            "A": 10,
            "B": 11,
            "C": 12,
            "D": 13,
            "E": 14,
            "F": 15,
        }
        table = QTableWidget()
        result = 0

        table.setRowCount(len(num))
        table.setColumnCount(2)
        table.setHorizontalHeaderLabels(["Hexadecimal Number", "Decimal Number"])
        table.setStyleSheet("QTableWidget::item { border: 1px solid white; }")
        table.verticalHeader().setVisible(False)
        table.setEditTriggers(QTableWidget.EditTrigger.NoEditTriggers)

        for i in range(len(num)):
            hexadecimal_item = QTableWidgetItem(f"16 ^ {len(num) - 1 - i} * {values[num[i]]}")
            decimal_item = QTableWidgetItem(str(16 ** (len(num) - 1 - i) * values[num[i]]))

            table.setItem(i, 0, hexadecimal_item)
            table.setItem(i, 1, decimal_item)

            result += 16 ** (len(num) - 1 - i) * values[num[i]]

        return table, str(result)

    # Method used to check if a system is valid.
    @staticmethod
    def check_system(num: str, system: int) -> bool:
        if len(num) == 0:
            return False

        match system:
            case 2:
                digits = ("0", "1")
                for digit in num:
                    if digit not in digits:
                        return False

                return True
            case 8:
                digits = ("0", "1", "2", "3", "4", "5", "6", "7")
                for digit in num:
                    if digit not in digits:
                        return False

                return True
            case 10:
                digits = ("0", "1", "2", "3", "4", "5", "6", "7", "8", "9")
                for digit in num:
                    if digit not in digits:
                        return False

                return True
            case 16:
                digits = ("0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F")
                for digit in num:
                    if digit not in digits:
                        return False

                return True


class Window(QWidget):
    # Main layout of the window.
    layout: QGridLayout
    # QLineEdits used for entering the number and displaying the number.
    inputLineEdit: QLineEdit
    resultLineEdit: QLineEdit
    # QCombo boxes used to select the system of the input and if the result
    inputSystems: QComboBox
    resultSystems: QComboBox

    # Layout used by the frame for tables.
    frameLayout: QVBoxLayout

    def __init__(self) -> None:
        super().__init__()

        # Setting attributes to the window.
        self.setWindowTitle("Numeral system transformation")
        self.setFixedSize(400, 600)

        # Creating the UI.
        self.layout = QGridLayout()
        self.setLayout(self.layout)
        self.create_ui()

    # Method that will create the UI.
    def create_ui(self) -> None:
        # Creating the widgets.
        self.inputLineEdit = QLineEdit()
        self.resultLineEdit = QLineEdit()
        self.inputSystems = QComboBox()
        self.resultSystems = QComboBox()
        self.frameLayout = QVBoxLayout()
        frame = QFrame()
        transform_button = QPushButton("Transform")

        # Setting attributes to the widgets.
        self.resultLineEdit.setReadOnly(True)
        self.inputSystems.addItems(["Binary", "Octal", "Decimal", "Hexadecimal"])
        self.resultSystems.addItems(["Binary", "Octal", "Decimal", "Hexadecimal"])
        frame.setLayout(self.frameLayout)

        # Connecting the widgets.
        transform_button.clicked.connect(self.on_transform_button_clicked)

        # Adding the widgets.
        self.layout.addWidget(self.inputSystems, 0, 0)
        self.layout.addWidget(self.resultSystems, 1, 0)
        self.layout.addWidget(self.inputLineEdit, 2, 0)
        self.layout.addWidget(transform_button, 3, 0)
        self.layout.addWidget(self.resultLineEdit, 4, 0)
        self.layout.addWidget(frame, 5, 0)

    # Method that will remove all the widgets form the frame layout
    def clean_frame_layout(self) -> None:
        for i in reversed(range(self.frameLayout.count())):
            item = self.frameLayout.itemAt(i)

            if item.widget():
                item.widget().deleteLater()

    # Method that will be activated when the user clicks transform.
    def on_transform_button_clicked(self) -> None:
        input_system = self.inputSystems.currentText()
        result_system = self.resultSystems.currentText()
        num = self.inputLineEdit.text().upper()

        match input_system:
            case "Binary":
                self.clean_frame_layout()

                if not TransformNumeralSystem.check_system(num, 2):
                    QMessageBox.warning(self, "Error", "Invalid input")
                    return

                match result_system:
                    case "Binary":
                        self.resultLineEdit.setText(num)
                    case "Octal":
                        tabel, result = TransformNumeralSystem.binary_to_octal(num)
                        self.frameLayout.addWidget(tabel)
                        self.resultLineEdit.setText(result)
                    case "Decimal":
                        tabel, result = TransformNumeralSystem.binary_to_decimal(num)
                        self.frameLayout.addWidget(tabel)
                        self.resultLineEdit.setText(result)
                    case "Hexadecimal":
                        tabel, result = TransformNumeralSystem.binary_to_hexadecimal(num)
                        self.frameLayout.addWidget(tabel)
                        self.resultLineEdit.setText(result)

            case "Octal":
                self.clean_frame_layout()

                if not TransformNumeralSystem.check_system(num, 8):
                    QMessageBox.warning(self, "Error", "Invalid input")
                    return

                match result_system:
                    case "Binary":
                        table, result = TransformNumeralSystem.octal_to_binary(num)
                        self.frameLayout.addWidget(table)
                        self.resultLineEdit.setText(result)
                    case "Octal":
                        self.resultLineEdit.setText(num)
                    case "Decimal":
                        tabel, result = TransformNumeralSystem.octal_to_decimal(num)
                        self.frameLayout.addWidget(tabel)
                        self.resultLineEdit.setText(result)
                    case "Hexadecimal":
                        tabel1, result1, tabel2, result2 = TransformNumeralSystem.octal_to_hexadecimal(num)
                        self.frameLayout.addWidget(tabel1)
                        self.frameLayout.addWidget(QLabel(f"Binary: {result1}"))
                        self.frameLayout.addWidget(tabel2)
                        self.resultLineEdit.setText(result2)
            case "Decimal":
                self.clean_frame_layout()

                if not TransformNumeralSystem.check_system(num, 10):
                    QMessageBox.warning(self, "Error", "Invalid input")
                    return

                match result_system:
                    case "Binary":
                        table, result = TransformNumeralSystem.decimal_to_binary(num)
                        self.frameLayout.addWidget(table)
                        self.resultLineEdit.setText(result)
                    case "Octal":
                        tabel, result = TransformNumeralSystem.decimal_to_octal(num)
                        self.frameLayout.addWidget(tabel)
                        self.resultLineEdit.setText(result)
                    case "Decimal":
                        self.resultLineEdit.setText(num)
                    case "Hexadecimal":
                        tabel, result = TransformNumeralSystem.decimal_to_hexadecimal(num)
                        self.frameLayout.addWidget(tabel)
                        self.resultLineEdit.setText(result)
            case "Hexadecimal":
                self.clean_frame_layout()

                if not TransformNumeralSystem.check_system(num, 16):
                    QMessageBox.warning(self, "Error", "Invalid input")
                    return

                match result_system:
                    case "Binary":
                        table, result = TransformNumeralSystem.hexadecimal_to_binary(num)
                        self.frameLayout.addWidget(table)
                        self.resultLineEdit.setText(result)
                    case "Octal":
                        tabel1, result1, table2, result2 = TransformNumeralSystem.hexadecimal_to_octal(num)
                        self.frameLayout.addWidget(tabel1)
                        self.resultLineEdit.setText(f"Binary: {result1}")
                        self.frameLayout.addWidget(table2)
                        self.resultLineEdit.setText(result2)
                    case "Decimal":
                        tabel, result = TransformNumeralSystem.hexadecimal_to_decimal(num)
                        self.frameLayout.addWidget(tabel)
                        self.resultLineEdit.setText(result)
                    case "Hexadecimal":
                        self.resultLineEdit.setText(num)


def main() -> None:
    app = QApplication(sys.argv)
    window = Window()
    window.show()
    app.exec()


if __name__ == "__main__":
    main()
