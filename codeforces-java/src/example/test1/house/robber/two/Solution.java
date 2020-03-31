package example.test1.house.robber.two;

/**
 * // TODO Comment
 */
public class Solution {

  public int rob(int[] nums) {
    int len = nums.length;
    int[] cnt = new int[len];
    if (len == 0) {
      return 0;
    }
    cnt[0] = nums[0];
    for (int i = 1; i < len; i++) {
      cnt[i] = Math.max(cnt[i - 1], nums[i]);
      if (i - 2 == 0 && ((i + 1) == len)) {
        System.out.println("here " + i);

      } else {
        if (i - 2 >= 0) {
          cnt[i] = Math.max(cnt[i - 2] + nums[i], cnt[i]);
        }
      }
      if(i == len - 1)
      System.out.println("i " + i + " cnt " + cnt[i]);
    }
    return cnt[len - 1];
  }

  public static void main(String[] args) {
    Solution s = new Solution();
    int[] n = {2,3,2};

    System.out.println(s.rob(n));
    int[] q = {1,2,3,1};
    System.out.println(s.rob(q));
    int[] a = {1,2,1,1};
    System.out.println(s.rob(a));
    int b[] = {2,1,1,2};
    System.out.println(s.rob(b));
  }
}
