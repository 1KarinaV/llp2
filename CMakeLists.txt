cmake_minimum_required(VERSION 3.10)

project(lab2 VERSION 1.0 LANGUAGES C)

set(SRC_DIR ".")
set(PARSER_DIR "${CMAKE_CURRENT_BINARY_DIR}")

find_package(FLEX 2.6 REQUIRED)
find_package(BISON 2.3 REQUIRED)
find_package(json-c CONFIG)

set(LEXER_OUT "${PARSER_DIR}/lexer.c")
set(PARSER_OUT "${PARSER_DIR}/parser.c")

flex_target(LEXER "${SRC_DIR}/lexer.l" "${LEXER_OUT}" DEFINES_FILE "${PARSER_DIR}/lexer.h")
bison_target(PARSER "${SRC_DIR}/parser.y" "${PARSER_OUT}" DEFINES_FILE "${PARSER_DIR}/parser.h" COMPILE_FLAGS "-d -v")
add_flex_bison_dependency(LEXER PARSER)

file(GLOB source_files
        ${CMAKE_CURRENT_SOURCE_DIR}/*.c
        )

add_executable(lab2 "${source_files}" "${SRC_DIR}/main.c" "${LEXER_OUT}" "${PARSER_OUT}" vector.c )
target_include_directories(lab2 PRIVATE ${PARSER_DIR} ${SRC_DIR})

target_link_libraries(lab2 m)
target_link_libraries(lab2 json-c::json-c)