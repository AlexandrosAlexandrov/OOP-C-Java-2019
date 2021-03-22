#include <iostream>
#include "Objects.h"

using namespace std;

//////////////////////////             OBJECT              /////////////////////////////////////////

Object::Object(){
}

Object::Object(const Object& obj){
	this->id = obj.id;
}

Object::~Object(){
}

bool Object::equal(const Object& obj) const{
	if (this->id == obj.id)
		return true;
	else
		return false;
}

bool Object::identical(const Object& obj) const{
	if (this == &obj)
		return true;
	else
		return false;
}

Object Object::clone(const Object& obj){
	return  Object(obj); 
}

//////////////////////////             STRING              /////////////////////////////////////////

String::String(string s){
	str = s;
}

String::~String(){
}


int String::length(){
	return str.length(); 
}

void String::clear(){
	str.clear();
}

void String::concat(const string str1){
	this->str = str + str1;
}

char String::at(int i){
	return str.at(i);
}

void String::updateAt(int i, char c){
	str.assign(i, c);
}

void String::print(){
	cout << str << endl;
}

string String::getstr(){
	return str;
}

//////////////////////////             PLANE COMP              /////////////////////////////////////////

bool PlaneComponent::ready_check(){
	if(Employee.length() == 0)
		return false;
	else{
		return true;
		cout << "Plane Component OK!" << endl;
	}
}

void PlaneComponent::process(String s){
	Employee = s;
}

//////////////////////////             PASS COMP              /////////////////////////////////////////

bool PassengerCompartment::ready_check(){
	if(Employee.getstr().length() == 0)
		return false;
	else{
		return true;
		cout << "Passenger Compartment OK!" << endl;
	}
}

void PassengerCompartment::process(String s){
	Employee = s;
}

//////////////////////////             PRIV COMP              /////////////////////////////////////////

bool PrivateCompartment::ready_check(){
	if(Employee.length() == 0)
		return false;
	else{
		return true;
		cout << "Private Compartment OK!" << endl;
	}
}

void PrivateCompartment::process(String s){
	Employee = s;
}

PrivateCompartment::PrivateCompartment(){
}

//////////////////////////             EQUIP COMP              /////////////////////////////////////////

bool EquipmentCompartment::ready_check(){
	if(Employee.getstr().length() == 0)
		return false;
	else{
		return true;
		cout << "Equipment Compartment OK!" << endl;
	}
}

//////////////////////////             CARGO BAY              /////////////////////////////////////////

bool CargoBay::ready_check(){
	if(Employee.getstr().length() == 0)
		return false;
	else{
		return true;
		cout << "Cargo Bay OK!" << endl;
	}
}

//////////////////////////               PLANE              /////////////////////////////////////////

String Plane::GetDescription(){
	return Description;
}

String Plane::GetTitle(){
	return Title;
}

int Plane::GetPassengerCapacity(){
	return PassengerCapacity;
}

CargoBay Plane::GetCargo(){
	return Cargo;
}

EquipmentCompartment Plane::GetEquipment(int i){
	return Equipment[i];
}

PassengerCompartment Plane::GetPassenger(int i){
	return Passengers[i];
}

bool Plane::ready_check(){
	int s = 0;
	if(GetCargo().ready_check()){
		for (int i=0; i<3; i++){
			if (GetEquipment(i).ready_check() && GetPassenger(i).ready_check()){
				s++;
			}
		}
	}
	
	if(s = 3){
		return true;
		cout << "Plane OK!" << endl;
	}
	else
		return false;	
}

void Plane::process(String s1, String s2, String s3){
	Cargo.process(s1);
	for(int i=0; i<3; i++){
		Equipment[i].process(s2);
		Passengers[i].process(s3);
	}
}

//////////////////////////               EMPLOYEE              /////////////////////////////////////////

Employee::Employee(){
}

void Employee::workOn(PlaneComponent& planecomp){
	planecomp.process(this->getname());
}

void Employee::report(){
	cout << "This employe works on:" << endl;
}

String Employee::getname(){
	return name;
}

//////////////////////////               EMPLOYEE              /////////////////////////////////////////

SecurityEmployee::SecurityEmployee(String s){
	this->getname().getstr() = s.getstr();
}

void SecurityEmployee::workOn(PlaneComponent& plane){
}

//////////////////////////               EMPLOYEE              /////////////////////////////////////////

MaintenanceEmployee::MaintenanceEmployee(String s){
	this->getname().getstr() = s.getstr();
}

void MaintenanceEmployee::workOn(const CargoBay& cargo){
	
}

void MaintenanceEmployee::workOn(const EquipmentCompartment& equip){
	
}

//////////////////////////               EMPLOYEE              /////////////////////////////////////////

CleaningEmployee::CleaningEmployee(String s){
	this->getname().getstr() = s.getstr();
}

void CleaningEmployee::workOn(const PassengerCompartment& pass){
	
}

void CleaningEmployee::workOn(const CargoBay& cargo){
	
}
