package product.except.self;

public class Solution {

  public int[] productExceptSelf(int[] nums) {
    int[] output = new int[nums.length];

    for (int i = 0; i < nums.length; i++) {
      output[i] = i - 1 >= 0 ? output[i - 1] * nums[i] : nums[i];
    }

    int right = 1;
    for (int i = nums.length - 1; i > 0; i--) {
      output[i] = output[i - 1] * right;
      right *= nums[i];
    }
    output[0] = right;

    return output;
  }
  
}
