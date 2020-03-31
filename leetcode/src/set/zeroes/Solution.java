package set.zeroes;

public class Solution {

  public void setZeroes(int[][] matrix) {
    int row = matrix.length;
    int col = matrix[0].length;

    boolean rowZ = false;
    boolean colZ = false;

    for (int i = 0; i < row; i++) {
      if (matrix[i][0] == 0) {
        rowZ = true;
        break;
      }
    }

    for (int j = 0; j < col; j++) {
      if (matrix[0][j] == 0) {
        colZ = true;
        break;
      }
    }
    //System.out.println("b " + rowZ + " " + colZ);

    for (int i = 1; i < row; i++) {
      for (int j = 1; j < col; j++) {
        if (matrix[i][j] == 0) {
          //System.out.println(i + " " + j);
          matrix[i][0] = 0;
          matrix[0][j] = 0;
        }
      }
    }

    for (int i = 1; i < row; i++) {
      for (int j = 1; j < col; j++) {
        if (matrix[i][0] == 0 || matrix[0][j] == 0) {
          matrix[i][j] = 0;
        }
      }
    }

    if (rowZ) {
      for (int i = 0; i < row; i++) {
        matrix[i][0] = 0;
      }
    }

    if (colZ) {
      for (int j = 0; j < col; j++) {
        matrix[0][j] = 0;
      }
    }

  }
}
