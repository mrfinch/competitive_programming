package first.last.position.sorted.array;

public class Solution {

  public int[] searchRange(int[] nums, int target) {
    int index = -1;

    int low = 0;
    int high = nums.length - 1;

    int mid;
    while (low <= high) {
      mid = (low + high) / 2;

      int curr = nums[mid];
      if (curr == target) {
        index = mid;
        break;
      } else if (curr < target) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }

    int[] a = new int[2];
    if (index == -1) {
      a[0] = -1;
      a[1] = -1;
      return a;
    }
    int lowIndex = index;

    low = 0;
    high = index;
    while (low <= high) {
      mid = (low + high) / 2;
      int curr = nums[mid];

      if (curr == target) {
        lowIndex = mid;
        high = mid - 1;
      } else if (curr < target) {
        low = mid + 1;
      }
    }

    low = index;
    high = nums.length - 1;
    int highIndex = index;
    while (low <= high) {
      mid = (low + high) / 2;
      int curr = nums[mid];

      if (curr == target) {
        highIndex = mid;
        low = mid + 1;
      } else if (curr > target) {
        high = mid - 1;
      }
    }

    a[0] = lowIndex;
    a[1] = highIndex;

    return a;
  }
  
}
