[main1.cc](./main1.cc): has no shebang and is recognized as C source so it may be required to run it with sh `sh ./main2.cc`  
[main2.cc](./main2.cc): is basically a script that exits before c++ code starts


# HOW
i wrapped shell script in `#if 0` and well '#' is comment in shell so it worked out nicely.  

what is different between main1 and main2 is that main1 is recognized as c source and is completely valid syntax-wise but main2 has shebang which is unknown preprocessor directive

main1 works by running g++ on itself with flag `-xc++` which tells g++ that its c++ code  
**NOTE: main1 in some cases must be run using `shell ./main1.cc` but usually shell is default interpreter for files without shebang**
```sh
g++ $@ -xc++ -o $0.out $0
```

main2 works by first cutting of shebang (`#!/bin/sh`) from itself and then piping it to g++ which uses stdin to get input (also uses `-xc++`)  
```sh
tail -n+2 $0 | g++ $@ -o $0.out -xc++ -
```

