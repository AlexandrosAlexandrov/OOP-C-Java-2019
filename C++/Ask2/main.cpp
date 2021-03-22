#include <iostream>
#include "Objects.h"
#include "Objects.cpp"
#include <time.h>

using namespace std;

void clone_encrypt_and_print(Object& obj1){
	srand (time(NULL));	
	
	Object obj2	= obj1.clone(obj1);
	if(obj1.equal(obj2))
		cout << "Objects are equal" << endl;
	if(obj1.identical(obj2))
		cout << "Objects are identical" << endl;
		
	String s1("string1");
	s1.print();
	String s2("string2");
	s2.print();
	
	s1.concat(s2.getstr());
	cout << s1.length() << endl;
	s1.clear();
	cout << s1.length() << endl;
}

int main()
{
	Object obj;
	clone_encrypt_and_print(obj);
	
	String e1("Security");
	String e2("Maintenance");
	String e3("Cleaning");
	
	Plane plane;
	SecurityEmployee security(e1);
	MaintenanceEmployee maintenance(e2);
	CleaningEmployee cleaning(e3);
	
	plane.process(security.getname(), maintenance.getname(), cleaning.getname());
	
	plane.ready_check();
}
