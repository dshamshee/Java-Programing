import javax.swing.*;
public class SwingExample {
    public static void main(String[] args) {
      JFrame frame = new JFrame("Swing Example");
      frame.setDefaultCloseOperation(frame.EXIT_ON_CLOSE);
      frame.setSize(300, 400);

      JButton button = new JButton("Click Me");
      frame.add(button);

      frame.setVisible(true);
    }
}
