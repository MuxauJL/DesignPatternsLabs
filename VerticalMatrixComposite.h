#pragma once
#include "AMyMatrix.h"
#include <vector>
#include <memory>

class VerticalMatrixComposite :
	public AMyMatrix
{
public:
	VerticalMatrixComposite(bool shNulls = true);
	virtual ~VerticalMatrixComposite();
	virtual int getRowsCount();
	virtual int getColsCount();
	virtual double get(int row, int col);
	virtual void set(int row, int col, double value);
	// ���� ���������� ��������� ����������� ������ ����� ���������� �������� �������, ����� ����� ����� ���� �� ���� shared_ptr �� ����������� ������, ����� �� ����� ���������.
	void add(std::shared_ptr<AMyMatrix>);
	bool showNulls;
	virtual void iterate(std::function<void(int, int, double)>it = nullptr);
	virtual void setDrawer(IDrawer* drawer) { AMyMatrix::setDrawer(drawer); for (auto matr : list) matr->setDrawer(drawer); };
	virtual std::function<void(int, int, double)> getIterator(int i = 0, int j = 0);
private:
	std::vector<std::shared_ptr<AMyMatrix>> list;
};