#pragma once

#include <iostream>
#include "Figures.h"

class Drawable
{
public:
	virtual void draw() const = 0;
	virtual double length() const = 0;
};

inline void draw(Drawable *d)
{
	d->draw();
}

class Transformable
{
public:
	virtual void shift(const double x_shift, const double y_shift) = 0;
};


class ClosedShape
{
public:

	virtual double area() const = 0;
};
