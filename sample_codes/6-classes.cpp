#include <iostream>

class Date{
	int day, month, year;
};

void func1(Date adate){
	// this copy given parameter variable by variable into adate
	// this is unusal way beacue copy process is huge 
	;
}

void func2(Date *pdate){
	// just copy given adress of object
	// in the func use directly given object
	// via "->" operator
	// like pdate -> set_date(x, y, z)	
}

void func3(Date &rdate){
	// use rdate directly like normal object 
	// rdate refer to given object
}

// func2 and func3 same but reference are better to read code

int main(){
	Date *pdate;
	pdate = new Date; // Dynamic class object created
	// for above code, firtly a dynamic object is created with sizeof(Date)
	// constructor is called for dynamic object
	// adress of dynamic object assagine to pdate
	delete pdate; // before delete call destructor

	//to create array
	pdate = new Date[10]; // for each index of array, constructor is called

	delete[] pdate; // before delete destructor is called for each index of array	
}
