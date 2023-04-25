#include "Function/CreateMatrix.h"

#include <conio.h>
#include <iostream>
#include <utility>

#include "Menu/MatrixMenu/MatrixMenu.h"

using namespace std;

void Random(vector<vector<int>>&, int, int);
void Random(vector<int>&, int, int);
int  Random(int, int);


void MatrixManipulation::CLI::CreateMatrix(Menu* menu) {
	system("cls");
	auto* matrixMenu = reinterpret_cast<MatrixMenu*>(menu);

	cout << "Input size of square matrix : " << flush;
	size_t rank = 10;
	cin >> rank;
	
	int min = -14, max = 14;
	cout << "Input range of matrix's values : " << flush;
	cin >> min >> max;
	if (max < min)
		swap(max, min);

	vector<vector<int>> newMatrix(rank, vector<int>(rank));
	srand(static_cast<unsigned int>(time(nullptr)));
	Random(newMatrix, min, max);

	matrixMenu->setMatrix(newMatrix);
}


void Random(vector<vector<int>>& matrix, int min, int max) {
	for (auto& row : matrix)
		Random(row, min, max);
}

void Random(vector<int>& array, int min, int max) {
	for (int& element : array)
		element = Random(min, max);
}

int  Random(int min, int max) {
	return rand() % (max - min + 1) + min;
}
