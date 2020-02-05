#include functions.h

#include vars.h
Global M1 = M;

* complex conjugate (including spinors)
#call MelConjugate();

* rename indices
argument;
    id mu1?mu?nu = mu1;
endargument;

Print;
.store;


#include vars.h
CFunction m;
Global Msq = M1*M;
#call ResolveSpinors();
Print;
.store
