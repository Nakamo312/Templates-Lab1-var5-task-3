#pragma once
#include <iostream>

namespace Line
{
	template<typename T>
	struct Point
	{
		T x, y;	
		Point();
		Point(T x, T y);		
	};

	template<typename T>
	class BrokenLine
	{
	private:

		
		Point<T>* _points;
		size_t _size;
	public:
		BrokenLine();
		BrokenLine(const T x, const T y);
		BrokenLine(const size_t size);
		BrokenLine(const BrokenLine& other);
		BrokenLine(const int m1, const int m2, const size_t amount);

		Point<T>& operator[](const size_t index);
		const Point<T>& operator[](const size_t index) const;
		size_t size() const;

		BrokenLine operator+(const BrokenLine& other) const;
		friend BrokenLine<T> operator+(const Point<T>& point, const BrokenLine<T>& line);
		friend BrokenLine<T> operator+(const BrokenLine<T>& line, const Point<T>& point);
		BrokenLine& operator=(const BrokenLine& other) const;
		BrokenLine& operator+=(const BrokenLine& other);		
		double Length(size_t index1, size_t index_2);
	};
	template<typename T>
	std::ostream& operator<<(std::ostream& out, const Point<T>& point);
	template<typename T>
	std::ostream& operator<<(std::ostream& out, const BrokenLine<T>& line);
}