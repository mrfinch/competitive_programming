package binary.inorder;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class Solution {

  public class TreeNode {
      int val;
      TreeNode left;
      TreeNode right;
      TreeNode(int x) { val = x; }
  }

  public List<Integer> inorderTraversal(TreeNode root) {

    Stack<TreeNode> stack = new Stack<TreeNode>();
    TreeNode curr = root;

    List<Integer> result = new ArrayList<Integer>();
    while (!stack.empty() || curr != null) {
      while (curr != null) {
        stack.push(curr);
        curr = curr.left;
      }

      TreeNode node = stack.pop();
      result.add(node.val);

      curr = node.right;
    }

    return result;

  }

}
