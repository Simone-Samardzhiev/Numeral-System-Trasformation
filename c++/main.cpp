#include <QApplication>
#include <QString>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include "functions.h"

class window : public QWidget {
Q_OBJECT

private:
    QGridLayout *layout = new QGridLayout;
    QLineEdit *lineEdit = new QLineEdit;
    QComboBox *box1 = new QComboBox;
    QComboBox *box2 = new QComboBox;
    QPushButton *button = new QPushButton;
    QLabel *result = new QLabel;
public:
    explicit window(QWidget *parent = nullptr) : QWidget(parent) {
        this->setGeometry(100, 100, 500, 400);
        this->setWindowTitle("Numeral system transformation");

        this->box1->addItem("2");
        this->box1->addItem("8");
        this->box1->addItem("10");
        this->box1->addItem("16");

        this->box2->addItem("2");
        this->box2->addItem("8");
        this->box2->addItem("10");
        this->box2->addItem("16");

        this->button->setText("Transform");
        connect(this->button, &QPushButton::clicked, this, &window::convert);

        this->layout->addWidget(lineEdit, 0, 0);
        this->layout->addWidget(box1, 1, 0);
        this->layout->addWidget(result, 2, 0);
        this->layout->addWidget(box2, 3, 0);
        this->layout->addWidget(button, 4, 0);

        this->setLayout(this->layout);
    }

    void convert() {
        QString num = this->lineEdit->text();
        int baseSystem;
        int newSystem;

        switch (box1->currentIndex()) {
            case 0:
                baseSystem = 2;
                break;
            case 1:
                baseSystem = 8;
                break;
            case 2:
                baseSystem = 10;
                break;
            case 3: {
                baseSystem = 16;
            }
        }

        switch (box2->currentIndex()) {
            case 0:
                newSystem = 2;
                break;
            case 1:
                newSystem = 8;
                break;
            case 2:
                newSystem = 10;
                break;
            case 3: {
                newSystem = 16;
            }
        }

        if (checkForValidSystem(num, baseSystem)) {
            switch (baseSystem) {
                case 2:
                    this->result->setText(transformBynary(num, newSystem));
                    break;
                case 8:
                    this->result->setText(transformOctal(num, newSystem));
                    break;
                case 10:
                    this->result->setText(transformDecimal(num, newSystem));
                    break;
                case 16:
                    this->result->setText(transformHexadecimal(num, newSystem));
                    break;
                default:
                    this->result->setText("There was an error !");
            }
        } else {
            this->result->setText("The input is invalid");
        }

    }
};


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    window myWindow;

    myWindow.show();

    return QApplication::exec();
}


#include "main.moc"