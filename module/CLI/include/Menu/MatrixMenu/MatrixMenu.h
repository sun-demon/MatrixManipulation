#ifndef MATRIXMANIPULATION_CLI_MATRIXMENU_H
#define MATRIXMANIPULATION_CLI_MATRIXMENU_H


#include "Menu/Menu.h"

namespace MatrixManipulation {
	namespace CLI {
		class MatrixMenu : public Menu {
		public:
			using Matrix = std::vector<std::vector<int>>;

			MatrixMenu(std::initializer_list<Item>);

			const Matrix& getMatrix() const;
				  Matrix& getMatrix();

			void setMatrix(const Matrix& matrix);

		private:
			Matrix matrix_;
		};
	}
}


#endif //MATRIXMANIPULATION_CLI_MATRIXMENU_H