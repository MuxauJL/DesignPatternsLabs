
// PP_indWork_2.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CPPindWork2App:
// Сведения о реализации этого класса: PP_indWork_2.cpp
//

class CPPindWork2App : public CWinApp
{
public:
	CPPindWork2App();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

//extern CPPindWork2App theApp;
