#include "Graph.h"
#include <string>

int main()
{
	Graph<std::string> graph;
	graph.AddVertex("A");
	graph.AddVertex("B");
	graph.AddVertex("C");
	graph.AddVertex("D");
	graph.AddEdge("A", "B", 1);
	graph.AddEdge("B", "C", 2);
	graph.AddEdge("C", "D", 3);
	graph.AddEdge("D", "A", 2);
};