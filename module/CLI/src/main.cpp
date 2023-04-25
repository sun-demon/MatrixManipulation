#include "Menu/MatrixMenu/MatrixMenu.h"
#include "Menu/Function/CreateMatrix.h"
#include "Menu/Function/ResetRow.h"
#include "Menu/Function/ReplaceZeroRows.h"
#include "Menu/Function/OutputMatrix.h"

using namespace MatrixManipulation::CLI;

int main() {
    MatrixMenu menu({
        {"Create matrix", CreateMatrix},
        {"Reset row",         ResetRow},
        {"Replace zero rows", ReplaceZeroRows},
        {"Output matrix", OutputMatrix}
    });
    menu.run();

    return 0;
}
