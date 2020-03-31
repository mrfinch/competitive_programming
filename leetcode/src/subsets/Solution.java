package subsets;

import java.util.ArrayList;
import java.util.List;

public class Solution {

  public List<List<Integer>> subsets(int[] nums) {

    int pow = (int)Math.pow(2, nums.length);

    List<List<Integer>> result = new ArrayList<>();
    for (int i = 0; i < pow; i++) {
      List<Integer> set = new ArrayList<>();
      System.out.println("i " + i);
      for (int j = 0; j < nums.length; j++) {
        System.out.println("j " + (1 << j));
        if ((i & (1 << j)) != 0) { // or could use (((i>>j) & 1) == 1)
          set.add(nums[j]);
        }
      }
      result.add(set);
    }

    return result;
  }
}
