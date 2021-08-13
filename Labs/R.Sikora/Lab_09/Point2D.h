#pragma once

#include <iostream>
#include <cmath>


class Point2D
{
public:
	Point2D(int x = 0, int y = 0): m_x(x), m_y(y) {}

	// wypisuje na ekran informacje o obiekcie point
	static void PrintPoint(const Point2D point);

	//wypisuje na ekran tylko współrzędną Y punktu
	static void FunctionPrintY(const Point2D& point);


	bool operator < (const Point2D& otherPoint) const;

	void Print() const;

	inline int getX() const { return m_x; }
	inline int getY() const { return m_y; }

	double distance() const;

private:
	int m_x;
	int m_y;
};

struct OrderAscX 
{
	bool operator ()  (const Point2D &p_1, const Point2D &p_2) const
	{
		return p_1.getX() > p_2.getX();
	}
};

struct OrderDescY 
{
	bool operator () (const Point2D &p_1, const Point2D &p_2) const
	{
		return p_1.getY() > p_2.getY();
	}
};


//wypisuje na ekran wspolrzędną X punktu
void FunctionPrintX(const Point2D& point);

bool MaxDistanceAsc(const Point2D &p_1, const Point2D &p_2);


