package word.search;

public class Solution {

  public boolean exist(char[][] board, String word) {
    int row = board.length;
    int col = board[0].length;
    boolean result = false;
    boolean[][] vis = new boolean[board.length][board[0].length];
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (search(board, word, i, j, 0, vis)) {
          result = true;
          break;
        }
      }
      if (result) {
        break;
      }
    }
    return result;
  }

  public boolean search(char[][] board, String word, int r, int c, int index, boolean[][] vis) {
    if (board[r][c] != word.charAt(index)) {
      return false;
    }

    if (index == word.length() - 1) {
       return board[r][c] == word.charAt(index);
    }

    int[] row = new int[] {0, 0, -1, 1};
    int[] col = new int[] {1, -1, 0, 0};

    int rSize = board.length;
    int cSize = board[0].length;
    boolean result = false;

    vis[r][c] = true;
    for (int i = 0; i < row.length; i++) {
     int r1 = r + row[i];
     int c1 = c + col[i];

     if (r1 >= rSize || c1 >= cSize || r1 < 0 || c1 < 0) {
       continue;
     }

     if (vis[r1][c1]) {
       continue;
     }

     result = result || search(board, word, r1, c1, index + 1, vis);
     if (result) {
       break;
     }
    }
    vis[r][c] = false;

    return result;
  }

}
