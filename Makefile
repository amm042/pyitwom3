
CC=g++
LD=ld

all: libitwom3.0.so test pyitwom3.so

itwom3.0.o: itwom3.0.cpp
	# try to vectorize, doesn't seem to be getting any
	# also enable fast math which takes a lot of floating point shortcuts
	#$(CC) -fpic -O3 -ftree-vectorize -ftree-vectorizer-verbose=2 -mavx2 -ffast-math -c itwom3.0.cpp
	$(CC) -fpic -O3  -ftree-vectorize -ftree-vectorizer-verbose=2 -mavx2 -march=x86-64 -mcmodel=medium -pipe -fomit-frame-pointer -ffast-math -c itwom3.0.cpp


pyitwom3.so: itwom3.0.cpp itwom3.0.h pyitwom3.i itwom3.0.o
	swig -c++ -python pyitwom3.i
	$(CC) -fpic -march=x86-64 -mcmodel=medium -pipe -fomit-frame-pointer -ffast-math -I/usr/include/python3.5 -c pyitwom3_wrap.cxx
	$(CC) -shared itwom3.0.o pyitwom3_wrap.o -o _pyitwom3.so

libitwom3.0.so: itwom3.0.o
	$(CC) -shared itwom3.0.o -o libitwom3.0.so

test: test.cpp libitwom3.0.so
	# rpath adds current directory to shared library search path
	$(CC) -Wall -g -o test test.cpp -Wl,-rpath=. -L. -litwom3.0 -lm

clean:
	rm -rf *.o *.so test pyitwom3.py pyitwom3_wrap.*

