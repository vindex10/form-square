* define number of fermionic lines (minimal)
#define LINES "2"

* define number of lorentz indices being used in M
#define LORENTZIDXNUM "10"


* include required variables, see descriptions in the vars.h
#include vars.h

* define custom symbols (irrelevant to Tr(M^2) computation) used in M
Symbol e;
Symbol [photon prop];

* define matrix element
Global M = vbar(fline1, p2) * i_ * e * g(fline1, mu1) * u(fline1, p1) * (-i_*d_(mu1, mu2)*[photon prop]) * ubar(fline2, p4) * (i_*e*g(fline2, mu2)) * v(fline2, p3);

* contract possible einstein symbols (eliminates metric tensor for instance, if possible)
contract;

Print;
.store;


* load this to compute Tr(M^2). Result is saved to Msq
#include matrix.frm
* NOTE: .end command is not called inside. If you want to stop here, call it below:
* .end;


* postprocessing. just to simplify result according to Peskin.
#include vars.h

Symbol [photon prop];
Symbol mMu;
Symbol k;

Local Peskin = Msq/4;

id m(p1) = 0;
id m(p2) = 0;
id m(p3) = mMu;
id m(p4) = mMu;
id [photon prop] = 1/k^2;
bracket e, k;

Print;
end.
