package peak.element;

public class Solution {

  public int findPeakElement(int[] nums) {
    int low = 0;
    int high = nums.length - 1;
    int out = 0;
    while (low < high) {
      int mid = (low + high) / 2;

      if (nums[mid] > nums[mid + 1]) {
        high = mid;
        out = mid;
      } else {
        low = mid + 1;
        out = low;
      }

    }

    return out;
  }

}
