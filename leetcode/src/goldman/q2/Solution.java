package goldman.q2;

import java.util.List;

public class Solution {

  static int getCountOfPossibleTeams(List<Integer> coders) {
    int len = coders.size();
    int sum = 0;

    for (int i = 0; i < len; i++) {
      for (int j = i + 1; j < len; j++) {
        for (int k = j + 1; k < len; k++) {
          if (
              ((coders.get(i) < coders.get(j)) && (coders.get(j) < coders.get(k))) ||
              ((coders.get(i) > coders.get(j)) && (coders.get(j) > coders.get(k)))
          ) {
            sum += 1;
          }
        }
      }
    }

    return sum;
  }

}
