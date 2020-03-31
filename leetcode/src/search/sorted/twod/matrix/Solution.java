package search.sorted.twod.matrix;

public class Solution {

  public boolean searchMatrix(int[][] matrix, int target) {
    int row = matrix.length;
    if (row == 0) {
      return false;
    }
    int col = matrix[0].length;

    int i = row - 1;
    int j = 0;
    boolean found = false;
    while (i >= 0 && j < col) {
      int val = matrix[i][j];

      if (val < target) {
        j++;
      } else if (val > target) {
        i--;
      } else {
        found = true;
        break;
      }
    }

    return found;
  }
}
