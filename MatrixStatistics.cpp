#include "stdafx.h"
#include "MatrixStatistics.h"

MatrixStatistics::MatrixStatistics(IMatrix* mat)
{
	matrix = mat;
}

MatrixStatistics::~MatrixStatistics()
{
}

double MatrixStatistics::sum() {
	double s = 0;
	for (int i = 0; i < matrix->getRowsCount(); ++i)
		for (int j = 0; j < matrix->getColsCount(); ++j)
			s += matrix->get(i, j);
	return s;
}

double MatrixStatistics::average() {
	return sum() / (matrix->getRowsCount()*matrix->getColsCount());
}

double MatrixStatistics::maximum() {
	double max = matrix->get(0, 0);
	double tmp;
	for (int i = 0; i < matrix->getRowsCount(); ++i)
		for (int j = 0; j < matrix->getColsCount(); ++j) {
			tmp = matrix->get(i, j);
			if (max < tmp)
				max = tmp;
		}
	return max;
}

int  MatrixStatistics::countOfNonZero() {
	int count = 0;
	for (int i = 0; i < matrix->getRowsCount(); ++i)
		for (int j = 0; j < matrix->getColsCount(); ++j)
			if (matrix->get(i, j) != 0)
				++count;
	return count;
}
