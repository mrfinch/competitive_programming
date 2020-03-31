package example.test1.decode.ways;

/**
 * // TODO Comment
 */
public class Solution {

  public int numDecodings(String s) {
    if (s.charAt(0) == '0') {
      return 0;
    }
    int len = s.length() + 1;
    int[] cnt = new int[len];

    cnt[0] = 1;
    cnt[1] = 1;

    for (int i = 2; i < len; i++) {
      if (s.charAt(i - 1) != '0') {
        cnt[i] = cnt[i - 1];
      }


      if ( (Integer.parseInt(s.substring(i - 2, i - 1)) == 2 || Integer.parseInt(s.substring(i - 2, i - 1)) == 1 )) {
        if (Integer.parseInt(s.substring(i - 2, i - 1)) == 2) {
          if (Integer.parseInt(s.substring(i - 1, i)) < 7) {
            cnt[i] += cnt[i - 2];
          }
        } else {
          cnt[i] += cnt[i - 2];
        }

      }
    }
    return cnt[len - 1];
  }

  public static void main(String[] args) {
    Solution s = new Solution();
    System.out.println(s.numDecodings("12"));
    System.out.println(s.numDecodings("126"));
  }

}
