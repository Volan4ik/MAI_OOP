# cmake_minimum_required(VERSION 3.10)

# # Устанавливаем название проекта и версии
# project(BalagurFate3 VERSION 1.0.0 LANGUAGES CXX)

# # Устанавливаем стандарт C++
# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# # Указываем пути к папкам с заголовочными файлами
# include_directories(
#     ${PROJECT_SOURCE_DIR}/include
# )

# # Находим все исходные файлы в папке src
# file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)

# # Добавляем главный исполняемый файл
# add_executable(
#     balagur_fate3
#     ${SOURCES}
# )

# # Добавляем флаги компиляции
# target_compile_options(
#     balagur_fate3 PRIVATE
#     -Wall
#     -Wextra
#     -pedantic
# )
cmake_minimum_required(VERSION 3.10)

project(test VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(
    "${CMAKE_CURRENT_SOURCE_DIR}/googletest"
    "googletest"
)

# include_directories(${PROJECT_SOURCE_DIR}/include)

set(
    TEST_SOURCES
    tests/test.cpp
    src/NPC.cpp
    src/NPCFactory.cpp
    src/BattleVisitor.cpp
    src/Observers.cpp
    include/BattleVisitor.h
    include/NPC.h
    include/NPCFactory.h
    include/Observers.h
    # src/main.cpp
)

add_executable(
    tests
    ${TEST_SOURCES}
)

target_include_directories(
    tests PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
    "${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest/include"
)

target_link_libraries(
    tests
    gtest 
    gtest_main
)

enable_testing()

add_test(NAME Seven COMMAND tests)

target_compile_options(
    tests PRIVATE
    -Wall
    -pedantic
)
