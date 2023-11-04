#include <BrokenLine.h>

using namespace Line;


template <typename T>
Point<T>::Point()
{

}

template <typename T>
Point<T>::Point(T x, T y) : x(x), y(y)
{

}

template <typename T>
std::ostream& Line::operator<<(std::ostream& out, const Point<T>& point)
{
	out << "(" << point.x << ", " << point.y << ")" << std::endl;
	return out;
}

template<typename T>
std::ostream& Line::operator<<(std::ostream& out, const BrokenLine<T>& line)
{
	for (int i = 0; i < line.size(); ++i)
	{
		out << "(" << line[i].x << ", " << line[i].y << ")" << std::endl;
	}
	return out;
}

template <typename T>
BrokenLine<T>::BrokenLine() : _size(0), _points(nullptr)
{

}

template <typename T>
BrokenLine<T>::BrokenLine(const T x, const T y)
{
	_points = new Point(x, y);
	_size = 1;
}

template <typename T>
BrokenLine<T>::BrokenLine(const size_t size)
{
	_size = size;
	_points = new Point<T>[_size];
}

template <typename T>
BrokenLine<T>::BrokenLine(const BrokenLine& other)
{
	_size = other.size();
	_points = new Point<T>[_size];
	for (int i = 0; i < _size; ++i)
	{
		_points[i] = other[i];
	}

}
template <typename T>
BrokenLine<T>::BrokenLine(const int m1, const int m2, const size_t amount)
{

}
template <typename T>
Point<T>& BrokenLine<T>::operator[](const size_t index)
{
	return _points[index];
}
template <typename T>
const Point<T>& BrokenLine<T>::operator[](const size_t index) const
{
	return _points[index];
}

template <typename T>
size_t BrokenLine<T>::size() const
{
	return _size;
}
template <typename T>
BrokenLine<T> BrokenLine<T>::operator+(const BrokenLine<T>& other) const
{
	size_t size1 = _size;
	size_t size2 = other.size();
	BrokenLine<T> new_line = BrokenLine(size1 + size2);
	for (int i = 0; i < size1; ++i)
	{
		new_line[i] = _points[i];
	};
	for (int i = size1; i < new_line.size(); ++i)
	{
		new_line[i] = other[i - size1];
	}
	return	new_line;
}
template <typename T>
BrokenLine<T> operator+(const Point<T>& point, const BrokenLine<T>& line) 
{

}
template <typename T>
BrokenLine<T> operator+(const BrokenLine<T>& line, const Point<T>& point)
{
	BrokenLine<T> new_line = BrokenLine(line.size());
	new_line[line.size()] = point;
	return new_line;
}
template <typename T>
BrokenLine<T>& BrokenLine<T>::operator=(const BrokenLine& other) const
{

}
template <typename T>
BrokenLine<T>& BrokenLine<T>::operator+=(const BrokenLine& other)
{

}

template <typename T>
double BrokenLine<T>::Length(size_t index1, size_t index_2)
{

}