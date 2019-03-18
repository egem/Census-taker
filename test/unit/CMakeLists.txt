cmake_minimum_required(VERSION 3.0)

enable_testing()

include(${PROJECT_CMAKE_FILES_DIR}/ossGoogleTestProject.cmake)

set(INC_DIRS ${PROJECT_INC_DIR}
             ${PROJECT_TEST_UNIT_INC_DIR}
             ${GOOGLE_TEST_INC_DIRS})

set(SRC_DIRS ${CMAKE_CURRENT_LIST_DIR}/src)

include_directories(${INC_DIRS})
link_directories(${CMAKE_CURRENT_BINARY_DIR})

add_executable(testUserManager ${SRC_DIRS}/testUserManager.cpp)
add_dependencies(testUserManager ${GOOGLE_TEST_DEPENDENCIES})

target_link_libraries(testUserManager   ${LIB_NAME})
target_link_libraries(testUserManager   ${GOOGLE_TEST_GTEST_LIB_NAME})

add_test(   NAME        testUserManager
            COMMAND     testUserManager)

add_custom_command(TARGET testUserManager
                       POST_BUILD
                       COMMAND testUserManager
                       WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
                       COMMENT "Running tests" VERBATIM)