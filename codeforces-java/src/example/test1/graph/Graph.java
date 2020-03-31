package example.test1.graph;

import java.util.Iterator;
import java.util.LinkedList;

public abstract class Graph {

  LinkedList<Integer>[] adjList;
  int vertices;

  public Graph(int vertices) {
    this.vertices = vertices;
    adjList = new LinkedList[vertices];

    for (int i = 0; i < vertices; i++) {
      adjList[i] = new LinkedList<>();
    }
  }

  public abstract void addEdge(int src, int dest);

  public void bfs(int start) {
    boolean[] visited = new boolean[vertices];

    LinkedList<Integer> queue = new LinkedList<Integer>();
    queue.push(start);
    visited[start] = true;
    while (!queue.isEmpty()) {
      Integer node = queue.poll();
      System.out.println(node);
      LinkedList<Integer> neighbors = adjList[node];

      for (Integer val : neighbors) {
        if (!visited[val]) {
          visited[val] = true;
          queue.push(val);
        }
      }

    }

  }

  public void dfs(int start) {
    boolean[] visited = new boolean[vertices];
    visited[start] = true;
    dfsUtil(start, visited);
  }

  private void dfsUtil(int node, boolean[] visited) {
    System.out.println(node);
    LinkedList<Integer> neighbors = adjList[node];

    Iterator<Integer> iterator = neighbors.iterator();
    while (iterator.hasNext()) {
      int n = iterator.next();
      if (!visited[n]) {
        visited[n] = true;
        dfsUtil(n, visited);
      }
    }
  }

}
