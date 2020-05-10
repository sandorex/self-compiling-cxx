# Self Compiling CXX
Experiment to make a C++ source code compile by running the file itself

## Versions
[First Version](./main1.cc): has no shebang and is recognized as C source so it may be required to run it with sh `sh ./main2.cc`  
[Second Version](./main2.cc): is basically a script that exits before C++ source code starts

# How It Works
I wrapped shell script in `#if 0` and well '#' is comment in shell so it worked out nicely.  

What is different between v1 and v2 is that v1 is recognized as c source and is completely valid syntax-wise but v2 has shebang which is unknown preprocessor directive

v1 works by running g++ on itself with flag `-xc++` which tells g++ that its c++ code  
**NOTE: v1 in some cases must be run using `shell ./main1.cc` but usually shell is default interpreter for files without shebang**
```sh
g++ $@ -xc++ -o $0.out $0
```

v2 works by first cutting of shebang (`#!/bin/sh`) from itself using tail and then piping it to g++ which uses stdin to get input (also uses `-xc++` so it knows it's input is c++ source code)  
```sh
tail -n+2 $0 | g++ $@ -o $0.out -xc++ -
```

