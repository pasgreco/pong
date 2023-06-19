project(pong)

# CMake 3.* necessario per Qt
cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

# ottengo tutti i sorgenti 
file(GLOB my_sources *.h *.cpp *.qrc *.ui)

# attivo il Resource Compiler (RCC)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


# aggiungo eseguibile
add_executable(pong ${my_sources})
#set_property(TARGET helloworld2 PROPERTY POSITION_INDEPENDENT_CODE FALSE)

# verifico l'esistenza delle librerie di Qt che mi servono
find_package(Qt6Widgets REQUIRED)

# collego l'eseguibile con le librerie
target_link_libraries(pong Qt6::Widgets)

#set (CMAKE_EXE_LINKER_FLAGS -no-pie)



