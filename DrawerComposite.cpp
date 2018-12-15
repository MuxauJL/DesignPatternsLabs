#include "stdafx.h"
#include "DrawerComposite.h"


//DrawerComposite::DrawerComposite()
//{
//}
//
//
//DrawerComposite::~DrawerComposite()
//{
//}

void DrawerComposite::drawBorder(int rowsCount, int colsCount)
{
	for (auto dr : list) {
		dr->drawBorder(rowsCount, colsCount);
	}
}

void DrawerComposite::drawItem(int i, int j, double value)
{
	for (auto dr : list) {
		dr->drawItem(i, j, value);
	}
}
