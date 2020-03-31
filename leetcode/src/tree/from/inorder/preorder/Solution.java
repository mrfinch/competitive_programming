package tree.from.inorder.preorder;

/**
 * // TODO Comment
 */
public class Solution {

  public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
  }

  private static int preInd = 0;
  public TreeNode buildTree(int[] preorder, int[] inorder) {
    preInd = 0;
    return fun(0, preorder.length - 1, preorder, inorder);
  }

  private TreeNode fun(int inS, int inE, int[] pre, int[] in) {
    if (preInd >= pre.length || inS > inE) {
      return null;
    }
    TreeNode treeNode = new TreeNode(pre[preInd]);
    preInd++;
    if (inS == inE) {
      return treeNode;
    }
    int ind = findIndex(in, treeNode.val);
    treeNode.left = fun(inS, ind - 1, pre, in);
    treeNode.right = fun(ind + 1, inE, pre, in);
    return treeNode;
  }

  private int findIndex(int[] in, int num) {
    int ind = -1;
    for (int i = 0; i < in.length; i++) {
      if (in[i] == num) {
        ind = i;
        break;
      }
    }
    return ind;
  }
}
