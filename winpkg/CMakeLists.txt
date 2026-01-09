cmake_minimum_required(VERSION 3.10)

project(aigui LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Core)
qt_standard_project_setup()

qt_add_executable(${PROJECT_NAME} GUI/gui.cpp)
target_link_libraries(${PROJECT_NAME}
        PRIVATE Qt6::Widgets
        PRIVATE Qt6::Core
)
target_include_directories(${PROJECT_NAME}
        PRIVATE GUI
)

add_subdirectory(aiOverride)

target_link_libraries(${PROJECT_NAME} PUBLIC aiOverride)
