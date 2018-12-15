#pragma once
#include "IMatrix.h"
#include <cstdlib>
#include <time.h>
class MatrixInitiator
{
public:
	static void fillMatrix(IMatrix* matrix, int count, int maxValue) {
		srand(time(0));
		int rowsCount, colsCount, size;
		rowsCount = matrix->getRowsCount();
		colsCount = matrix->getColsCount();
		size = rowsCount * colsCount;
		if (count > size)
			count = size;

		int currentCount = 0;
		int i, j;
		float p = count / (float)size * 100.;
		if (count < size / 2) {
			for (i = 0; i < rowsCount; ++i)
				for (j = 0; j < colsCount; ++j) {
					matrix->set(i, j, 0);
					if ((currentCount < count) && (rand() % 100 < p)) {
						matrix->set(i, j, rand() % maxValue + 1);
						++currentCount;
					}
				}
		}
		else {
			for (i = 0; i < rowsCount; ++i)
				for (j = 0; j < colsCount; ++j) {
					if ((rand() % 100 < 100 - p)) {
						matrix->set(i, j, 0);
					}
					else {
						matrix->set(i, j, rand() % maxValue + 1);
						++currentCount;
					}
				}
		}
		while (currentCount < count) {
			i = rand() % rowsCount;
			j = rand() % colsCount;
			if (matrix->get(i, j) == 0) {
				matrix->set(i, j, rand() % maxValue + 1);
				++currentCount;
			}
		}
	}
};

