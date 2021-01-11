#include <iostream>

class Date{
	int day, month, year;
	public:
	int get_day(void) const; // const definition
	// this const funcs are for just classes not global
	int get_month(void);
	int *get_adr(void) const;
	// constructor and deconstructor couldnt be defined as const
	// because their goal is to set or unset variables
};

int Date::get_day(void) const{ // const definition must be at both func definition and decleration
	// in const functions variables of class couldnt be changed
	// it is just to read variable
	// 
	// in the const func, a func which is not const couldn't be called
	// this -> get_month(); -- is not valid
	return day;
}

int Date::get_month(void){
	// all class funcs take a hidden varibale, it is "this"
	// Actually "this" is "Date *const this" 
	// In const funcs "this" is "const Date *const this"
	return month;
}

int *Date::get_adr(void) const{
	// because func is const
	// taken "this" adress is evalauted as "const this"
	// return type of this func is "int *"
	// because of above reasons, below return is not valid
	// return *this; -> "this" is const Date *, return is int* 
}


