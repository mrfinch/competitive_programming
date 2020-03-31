package jump.game;

public class Solution {

  public boolean canJump(int[] nums) {
    if (nums.length == 0) {
      return true;
    }
    int maxReach = nums[0];

    int i = 1;
    boolean res = true;
    while (i < nums.length) {
      if (i > maxReach) {
        res = false;
        break;
      }
      maxReach = Math.max(maxReach, i + nums[i]);
      i++;
    }
    return res;
  }

}
