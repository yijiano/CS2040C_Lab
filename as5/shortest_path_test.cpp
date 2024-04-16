#include <gtest/gtest.h>

#include <utility>

#include "graph.h"
#include "shortest_path.h"
#include <gtest/gtest.h>

#include <utility>

#include "graph.h"
#include "shortest_path.h"

using namespace std;

Graph createSimpleGraph() {
  Graph g(4);
  g.addEdge(0, 1, 1);
  g.addEdge(0, 2, 2);
  g.addEdge(1, 3, 5);
  g.addEdge(2, 3, 1);
  return g;
}

Graph createComplexGraph() {
  Graph g(8);
  g.addEdge(0, 1, 5);
  g.addEdge(0, 7, 8);
  g.addEdge(0, 4, 9);
  g.addEdge(1, 3, 15);
  g.addEdge(1, 2, 12);
  g.addEdge(1, 7, 4);
  g.addEdge(3, 6, 9);
  g.addEdge(2, 3, 3);
  g.addEdge(2, 6, 11);
  g.addEdge(4, 7, 5);
  g.addEdge(4, 5, 4);
  g.addEdge(4, 6, 20);
  g.addEdge(5, 2, 1);
  g.addEdge(5, 6, 13);
  g.addEdge(7, 5, 6);
  g.addEdge(7, 2, 7);
  return g;
}

class ShortestPathParamTest
    : public testing::TestWithParam<tuple<Graph, int, int, int, vector<int>>> {
};

TEST_P(ShortestPathParamTest, test_public_shortest_path_example) {
  Graph g(0);
  int src, dest, expected_distance;
  vector<int> expected_path;
  tie(g, src, dest, expected_distance, expected_path) = GetParam();
  Path p = shortestPath(g, src, dest);
  EXPECT_EQ(p.total_distance(), expected_distance);
  ASSERT_EQ(p.path().size(), expected_path.size());
  for (int i = 0; i < p.path().size(); i++) {
    EXPECT_EQ(p.path()[i], expected_path[i]);
  }
}

TEST(test_trains, SimpleTest) {
  Graph g(10);

  int src = 1;
  int dest = 8;

  g.addEdge(0, 2,  103);
  g.addEdge(0, 3,  156);
  g.addEdge(1, 2,   20);
  g.addEdge(1, 5,   67);
  g.addEdge(1, 6,  144);
  g.addEdge(2, 1,   42);
  g.addEdge(2, 7,  128);
  g.addEdge(3, 1,  180);
  g.addEdge(3, 4,   26);
  g.addEdge(3, 5,  193);
  g.addEdge(3, 7,  175);
  g.addEdge(3, 8,  121);
  g.addEdge(4, 0,  107);
  g.addEdge(4, 1,  135);
  g.addEdge(4, 8,   89);
  g.addEdge(4, 9,   80);
  g.addEdge(5, 3,  120);
  g.addEdge(5, 6,  151);
  g.addEdge(6, 2,  122);
  g.addEdge(6, 3,   37);
  g.addEdge(6, 9,   29);
  g.addEdge(7, 4,   89);
  g.addEdge(7, 8,   81);
  g.addEdge(8, 3,   45);
  g.addEdge(8, 4,   94);

  Path p = shortestPath(g, src, dest);
    
   // process output

  std::string student_id = "A0271585W";  // Define the string variable
  cout << endl << "student_id = \"" << student_id << "\"" << endl;

  std::string output = "path = [";
  for (int i = 0; i < p.path().size(); i++) {
    output += "'";
    output += string(1 , (char) ('A' + p.path()[i]));
    output += "'";
    if (i < p.path().size() - 1) output += ", ";
  }
  output += "]";
  cout << output << endl;

  cout << "length = " << p.total_distance() << endl << endl;
}


INSTANTIATE_TEST_CASE_P(
    PublicTestValues, ShortestPathParamTest,
    testing::Values(make_tuple(createSimpleGraph(), 0, 1, 1, vector<int>{0, 1}),
                    make_tuple(createSimpleGraph(), 0, 2, 2, vector<int>{0, 2}),
                    make_tuple(createSimpleGraph(), 0, 3, 3,
                               vector<int>{0, 2, 3}),
                    make_tuple(createSimpleGraph(), 1, 3, 5, vector<int>{1, 3}),
                    make_tuple(createComplexGraph(), 0, 6, 25,
                               vector<int>{0, 4, 5, 2, 6})));
