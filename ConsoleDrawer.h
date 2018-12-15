#pragma once
#include "IDrawer.h"
#include "IMatrix.h"

class ConsoleDrawer :
	public IDrawer
{
public:
	ConsoleDrawer(int numberWidth = 3, bool showBorder = false);
	~ConsoleDrawer();
	virtual void drawBorder(int rowsCount, int colsCount);
	virtual void drawItem(int i, int j, double value);
	bool showBorder;
	int numberWidth;
};

