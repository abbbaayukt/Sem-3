# include <iostream> // C++ 11 std <.h>  io related functions 
using namespace std; // namespace - IO libraries - global namespace of C++ 
int main ()  // main is a library function
{
int i;
float f;
char s [80];
cout << " Enter an integer , float , and string : "; //  << 
cin >> i >> f >> s;  // >> 
cout << " Here 's your data : ";
cout << i << ' ' << f << ' ' << s;
return 0;
}

// sample.cpp
// gcc -save-temps sample.cpp
// sample.i  - preprocessed file 
// sample.s - assembled file (.s - linux platform) 
// sample.o  - object file 
// a.out - executable 
// loader puts a.out (Secondary storage)  into the RAM
// processor runs it 
//# define x 15  - x is replaced by 15
//conditional compilation 
// sample.i is given to g++ 
// g++ translates to sample.s - assembly language instructions -X64 bit intel 
// gas - GNU Assembler -sample.s - sample.o - gas is a part of g++ 
// linker (ld.a /ld.so) sample.o + library files => a.out 
// loader loads a.out - RAM 
// glibc.a and program are combined together
// glibc.so 
