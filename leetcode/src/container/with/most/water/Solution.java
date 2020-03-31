package container.with.most.water;

public class Solution {

  public int maxArea(int[] height) {
    int mx = Integer.MIN_VALUE;

    int i = 0;
    int j = height.length - 1;

    while (i < j) {
      int val = Math.min(height[i], height[j]);
      mx = Math.max(mx, val * (j - i));

      if (height[i] < height[j]) {
        i++;
      } else {
        j--;
      }
    }

    return mx;
  }
  
}
