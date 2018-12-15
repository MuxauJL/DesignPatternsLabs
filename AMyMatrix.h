#pragma once
#include "IMatrix.h"
#include "IVector.h"
#include "IDrawer.h"
#include <vector>
#include "IVectorFactory.h"
#include "IDrawable.h"
#include "IIterable.h"

class AMyMatrix :
	public IMatrix, public IDrawable, public IIterable
{
public:
	AMyMatrix() {};
	AMyMatrix(int rows, int cols, IVectorFactory* vectorFactory, IDrawer * drawer = nullptr);
	virtual ~AMyMatrix();
	virtual int getRowsCount();
	virtual int getColsCount();
	virtual double get(int row, int col);
	virtual void set(int row, int col, double value);
	virtual void draw();
	virtual void setDrawer(IDrawer* drawer) { d = drawer; };
	virtual AMyMatrix* getComponent() { return this; };
	virtual void iterate(std::function<void(int, int, double)>it = nullptr);
//ненулевые параметры нужны для возвращения частного итератора матрицы, входящей в состав объекта компоновщика.
	virtual std::function<void(int, int, double)> getIterator(int i = 0, int j = 0) = 0;
protected:
	void drawBorder(int rowsCount, int colsCount);
	void drawItem(int i, int j, double value);
private:
	std::vector<IVector*> data;
	IDrawer* d;
};