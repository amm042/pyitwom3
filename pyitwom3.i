%module pyitwom3
%include "carrays.i"
%array_class(double, doubleArray);
%include "cpointer.i"
%pointer_class(double, doublep);
%pointer_class(int, intp);
%include "cstring.i"
%cstring_bounded_output(char *strmode, 1024);

%{
	#include "itwom3.0.h"
%}



%include "itwom3.0.h"