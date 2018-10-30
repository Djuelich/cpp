cmake_minimum_required(VERSION 2.8)
project(CMAKE_GUI)

# Find Qt4 package and add include directories for the 
# used components
find_package(Qt4)
if(QT4_FOUND)
    include_directories(${QT_INCLUDE_DIR})
    include_directories(${QT_QTGUI_INCLUDE_DIR})
    include_directories(${QT_QTCORE_INCLUDE_DIR})
endif(QT4_FOUND)

# Add the build directory to include directories to
# find the generated header files for the UI components
include_directories(${CMAKE_CURRENT_BINARY_DIR})

# Add QT definitions, use Q_SIGNALS and QSLOTS. Uncomment
# this to use signal and slot keywords in your code
add_definitions(-DQT_NO_KEYWORDS )
add_definitions(${QT_DEFINITIONS})

# List of unser interface files
set(GUI_UIS src/MainWindowInterface.ui)

# List of source files
set(GUI_SOURCES src/Main.cpp 
                src/MainWindow.cpp
                src/GraphicsTileItem.cpp
                src/LevelScene.cpp)

# List of input files for moc, i.e., all object the 
# use the Q_OBJECT macro 
set(GUI_MOCS src/MainWindow.hpp)

# All library dependencies
set(GUI_DEPENDENCIES ${QT_QTCORE_LIBRARIES} ${QT_QTGUI_LIBRARIES})

# Parse ui files
qt_wrap_cpp(gui GUI_MOC_SRC ${GUI_MOCS})

# Generate meta code for signaling
qt_wrap_ui(gui GUI_UI_HDRS GUI_UI_SRC ${GUI_UIS})

# Add executable and link 
add_executable(gui ${GUI_SOURCES} ${GUI_MOC_SRC} ${GUI_UI_HDRS})
target_link_libraries(gui ${GUI_DEPENDENCIES})
