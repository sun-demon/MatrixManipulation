#include "Menu/Function/ReplaceZeroRows.h"

#include <iostream>

#include "Menu/MatrixMenu/MatrixMenu.h"

using namespace std;

bool IsZero(const std::vector<int>&);


void MatrixManipulation::CLI::ReplaceZeroRows(Menu* menu) {
	system("cls");
	auto* matrixMenu = reinterpret_cast<MatrixMenu*>(menu);

	size_t rank = matrixMenu->getMatrix().size();
	vector<int> sampleRow(rank);

	cout << "Input sample row with rank " << rank << ": " << flush;
	for (size_t i = 0; i < rank; ++i)
		cin >> sampleRow[i];

	for (auto& row : matrixMenu->getMatrix())
		if (IsZero(row))
			row = sampleRow;
}


bool IsZero(const std::vector<int>& row) {
	for (auto val : row)
		if (val != 0)
			return false;
	return true;
}