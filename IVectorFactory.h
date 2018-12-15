#pragma once
#include "IVector.h"
#include "VectorNormal.h"
#include "VectorSparse.h"

class IVectorFactory
{
public:
	virtual IVector* createVector(int size) = 0;
};

class VectorNormalFactory:
	public IVectorFactory
{
public:
	IVector* createVector(int size) {
		return new VectorNormal(size);
	}
};

class VectorSparseFactory :
	public IVectorFactory
{
public:
	IVector* createVector(int size) {
		return new VectorSparse(size);
	}
};