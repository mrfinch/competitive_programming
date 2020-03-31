package example.test1.graph;

/**
 * // TODO Comment
 */
public class Solution {

  public static void main(String[] args) {
    UndirectedGraph undirectedGraph = new UndirectedGraph(4);

    undirectedGraph.addEdge(0, 1);
    undirectedGraph.addEdge(0, 2);
    undirectedGraph.addEdge(1, 2);
    undirectedGraph.addEdge(2, 0);
    undirectedGraph.addEdge(2, 3);
    undirectedGraph.addEdge(3, 3);

    System.out.println("Following is Breadth First Traversal "+
        "(starting from vertex 2)");

    undirectedGraph.bfs(2);

    System.out.println("Following is Depth First Traversal "+
        "(starting from vertex 2)");

    undirectedGraph.dfs(2);

    DirectedGraph directedGraph = new DirectedGraph(4);

    directedGraph.addEdge(0, 1);
    directedGraph.addEdge(0, 2);
    directedGraph.addEdge(1, 2);
    directedGraph.addEdge(2, 0);
    directedGraph.addEdge(2, 3);
    directedGraph.addEdge(3, 3);

    System.out.println("Following is Breadth First Traversal of Directed"+
        "(starting from vertex 2)");

    undirectedGraph.bfs(2);

    System.out.println("Following is Depth First Traversal of Directed"+
        "(starting from vertex 2)");

    undirectedGraph.dfs(2);


  }
}
