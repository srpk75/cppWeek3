class Vector
{
public:
	Vector(const int n); //const
	~Vector();	   //deconst

	int size() const;
	int capacity() const;
	int resizeFactor() const;
	bool empty() const;
	void push_back(const int& val);
	int pop_back();
	void reserve(const int n);

private:
	int* _elements;
	int _capacity;
	int _resizeFactor;
	int _size;
};