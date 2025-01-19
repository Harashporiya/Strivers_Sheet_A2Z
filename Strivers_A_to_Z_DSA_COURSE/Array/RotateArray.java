import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class RotateArray {
    public static void main(String[] args) {
        List<Integer> arr = new ArrayList<>();
        arr.add(1);
        arr.add(2);
        arr.add(3);
        arr.add(4);
        arr.add(5);
        arr.add(6);
        arr.add(7);

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of rotations:");
        int k = sc.nextInt();
        sc.close();

        k = k % arr.size();
        if (k > 0) {
             rotate(arr, k);
        }

        System.out.println("Rotated Array: " + arr);
    }

    public static void rotate(List<Integer> arr, int k) {
        int n = arr.size();
        reverse(arr, 0, n - 1);
        reverse(arr, 0, k - 1);
        reverse(arr, k, n - 1);
    }

    public static void reverse(List<Integer> arr, int start, int end) {
        while (start < end) {
            int temp = arr.get(start);
            arr.set(start, arr.get(end));
            arr.set(end, temp);
            start++;
            end--;
        }
    }
}
