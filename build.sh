BUILD_PATH=./build
SOURCE_FILES="main.cpp vector.cpp vector_chain.cpp"

mkdir -p $BUILD_PATH
g++ -o $BUILD_PATH/rotary-vectors $SOURCE_FILES -g -Wall `sdl2-config --cflags --libs`
