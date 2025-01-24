import java.util.Scanner;

public class squareRoot {
    public static int binarySearch(int n){
        int low=1;
        int high=n;
        while(low<=high){
            int mid = low+(high-low)/2;
            int value=mid*mid;
            if(value<=n){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return high;
    }
    public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      System.out.println(binarySearch(n));
    }
}