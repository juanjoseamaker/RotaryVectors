BUILD_PATH=./build
SOURCE_FILES="main.cpp vector.cpp"

mkdir -p $BUILD_PATH
g++ -o $BUILD_PATH/rotary-vectors $SOURCE_FILES -g `sdl2-config --cflags --libs`
