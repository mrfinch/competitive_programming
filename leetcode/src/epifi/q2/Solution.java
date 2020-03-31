package epifi.q2;

import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;

public class Solution {

  static int droppedRequests(List<Integer> requestTime) {
    Map<Integer, Integer> count = new LinkedHashMap<>();

    int len = requestTime.size();
    int start = requestTime.get(0);
    int end = requestTime.get(requestTime.size() - 1);

    for (int i = 0; i < len; i++) {
      Integer t = requestTime.get(i);
      if (count.containsKey(t)) {
        count.put(t, count.get(t) + 1);
      } else {
        count.put(t, 1);
      }
    }

    int oneCtr = 0;
    for (Map.Entry<Integer, Integer> entry: count.entrySet()) {
      Integer val = entry.getValue();
      oneCtr += (val <= 3 ? 0 : val - 3);
    }

    int tenCtr = 0;
    for (Map.Entry<Integer, Integer> entry: count.entrySet()) {
      Integer val = entry.getValue();
      Integer key = entry.getKey();

      int s = key - 10;
      int sum = 0;
      while (s <= key) {
        sum += count.getOrDefault(s, 0);
        s++;
      }
      tenCtr += (sum <= 20 ? 0 : sum - 20);
    }

    //int tenCtr = 0;
    //for (int i = 10; i <= end; i += 10) {
    //  int s = i - 9;
    //  int sum = 0;
    //  while (s <= i) {
    //    sum += count.getOrDefault(s, 0);
    //    s++;
    //  }
    //  System.out.println("ten " + tenCtr);
    //
    //  tenCtr += (sum <= 20 ? 0 : sum - 20);
    //}

    int sixtyCtr = 0;
    for (Map.Entry<Integer, Integer> entry: count.entrySet()) {
      Integer val = entry.getValue();
      Integer key = entry.getKey();

      int s = key - 60;
      int sum = 0;
      while (s <= key) {
        sum += count.getOrDefault(s, 0);
        s++;
      }
      sixtyCtr += (sum <= 60 ? 0 : sum - 60);
    }

    //int sixtyCtr = 0;
    //for (int i = 60; i <= end; i += 60) {
    //  int s = i - 59;
    //  int sum = 0;
    //  while (s <= i) {
    //    sum += count.getOrDefault(s, 0);
    //    s++;
    //  }
    //  System.out.println("sixty " + sixtyCtr);
    //  sixtyCtr += (sum <= 60 ? 0 : sum - 60);
    //}

    System.out.println("one " + oneCtr + " " + tenCtr + " " + sixtyCtr);
    return oneCtr + tenCtr + sixtyCtr;


  }
}
