import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;

public class OOPQuiz {

    public static void main(String[] args) {
        // Create the frame
        JFrame frame = new JFrame("OOP Language Quiz");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 200);

        // Create the panel and layout
        JPanel panel = new JPanel();
        panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS));

        // Create the question label
        JLabel questionLabel = new JLabel("Which of the following is NOT an OOP language?");
        questionLabel.setAlignmentX(Component.CENTER_ALIGNMENT);

        // Create the radio buttons
        JRadioButton buttonCPlusPlus = new JRadioButton("C++");
        JRadioButton buttonJava = new JRadioButton("Java");
        JRadioButton buttonPascal = new JRadioButton("Pascal");

        // Group the radio buttons together so that only one can be selected at a time
        ButtonGroup group = new ButtonGroup();
        group.add(buttonCPlusPlus);
        group.add(buttonJava);
        group.add(buttonPascal);

        // Create a button to submit the answer
        JButton submitButton = new JButton("Submit");

        // Create a label to display the result
        JLabel resultLabel = new JLabel("");
        resultLabel.setAlignmentX(Component.CENTER_ALIGNMENT);

        // Add action listener to the submit button
        submitButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // Check which radio button is selected and display the result
                if (buttonCPlusPlus.isSelected()) {
                    resultLabel.setText("Wrong! C++ is a OOP language.");
                } else if (buttonJava.isSelected()) {
                    resultLabel.setText("Wrong! Java is an OOP language.");
                } else if (buttonPascal.isSelected()) {
                    resultLabel.setText("Correct! Pascal is not a OOP language.");
                } else {
                    resultLabel.setText("Please select an option.");
                }
            }
        });

        // Add components to the panel
        panel.add(questionLabel);
        panel.add(buttonCPlusPlus);
        panel.add(buttonJava);
        panel.add(buttonPascal);
        panel.add(submitButton);
        panel.add(resultLabel);

        // Add panel to frame
        frame.add(panel);
        frame.setVisible(true);
    }
}
