import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class EL implements ActionListener {
    JLabel w, l, s, sen;
    JTextArea tx;

    EL(JLabel w, JLabel l, JLabel s, JLabel sen, JTextArea tx) {
        this.w = w;
        this.l = l;
        this.s = s;
        this.sen = sen;
        this.tx = tx;
    }

    public void actionPerformed(ActionEvent e) {
        String str = e.getActionCommand();
        if (str.equals("Submit")) {
            String data = tx.getText().trim();
            int words = 1, letters = 0, sentences = 0, lines = 1;

            for (int i = 0; i < data.length(); i++) {
                char ch = data.charAt(i);
                letters++;
                if (ch == ' ' || ch == '\n') {
                    words++;
                }
                if (ch == '.') {
                    sentences++;
                }
                if (ch == '\n') {
                    lines++;
                }
            }

            w.setText("" + words);
            l.setText("" + letters);
            s.setText("" + lines);
            sen.setText("" + sentences);
        }
    }
}

public class Main2 {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Frequency Counter");
        frame.setSize(400, 500);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JPanel p = new JPanel(new GridLayout(4, 2, 5, 5));
        JPanel resultPanel = new JPanel(new GridLayout(1, 4, 5, 5));
        frame.setLayout(new BorderLayout(10, 10));

        JLabel Lwords = new JLabel("   Words:");
        JLabel Lletters = new JLabel("   Letters:");
        JLabel Llines = new JLabel("   Lines:");
        JLabel Lsentences = new JLabel("   Sentences:");

        JLabel words = new JLabel("0");
        JLabel letters = new JLabel("0");
        JLabel lines = new JLabel("0");
        JLabel sentences = new JLabel("0");

        JTextArea tx = new JTextArea(10, 30);        
        JButton submit = new JButton("Submit");
        submit.addActionListener(new EL(words, letters, lines, sentences, tx));

        p.add(Lwords);
        p.add(words);
        p.add(Lletters);
        p.add(letters);
        p.add(Llines);
        p.add(lines);
        p.add(Lsentences);
        p.add(sentences);

        frame.add(p, BorderLayout.NORTH);
        frame.add(tx, BorderLayout.CENTER);
        frame.add(submit, BorderLayout.SOUTH);

        frame.setVisible(true);
    }
}
