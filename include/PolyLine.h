#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdexcept>
namespace Line
{
	template<typename T>
	struct Point
	{
		T x, y;	
		Point() { }
		Point(T x, T y) : x(x), y(y){ }
	};

	template<typename T>
	class PolyLine
	{
	private:		
		Point<T>* _points;
		size_t _size;
	public:
		PolyLine() : _size(0), _points(nullptr){ }
		PolyLine(const T x, const T y)
		{
			_points = new Point(x, y);
			_size = 1;
		}

		PolyLine(const size_t size)
		{
			_size = size;
			_points = new Point<T>[_size];
		}

		PolyLine(const PolyLine& other)
		{
			_size = other.size();
			_points = new Point<T>[_size];
			for (int i = 0; i < _size; ++i)
			{
				_points[i] = other[i];
			}

		}
		PolyLine(const T m1, const T m2, const size_t amount)
		{
			srand(time(NULL));			
			_size = amount;
			_points = new Point<T>[_size];
			if (typeid(T()) == typeid(int()))
			{
				for (int i = 0; i < _size; ++i)
				{
					_points[i] = Point(T(int(m1) + rand() % (int(m2) - int(m1) + 1)), T(int(m1) + rand() % (int(m2) - int(m1) + 1)));
				}
			}
			else
			{
				for (int i = 0; i < _size; ++i)
				{
					size_t precision = 2;
					double x = rand() % (int)pow(10, precision);
					double y = rand() % (int)pow(10, precision);
					_points[i] = Point(T(m1 + (x / pow(10, precision)) * (m2 - m1)), T(m1 + (y / pow(10, precision)) * (m2 - m1)));
				}
			}
		}

		Point<T>& operator[](const size_t index)
		{
			if (index >= size() || index < 0)
			{
				throw std::runtime_error("PolyLine::operator[]  invalid index");
			}
			return _points[index];
		}

		const Point<T>& operator[](const size_t index) const
		{
			if (index >= size() || index < 0)
			{
				throw std::runtime_error("PolyLine::operator[]  invalid index");
			}
			return _points[index];
		}

		size_t size() const
		{
			return _size;
		}

		
		PolyLine<T> operator+(const PolyLine<T>& other) const
		{
			size_t size1 = _size;
			size_t size2 = other.size();
			PolyLine<T> new_line = PolyLine(size1 + size2);
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
		friend PolyLine<T> operator+(const Point<T>& point, const PolyLine<T>& line)
		{
			PolyLine<T> new_line = PolyLine(line.size() + 1);
			new_line[0] = point;
			for (int i = 1; i < new_line.size(); ++i)
			{
				new_line[i] = line[i-1];
			};
			return new_line;
		}
		friend PolyLine<T> operator+(const PolyLine<T>& line, const Point<T>& point)
		{			
			PolyLine<T> new_line = PolyLine(line.size() + 1);
			for (int i = 0; i < line.size(); ++i)
			{
				new_line[i] = line[i];
			};
			new_line[new_line.size() - 1] = point;
			return new_line;
		}
		PolyLine<T>& operator=(const PolyLine<T>& other)
		{
			PolyLine<T> copy(other);
			_size = other.size();
			std::swap(this->_points, copy._points);			
			return *this;
		}
		
		PolyLine<T>& operator+=(const PolyLine<T>& other)
		{
			PolyLine<T> copy(*this);
			PolyLine<T> newline = copy + other;
			
			*this = newline;
			return *this;
		}
		PolyLine<T>& operator+=(const Point<T>& point)
		{
			PolyLine<T> newline = *this + point;
			*this = newline;
			return *this;
		}
		double length(size_t index1, size_t index2)
		{
			if (index1 >= size() || index1 < 0)
			{
				throw std::runtime_error("PolyLine::operator[]  invalid index");
			}
			if (index2 >= size() || index2 < 0)
			{
				throw std::runtime_error("PolyLine::operator[]  invalid index");
			}
			double len = 0;
			for (int i = index1; i <= index2-1; ++i)
			{
				double dx = _points[index1].x - _points[index1 + 1].x;
				double dy = _points[index1].y - _points[index1 + 1].y;
				dx = pow(dx, 2);
				dy = pow(dy, 2);
				len += sqrt(dx + dy);
			}
			return len;
		}
	};
	template<typename T>
	std::ostream& operator<<(std::ostream& out, const Point<T>& point)
	{
		out << "(" << point.x << ", " << point.y << ")" << std::endl;
		return out;
	}

	template<typename T>
	std::ostream& operator<<(std::ostream& out, const PolyLine<T>& line)
	{
		for (int i = 0; i < line.size(); ++i)
		{
			out << "(" << line[i].x << ", " << line[i].y << ")" << std::endl;
		}
		return out;
	}
}