#include "Menu/MatrixMenu/MatrixMenu.h"
#include "Menu/Function/CreateMatrix.h"
#include "Menu/Function/ResetRow.h"
#include "Menu/Function/ReplaceZeroRows.h"
#include "Menu/Function/AccumulateNegativeLowerValues.h"
#include "Menu/Function/OutputMatrix.h"
#include "Menu/Function/SortRowsBySignature.h"

using namespace MatrixManipulation::CLI;

int main() {
    MatrixMenu menu({
        {"Create matrix", CreateMatrix},
        {"Sort rows", SortRowsBySignature},
        {"Reset row",         ResetRow},
        {"Replace zero rows", ReplaceZeroRows},
        {"Accumulate negative lower values", AccumulateNegativeLowerValues},
        {"Output matrix", OutputMatrix}
    });
    menu.run();

    return 0;
}
