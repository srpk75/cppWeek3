class Vector
{
public:
	Vector(const int n); //const
	~Vector();	   //deconst

	int size() const;
	int capacity() const;
	int resizeFactor() const;
	bool empty() const;

private:
	int* _elements;
	int _capacity;
	int _resizeFactor;
	int _size;
};