/* file: kir.i */
%module kir

%{
/* include C++ header files necessary to compile the interface */
#include <vector>
#include "src/Kir.h"
%}

%include "std_string.i"
%include "std_vector.i"
%include "typemaps.i"

namespace std
{
   %template(FloatVector) vector<float>;
}


%include "src/Kir.h"
