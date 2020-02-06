#procedure MelConjugate()
*
* Conjugate dirac spinors and change i_ to -i_.
* NOTE: complex numbers assumed to be explicit. Conjugation does not propagate.
*
    id ubar?antipart[S1](i1?, p1?)*u?part[S2](i1?, p2?) = antipart[S2](i1, p2)*part[S1](i1, p1);
    id ubar?antipart[S1](i1?, p1?)*g(i1?, i2?)*u?part[S2](i1?, p2?) = antipart[S2](i1, p2)*g(i1, i2)*part[S1](i1, p1);
    id ubar?antipart[S1](i1?, p1?)*g(i1?, i2?)*g(i1?, gIdx5)*u?part[S2](i1?, p2?) = antipart[S2](i1, p2)*g(i1, i2)*g(i1, gIdx5)*part[S1](i1, p1);
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


#procedure ResolveSpinors()
*
* Replace spin sums
* Replace fake gamma matrices with g_
* Do traces
* Contract
*
* NOTE: since we contract respecting spinor line indices, no need to reorder spinors
*
    #call ReplaceSpinSums;
    id g(fline1?, gIdx5) = g_(fline1, 5_);
    id g(fline1?, mu1?) = g_(fline1, mu1);
    id g(fline1?) = g_(fline1);
    #do i = 1,`LINES'
        trace4 fline`i';
    #enddo;
    contract;
#endprocedure
