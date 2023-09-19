project (CPP-LAB-2
        LANGUAGES C) # Используем язык C
cmake_minimum_required(VERSION 2.8.12) # Минимальная допустимая версия CMake
add_executable (lab2 main.c) # Бинарный файл находится в build/helloWorld
add_compile_options(-Wall -Wextra -Wpedantic) # Опции компиляции для предупреждений
set_property(TARGET lab2 PROPERTY C_STANDARD 99) # Используем стандарт C99
set(EXECUTABLE_OUTPUT_PATH ..) # Путь скомпилированной программы