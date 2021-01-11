#include <iostream>

using namespace std;

double foo(int x = 20, char y = 'A', double z = 3.14);
// default values are defined at decleration of func
// Definition is later, 
double foo(int x, char y, double z){
	return x+y+z;
}

int foo2(int x, int y = 30, int z =40);
// If any parameter is assigned as default
// right parameters must take default value
// below is not valid decleration
// int foo2(int x = 20, int y, int z);

int foo3(int x = 20, int y = 30, int z =40);
// A parameter must be assigned only once as default
// If assiginment is twice in same code,
// İt is not a valid code like below 
// int foo3(int x, int y = 50, int z){ ... }
int foo3(int x, int y, int z){
	return x+y+z;
}

void putChar(const char *p = "Succes"){
	// pointer parameters can take a default value
	cout << p;
}
// and also it can be  refrence
char c = 'C';
void putchar(char &r = c){
	cout << c;
}

void foo4(int x = foo()){
	//a default value can be a func
}

// Default values can define separetly 
// But it must be right to left
int foo5(int x, int y, int z, int k = 30);
int foo5(int x, int y = 10, int z = 20, int k);
int foo5(int x = 1, int y, int z, int k){
	return 0;
}

// the funcs parameters haven't to take name at decleration
// like that int foo6(int, int, char)
// It can take a default value aswell
int foo6(int, int = 20, char = 'A');
int foo6(int a = 10, int b, char c){
	return 0;
}
// But any parameter is a pointer be careful
// int foo7(const char *= "Hello")
// this gives an eror becaues *= has different mean
// it must be seperate 
int foo7(const char * = "Hello"){
	return 0;
}


int main(void){
	foo(20,30); // for double z, default value is assigned
	// If any value is called as default
	// rigth vlues must be called as default
	// below is not valid
	// foo(, 20, 30);
	return 0;
}
