import java.util.Scanner;

class CharFrequency {
    private char[] strArray;
    CharFrequency(String str) {
        this.strArray = str.toCharArray(); 
    }
    public int getFrequency(char ch) {
        int frequency = 0;
        for (char c : strArray) {
            if (c == ch) {
                frequency++;
            }
        }
        return frequency;
    }
}

public class CharFrequencyChecker {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter string: ");
        String inputString = scanner.nextLine();
        System.out.println("Enter character: ");
        char inputChar = scanner.next().charAt(0);
        CharFrequency charFrequency = new CharFrequency(inputString);
        int frequency = charFrequency.getFrequency(inputChar);
        System.out.println("The frequency of character: " + frequency);
        scanner.close();
    }
}
