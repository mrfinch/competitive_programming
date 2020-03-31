package validate.bst;

public class Solution {

  public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
  }

  public boolean isValidBST(TreeNode root) {
    return validate(null, null, root);
  }

  public boolean validate(Integer mn, Integer mx, TreeNode node) {
    if (node == null) {
      return true;
    }

    if (mn == null && mx == null) {
      return validate(null, node.val, node.left) && validate(node.val, null, node.right);
    } else if (mn == null) {
      if (node.val >= mx) {
        return false;
      }
      return validate(mn, node.val, node.left) && validate(node.val, mx, node.right);
    } else if (mx == null) {
      if (node.val <= mn) {
        return false;
      }
      return validate(mn, node.val, node.left) && validate(node.val, mx, node.right);
    } else {
      if (node.val <= mn || node.val >= mx) {
        return false;
      }
      return validate(mn, node.val, node.left) && validate(node.val, mx, node.right);
    }
  }

}
