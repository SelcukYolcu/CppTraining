#include <iostream>

int a = 10; // global a

class Date{
	public:
		void set_date(int, int, int);
	private:
		int day, month, year;
};

int main(void){
	int a = 30; // main's a
	{
		int a = 30; // block's a
		std::cout << ::a << std::endl;
		// it writes 10 because :: points the global one
	}
	
}

void Date::set_date(int day, int month, int year){
	Date::day = day;
	Date::month = month;
	Date::year = year;
	// Date::xxx variables are class' private variables
}
