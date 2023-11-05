#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
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
		PolyLine(const int m1, const int m2, const size_t amount)
		{
			_size = amount;
			_points = new Point<T>[_size];
			for (int i = 0; i < _size; ++i)
			{
				srand(time(NULL));
				_points[i] = m1 + rand() % (m2 - m1 + 1);
			}
		}

		Point<T>& operator[](const size_t index)
		{
			return _points[index];
		}

		const Point<T>& operator[](const size_t index) const
		{
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
			PolyLine<T> new_line = PolyLine(line.size() +1);
			for (int i = 0; i < line.size(); ++i)
			{
				new_line[i] = line[i];
			};
			new_line[new_line.size()] = point;
			return new_line;
		}
		friend PolyLine<T> operator+(const PolyLine<T>& line, const Point<T>& point)
		{
			PolyLine<T> new_line = PolyLine(line.size() + 1);
			new_line[0] = point;
			for (int i = 1; i < line.size() - 1; ++i)
			{
				new_line[i] = line[i];
			};
			return new_line;
		}
		PolyLine<T>& operator=(const PolyLine<T>& other) const
		{
			return PolyLine(other);
		}
		PolyLine<T>& operator+=(const PolyLine<T>& other)
		{
			PolyLine<T> newline = this + other;
			this = newline;
			return *this;
		}
		PolyLine<T>& operator+=(const Point<T>& point)
		{
			PolyLine<T> newline = this + point;
			this = newline;
			return *this;
		}
		double length(size_t index1, size_t index2)
		{
			double len = 0;
			for (int i = index1; i <= index2; ++i)
			{
				len += pow((pow(_points[index1], 2) + pow(_points[index1], 2)), 1 / 2);
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