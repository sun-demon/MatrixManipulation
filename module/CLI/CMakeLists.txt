# Название модуля
get_filename_component(MODULE_NAME "${CMAKE_CURRENT_LIST_DIR}" NAME)

# Название исполняемого файла
set(EXECUTABLE_NAME "${PROJECT_NAME}_${MODULE_NAME}")

# Путь к закоголовочным файлам модуля
include_directories("include")

# Источники сборки исполняемого файла модуля
add_executable (${EXECUTABLE_NAME}  
	"src/main.cpp"

	"include/Menu/Menu.h"
		"src/Menu/Menu.cpp"

	"include/Menu/MatrixMenu/MatrixMenu.h"
		"src/Menu/MatrixMenu/MatrixMenu.cpp"

	"include/Menu/Function/CreateMatrix.h"
		"src/Menu/Function/CreateMatrix.cpp"

	"include/Menu/Function/SortRowsBySignature.h"
		"src/Menu/Function/SortRowsBySignature.cpp"

	"include/Menu/Function/ResetRow.h"
		"src/Menu/Function/ResetRow.cpp"

	"include/Menu/Function/ReplaceZeroRows.h"
		"src/Menu/Function/ReplaceZeroRows.cpp"

	"include/Menu/Function/AccumulateNegativeLowerValues.h"
		"src/Menu/Function/AccumulateNegativeLowerValues.cpp"

	"include/Menu/Function/OutputMatrix.h"
		"src/Menu/Function/OutputMatrix.cpp"
)

# Ограничение стандарта написания кода на C++20 для CMake выше версии 3.12
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ${EXECUTABLE_NAME} PROPERTY CXX_STANDARD 20)
endif()
