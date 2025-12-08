import java.io.DataInputStream; 
import java.io.IOException; 
import java.util.StringTokenizer; 
 
public class IntegerSum  
{ 
    public static void main(String[] args)  
    { 
        DataInputStream dataInputStream = new DataInputStream(System.in); 
        String input; 
        try  
        { 
            System.out.print("Enter integers: "); 
            input = dataInputStream.readLine(); 
        }  
        catch (IOException e)  
        { 
            System.out.println(e.getMessage()); 
            return; 
        } 
 
        StringTokenizer tokenizer = new StringTokenizer(input); 
        int sum = 0; 
        System.out.println("Integers:"); 
        while (tokenizer.hasMoreTokens())  
        { 
            int number = Integer.parseInt(tokenizer.nextToken()); 
            System.out.println(number); 
            sum += number; 
        } 
        System.out.println("Sum: " + sum); 
    } 
}
