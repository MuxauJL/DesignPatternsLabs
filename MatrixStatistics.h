#pragma once
#include "IMatrix.h"
class MatrixStatistics
{
public:
	MatrixStatistics(IMatrix*);
	~MatrixStatistics();
	double sum();
	double average();
	double maximum();
	int  countOfNonZero();
private:
	IMatrix *matrix;
};

