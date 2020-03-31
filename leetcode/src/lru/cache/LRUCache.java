package lru.cache;

import java.util.HashMap;
import java.util.Map;

class LRUCache {

  class Node {
    private int val;
    private Node next;
    private Node prev;
    private int key;

    public Node(int key, int val) {
      this.val = val;
      this.key = key;
    }
  }

  private Map<Integer, Node> cache;
  private Node head;
  private Node tail;
  private int capacity;

  public LRUCache(int capacity) {
    cache = new HashMap<>(capacity);
    this.capacity = capacity;
  }

  public int get(int key) {
    int out = -1;
    if (cache.containsKey(key)) {
      Node n = cache.get(key);

      if (n != head) {
        Node temp = n.next;
        Node prev = n.prev;
        if (prev != null) {
          prev.next = temp;
          if (temp == null) {
            tail = prev;
          }
        }

        if (temp != null) {
          temp.prev = prev;
        }

        n.next = head;
        head.prev = n;
        n.prev = null;
        head = n;
      }

      out = n.val;
    }
    //printState("get");
    return out;
  }

  public void put(int key, int value) {
    if (cache.size() == this.capacity && !cache.containsKey(key)) {
      int k = tail.key;
      cache.remove(k);

      Node prev = tail.prev;
      if (prev != null) {
        prev.next = null;
        tail = prev;
      } else {
        head = null;
      }

    }

    if (cache.containsKey(key)) {
      Node n = cache.get(key);
      n.val = value;

      if (n != head) {
        Node temp = n.next;
        Node prev = n.prev;
        if (prev != null) {
          prev.next = temp;
          if (temp == null) {
            tail = prev;
          }
        }

        if (temp != null) {
          temp.prev = prev;
        }

        n.next = head;
        head.prev = n;
        n.prev = null;
        head = n;
      }

    } else {
      Node n = new Node(key, value);
      cache.put(key, n);
      if (head == null || tail == null) {
        head = n;
        tail = n;
      } else {
        //System.out.println("here " + head.val + " " + n.val);
        n.next = head;
        head.prev = n;
        head = n;
        //System.out.println("herex " + head.val + " " + n.val);
      }
    }
    //printState("put");

  }

  private void printState(String val) {
    System.out.println("print state " + val);
    for(Map.Entry<Integer, Node> entry: cache.entrySet()) {
      System.out.println("k " + entry.getKey() + " v " + entry.getValue().val + " h " + (head != null ? head.key : "") + " t " + (tail != null ? tail.key : ""));
    }
  }
}
