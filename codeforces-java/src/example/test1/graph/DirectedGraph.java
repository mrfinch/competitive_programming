package example.test1.graph;

/**
 * // TODO Comment
 */
public class DirectedGraph extends Graph {

  public DirectedGraph(int vertices) {
    super(vertices);
  }

  @Override
  public void addEdge(int src, int dest) {
    adjList[src].add(dest);
  }
}
