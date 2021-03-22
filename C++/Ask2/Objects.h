#ifndef OBJECTS_H
#define OBJECTS_H
#include <iostream>
#include <vector>

using namespace std;

class Object
{
	int id;
	
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
	String(){};
	String(string s);
	~String();
	
	string getstr();
	int length();
	void clear();
	void concat(const string str1);
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
};

class PassengerCompartment : public PlaneComponent
{
	PassengerCompartment Inner();
	String Employee;
	
public:
	bool ready_check();
	void process(String s);
	
	PasengerCompartment();
};

class PrivateCompartment : public PlaneComponent
{
public:
	String Employee;
	bool ready_check();
	void process(String s);
	
	PrivateCompartment();
};

class EquipmentCompartment : public PrivateCompartment
{
public:
	bool ready_check();
};

class CargoBay : public PrivateCompartment
{
	PrivateCompartment GearCompartment();
	
public:
	bool ready_check();
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
	bool ready_check();
	void process(String s1, String s2, String s3);
};

class Employee
{
	String name;
	
public:
	String getname();
 	void workOn(PlaneComponent& planecomp);
	void report();	
	
	Employee();
};

class SecurityEmployee : public Employee
{
public:
	void workOn(PlaneComponent& plane);
	SecurityEmployee(String s);
};

class MaintenanceEmployee : public Employee
{
public:
	void workOn(const CargoBay& cargo);
	void workOn(const EquipmentCompartment& equip);
	 MaintenanceEmployee(String s);
};

class CleaningEmployee : public Employee
{
public:
	void workOn(const PassengerCompartment& pass);
	void workOn(const CargoBay& cargo);
	CleaningEmployee(String s);
};

#endif
