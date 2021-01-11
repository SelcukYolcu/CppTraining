#include <iostream>

class Date{
	public:
		Date(); // Default Constructor
		// instead o Date(), If there was Date(int = 10, char = 'S')
		// It would be default. They are cannot define in same class
		Date(int, int, int); // Overloaded constructor
		Date(const char *); // Overloaded constructor
		~Date(); // Destructor
		// Destructors can not be overloaded, it is declared only once
		// Destructors call when the object killed
	private:
		int day, month, year;
};

// There is no return type of constructor, Even void
// It is defined as "calss name"::"calss name"
Date::Date(){
	;
}

Date::Date(int day, int month, int year){
	Date::day = day;
	Date::month = month;
	Date::year = year;
}

Date::Date(const char *mes){
	;
}

Date::~Date(){
	;
	// usually destructors are used to delete memory blocks
	// which reserved in the class methods using malloc or new
	// Use in destructor delete or free according to reserving
}

int main(void){
	Date adate(6, 1 ,1996); // call Date(int, int, int) constructor
	Date bdate("Nan"); // If constructor has only one paremeter then " = " is can be used 
	Date cDate = "Nan"; // like that it same like above definition
	Date ddate ; // Default constructor is called
	// Constructors can not be called extarnly
	// They are only called by compiler when object is created
	// ddate.Date("Nan") -> it is invalid
	
	Date *pdate;  // While pointer or referans are created
	pdate = &adate; // Constructor is not called 
	Date &rdate = bdate; // Because there is no object creation 

}
