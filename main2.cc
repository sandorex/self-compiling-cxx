#!/bin/sh
# if 0
# Made by SandoreX
# https://git{la,hu}b.com/sandorex

# cut off shebang and pipe to g++
tail -n+2 $0 | g++ -o $0.out -xc++ -

# run executable
./$0.out $@

# remove executable
rm $0.out

# exit before trying to run c++
exit
# endif

#include <iostream>

int main() {
	std::cout << "hello world!\n";
	return 0;
}
