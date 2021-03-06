// MatrixPanel.cpp: файл реализации
//

#include "stdafx.h"
#include "PP_indWork_2.h"
#include "CContextDrawer.h"
#include "afxdialogex.h"
#include <sstream>
#include <iomanip>


// Диалоговое окно MatrixPanel

IMPLEMENT_DYNAMIC(CContextDrawer, CDialogEx)

CContextDrawer::CContextDrawer(int numberWidth, bool showBorder)
	: CDialogEx()
{
	this->showBorder = showBorder;
	this->numberWidth = numberWidth;
	flag = false;
	Create(IDD_MatrixPanel);
	ShowWindow(SW_SHOW);
}

CContextDrawer::~CContextDrawer()
{
	DestroyWindow();
}

void CContextDrawer::drawBorder(int rowsCount,int colsCount) {
	flag = false;
	this->rowsCount = rowsCount;
	this->colsCount = colsCount;
	InvalidateRect(0);
	UpdateWindow();
}

void CContextDrawer::drawItem(int i, int j, double value) {
	row = i;
	col = j;
	val = value;
	flag = true;
	InvalidateRect(0, FALSE);
	UpdateWindow();
}


BEGIN_MESSAGE_MAP(CContextDrawer, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// Обработчики сообщений MatrixPanel

void CContextDrawer::OnPaint() {
	if (showBorder || flag) {
		CPaintDC dc(this);
		if (showBorder) {
			dc.MoveTo(2, 2);
			dc.LineTo(colsCount * numberWidth * 15 - 5, 2);
			dc.LineTo(colsCount * numberWidth * 15 - 5, rowsCount * 20);
			dc.LineTo(2, rowsCount * 20);
			dc.LineTo(2, 2);
		}
		if (flag) {
			char* elem = new char[numberWidth + 2];//+1 для точки и +1 для символа конца строки
			for (int k = 0; k < numberWidth + 1; ++k)
				elem[k] = ' ';
			elem[numberWidth + 1] = '\0';
			std::istringstream(std::to_string(val)) >> std::setw(numberWidth + 1) >> elem;//+1 для точки
			dc.TextOutW(5 + col * numberWidth * 15, 5 + row * 20, CString(elem));
			delete[] elem;
			flag = false;
		}
	}
}