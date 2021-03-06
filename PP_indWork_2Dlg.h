
// PP_indWork_2Dlg.h: файл заголовка
//

#pragma once
#include "AMyMatrix.h"
#include "ConsoleDrawer.h"
#include "CContextDrawer.h"
#include "RenumerDecorator.h"
#include "HorizontalMatrixComposite.h"
#include "VerticalMatrixComposite.h"
#include "DrawerComposite.h"

// Диалоговое окно CPPindWork2Dlg
class CPPindWork2Dlg : public CDialogEx
{
	// Создание
public:
	CPPindWork2Dlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PP_INDWORK_2_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;
	AMyMatrix* matrix;
	std::shared_ptr<RenumerDecorator> decoratedMatrix;
	std::shared_ptr<HorizontalMatrixComposite> hMatrixComposite;
	std::shared_ptr<VerticalMatrixComposite> vMatrixComposite;
	ConsoleDrawer* consoleDrawer;
	CContextDrawer* contextDrawer;
	DrawerComposite* drawerComposite;
	CButton m_showBorder;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();

	DECLARE_MESSAGE_MAP()
	
};
