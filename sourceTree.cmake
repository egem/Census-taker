cmake_minimum_required(VERSION 3.0)

#[[
        Census-taker
  P     |
  R     ----------PROJECT_3RD_PARTY_DIR---------3rd_party (During build process, 3rd party source will downloaded from remote repos)
  O     |
  J     ----------PROJECT_CMAKE_FILES_DIR-------cmake_files (All the cmake files will be located here except sourceTree.cmake file.)
  E     |
  C     ----------PROJECT_EXAMPLE_DIR-----------examples (This folder will be used for examples to show how to use this library.)
  T     |
  _     ----------PROJECT_INC_DIR---------------inc (Project header files will be located here)
  R     |
  O     ----------PROJECT_SRC_DIR---------------src (Project source files will be located here)
  O     |
  T     ----------PROJECT_LIB_DIR---------------lib (Output library files will be located here)
  _     |
  D     ----------PROJECT_TEST_DIR--------------test (Unit and integration tests will be located here)
  I                                             |
  R                                             ----------------unit (This folder will be used for unit tests)
                                                                |
                                                                -----------inc (Unit test header files)
                                                                |
                                                                -----------src (Unit test source files)
    
]]

set(PROJECT_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})

# Folders under Project Root Dir
set(PROJECT_3RD_PARTY_DIR ${PROJECT_ROOT_DIR}/3rd_party)
set(PROJECT_CMAKE_FILES_DIR ${PROJECT_ROOT_DIR}/cmake_files)
set(PROJECT_EXAMPLE_DIR ${PROJECT_ROOT_DIR}/examples)
set(PROJECT_INC_DIR ${PROJECT_ROOT_DIR}/inc)
set(PROJECT_SRC_DIR ${PROJECT_ROOT_DIR}/src)
set(PROJECT_LIB_DIR ${PROJECT_ROOT_DIR}/lib)
set(PROJECT_TEST_DIR ${PROJECT_ROOT_DIR}/test)

# Folders under Project Test Dir
set(PROJECT_TEST_UNIT_DIR ${PROJECT_TEST_DIR}/unit)

# Folders under Project Test Unit Dir
set(PROJECT_TEST_UNIT_INC_DIR ${PROJECT_TEST_UNIT_DIR}/inc)
set(PROJECT_TEST_UNIT_SRC_DIR ${PROJECT_TEST_UNIT_DIR}/src)
