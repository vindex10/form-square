FOR<i>M</i><sup>2</sup>
=======================

A solution to compute traces of squared matrix elements in QFT (Tree level).

How to:
-------

Run:

```
cd examples/
form -p ../form-square ee-mumu.frm
```

Now you can modify matrix element defined in the file. `-p` option is needed to
provide search path to the library.

The package operates on predefined terms (in `vars.h`):

* dirac gamma is `g` not `g_`, it will be converted at the moment of calculation
of the trace. See the issue here for details: https://github.com/vermaseren/form/issues/328

* use indices `mu1` - `muLORENTZIDXNUM` if you need some lorentz indices in the definition of your matrix element

* spinors are `u`, `ubar`, `v`, `vbar`. First argument is `fline1` - `flineLINES` which denotes fermion line. Spinors / dirac gammas with different `fline` commute.

* feel free to define your own symbols for propagators or coefficients. FORM doesn't like denominators.

* notice, `qIDX` is reserved for propagators, but there is no any convenience yet.


TODO:
-----

Sum over external vector polarizations is not supported yet.


References:
-----------

* FORM main page: https://www.nikhef.nl/~form/
* Mostly used tutorial: https://www.nikhef.nl/~form/maindir/documentation/tutorial/online/online.html
* Example is taken from M. Peskin, D. Shroder book.
