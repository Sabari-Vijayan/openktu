import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class EL implements TextListener {
    JLabel w, l, s, sen;
    TextArea tx;

    EL(JLabel w, JLabel l, JLabel s, JLabel sen, TextArea tx) {
        this.w = w;
        this.l = l;
        this.s = s;
        this.sen = sen;
        this.tx = tx;
    }

    public void textValueChanged(TextEvent e) {
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

public class Main2 {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Frequency Counter");
        frame.setSize(400, 500);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        Panel p = new Panel(new GridLayout(4, 2, 5, 5)); 
        frame.setLayout(new BorderLayout(10, 10));

        JLabel Lwords = new JLabel("   Words:");
        JLabel Lletters = new JLabel("   Letters:");
        JLabel Llines = new JLabel("   Lines:");
        JLabel Lsentences = new JLabel("   Sentences:");

        JLabel words = new JLabel("0");
        JLabel letters = new JLabel("0");
        JLabel lines = new JLabel("0");
        JLabel sentences = new JLabel("0");

        TextArea tx = new TextArea(10, 30);  
        EL listener = new EL(words, letters, lines, sentences, tx);
        tx.addTextListener(listener);  

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

        frame.setVisible(true);
    }
}
