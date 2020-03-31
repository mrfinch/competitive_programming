package largest.number;

import java.util.Arrays;
import java.util.Comparator;

public class Solution {

  public String largestNumber(int[] nums) {
    Integer[] arr = new Integer[nums.length];

    for (int i = 0; i < nums.length; i++) {
      arr[i] = nums[i];
    }

    Arrays.sort(arr, new SortByNumber());

    StringBuilder res = new StringBuilder();
    for (Integer a: arr) {
      res.append(a);
    }

    String r = res.toString();
    return allZeros(r) ? "0" : r;
  }

  public class SortByNumber implements Comparator<Integer> {
    @Override
    public int compare(Integer integer, Integer t1) {
      return Long.compare(Long.parseLong(String.valueOf(t1) + String.valueOf(integer)), Long.parseLong(String.valueOf(integer) + String.valueOf(t1)));
    }
  }

  private boolean allZeros(String r) {
    boolean res = true;

    for (Character c: r.toCharArray()) {
      if (c != '0') {
        res = false;
        break;
      }
    }
    return res;
  }

}
