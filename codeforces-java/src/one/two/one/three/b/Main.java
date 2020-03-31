package one.two.one.three.b;

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

    try {
      int t = Integer.parseInt(bufferedReader.readLine());
      List<Integer> result = new ArrayList<>();
      while (t > 0) {
        int n = Integer.parseInt(bufferedReader.readLine());
        String[] arr = bufferedReader.readLine().split("\\s+");
        int[] num = Arrays.stream(arr).mapToInt(Integer::parseInt).toArray();
        int lowest = num[num.length - 1];
        int cnt = 0;
        for (int i = num.length - 2; i >= 0; i--) {
          if (num[i] > lowest) {
            cnt++;
          }
          if (num[i] < lowest) {
            lowest = num[i];
          }
        }
        result.add(cnt);
        t--;
      }

      for (Integer out: result) {
        System.out.println(out);
      }
    } catch (IOException e) {
      e.printStackTrace();  // TODO impl
    }
  }
}
