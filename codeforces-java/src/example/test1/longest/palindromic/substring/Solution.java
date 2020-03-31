package example.test1.longest.palindromic.substring;

/**
 * // TODO Comment
 */
class Solution {
  public String longestPalindrome(String s) {
    boolean[][] res = new boolean[s.length()][s.length()];
    int len = s.length();
    int max = 0;
    int start = -1;

    for (int i = 0; i < len; i++) {
      res[i][i] = true;
      max = 1;
      start = i;
    }
    for (int i = 0; i < len - 1; i++) {
      if (s.charAt(i) == s.charAt(i + 1)) {
        res[i][i + 1] = true;
        max = 2;
        start = i;
      }
    }


    for (int k = 3; k <= len; k++) {
      for (int i = 0; i < len - k + 1; i++) {
        System.out.println(i + " " + k + " " + res[i + 1][i + k - 2]);
        if (s.charAt(i) == s.charAt(i + k - 1) && res[i + 1][i + k - 2]) {
          //System.out.println("hel " + i + " " + k + " " + res[i + 1][i + k - 2]);
          res[i][i + k - 1] = true;
          max = k;
          start = i;
        }
      }
    }
    System.out.println(start + " " + max);
    if (start != -1) {
      return s.substring(start, start + max);
    } else {
      return s;
    }

  }

  public static void main(String[] args) {
    Solution s = new Solution();
    System.out.println(s.longestPalindrome("babad"));
    System.out.println(s.longestPalindrome("cbbd"));
    System.out.println(s.longestPalindrome("ccc"));
    System.out.println(s.longestPalindrome("abcba"));
  }
}