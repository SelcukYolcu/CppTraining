#include <iostream>
#include <string.h>


class String{
	char *mp;
	public:
		String(const char*);
		~String();
		String &operator=(const String &);
		// assigment operator declaration
		void print() const;
};
String::String(const char *name){
	mp = new char[sizeof(name)];
	strcpy(mp, name);
}

String::~String(){
	delete[] mp;
}

String &String::operator=(String const &rfr){
	// for this func, "this" address is str1
	// rfr reference str2
	
	// below comprasion must be written
	// to avoid copy same object to same object
	// usually, in assgment operator, "this" objects cleaned before
	// if 2 adreses are same when you clean object you couldnt read it again 
	if (this == &rfr)
		return *this;
	
	delete[] mp;
	mp = new char[sizeof(rfr.mp)];
	strcpy(mp, rfr.mp);
	return *this;
} 

void String::print() const{
	std::cout << mp << std::endl;
}

int main(){
	String str1("selcuk");
	str1.print();
	String str2 = "yolcu";
	str2.print();
	// copy constructor is not first assigment
	// it is for already defined, created object
	// At this scope, str1 and str2 are filled objects
	// for below assigment, 
	// if there wasnt a assigment operator,
	// al str2 objects would copied to str1 campletely same
	// and when st1 is died, str2 mp is automatically killed
	// because they would have same address
	str1 = str2;
	str1.print();	
}
