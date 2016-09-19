# pyitwom3
python wrapper to itwom rf propagation model.

### example:
```
$ make
g++ -Wall -g -o test test.cpp -Wl,-rpath=. -L. -litwom3.0 -lm
swig -c++ -python pyitwom3.i
g++ -fpic -march=x86-64 -mcmodel=medium -pipe -fomit-frame-pointer -ffast-math -I/usr/include/python3.5 -c pyitwom3_wrap.cxx
g++ -shared itwom3.0.o pyitwom3_wrap.o -o _pyitwom3.so
$ python3 pyitwom3_example.py 
Using ITWOM Version: 3.0
dbloss:    90.44, mode: L-o-S, errno: 4
```

This output is consistent with the test.cpp native call.

