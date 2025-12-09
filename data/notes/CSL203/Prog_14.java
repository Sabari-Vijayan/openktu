import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class AL implements ActionListener {
    JButton redButton;
    JButton yellowButton;
    JButton greenButton;
    JRadioButton redRadioButton;
    JRadioButton yellowRadioButton;
    JRadioButton greenRadioButton;

    AL(JButton redButton, JButton yellowButton, JButton greenButton, JRadioButton redRadioButton, JRadioButton yellowRadioButton, JRadioButton greenRadioButton) {
        this.redButton = redButton;
        this.yellowButton = yellowButton;
        this.greenButton = greenButton;
        this.redRadioButton = redRadioButton;
        this.yellowRadioButton = yellowRadioButton;
        this.greenRadioButton = greenRadioButton;
    }

    public void actionPerformed(ActionEvent e) {

        redButton.setBackground(null);
        yellowButton.setBackground(null);
        greenButton.setBackground(null);

        if (redRadioButton.isSelected()) {
            redButton.setBackground(Color.RED);
        } 
        else if (yellowRadioButton.isSelected()) {
            yellowButton.setBackground(Color.YELLOW);
        } 
        else if (greenRadioButton.isSelected()) {
            greenButton.setBackground(Color.GREEN);
        }
    }
}

public class TrafficLight {
    public static void main(String[] args) {

        JFrame frame = new JFrame("Traffic Light");
        frame.setSize(200, 400);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new GridLayout(6, 1)); 

        JButton redButton = new JButton();
        JButton yellowButton = new JButton();
        JButton greenButton = new JButton();

        JRadioButton redRadioButton = new JRadioButton("Red");
        JRadioButton yellowRadioButton = new JRadioButton("Yellow");
        JRadioButton greenRadioButton = new JRadioButton("Green");

        ButtonGroup group = new ButtonGroup();
        group.add(redRadioButton);
        group.add(yellowRadioButton);
        group.add(greenRadioButton);

        AL actionListener = new AL(redButton, yellowButton, greenButton, redRadioButton, yellowRadioButton, greenRadioButton);
        redRadioButton.addActionListener(actionListener);
        yellowRadioButton.addActionListener(actionListener);
        greenRadioButton.addActionListener(actionListener);

        frame.add(redButton);
        frame.add(yellowButton);
        frame.add(greenButton);
        frame.add(redRadioButton);
        frame.add(yellowRadioButton);
        frame.add(greenRadioButton);

        frame.setVisible(true);
    }
}
