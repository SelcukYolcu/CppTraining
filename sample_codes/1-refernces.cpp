%:include <stdio.h>
%:include <iostream>
using namespace std;

struct reference<%
    int x;
    int y;
%> ref;
void foo(const reference &r)<%
   cout << "2 - " << r.x << endl;
   // references' object can be reached by "."
%>

int &func(void){
    // İf return value type of a func is a reference 
    // then func returns directly variable
    return ref.x;
    // In this usage, return value must be global
    // otherwise the func returns a garbage variable
}	

int main()
<%
    char arr<:10:>;
    char &rarr1 = *arr; // rarr1 refer to first byte of arr[]
    char (&rarr)<:10:> = arr; // This refer to all array
    cout << "1 - "  <<  sizeof(rarr) << endl;

    int a = 10;
    rarr1 = a; // write 10 to first byte of arr[]
    // rarr1 is same for const ptr
    // if rarr1 is defined as pttr
    // it would be char *const rarr1 = arr(arr is already first adress of array)
    
    const int &ra = a;
    // a can't be changed via ra refernce
    // ra is just to read a
    // it is same "const int *const ra = &a;"
    
    const int b = 20;
    // int &rb = b; this give an error 
    // because b is const so rb must be const
    const int &rb = b;

    // char &cra = a;
    // this gives an error
    // because types are not same
    // char &cra =(char)a; also not work
    char c = 'C';
    char &cra = c;
    
    ref.x = 20;   
    foo(ref);
    // structs can be used as reference aswell
    
    func() = 40;
    // func refers to ref.x, then 40 is writen to ref.x 
    cout << "3 - " << ref.x << endl;

    return 0;
%>

