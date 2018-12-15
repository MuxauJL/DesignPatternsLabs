#pragma once
#include "AMyMatrix.h"
#include "VectorNormal.h"

class MatrixNormal :
	public AMyMatrix
{
public:
	MatrixNormal(int rows, int cols, IDrawer* drawer = nullptr)
		:AMyMatrix(rows, cols, &VectorNormalFactory(), drawer),
		iterator([this](int i, int j, double value) {
		this->drawItem(i, j, value);
	}) {};
	virtual std::function<void(int, int, double)> getIterator(int i = 0, int j = 0) { return iterator; };
private:
	std::function<void(int, int, double)>iterator;
};

