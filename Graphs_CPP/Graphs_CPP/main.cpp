#include "Graph.h"
#include <vector>
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
	graph.AddEdge("D", "A", 4);

	std::vector<Vertex<std::string>*> path = graph.DepthFirstSearch("A", "C");

	for (int i = 0; i < path.size(); i++)
	{
		std::cout << (*path.at(i)).Value << std::endl;
	}
};