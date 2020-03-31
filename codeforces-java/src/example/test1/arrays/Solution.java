package example.test1.arrays;

import java.util.Arrays;

public class Solution {


  public static void swap(int[] a, int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
  }
  
  public static void dutchNational(int[] a, int pivot) {
    int start = 0, end = a.length - 1, equal = 0;

    while (equal <= end) {
      if (a[equal] < pivot) {
        swap(a, start, equal);
        start++;
        equal++;
      } else if (a[equal] == pivot) {
        equal++;
      } else {
        swap(a, end, equal);
        end--;
      }
    }

  }

  public static void main(String[] args) {
    int[] a = new int[] {1,2,0, 1, 2, 2};
    System.out.println("dutch flag");
    dutchNational(a, 1);
    System.out.println(Arrays.toString(a));

  }
}
