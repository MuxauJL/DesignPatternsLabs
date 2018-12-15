#pragma once
#include "AMyMatrix.h"
#include "VectorSparse.h"

class MatrixSparse :
	public AMyMatrix
{
public:
	MatrixSparse(int rows, int cols, IDrawer* drawer = nullptr)
		:AMyMatrix(rows, cols, &VectorSparseFactory(), drawer), 
		iterator([this](int i, int j, double value) {
		if (abs(value) > 0.000001)this->drawItem(i, j, value);
	}) {};
	virtual std::function<void(int, int, double)> getIterator(int i = 0, int j = 0) { return iterator; };
private:
	std::function<void(int, int, double)>iterator;
};

