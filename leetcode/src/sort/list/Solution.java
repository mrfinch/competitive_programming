package sort.list;

public class Solution {

   public static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
   }

   public class SplitNode {
     ListNode h1;
     ListNode h2;

     public SplitNode(ListNode h1, ListNode h2) {
       this.h1 = h1;
       this.h2 = h2;
     }
   }
  public ListNode sortList(ListNode head) {
    ListNode newHead = mergeSort(head);
    return newHead;
  }

  private ListNode mergeSort(ListNode head) {
     if (head == null || head.next == null) {
       return head;
     }
    SplitNode node = splitList(head);
     if (node == null) {
       return null;
     }

    ListNode a = mergeSort(node.h1);
    ListNode b = mergeSort(node.h2);

    return merge(a, b);
  }

  private SplitNode splitList(ListNode node) {
     if (node == null) {
       return null;
     }
     ListNode slow = node;
     ListNode fast = node.next;
    System.out.println(slow.val);
    if (fast == null) {
      return new SplitNode(slow, null);
    }

    while (fast.next != null) {
       slow = slow.next;
       fast = fast.next.next;
     }

     slow.next = null;
     return new SplitNode(slow, fast);
  }

  private ListNode merge(ListNode h1, ListNode h2) {
    if (h1 == null) {
      return h2;
    } else if (h2 == null) {
      return h1;
    }

    ListNode res = null;

    if (h1.val < h2.val) {
      res = h1;
      h1 = h1.next;
    } else {
      res = h2;
      h2 = h2.next;
    }
    ListNode head = res;

    while (h1 != null && h2 != null) {
      if (h1.val < h2.val) {
        res.next = h1;
        h1 = h1.next;
      } else {
        res.next = h2;
        h2 = h2.next;
      }
      res = res.next;
    }


     while (h1 != null) {
       res.next = h1;
       h1 = h1.next;
       res = res.next;
     }
     while (h2 != null) {
       res.next = h2;
       h2 = h2.next;
       res = res.next;
     }

     return head;
  }


  public static void main(String[] args) {
    Solution s = new Solution();
    ListNode li = new ListNode(15);
    ListNode l2 = new ListNode(10);
    ListNode l3 = new ListNode(5);
    ListNode l4 = new ListNode(20);
    li.next = l2;
    l2.next = l3;
    l3.next = l4;

    ListNode temp = li;
    while (li != null) {
      System.out.println(li.val);
      li = li.next;
    }

    ListNode r = s.mergeSort(temp);

    System.out.println("sorted " + temp.val);
    while (r != null) {
      System.out.println(r.val);
      r = r.next;
    }
  }
  
}
