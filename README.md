# RcppLogger

Simple lightweight header-only logging framework for Rcpp. Lets you chain stuff together using the standard `<<` notation. Not threadsafe.

## Usage

After installing the package,

```{r}
#install_package("devtools")
devtools::install_github("njanetos/RcppLogger")
```

include the header file `RcppLogger.h` somewhere.

If you want to use RcppLogger as part of a package, put the line
```
LinkingTo: RcppLogger
```
in your `DESCRIPTION` and then include the header file in your C++ code using `#include <RcppLogger.h>`.

Here is an example of how to use the logger:

```{c++}
#include <RcppLogger.h>
using namespace RcppLogger;
logger logg(ALL);

logg.info() << "General information";
logg.warning() << "This is " << "a warning.";
logg.error() << "This is an error.";

logg.configure(QUIET);

logg.info() << "This won't be displayed.";
logg.warning() << "Neither will this.";
logg.error() << "This also won't be displayed.";

logg.configure(WARNING);

logg.info() << "This won't be displayed";
logg.warning() << "This will.";
logg.error() << "Errors will be displayed as well.";
```

Output:

```{r}
[INFO] General information
[WARNING] This is a warning.
[ERROR] This is an error.
[WARNING] This will.
[ERROR] Errors will be displayed as well.
```
