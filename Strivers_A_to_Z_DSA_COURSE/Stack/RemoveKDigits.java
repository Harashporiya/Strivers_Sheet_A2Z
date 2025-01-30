import java.util.Scanner;
import java.util.Stack;

public class RemoveKDigits {
    public static String removeKDigits(String s, int k) {
        Stack<Character> stack = new Stack<>();

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            while (!stack.isEmpty() && k > 0 && stack.peek() > c) {
                stack.pop();
                k--;
            }
            stack.push(c);
        }

        while (k > 0 && !stack.isEmpty()) {
            stack.pop();
            k--;
        }

        StringBuilder ans = new StringBuilder();
        while (!stack.isEmpty()) {
            ans.append(stack.pop());
        }
        ans.reverse();

        while (ans.length() > 1 && ans.charAt(0) == '0') {
            ans.deleteCharAt(0);
        }

        return ans.length() == 0 ? "0" : ans.toString();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number string:");
        String str = sc.nextLine();
        System.out.println("Enter the value of k:");
        int k = sc.nextInt();
        sc.close();

        System.out.println("Smallest number after removing " + k + " digits: " + removeKDigits(str, k));
    }
}
