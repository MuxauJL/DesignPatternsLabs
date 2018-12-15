#include "stdafx.h"
#include "ConsoleDrawer.h"
#include <iostream>
#include <iomanip>
#include "MatrixStatistics.h"
//#include "windows.h"

ConsoleDrawer::ConsoleDrawer(int numberWidth, bool showBorder)
{
	AllocConsole();
	AttachConsole(GetCurrentProcessId());
	FILE* stream;
	freopen_s(&stream, "CONOUT$", "w", stdout);
	this->showBorder = showBorder;
	this->numberWidth = numberWidth;
}

ConsoleDrawer::~ConsoleDrawer()
{
}

void ConsoleDrawer::drawBorder(int rowsCount, int colsCount) {
	system("cls");
	short lastPos = (numberWidth + 1) * colsCount;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
	char ch;
	if (showBorder)
		ch = '*';
	else
		ch = ' ';
	std::cout << ch << ch;
	for (int j = 0; j < colsCount; ++j)
		for (int k = 0; k < (numberWidth + 1); ++k)
			std::cout << ch;
	std::cout << std::endl;
	for (int i = 0; i < rowsCount; ++i) {
		std::cout << ch;
		for (int k = 0; k < lastPos; ++k)
			std::cout << " ";
		std::cout << ch << "\n";
	}
	for (int j = 0; j < colsCount; ++j)
		for (int k = 0; k < (numberWidth + 1); ++k)
			std::cout << ch;
	std::cout << ch << ch;
}

void ConsoleDrawer::drawItem(int i, int j, double value) {
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)(j*(numberWidth + 1)) + 1, (short)i + 1 });
	std::cout << std::setw(numberWidth + 1) << value;
}
