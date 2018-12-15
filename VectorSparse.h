#pragma once
#include "IVector.h"
#include <map>

class VectorSparse :
	public IVector
{
public:
	VectorSparse(int size);
	~VectorSparse();
	virtual int getSize();
	virtual double get(int pos);
	virtual void set(int pos, double value);
	virtual void iterate(std::function<void(int)>iterator);
private:
	int length;
	std::map<int, double> values;
};

