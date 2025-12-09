import java.io.*;

class ThreadTask extends Thread {
    fileWriter writer;
    String data;

    ThreadTask(fileWriter writer, String data) {
        this.writer = writer;
        this.data = data;
    }

    public void run() {
        synchronized (writer) {
            while (writer.getN() < 10) {
                try {
                    writer.writes(data);
                    System.out.println("Written: " + data);
                    writer.incrementN();
                    writer.flush();
                    writer.notifyAll(); 
                    writer.wait();
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }
    }
}

class fileWriter extends FileWriter {
    private int n;

    fileWriter(String name) throws IOException {
        super(name);
        n = 0;
    }

    public synchronized void writes(String data) {
        try {
            super.write(data+"\n");
        } catch (Exception e) {
            System.out.println(e);
        }
    }

    public synchronized int getN() {
        return n;
    }

    public synchronized void incrementN() {
        n++;
    }
}

public class Main2 {
    public static void main(String[] args) {
        fileWriter writer = null;
        try {
            writer = new fileWriter("file.txt");
            Thread t1 = new ThreadTask(writer, "This is line 0");
            Thread t2 = new ThreadTask(writer, "This is line 1");

            t1.start();
            t2.start();

        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
