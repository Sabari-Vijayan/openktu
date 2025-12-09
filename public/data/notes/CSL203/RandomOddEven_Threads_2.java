import java.util.Random;

class CommonData extends Thread {
    Random rd = new Random();
    int num;
    boolean newNum;

    CommonData() {
        newNum = false;
    }

    public void run() {
        while (true) {
            try {
                if (!newNum) {
                    num = rd.nextInt(100);
                    System.out.println("Generated number: " + num);
                    newNum = true;
                }
                Thread.sleep(500);
            } 
            catch (Exception e) {}
        }
    }

    boolean newNumMade() {
        return newNum;
    }
}

class Even extends Thread {
    CommonData cd;

    Even(CommonData cd) {
        this.cd = cd;
    }

    public void run() {
        while (true) {
            try {
                if (cd.newNum && cd.num%2==0) {
                    System.out.println("EVEN: " + cd.num);
                    cd.newNum = false;
                }
                Thread.sleep(100); 
            } 
            catch (Exception e) {}
        }
    }
}

class Odd extends Thread {
    CommonData cd;

    Odd(CommonData cd) {
        this.cd = cd;
    }

    public void run() {
        while (true) {
            try {
                if (cd.newNum && cd.num%2!=0) {
                    System.out.println("ODD: " + cd.num);
                    cd.newNum = false;
                }
                Thread.sleep(100);
            } 
            catch (Exception e) {}
        }
    }
}

class Main {
    public static void main(String args[]) {
        CommonData cd = new CommonData();
        Even e = new Even(cd);
        Odd o = new Odd(cd);

        cd.start();
        e.start();
        o.start();
    }
}
