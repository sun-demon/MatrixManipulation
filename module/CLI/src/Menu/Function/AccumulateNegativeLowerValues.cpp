#include "Menu/Function/AccumulateNegativeLowerValues.h"

#include <conio.h>
#include <iostream>

#include "Menu/MatrixMenu/MatrixMenu.h"

using namespace std;

void MatrixManipulation::CLI::AccumulateNegativeLowerValues(Menu* menu) {
	system("cls");
	auto* matrixMenu = reinterpret_cast<MatrixMenu*>(menu);

	size_t rank = matrixMenu->getMatrix().size();
	vector<int> resetRow(rank, 0);

	int result = 0;
	for (int i = 0; i < rank; ++i) {
		for (int j = 0; j < rank; ++j) {
			if (j <= i) {
				int value = matrixMenu->getMatrix()[i].at(j);
				if (value < 0)
					result += value;
			}
		}
	}

	cout << "Result of negative lower values accumulation: " << result << "\r\n";
	cout << "Press any key to continue..." << flush;
	_getch();
}