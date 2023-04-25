#include "Function/OutputMatrix.h"

#include <conio.h>
#include <iomanip>
#include <iostream>

#include "Menu/MatrixMenu/MatrixMenu.h"

using namespace std;

ostream& operator<<(ostream&, const vector<vector<int>>&);
ostream& operator<<(ostream&, const vector<int>&);
int CountCharacters(int);


void MatrixManipulation::CLI::OutputMatrix(Menu* menu) {
	system("cls");
	auto* matrixMenu = reinterpret_cast<MatrixMenu*>(menu);

	cout << matrixMenu->getMatrix() << "\r\n"
		 << "Press any key to continue..." << flush;
	_getch();
}


ostream& operator<<(ostream& out, const vector<vector<int>>& matrix) {
	int maxColumns = 0;
	for (auto& row : matrix)
		maxColumns = max((int)row.size(), maxColumns);
	vector<int> widthsColumns(maxColumns, 0);
	for (auto& row : matrix)
		for (int j = 0; j < row.size(); ++j)
			widthsColumns[j] = max(CountCharacters(row[j]), widthsColumns[j]);

	for (auto& row : matrix) {
		for (int j = 0; j < row.size(); ++j)
			out << setw(widthsColumns[j]) << row[j] << " ";
		out << "\r\n";
	}
	return out;
}

ostream& operator<<(ostream& out, const vector<int>& array) {
	for (int element : array)
		out << element << " ";
	return out;
}

int CountCharacters(int value) {
	int result = value <= 0 ? 1 : 0;
	for (; value != 0; value /= 10)
		++result;
	return result;
}
