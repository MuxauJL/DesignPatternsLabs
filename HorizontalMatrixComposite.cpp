#include "stdafx.h"
#include "HorizontalMatrixComposite.h"

HorizontalMatrixComposite::HorizontalMatrixComposite(bool shNulls)
{
	showNulls = shNulls;
}


HorizontalMatrixComposite::~HorizontalMatrixComposite()
{
}

int HorizontalMatrixComposite::getRowsCount()
{
	if (list.size() == 0)
		return 0;
	int max = list[0]->getRowsCount();
	for (auto matr : list) 
		if (max < matr->getRowsCount())
			max = matr->getRowsCount();
	return max;
}

int HorizontalMatrixComposite::getColsCount()
{
	int sum = 0;
	for (auto matr : list)
		sum += matr->getColsCount();
	return sum;
}

double HorizontalMatrixComposite::get(int row, int col)
{
	int sumCols = 0;
	for (int i = 0; i < list.size(); ++i) {
		if (col < sumCols + list[i]->getColsCount()) {
			if (row < list[i]->getRowsCount())
				return list[i]->get(row, col - sumCols);
			else
				return 0;
		}
		else {
			sumCols += list[i]->getColsCount();
		}
	}
	return list[0]->get(row, col);
}

void HorizontalMatrixComposite::set(int row, int col, double value)
{
	int sumCols = 0;
	bool setted = false;
	for (int i = 0; i < list.size(); ++i) {
		if (col < sumCols + list[i]->getColsCount()) {
			if (row < list[i]->getRowsCount()) {
				list[i]->set(row, col - sumCols, value);
				setted = true;
			}
		}
		else {
			sumCols += list[i]->getColsCount();
		}
	}
	if (!setted)
		list[0]->set(row, col, value);
}

void HorizontalMatrixComposite::add(std::shared_ptr<AMyMatrix> matrix)
{
	list.push_back(matrix);
}

void HorizontalMatrixComposite::iterate(std::function<void(int, int, double)>it)
{
	int offsetCols = 0;
	for (auto matr : list) {
		for (int i = 0; i < matr->getRowsCount(); ++i)
			for (int j = 0; j < matr->getColsCount(); ++j)
				matr->getIterator(i, j)(i, j + offsetCols, matr->get(i, j));
		if (showNulls) {
			for (int r = matr->getRowsCount(); r < getRowsCount(); ++r)
				for (int c = 0; c < matr->getColsCount(); ++c)
					drawItem(r, c + offsetCols, 0);
		}
		offsetCols += matr->getColsCount();
	}
}


std::function<void(int, int, double)> HorizontalMatrixComposite::getIterator(int i, int j)
{
	int sum = 0;
	for (auto matr : list) {
		sum += matr->getColsCount();
		if (sum > j)
			if (i < matr->getRowsCount())
				return matr->getIterator(i, j);
			else
				return [this](int i, int j, double value) {drawItem(i, j, value); };
	}
	return list[0]->getIterator(i, j);
}

