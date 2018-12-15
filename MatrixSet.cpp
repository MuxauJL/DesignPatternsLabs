#include "stdafx.h"
#include "MatrixSet.h"

MatrixSet::MatrixSet(IMatrix* m, int i, int j, double val)
{
	matrix = m;
	row = i;
	col = j;
	value = val;
}

MatrixSet::~MatrixSet()
{
}
