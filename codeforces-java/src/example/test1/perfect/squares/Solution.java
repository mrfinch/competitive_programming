package example.test1.perfect.squares;

public class Solution {

  public int numSquares(int n) {
    int[] dp = new int[n + 1];
    for (int i = 0; i < n + 1; i++) {
      dp[i] = i;
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= i; j++) {
        if (j * j > i) {
          break;
        }
        dp[i] = Math.min(dp[i], dp[i - (j * j)] + 1);
      }
    }

    return dp[n];
  }

  public static void main(String[] args) {
    Solution s = new Solution();
    System.out.println(s.numSquares(10));
    System.out.println(s.numSquares(12));
    System.out.println(s.numSquares(13));
  }
}
