package graph.course.sched;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class Solution {

  class Graph {
    Map<Integer, Set<Integer>> edges;

    public Graph(int numCourses) {
      edges = new HashMap<>();

      for (int i = 0; i < numCourses; i++) {
        edges.put(i, new HashSet<>());
      }
    }

    public void addEdge(int src, int dest) {
      edges.get(src).add(dest);
    }
  }

  public boolean canFinish(int numCourses, int[][] prerequisites) {
    Graph g = new Graph(numCourses);

    int row = prerequisites.length;
    if (row == 0) {
      return true;
    }
    int col = prerequisites[0].length;
    for (int i = 0; i < row; i++) {
      g.addEdge(prerequisites[i][0], prerequisites[i][1]);
    }

    boolean[] vis = new boolean[numCourses];

    boolean out = false;
    boolean[] inStack = new boolean[vis.length];

    for (int i = 0; i < numCourses; i++) {
      if (!vis[i]) {
        boolean temp = hasCycle(i, vis, g, inStack);
        if (temp) {
          out = temp;
          break;
        }
      }
    }

    return !out;
  }

  private boolean hasCycle(int node, boolean[] vis, Graph g, boolean[] inStack) {
    if (vis[node]) {
      return false;
    }

    inStack[node] = true;
    vis[node] = true;
    boolean res = false;
    Set<Integer> neighbors = g.edges.get(node);
    for (Integer n : neighbors) {
      if (inStack[n]) {
        res = true;
      }
      res = res || hasCycle(n, vis, g, inStack);
    }
    inStack[node] = false;

    return res;
  }

}
