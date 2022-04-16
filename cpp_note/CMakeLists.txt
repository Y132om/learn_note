# cmake needs this line
cmake_minimum_required(VERSION 3.1)

# Define project name
project(cpp_note)

#find_package(OpenCV REQUIRED)

include_directories(include)
aux_source_directory(src DIR_SRCS)
set(PROJECT_SRC ${DIR_SRCS})
add_executable(${PROJECT_NAME} ${PROJECT_SRC})
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
