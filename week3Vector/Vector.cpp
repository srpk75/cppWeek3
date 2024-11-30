#include "Vector.h"

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
		delete[] oldElements;
	}
	this->_elements[this->_size] = val;
	this->_size++;
}

int Vector::pop_back()
{
	this->_size--;
	return this->_elements[this->_size];
}

void reserve(const int n)
{

}