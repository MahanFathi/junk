swig -python -c++ -Isrc kir.i

clang++ -Isrc -fPIC -c $(pkg-config --cflags --libs python3) src/Kir.cpp kir_wrap.cxx

clang++ -shared -o _kir.so Kir.o kir_wrap.o

python -c "from kir import Kir"
