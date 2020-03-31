package sort.colors;

public class Solution {

  public void sortColors(int[] nums) {
    int low = 0;
    int mid = 0;
    int high = nums.length - 1;

    while (mid < high) {
      int temp = nums[mid];

      if (temp == 0) {
        swap(low, mid, nums);
        low++;
        mid++;
      } else if (temp == 1) {
        mid++;
      } else {
        swap(mid, high, nums);
        high--;
      }
    }
  }

  private void swap(int i, int j, int[] nums) {
    int t = nums[i];
    nums[i] = nums[j];
    nums[j] = t;
  }

  public static void main(String[] args) {
    System.out.println('b' - 'a');
    System.out.println('a' - 'a');
    System.out.println('z' - 'a');
  }

}
