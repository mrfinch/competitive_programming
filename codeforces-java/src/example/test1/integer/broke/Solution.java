package example.test1.integer.broke;

import java.util.Arrays;

/**
 * // TODO Comment
 */
public class Solution {

  public int integerBreak(int n) {
    if (n == 1 || n == 2) {
      return 1;
    }
    if (n == 3) {
      return 2;
    }
    int[] dp = new int[n + 1];
    Arrays.fill(dp, 1);
    dp[2] = 2;
    dp[3] = 3;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j < i; j++) {
        dp[i] = Math.max(dp[i - j] * dp[j], dp[i]);
      }
    }
    return dp[n];
  }

  public static void main(String[] args) {
    Solution s = new Solution();
    System.out.println(s.integerBreak(2));
    System.out.println(s.integerBreak(10));

  }
}
