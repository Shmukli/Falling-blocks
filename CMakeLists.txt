cmake_minimum_required(VERSION 3.17)
project(Tetris)

set(CMAKE_EXE_LINKER_FLAGS -static)

set(CMAKE_CXX_STANDARD 20)
set(SFML_STATIC_LIBRARIES TRUE)


include_directories(${EIGEN_DIR})
include_directories(headers F:/lib/SFML/include)

find_package(SFML 2.5 COMPONENTS system window graphics)










add_executable(Tetris main.cpp Engine/Engine.h Engine/Engine.cpp object/GameObject.h object/GameObject.cpp object/GameBlock.h object/GameBlock.cpp visual/Menu.h physics/Collision.cpp physics/Collision.h event/eventController.h event/eventController.cpp visual/Menu.cpp Engine/settings.h Engine/settings.cpp object/STypeBlock.h object/STypeBlock.cpp object/LTypeBlock.h object/LTypeBlock.cpp object/SQUARETypeBlock.h object/SQUARETypeBlock.cpp object/ITypeBlock.h object/ITypeBlock.cpp object/TTypeBlock.h object/TTypeBlock.cpp)
target_link_libraries(Tetris sfml-system sfml-window sfml-graphics)