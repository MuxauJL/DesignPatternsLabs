#pragma once
//#include "IDrawable.h"
//#include "IIterable.h"

class IMatrix 
	//:public IDrawable, public IIterable
{
public:
	virtual ~IMatrix() {};
	virtual int getRowsCount() = 0;
	virtual int getColsCount() = 0;
	virtual double get(int row, int col) = 0;
	virtual void set(int row, int col, double value) = 0;
};