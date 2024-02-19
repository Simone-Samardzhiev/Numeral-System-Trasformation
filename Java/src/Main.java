import javax.swing.*;
import java.awt.*;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;

// Record that store a scroll pane a num for the TransformSystem methods.
record Result(JScrollPane scrollPane, String num) {
}

// Record that is used when the methods in TransformSystem need to return larger data.
record LargerResult(JScrollPane scrollPane1, String num1, JScrollPane scrollPane2, String num2) {
}

@SuppressWarnings("DuplicatedCode")
class TransformSystems {
    static private JScrollPane createScrollPane(String[][] tableData, String[] columnNames) {
        // Creating the table.
        JTable table = new JTable(tableData, columnNames);
        table.setDefaultEditor(Object.class, null);


        // Creating the scrollPane.
        JScrollPane scrollPane = new JScrollPane(table);
        scrollPane.setPreferredSize(new Dimension(300, 200));
        return scrollPane;
    }

    // Method used to transform binary to octal.
    public static Result binaryToOctal(String num) {
        Map<String, String> values = new HashMap<>() {{
            put("000", "0");
            put("001", "1");
            put("010", "2");
            put("011", "3");
            put("100", "4");
            put("101", "5");
            put("110", "6");
            put("111", "7");
        }};
        StringBuilder builder = new StringBuilder(num);

        while (builder.length() % 3 != 0) {
            builder.insert(0, '0');
        }

        String[] splitNum = new String[builder.length() / 3];
        String[][] tableData = new String[splitNum.length][2];
        String[] columnNames = {"Binary Number", "Octal Number"};

        for (int i = 0; i < splitNum.length; i++) {
            splitNum[i] = builder.substring(i * 3, (i + 1) * 3);
        }

        builder.setLength(0);

        for (int i = 0; i < tableData.length; i++) {
            tableData[i][0] = splitNum[i];
            tableData[i][1] = values.get(splitNum[i]);
            builder.append(values.get(splitNum[i]));
        }

        return new Result(createScrollPane(tableData, columnNames), builder.toString());
    }

    // Method used to transform binary to decimal.
    public static Result binaryToDecimal(String num) {
        String[][] tableData = new String[num.length()][2];
        String[] columnNames = {"Binary Number", "Decimal Number"};
        int result = 0;

        for (int i = 0; i < tableData.length; i++) {
            tableData[i][0] = String.format("2 ^ %d * %c", tableData.length - 1 - i, num.charAt(i));

            int temp = (int) (Math.pow(2, tableData.length - 1 - i) * Integer.parseInt(String.valueOf(num.charAt(i))));
            tableData[i][1] = Integer.toString(temp);
            result += temp;
        }

        return new Result(createScrollPane(tableData, columnNames), Integer.toString(result));
    }

    // Method used to transform binary to hexadecimal.
    public static Result binaryToHexadecimal(String num) {
        Map<String, String> values = new HashMap<>() {{
            put("0000", "0");
            put("0001", "1");
            put("0010", "2");
            put("0011", "3");
            put("0100", "4");
            put("0101", "5");
            put("0110", "6");
            put("0111", "7");
            put("1000", "8");
            put("1001", "9");
            put("1010", "A");
            put("1011", "B");
            put("1100", "C");
            put("1101", "D");
            put("1110", "E");
            put("1111", "F");
        }};
        StringBuilder builder = new StringBuilder(num);

        while (builder.length() % 4 != 0) {
            builder.insert(0, '0');
        }

        String[] splitNum = new String[builder.length() / 4];
        String[][] tableData = new String[splitNum.length][2];
        String[] columNames = {"Binary Number", "Hexadecimal Number"};

        for (int i = 0; i < splitNum.length; i++) {
            splitNum[i] = builder.substring(i * 4, (i + 1) * 4);
        }

        builder.setLength(0);

        for (int i = 0; i < tableData.length; i++) {
            tableData[i][0] = splitNum[i];
            tableData[i][1] = values.get(splitNum[i]);
            builder.append(values.get(splitNum[i]));
        }

        return new Result(createScrollPane(tableData, columNames), builder.toString());
    }

    // Method used to transform octal to binary.
    public static Result octalToBinary(String num) {
        Map<Character, String> values = new HashMap<>() {{
            put('0', "000");
            put('1', "001");
            put('2', "010");
            put('3', "011");
            put('4', "100");
            put('5', "101");
            put('6', "110");
            put('7', "111");
        }};

        String[][] tableData = new String[num.length()][2];
        String[] columNames = {"Octal Number", "Binary Number"};
        StringBuilder builder = new StringBuilder();

        for (int i = 0; i < tableData.length; i++) {
            tableData[i][0] = String.valueOf(num.charAt(i));
            tableData[i][1] = values.get(num.charAt(i));
            builder.append(values.get(num.charAt(i)));
        }

        return new Result(createScrollPane(tableData, columNames), builder.toString());
    }

    // Method used to transform octal to decimal.
    public static Result octalToDecimal(String num) {
        String[][] tableData = new String[num.length()][2];
        String[] columnNames = {"Octal Number", "Decimal Number"};
        int result = 0;

        for (int i = 0; i < tableData.length; i++) {
            tableData[i][0] = String.format("8 ^ %d * %c", tableData.length - 1 - i, num.charAt(i));

            int temp = (int) (Math.pow(8, tableData.length - 1 - i) * Integer.parseInt(String.valueOf(num.charAt(i))));
            tableData[i][1] = Integer.toString(temp);
            result += temp;
        }

        return new Result(createScrollPane(tableData, columnNames), Integer.toString(result));
    }

    // Method used to transform octal to hexadecimal.
    public static LargerResult octalToHexadecimal(String num) {
        Result result1 = TransformSystems.octalToBinary(num);
        Result result2 = TransformSystems.binaryToHexadecimal(result1.num());

        return new LargerResult(result1.scrollPane(), result1.num(), result2.scrollPane(), result2.num());
    }

    // Method used to transform decimal to binary.
    public static Result decimalToBinary(String num) {
        int n = Integer.parseInt(num);
        int countRows = 0;

        while (n != 0) {
            n /= 2;
            countRows++;
        }

        String[][] tableData = new String[countRows][3];
        String[] columnNames = {"Decimal Number", "Quotient Number", "Binary Number"};
        StringBuilder builder = new StringBuilder();
        n = Integer.parseInt(num);

        for (int i = 0; i < tableData.length; i++) {
            tableData[i][0] = String.format("%d / 2", n);
            tableData[i][1] = Integer.toString(n / 2);
            tableData[i][2] = Integer.toString(n % 2);
            builder.insert(0, n % 2);
            n /= 2;
        }

        return new Result(createScrollPane(tableData, columnNames), builder.toString());
    }

    // Method used to transform decimal to octal.
    public static Result decimalToOctal(String num) {
        int n = Integer.parseInt(num);
        int countRows = 0;

        while (n != 0) {
            n /= 8;
            countRows++;
        }

        String[][] tableData = new String[countRows][3];
        String[] columnNames = {"Decimal Number", "Quotient Number", "Octal Number"};
        StringBuilder builder = new StringBuilder();
        n = Integer.parseInt(num);

        for (int i = 0; i < tableData.length; i++) {
            tableData[i][0] = String.format("%d / 8", n);
            tableData[i][1] = Integer.toString(n / 8);
            tableData[i][2] = Integer.toString(n % 8);
            builder.insert(0, n % 8);
            n /= 8;
        }

        return new Result(createScrollPane(tableData, columnNames), builder.toString());
    }

    // Method used to transform decimal to hexadecimal.
    public static Result decimalToHexadecimal(String num) {
        Map<Integer, String> values = new HashMap<>() {{
            put(0, "0");
            put(1, "1");
            put(2, "2");
            put(3, "3");
            put(4, "4");
            put(5, "5");
            put(6, "6");
            put(7, "7");
            put(8, "8");
            put(9, "9");
            put(10, "A");
            put(11, "B");
            put(12, "C");
            put(13, "D");
            put(14, "E");
            put(15, "F");
        }};
        int n = Integer.parseInt(num);
        int countRows = 0;

        while (n != 0) {
            n /= 16;
            countRows++;
        }

        String[][] tableData = new String[countRows][3];
        String[] columnNames = {"Decimal Number", "Quotient Number", "Hexadecimal Number"};
        StringBuilder builder = new StringBuilder();
        n = Integer.parseInt(num);

        for (int i = 0; i < tableData.length; i++) {
            tableData[i][0] = String.format("%d / 16", n);
            tableData[i][1] = Integer.toString(n / 16);
            tableData[i][2] = values.get(n % 16);
            builder.insert(0, values.get(n % 16));
            n /= 16;
        }

        return new Result(createScrollPane(tableData, columnNames), builder.toString());
    }

    // Method used to transform hexadecimal to binary.
    public static Result hexadecimalToBinary(String num) {
        Map<Character, String> values = new HashMap<>() {{
            put('0', "0000");
            put('1', "0001");
            put('2', "0010");
            put('3', "0011");
            put('4', "0100");
            put('5', "0101");
            put('6', "0110");
            put('7', "0111");
            put('8', "1000");
            put('9', "1001");
            put('A', "1010");
            put('B', "1011");
            put('C', "1100");
            put('D', "1101");
            put('E', "1110");
            put('F', "1111");
        }};

        String[][] tableData = new String[num.length()][2];
        String[] columnNames = {"Hexadecimal Number", "Binary Number"};
        StringBuilder builder = new StringBuilder();

        for (int i = 0; i < tableData.length; i++) {
            tableData[i][0] = String.valueOf(num.charAt(i));
            tableData[i][1] = values.get(num.charAt(i));
            builder.append(values.get(num.charAt(i)));
        }

        return new Result(createScrollPane(tableData, columnNames), builder.toString());
    }

    public static LargerResult hexadecimalToOctal(String num) {
        Result result1 = hexadecimalToBinary(num);
        Result result2 = binaryToOctal(result1.num());

        return new LargerResult(result1.scrollPane(), result1.num(), result2.scrollPane(), result2.num());
    }

    // Method used to transform hexadecimal to decimal.
    public static Result hexadecimalToDecimal(String num) {
        Map<Character, Integer> values = new HashMap<>() {{
            put('0', 0);
            put('1', 1);
            put('2', 2);
            put('3', 3);
            put('4', 4);
            put('5', 5);
            put('6', 6);
            put('7', 7);
            put('8', 8);
            put('9', 9);
            put('A', 10);
            put('B', 11);
            put('C', 12);
            put('D', 13);
            put('E', 14);
            put('F', 15);
        }};
        String[][] tableData = new String[num.length()][2];
        String[] columnNames = {"Hexadecimal Number", "Decimal Number"};
        int result = 0;

        for (int i = 0; i < tableData.length; i++) {
            tableData[i][0] = String.format("16 ^ %d * %c", tableData.length - 1 - i, num.charAt(i));

            int temp = (int) (Math.pow(16, tableData.length - 1 - i) * values.get(num.charAt(i)));
            tableData[i][1] = Integer.toString(temp);
            result += temp;
        }

        return new Result(createScrollPane(tableData, columnNames), Integer.toString(result));
    }

    // Method that checks the numeral system. False mean its correct and true means it not correct.
    public static boolean checkSystem(String num, int system) {
        switch (system) {
            case 2: {
                Set<Character> digits = Set.of('0', '1');

                for (char digit : num.toCharArray()) {
                    if (!digits.contains(digit)) {
                        return true;
                    }
                }
                return false;
            }
            case 8: {
                Set<Character> digits = Set.of('0', '1', '2', '3', '4', '5', '6', '7');

                for (char digit : num.toCharArray()) {
                    if (!digits.contains(digit)) {
                        return true;
                    }
                }
                return false;
            }
            case 10: {
                Set<Character> digits = Set.of('0', '1', '2', '3', '4', '5', '6', '7', '8', '9');

                for (char digit : num.toCharArray()) {
                    if (!digits.contains(digit)) {
                        return true;
                    }
                }
                return false;
            }
            case 16: {
                Set<Character> digits = Set.of('0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F');

                for (char digit : num.toCharArray()) {
                    if (!digits.contains(digit)) {
                        return true;
                    }
                }
                return false;
            }
            default: {
                throw new IllegalArgumentException("The system in not made for the function");
            }
        }
    }
}

@SuppressWarnings("ALL")
class Window extends JFrame {
    // Text filed used to get and display the result.
    JTextField inputTextField = new JTextField();
    JTextField resultTextField = new JTextField();

    // Combo boxes used to select the input system and result system.
    JComboBox<String> inputSystems = new JComboBox<>();
    JComboBox<String> resultSystems = new JComboBox<>();

    // JPanel that will hold the result from the transformation.
    JPanel resultPanel = new JPanel();

    public Window() {
        // Setting attributes to the window.
        this.setTitle("Numerical system transformation");
        this.setSize(500, 700);
        this.setLayout(new GridBagLayout());
        this.setResizable(false);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Creating the UI.
        createUI();

    }

    // Method used to create the UI.
    public void createUI() {
        // Creating the widgets.
        GridBagConstraints layout = new GridBagConstraints();
        JButton transformButton = new JButton("Transform");

        // Setting attributes to the widgets.
        inputTextField.setPreferredSize(new Dimension(200, 30));
        resultTextField.setPreferredSize(new Dimension(200, 30));
        resultTextField.setEditable(false);

        for (String system : new String[]{"Binary", "Octal", "Decimal", "Hexadecimal"}) {
            inputSystems.addItem(system);
            resultSystems.addItem(system);
        }
        inputSystems.setEditable(false);
        resultSystems.setEditable(false);

        resultPanel.setLayout(new GridBagLayout());
        resultPanel.setPreferredSize(new Dimension(300, 500));

        // Connecting the widgets.
        transformButton.addActionListener(e -> Window.this.onTransformButtonClicked());

        // Adding the widget.
        layout.gridx = 0;
        layout.gridy = 0;
        this.add(inputSystems, layout);

        layout.gridx = 1;
        this.add(resultSystems, layout);

        layout.gridx = 0;
        layout.gridy = 1;
        layout.gridwidth = 2;
        this.add(inputTextField, layout);

        layout.gridy = 2;
        this.add(transformButton, layout);

        layout.gridy = 3;
        this.add(resultTextField, layout);

        layout.gridy = 4;
        this.add(resultPanel, layout);
    }

    // Method that will be called when the user clicks transform button.
    private void onTransformButtonClicked() {
        String inputSystem = ((String) inputSystems.getSelectedItem());
        String resultSystem = (String) resultSystems.getSelectedItem();
        String num = inputTextField.getText().toUpperCase();

        if (inputSystem == null || resultSystem == null) {
            return;
        }

        switch (inputSystem) {
            case "Binary": {
                if (TransformSystems.checkSystem(num, 2)) {
                    JOptionPane.showMessageDialog(this, "The system is valid");
                }

                resultPanel.removeAll();
                GridBagConstraints layout = new GridBagConstraints();

                switch (resultSystem) {
                    case "Binary": {
                        resultTextField.setText(num);
                        break;
                    }
                    case "Octal": {
                        Result result = TransformSystems.binaryToOctal(num);

                        layout.gridx = 0;
                        layout.gridy = 0;
                        resultPanel.add(result.scrollPane(), layout);
                        resultTextField.setText(result.num());
                        break;
                    }
                    case "Decimal": {
                        Result result = TransformSystems.binaryToDecimal(num);

                        layout.gridx = 0;
                        layout.gridy = 0;
                        resultPanel.add(result.scrollPane(), layout);
                        resultTextField.setText(result.num());
                        break;
                    }
                    case "Hexadecimal": {
                        Result result = TransformSystems.binaryToHexadecimal(num);

                        layout.gridx = 0;
                        layout.gridy = 0;
                        resultPanel.add(result.scrollPane(), layout);
                        resultTextField.setText(result.num());
                        break;
                    }
                }
                break;
            }
            case "Octal": {
                if (TransformSystems.checkSystem(num, 8)) {
                    JOptionPane.showMessageDialog(this, "The system is valid");
                }

                resultPanel.removeAll();
                GridBagConstraints layout = new GridBagConstraints();

                switch (resultSystem) {
                    case "Binary": {
                        Result result = TransformSystems.octalToBinary(num);

                        layout.gridx = 0;
                        layout.gridy = 0;
                        resultPanel.add(result.scrollPane(), layout);
                        resultTextField.setText(result.num());
                        break;
                    }
                    case "Octal": {
                        resultTextField.setText(num);
                        break;
                    }
                    case "Decimal": {
                        Result result = TransformSystems.octalToDecimal(num);

                        layout.gridx = 0;
                        layout.gridy = 0;
                        resultPanel.add(result.scrollPane(), layout);
                        resultTextField.setText(result.num());
                        break;
                    }

                    case "Hexadecimal": {
                        LargerResult result = TransformSystems.octalToHexadecimal(num);

                        layout.gridx = 0;
                        layout.gridy = 1;
                        resultPanel.add(result.scrollPane1(), layout);

                        layout.gridy = 2;
                        resultPanel.add(new JLabel(String.format("Binary Number: %s", result.num1())), layout);

                        layout.gridy = 3;
                        resultPanel.add(result.scrollPane2(), layout);
                        resultTextField.setText(result.num2());
                        break;
                    }
                }
                break;
            }
            case "Decimal": {
                if (TransformSystems.checkSystem(num, 10)) {
                    JOptionPane.showMessageDialog(this, "The system is valid");
                }

                resultPanel.removeAll();
                GridBagConstraints layout = new GridBagConstraints();

                switch (resultSystem) {
                    case "Binary": {
                        Result result = TransformSystems.decimalToBinary(num);

                        layout.gridx = 0;
                        layout.gridy = 0;
                        resultPanel.add(result.scrollPane(), layout);
                        resultTextField.setText(result.num());
                        break;
                    }
                    case "Octal": {
                        Result result = TransformSystems.decimalToOctal(num);

                        layout.gridx = 0;
                        layout.gridy = 0;
                        resultPanel.add(result.scrollPane(), layout);
                        resultTextField.setText(result.num());
                        break;
                    }
                    case "Decimal": {
                        resultTextField.setText(num);
                        break;
                    }
                    case "Hexadecimal": {
                        Result result = TransformSystems.decimalToHexadecimal(num);

                        layout.gridx = 0;
                        layout.gridy = 0;
                        resultPanel.add(result.scrollPane(), layout);
                        resultTextField.setText(result.num());
                        break;
                    }
                }
                break;
            }
            case "Hexadecimal": {
                if (TransformSystems.checkSystem(num, 16)) {
                    JOptionPane.showMessageDialog(this, "The system is valid");
                }

                resultPanel.removeAll();
                GridBagConstraints layout = new GridBagConstraints();

                switch (resultSystem) {
                    case "Binary": {
                        Result result = TransformSystems.hexadecimalToBinary(num);

                        layout.gridx = 0;
                        layout.gridy = 0;
                        resultPanel.add(result.scrollPane(), layout);
                        resultTextField.setText(result.num());
                        break;
                    }
                    case "Octal": {
                        LargerResult result = TransformSystems.hexadecimalToOctal(num);

                        layout.gridx = 0;
                        layout.gridy = 1;
                        resultPanel.add(result.scrollPane1(), layout);

                        layout.gridy = 2;
                        resultPanel.add(new JLabel(String.format("Binary Number: %s", result.num1())), layout);

                        layout.gridy = 3;
                        resultPanel.add(result.scrollPane2(), layout);
                        resultTextField.setText(result.num2());
                        break;
                    }
                    case "Decimal": {
                        Result result = TransformSystems.hexadecimalToDecimal(num);

                        layout.gridx = 0;
                        layout.gridy = 0;
                        resultPanel.add(result.scrollPane(), layout);
                        resultTextField.setText(result.num());
                        break;
                    }
                    case "Hexadecimal": {
                        resultTextField.setText(num);
                        break;
                    }
                }
                break;
            }
        }

        refreshUI();
    }

    // Method that will refresh the UI.
    private void refreshUI() {
        resultPanel.revalidate();
        resultPanel.repaint();
        this.revalidate();
        this.repaint();
    }
}

class Main {
    public static void main(String[] args) {
        Window window = new Window();
        window.setVisible(true);
    }
}