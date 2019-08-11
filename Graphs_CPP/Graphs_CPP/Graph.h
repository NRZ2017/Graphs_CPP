#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
#include <limits>
#include"Vertex.h"
#include "Edges.h"
#include "PriorityQueue.h"

template <typename T>
class Graph
{
private:
	const int& edgecount = EdgeCount;

public:
	std::vector<Vertex<T>*> Vertices;
	int EdgeCount = 0;

	Graph()
	{
	}
	Vertex<T>* Search(T value);
	void AddVertex(Vertex<T>* vert);
	void AddVertex(T value);
	bool RemoveVertex(Vertex<T>* vert);
	bool RemoveEdge(Vertex<T>* a, Vertex<T>* b);
	bool AddEdge(Vertex<T>* a, Vertex<T>* b, double weight);
	bool AddEdge(T a, T b, double weight);
	Vertex<T>* GetVertex(T value);
	Edges<T>* GetEdge(T a, T b);
	Edges<T>* GetEdge(Vertex<T>* a, Vertex<T>* b);
	std::vector<Vertex<T>*> DepthFirstSearch(Vertex<T>* start, Vertex<T>* end);
	std::vector<Vertex<T>*> DepthFirstSearch(T start, T end);
};

template <typename T>
Vertex<T>* Graph<T>::Search(T value)
{
	for (int i = 0; i < Vertices.size(); i++)
	{
		auto item = Vertices.at(i);
		if (item->Value == value)
		{
			return item;
		}
	}
}

template <typename T>
void Graph<T>::AddVertex(Vertex<T>* vert)
{
	if (Search(vert->Value) == nullptr)
	{
		throw std::exception{};
	}
	Vertices.push_back(vert);
}
template <typename T>
void Graph<T>::AddVertex(T value)
{
	AddVertex(new Vertex<T>(value));
}

template <typename T>
bool Graph<T>::RemoveVertex(Vertex<T>* vertex)
{
	if (!(std::find(Vertices.begin, Vertices.end, &vertex)))
	{
		return false;
	}

	for (int i = 0; i < Vertices.size; i++)
	{
		auto item = Vertices.at(i);
		for (int j = 0; j < item->Neighbors.size(); j++)
		{
			if (item->Neighbors.at(i)->EndingPoint == vertex)
			{
				RemoveEdge(item, vertex);
			}
		}
	}
	return true;
}

template <typename T>
bool Graph<T>::RemoveEdge(Vertex<T>* a, Vertex<T>* b)
{
	auto edge = GetEdge(a, b);

	if (edge == nullptr)
	{
		return false;
	}

	int count;
	for (count = 0; count < a->Neighbors.size(); count++)
	{
		if (a->Neighbors.at(count) == edge)
		{
			break;
		}
	}

	a->Neighbors.erase(a->Neighbors.begin() + count);
	return true;
}
	 
template<typename T>
bool Graph<T>::AddEdge(Vertex<T>* a, Vertex<T>* b, double weight)
{
	auto tempEdge = GetEdge(a, b);
	if (tempEdge != nullptr && 
			std::find(Vertices.begin(), Vertices.end(), a) != Vertices.end() && 
			std::find(Vertices.begin(), Vertices.end(), b) != Vertices.end())
	{
		return false;
	}

	a->Neighbors.push_back(new Edges<T>(a, b, weight));
	EdgeCount++;
	return true;
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
		if (vert->Value == value)
		{
			return vert;
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
	if (!(std::find(Vertices.begin(), Vertices.end(), a) != Vertices.end() && std::find(Vertices.begin(), Vertices.end(), b) != Vertices.end()))
	{
		return nullptr;
	}
	for (int i = 0; i < a->Neighbors.size(); i++)
	{
		auto item = a->Neighbors.at(i);
		if (item->EndingPoint == b)
		{
			return item;
		}
	}
	return nullptr;
}

template <typename T>
std::vector<Vertex<T>*> Graph<T>::DepthFirstSearch(T start, T end)
{
	return DepthFirstSearch(Search(start), Search(end));
}

template <typename T>
 std::vector<Vertex<T>*> Graph<T>::DepthFirstSearch(Vertex<T>* start, Vertex<T>* end)
{
	for (int i = 0; i < Vertices.size(); i++)
	{
		Vertices.at(i)->IsVisited = false;
		Vertices.at(i)->TotalDistance = std::numeric_limits<double>::infinity();
		Vertices.at(i)->Founder = nullptr;
	}

	start->TotalDistance = 0;
	Heap<Vertex<T>*> Queue;
	Queue.Insert(start);

	while (Queue.Count != 0)
	{
		auto current = Queue.Pop();
		current->IsVisited = true;
		
		for (int i = 0; i < current->Neighbors.size(); i++)
		{
			auto edge = current->Neighbors.at(i);
			int tent = current->TotalDistance + edge->Distance;
			if (tent <= edge->Distance)
			{
				edge->EndingPoint->TotalDistance = tent;
				edge->EndingPoint->IsVisited = false;
				edge->EndingPoint->Founder = current;
			}

			if (!edge->EndingPoint->IsVisited && !Queue.Contains(edge->EndingPoint))
			{
				Queue.Insert(edge->EndingPoint);
			}

			std::vector<Vertex<T>*> path;
			auto curr = start;
			while (curr != nullptr)
			{
				path.push_back(curr);
				curr = curr->Founder;
			}
			
			return path;
		}
	}
}
