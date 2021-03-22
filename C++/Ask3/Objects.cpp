#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Objects.h"

using namespace std;

//////////////////////////             OBJECT              /////////////////////////////////////////

Object::Object() {
	id = id++;
	cout << "Object just created!" << endl;
}

Object::Object(const Object& obj) {
	this->id = obj.id;
}

Object::~Object() {
	cout << "Object to be destroyed!" << endl;
}

bool Object::equal(const Object& obj) const {
	if (this->id == obj.id)
		return true;
	else
		return false;
}

bool Object::identical(const Object& obj) const {
	if (this == &obj)
		return true;
	else
		return false;
}

Object Object::clone(const Object& obj) {
	return  Object(obj);
}

//////////////////////////             STRING              /////////////////////////////////////////

String::String(string s) {
	str = s;
	cout << "String just created!" << endl;
}

String::~String() {
	cout << "String to be destroyed!" << endl;
}


int String::length() {
	return str.length();
}

void String::clear() {
	str.clear();
}

void String::concat(String s1) {
	this->str = str + s1.getstr();
}

char String::at(int i) {
	return str.at(i);
}

void String::updateAt(int i, char c) {
	if (i <= str.length())
		str[i] = c;
	else
		cout << "Cannot do that." << endl;
}

void String::print() {
	cout << str << endl;
}

string String::getstr() {
	return str;
}

//////////////////////////             PLANE COMP              /////////////////////////////////////////

bool PlaneComponent::ready_check() {
	if (Employee.length() == 0)
		return false;
	else {
		return true;
		cout << "Plane Component OK!" << endl;
	}
}

void PlaneComponent::process(String s) {
	Employee = s;
}

PlaneComponent::PlaneComponent() {
	cout << "Plane Component just created!" << endl;
}

PlaneComponent::~PlaneComponent() {
	cout << "Plane Component to be destroyed!" << endl;
}

//////////////////////////             PASS COMP              /////////////////////////////////////////

PassengerCompartment::PassengerCompartment() {
	cout << "Passenger Compartment just created!" << endl;
}

PassengerCompartment::~PassengerCompartment() {
	cout << "Passenger Compartment to be " << endl;
}


//////////////////////////             PRIV COMP              /////////////////////////////////////////


PrivateCompartment::PrivateCompartment() {
	cout << "Private Compartment just created!" << endl;
}

PrivateCompartment::~PrivateCompartment() {
	cout << "Private Compartment to be destroyed!" << endl;
}

//////////////////////////             EQUIP COMP              /////////////////////////////////////////


EquipmentCompartment::EquipmentCompartment() {
	cout << "Equipment Compartment just created!" << endl;
}

EquipmentCompartment::~EquipmentCompartment() {
	cout << "Equipment Compartment to be destroyed!" << endl;
}

//////////////////////////             CARGO BAY              /////////////////////////////////////////


CargoBay::CargoBay() {
	cout << "Cargo Bay just created!" << endl;
}

CargoBay::~CargoBay() {
	cout << "Cargo Bay to be destroyed!" << endl;
}

//////////////////////////               EMPLOYEE              /////////////////////////////////////////

Employee::Employee() {
	cout << "Employee just created!" << endl;
}

Employee::~Employee() {
	cout << "Employee to be destroyed!" << endl;
}

void Employee::setname(String s) {
	name = s;
}

void Employee::workOn(PlaneComponent planecomp) {
	planecomp.process(this->getname());
	planecomp.ready_check();
}

void Employee::report() {
	cout << "Employee OK!" << endl;
}

String Employee::getname() {
	return name;
}

//////////////////////////               EMPLOYEE              /////////////////////////////////////////


SecurityEmployee::SecurityEmployee(String s) {
	setname(s);
	cout << "Security Employee just created!" << endl;
}

SecurityEmployee::~SecurityEmployee() {
	cout << "Security Employee to be destroyed!" << endl;
}

void SecurityEmployee::report() {
	cout << "Security Employee OK!" << endl;
}

//////////////////////////               EMPLOYEE              /////////////////////////////////////////


MaintenanceEmployee::MaintenanceEmployee(String s) {
	setname(s);
	cout << "Maintenance Employee just created!" << endl;
}

MaintenanceEmployee::~MaintenanceEmployee() {
	cout << "Maintenance Employee to be destroyed!" << endl;
}

void MaintenanceEmployee::report() {
	cout << "Maintenance Employee OK!" << endl;
}
//////////////////////////               EMPLOYEE              /////////////////////////////////////////


CleaningEmployee::CleaningEmployee(String s) {
	setname(s);
	cout << "Cleaning Employee just created!" << endl;
}

CleaningEmployee::~CleaningEmployee() {
	cout << "Cleaning Employee to be destroyed!" << endl;
}

void CleaningEmployee::report() {
	cout << "Cleaning Employee OK!" << endl;
}


//////////////////////////               PLANE              /////////////////////////////////////////

String Plane::GetDescription() {
	return Description;
}

String Plane::GetTitle() {
	return Title;
}

int Plane::GetPassengerCapacity() {
	return PassengerCapacity;
}

CargoBay Plane::GetCargo() {
	return Cargo;
}

EquipmentCompartment Plane::GetEquipment(int i) {
	return Equipment[i];
}

PassengerCompartment Plane::GetPassenger(int i) {
	return Passengers[i];
}

void Plane::ready_check() {
	Cargo.ready_check();
	for (int i = 0; i < 3; i++) {
		Equipment[i].ready_check();
		Passengers[i].ready_check();
	}

	cout << "Plane OK!" << endl;
}

void Plane::process(SecurityEmployee sec, MaintenanceEmployee maint, CleaningEmployee clean) {
	maint.workOn(this->GetCargo());

	for (int i = 0; i < 3; i++) {
		sec.workOn(this->GetEquipment(i));
		clean.workOn(this->GetPassenger(i));
	}

	maint.report();
	sec.report();
	clean.report();

}


Plane::Plane() {
	cout << "Plane just created!" << endl;
}

Plane::~Plane() {
	cout << "Plane to be destroyed!" << endl;
}