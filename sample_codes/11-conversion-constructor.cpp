#include <iostream>

class Account{
	private:
		int accNo;
		double balance;
	public:
		Account(double);
		// a func which get only one parameter or the other parameters have default value
		// the func is a conversion constructors
		// this command is decleration of func
};

Account::Account(double point){
	// definition of func
	Account::balance = point;
}

void func(Account p){
	;
}

Account foo(){
	double x;
	return x;
	// while it return x
	// it creates a temp Account object
	// and it runs the conversion constructor to make return type Account
	// and pass double x value as Account type  to return tmp object
	// via Copy constructor
}

int main(void){
	Account a1 = 200.; // It is like a1 = Account(200.) or (Account)200.
	Account a2(400.); // its same as a1
	a1 = 300.; // this is operator overloading a1.operator = Account(300.)
	func(200); // it pass value to func as Account(200)
		   // but first it convert 200 to double then double to Account(double)
		   // it is same func(Account(double(200)))
	// All of below conversions Automatic conversion
	// because there is no Account() or (Account) words on front of the values
		  
	// However, Sometimes automatic type conversion not acceptable for designer
	// to avoid automatic type conversion
	// there is key word "explicit"
	//
	// If conversion constructor was declerated as 
	// "explicit Account(double):"
	//then, All below main command would unvalid
	//they would have to be like this:
	//"Account a1 = Account(200); ect.
	//
	// "explicit" key word ONLY written in DECLERATION
	
	return 0;
}
