import java.util.Scanner;

class Word
{
    private char word[];
    Word(char[] arr) {
        this.word = new char[arr.length]; 
        for (int i = 0; i < arr.length; i++) {
            this.word[i] = arr[i]; 
        }
    }
    public boolean isPalindrome() {
        int left = 0;
        int right = word.length - 1;
        while (left < right) {
            if (word[left] != word[right]) {
                return false; 
            }
            left++;
            right--;
        }
        return true;
    }
}

public class PalindromeChecker {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter a word: ");
        String input = scanner.nextLine();
        Word w = new Word(input.toCharArray());

        if (w.isPalindrome()) 
            System.out.println("Palindrome.");
        else 
            System.out.println("Not Palindrome");
        scanner.close();
    }
}
