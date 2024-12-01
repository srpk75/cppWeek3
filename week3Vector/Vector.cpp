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
	int* old_elements = nullptr;
	if (this->_size == this->_capacity)
	{
		old_elements = this->_elements;
		this->_elements = new int[this->_capacity + this->_resizeFactor];
		this->_capacity += this->_resizeFactor;
		Vector::deepCopy(old_elements, this->_size, this->_elements);
		delete[] old_elements;
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
	int* old_elements = nullptr;
	int mulFactor = this->_resizeFactor;
	while (mulFactor < n)
	{
		mulFactor += this->_resizeFactor;
	}
	this->_capacity = mulFactor;
	old_elements = this->_elements;
	this->_elements = new int[this->_capacity + this->_resizeFactor];
	Vector::deepCopy(old_elements, this->_size, this->_elements);
	delete[] old_elements;
}

void Vector::resize(const int n)
{
	int* old_elements = nullptr;
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
		old_elements = this->_elements;
		this->_elements = new int[this->_capacity + this->_resizeFactor];
		Vector::deepCopy(old_elements, this->_size, this->_elements);
		delete[] old_elements;

		//init values
		for (i = this->_size; i < this->_capacity-1; i++)
		{
			this->_elements[i] = 0;
		}

		//update size
		this->_size = n;
	}
	if (n < this->_capacity)
	{
		old_elements = this->_elements;
		this->_elements = new int[n];
		Vector::deepCopy(old_elements, n, this->_elements);
		delete[] old_elements;
	}
}

void Vector::assign(const int val)
{
	int i;
	for (i = 0; i < this->_size; i++)
	{
		this->_elements[i] = val;
	}
}

void Vector::resize(const int n, const int& val)
{
	int* old_elements = nullptr;
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
		old_elements = this->_elements;
		this->_elements = new int[this->_capacity + this->_resizeFactor];
		Vector::deepCopy(old_elements, this->_size, this->_elements);
		delete[] old_elements;

		//init values
		for (i = this->_size; i < this->_capacity - 1; i++)
		{
			this->_elements[i] = val; //only difference omg
		}

		//update size
		this->_size = n;
	}
	if (n < this->_capacity)
	{
		old_elements = this->_elements;
		this->_elements = new int[n];
		Vector::deepCopy(old_elements, n, this->_elements);
		delete[] old_elements;
	}
}

Vector& Vector::operator=(const Vector& src)
{
	int i;
	this->_capacity = src.capacity();
	this->_size = src.size();
	this->_resizeFactor = src.resizeFactor();
	this->_elements = new int[src.capacity()];
	for (i = 0; i < src.size(); i++)
	{
		this->_elements[i] = src._elements[i];
	}
	return *this;
}

int& Vector::operator[](int n) const
{
	if (n > this->_size - 1 || n < 0)
	{
		std::cerr << "what are you doing?? this is NOT your memory" << std::endl;
		return this->_elements[0];
	}
	return this->_elements[n];
}
