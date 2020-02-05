#procedure SpinorLineToLeft(i)
*
* Push spinors corresponding to line `i'
* to the left
*
    repeat;
        id u?particles(flineX?!{fline`i'}, p1?)*v?particles(fline`i', p2?) = v(fline`i', p2)*u(flineX, p1);
        id u?particles(flineX?!{fline`i'}, p1?)*g(fline`i', mu1?) = g(fline`i', mu1)*u(flineX, p1);
        id g(flineX?!{fline`i'}, mu1?)*u?particles(fline`i', p1?) = u(fline`i', p1)*g(flineX, mu1);
        id g(flineX?!{fline`i'}, mu1?)*g(fline`i', nu1?) = g(fline`i', nu1)*g(flineX, mu1);
    endrepeat;
#endprocedure

#procedure MelConjugate
*
* Conjugate dirac spinors and change i_ to -i_.
* NOTE: complex numbers assumed to be explicit. Conjugation does not propagate.
*
    id ubar?antipart[S1](i1?, p1?)*g(i1?, i2?)*u?part[S2](i1?, p2?) = antipart[S2](i1, p2)*g(i1, i2)*part[S1](i1, p1);
    id i_ = -i_;
#endprocedure


#procedure ReplaceSpinSums()
*
* Replace spin sums of dirac spinor products
*
    id ubar?antipart(fline1?, p1?) = 1;
    id u(fline1?, p1?) = g(fline1, p1) + m(p1)*g(fline1);
    id v(fline1?, p1?) = g(fline1, p1) - m(p1)*g(fline1);
#endprocedure


#procedure ResolveSpinors
*
* Group spinors by lines they contribute to (respect non-commutativity)
* Replace spin sums
* Replace fake gamma matrices with g_
* Do traces
* Contract
*
    #do i = `LINES',1,-1
        #call SpinorLineToLeft(`i');
    #enddo;
    #call ReplaceSpinSums;
    id g(fline1?, mu1?) = g_(fline1, mu1);
    id g(fline1?) = g_(fline1);
    #do i = 1,`LINES'
        trace4 fline`i';
    #enddo;
    contract;
#endprocedure
