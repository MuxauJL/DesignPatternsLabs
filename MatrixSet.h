#pragma once
#include "ACommand.h"
#include "IMatrix.h"

class MatrixSet :
	public ACommand
{
private:
	IMatrix* matrix;
	int row, col;
	double value;
public:
	MatrixSet(IMatrix* m, int i, int j, double val);
	virtual ~MatrixSet();
	ACommand* clone() { return new MatrixSet(matrix, row, col, value); };
protected:
	void doExecute() { matrix->set(row, col, value); };
};

