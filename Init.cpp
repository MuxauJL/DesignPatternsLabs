#include "stdafx.h"
#include "Init.h"

Init::Init(AMyMatrix* m)
{
	matrix = m;
}

Init::~Init()
{
}

void Init::doExecute()
{
	for (int i = 0; i < matrix->getRowsCount(); ++i)
		for (int j = 0; j < matrix->getColsCount(); ++j)
			matrix->set(i, j, 0);
}

