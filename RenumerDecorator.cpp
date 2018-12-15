#include "stdafx.h"
#include "RenumerDecorator.h"


RenumerDecorator::RenumerDecorator(std::shared_ptr<AMyMatrix> c)
{
	component = c;
	rowsNumbers = std::vector<int>(component->getRowsCount());
	colsNumbers = std::vector<int>(component->getColsCount());
	for (int i = 0; i < component->getRowsCount(); ++i)
		rowsNumbers[i] = i;
	for (int i = 0; i < component->getColsCount(); ++i)
		colsNumbers[i] = i;
}


RenumerDecorator::~RenumerDecorator()
{
}

int RenumerDecorator::getRowsCount()
{
	return component->getRowsCount();
}

int RenumerDecorator::getColsCount()
{
	return component->getColsCount();
}

double RenumerDecorator::get(int row, int col)
{
	return component->get(rowsNumbers[row], colsNumbers[col]);
}

void RenumerDecorator::set(int row, int col, double value)
{
	component->set(rowsNumbers[row], colsNumbers[col], value);
}

void RenumerDecorator::swapRows(int x, int y)
{
	int tmp = rowsNumbers[x];
	rowsNumbers[x] = rowsNumbers[y];
	rowsNumbers[y] = tmp;
}

void RenumerDecorator::swapCols(int x, int y)
{
	int tmp = colsNumbers[x];
	colsNumbers[x] = colsNumbers[y];
	colsNumbers[y] = tmp;
}

void RenumerDecorator::iterate(std::function<void(int, int, double)>iterator) {
	for (int i = 0; i < getRowsCount(); ++i)
		for (int j = 0; j < getColsCount(); ++j)
			component->getIterator(rowsNumbers[i], colsNumbers[j])(i, j, get(i, j));
}
