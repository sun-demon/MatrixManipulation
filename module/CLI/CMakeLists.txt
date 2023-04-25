# CMakeList.txt: проект CMake для CLI; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

# Название проекта
get_filename_component(MODULE_NAME "${CMAKE_CURRENT_LIST_DIR}" NAME)

# Название исполняемого файла
set(EXECUTABLE_NAME "${PROJECT_NAME}_${MODULE_NAME}")

# Добавьте пути к закоголовочным файлам проекта
include_directories("include")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (EXECUTABLE_NAME  
	"src/main.cpp"

	"include/Menu/Menu.h"
		"src/Menu/Menu.cpp"

	"include/Menu/MatrixMenu/MatrixMenu.h"
		"src/Menu/MatrixMenu/MatrixMenu.cpp"

	"include/Menu/Function/CreateMatrix.h"
		"src/Menu/Function/CreateMatrix.cpp"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET EXECUTABLE_NAME PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
