import java.util.Random;

class CommonData extends Thread 
{
    Random rd = new Random();
    int num;
    boolean numGenerated = false;

    public synchronized void run() 
    {
        while (true) 
        {
            if (!numGenerated) 
            {
                num = rd.nextInt(100);
                numGenerated = true;
                notifyAll(); 
            }
            try 
            {
                wait(); 
            } 
            catch (Exception e) {}
        }
    }
}

class Even extends Thread 
{
    CommonData cd;

    Even(CommonData cd) 
    {
        this.cd = cd;
    }

    public void run() 
    {
        while (true) 
        {
            synchronized (cd) 
            {
                try 
                {
                    while (!cd.numGenerated || cd.num % 2 != 0)
                        cd.wait();
                    System.out.printf("Even Thread : %d : %d\n", cd.num, cd.num * cd.num);
                    cd.numGenerated = false;
                    cd.notifyAll(); 
                    Thread.sleep(1000);
                } 
                catch (Exception e) {}
            }
        }
    }
}

class Odd extends Thread 
{
    CommonData cd;

    Odd(CommonData cd) 
    {
        this.cd = cd;
    }

    public void run() 
    {
        while (true) 
        {
            synchronized (cd) 
            {
                try 
                {
                    while (!cd.numGenerated || cd.num % 2 == 0)
                        cd.wait(); 
                    System.out.printf("Odd Thread : %d : %d\n", cd.num, cd.num * cd.num * cd.num);
                    cd.numGenerated = false;
                    cd.notifyAll(); 
                    Thread.sleep(1000);
                } 
                catch (Exception e) {}
            }
        }
    }
}

public class Main 
{
    public static void main(String[] args) 
    {
        CommonData cd = new CommonData();
        Even e = new Even(cd);
        Odd o = new Odd(cd);
        cd.start();
        e.start();
        o.start();
    }
}
