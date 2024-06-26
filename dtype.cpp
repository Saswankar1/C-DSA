// integrer take 4byte to store, characters take 1 byte in the memory
// Data Type: Primitive(int, float,etc), Derived(funct, array,etc), User-defined(Class, structure,etc)
/* int
    - if we have n bits, max number formed using those bits is (2^n)-1
    - in memory we use MSB to represent the number if its negative(1) or positive(0)
    - range: unsigned(0 to (2^n)-1)     signed: -2^n-1 to 2^n
*/ 
/*Float
    - float-> store upto 7 decimal digits(size:4byte)
    - double-> store upto 15 decimal digits(size:8byte)
*/
// bool has 1byte size
/*
    type modifiers(modify the datatype size)
        - signed(4bytes)
        - unsigned(4 bytes)
        - long(8 bytes)
        - short(2 bytes)
*/ 
#include<iostream>
using namespace std;

int main() {

    int a;
    a=12;
    cout<<"size of a"<<sizeof(a)<<endl;

    float f;
    cout<<"size of float"<<sizeof(f)<<endl;

    char c;
    cout<<"size of char"<<sizeof(c)<<endl;

    bool b;
    cout<<"size of bool"<<sizeof(b)<<endl;

    short int si;
    long int li;
    cout<<"size of shortint"<<sizeof(si)<<endl;
    cout<<"size of longint"<<sizeof(li)<<endl;

    return 0;
}