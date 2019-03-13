cmake_minimum_required(VERSION 2.8)
include(projectConfig.cmake)

set(INC_DIRS ${PROJECT_INC_DIR})
set(SRC_DIRS ${PROJECT_SRC_DIR})

include_directories(${INC_DIRS})
aux_source_directory(${SRC_DIRS} srcs)

add_library(${LIB_NAME} SHARED ${srcs})

add_subdirectory(${PROJECT_TEST_DIR})