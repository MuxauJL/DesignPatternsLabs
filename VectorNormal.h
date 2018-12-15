#pragma once
#include "IVector.h"
#include <vector>

class VectorNormal :
	public IVector
{
public:
	VectorNormal(int size);
	~VectorNormal();
	virtual int getSize();
	virtual double get(int pos);
	virtual void set(int pos, double value);
	virtual void iterate(std::function<void(int)>iterator);
private:
	std::vector<double> values;
};

