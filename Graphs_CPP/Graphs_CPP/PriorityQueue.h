#pragma once

#include <exception>

template <typename T>
class Heap
{
private:
	int size;
	T* HTree = new T[10];
	const int& count = Count;
	int Left(int index);
	int Right(int index);
	int Parent(int index);
	void ChangeSize(int size);
	void Swap(int i, int k);
public:
	int Count = 0;
	void Insert(T value);
	void HeapifyUp(int index);
	void HeapifyDown(int index);
	T Pop();
	bool Contains(T value);
	Heap()
	{
		size = 10;
	}
};

template <typename T>
int Heap<T>::Left(int index)
{
	return(2 * index) + 1;
}

template <typename T>
int Heap<T>::Right(int index)
{
	return(2 * index) + 2;
}

template <typename T>
int Heap<T>::Parent(int index)
{
	return(index - 1) / 2;
}

template <typename T>
void Heap<T>::Insert(T value)
{
	if (Count == size)
	{
		ChangeSize(size * 2);
	}

	HTree[Count] = value;
	HeapifyUp(Count);
	Count++;
}

template <typename T>
void Heap<T>::HeapifyUp(int index)
{
	if (index == 0)
	{
		return;
	}

	int parentIndex = Parent(index);
	if (HTree[index] < HTree[parentIndex])
	{
		Swap(index, parentIndex);
		HeapifyUp(parentIndex);
	}
}

template <typename T>
void Heap<T>::HeapifyDown(int index)
{
	int left = Left(index);
	int right = Right(index);

	int smaller = index;
	if (left < Count && right < Count)
	{
		smaller = left;
		if (HTree[right] < HTree[left])
		{
			smaller = right;
		}
	}

	else if (left < Count)
	{
		smaller = left;
	}
	else if (right < Count)
	{
		smaller = right;
	}
	if (smaller != index && HTree[smaller] < HTree[index])
	{
		Swap(smaller, index);
		HeapifyDown(smaller);
	}
}

template <typename T>
T Heap<T>::Pop()
{
	if (Count == 0)
	{
		throw std::exception{};
	}

	if (Count == size / 4)
	{
		ChangeSize(size / 2);
	}

	T ret = HTree[0];
	HTree[0] = HTree[Count - 1];
	Count--;
	HeapifyDown(0);
	return ret;
}

template <typename T>
void Heap<T>::ChangeSize(int size)
{
	T* ts = new T[size];
	for (int i = 0; i < Count; i++)
	{
		ts[i] = HTree[i];
	}
	HTree = ts;
}

template <typename T>
void Heap<T>::Swap(int i, int k)
{
	T temp = HTree[i];
	HTree[i] = HTree[k];
	HTree[k] = temp;
}

template <typename T>
bool Heap<T>::Contains(T value)
{
	for (int i = 0; i < size; i++)
	{
		if (value = HTree[i])
		{
			return true;
		}
	}
	return false;
}