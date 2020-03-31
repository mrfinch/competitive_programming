package zigzag.level.traversal;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Deque;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Solution {

  public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
  }

  public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
    Deque<TreeNode> queue1 = new LinkedList<>();
    Deque<TreeNode> queue2 = new LinkedList<>();
    List<List<Integer>> result = new ArrayList<>();

    if (root != null) {
      queue1.addLast(root);
    }
    while (!(queue1.isEmpty() && queue2.isEmpty())) {
      List<Integer> list = new ArrayList<>();
      if (queue2.isEmpty()) {
        while (!queue1.isEmpty()) {
          TreeNode node = queue1.removeFirst();
          list.add(node.val);
          if (node.left != null) {
            queue2.addLast(node.left);
          }
          if (node.right != null) {
            queue2.addLast(node.right);
          }
        }
      } else {
        while (!queue2.isEmpty()) {
          TreeNode node = queue2.removeFirst();
          list.add(node.val);
          if (node.left != null) {
            queue1.addLast(node.left);
          }
          if (node.right != null) {
            queue1.addLast(node.right);
          }
        }
        Collections.reverse(list);
      }
      result.add(list);
    }
    return result;

  }
}
