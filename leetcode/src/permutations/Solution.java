package permutations;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class Solution {

  public List<List<Integer>> permute(int[] nums) {
    List<List<Integer>> result = new ArrayList<List<Integer>>();

    fun(0, nums, result);
    return result;
  }

  private void fun(int index, int[] nums, List<List<Integer>> result) {
    if (index == nums.length) {
      //result.add(Arrays.asList(nums));
      List<Integer> list = IntStream.of(nums)
          .boxed().collect(Collectors.toCollection(ArrayList::new));
      result.add(list);
      return;
    }

    for (int i = index; i < nums.length; i++) {
      swap(i, index, nums);
      fun(index + 1, nums, result);
      swap(index, i, nums);
    }

  }

  private void swap(int i, int j, int[] nums) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
  }


}
