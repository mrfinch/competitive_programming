package graph.strongly.connected.components;

import java.util.Deque;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Map;
import java.util.Set;

public class Solution {

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
    }
  }

  public void printStronglyConnectedComponents(Graph g) {
    Deque<Integer> stack = new LinkedList<>();
    boolean[] vis = new boolean[g.nodes];

    for (int i = 0; i < g.nodes; i++) {
      if (!vis[i]) {
        dfs(i, vis, stack, g);
      }
    }

    System.out.println("stack: ");
    for(Integer n: stack) {
      System.out.println(n);
    }
    Graph rGraph = getReverseGraph(g);
    boolean[] vis2 = new boolean[rGraph.nodes];

    while (!stack.isEmpty()) {
      Integer node = stack.removeLast();

      if (!vis2[node]) {
        Deque<Integer> queue = new LinkedList<>();
        dfs(node, vis2, queue, rGraph);

        System.out.print("SCC: ");
        for (Integer n: queue) {
          System.out.print(n + " ");
        }
        System.out.println();
      }

    }

  }

  public void dfs(int node, boolean[] vis, Deque<Integer> path, Graph g) {
    vis[node] = true;
    Set<Integer> neighbors = g.edges.get(node);

    for (Integer n: neighbors) {
      if (!vis[n]) {
        dfs(n, vis, path, g);
      }
    }
    path.addLast(node);
  }

  public Graph getReverseGraph(Graph g) {
    Graph newGraph = new Graph(g.nodes);

    for (int i = 0; i < g.nodes; i++) {
      Set<Integer> neighbors = g.edges.get(i);

      for (Integer n: neighbors) {
        newGraph.addEdge(n, i);
      }
    }

    return newGraph;
  }

  public void init() {
    Graph g = new Graph(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);

    printStronglyConnectedComponents(g);
  }

  public static void main(String[] args) {
    Solution s = new Solution();
    s.init();
  }

}
