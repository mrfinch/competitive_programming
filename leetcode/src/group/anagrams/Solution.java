package group.anagrams;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Solution {

  public List<List<String>> groupAnagrams(String[] strs) {
    Map<String, List<String>> result = new HashMap<>();

    for (String s: strs) {
      String sorted = getSortedString(s);
      if (result.containsKey(sorted)) {
        List<String> curr = result.get(sorted);
        curr.add(s);
        result.put(sorted, curr);
      } else {
        result.put(sorted, new ArrayList<String>(){{ add(s); }});
      }
    }

    List<List<String>> out = new ArrayList<>();
    for (Map.Entry<String, List<String>> entry: result.entrySet()) {
      List<String> temp = entry.getValue();
      out.add(temp);
    }

    return out;
  }

  private String getSortedString(String s) {
    char[] x = s.toCharArray();
    Arrays.sort(x);
    return new String(x);
  }

}
