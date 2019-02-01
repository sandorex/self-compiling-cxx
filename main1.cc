# if 0
# Made by SandoreX
# https://git{la,hu}b.com/sandorex

# compile the file
g++ -o $0.out -xc++ $0

# run executable
./$0.out $@

# remove executable
rm ./$0.out

# exit before trying to run c++
exit
# endif

#include <iostream>

int main() {
	std::cout << "hello world!\n";
	return 0;
}
