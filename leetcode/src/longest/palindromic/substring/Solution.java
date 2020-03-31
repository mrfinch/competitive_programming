package longest.palindromic.substring;

public class Solution {

  public String longestPalindrome(String s) {
    int len = s.length();
    boolean[][] dp = new boolean[len][len];

    int mx = 0;
    int mxI = 0;
    for (int l = 0; l < len; l++) {
      for (int j = 0; j + l < len; j++) {
        int i = j + l;

        if (i == j) {
          dp[i][j] = true;
          mx = 1;
        } else {
          if (s.charAt(i) == s.charAt(j)) {
            //System.out.println("i " + i + " j " + j);
            if (j + 1 < len && i - 1 >= 0) {
              if (i == j + 1) {
                dp[j][i] = true;
              } else {
                dp[j][i] = dp[j + 1][i - 1];
              }

              //System.out.println("i " + i + " j " + j + " dp " + dp[j][i]);
              if (dp[j][i] && i - j + 1 > mx) {
                mx = i - j + 1;
                mxI = j;
              }
            }
          }
        }
      }
      //System.out.println("l " + l + " mx " + mx);
    }

    return s.substring(mxI, mxI + mx);
  }

}
