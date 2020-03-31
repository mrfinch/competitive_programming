package kth.largest.array;

import java.util.Iterator;
import java.util.PriorityQueue;

public class Solution {

  public int findKthLargest(int[] nums, int k) {
    PriorityQueue<Integer> priorityQueue = new PriorityQueue<>(k);

    for (int i = 0; i < k; i++) {
      priorityQueue.add(nums[i]);
    }

    int len = nums.length;
    for (int i = k; i < len; i++) {
      if (priorityQueue.peek() < nums[i]) {
        priorityQueue.poll();
        priorityQueue.add(nums[i]);
      }
    }

    Iterator<Integer> iterator = priorityQueue.iterator();
    int mn = Integer.MAX_VALUE;
    while (iterator.hasNext()) {
      mn = Math.min(iterator.next(), mn);
    }

    return mn;
  }

}
