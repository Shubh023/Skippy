cmake_minimum_required (VERSION 3.20)

project ("Skippy")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include sub-projects.
find_package(Vulkan REQUIRED)
add_subdirectory ("Dependencies/glfw")
add_subdirectory ("Dependencies/glm")
# add_subdirectory ("Dependencies/sdl2")
add_subdirectory ("Skippy")

target_include_directories (${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/glfw/include)
target_include_directories (${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/glm/include)
# target_include_directories (${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/sdl2/include)
target_include_directories(${PROJECT_NAME} PUBLIC ${Vulkan_INCLUDE_DIRS})