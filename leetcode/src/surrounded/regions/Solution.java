package surrounded.regions;

public class Solution {

  public void solve(char[][] board) {
    int row = board.length;
    if (row == 0) {
      return;
    }

    int col = board[0].length;

    for (int i = 0; i < row; i++) {
      if (board[i][0] == 'O') {
        dfs(i, 0, board, row, col);
      }
      if (board[i][col - 1] == 'O') {
        dfs(i, col - 1, board, row, col);
      }
    }

    for (int j = 0; j < col; j++) {
      if (board[0][j] == 'O') {
        dfs(0, j, board, row, col);
      }
      if (board[row - 1][j] == 'O') {
        dfs(row - 1, j, board, row, col);
      }
    }

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        System.out.println("i " + i + " j " + board[i][j]);
        if (board[i][j] == '*') {
          board[i][j] = 'O';
        } else if (board[i][j] == 'O') {
          board[i][j] = 'X';
        }
      }
    }

  }

  private void dfs(int i, int j, char[][] board, int rows, int cols) {
    if (i >= rows || j >= cols || i < 0 || j < 0) {
      return;
    }

    if (board[i][j] == '*' || board[i][j] == 'X') {
      return;
    }

    int[] dir1 = {1, -1, 0, 0};
    int[] dir2 = {0, 0, 1, -1};

    board[i][j] = '*';
    for (int k = 0; k < 4; k++) {
      dfs(i + dir1[k], j + dir2[k], board, rows, cols);
    }
  }
}
