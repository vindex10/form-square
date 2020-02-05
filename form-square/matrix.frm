#include form-square/functions.h

#include form-square/vars.h
Global M1 = M;

* complex conjugate (including spinors)
#call MelConjugate();

* rename indices
argument;
    id mu1?mu?nu = mu1;
endargument;

#if `DEBUG'
    Print;
#endif
.store;


#include form-square/vars.h
Global Msq = M1*M;
#call ResolveSpinors();
#if `DEBUG'
    Print;
#endif
.store
