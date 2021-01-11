#include <iostream>
// 1
class A{
	int aa; // This variable is private
	// Default block is Private
	private:
		int a = 2;
		// funcs declared in class
		// But definition is out of class
		void func1(); 
	protected:
		int b;
	public:
		double c;
		int func2(int);
	private: // Any block can opened many times 
		int aaa;
};

// 2
void A::func1(void){
	// Definition of class function
	; // pass
	// 7
	// Actuall for each function
	// Even function hasnt a parameter
	// Every function has a hidden parameter
	// It is this
	// func1(this) -> "this" is adress af class
	// using this class adress varaibles of class are reachable
	this -> a = 4;
	// "this" is a const pointer
	//  func(A *const this), here is exact hidden parameter
	std::cout << this << std::endl; // it shows adress of A class object for which A object is created
	A *p1;
	p1 -> func2(10); // it is that func2(this(for p1 adress), 10)
	// INFO, Cause  p1 is defined as local, It has garbage adress	
	p1 = this; // "this" points which object call func1 in main
	// A a_th(); has "return *this" it is value of class object
	// A *a_th(); has "return this" it is point of class object
	// A &a_th; has "return *this" it is directly class object
}

// 3
int A::func2(int af){
	// Definition of class function
	return (af*a);
	//6
	// before read here check a2.func2(10) section
	// class functions can use calss' private variables
	func1(); // call is valid here
	A a4;
	a4.a = 2; // this is valid because a4 is created in member function
}
// 4
// Both of below code is valid
// But using class tag is NOT preferred
int main(void){
	class A a;
	A a2, a3;
	// 5
	a2.c = .5; // Call class function
	// a2.func1() -> this call is invalid cause it is private
}
