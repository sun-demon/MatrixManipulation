#include "Menu/MatrixMenu/MatrixMenu.h"
#include "Menu/Function/CreateMatrix.h"
#include "Menu/Function/OutputMatrix.h"

using namespace MatrixManipulation::CLI;

int main() {
    MatrixMenu menu({
        {"Create matrix", CreateMatrix},
        {"Output matrix", OutputMatrix}
    });
    menu.run();

    return 0;
}
