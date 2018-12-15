#include "stdafx.h"
#include "AMyMatrix.h"

AMyMatrix::AMyMatrix(int rows, int cols, IVectorFactory* vectorFactory, IDrawer* drawer) {
	data = std::vector<IVector*>(rows);
	for (int i = 0; i < rows; ++i)
		data[i] = vectorFactory->createVector(cols);
	d = drawer;
}

AMyMatrix::~AMyMatrix() {
	for (int i = 0; i < getRowsCount(); ++i)
		delete data[i];
}

int AMyMatrix::getRowsCount() {
	return data.size();
}

int AMyMatrix::getColsCount() {
	return data[0]->getSize();
}

double AMyMatrix::get(int row, int col) {
	return data[row]->get(col);
}

void AMyMatrix::set(int row, int col, double value) {
	data[row]->set(col, value);
}

void AMyMatrix::iterate(std::function<void(int, int, double)>iterator)
{
	for (int i = 0; i < getRowsCount(); ++i)
		data[i]->iterate([this, i, iterator](int j) {iterator(i, j, get(i, j)); });
}

void AMyMatrix::drawBorder(int rowsCount, int colsCount) {
	d->drawBorder(rowsCount, colsCount);
}

void AMyMatrix::drawItem(int i, int j, double value) {
	d->drawItem(i, j, value);
}

void AMyMatrix::draw()
{
	drawBorder(getRowsCount(), getColsCount());
	iterate(getIterator());
}
