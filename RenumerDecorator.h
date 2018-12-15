#pragma once
#include "AMyMatrix.h"
#include <memory>
#include <vector>

class RenumerDecorator :
	public AMyMatrix
{
public:
	// если необходимо сохранить декорируемый объект после разрушения текущего объекта, тогда нужно иметь хотя бы один shared_ptr на декорируемый объект, иначе он будет уничтожен.
	RenumerDecorator(std::shared_ptr<AMyMatrix>);
	virtual ~RenumerDecorator();
	virtual int getRowsCount();
	virtual int getColsCount();
	virtual double get(int row, int col);
	virtual void set(int row, int col, double value);
	virtual AMyMatrix* getComponent() { return component->getComponent(); };
	void swapRows(int, int);
	void swapCols(int, int);
	virtual void iterate(std::function<void(int, int, double)>it = nullptr);
	virtual std::function<void(int, int, double)> getIterator(int i = 0, int j = 0) { return component->getIterator(rowsNumbers[i], colsNumbers[j]); };
	virtual void setDrawer(IDrawer* drawer) { AMyMatrix::setDrawer(drawer); component->setDrawer(drawer); };
private:
	std::shared_ptr<AMyMatrix> component;
	std::vector<int> rowsNumbers;
	std::vector<int> colsNumbers;
};

