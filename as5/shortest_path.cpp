#include "graph.h"
#include "shortest_path.h"
#include "heap.hpp"

#define VERY_LARGE_NUMBER 2147483647 // idk why but INT_MAX is somehow not working

Path shortestPath(const Graph& g, int source, int dest) {
  Heap<GraphEdge> pq; // priority queue implemented with min heap
  vector<int> distTo(g.num_vertices(), VERY_LARGE_NUMBER); // init all distances to very small number INT_MIN
  vector<int> closestNode(g.num_vertices(), -1); // shortest path from adjcaent nodes a to b, closestNode[b] = a
  vector<int> path; // final path
  
  // main loop
  distTo[source] = 0;
  pq.insert(GraphEdge(source, 0)); // source-to-source weight is 0
  while (!pq.empty()) {
    int currNode = pq.extractMax().dest();
    if (currNode == dest) break; // early exit if destination is reached

    // relaxing edges
    for (GraphEdge currEdge : g.edges_from(currNode)) {
      int nextNode = currEdge.dest();
      int weight = currEdge.weight();
      int newDist = distTo[currNode] + weight;
      if (newDist < distTo[nextNode]) {
        distTo[nextNode] = newDist;
        closestNode[nextNode] = currNode;
        pq.insert(GraphEdge(nextNode, -newDist)); // distance is negated due to pq implementation
      }
    }
  }

  // Error handling if no path is found
  if (closestNode[dest] == -1 || distTo[dest] == VERY_LARGE_NUMBER) throw std::runtime_error("path does not exist"); 

  // Backtracking to build the shortest path
  for (int i = dest; i != source; i = closestNode[i]) {
      path.insert(path.begin(), i);
      if (closestNode[i] == -1) throw std::runtime_error("path does not exist");
  }

  path.insert(path.begin(), source);
  return Path(distTo[dest], path);
}