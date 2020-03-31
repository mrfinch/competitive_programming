package graph.word.ladder;

import java.util.ArrayList;
import java.util.Deque;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.Set;

public class Solution {

  class Graph {
    Map<String, Set<String>> edges;

    public Graph(List<String> nodes) {
      edges = new HashMap<>();
      for (String node: nodes) {
        edges.put(node, new HashSet<>());
      }
    }

    public void addEdge(String src, String dest) {
      edges.get(src).add(dest);
    }
  }

  public int ladderLength(String beginWord, String endWord, List<String> wordList) {
    List<String> nodes = new ArrayList<>(wordList);
    nodes.add(beginWord);
    Graph g = new Graph(nodes);

    for (int i = 0; i < nodes.size(); i++) {
      for (int j = i + 1; j < nodes.size(); j++) {
        String s1 = nodes.get(i);
        String s2 = nodes.get(j);
        if (isAdjacent(s1, s2)) {
          g.addEdge(s1, s2);
          g.addEdge(s2, s1);
        }
      }
    }

    int ctr = 0;
    Deque<String> queue = new LinkedList<>();
    HashSet<String> vis = new HashSet<>();
    queue.addLast(beginWord);
    vis.add(beginWord);

    boolean done = false;
    while (!queue.isEmpty()) {
      Deque<String> temp = new LinkedList<>();
      ctr++;
      
      while (!queue.isEmpty()) {
        String node = queue.removeFirst();

        if (node.equals(endWord)) {
          done = true;
        }

        if (done){
          break;
        }

        for (String n: g.edges.get(node)) {
          if (!vis.contains(n)) {
            temp.addLast(n);
            vis.add(n);
          }
        }

      }

      if (done) {
        break;
      }


      queue = temp;
    }

    return done ? ctr : 0;
  }

  private boolean isAdjacent(String s1, String s2) {
    int ctr = 0;

    for (int i = 0; i < s1.length(); i++) {
      if (s1.charAt(i) != s2.charAt(i)) {
        ctr++;
      }
    }
    return ctr == 1;
  }

}
