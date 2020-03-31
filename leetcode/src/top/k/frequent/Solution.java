package top.k.frequent;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;

public class Solution {

  public class Node {
    public int val;
    public int ctr;

    public Node(int val, int ctr) {
      this.val = val;
      this.ctr = ctr;
    }
  }

  public List<Integer> topKFrequent(int[] nums, int k) {
    Map<Integer, Integer> numCount = new HashMap<>();

    for (int num: nums) {
      if (numCount.containsKey(num)) {
        numCount.put(num, numCount.get(num) + 1);
      } else {
        numCount.put(num, 1);
      }
    }

    PriorityQueue<Node> priorityQueue = new PriorityQueue<>(k, new Comparator<Node>() {
      @Override
      public int compare(Node node, Node t1) {
        return Integer.compare(node.ctr, t1.ctr);
      }
    });

    int cnt = 0;

    for (Map.Entry<Integer, Integer> entry: numCount.entrySet()) {
      if (cnt < k) {
        priorityQueue.add(new Node(entry.getKey(), entry.getValue()));
        cnt++;
      } else {
        Node top = priorityQueue.peek();
        if (entry.getValue() > top.ctr) {
          priorityQueue.poll();
          priorityQueue.add(new Node(entry.getKey(), entry.getValue()));
        }
      }
    }
    Iterator<Node> iterator = priorityQueue.iterator();
    List<Integer> result = new ArrayList<>();
    while (iterator.hasNext()) {
      result.add(iterator.next().val);
    }

    return result;
  }

}
