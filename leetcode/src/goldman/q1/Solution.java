package goldman.q1;

public class Solution {

  static int noOfWaysToDrawTheGame(int totalScore) {
    int[] possible = new int[]{2, 4, 6};
    return fun(totalScore, possible);

  }

  static int fun(int score, int[] possible) {
    if (score == 0) {
      return 1;
    }
    if (score < 0) {
      return 0;
    }

    int res = 0;
    for (int i = 0; i < possible.length; i++) {
      if (possible[i] > score) {
        break;
      }
      res += fun(score - possible[i], possible);
    }

    return res;
  }
}
