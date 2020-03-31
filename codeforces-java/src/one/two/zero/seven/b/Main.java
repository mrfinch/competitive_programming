package one.two.zero.seven.b;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * // TODO Comment
 */
public class Main {

  public static void main(String[] args) {

    BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
    
    {
      try {

        String[] input = bufferedReader.readLine().split("\\s+");
        int[] num = Arrays.stream(input).mapToInt(Integer::parseInt).toArray();

        int row = num[0];
        int[][] arr = new int[num[0]][num[1]];

        int ind = 0;
        while (row > 0) {
          int[] inp = Arrays.stream(bufferedReader.readLine().split("\\s+")).mapToInt(Integer::parseInt).toArray();
          arr[ind] = inp;
          ind++;
          row--;
        }

        int[][] dup = new int[num[0]][num[1]];
        boolean all_zero = true;
        for (int i = 0; i < num[0]; i++) {
          for (int j = 0; j < num[1]; j++) {
            dup[i][j] = 0;

            if (all_zero) {
              all_zero = !(arr[i][j] == 1);
            }

          }
        }

            List<List<Integer>> result = new ArrayList<>();
        for (int i = 0; i < num[0] - 1; i++) {
          for (int j = 0; j < num[1] - 1; j++) {
            boolean first = arr[i][j] == 1;
            boolean second = arr[i + 1][j] == 1;
            boolean third = arr[i][j + 1] == 1;
            boolean fourth = arr[i + 1][j + 1] == 1;

            if (first && second && third && fourth) {
              dup[i][j] = 1;
              dup[i + 1][j] = 1;
              dup[i][j + 1] = 1;
              dup[i + 1][j + 1] = 1;

              int finalI = i + 1;
              int finalJ = j + 1;
              result.add(new ArrayList<Integer>(){{ add(finalI); add(finalJ); }});
            }
          }
        }

        boolean allConverted = true;
        for (int i = 0; i < num[0]; i++) {
          for (int j = 0; j < num[1]; j++) {
            if (arr[i][j] != dup[i][j]) {
              //System.out.println(i + " " + j);
              allConverted = false;
              break;
            }
          }
        }

        //System.out.println(allConverted + " " + result.size() + " " + all_zero);
        if (all_zero) {
          System.out.println(0);
        } else if (result.size() == 0 || !allConverted) {
          System.out.println(-1);
        } else {
          System.out.println(result.size());
          for (List<Integer> out: result) {
            System.out.println(out.get(0) + " " + out.get(1));
          }
        }

        // System.out.println(Arrays.deepToString(arr));

      } catch (IOException e) {
        e.printStackTrace();  // TODO impl
      }
    }
  }
}
