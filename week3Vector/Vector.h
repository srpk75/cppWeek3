class Vector
{
public:

	Vector(int n); //const
	~Vector();	   //deconst
	Vector& operator=(const Vector& src);
	int& operator[](int n) const;

	void deepCopy(const int* src, int size, int* dst);

	//pt2
	int size() const;
	int capacity() const;
	int resizeFactor() const;
	bool empty() const;
	void push_back(const int& val);
	int pop_back();
	void reserve(const int n);

	//pt3
	void resize(const int n);
	void assign(const int val);
	void resize(const int n, const int& val);

private:
	int* _elements;
	int _capacity;
	int _resizeFactor;
	int _size;
};