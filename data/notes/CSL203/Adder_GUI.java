import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class AL implements ActionListener
{
    JTextField t1, t2;
    JLabel l;
    AL(JTextField t1, JTextField t2, JLabel l)
    {
        this.t1 = t1;
        this.t2 = t2;
        this.l = l;
    }
    public void actionPerformed(ActionEvent e)
    {
        String s = e.getActionCommand();
        if(s=="Add")
        {
            float a = Float.parseFloat(t1.getText());
            float b = Float.parseFloat(t2.getText());
            l.setText("  " + (a+b));
            System.out.println(a+b);

        }
        else if(s=="Clear")
        {
            l.setText("");
            t1.setText("");
            t2.setText("");
        }
    }
}

public class Main2 {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Adder");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setBounds(0,0, 300, 130);
        frame.setLayout(new GridLayout(2,3));
        JTextField t1 = new JTextField();
        JTextField t2 = new JTextField();
        JButton add = new JButton("Add");
        JButton clear = new JButton("Clear");
        JLabel sl = new JLabel("  Sum: ");
        JLabel l = new JLabel("");

        AL al = new AL(t1, t2, l);
        add.addActionListener(al);
        clear.addActionListener(al);
        frame.add(t1);
        frame.add(t2);
        frame.add(sl);
        frame.add(add);
        frame.add(clear);
        frame.add(l);
        frame.setVisible(true);
    }
}
