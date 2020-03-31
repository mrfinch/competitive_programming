package delete.duplicates.sorted.array;

import java.util.Arrays;

public class Solution {


  private void deleteDuplicates(int[] n) {
    int writeIndex = 1;

    for (int i = 1; i < n.length; i++) {
      if (n[i - 1] != n[i]) {
        n[writeIndex] = n[i];
        writeIndex++;
      }
    }

    for (int i = writeIndex; i < n.length; i++) {
      n[i] = 0;
    }

  }

  public static void main(String[] args) {
    int[] a = {2, 3, 5, 5, 7, 11, 11, 11, 13}; // return  {2, 3, 5, 7, 11, 13, 0, 0, 0}

    Solution s = new Solution();
    s.deleteDuplicates(a);

    System.out.println(Arrays.toString(a));
  }
}
