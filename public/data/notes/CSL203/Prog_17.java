
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    // QuickSort method
    public static void quickSort(String[] names, int low, int high) {
        if (low < high) {
            String pivot = names[high];
            int i = low - 1;

            for (int j = low; j < high; j++) {
                if (names[j].compareToIgnoreCase(pivot) <= 0) {
                    i++;
                    String temp = names[i];
                    names[i] = names[j];
                    names[j] = temp;
                }
            }

            String temp = names[i + 1];
            names[i + 1] = names[high];
            names[high] = temp;
            int pi = i+1;

            quickSort(names, low, pi - 1);
            quickSort(names, pi + 1, high);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of names: ");
        int n = scanner.nextInt();
        scanner.nextLine(); 

        String[] names = new String[n];

        System.out.println("Enter the names:");
        for (int i = 0; i < n; i++) {
            names[i] = scanner.nextLine();
        }

        quickSort(names, 0, names.length - 1);

        System.out.println("Names in ascending order:");
        System.out.println(Arrays.toString(names));

        scanner.close();
    }
}

