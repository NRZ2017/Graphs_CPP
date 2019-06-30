#pragma once

template <typename T>
class Vertex;

template <typename T>
class Edges
{
public:

	Vertex<T>* StartingPoint;
	Vertex<T>* EndingPoint;
	float Distance;

	Edges(Vertex<T>* startingPoint, Vertex<T>* endingPoint, float distance)
	{
		StartingPoint = startingPoint;
		EndingPoint = endingPoint;
		Distance = distance;
	}

private:

};