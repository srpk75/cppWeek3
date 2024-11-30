class Vector
{
public:
	Vector(int n); //const
	~Vector();	   //deconst

	int size() const;
	int capacity() const;
	int resizeFactor() const;
	bool empty() const;

private:
	int* _elements;
	int _capacity;
	int _resizeFactor;
};