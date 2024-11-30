#include "Vector.h"

Vector::Vector(const int n)
{
	this->_capacity = n;
	this->_elements = nullptr;
	this->_resizeFactor = 0;
	this->_size = 0;
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