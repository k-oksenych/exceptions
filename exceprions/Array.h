#pragma once

#include "exceptions.h"

template <typename T>
class Array
{
public:
	Array();
	Array(const Array& source);
	Array(Array&& source);
	~Array();

	Array& operator=(const Array& right);
	Array& operator=(Array&& right);
	T& operator[](const unsigned int index);

	void Add(const T item);
	int BinarySearch(const T item);
	int BinarySearch(const T item, const unsigned int index, const unsigned int count);
	int IndexOf(const T item);
	int IndexOf(const T item, const unsigned int index);
	int IndexOf(const T item, const unsigned int index, const unsigned int count);
	void RemoveAt(const unsigned int index);

private:
	int elements;
	int length;
	T* array;
};

template <typename T>
Array<T>::Array() :
	elements(0),
	length(30),
	array(new T[length])
{
}

template <typename T>
Array<T>::Array(const Array& source) :
	Array(source.length)
{
	for (int index = 0; index < source.length; ++index)
	{
		array[index] = source.array[index];
	}
	this->elements = source.elements;
}

template <typename T>
Array<T>::Array(Array&& source)
{
	array = source;
	this->length = source.length;
	this->elements = source.elements;
	source = nullptr;
}

template <typename T>
Array<T>::~Array()
{
	delete[] array;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& right)
{
	Array<T>* array = new T[right.length];
	array->length = right.length;
	array->elements = right.elements;

	for (int index = 0; index < length; ++index)
	{
		array[index] = right.array[index];
	}

	return *this;
}

template <typename T>
Array<T>& Array<T>::operator=(Array&& right)
{
	Array<T>* array = right;
	this->length = right.length;
	this->elements = right.elements;
	right = nullptr;

	return *this;
}

template <typename T>
T& Array<T>::operator[](const unsigned int index)
{
	if (index < 0 || index >= elements)
	{
		throw ArgumentOutOfRangeException();
	}
	else
	{
		return array[index];
	}
}

template <typename T>
void Array<T>::Add(const T item)
{
	if (elements < length)
	{
		for (int i = 0; i < elements; ++i)
		{
			if (array[i] == item)
			{
				throw ElementExistsException();
			}
		}

		array[elements] = item;
		++elements;
	}
}

template <typename T>
int Array<T>::BinarySearch(const T item)
{
	int index = -1;

	int low = 0;
	int high = elements - 1;
	int middle = 0;

	while (low <= high)
	{
		middle = (low + high) / 2;

		if (item == array[middle])
		{
			index = middle;
			break;
		}
		else if (item > array[middle])
		{
			low = middle + 1;
		}
		else
		{
			high = middle - 1;
		}
	}

	return index;
}

template <typename T>
int Array<T>::BinarySearch(const T item, const unsigned int index, const unsigned int count)
{
	int keyIndex = -1;

	if (index < 0 || count < 0)
	{
		throw ArgumentOutOfRangeException();
	}
	else if (index > elements - 1 || count == 0 || count > elements - index)
	{
		throw ArgumentException();
	}
	else
	{
		int low = index;
		int high = index + count;
		int middle = 0;

		while (low <= high)
		{
			middle = (low + high) / 2;

			if (item == array[middle])
			{
				keyIndex = middle;
				break;
			}
			else if (item > array[middle])
			{
				low = middle + 1;
			}
			else
			{
				high = middle - 1;
			}
		}
	}

	return keyIndex;
}

template <typename T>
int Array<T>::IndexOf(const T item)
{
	int index = -1;

	for (int i = 0; i < elements; ++i)
	{
		if (array[i] == item)
		{
			index = i;
			break;
		}
	}

	return index;
}

template <typename T>
int Array<T>::IndexOf(const T item, const unsigned int index)
{
	int keyIndex = -1;

	if (index < 0)
	{
		throw ArgumentOutOfRangeException();
	}
	else if (index > elements - 1)
	{
		throw ArgumentException();
	}
	else
	{
		for (int i = index; i < elements; ++i)
		{
			if (array[i] == item)
			{
				keyIndex = i;
				break;
			}
		}
	}

	return keyIndex;
}

template <typename T>
int Array<T>::IndexOf(const T item, const unsigned int index, const unsigned int count)
{
	int keyIndex = -1;

	if (index < 0 || count < 0)
	{
		throw ArgumentOutOfRangeException();
	}
	else if (index > elements - 1 || count == 0 || count > elements - index)
	{
		throw ArgumentException();
	}
	else
	{
		for (int i = index; i < index + count; ++i)
		{
			if (array[i] == item)
			{
				keyIndex = i;
				break;
			}
		}
	}

	return keyIndex;
}

template <typename T>
void Array<T>::RemoveAt(const unsigned int index)
{
	if (index < 0 || index > elements - 1)
	{
		throw ArgumentOutOfRangeException();
	}
	else
	{
		--elements;
		for (int i = index; i < elements; ++i)
		{
			array[i] = array[i + 1];
		}
	}
}