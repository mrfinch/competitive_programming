package example.test1.unique.path.with.obstacles;

/**
 * // TODO Comment
 */
public class Solution {

  public int uniquePathsWithObstacles(int[][] obstacleGrid) {
    int row = obstacleGrid.length;
    int col = obstacleGrid[0].length;
    int[][] cnt = new int[row][col];

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {

        if (obstacleGrid[i][j] == 1) {
          cnt[i][j] = 0;
        } else if ((i == 0 && j == 0)) {
          cnt[i][j] = 1;
        } else if (i == 0) {
          cnt[i][j] = cnt[i][j - 1];
        } else if (j == 0) {
          cnt[i][j] = cnt[i - 1][j];
        } else {
          cnt[i][j] = cnt[i][j - 1] + cnt[i - 1][j];
        }
      }
    }
    return cnt[row - 1][col - 1];
  }

  public static void main(String[] args) {
    
  }
}
