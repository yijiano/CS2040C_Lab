#include "graph.h"
#include "shortest_path.h"
#include "heap.hpp"

#define VERY_SMALL_NUMBER (-1 * 2147483647) // INT_MIN is somehow not working

Path shortestPath(const Graph& g, int source, int dest) {
  Heap<GraphEdge> pq; // priority queue implemented with min heap
  vector<int> distTo; // init all distances to very small number INT_MIN
  vector<int> closestNode; // shortest path from adjcaent nodes a to b, closestNode[b] = a
  for (int i = 0; i < g.num_vertices(); ++i) {
    distTo.push_back(VERY_SMALL_NUMBER);
    closestNode.push_back(-1);
  }
  
  // main loop
  distTo[source] = 0;
  int currNode = source;
  while (currNode != dest) {

    // pre-processing to to convert weights to negative so maxHeap functions as minHeap
    forward_list<GraphEdge> adjNodes = g.edges_from(currNode);
    while (!adjNodes.empty()) {
      
      // weight conversion
      GraphEdge temp = adjNodes.front();
      int tempWeight = -1 * temp.weight();
      int tempDestination = temp.dest();
      adjNodes.pop_front();

      // if current node is source, then adjacent nodes' closest node must be the source
      if (currNode == source) {
        distTo[tempDestination] = tempWeight;
        closestNode[tempDestination] = currNode;
        pq.insert(GraphEdge(tempDestination, -1 * distTo[tempDestination]));
      }

      // node distance has never been updated before
      if (distTo[tempDestination] == VERY_SMALL_NUMBER) {
        pq.insert(GraphEdge(tempDestination, -1 * distTo[tempDestination]));
      }

      // relax distances
      if (distTo[tempDestination] < distTo[currNode] + tempWeight) { // reversed due to minheap implementation
	      distTo[tempDestination] = distTo[currNode] + tempWeight;
        pq.changeKey(temp, GraphEdge(tempDestination, -1 * distTo[tempDestination]));
	      closestNode[tempDestination] = currNode;
		  }
    }
    currNode = pq.extractMax().dest(); // extract the node in the pq with the shortest estimated distance
  }

  // back tracking to rebuild shortest path from dest to source
  currNode = dest;
  vector<int> result;
  while (currNode != source) {
    result.insert(result.begin(), currNode);
    currNode = closestNode[currNode];
  }
  result.insert(result.begin(), currNode);
  return Path(-1 * distTo[dest], result);
}