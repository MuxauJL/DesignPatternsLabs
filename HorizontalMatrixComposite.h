#pragma once
#include "AMyMatrix.h"
#include <vector>
#include <memory>

class HorizontalMatrixComposite :
	public AMyMatrix
{
public:
	HorizontalMatrixComposite(bool shNulls = true);
	virtual ~HorizontalMatrixComposite();
	virtual int getRowsCount();
	virtual int getColsCount();
	virtual double get(int row, int col);
	virtual void set(int row, int col, double value);
	// если необходимо сохранить добавляемый объект после разрушения текущего объекта, тогда нужно иметь хотя бы один shared_ptr на добавляемый объект, иначе он будет уничтожен.
	void add(std::shared_ptr<AMyMatrix>);
	bool showNulls;
	virtual void iterate(std::function<void(int, int, double) >it = nullptr);
	virtual void setDrawer(IDrawer* drawer) { AMyMatrix::setDrawer(drawer); for (auto matr : list) matr->setDrawer(drawer); };
	virtual std::function<void(int, int, double)> getIterator(int i = 0, int j = 0);
private:
	std::vector<std::shared_ptr<AMyMatrix>> list;
};

