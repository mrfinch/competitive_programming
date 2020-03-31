package merge.intervals;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class Solution {

  public int[][] merge(int[][] intervals) {
    if (intervals.length == 0) {
      return intervals;
    }

    List<List<Integer>> intervalList = new ArrayList<>();

    for (int i = 0; i < intervals.length; i++) {
      List<Integer> list = new ArrayList<>();
      for (int j = 0; j < intervals[0].length; j++) {
        list.add(intervals[i][j]);
      }
      intervalList.add(list);
    }

    intervalList.sort(new Comparator<List<Integer>>() {
      @Override
      public int compare(List<Integer> integers, List<Integer> t1) {
        return Integer.compare(integers.get(0), t1.get(0));
      }
    });

    List<List<Integer>> result = new ArrayList<>();

    List<Integer> last = intervalList.get(0);
    result.add(last);
    for (int i = 1; i < intervalList.size(); i++) {
      List<Integer> current = intervalList.get(i);
      if (last.get(1) >= current.get(0)) {
        last.set(1, Math.max(last.get(1), current.get(1)));
      } else {
        last = intervalList.get(i);
        result.add(last);
      }
    }

    int[][] out = new int[result.size()][2];

    for (int i = 0; i < result.size(); i++) {
      List<Integer> curr = result.get(i);
      out[i][0] = curr.get(0);
      out[i][1] = curr.get(1);
    }

    return out;

  }

}
