cmake_minimum_required(VERSION 3.27)
project(Chip-8)

add_subdirectory(vendor/SDL)


include_directories(vendor/imgui)
include_directories(vendor/ImGuiFileDialog)
file(GLOB IMGUI_SRC vendor/imgui/*.cpp)
set(CMAKE_CXX_STANDARD 23)


add_executable(${PROJECT_NAME}
        main.cpp
        Chip8.cpp
        Chip8.h
        vendor/ImGuiFileDialog/ImGuiFileDialog.cpp
        vendor/ImGuiFileDialog/ImGuiFileDialog.h
        ${IMGUI_SRC}

)

target_link_directories(${PROJECT_NAME} PUBLIC SDL3::SDL3)
target_link_libraries(${PROJECT_NAME} PUBLIC  SDL3::SDL3)

