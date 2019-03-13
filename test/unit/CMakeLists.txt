cmake_minimum_required(VERSION 2.8)

include(${PROJECT_CMAKE_FILES_DIR}/ossGoogleTestProject.cmake)

set(INC_DIRS ${PROJECT_INC_DIR}
             ${GOOGLE_TEST_INC_DIRS})

set(SRC_DIRS ${CMAKE_CURRENT_LIST_DIR}/src)

include_directories(${INC_DIRS})

add_executable(deneme ${SRC_DIRS}/deneme.cpp)
add_dependencies(deneme ${GOOGLE_TEST_DEPENDENCIES})

target_link_libraries(deneme   ${LIB_NAME})
target_link_libraries(deneme   ${GOOGLE_TEST_GTEST_LIB_NAME})

add_test(NAME testDeneme 
        COMMAND deneme)

add_custom_target(  tests 
                    COMMAND ${CMAKE_CTEST_COMMAND}
                    DEPENDS deneme)
enable_testing()