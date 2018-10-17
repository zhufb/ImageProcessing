CMAKE_MINIMUM_REQUIRED( VERSION 2.8 )

PROJECT( ImageProcessing )

INCLUDE_DIRECTORIES( main.hpp Processing.hpp )

ADD_EXECUTABLE( my_DIP main.cpp Processing.cpp )
