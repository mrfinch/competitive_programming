package search.rotated.array;

import java.util.Arrays;

public class Solution {

  //public int search(int[] nums, int target) {
  //  int low = 0;
  //  int high = nums.length - 1;
  //
  //  int ind = -1;
  //  while (low <= high) {
  //    int mid = (low + high) / 2;
  //    int curr = nums[mid];
  //
  //    if (curr == target) {
  //      ind = mid;
  //      break;
  //    }
  //
  //    if (curr > target) {
  //      if (nums[low] < target) {
  //        high = mid - 1;
  //      } else if (nums[low] == target) {
  //        ind = low;
  //        break;
  //      } else {
  //        low = mid + 1;
  //      }
  //    } else {
  //      if (nums[high] < target) {
  //        high = mid - 1;
  //      } else if (nums[high] == target) {
  //        ind = high;
  //        break;
  //      } else {
  //        low = mid + 1;
  //      }
  //    }
  //  }
  //  return ind;
  //}

  public int search(int[] nums, int target) {
    int pivot = findPivot(nums);
    int res;
    if (pivot == -1) {
      res = Arrays.binarySearch(nums, target);
    } else {
      if (target >= nums[pivot] && target <= nums[nums.length - 1]) {
        res = Arrays.binarySearch(nums, pivot, nums.length, target);
      } else {
        res = Arrays.binarySearch(nums, 0, pivot, target);
      }
    }
    return  res < 0 ? -1 : res;

  }

  private int findPivot(int[] nums) {
    int i = 0;
    int j = nums.length - 1;
    int res = -1;

    while (i < j) {
      int mid = (i + j) / 2;


      if (mid - 1 >= 0 && nums[mid] < nums[mid - 1]) {
        res = mid;
        break;
      }

      if (mid + 1 < nums.length && nums[mid] > nums[mid + 1]) {
        res = mid + 1;
        break;
      }

      if (nums[i] < nums[mid]) {
        i = mid + 1;
      } else {
        j = mid - 1;
      }
    }
    return res;
  }

  

  public static void main(String[] args) {
    int[] a = {4, 5, 6, 7, 0, 1, 2, 3};
    Solution s = new Solution();
    System.out.println(s.findPivot(a));
  }

}
