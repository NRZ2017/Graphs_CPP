#pragma once
#include <limits>
#include<string>
#include <map>
#include "Edges.h"

template <typename T>
class Vertex
{
private:

public:
	T Value;
	bool IsVisited = false;
	double TotalDistance = std::numeric_limits<double>::max();
	Vertex<T>* Founder = nullptr;
	std::vector<Edges<T>*> Neighbors;

	Vertex(T value)
	{
		this->Value = value;
	}

	int CompareTo(Vertex<T> other);
	std::string ToString();
};

template <typename T>
int Vertex<T>::CompareTo(Vertex<T> other)
{
	if (TotalDistance > other.TotalDistance)
	{
		return 1;
	}
	if (TotalDistance < other.TotalDistance)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

template <typename T>
std::string Vertex<T>::ToString()
{
	return std::to_string(Value);
}