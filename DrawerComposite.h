#pragma once
#include "IDrawer.h"
#include <vector>
#include <memory>

class DrawerComposite :
	public IDrawer
{
public:
	/*DrawerComposite();
	virtual ~DrawerComposite();*/
	virtual void drawBorder(int rowsCount, int colsCount);
	virtual void drawItem(int i, int j, double value);
	void addDrawer(std::shared_ptr<IDrawer> d) { list.push_back(d); };
private:
	std::vector<std::shared_ptr<IDrawer>> list;
};

