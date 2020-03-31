package trie;

public class Trie {

  public class Node {
    Node[] child;
    int leafCtr;
    int ctr;

    public Node() {
      this.child = new Node[26];
      leafCtr = 0;
      ctr = 0;
    }

    public void setLeafCtr(int leafCtr) {
      this.leafCtr = leafCtr;
    }

    public void setCtr(int ctr) {
      this.ctr = ctr;

    }

    public void initChild() {
      for (int i = 0; i < 26; i++) {
        this.child[i] = new Node();
      }

    }
  }

  private Node root;

  /** Initialize your data structure here. */
  public Trie() {
    root = new Node();
  }

  /** Inserts a word into the trie. */
  public void insert(String word) {
    char[] words = word.toCharArray();
    fun(words, root, 0);
  }

  private void fun(char[] words, Node node, int ind) {
    Node n = node.child[words[ind] - 'a'];
    //System.out.println("n1 " + n);
    if (n == null) {
      node.initChild();
      n = node.child[words[ind] - 'a'];
    }
    //System.out.println("n " + n);
    n.setCtr(n.ctr + 1);
    if (ind != words.length - 1) {
      fun(words, n, ind + 1);
    } else {
      n.setLeafCtr(n.leafCtr + 1);
    }

  }

  /** Returns if the word is in the trie. */
  public boolean search(String word) {
    char[] words = word.toCharArray();
    return funSearch(words, root, 0);
  }

  private boolean funSearch(char[] words, Node node, int ind) {
    //System.out.println(ind);
    Node n = node.child[words[ind] - 'a'];
    if (n == null) {
      return false;
    }
    if (ind == words.length - 1) {
      //System.out.println(n.leafCtr);
      return n.leafCtr > 0;
    } else {
      if (n.ctr == 0) {
        return false;
      }
      return funSearch(words, n, ind + 1);
    }
  }

  /** Returns if there is any word in the trie that starts with the given prefix. */
  public boolean startsWith(String prefix) {
    char[] words = prefix.toCharArray();
    return funStartsWith(words, root, 0);
  }

  private boolean funStartsWith(char[] words, Node node, int ind) {
    Node n = node.child[words[ind] - 'a'];
    //System.out.println(ind + " " + n.ctr + " " + words.length);
    if (n == null) {
      return false;
    }
    if (ind == words.length - 1) {
      return n.ctr > 0;
    } else {
      if (n.ctr == 0) {
        return false;
      }
      return funStartsWith(words, n, ind + 1);
    }
  }

  //public static void main(String[] args) {
  //  Trie trie = new Trie();
  //
  //  //trie.insert("apple");
  //  //System.out.println(trie.search("apple"));   // returns true
  //  //trie.search("app");     // returns false
  //  //System.out.println(trie.startsWith("app")); // returns true
  //  //trie.insert("app");
  //  //trie.search("app");     // returns true
  //
  //  trie.insert("a");
  //  System.out.println(trie.startsWith("a")); // returns true
  //  System.out.println(trie.search("a")); // returns true
  //
  //}

}
