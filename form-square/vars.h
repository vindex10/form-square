* vectors used for external lines
AutoDeclare Vector p;

* vectors used in propagators
AutoDeclare Vector q;

* indices to be used in functions (dummy)
AutoDeclare Index i;
* symbols to be used in functions (dummy)
AutoDeclare Symbol S;

* used for gamma matrices
Function g;

* used for masses of external particles m(p1)
CFunction m;

* external spinors. ubar(flineIdx, p1)
Function u, ubar, v, vbar;
Set particles: u, ubar, v, vbar;
Set part: u, v;
Set antipart: ubar, vbar;

* indices to be used for numerating fermion lines
#do i=1,`LINES';
    Index fline`i'=0;
#enddo
Index flineX;

* lorentz indices
Index mu1, ..., mu`LORENTZIDXNUM';
Index nu1, ..., nu`LORENTZIDXNUM';

Set mu: mu1, ..., mu`LORENTZIDXNUM';
Set nu: nu1, ..., nu`LORENTZIDXNUM';
