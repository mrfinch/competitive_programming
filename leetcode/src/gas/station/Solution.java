package gas.station;

public class Solution {

  public int canCompleteCircuit(int[] gas, int[] cost) {
    int total = 0;
    for (int i = 0; i < gas.length; i++) {
      total += (gas[i] - cost[i]);
    }

    if (total < 0) {
      return -1;
    }

    int start = 0;
    int curr = 0;
    for (int i = 0; i < gas.length; i++) {
      curr += (gas[i] - cost[i]);

      if (curr < 0) {
        start = i + 1;
        curr = 0;
      }
    }

    return start;
  }
  
}
