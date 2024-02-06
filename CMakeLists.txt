cmake_minimum_required(VERSION 3.16)
project(md2html C)

set(CMAKE_C_STANDARD 11)

find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

BISON_TARGET(MyParser parser.y ${CMAKE_CURRENT_BINARY_DIR}/parser.c)
FLEX_TARGET(MyScanner scanner.l ${CMAKE_CURRENT_BINARY_DIR}/scanner.c)
ADD_FLEX_BISON_DEPENDENCY(MyScanner MyParser)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(md2html
        AstNodeDefinition.h
        MdDocument.c
        AstNode.c
        MdHeading.c
        MdText.c
        ${BISON_MyParser_OUTPUTS} ${FLEX_MyScanner_OUTPUTS}
        main.c
        MdParagraph.c
)

enable_testing()

file(GLOB TEST_DIRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/tests ${CMAKE_CURRENT_SOURCE_DIR}/tests/*)

foreach(TEST_DIR ${TEST_DIRS})
    set(TEST_INPUT ${CMAKE_CURRENT_SOURCE_DIR}/tests/${TEST_DIR}/in)
    set(TEST_OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/tests/${TEST_DIR}/out)
    add_test(NAME ${TEST_DIR} COMMAND md2html ${TEST_INPUT} ${TEST_OUTPUT}.html)
endforeach()

