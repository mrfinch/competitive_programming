package example.test1.graph;

public class UndirectedGraph extends Graph {

  public UndirectedGraph(int vertices) {
    super(vertices);
  }

  @Override
  public void addEdge(int src, int dest) {
    adjList[src].add(dest);
    adjList[dest].add(src);
  }
  
}
