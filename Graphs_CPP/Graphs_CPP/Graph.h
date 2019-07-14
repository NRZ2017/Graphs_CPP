#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
#include"Vertex.h"
#include "Edges.h"
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
	Vertex<T>* Search(T value);
	void AddVertex(Vertex<T> vert);
	void AddVertex(T value);
	bool RemoveVertex(Vertex<T> vert);
	bool RemoveEdge(Vertex<T>* a, Vertex<T>* b);
	bool AddEdge(Vertex<T>* a, Vertex<T>* b, double weight);
	bool AddEdge(T a, T b, double weight);
	Vertex<T>* GetVertex(T value);
	Edges<T>* GetEdge(T a, T b);
	Edges<T>* GetEdge(Vertex<T>* a, Vertex<T>* b);
};

template <typename T>
Vertex<T>* Graph<T>::Search(T value)
{
	for (int i = 0; i < Vertices.size(); i++)
	{
		auto item = Vertices.at(i);
		if (item.Value == value)
		{
			return &item;
		}
	}
}

template <typename T>
void Graph<T>::AddVertex(Vertex<T> vert)
{
	if (Search(vert.Value) != nullptr)
	{
		throw std::exception{};
	}
}
template <typename T>
void Graph<T>::AddVertex(T value)
{
	AddVertex(Vertex<T>(value));
}

template <typename T>
bool Graph<T>::RemoveVertex(Vertex<T> vertex)
{
	if (!(std::find(Vertices.begin, Vertices.end, vertex)))
	{
		return false;
	}

	for (int i = 0; i < Vertices.size; i++)
	{
		auto item = Vertices.at(i);
		for (int j = 0; j < item.Neighbors.size; j++)
		{
			if (item.Neighbors.at(i)->EndingPoint == &vertex)
			{
				RemoveEdge(&item, &vertex);
			}
		}
	}
}

template <typename T>
bool Graph<T>::RemoveEdge(Vertex<T>* a, Vertex<T>* b)
{
	auto edge = GetEdge(a, b);

	if (edge == nullptr)
	{
		return false;
	}

	a->Neighbors.erase(edge);
	return true;
}

template<typename T>
bool Graph<T>::AddEdge(Vertex<T>* a, Vertex<T>* b, double weight)
{
	if (!(GetEdge(a, b) == nullptr && std::find(Vertices.begin(), Vertices.end(), *a) != Vertices.end() && std::find(Vertices.begin(), Vertices.end(), *b) != Vertices.end()))
	{
		return false;
	}

	a->Neighbors.push_back(new Edges<T>(a, b, weight));
}

template <typename T>
bool Graph<T>::AddEdge(T a, T b, double weight)
{
	return AddEdge(Search(a), Search(b), weight);
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
Edges<T>* Graph<T>::GetEdge(T a, T b)
{
	return GetEdge(Search(a), Search(b));
}

template <typename T>
Edges<T>* Graph<T>::GetEdge(Vertex<T>* a, Vertex<T>* b)
{
	if (!(std::find(Vertices.begin(), Vertices.end(), *a) != Vertices.end() && std::find(Vertices.begin(), Vertices.end(), *b) != Vertices.end()))
	{
		return nullptr;
	}
	for (int i = 0; i < a->Neighbors.size(); i++)
	{
		auto item = a->Neighbors.at(i);
		if (item->EndingPoint == *b)
		{
			return item;
		}
	}
	return nullptr;
}

