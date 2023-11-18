#include <QString>
#include <cmath>
#include <unordered_map>
#include <QSet>

QString transformBynary(QString &num, int system) {

    switch (system) {
        case 2: {
            return num;
        }
        case 8: {
            std::unordered_map<QString, QString> transform = {
                    {"000", "0"},
                    {"001", "1"},
                    {"010", "2"},
                    {"011", "3"},
                    {"100", "4"},
                    {"101", "5"},
                    {"110", "6"},
                    {"111", "7"}
            };
            QString text1;
            QString text2;
            while (num.size() % 3 != 0) {
                num = "0" + num;
            }

            for (int i = 0; i < num.size(); i++) {
                text1 += num[i];
                if ((i + 1) % 3 == 0) {
                    text1 += "|";
                }
            }

            for (int i = 0; i <= num.size() - 3; i += 3) {
                text2 += transform[num.mid(i, 3)];
            }

            return text1 + " =\n" + text2;
        }
        case 10: {
            QString text1;
            QString text2;
            int result = 0;
            int position = 0;
            for (int i = num.size() - 1; i >= 0; i--) {
                if (i != 0) {
                    text1 += QString("%1 * 2 ^ %2 + ").arg(num[i]).arg(position);
                    text2 += QString("%1 + ").arg(num[i].digitValue() * pow(2, position));
                } else {

                    text1 += QString("%1 * 2 ^ %2 =\n").arg(num[i]).arg(position);
                    text2 += QString("%1 =\n").arg(num[i].digitValue() * pow(2, position));
                }

                result += (int) num[i].digitValue() * (int) pow(2, position);

                position++;
            }

            return text1 + text2 + QString::number(result);
        }
        case 16: {
            std::unordered_map<QString, QString> transform = {
                    {"0000", "0"},
                    {"0001", "1"},
                    {"0010", "2"},
                    {"0011", "3"},
                    {"0100", "4"},
                    {"0101", "5"},
                    {"0110", "6"},
                    {"0111", "7"},
                    {"1000", "8"},
                    {"1001", "9"},
                    {"1010", "A"},
                    {"1011", "B"},
                    {"1100", "C"},
                    {"1101", "D"},
                    {"1110", "E"},
                    {"1111", "F"},
            };
            QString text1;
            QString text2;

            while (num.size() % 4 != 0) {
                num = "0" + num;
            }

            for (int i = 0; i < num.size(); i++) {
                text1 += num[i];
                if ((i + 1) % 4 == 0) {
                    text1 += "|";
                }
            }

            for (int i = 0; i <= num.size(); i += 4) {
                text2 += transform[num.mid(i, 4)];
            }

            return text1 + " =\n" + text2;
        }
        default: {
            throw std::invalid_argument("The system that was put is invalid ");
        }
    }
}

QString transformOctal(QString &num, int system) {
    switch (system) {
        case 2: {
            QString text;
            std::unordered_map<QString, QString> transform = {
                    {"0", "000"},
                    {"1", "001"},
                    {"2", "010"},
                    {"3", "011"},
                    {"4", "100"},
                    {"5", "101"},
                    {"6", "110"},
                    {"7", "111"}
            };

            for (QChar digit: num) {
                text += transform[digit];
            }

            return text;
        }
        case 8: {
            return num;
        }
        case 10: {
            QString text1;
            QString text2;
            int position = 0;
            int result = 0;

            for (int i = num.size() - 1; i >= 0; i--) {
                if (i != 0) {
                    text1 += QString("%1 * 8 ^ %2 + ").arg(num[i]).arg(position);
                    text2 += QString("%1 + ").arg(num[i].digitValue() * pow(8, position));
                } else {
                    text1 += QString("%1 * 8 ^ %2 =\n").arg(num[i]).arg(position);
                    text2 += QString("%1 =\n").arg(num[i].digitValue() * pow(8, position));
                }

                result += (int) num[i].digitValue() * (int) pow(8, position);
                position++;
            }

            return text1 + text2 + QString::number(result);
        }
        case 16: {
            QString text;
            std::unordered_map<QString, QString> transform = {
                    {"0", "000"},
                    {"1", "001"},
                    {"2", "010"},
                    {"3", "011"},
                    {"4", "100"},
                    {"5", "101"},
                    {"6", "110"},
                    {"7", "111"}
            };

            for (QChar digit: num) {
                text += transform[digit];
            }

            return text + '\n' + transformBynary(text, 16);
        }
        default: {
            throw std::invalid_argument("The system that was put is invalid ");
        }
    }
}

QString transformDecimal(QString &num, int system) {
    int n = num.toInt();
    switch (system) {
        case 2: {
            QString text1;
            QString text2;
            while (n) {
                text1 += (QString("%1 : 2 = %2 + remainder %3 \n")).arg(n).arg(n / 2).arg(n % 2);
                text2 = QString::number(n % 2) + text2;
                n /= 2;
            }

            return text1 + text2;
        }
        case 8: {
            QString text1;
            QString text2;
            while (n) {
                text1 += (QString("%1 : 8 = %2 + remainder %3 \n")).arg(n).arg(n / 8).arg(n % 8);
                text2 = QString::number(n % 8) + text2;
                n /= 8;
            }

            return text1 + text2;
        }
        case 10: {
            return num;
        }
        case 16: {
            std::unordered_map<int, QString> transform = {
                    {0,  "0"},
                    {1,  "1"},
                    {2,  "2"},
                    {3,  "3"},
                    {4,  "4"},
                    {5,  "5"},
                    {6,  "6"},
                    {7,  "7"},
                    {8,  "8"},
                    {9,  "9"},
                    {10, "A"},
                    {11, "B"},
                    {11, "C"},
                    {13, "D"},
                    {14, "E"},
                    {15, "F"}
            };

            QString text1;
            QString text2;

            while (n) {
                text1 += (QString("%1 : 16 = %2 + remainder %3 = %4 \n")).arg(n).arg(n / 16).arg(n % 16).arg(
                        transform[n % 16]);
                text2 = transform[n % 16] + text2;
                n /= 16;
            }

            return text1 + text2;
        }
        default: {
            throw std::invalid_argument("The system that was put is invalid ");
        }
    }
}

QString transformHexadecimal(QString &num, int system) {
    switch (system) {
        case 2: {
            std::unordered_map<QString, QString> transform = {
                    {"0", "0000"},
                    {"1", "0001"},
                    {"2", "0010"},
                    {"3", "0011"},
                    {"4", "0100"},
                    {"5", "0101"},
                    {"6", "0110"},
                    {"7", "0111"},
                    {"8", "1000"},
                    {"9", "1001"},
                    {"A", "1010"},
                    {"B", "1011"},
                    {"C", "1100"},
                    {"D", "1101"},
                    {"E", "1110"},
                    {"F", "1111"}
            };
            QString text;

            for (QChar digit: num) {
                text += transform[digit];
            }

            return text;
        }
        case 8: {
            std::unordered_map<QString, QString> transform = {
                    {"0", "0000"},
                    {"1", "0001"},
                    {"2", "0010"},
                    {"3", "0011"},
                    {"4", "0100"},
                    {"5", "0101"},
                    {"6", "0110"},
                    {"7", "0111"},
                    {"8", "1000"},
                    {"9", "1001"},
                    {"A", "1010"},
                    {"B", "1011"},
                    {"C", "1100"},
                    {"D", "1101"},
                    {"E", "1110"},
                    {"F", "1111"}
            };
            QString text;

            for (QChar digit: num) {
                text += transform[digit];
            }

            return text + '\n' + transformBynary(text, 8);

        }
        case 10: {
            std::unordered_map<QString, int> transform = {
                    {"0", 0},
                    {"1", 1},
                    {"2", 2},
                    {"3", 3},
                    {"4", 4},
                    {"5", 5},
                    {"6", 6},
                    {"7", 7},
                    {"8", 8},
                    {"9", 9},
                    {"A", 10},
                    {"B", 11},
                    {"C", 12},
                    {"D", 13},
                    {"E", 14},
                    {"F", 15}
            };
            QString text1;
            QString text2;
            int position = 0;
            int result = 0;

            for (int i = num.size() - 1; i >= 0; i--) {
                if (i != 0) {
                    text1 += QString("%1 * 16 ^ %2 + ").arg(transform[QString(num[i])]).arg(position);
                    text2 += QString("%1 + ").arg(transform[QString(num[i])] * pow(16, position));
                } else {
                    text1 += QString("%1 * 16 ^ %2 =\n").arg(transform[QString(num[i])]).arg(position);
                    text2 += QString("%1 =\n").arg(transform[QString(num[i])] * pow(16, position));
                }

                result += (int) transform[QString(num[i])] * (int) pow(16, position);
                position++;
            }

            return text1 + text2 + QString::number(result);
        }
        case 16: {
            return num;
        }
        default: {
            throw std::invalid_argument("The system that was put is invalid ");
        }
    }
}

bool checkForValidSystem(QString &num, int system) {
    switch (system) {
        case 2: {
            QSet<QChar> binary = {'1', '0'};

            for (QChar digit: num) {
                if (!binary.contains(digit)) {
                    return false;
                }
            }

            return true;
        }
        case 8: {
            QSet<QChar> octal = {'0', '1', '2', '3', '4', '5', '6', '7'};

            for (QChar digit: num) {
                if (!octal.contains(digit)) {
                    return false;
                }
            }

            return true;
        }

        case 10: {
            QSet<QChar> decimal = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

            for (QChar digit: num) {
                if (!decimal.contains(digit)) {
                    return false;
                }
            }
            return true;

        }
        case 16: {
            QSet<QChar> hexadecimal = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

            for (QChar digit: num) {
                if (!hexadecimal.contains(digit)) {
                    return false;
                }
            }
            return true;
        }
        default: {
            throw std::invalid_argument("The system that was put is invalid ");
        }
    }


}