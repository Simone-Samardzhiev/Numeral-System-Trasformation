#include <QString>
#include <QTableWidget>
#include <QHeaderView>
#include <QList>
#include <unordered_map>
#include <unordered_set>

#include <QApplication>
#include <QWidget>
#include <QMessageBox>
#include <QGridLayout>
#include <QFrame>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>

namespace TransformSystems {
    // Class used to hold the table and the result for the functions.
    class Result {
    private:
        QTableWidget *table;
        QString num;
    public:
        Result(QTableWidget *table, QString num) : table(table), num(std::move(num)) {}

        QTableWidget *getTable() {
            return table;
        }

        const QString &getNum() {
            return num;
        }
    };

    // Class that will hold two tables and two string for function that need to return more values.
    class LargerResult {
    private:
        QTableWidget *table1;
        QString num1;
        QTableWidget *table2;
        QString num2;
    public:
        LargerResult(QTableWidget *table1, QString num1, QTableWidget *table2, QString num2) : table1(table1),
                                                                                               num1(std::move(num1)),
                                                                                               table2(table2),
                                                                                               num2(std::move(num2)) {}

        QTableWidget *getTable1() {
            return table1;
        }

        const QString &getNum1() {
            return num1;
        }

        QTableWidget *getTable2() {
            return table2;
        }

        const QString &getNum2() {
            return num2;
        }
    };

    // Function used to transform binary to octal.
    Result binaryToOctal(QString num) {
        auto table = new QTableWidget();
        std::unordered_map<QString, QChar> values = {
                {"000", '0'},
                {"001", '1'},
                {"010", '2'},
                {"011", '3'},
                {"100", '4'},
                {"101", '5'},
                {"110", '6'},
                {"111", '7'}
        };

        while (num.length() % 3 != 0) {
            num.insert(0, '0');
        }

        QList<QString> columnNames = {"Binary Number", "Octal Number"};
        table->setRowCount((int) num.length() / 3);
        table->setColumnCount(2);
        table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        table->verticalHeader()->setVisible(false);
        table->setHorizontalHeaderLabels(columnNames);
        table->setStyleSheet("QTableWidget::item { border: 1px solid white; }");
        QString result;

        for (int i = 0; i < table->rowCount(); i++) {
            QString temp = num.mid(i * 3, 3);
            auto binaryItem = new QTableWidgetItem(temp);
            auto octalItem = new QTableWidgetItem(values[temp]);

            table->setItem(i, 0, binaryItem);
            table->setItem(i, 1, octalItem);
            result.append(values[temp]);
        }

        return {table, result};
    }

    // Function used to transform binary to decimal.
    Result binaryToDecimal(QString num) {
        auto table = new QTableWidget();
        QList<QString> columnNames = {"Binary Number", "Decimal Number"};
        table->setRowCount((int) num.length());
        table->setColumnCount(2);
        table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        table->verticalHeader()->setVisible(false);
        table->setHorizontalHeaderLabels(columnNames);
        table->setStyleSheet("QTableWidget::item { border: 1px solid white; }");
        int result = 0;

        for (int i = 0; i < num.length(); i++) {
            auto binaryItem = new QTableWidgetItem(QString("2 ^ %1 * %2").arg(num.length() - 1 - i).arg(num[i]));
            auto decimalItem = new QTableWidgetItem(
                    QString::number(pow(2, num.length() - 1 - i) * num[i].digitValue()));

            table->setItem(i, 0, binaryItem);
            table->setItem(i, 1, decimalItem);

            result += (int) pow(2, num.length() - 1 - i) * num[i].digitValue();
        }

        return {table, QString::number(result)};
    }

    // Function used to transform binary to hexadecimal.
    Result binaryToHexadecimal(QString num) {
        auto table = new QTableWidget();
        std::unordered_map<QString, QChar> values = {
                {"0000", '0'},
                {"0001", '1'},
                {"0010", '2'},
                {"0011", '3'},
                {"0100", '4'},
                {"0101", '5'},
                {"0110", '6'},
                {"0111", '7'},
                {"1000", '8'},
                {"1001", '9'},
                {"1010", 'A'},
                {"1011", 'B'},
                {"1100", 'C'},
                {"1101", 'D'},
                {"1110", 'E'},
                {"1111", 'F'},
        };

        while (num.length() % 4 != 0) {
            num.insert(0, '0');
        }

        QList<QString> columnNames = {"Binary Number", "Hexadecimal Number"};
        table->setRowCount((int) num.length() / 4);
        table->setColumnCount(2);
        table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        table->verticalHeader()->setVisible(false);
        table->setHorizontalHeaderLabels(columnNames);
        table->setStyleSheet("QTableWidget::item { border: 1px solid white; }");
        QString result;

        for (int i = 0; i < table->rowCount(); i++) {
            auto binaryItem = new QTableWidgetItem(num.mid(i * 4, 4));
            auto hexadecimalItem = new QTableWidgetItem(values[num.mid(i * 4, 4)]);

            table->setItem(i, 0, binaryItem);
            table->setItem(i, 1, hexadecimalItem);
            result.append(values[num.mid(i * 4, 4)]);
        }

        return {table, result};
    }

    // Function used to transform octal to binary.
    Result octalToBinary(const QString &num) {
        auto table = new QTableWidget();
        std::unordered_map<QChar, QString> values = {
                {'0', "000"},
                {'1', "001"},
                {'2', "010"},
                {'3', "011"},
                {'4', "100"},
                {'5', "101"},
                {'6', "110"},
                {'7', "111"}
        };
        QList<QString> columnNames = {"Octal Number", "Binary Number"};
        table->setRowCount((int) num.length());
        table->setColumnCount(2);
        table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        table->verticalHeader()->setVisible(false);
        table->setHorizontalHeaderLabels(columnNames);
        table->setStyleSheet("QTableWidget::item { border: 1px solid white; }");
        QString result;

        for (int i = 0; i < table->rowCount(); i++) {
            auto octalItem = new QTableWidgetItem(num[i]);
            auto binaryItem = new QTableWidgetItem(values[num[i]]);

            table->setItem(i, 0, octalItem);
            table->setItem(i, 1, binaryItem);
            result.append(values[num[i]]);
        }

        return {table, result};
    }

    // Function used to transform octal to decimal.
    Result octalToDecimal(const QString &num) {
        auto table = new QTableWidget();
        QList<QString> columnNames = {"Octal Number", "Decimal Number"};
        table->setRowCount((int) num.length());
        table->setColumnCount(2);
        table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        table->verticalHeader()->setVisible(false);
        table->setHorizontalHeaderLabels(columnNames);
        table->setStyleSheet("QTableWidget::item { border: 1px solid white; }");
        int result = 0;

        for (int i = 0; i < num.length(); i++) {
            auto octalItem = new QTableWidgetItem(QString("8 ^ %1 * %2").arg(num.length() - 1 - i).arg(num[i]));
            auto decimalItem = new QTableWidgetItem(
                    QString::number(pow(8, num.length() - 1 - i) * num[i].digitValue()));

            table->setItem(i, 0, octalItem);
            table->setItem(i, 1, decimalItem);

            result += (int) pow(8, num.length() - 1 - i) * num[i].digitValue();
        }

        return {table, QString::number(result)};
    }

    // Function used to transform octal to hexadecimal.
    LargerResult octalToHexadecimal(const QString &num) {
        Result result1 = octalToBinary(num);
        Result result2 = binaryToHexadecimal(result1.getNum());

        return {result1.getTable(), result1.getNum(), result2.getTable(), result2.getNum()};
    }

    // Function used to transform decimal to binary.
    Result decimalToBinary(const QString &num) {
        auto table = new QTableWidget();
        int n = num.toInt();
        int countRows = 0;

        while (n) {
            countRows++;
            n /= 2;
        }

        QList<QString> columnNames = {"Decimal Number", "Quotient Number", "Binary Number"};
        table->setRowCount((int) countRows);
        table->setColumnCount(3);
        table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        table->verticalHeader()->setVisible(false);
        table->setHorizontalHeaderLabels(columnNames);
        table->setStyleSheet("QTableWidget::item { border: 1px solid white; }");
        QString result;

        n = num.toInt();

        for (int i = 0; i < table->rowCount(); i++) {
            auto decimalItem = new QTableWidgetItem(QString("%1 / 2").arg(n));
            auto quotientItem = new QTableWidgetItem(QString::number(n / 2));
            auto binaryNumber = new QTableWidgetItem(QString::number(n % 2));

            table->setItem(i, 0, decimalItem);
            table->setItem(i, 1, quotientItem);
            table->setItem(i, 2, binaryNumber);
            result.insert(0, QString::number(n % 2));
            n /= 2;
        }

        return {table, result};
    }

    // Function used to transform decimal to octal.
    Result decimalToOctal(const QString &num) {
        auto table = new QTableWidget();
        int n = num.toInt();
        int countRows = 0;

        while (n) {
            countRows++;
            n /= 8;
        }

        QList<QString> columnNames = {"Decimal Number", "Quotient Number", "Octal Number"};
        table->setRowCount((int) countRows);
        table->setColumnCount(3);
        table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        table->verticalHeader()->setVisible(false);
        table->setHorizontalHeaderLabels(columnNames);
        table->setStyleSheet("QTableWidget::item { border: 1px solid white; }");
        QString result;

        n = num.toInt();

        for (int i = 0; i < table->rowCount(); i++) {
            auto decimalItem = new QTableWidgetItem(QString("%1 / 8").arg(n));
            auto quotientItem = new QTableWidgetItem(QString::number(n / 8));
            auto octalItem = new QTableWidgetItem(QString::number(n % 8));

            table->setItem(i, 0, decimalItem);
            table->setItem(i, 1, quotientItem);
            table->setItem(i, 2, octalItem);
            result.insert(0, QString::number(n % 8));
            n /= 8;
        }

        return {table, result};
    }

    // Function used to transform decimal to hexadecimal.
    Result decimalToHexadecimal(const QString &num) {
        std::unordered_map<int, QChar> values = {
                {0,  '0'},
                {1,  '1'},
                {2,  '2'},
                {3,  '3'},
                {4,  '4'},
                {5,  '5'},
                {6,  '6'},
                {7,  '7'},
                {8,  '8'},
                {9,  '9'},
                {10, 'A'},
                {11, 'B'},
                {12, 'C'},
                {13, 'D'},
                {14, 'E'},
                {15, 'F'},
        };

        auto table = new QTableWidget();
        int n = num.toInt();
        int countRows = 0;

        while (n) {
            countRows++;
            n /= 8;
        }

        QList<QString> columnNames = {"Decimal Number", "Quotient Number", "Octal Number"};
        table->setRowCount((int) countRows);
        table->setColumnCount(3);
        table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        table->verticalHeader()->setVisible(false);
        table->setHorizontalHeaderLabels(columnNames);
        table->setStyleSheet("QTableWidget::item { border: 1px solid white; }");
        QString result;

        n = num.toInt();

        for (int i = 0; i < table->rowCount(); i++) {
            auto decimalItem = new QTableWidgetItem(QString("%1 / 16").arg(n));
            auto quotientItem = new QTableWidgetItem(QString::number(n / 16));
            auto binaryNumber = new QTableWidgetItem(values[n % 16]);

            table->setItem(i, 0, decimalItem);
            table->setItem(i, 1, quotientItem);
            table->setItem(i, 2, binaryNumber);
            result.insert(0, values[n % 16]);
            n /= 16;
        }

        return {table, result};
    }

    // Function used to transform hexadecimal to binary.
    Result hexadecimalToBinary(const QString &num) {
        std::unordered_map<QChar, QString> values = {
                {'0', "0000"},
                {'1', "0001"},
                {'2', "0010"},
                {'3', "0011"},
                {'4', "0100"},
                {'5', "0101"},
                {'6', "0110"},
                {'7', "0111"},
                {'8', "1000"},
                {'9', "1001"},
                {'A', "1010"},
                {'B', "1011"},
                {'C', "1100"},
                {'D', "1101"},
                {'E', "1110"},
                {'F', "1111"},
        };

        auto table = new QTableWidget();
        QList<QString> columnNames = {"Hexadecimal Number", "Binary Number"};
        table->setRowCount((int) num.length());
        table->setColumnCount(2);
        table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        table->verticalHeader()->setVisible(false);
        table->setHorizontalHeaderLabels(columnNames);
        table->setStyleSheet("QTableWidget::item { border: 1px solid white; }");
        QString result;

        for (int i = 0; i < table->rowCount(); i++) {
            auto hexadecimalItem = new QTableWidgetItem(num[i]);
            auto binaryItem = new QTableWidgetItem(values[num[i]]);

            table->setItem(i, 0, hexadecimalItem);
            table->setItem(i, 1, binaryItem);
            result.append(values[num[i]]);
        }

        return {table, result};
    }

    // Function used to transform hexadecimal to octal.
    LargerResult hexadecimalToOctal(const QString &num) {
        Result result1 = hexadecimalToBinary(num);
        Result result2 = binaryToOctal(result1.getNum());
        return {result1.getTable(), result1.getNum(), result2.getTable(), result2.getNum()};
    }

    // Function used to transform hexadecimal to decimal.
    Result hexadecimalToDecimal(const QString &num) {
        std::unordered_map<QChar, int> values = {
                {'0', 0},
                {'1', 1},
                {'2', 2},
                {'3', 3},
                {'4', 4},
                {'5', 5},
                {'6', 6},
                {'7', 7},
                {'8', 8},
                {'9', 9},
                {'A', 10},
                {'B', 11},
                {'C', 12},
                {'D', 13},
                {'E', 14},
                {'F', 15},
        };

        auto table = new QTableWidget();
        QList<QString> columnNames = {"Hexadecimal Number", "Decimal Number"};
        table->setRowCount((int) num.length());
        table->setColumnCount(2);
        table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        table->verticalHeader()->setVisible(false);
        table->setHorizontalHeaderLabels(columnNames);
        table->setStyleSheet("QTableWidget::item { border: 1px solid white; }");
        int result = 0;

        for (int i = 0; i < num.length(); i++) {
            auto hexadecimalItem = new QTableWidgetItem(
                    QString("16 ^ %1 * %2").arg(num.length() - 1 - i).arg(values[num[i]]));
            auto decimalItem = new QTableWidgetItem(
                    QString::number(pow(16, num.length() - 1 - i) * values[num[i]]));

            table->setItem(i, 0, hexadecimalItem);
            table->setItem(i, 1, decimalItem);

            result += (int) pow(16, num.length() - 1 - i) * values[num[i]];
        }

        return {table, QString::number(result)};
    }

    // Method used to check if a system is valid.
    // If the system in not valid it will true and false if the system is valid.
    bool checkSystem(const QString &num, int system) {
        if (num.isEmpty()) {
            return false;
        }

        switch (system) {
            case 2: {
                std::unordered_set<QChar> digits = {'0', '1'};

                for (const QChar &digit: num) {
                    if (digits.count(digit) == 0) {
                        return true;
                    }
                }
                return false;
            }
            case 8: {
                std::unordered_set<QChar> digits = {'0', '1', '2', '3', '4', '5', '6', '7'};

                for (const QChar &digit: num) {
                    if (digits.count(digit) == 0) {
                        return true;
                    }
                }
                return false;
            }
            case 10: {
                std::unordered_set<QChar> digits = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

                for (const QChar &digit: num) {
                    if (digits.count(digit) == 0) {
                        return true;
                    }
                }
                return false;
            }
            case 16: {
                std::unordered_set<QChar> digits = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C',
                                                    'D', 'E', 'F'};

                for (const QChar &digit: num) {
                    if (digits.count(digit) == 0) {
                        return true;
                    }
                }
                return false;
            }
            default: {
                throw std::invalid_argument("The system is not made for the function");
            }
        }
    }
}
class Window : public QWidget {
Q_OBJECT

private:
    // Main layout of the window.
    QGridLayout *layout = new QGridLayout();
    // Line edits used to display and get the systems.
    QLineEdit *inputLineEdit = new QLineEdit();
    QLineEdit *resultLineEdit = new QLineEdit();
    // Combo boxes used to select the systems.
    QComboBox *inputSystems = new QComboBox();
    QComboBox *resultSystems = new QComboBox();
    // Layout used by the frame that shows the information tables.
    QGridLayout *frameLayout = new QGridLayout();
public:
    explicit Window(QWidget *parent = nullptr) : QWidget(parent) {
        // Setting attributes to the window.
        this->setWindowTitle("Numeral system transformation");
        this->setGeometry(300, 300, 400, 600);

        // Creating the UI.
        this->setLayout(layout);
        createUI();
    }

private:
    void createUI() {
        // Creating the widgets.
        auto transformButton = new QPushButton("Transform");
        auto resultFrame = new QFrame();

        // Setting attributes to the widgets.
        QString systems[] = {"Binary", "Octal", "Decimal", "Hexadecimal"};
        for (const QString &system: systems) {
            inputSystems->addItem(system);
            resultSystems->addItem(system);
        }

        resultFrame->setLayout(frameLayout);

        // Connecting the widgets.
        connect(transformButton, &QPushButton::clicked, [=]() { onTransformButtonClicked(); });

        // Adding the widgets.
        layout->addWidget(inputSystems, 0, 0);
        layout->addWidget(resultSystems, 0, 1);
        layout->addWidget(inputLineEdit, 1, 0, 1, 2);
        layout->addWidget(transformButton, 2, 0, 1, 2);
        layout->addWidget(resultLineEdit, 3, 0, 1, 2);
        layout->addWidget(resultFrame, 4, 0, 1, 2);
    }

    // Method used to transform the system that will be activated when the user clicks transform button.
    void onTransformButtonClicked() {
        QString inputSystem = inputSystems->currentText();
        QString resultSystem = resultSystems->currentText();
        QString num = inputLineEdit->text().toUpper();

        cleanResultFrame();

        if (inputSystem == "Binary") {
            if (TransformSystems::checkSystem(num, 2)) {
                QMessageBox::warning(this, "Error", "The inputs is not valid");
                return;
            }

            if (resultSystem == "Binary") {
                resultLineEdit->setText(num);
            } else if (resultSystem == "Octal") {
                TransformSystems::Result result = TransformSystems::binaryToOctal(num);
                frameLayout->addWidget(result.getTable(), 0, 0);
                resultLineEdit->setText(result.getNum());
            } else if (resultSystem == "Decimal") {
                TransformSystems::Result result = TransformSystems::binaryToDecimal(num);
                frameLayout->addWidget(result.getTable(), 0, 0);
                resultLineEdit->setText(result.getNum());
            } else {
                TransformSystems::Result result = TransformSystems::binaryToHexadecimal(num);
                frameLayout->addWidget(result.getTable(), 0, 0);
                resultLineEdit->setText(result.getNum());
            }
        } else if (inputSystem == "Octal") {
            if (TransformSystems::checkSystem(num, 8)) {
                QMessageBox::warning(this, "Error", "The inputs is not valid");
                return;
            }

            if (resultSystem == "Binary") {
                TransformSystems::Result result = TransformSystems::octalToBinary(num);
                frameLayout->addWidget(result.getTable(), 0, 0);
                resultLineEdit->setText(result.getNum());
            } else if (resultSystem == "Octal") {
                resultLineEdit->setText(num);
            } else if (resultSystem == "Decimal") {
                TransformSystems::Result result = TransformSystems::octalToDecimal(num);
                frameLayout->addWidget(result.getTable(), 0, 0);
                resultLineEdit->setText(result.getNum());
            } else {
                TransformSystems::LargerResult result = TransformSystems::octalToHexadecimal(num);
                frameLayout->addWidget(result.getTable1(), 0, 0);
                frameLayout->addWidget(new QLabel(QString("Binary Number: %1").arg(result.getNum1())), 1, 0);
                frameLayout->addWidget(result.getTable2(), 2, 0);
                resultLineEdit->setText(result.getNum2());
            }
        } else if (inputSystem == "Decimal") {
            if (TransformSystems::checkSystem(num, 10)) {
                QMessageBox::warning(this, "Error", "The inputs is not valid");
                return;
            }

            if (resultSystem == "Binary") {
                TransformSystems::Result result = TransformSystems::decimalToBinary(num);
                frameLayout->addWidget(result.getTable(), 0, 0);
                resultLineEdit->setText(result.getNum());
            } else if (resultSystem == "Octal") {
                TransformSystems::Result result = TransformSystems::decimalToOctal(num);
                frameLayout->addWidget(result.getTable(), 0, 0);
                resultLineEdit->setText(result.getNum());
            } else if (resultSystem == "Decimal") {
                resultLineEdit->setText(num);
            } else {
                TransformSystems::Result result = TransformSystems::decimalToHexadecimal(num);
                frameLayout->addWidget(result.getTable(), 0, 0);
                resultLineEdit->setText(result.getNum());
            }
        } else {
            if (TransformSystems::checkSystem(num, 16)) {
                QMessageBox::warning(this, "Error", "The inputs is not valid");
                return;
            }

            if (resultSystem == "Binary") {
                TransformSystems::Result result = TransformSystems::hexadecimalToBinary(num);
                frameLayout->addWidget(result.getTable(), 0, 0);
                resultLineEdit->setText(result.getNum());
            } else if (resultSystem == "Octal") {
                TransformSystems::LargerResult result = TransformSystems::hexadecimalToOctal(num);
                frameLayout->addWidget(result.getTable1(), 0, 0);
                frameLayout->addWidget(new QLabel(QString("Binary Number: %1").arg(result.getNum1())), 1, 0);
                frameLayout->addWidget(result.getTable2(), 2, 0);
                resultLineEdit->setText(result.getNum2());
            } else if (resultSystem == "Decimal") {
                TransformSystems::Result result = TransformSystems::hexadecimalToDecimal(num);
                frameLayout->addWidget(result.getTable(), 0, 0);
                resultLineEdit->setText(result.getNum());
            } else {
                resultLineEdit->setText(num);
            }
        }
    }

    // Method that will clean the result frame.
    void cleanResultFrame() {
        QLayoutItem *layoutItem;

        while ((layoutItem = frameLayout->takeAt(0)) != nullptr) {
            QWidget *widget = layoutItem->widget();

            if (widget != nullptr) {
                frameLayout->removeWidget(widget);
                delete widget;
            }
            delete layoutItem;
        }

    }
};

int main(int argc, char *argv[]) {
    QApplication application(argc, argv);
    Window window;
    window.show();
    return QApplication::exec();
}

#include "main.moc"

