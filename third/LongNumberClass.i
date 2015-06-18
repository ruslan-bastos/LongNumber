%module LongNumberClass
%{
/* Includes the header in the wrapper code */
#include "LongNumberClass.h"
%}


/* Parse the header file to generate wrappers */
%include "LongNumberClass.h"
