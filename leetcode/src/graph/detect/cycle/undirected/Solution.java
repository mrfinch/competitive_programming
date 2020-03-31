package graph.detect.cycle.undirected;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class Solution {

  // undirected
  class Graph {
    int nodes;
    Map<Integer, Set<Integer>> edges;

    public Graph(int numCourses) {
      this.nodes = numCourses;
      edges = new HashMap<>();

      for (int i = 0; i < numCourses; i++) {
        edges.put(i, new HashSet<>());
      }
    }

    public void addEdge(int src, int dest) {
      edges.get(src).add(dest);
      edges.get(dest).add(src);
    }

    public boolean isCyclic() {
      boolean[] vis = new boolean[nodes];
      for (int i = 0; i < nodes; i++) {
        if (!vis[i]) {
          if (dfs(i, -1, vis)) {
            return true;
          }
        }
      }
      return false;
    }

    public boolean dfs(int node, int parent, boolean[] vis) {
      vis[node] = true;

      Set<Integer> neighbors = edges.get(node);
      boolean res = false;
      for (Integer n: neighbors) {
        if (!vis[n]) {
          res = res || dfs(n, node, vis);
        } else if (parent != n) {
          res = true;
          break;
        }
      }
      return res;
    }
  }

  public void init() {
    Graph g1 = new Graph(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    String res = g1.isCyclic() ? "Graph contains cycle\n" : "Graph doesn't contain cycle\n";
    System.out.println(res);

    Graph g2 = new Graph(3);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    res = g2.isCyclic() ? "Graph contains cycle\n" : "Graph doesn't contain cycle\n";
    System.out.println(res);
  }

  public static void main(String[] args) {
    Solution s = new Solution();
    s.init();
  }
  
}
