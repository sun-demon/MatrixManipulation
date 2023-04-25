#include "Menu/Function/SortRowsBySignature.h"

#include <algorithm>
#include <iostream>

#include "Menu/MatrixMenu/MatrixMenu.h"

using namespace std;

bool CompareBySignature(int, int);
int Signature(int);


void MatrixManipulation::CLI::SortRowsBySignature(Menu* menu) {
	system("cls");
	auto* matrixMenu = reinterpret_cast<MatrixMenu*>(menu);

	for (auto& row : matrixMenu->getMatrix())
		sort(row.begin(), row.end(), CompareBySignature);
}




bool CompareBySignature(int left, int right) {
	return Signature(left) < Signature(right);
}
int Signature(int value) {
	return (value < 0 ? -1 : (value == 0 ? 1 : 0));
}