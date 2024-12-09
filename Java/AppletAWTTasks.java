import java.applet.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;

// Task 1: Simple Calculator
class SimpleCalculator extends Applet implements ActionListener {
    TextField num1, num2, result;
    Button add, subtract, multiply, divide;

    public void init() {
        Label label1 = new Label("Number 1:");
        num1 = new TextField(10);
        Label label2 = new Label("Number 2:");
        num2 = new TextField(10);
        Label label3 = new Label("Result:");
        result = new TextField(10);
        result.setEditable(false);

        add = new Button("Add");
        subtract = new Button("Subtract");
        multiply = new Button("Multiply");
        divide = new Button("Divide");

        add(label1); add(num1);
        add(label2); add(num2);
        add(label3); add(result);
        add(add); add(subtract); add(multiply); add(divide);

        add.addActionListener(this);
        subtract.addActionListener(this);
        multiply.addActionListener(this);
        divide.addActionListener(this);
    }

    public void actionPerformed(ActionEvent e) {
        try {
            int n1 = Integer.parseInt(num1.getText());
            int n2 = Integer.parseInt(num2.getText());
            int res = 0;

            if (e.getSource() == add) res = n1 + n2;
            else if (e.getSource() == subtract) res = n1 - n2;
            else if (e.getSource() == multiply) res = n1 * n2;
            else if (e.getSource() == divide) res = n1 / n2;

            result.setText(String.valueOf(res));
        } catch (NumberFormatException | ArithmeticException ex) {
            result.setText("Error");
        }
    }
}

// Task 2: Write content of TextArea to file using Frame
class TextAreaToFile extends Frame implements ActionListener {
    TextArea textArea;
    TextField fileNameField;
    Button saveButton;

    public TextAreaToFile() {
        super("Write to File");
        setLayout(new FlowLayout());

        textArea = new TextArea(10, 30);
        fileNameField = new TextField(20);
        saveButton = new Button("Save");

        add(new Label("File Name:"));
        add(fileNameField);
        add(textArea);
        add(saveButton);

        saveButton.addActionListener(this);
        setSize(400, 300);
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        try {
            String fileName = fileNameField.getText();
            String content = textArea.getText();

            FileWriter writer = new FileWriter(fileName);
            writer.write(content);
            writer.close();

            System.out.println("File saved successfully.");
        } catch (IOException ex) {
            System.out.println("Error saving file: " + ex.getMessage());
        }
    }
}

// Task 3: Draw rectangle on mouse drag
class RectangleDrawer extends Applet implements MouseMotionListener {
    int startX, startY, endX, endY;

    public void init() {
        addMouseMotionListener(this);
    }

    public void paint(Graphics g) {
        g.drawRect(Math.min(startX, endX), Math.min(startY, endY),
                   Math.abs(endX - startX), Math.abs(endY - startY));
    }

    public void mouseDragged(MouseEvent e) {
        endX = e.getX();
        endY = e.getY();
        repaint();
    }

    public void mouseMoved(MouseEvent e) {}
}

// Main class to launch examples
public class AppletAWTTasks {
    public static void main(String[] args) {
        // Task 1: Launch Simple Calculator as an applet
        Frame calculatorFrame = new Frame("Simple Calculator");
        Applet calculator = new SimpleCalculator();
        calculator.init();
        calculatorFrame.add(calculator);
        calculatorFrame.setSize(300, 200);
        calculatorFrame.setVisible(true);

        // Task 2: Launch TextAreaToFile Frame
        new TextAreaToFile();

        // Task 3: Launch RectangleDrawer as an applet
        Frame rectangleFrame = new Frame("Rectangle Drawer");
        Applet rectangleDrawer = new RectangleDrawer();
        rectangleDrawer.init();
        rectangleFrame.add(rectangleDrawer);
        rectangleFrame.setSize(400, 300);
        rectangleFrame.setVisible(true);
    }
}
