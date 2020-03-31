package hackerrank.arrays.left.rotation;

public class Solution {

  static int[] rotLeft(int[] a, int d) {
    reverse(a, 0, d - 1);
    reverse(a, d, a.length - 1);
    reverse(a, 0 , a.length - 1);
    return a;
  }

  private static void reverse(int[] a, int i, int j) {
    while (i < j) {
      int temp = a[i];
      a[i] = a[j];
      a[j] = temp;
      i++;
      j--;
    }
  }
  
}
