#pragma once
#include "ACommand.h"
#include "PP_indWork_2Dlg.h"
#include "AMyMatrix.h"

class Init :
	public ACommand
{
private:
	AMyMatrix* matrix;
public:
	Init(AMyMatrix* m);
	virtual ~Init();
	ACommand* clone() { return new Init(matrix); };
protected:
	void doExecute();
};

