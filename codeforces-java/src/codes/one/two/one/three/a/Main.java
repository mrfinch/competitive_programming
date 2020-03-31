package codes.one.two.one.three.a;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * // TODO Comment
 */
public class Main {

  public static void main(String[] args) {
    BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

    int size = 0;
    try {
      size = Integer.parseInt(bufferedReader.readLine());
    } catch (IOException e) {
      e.printStackTrace();  // TODO impl
    }

    int result = 0;
    try {
      String[] num = bufferedReader.readLine().split("\\s+");
      int odd = 0;
      for (int i = 0; i < num.length; i++) {
        odd += (Long.parseLong(num[i]) % 2 == 1) ? 1 : 0;
      }
      int even = num.length - odd;
      result = odd < even ? odd : even;

    } catch (IOException e) {
      e.printStackTrace();  // TODO impl
    }

    System.out.println(result);

  }
}
