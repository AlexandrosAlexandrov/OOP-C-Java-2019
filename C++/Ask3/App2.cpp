
#include <iostream>
#include "Objects.h"
#include <time.h>

using namespace std;

int Object::id = 0;

void clone_encrypt_and_print(Object& obj1) {
	cout << "CLONE ENCRYPT AND PRINT" << endl << "--------------------------------------------------------" << endl;
	Object obj2 = obj1.clone(obj1);
	if (obj1.equal(obj2))
		cout << "Objects are equal" << endl;
	if (obj1.identical(obj2))
		cout << "Objects are identical" << endl;

	String s1("string1");
	s1.print();
	String s2("string2");
	s2.print();

	s2.updateAt(1, '!');
	s2.print();

	s1.concat(s2);
	s1.print();
	cout << s1.length() << endl;
	s1.clear();
	cout << s1.length() << endl;

	cout << "--------------------------------------------------------" << endl << endl;
}

int main()
{
	Object obj;
	clone_encrypt_and_print(obj);

	cout << endl << "MAIN" << endl << "--------------------------------------------------------" << endl;

	String e1("Security");
	String e2("Maintenance");
	String e3("Cleaning");

	Plane plane;
	SecurityEmployee security(e1);
	MaintenanceEmployee maintenance(e2);
	CleaningEmployee cleaning(e3);

	plane.process(security, maintenance, cleaning);
	plane.ready_check();
	
	cout << "--------------------------------------------------------" << endl;
}
