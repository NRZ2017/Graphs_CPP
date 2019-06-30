#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
#include"Vertex.h"
#include "PriorityQueue.h"

template <typename T>
class Graph
{
private:
	const int& edgecount = EdgeCount;
public:
	std::vector<Vertex<T>> Vertices;
	int EdgeCount = 0;

	Graph()
	{
	}

	void AddVertex(Vertex<T> vert);
	void RemoveVertex(Vertex<T> vert);
	void AddEdge(Vertex<T>* a, Vertex<T>* b, double weight);
	void AddEdge(T a, T b, double weight);
	Vertex<T>* GetVertex(T value);
	void AddDirectedEdge(Vertex<T>* start, Vertex<T>* end, double weight);
	bool ContainsLoop(Vertex<T>* start);
};

template <typename T>
void Graph<T>::AddVertex(Vertex<T> vert)
{
	Vertices.push_back(vert);
}

template <typename T>
void Graph<T>::RemoveVertex(Vertex<T> vertex)
{
	for (int i = 0; i < Vertices.size(); i++)
	{
		auto vert = Vertices.at(i);
		vert.Neighbors.erase(vertex);

		//vert.Edges->erase(&vertex);
		
	}
}

template<typename T>
void Graph<T>::AddEdge(Vertex<T>* a, Vertex<T>* b, double weight)
{

	a->Edges->insert(std::pair<Vertex<T>*, double>(b, weight));
	b->Edges->insert(std::pair<Vertex<T>*, double>(a, weight));
}

template <typename T>
void Graph<T>::AddEdge(T a, T b, double weight)
{
	auto x = GetVertex(a);
	auto y = GetVertex(b);

	if (x == nullptr || y == nullptr)
	{
		throw std::exception{};
	}

	AddEdge(x, y, weight);
}


template <typename T>
Vertex<T>* Graph<T>::GetVertex(T value)
{
	// check by giving it a bad value, should get a nullptr back
	for (int i = 0; i < Vertices.size(); i++)
	{
		auto vert = Vertices.at(i);
		if (vert.Value = value)
		{
			return &vert;
		}
	}
	return nullptr;
}

template <typename T>
void Graph<T>::AddDirectedEdge(Vertex<T>* start, Vertex<T>* end, double weight)
{
	start->Edges->insert(std::pair<Vertex<T>*, double>(end, weight));
}

template <typename T>
bool Graph<T>::ContainsLoop(Vertex<T>* start)
{
	//Depth First Search
	std::stack<Vertex<T>*> stack;// = std::stack<Vertex<T>*>();
	std::vector<Vertex<T>*> visited;// = std::unordered_set<Vertex<T>*>();

	stack.push(&Vertices.at(0));
	while (stack.size() != 0)
	{
		int index = 0;
		Vertex<T>* temp;
		Vertex<T>* curr = stack.top();
		stack.pop();
		visited[index++] = curr;
		for (int i = 0; i < curr->Edges->size(); i++)
		{
			
		}
	}

}