#include <PolyLine.h>
#include <complex>
#include <iostream> 
#include <cmath>
using namespace Line;
using namespace std;


template<typename T>
Point<T> rotate(float angle,Point<T> point, Point<T> center)
{
	Point<T> newpoint;
	newpoint.x = (point.x - center.x) * cos(angle) - (point.y - center.y) * sin(angle) + center.x;
	newpoint.y = (point.x - center.x) * sin(angle) + (point.y - center.y) * cos(angle) + center.y;
	return newpoint;
}

double angle(int n)
{
	return 2 * acos(-1.0) / n;
}

template<typename T>
PolyLine<T> polygon(int N, T radius)
{
	PolyLine<T> polygon(N + 1);
	double a = angle(N);
	polygon[0] = Point<T>(radius, 0);
	for (int i = 1; i < polygon.size(); ++i)
	{
		polygon[i] = rotate(a, polygon[i - 1], Point<float>(0.f, 0.f));

	}
	return polygon;
}

template<typename T>
PolyLine<T> trapezoid(T a, T b, T h)
{
	PolyLine<T> polygon(5);	
	polygon[0] = Point<T>(0, 0);
	polygon[1] = Point<T>(polygon[0].x + (a - b) / 2, polygon[0].y + h);
	polygon[2] = Point<T>(polygon[1].x +  b, polygon[1].y);
	polygon[3] = Point<T>(polygon[2].x + (a - b) / 2, polygon[0].y);
	polygon[4] = polygon[0];
	return polygon;
}
template<typename T>
PolyLine<T> isosceles_triangle(double angle, T length)
{
	angle = angle * acos(-1.0) / 180;
	PolyLine<T> polygon(4);
	polygon[0] = Point<T>(0, 0);
	polygon[1] = Point<T>(length * cos(angle), length * sin(angle));
	polygon[2] = Point<T>(polygon[1].x * 2, polygon[0].y);
	polygon[3] = polygon[0];
	return polygon;
}

int main()
{
	//--------------------------------------------------------------
	int N;
	float radius;
	do
	{
		cout << "Enter the number of vertices of the polygon: ";
		cin >> N;
	} while (N <= 2);
	cout << "Enter radius: ";
	cin >> radius;

	PolyLine<float> poly = polygon(N, radius);
	cout << poly;
	//--------------------------------------------------------------
	float a, b, h;
	cout << "Enter the length of the lower base of the trapezoid: ";
	cin >> a;
	cout << "Enter the length of the higher base of the trapezoid: ";
	cin >> b;
	cout << "Enter the height of the trapezoid: ";
	cin >> h;
	PolyLine<float> trap = trapezoid(a, b, h);
	cout << trap;
	//--------------------------------------------------------------
	double angle;
	float len;
	cout << "Enter the angle at the base of an isosceles triangle: ";
	cin >> angle;
	cout << "Enter the side length of an isosceles triangle: ";
	cin >> len;
	PolyLine<float> triangle = isosceles_triangle(angle, len);
	cout << triangle;
	//--------------------------------------------------------------
	PolyLine<int> letter = PolyLine<int>(7);
	letter[0] = Point<int>(0, 1);
	letter[1] = Point<int>(0, 0);
	letter[2] = Point<int>(1, 0);
	letter[3] = Point<int>(1, 1);
	letter[4] = Point<int>(1, 0);
	letter[5] = Point<int>(2, 0);
	letter[6] = Point<int>(2, 1);
	cout << letter;
	//--------------------------------------------------------------
	return 0;

}
