#include "Menu/Function/ResetRow.h"

#include <iostream>

#include "Menu/MatrixMenu/MatrixMenu.h"

using namespace std;

void MatrixManipulation::CLI::ResetRow(Menu* menu) {
	system("cls");
	auto* matrixMenu = reinterpret_cast<MatrixMenu*>(menu);

	size_t rank = matrixMenu->getMatrix().size();
	vector<int> resetRow(rank, 0);

	cout << "Input number of row in range [1, " << rank << "] for reset: " << flush;
	int rowNumber;
	cin >> rowNumber;
	rowNumber -= 1;

	if (0 <= rowNumber && rowNumber < rank)
		matrixMenu->getMatrix()[rowNumber] = resetRow;
}