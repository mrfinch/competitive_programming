package kth.smallest.bst;

import java.util.ArrayList;
import java.util.List;

public class Solution {
  public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
  }

  public int kthSmallest(TreeNode root, int k) {
    List<Integer> arr = new ArrayList<>();
    fun(arr, root, k);
    return arr.get(k - 1);
  }

  private void fun(List<Integer> a, TreeNode root, int k) {
    // System.out.println(a.size() + " " + root.val);

    if (root == null) {
      return;
    }
    fun(a, root.left, k);
    System.out.println(a.size() + " " + root.val);
    if (a.size() == k) {
      return;
    } else {
      a.add(root.val);
    }
    fun(a, root.right, k);
  }





}
