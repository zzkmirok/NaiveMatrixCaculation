cmake_minimum_required(VERSION 3.5)
project (Matrix)
set(SOURCES src/MatrixAdd.cc src/testmatrix.cc)

add_executable(Matrix ${SOURCES})
# Set the directories that should be included in the build command for this target
# when running g++ these will be included as -I/directory/path/
target_include_directories(Matrix
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)