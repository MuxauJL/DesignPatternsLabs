
// PP_indWork_2Dlg.cpp: файл реализации
//

#include "stdafx.h"
#include "PP_indWork_2.h"
#include "PP_indWork_2Dlg.h"
#include "afxdialogex.h"
#include "MatrixNormal.h"
#include "MatrixSparse.h"
#include "MatrixInitiator.h"
#include "MatrixSet.h"
#include "CM.h"
#include "Init.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CPPindWork2Dlg



CPPindWork2Dlg::CPPindWork2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PP_INDWORK_2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPPindWork2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK1, m_showBorder);
}

BEGIN_MESSAGE_MAP(CPPindWork2Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CPPindWork2Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CPPindWork2Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_CHECK1, &CPPindWork2Dlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_BUTTON3, &CPPindWork2Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CPPindWork2Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CPPindWork2Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CPPindWork2Dlg::OnBnClickedButton6)
END_MESSAGE_MAP()


// Обработчики сообщений CPPindWork2Dlg

BOOL CPPindWork2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию
	consoleDrawer = new ConsoleDrawer(2);
	contextDrawer = new CContextDrawer(2);
	drawerComposite = new DrawerComposite();
	drawerComposite->addDrawer(std::shared_ptr<IDrawer>(new CContextDrawer(2)));
	drawerComposite->addDrawer(std::shared_ptr<IDrawer>(new CContextDrawer(5)));

	matrix = new MatrixNormal(5, 4);
	ACommand* init = new Init(matrix);
	init->execute();

	matrix->setDrawer(contextDrawer);
	matrix->draw();

	matrix->setDrawer(consoleDrawer);
	matrix->draw();

	matrix->setDrawer(drawerComposite);
	matrix->draw();

	decoratedMatrix = nullptr;
	hMatrixComposite = nullptr;
	vMatrixComposite = nullptr;
	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CPPindWork2Dlg::OnPaint()
{
	CDialogEx::OnPaint();
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CPPindWork2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPPindWork2Dlg::OnBnClickedButton1()
{
	hMatrixComposite = std::shared_ptr<HorizontalMatrixComposite>(new HorizontalMatrixComposite());
	std::shared_ptr<AMyMatrix> mn1(new MatrixNormal(5, 5));
	std::shared_ptr<AMyMatrix> ms1(new MatrixSparse(3, 5));
	std::shared_ptr<AMyMatrix> mn2(new MatrixNormal(5, 3));
	MatrixInitiator::fillMatrix(mn1.get(), 20, 99);
	MatrixInitiator::fillMatrix(ms1.get(), 5, 99);
	MatrixInitiator::fillMatrix(mn2.get(), 13, 99);
	//hMatrixComposite->add(mn1);
	hMatrixComposite->add(ms1);
	hMatrixComposite->add(mn2);
	//MatrixInitiator::fillMatrix(matrix, 120, 99);
	UpdateData(TRUE);
	if (m_showBorder.GetCheck() == BST_CHECKED)
		consoleDrawer->showBorder = true;
	else
		consoleDrawer->showBorder = false;
	if (m_showBorder.GetCheck() == BST_CHECKED)
		contextDrawer->showBorder = true;
	else
		contextDrawer->showBorder = false;
	//matrix->setDrawer(consoleDrawer);
	hMatrixComposite->setDrawer(consoleDrawer);
	//matrix->draw();
	hMatrixComposite->draw();
    //	matrix->setDrawer(contextDrawer);
	hMatrixComposite->setDrawer(contextDrawer);
	//matrix->draw();
	hMatrixComposite->draw();

	hMatrixComposite->setDrawer(drawerComposite);
	hMatrixComposite->draw();
}


void CPPindWork2Dlg::OnBnClickedButton2()
{
	vMatrixComposite = std::shared_ptr<VerticalMatrixComposite>(new VerticalMatrixComposite());
	std::shared_ptr<AMyMatrix> ms1(new MatrixSparse(5, 10));
	std::shared_ptr<AMyMatrix> mn1( new MatrixNormal(10, 5));
	std::shared_ptr<AMyMatrix> ms2 ( new MatrixSparse(5, 5));
	MatrixInitiator::fillMatrix(ms1.get(), 20, 99);
	MatrixInitiator::fillMatrix(mn1.get(), 45, 99);
	MatrixInitiator::fillMatrix(ms2.get(), 7, 99);
	vMatrixComposite->add(ms1);
	vMatrixComposite->add(mn1);
	vMatrixComposite->add(ms2);
	if (hMatrixComposite != nullptr)
		vMatrixComposite->add(hMatrixComposite);
	if (((CButton *)(GetDlgItem(IDC_CHECK1)))->GetCheck() == BST_CHECKED)
		consoleDrawer->showBorder = true;
	else
		consoleDrawer->showBorder = false;
	if (((CButton *)(GetDlgItem(IDC_CHECK1)))->GetCheck() == BST_CHECKED)
		contextDrawer->showBorder = true;
	else
		contextDrawer->showBorder = false;
	vMatrixComposite->setDrawer(consoleDrawer);
	vMatrixComposite->draw();
	vMatrixComposite->setDrawer(contextDrawer);
	vMatrixComposite->draw();

	vMatrixComposite->setDrawer(drawerComposite);
	vMatrixComposite->draw();
}


void CPPindWork2Dlg::OnBnClickedCheck1()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (((CButton *)(GetDlgItem(IDC_CHECK1)))->GetCheck() == BST_CHECKED) {
		consoleDrawer->showBorder = true;
		contextDrawer->showBorder = true;
	}
	else {
		consoleDrawer->showBorder = false;
		contextDrawer->showBorder = false;
	}
	if (matrix != nullptr) {
		matrix->setDrawer(contextDrawer);
		matrix->draw();
		//system("cls");
		matrix->setDrawer(consoleDrawer);
		matrix->draw();
	}
}


void CPPindWork2Dlg::OnBnClickedButton3()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (vMatrixComposite != nullptr) {
		decoratedMatrix = std::shared_ptr<RenumerDecorator>(new RenumerDecorator(std::shared_ptr<AMyMatrix>(new RenumerDecorator(std::shared_ptr<AMyMatrix>(vMatrixComposite)))));
		decoratedMatrix->swapRows(rand() % 10, rand() % 10);
		decoratedMatrix->swapCols(rand() % 10, rand() % 10);
		decoratedMatrix->setDrawer(consoleDrawer);
		decoratedMatrix->draw();
		decoratedMatrix->setDrawer(contextDrawer);
		decoratedMatrix->draw();

		decoratedMatrix->setDrawer(drawerComposite);
		decoratedMatrix->draw();
	}
}


void CPPindWork2Dlg::OnBnClickedButton4()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (decoratedMatrix != nullptr) {
		matrix = decoratedMatrix->getComponent();
		matrix->setDrawer(contextDrawer);
		matrix->draw();
		//system("cls");
		matrix->setDrawer(consoleDrawer);
		matrix->draw();

		matrix->setDrawer(drawerComposite);
		matrix->draw();
	}
}


void CPPindWork2Dlg::OnBnClickedButton5()
{
	// TODO: добавьте свой код обработчика уведомлений
	ACommand* cmd = new MatrixSet(matrix, rand() % matrix->getRowsCount(), rand() % matrix->getColsCount(), 1 + rand() % 99);
	cmd->execute();
	delete cmd;
	matrix->setDrawer(contextDrawer);
	matrix->draw();

	matrix->setDrawer(consoleDrawer);
	matrix->draw();

	matrix->setDrawer(drawerComposite);
	matrix->draw();
}


void CPPindWork2Dlg::OnBnClickedButton6()
{
	// TODO: добавьте свой код обработчика уведомлений
	CM::instance().undo();
	matrix->setDrawer(contextDrawer);
	matrix->draw();

	matrix->setDrawer(consoleDrawer);
	matrix->draw();

	matrix->setDrawer(drawerComposite);
	matrix->draw();
}
