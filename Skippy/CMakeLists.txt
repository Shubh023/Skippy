cmake_minimum_required (VERSION 3.20)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)
set (SOURCES "src/main.cpp")
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/resources/shaders
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} glfw glm Vulkan::Vulkan)