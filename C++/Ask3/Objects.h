#ifndef OBJECTS_H
#define OBJECTS_H
#include <iostream>

using namespace std;

class Object
{
	static int id;

public:
	Object();
	Object(const Object& obj);
	~Object();

	bool equal(const Object& obj) const;
	bool identical(const Object& obj) const;
	Object clone(const Object& obj);
};

class String : public Object
{
	string str;

public:
	String() {};
	String(string s);
	~String();

	string getstr();
	int length();
	void clear();
	void concat(String s1);
	char at(int i);
	void updateAt(int i, char c);
	void print();
};

class PlaneComponent : public Object
{
	String Description;
	String Employee;

public:
	virtual bool ready_check();
	virtual void process(String s);

	PlaneComponent();
	virtual ~PlaneComponent();
};

class PassengerCompartment : public PlaneComponent
{
	PassengerCompartment Inner();
	String Employee;

public:

	PassengerCompartment();
	~PassengerCompartment();
};

class PrivateCompartment : public PlaneComponent
{
public:
	String Employee;

	PrivateCompartment();
	~PrivateCompartment();
};

class EquipmentCompartment : public PrivateCompartment
{
public:
	EquipmentCompartment();
	~EquipmentCompartment();
};

class CargoBay : public PrivateCompartment
{
	EquipmentCompartment GearCompartment();

public:
	CargoBay();
	~CargoBay();
};

class Employee
{
	String name;

public:
	void setname(String s);
	String getname();
	virtual void workOn(PlaneComponent planecomp);
	virtual void report();

	Employee();
	virtual ~Employee();
};

class SecurityEmployee : public Employee
{
public:
	void report();
	SecurityEmployee(String s);
	~SecurityEmployee();
};

class MaintenanceEmployee : public Employee
{
public:
	void report();
	MaintenanceEmployee(String s);
	~MaintenanceEmployee();
};

class CleaningEmployee : public Employee
{
public:
	void report();
	CleaningEmployee(String s);
	~CleaningEmployee();
};

class Plane : public Object
{
	String Description;
	String Title;
	int PassengerCapacity;
	CargoBay Cargo;
	EquipmentCompartment Equipment[3];
	PassengerCompartment Passengers[3];

public:
	String GetDescription();
	String GetTitle();
	int GetPassengerCapacity();
	CargoBay GetCargo();
	EquipmentCompartment GetEquipment(int i);
	PassengerCompartment GetPassenger(int i);
	void ready_check();
	void process(SecurityEmployee sec, MaintenanceEmployee maint, CleaningEmployee clean);

	Plane();
	~Plane();
};
#endif