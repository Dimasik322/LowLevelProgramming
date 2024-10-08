cmake_minimum_required(VERSION 3.11)

project(lowlevelprogramming CXX)

set(CMAKE_CXX_STANDARD 23)

# Специфичные настройки для компилятора Visual Studio
if(MSVC)
    # Генерируем статическую заглушку для динамических библиотек
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS true)

    # Включаем высокий уровень предупреждений
    if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif()
endif()

# Объявляем библиотеку
add_library(lowlevelprogramming SHARED "include/lab1/lab1.h" "src/lab1.cc")
target_include_directories(lowlevelprogramming PUBLIC "include")

# Ну и мою менюшку тоже объявить надо
add_executable(main "main/main.cc" "include/lab1/lab1.h")
target_link_libraries(main lowlevelprogramming)