package add.two.nums.linkedlist;

public class Solution {
   public class ListNode {
      int val;
      ListNode next;
      ListNode(int x) { val = x; }
   }

  public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
    ListNode rev1 = l1;
    ListNode rev2 = l2;
    ListNode res = null;
    ListNode curr = null;

    int carry = 0;
    while (rev1 != null && rev2 != null) {
      int sum = rev1.val + rev2.val + carry;

      carry = sum / 10;
      if (res == null) {
        res = new ListNode((sum % 10));
        curr = res;
      } else {
        ListNode node = new ListNode((sum % 10));
        curr.next = node;
        curr = node;
      }
      rev1 = rev1.next;
      rev2 = rev2.next;
    }

    while (rev1 != null) {
      int sum = rev1.val + carry;

      carry = sum / 10;
      if (res == null) {
        res = new ListNode((sum % 10));
        curr = res;
      } else {
        ListNode node = new ListNode((sum % 10));
        curr.next = node;
        curr = node;
      }
      rev1 = rev1.next;
    }

    while (rev2 != null) {
      int sum = rev2.val + carry;

      carry = sum / 10;
      if (res == null) {
        res = new ListNode((sum % 10));
        curr = res;
      } else {
        ListNode node = new ListNode((sum % 10));
        curr.next = node;
        curr = node;
      }
      rev2 = rev2.next;
    }

    //for 5 + 5 = 10
    if (carry != 0) {
      curr.next = new ListNode(carry);
    }

    return res;
  }

  private ListNode reverse(ListNode head) {
     ListNode curr = head;
     ListNode prev = null;

     while (curr != null) {
       ListNode temp = curr.next;
       curr.next = prev;
       prev = curr;
       curr = temp;
     }

     return prev;
  }

}
