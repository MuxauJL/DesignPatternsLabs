#include "stdafx.h"
#include "VerticalMatrixComposite.h"


VerticalMatrixComposite::VerticalMatrixComposite(bool shNulls)
{
	showNulls = shNulls;
}


VerticalMatrixComposite::~VerticalMatrixComposite()
{
}

int VerticalMatrixComposite::getRowsCount()
{
	int sum = 0;
	for (auto matr : list)
		sum += matr->getRowsCount();
	return sum;
}

int VerticalMatrixComposite::getColsCount()
{
	if (list.size() == 0)
		return 0;
	int max = list[0]->getColsCount();
	for (auto matr : list)
		if (max < matr->getColsCount())
			max = matr->getColsCount();
	return max;
}

double VerticalMatrixComposite::get(int row, int col)
{
	int sumRows = 0;
	for (int i = 0; i < list.size(); ++i) {
		if (row < sumRows + list[i]->getRowsCount()) {
			if (col < list[i]->getColsCount())
				return list[i]->get(row - sumRows, col);
			else
				return 0;
		}
		else {
			sumRows += list[i]->getRowsCount();
		}
	}
	return list[0]->get(row, col);
}

void VerticalMatrixComposite::set(int row, int col, double value)
{
	int sumRows = 0;
	bool setted = false;
	for (int i = 0; i < list.size(); ++i) {
		if (row < sumRows + list[i]->getRowsCount()) {
			if (col < list[i]->getColsCount()) {
				list[i]->set(row-sumRows, col, value);
				setted = true;
			}
		}
		else {
			sumRows += list[i]->getRowsCount();
		}
	}
	if (!setted)
		list[0]->set(row, col, value);
}

void VerticalMatrixComposite::add(std::shared_ptr<AMyMatrix> matrix)
{
	list.push_back(matrix);
}

void VerticalMatrixComposite::iterate(std::function<void(int, int, double)>it)
{
	int offsetRows = 0;
	for (auto matr : list) {
		for (int i = 0; i < matr->getRowsCount(); ++i)
			for (int j = 0; j < matr->getColsCount(); ++j)
				matr->getIterator(i, j)(i + offsetRows, j, matr->get(i, j));
		if (showNulls) {
			for (int r = 0; r < matr->getRowsCount(); ++r)
				for (int c = matr->getColsCount(); c < getColsCount(); ++c)
					drawItem(r + offsetRows, c, 0);
		}
		offsetRows += matr->getRowsCount();
	}
}

std::function<void(int, int, double)> VerticalMatrixComposite::getIterator(int i, int j)
{
	int sum = 0;
	for (auto matr : list) {
		sum += matr->getRowsCount();
		if (sum > i)
			if (j < matr->getColsCount())
				return matr->getIterator(i, j);
			else
				return [this](int i, int j, double value) {drawItem(i, j, value); };
	}
	return list[0]->getIterator(i, j);
}
