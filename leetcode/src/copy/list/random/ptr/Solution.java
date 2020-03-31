package copy.list.random.ptr;

public class Solution {

  class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
      this.val = val;
      this.next = null;
      this.random = null;
    }
  }

  public Node copyRandomList(Node head) {

    Node curr = head;
    while (curr != null) {
      Node n = new Node(curr.val);
      Node temp = curr.next;
      curr.next = n;
      n.next = temp;
      curr = temp;
    }

    curr = head;
    while (curr != null) {
      curr.next.random = curr.random != null ? curr.random.next : null;
      curr = curr.next.next;
    }

    curr = head;
    Node newHead = curr != null ? curr.next : null;
    while (curr != null) {
      Node temp = curr.next;
      curr.next = temp.next;
      temp.next = curr.next != null ? curr.next.next : null;
      curr = curr.next;
    }

    return newHead;

  }
}
