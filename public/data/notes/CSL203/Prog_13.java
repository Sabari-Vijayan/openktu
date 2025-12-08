import java.awt.event.*;
import javax.swing.*;
import java.awt.*;

class Main {

    static JFrame f;
    static JTextField l;

    public static void main(String args[]) {
        f = new JFrame("Calculator");

        l = new JTextField(16);
        CAL actionListener = new CAL(l);

        JButton b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, ba, bs, bd, bm, be, bclr, beq;

        b0 = new JButton("0");
        b1 = new JButton("1");
        b2 = new JButton("2");
        b3 = new JButton("3");
        b4 = new JButton("4");
        b5 = new JButton("5");
        b6 = new JButton("6");
        b7 = new JButton("7");
        b8 = new JButton("8");
        b9 = new JButton("9");

        beq = new JButton("=");
        ba = new JButton("+");
        bs = new JButton("-");
        bd = new JButton("/");
        bm = new JButton("*");
        bclr = new JButton("C");
        be = new JButton(".");

        JPanel p = new JPanel();

        b0.addActionListener(actionListener);
        b1.addActionListener(actionListener);
        b2.addActionListener(actionListener);
        b3.addActionListener(actionListener);
        b4.addActionListener(actionListener);
        b5.addActionListener(actionListener);
        b6.addActionListener(actionListener);
        b7.addActionListener(actionListener);
        b8.addActionListener(actionListener);
        b9.addActionListener(actionListener);
        ba.addActionListener(actionListener);
        bs.addActionListener(actionListener);
        bd.addActionListener(actionListener);
        bm.addActionListener(actionListener);
        bclr.addActionListener(actionListener);
        beq.addActionListener(actionListener);
        be.addActionListener(actionListener);

        p.add(l);
        p.add(ba);
        p.add(b1);
        p.add(b2);
        p.add(b3);
        p.add(bs);
        p.add(b4);
        p.add(b5);
        p.add(b6);
        p.add(bm);
        p.add(b7);
        p.add(b8);
        p.add(b9);
        p.add(bd);
        p.add(be);
        p.add(b0);
        p.add(bclr);
        p.add(beq);

        f.add(p);
        f.setSize(200, 220);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setVisible(true);
    }
}
class CAL implements ActionListener {

    private JTextField l;
    private String s0, s1, s2;

    CAL(JTextField l) {
        this.l = l;
        s0 = s1 = s2 = "";
    }

    public void actionPerformed(ActionEvent e) {
        String s = e.getActionCommand();
        System.out.println(s);
        
        if ((s.charAt(0) >= '0' && s.charAt(0) <= '9') || s.charAt(0) == '.') {
            if (!s1.equals("")) {
                s2 = s2 + s;
            } else {
                s0 = s0 + s;
            }
            l.setText(s0 + s1 + s2);
        } else if (s.charAt(0) == 'C') {
            s0 = s1 = s2 = "";
            l.setText(s0 + s1 + s2);
        } else if (s.charAt(0) == '=') {
            float te;
            try {
                switch (s1) {
                    case "+":
                        te = Float.parseFloat(s0) + Float.parseFloat(s2);
                        break;
                    case "-":
                        te = Float.parseFloat(s0) - Float.parseFloat(s2);
                        break;
                    case "/":
                        if (Float.parseFloat(s2) == 0) {
                            throw new ArithmeticException("Cannot divide by zero");
                        }
                        te = Float.parseFloat(s0) / Float.parseFloat(s2);
                        break;
                    case "*":
                        te = Float.parseFloat(s0) * Float.parseFloat(s2);
                        break;
                    default:
                        te = 0;
                        break;
                }
                l.setText("" + te);
                s0 = Float.toString(te);
                s1 = s2 = "";
            } 
            catch (ArithmeticException ex) {
                l.setText("Error: " + ex.getMessage());
                s0 = s1 = s2 = "";
            }
        } else {
            s1 = s;
            l.setText(s0 + s1 + s2);
        }
    }
}
