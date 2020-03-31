package palindrome.partitioning;

import java.util.ArrayList;
import java.util.List;

public class Solution {

  public List<List<String>> partition(String s) {
    List<List<String>> list = new ArrayList<>();

    fun(s, list, new ArrayList<>(), 0);

    return list;
  }

  private void fun(String s, List<List<String>> l, List<String> ls, int index) {
    if (index == s.length()) {
      List<String> x = new ArrayList<>(ls);
      l.add(x);
      return;
    }
    for (int i = index; i < s.length(); i++) {
      String curr = s.substring(index, i + 1);
      if (isPalindrome(curr)) {
        ls.add(curr);
        fun(s, l, ls, i + 1);
        ls.remove(ls.size() - 1);
      }
    }
  }

  //private void fun2(String s, int index, List<String> l) {
  //  for (int i = index; i < s.length(); i++) {
  //    String curr =
  //  }
  //}

  private boolean isPalindrome(String s) {
    int i = 0;
    int j = s.length() - 1;

    if (j == 0) {
      return true;
    }

    char[] a = s.toCharArray();
    boolean res = true;
    while (i < j) {
      if (a[i] == a[j]) {
        i++;
        j--;
      } else {
        res = false;
        break;
      }
    }
    return res;
  }

}
