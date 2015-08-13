# RcppLogger

Simple logging framework for Rcpp.

## Usage

After installing the package,

```
install_package("devtools")
library("devtools")
install_github("njanetos/RcppLogger")
```

include the header file `RcppLogger.h` somewhere.

If you want to use RcppLogger as part of a package, put the line
```
LinkingTo: RcppLogger
```
in your `DESCRIPTION` and then include the header file in your C++ code using `#include <RcppLogger.h>`.

Here is an example of how to use the logger:

```
#include <RcppLogger.h>
using namespace RcppLogger;
logger log;
log.configure(ALL);

log.info() << "General information";
log.warning() << "This is a warning.";
log.error() << "This is an error.";

log.configure(QUIET);

log.info() << "This won't be displayed.";

log.configure(WARNING);
log.info() << "This won't be displayed";
log.warning() << "This will, along with errors.";
```
