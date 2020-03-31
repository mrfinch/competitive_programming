package codeforces.a;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main {

  public static void main(String[] args) {
    BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

    try {
      int t = Integer.parseInt(bufferedReader.readLine());
      List<Integer> res = new ArrayList<>();

      while (t > 0) {
        String[] arr = bufferedReader.readLine().split("\\s+");
        int[] temp = Arrays.stream(arr).mapToInt(Integer::parseInt).toArray();
        int n = temp[0];
        int m = temp[1];

        arr = bufferedReader.readLine().split("\\s+");
        int[] nums = Arrays.stream(arr).mapToInt(Integer::parseInt).toArray();

        int sum = 0;
        for (int i = 0; i < nums.length; i++) {
          sum += nums[i];
        }

        if (sum == m) {
          res.add(m);
        } else if (sum < m) {
          res.add(sum);
        } else {
          res.add(m);
        }

        t--;
      }
      for (Integer n: res) {
        System.out.println(n);
      }

    } catch (IOException e) {
      e.printStackTrace();  // TODO impl
    }


  }
}
