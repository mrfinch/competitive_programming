package three.sum;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class Solution {

  public List<List<Integer>> threeSum(int[] nums) {
    Arrays.sort(nums);
    List<List<Integer>> res = new ArrayList<>();

    Set<Integer> h = new HashSet<>();
    Set<List<Integer>> s = new HashSet<>();

    for (int i = 0; i < nums.length; i++) {
      int j = i + 1;
      int k = nums.length - 1;

      if (h.contains(nums[i])) {
        continue;
      }
      h.add(nums[i]);

      while (j < k) {
        if (j == i) {
          j++;
        }
        if (k == i) {
          k--;
        }

        int sum = nums[i] + nums[j] + nums[k];
        if (sum == 0) {
          List<Integer> a = new ArrayList<>();
          a.add(nums[i]);
          a.add(nums[j]);
          a.add(nums[k]);
          j++;
          k--;
          if (s.contains(a)) {
            continue;
          }
          s.add(a);
          res.add(a);
        } else if (sum > 0) {
          k--;
        } else {
          j++;
        }
      }
    }

    return res;
  }

}
