#include "Point2D.h"

void Point2D::PrintPoint(const Point2D point)
{
	point.Print();
}

void  Point2D::FunctionPrintY(const Point2D& point)
{
	std::cout << "Function print y=" << point.getY() << "\n";
}

bool Point2D::operator < (const Point2D& otherPoint) const
{
	return this -> distance() < otherPoint.distance();
}

void Point2D::Print() const
{
	std::cout << "Point coordinates (" << getX() << "," << getY() << ") distance from origin: " << distance() <<"\n"; 
}

double Point2D::distance() const
{
	double distance = sqrt(pow(static_cast<double>(getX()), 2) + pow(static_cast<double>(getY()), 2));
	return distance;
}

void  FunctionPrintX(const Point2D& point)
{
	std::cout << "Function print x=" << point.getX() << "\n";
}

bool  MaxDistanceAsc(const Point2D& p_1, const Point2D& p_2)
{
	double p1 = abs(p_1.getX() - p_1.getY());
	double p2 = abs(p_2.getX() - p_2.getY());

	if(p1 < p2) return true;
	else return false;
}



