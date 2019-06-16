#pragma once
#include <iostream>
#include <vector>
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
		auto vert = Vertices[i];
		vert.Edges->erase(vertex);
	}
}

template<typename T>
void Graph<T>::AddEdge(Vertex<T>* a, Vertex<T>* b, double weight)
{
	a.Edges.insert(a, weight);
	b.Edges.inswert(b, weight);
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
		auto vert = Vertices[i];
		if (vert.Value = value)
		{
			return &vert;
		}
	}
	return nullptr;
}