#include <string.h>

class A{
	public:
		char *mp;
		A(const char *);
		~A();
		A(const A &);
		// this is declaration of copy constructor
		// copy constructors run while class to class assigments
		// Normaly if user dosnt write a copy constructor
		// all variables are copied variable by variabl, all varaibles completely same
};

A::A(const char *name){
	mp = new char[sizeof(name)];
	strcpy(mp, name);
}

A::~A(){
	delete[] mp;
}

A::A(const A &cpy){
// definition of copy costructor
// copy constructor variables must defined with reference of class
// if directly class object is used like "A::A(A obj)"
// to asign given class to "obj" a temp object is called
// try  to assign given object to temp but for tmp a new comp constructor is run
// and for that an onother tm is created, this continues as recursive 
	// normaly if not defined a copy constructor
	// new mp is assigned as completely same address of old mp
	// In this case if new class kil then old adress is killed 
	// because same address
	// to avoid that, a copy constructror is defined and for new variable
	// new memory block is reserved and data in adress is just copied address to address 
	mp = new char[sizeof(cpy.mp)];
	strcpy(mp, cpy.mp);

}

// there are 3 types of assgiment
A a1("selcuk");
// first
A a2(a1); 
A a3 = a1; // it is same as above assigment

// second
void func(A p){
	char *c = p.mp;
}
// third
A foo(){
	A a("selcuk");
	return a;
}
A a4 = foo(); // for return value a temp A object is created 
// copy constructor is run to assign return a to temp A object
int main(void){
	
	// for 
/	func(a1);
	// if not copy constructor is defined
	// a1.mp adress would assigned to func(A p) as completely same adress
	// and when func is completed, due to deconstructor, funcs p.mp is killed
	// because they have same adress, a1.mp is killed as well
	// if user try to use a1.mp, or a1 destructor is run
	// that's code try to reach a1.mp beacuse is killed
	// it is run time error and undefined behavior

}

