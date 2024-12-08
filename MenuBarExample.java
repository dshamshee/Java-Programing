import javax.swing.*;

public class MenuBarExample {
    public static void main(String[] args) {
        // Create a frame
        JFrame frame = new JFrame("Menu Bar Example");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 300);

        // Create a menu bar
        JMenuBar menuBar = new JMenuBar();

        // Create File menu
        JMenu fileMenu = new JMenu("File");
        fileMenu.add(new JMenuItem("New"));
        fileMenu.add(new JMenuItem("Open"));
        fileMenu.add(new JMenuItem("Close"));
        fileMenu.addSeparator();
        fileMenu.add(new JMenuItem("Save"));
        fileMenu.add(new JMenuItem("Save As"));
        fileMenu.addSeparator();
        fileMenu.add(new JMenuItem("Print"));

        // Create Edit menu
        JMenu editMenu = new JMenu("Edit");

        // Add Radio Button menu items to Edit menu
        ButtonGroup shapeGroup = new ButtonGroup();
        JRadioButtonMenuItem lineItem = new JRadioButtonMenuItem("Line");
        JRadioButtonMenuItem rectangleItem = new JRadioButtonMenuItem("Rectangle");
        JRadioButtonMenuItem circleItem = new JRadioButtonMenuItem("Circle");
        shapeGroup.add(lineItem);
        shapeGroup.add(rectangleItem);
        shapeGroup.add(circleItem);
        editMenu.add(lineItem);
        editMenu.add(rectangleItem);
        editMenu.add(circleItem);
        editMenu.addSeparator();

        // Add Check Box menu items to Edit menu
        JCheckBoxMenuItem redItem = new JCheckBoxMenuItem("Red");
        JCheckBoxMenuItem greenItem = new JCheckBoxMenuItem("Green");
        JCheckBoxMenuItem blueItem = new JCheckBoxMenuItem("Blue");
        editMenu.add(redItem);
        editMenu.add(greenItem);
        editMenu.add(blueItem);

        // Add menus to menu bar
        menuBar.add(fileMenu);
        menuBar.add(editMenu);

        // Add menu bar to frame
        frame.setJMenuBar(menuBar);

        // Display the frame
        frame.setVisible(true);
    }
}
