def binary_to_octal(num: str) -> str:
    bin_to_oct = {
        '000': '0',
        '001': '1',
        '010': '2',
        '011': '3',
        '100': '4',
        '101': '5',
        '110': '6',
        '111': '7'
    }

    while len(num) % 3 != 0:
        num = '0' + num

    values = [num[i:i + 3] for i in range(0, len(num), 3)]
    text = str(values) + ' =' + '\n'

    for n in values:
        text += bin_to_oct[n]
    return text


def binary_to_decimal(num: str) -> str:
    text_1 = ''
    text_2 = ''
    position = 0
    length = len(num)

    for i in range(-1, -length - 1, -1):
        if i != -length:
            text_1 += f"{num[i]} * 2^{position} + "
            text_2 += str(eval(f"{num[i]}*2**{position}")) + " + "
        else:
            text_1 += f"{num[i]} * 2^{position} =\n"
            text_2 += str(eval(f"{num[i]} * 2**{position}")) + " =\n"
        position += 1

    text = text_1 + text_2 + str(int(num, 2))
    return text


def binary_to_hexadecimal(num: str) -> str:
    bin_to_hex = {
        '0000': '0',
        '0001': '1',
        '0010': '2',
        '0011': '3',
        '0100': '4',
        '0101': '5',
        '0110': '6',
        '0111': '7',
        '1000': '8',
        '1001': '9',
        '1010': 'A',
        '1011': 'B',
        '1100': 'C',
        '1101': 'D',
        '1110': 'E',
        '1111': 'F'
    }
    while len(num) % 4 != 0:
        num = '0' + num

    values = [num[i:i + 4] for i in range(0, len(num), 4)]
    text = str(values) + ' =' + '\n'

    for n in values:
        text += bin_to_hex[n]

    return text


def octal_to_binary(num: str) -> str:
    result = str(list(num)) + '\n'
    oct_to_bin = {
        '0': '000',
        '1': '001',
        '2': '010',
        '3': '011',
        '4': '100',
        '5': '101',
        '6': '110',
        '7': '111',
    }

    for digit in num:
        result += oct_to_bin[digit] + "|"

    return result


def octal_to_decimal(num: str) -> str:
    text_1 = ''
    text_2 = ''
    position = 0
    length = len(num)

    for i in range(-1, -length - 1, -1):
        if i != -length:
            text_1 += f"{num[i]} * 8^{position} + "
            text_2 += str(eval(f"{num[i]}*8**{position}")) + " + "
        else:
            text_1 += f"{num[i]} * 8^{position} =\n"
            text_2 += str(eval(f"{num[i]} * 8**{position}")) + " =\n"
        position += 1

    text = text_1 + text_2 + str(int(num, 8))
    return text


def octal_to_hexadecimal(num: str) -> str:
    result = octal_to_binary(num)
    result += '\n'
    result += binary_to_hexadecimal(bin(int(num, 8))[2:])
    return result


def decimal_to_binary(num: str) -> str:
    num = int(num)
    text = ""
    answer = ""

    while num != 0:
        text += f"{num} / 2 = {num // 2} + remainder = {num % 2}\n"
        answer += f"{num % 2} "
        num //= 2

    return text + answer[::-1]


def decimal_to_octal(num: str) -> str:
    num = int(num)
    text = ""
    answer = ""

    while num != 0:
        text += f"{num} / 8 = {num // 8} + remainder = {num % 8}\n"
        answer += f"{num % 8}"
        num //= 8

    return text + answer[::-1]


def decimal_to_hexadecimal(num: str) -> str:
    num = int(num)
    text = ""
    answer = ""
    dec_to_hex = {
        1: '1',
        2: '2',
        3: '3',
        4: '4',
        5: '5',
        6: '6',
        7: '7',
        8: '8',
        9: '9',
        10: 'A',
        11: 'B',
        12: 'C',
        13: 'D',
        14: 'E',
        15: 'F',
    }

    while num != 0:
        text += f"{num} / 16 = {num // 16} + remainder = {num % 16} = {dec_to_hex[num % 16]}\n"
        answer += f"{dec_to_hex[num % 16]}"
        num //= 16

    return text + answer[::-1]


def hexadecimal_to_binary(num: str) -> str:
    result = str(list(num)) + '\n'
    hexa_to_bin = {
        '0': '0000',
        '1': '0001',
        '2': '0010',
        '3': '0011',
        '4': '0100',
        '5': '0101',
        '6': '0110',
        '7': '0111',
        '8': '1000',
        '9': '1001',
        'A': '1010',
        'B': '1011',
        'C': '1100',
        'D': '1101',
        'E': '1110',
        'F': '1111'
    }

    for digit in num:
        result += hexa_to_bin[digit] + '|'

    return result


def hexadecimal_to_octal(num: str) -> str:
    return hexadecimal_to_binary(num) + '\n' + binary_to_octal(bin(int(num, 16))[2:])


def hexadecimal_to_decimal(num: str) -> str:
    hex_to_dec = {
        '0': '0',
        '1': '1',
        '2': '2',
        '3': '3',
        '4': '4',
        '5': '5',
        '6': '6',
        '7': '7',
        '8': '8',
        '9': '9',
        'A': '10',
        'B': '11',
        'C': '12',
        'D': '13',
        'E': '14',
        'F': '15'
    }
    text_1 = ''
    text_2 = ''
    position = 0
    length = len(num)

    for i in range(-1, -length - 1, -1):
        if i != -length:
            text_1 += f"{hex_to_dec[num[i]]} * 16^{position} + "
            text_2 += str(eval(f"{hex_to_dec[num[i]]}*16**{position}")) + " + "
        else:
            text_1 += f"{hex_to_dec[num[i]]} * 16^{position} =\n"
            text_2 += str(eval(f"{hex_to_dec[num[i]]} * 16**{position}")) + " =\n"
        position += 1

    text = text_1 + text_2 + str(int(num, 16))
    return text


def is_binary(num: str) -> bool:
    if len(num) == 0:
        return False

    for digit in num:
        if digit != '0' and digit != '1':
            return False

    return True


def is_octal(num: str) -> bool:
    if len(num) == 0:
        return False

    check = ('0', '1', '2', '3', '4', '5', '6', '7')
    for digit in num:
        if digit not in check:
            return False

    return True


def is_decimal(num: str) -> bool:
    if len(num) == 0:
        return False

    check = ('0', '1', '2', '3', '4', '5', '6', '7', '8', '9')
    for digit in num:
        if digit not in check:
            return False

    return True


def is_hexadecimal(num: str) -> bool:
    if len(num) == 0:
        return False

    check = ('0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F')
    for digit in num:
        if digit not in check:
            return False

    return True
