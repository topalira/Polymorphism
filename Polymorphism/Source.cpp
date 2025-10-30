#include<iostream>
#include<ctime>
using namespace std;
class Point
{
	int x;
	int y;
public:
	Point(int a, int b) :x(a), y(b) {}
	void Init(int a, int b);
	void InitRandom();
	void Output();
	int GetX() { return x; }
	int GetY() { return y; }
};
template<class T1, class T2>
class Numbers
{
	T1 a;
	T2 b;
public:
	Numbers();
	Numbers(T1 _a, T2 _b);
	void Init(T1 _a, T2 _b);
	void Output();
	void SetA(T1 _a) { a = _a; }
	void SetB(T2 _b) { b = _b; }
	T1 GetA() { return a; }
	T2 GetB() { return b; }
};

ostream& operator<<(ostream& os, Point& obj)
{
	os << obj.GetX() << "\t" << obj.GetY() << endl;
	return os;
}

template<class T1, class T2>
Numbers<T1, T2>::Numbers()
{
	a = T1();
	b = T2();
}
template<class T1, class T2>
Numbers<T1, T2>::Numbers(T1 _a, T2 _b)
{
	a = _a;
	b = _b;
}
template<class T1, class T2>
void Numbers<T1, T2>::Init(T1 _a, T2 _b)
{
	a = _a;
	b = _b;
}

template<class T1, class T2>
void Numbers<T1, T2>::Output()
{
	cout << a << "\t" << b << endl;
}

void Point::Init(int _a, int _b)
{
	x = _a;
	y = _b;
}

void Point::InitRandom()
{
	x = rand() % 100;
	y = rand() % 100;
}

void Point::Output()
{
	cout << x << "\t" << y << endl;
}

int main()
{
	srand(time(0));

	Numbers<int, double> obj1(5, 2.5);
	obj1.Output();

	Numbers<Point, Point> obj2(Point(1, 2), Point(3, 4));
	obj2.Output();

	Point obj3(10, 2);
	obj3.InitRandom();
	obj3.Output();
}