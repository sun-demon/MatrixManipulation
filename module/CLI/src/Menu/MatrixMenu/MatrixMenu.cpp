#include "Menu/MatrixMenu/MatrixMenu.h"

namespace MatrixManipulation {
	namespace CLI {
		MatrixMenu::MatrixMenu(std::initializer_list<Item> items) : Menu("Matrix menu", items) {}

		const MatrixMenu::Matrix& MatrixMenu::getMatrix() const { return matrix_; }

		void MatrixMenu::setMatrix(const MatrixMenu::Matrix& matrix) { matrix_ = matrix; }
	}
}
