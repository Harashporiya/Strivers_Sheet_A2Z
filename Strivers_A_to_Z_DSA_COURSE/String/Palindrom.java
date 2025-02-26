package Strivers_A_to_Z_DSA_COURSE.String;

import java.util.ArrayList;
import java.util.Scanner;

class Palindrom {
  
  public static boolean checkPalindrom(String s){
    int start = 0;
    int end = s.length() - 1;
    while(start < end){
      if(s.charAt(start) != s.charAt(end)){
        return false;
      }
      start++;
      end--;
    }
    return true;
  }
  
  public static String firstPalindrom(ArrayList<String> arr){
    for(int i = 0; i < arr.size(); i++){
       if(checkPalindrom(arr.get(i))){
        return arr.get(i);
       }
    }
    return ""; 
  }

  public static void main(String [] args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    sc.nextLine();  
    String str = sc.nextLine();
    ArrayList<String> arr = new ArrayList<>();
    
    String[] words = str.split(" ");
    for (int i = 0; i < n; i++) {
      arr.add(words[i]);
    }
    
    System.out.println(firstPalindrom(arr));
    
    sc.close();
  }
}
