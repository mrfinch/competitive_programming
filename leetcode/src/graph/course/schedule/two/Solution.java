package graph.course.schedule.two;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Set;

public class Solution {

  class Graph {
    private int v;
    private List<Set<Integer>> adj;

    Graph(int v) {
      this.v = v;
      adj = new ArrayList<>();
      for (int i = 0; i < v; i++) {
        adj.add(new HashSet<>());
      }
    }

    public void addEdge(int src, int dest) {
      adj.get(src).add(dest);
    }
  }

  private static boolean impossible = false;

  // topological sort with cycle check
  public int[] findOrder(int numCourses, int[][] prerequisites) {
    impossible = false;
    Graph g = new Graph(numCourses);

    for (int i = 0; i < prerequisites.length; i++) {
      g.addEdge(prerequisites[i][0], prerequisites[i][1]);
    }
    boolean[] vis = new boolean[numCourses];
    List<Integer> list = new ArrayList<>();
    boolean[] inStack = new boolean[numCourses];

    for (int i = 0; i < numCourses; i++) {
      if (vis[i]) {
        continue;
      }
      if (impossible) {
        break;
      }
      reverseTopoSort(vis, list, i, g, inStack);
    }

    if (impossible) {
      return new int[0];
    }

    // fill all elements which have no pre-requi
    for (int i = 0; i < numCourses; i++) {
      if (!vis[i]) {
        list.add(numCourses);
      }
    }

    int[] out = new int[numCourses];
    Iterator<Integer> iterator = list.iterator();
    int i = 0;
    while (iterator.hasNext()) {
      out[i++] = iterator.next();
    }
    return out;
  }

  private void reverseTopoSort(boolean[] vis, List<Integer> list, int index, Graph g, boolean[] inStack) {
    if (vis[index]) {
      return;
    }

    vis[index] = true;
    inStack[index] = true;

    Set<Integer> set = g.adj.get(index);

    for (Integer aSet : set) {
      if (inStack[aSet]) {
        impossible = true;
      }
      reverseTopoSort(vis, list, aSet, g, inStack);
    }
    inStack[index] = false;
    list.add(index);
  }
}
