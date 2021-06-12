BUILD_PATH=./build
SOURCE_FILES=main.cpp

g++ -o $BUILD_PATH/rotary-vectors $SOURCE_FILES -g `sdl2-config --cflags --libs`
