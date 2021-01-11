#include <iostream>

class Date{
	int day, month, year;
	mutable bool flag; // this variable can be changed even in const
	public:
	int pub;
	Date(int, int, int);
	int get_day(void) const; 
	int get_day(void); 
	int get_month(void);
};

Date::Date(int day, int month, int year){
	Date::day = day;
	Date::month = month;
	Date::year = year;
}

// 2
// Const funcs can be overloaded
// And which func called is detected avording to given "this" type
// If "this" type is const Date *, then const func is called
int Date::get_day(void) const{ //const
	Date::flag = false;
	return day;
}
// ıf "this" type is Date * then normal func is called     
int Date::get_day(void) { // not const
	Date::flag = true;
	return day;
}

int Date::get_month(void){
	return month;
}

int main(void){
	const Date birth(10, 12, 1991);
	// 1
	// because birth is const object
	// all birth variables is const
	// birth.pub = 10; is not valid
	// and also const class objects can call only const funcs
	// birth.get_month(); this code not valid, because get_month is not const
	// get_month's "this" is Date* not const but birth's "this" is const Date*
	// const Date * cannot be assigned to Date *
	// However, Destructors adn constructors are execptio
	// Constructor set all of variables while object is created
	
	//3
	Date exam(1, 6, 2020);
	birth.get_day(); // This calls const get_Day func because birth is const	
	exam.get_day(); // this calls normal get_Day func because birth is NOT const
}
