#include "Vector.h"
#include <iostream>

Vector::Vector(const int n)
{
	this->_capacity = n;
	this->_elements = new int[n];
	this->_resizeFactor = n;
	this->_size = 0;
}

Vector::~Vector()
{
	delete[] this->_elements;
}

void Vector::deepCopy(const int* src, const int size, int* dst)
{
	int i;
	for (i = 0; i < size; i++)
	{
		dst[i] = src[i];
	}
}

int Vector::capacity() const
{
	return this->_capacity;
}

int Vector::size() const
{
	return this->_size;
}

int Vector::resizeFactor() const
{
	return this->_resizeFactor;
}

bool Vector::empty() const
{
	if (this->_size == 0)
	{
		return true;
	}
	return false;
}

void Vector::push_back(const int& val)
{
	int* oldElements = nullptr;
	if (this->_size == this->_capacity)
	{
		oldElements = this->_elements;
		this->_elements = new int[this->_capacity + this->_resizeFactor];
		this->_capacity += this->_resizeFactor;
		Vector::deepCopy(oldElements, this->_size, this->_elements);
		delete[] oldElements;
	}
	this->_elements[this->_size] = val;
	this->_size++;
}

int Vector::pop_back()
{
	if (this->empty())
	{
		std::cout << "error: pop from empty vector" << std::endl;
		return -9999;
	}
	this->_size--;
	return this->_elements[this->_size];
}

void Vector::reserve(const int n)
{
	if (n < this->_capacity)
	{
		return;
	}
	int* oldElements = nullptr;
	int mulFactor = this->_resizeFactor;
	while (mulFactor < n)
	{
		mulFactor += this->_resizeFactor;
	}
	this->_capacity = mulFactor;
	oldElements = this->_elements;
	this->_elements = new int[this->_capacity + this->_resizeFactor];
	Vector::deepCopy(oldElements, this->_size, this->_elements);
	delete[] oldElements;
}

void Vector::resize(const int n)
{
	int* oldElements = nullptr;
	int mulFactor = this->_resizeFactor;
	int i;

	if (n > this->_capacity)
	{
		//scale capacity and size
		while (mulFactor < n)
		{
			mulFactor += this->_resizeFactor;
		}
		this->_capacity = mulFactor;
		oldElements = this->_elements;
		this->_elements = new int[this->_capacity + this->_resizeFactor];
		Vector::deepCopy(oldElements, this->_size, this->_elements);
		delete[] oldElements;

		//init values
		for (i = this->_size; i < this->_capacity-1; i++)
		{
			this->_elements[i] = 0;
		}

		//update size
		this->_size = this->_capacity;
	}
	if (n < this->_capacity)
	{
		oldElements = this->_elements;
		this->_elements = new int[n];
		Vector::deepCopy(oldElements, n, this->_elements);
		delete[] oldElements;
	}
}

void Vector::assign(const int val)
{

}

void Vector::resize(const int n, const int& val)
{
	int* oldElements = nullptr;
	int mulFactor = this->_resizeFactor;
	int i;

	if (n > this->_capacity)
	{
		//scale capacity and size
		while (mulFactor < n)
		{
			mulFactor += this->_resizeFactor;
		}
		this->_capacity = mulFactor;
		oldElements = this->_elements;
		this->_elements = new int[this->_capacity + this->_resizeFactor];
		Vector::deepCopy(oldElements, this->_size, this->_elements);
		delete[] oldElements;

		//init values
		for (i = this->_size; i < this->_capacity - 1; i++)
		{
			this->_elements[i] = val; //only difference omg
		}

		//update size
		this->_size = this->_capacity;
	}
	if (n < this->_capacity)
	{
		oldElements = this->_elements;
		this->_elements = new int[n];
		Vector::deepCopy(oldElements, n, this->_elements);
		delete[] oldElements;
	}
}