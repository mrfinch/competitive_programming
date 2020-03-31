package example.test1.coin.change;

import java.util.Arrays;

public class Solution {

  public int coinChange(int[] coins, int amount) {
    if (amount == 0) {
      return 0;
    }
    int[] dp = new int[amount + 1];
    Arrays.fill(dp, Integer.MAX_VALUE);

    for (int i = 1; i < dp.length; i++) {
      for (int j = 0; j < coins.length; j++) {
        if (i == coins[j]) {
          dp[i] = 1;
        } else if (coins[j] > i || dp[i - coins[j]] == Integer.MAX_VALUE) {
          // do nothing
        } else {
          dp[i] = Math.min(dp[i], dp[i - coins[j]] + 1);
        }
      }
    }
    return dp[amount] == Integer.MAX_VALUE ? -1 : dp[amount];
  }

  public static void main(String[] args) {
    Solution s = new Solution();
    int[] a = {1,2,5};
    System.out.println(s.coinChange(a, 11));
    int[] b = {2};
    System.out.println(s.coinChange(b, 3));
  }
}
