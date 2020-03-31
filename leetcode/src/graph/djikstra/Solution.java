package graph.djikstra;

import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Set;

public class Solution {

  class Node {
    int vertex;
    int cost;

    public Node(int vertex, int cost) {
      this.vertex = vertex;
      this.cost = cost;
    }
  }

  class Graph {
    Map<Integer, Set<Node>> edges;
    int nodes;

    public Graph(int numCourses) {
      this.nodes = numCourses;
      edges = new HashMap<>();

      for (int i = 0; i < numCourses; i++) {
        edges.put(i, new HashSet<>());
      }
    }

    public void addEdge(int src, Node dest) {
      edges.get(src).add(dest);
    }
  }

  public void djikstra(int src, Graph g) {
    Set<Integer> settled = new HashSet<>();
    int[] distance = new int[g.nodes];
    for (int i = 0; i < distance.length; i++) {
      distance[i] = Integer.MAX_VALUE;
    }

    PriorityQueue<Node> priorityQueue = new PriorityQueue<>(new Comparator<Node>() {
      @Override
      public int compare(Node node, Node t1) {
        return Integer.compare(node.cost, t1.cost);
      }
    });

    Node start = new Node(src, 0);
    priorityQueue.add(start);

    while (settled.size() != g.nodes && !priorityQueue.isEmpty()) {
      Node top = priorityQueue.poll();

      if (!settled.add(top.vertex)) {
        continue;
      }
      distance[top.vertex] = top.cost;

      Set<Node> neighbors = g.edges.get(top.vertex);

      for (Node n: neighbors) {
        if (!settled.contains(n.vertex)) {
          int newDist = top.cost + n.cost;
          if (newDist < distance[n.vertex]) {
            priorityQueue.add(new Node(n.vertex, newDist));
          }
        }
      }
    }

    for (int i = 0; i < g.nodes; i++) {
      System.out.println("shortest path from " + src + " to " + i + " is " + distance[i]);
    }
  }

  public void createAndRunDjiGraph() {
    Graph g = new Graph(5);
    Map<Integer, Set<Node>> adj = g.edges;

    adj.get(0).add(new Node(1, 9));
    adj.get(0).add(new Node(2, 6));
    adj.get(0).add(new Node(3, 5));
    adj.get(0).add(new Node(4, 3));

    adj.get(2).add(new Node(1, 2));
    adj.get(2).add(new Node(3, 4));

    djikstra(0, g);
  }

  public static void main(String[] args) {
    Solution s = new Solution();
    s.createAndRunDjiGraph();
  }
}
