#pragma once
#include "IMatrix.h"
#include "IDrawer.h"

// Диалоговое окно MatrixPanel

class CContextDrawer : public CDialogEx, public IDrawer
{
	DECLARE_DYNAMIC(CContextDrawer)

public:
	CContextDrawer(int numberWidth = 3, bool showBorder = false);   // стандартный конструктор
	virtual ~CContextDrawer();
	virtual void drawBorder(int rowsCount, int colsCount);
	virtual void drawItem(int i, int j, double value);

	// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MatrixPanel };
#endif
public:
	bool showBorder;
	int numberWidth;
private:
	bool flag;
	int row;
	int col;
	double val;
	int rowsCount;
	int colsCount;

protected:
	//virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
};
