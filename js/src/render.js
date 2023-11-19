function transformBinary(num, system) {
  switch (system) {
    case 8: {
      const transform = new Map();

      transform.set("000", 0);
      transform.set("001", 1);
      transform.set("010", 2);
      transform.set("011", 3);
      transform.set("100", 4);
      transform.set("101", 5);
      transform.set("110", 6);
      transform.set("111", 7);

      let result = "";
      let text = "";

      while (num.length % 3 != 0) {
        num = "0" + num;
      }

      for (let i = 0; i < num.length; i++) {
        if (i % 3 == 0) {
          text += "|";
        }
        text += num[i];
      }

      text += "|";

      for (let i = 0; i <= num.length - 3; i += 3) {
        result += transform.get(num.substring(i, i + 3));
      }

      return text + "= \n" + result;
    }
    case 10: {
      let text1 = "";
      let text2 = "";
      let position = 0;
      let decimalResult = 0;

      for (let i = num.length - 1; i >= 0; i--) {
        decimalResult += parseInt(num[i]) * Math.pow(2, position);

        if (i != 0) {
          text1 += `${num[i]} * 2 ^ ${position} + `;
          text2 += `${num[i] * Math.pow(2, position)} + `;
        } else {
          text1 += `${num[i]} * 2 ^ ${position} =`;
          text2 += `${num[i] * Math.pow(2, position)} =`;
        }

        position++;
      }

      return text1 + "\n" + text2 + "\n" + decimalResult;
    }
    case 16: {
      const transform = new Map();

      transform.set("0000", "0");
      transform.set("0001", "1");
      transform.set("0010", "2");
      transform.set("0011", "3");
      transform.set("0100", "4");
      transform.set("0101", "5");
      transform.set("0110", "6");
      transform.set("0111", "7");
      transform.set("1000", "8");
      transform.set("1001", "9");
      transform.set("1010", "A");
      transform.set("1011", "B");
      transform.set("1100", "C");
      transform.set("1101", "D");
      transform.set("1110", "E");
      transform.set("1111", "F");

      let result = "";
      let text = "";

      while (num.length % 4 != 0) {
        num = "0" + num;
      }

      for (let i = 0; i < num.length; i++) {
        if (i % 4 == 0) {
          text += "|";
        }
        text += num[i];
      }
      text += "|";

      for (let i = 0; i <= num.length - 4; i += 4) {
        result += transform.get(num.substring(i, i + 4));
      }

      return text + "= \n" + result;
    }
    default:
      return "";
  }
}

function transformOctal(num, system) {
  switch (system) {
    case 2: {
      const transform = new Map();

      transform.set("0", "000|");
      transform.set("1", "001|");
      transform.set("2", "010|");
      transform.set("3", "011|");
      transform.set("4", "100|");
      transform.set("5", "101|");
      transform.set("6", "110|");
      transform.set("7", "111|");

      let result = "|";

      for (let i = 0; i < num.length; i++) {
        result += transform.get(num[i]);
      }

      return result;
    }
    case 10: {
      let text1 = "";
      let text2 = "";
      let position = 0;
      let decimalResult = 0;

      for (let i = num.length - 1; i >= 0; i--) {
        decimalResult += parseInt(num[i]) * Math.pow(8, position);

        if (i != 0) {
          text1 += `${num[i]} * 8 ^ ${position} + `;
          text2 += `${num[i] * Math.pow(8, position)} + `;
        } else {
          text1 += `${num[i]} * 8 ^ ${position} =`;
          text2 += `${num[i] * Math.pow(8, position)} =`;
        }

        position++;
      }

      return text1 + "\n" + text2 + "\n" + decimalResult;
    }
    case 16: {
      const transform = new Map();

      transform.set("0", "000");
      transform.set("1", "001");
      transform.set("2", "010");
      transform.set("3", "011");
      transform.set("4", "100");
      transform.set("5", "101");
      transform.set("6", "110");
      transform.set("7", "111");

      let result = "|";
      let n = "";

      for (let i = 0; i < num.length; i++) {
        result += transform.get(num[i]) + "|";
        n += transform.get(num[i]);
      }
      console.log(result);
      console.log(n);
      return result + "\n" + transformBinary(num, 16);
    }
    default:
      return "";
  }
}

function transformDecimal(num, system) {
  num = parseInt(num, 10);
  switch (system) {
    case 2: {
      let text = "";
      let result = "";

      while (num != 0) {
        text += `${num} : 2 = ${Math.floor(num / 2)} + remainder ${num % 2} \n`;
        result = (num % 2) + result;
        num = Math.floor(num / 2);
      }

      return text + result;
    }
    case 8: {
      let text = "";
      let result = "";

      while (num != 0) {
        text += `${num} : 8 = ${Math.floor(num / 8)} + remainder ${num % 8} \n`;
        result = (num % 8) + result;
        num = Math.floor(num / 8);
      }

      return text + result;
    }
    case 16: {
      const transform = new Map();

      transform.set(0, "0");
      transform.set(1, "1");
      transform.set(2, "2");
      transform.set(3, "3");
      transform.set(4, "4");
      transform.set(5, "5");
      transform.set(6, "6");
      transform.set(7, "7");
      transform.set(8, "8");
      transform.set(9, "9");
      transform.set(10, "A");
      transform.set(11, "B");
      transform.set(12, "C");
      transform.set(13, "D");
      transform.set(14, "E");
      transform.set(15, "F");

      let text = "";
      let result = "";

      while (num != 0) {
        text += `${num} : 16 = ${Math.floor(num / 16)} + remainder ${
          num % 16
        } = ${transform.get(num % 16)}\n`;
        result = transform.get(num % 16) + result;
        num = Math.floor(num / 16);
      }

      return text + result;
    }
    default:
      return "";
  }
}

function transformHexadecimal(num, system) {
  switch (system) {
    case 2: {
      const transform = new Map();
      transform.set("0", "0000");
      transform.set("1", "0001");
      transform.set("2", "0010");
      transform.set("3", "0011");
      transform.set("4", "0100");
      transform.set("5", "0101");
      transform.set("6", "0110");
      transform.set("7", "0111");
      transform.set("8", "1000");
      transform.set("9", "1001");
      transform.set("A", "1010");
      transform.set("B", "1011");
      transform.set("C", "1100");
      transform.set("D", "1101");
      transform.set("E", "1110");
      transform.set("F", "1111");

      let result = "|";

      for (let i = 0; i < num.length; i++) {
        result += transform.get(num[i]) + "|";
      }

      return result;
    }
    case 8: {
      const transform = new Map();
      transform.set("0", "0000");
      transform.set("1", "0001");
      transform.set("2", "0010");
      transform.set("3", "0011");
      transform.set("4", "0100");
      transform.set("5", "0101");
      transform.set("6", "0110");
      transform.set("7", "0111");
      transform.set("8", "1000");
      transform.set("9", "1001");
      transform.set("A", "1010");
      transform.set("B", "1011");
      transform.set("C", "1100");
      transform.set("D", "1101");
      transform.set("E", "1110");
      transform.set("F", "1111");

      let result = "|";
      let n = "";

      for (let i = 0; i < num.length; i++) {
        result += transform.get(num[i]) + "|";
        n += transform.get(num[i]);
      }

      return result + "\n" + transformBinary(n, 8);
    }
    case 10: {
      const transform = new Map();

      transform.set("0", "0");
      transform.set("1", "1");
      transform.set("2", "2");
      transform.set("3", "3");
      transform.set("4", "4");
      transform.set("5", "5");
      transform.set("6", "6");
      transform.set("7", "7");
      transform.set("8", "8");
      transform.set("9", "9");
      transform.set("A", "10");
      transform.set("B", "11");
      transform.set("C", "12");
      transform.set("D", "13");
      transform.set("E", "14");
      transform.set("F", "15");

      let text1 = "";
      let text2 = "";
      let position = 0;
      let decimalResult = 0;

      for (let i = num.length - 1; i >= 0; i--) {
        decimalResult += transform.get(num[i]) * Math.pow(16, position);

        if (i != 0) {
          text1 += `${transform.get(num[i])} * 16 ^ ${position} + `;
          text2 += `${transform.get(num[i]) * Math.pow(16, position)} + `;
        } else {
          text1 += `${transform.get(num[i])} * 16 ^ ${position} =`;
          text2 += `${transform.get(num[i]) * Math.pow(16, position)} =`;
        }

        position++;
      }

      return text1 + "\n" + text2 + "\n" + decimalResult;
    }
    default:
      return "";
  }
}

let input = document.getElementById("input");
let firstOption = document.getElementById("first-option");
let secondOption = document.getElementById("second-option");
let result = document.getElementById("result");

input.addEventListener("input", (value) => {
  let number = input.value.toUpperCase();

  let isValidInput = false;
  switch (parseInt(firstOption.value)) {
    case 2:
      isValidInput = /^[01]+$/.test(number);
      break;
    case 8:
      isValidInput = /^[0-7]+$/.test(number);
      break;
    case 10:
      isValidInput = /^[0-9]+$/.test(number);
      break;
    case 16:
      isValidInput = /^[0-9A-Fa-f]+$/.test(number);
      break;
  }

  if (isValidInput) {
    switch (parseInt(firstOption.value)) {
      case 2: {
        switch (parseInt(secondOption.value)) {
          case 2: {
            result.textContent = transformBinary(number, 2);
            break;
          }
          case 8: {
            result.textContent = transformBinary(number, 8);
            break;
          }
          case 10: {
            result.textContent = transformBinary(number, 10);
            break;
          }
          case 16: {
            result.textContent = transformBinary(number, 16);
            break;
          }
        }
        break;
      }
      case 8: {
        switch (parseInt(secondOption.value)) {
          case 2: {
            result.textContent = transformOctal(number, 2);
            break;
          }
          case 8: {
            result.textContent = transformOctal(number, 8);
            break;
          }
          case 10: {
            result.textContent = transformOctal(number, 10);
            break;
          }
          case 16: {
            result.textContent = transformOctal(number, 16);
            break;
          }
        }
        break;
      }
      case 10: {
        switch (parseInt(secondOption.value)) {
          case 2: {
            result.textContent = transformDecimal(number, 2);
            break;
          }
          case 8: {
            result.textContent = transformDecimal(number, 8);
            break;
          }
          case 10: {
            result.textContent = transformDecimal(number, 10);
            break;
          }
          case 16: {
            result.textContent = transformDecimal(number, 16);
            break;
          }
        }
        break;
      }
      case 16:
        {
          switch (parseInt(secondOption.value)) {
            case 2: {
              result.textContent = transformHexadecimal(number, 2);
              break;
            }
            case 8: {
              result.textContent = transformHexadecimal(number, 8);
              break;
            }
            case 10: {
              result.textContent = transformHexadecimal(number, 10);
              break;
            }
            case 16: {
              result.textContent = transformHexadecimal(number, 16);
              break;
            }
          }
        }
        break;
    }
  } else {
    result.textContent = "";
  }
});
