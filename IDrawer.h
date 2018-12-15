#pragma once
class IDrawer {
public:
	virtual void drawBorder(int rowsCount, int colsCount) = 0;
	virtual void drawItem(int i, int j, double value) = 0;
};