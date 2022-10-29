add_executable(shell-app main.cpp arm.cpp path_planner.cpp)
add_executable(test-yaml test_yaml.cpp)
include_directories(
    ${CMAKE_SOURCE_DIR}/include
)

target_include_directories(test-yaml PUBLIC ../vendor/yaml-cpp/include 
                                           ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(test-yaml PUBLIC yaml-cpp)
