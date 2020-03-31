package word.breaking;

import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Solution {

  public boolean wordBreak(String s, List<String> wordDict) {

    Set<String> wordSet = new HashSet<>(wordDict);

    boolean[] dp = new boolean[s.length()];

    for (int i = 0; i < s.length(); i++) {
      for (int j = 0; j <= i; j++) {
        String curr = s.substring(j, i + 1);
        if (!wordSet.contains(curr)) {
          continue;
        }
        //System.out.println(curr + " " + j);
        if (j - 1 >= 0) {
          dp[i] = dp[i] || dp[j - 1];
        } else {
          dp[i] = true;
        }
      }
      //System.out.println("i " + i + " " + dp[i]);
    }

    return dp[s.length() - 1];

  }
}
