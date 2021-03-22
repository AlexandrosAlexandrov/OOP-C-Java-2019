#include <iostream>
#include <string>
#include <time.h>
#include "Objects.h"

using namespace std;

void set_date(Date *date ,int d, int m, int y){
	date->day = d;
	date->month = m;
	date->year = y;
}

void print_date(Date *date){
	cout << date->day << "/" << date->month << "/" << date->year << endl;
}

void delete_date(Date *date){
	date = NULL;
}

/////////////////                POST                              //////////////////////////

Post::Post(int i, string t, string c, int d, int m, int y, string txt){
	Post_number = i;
	Title = t;
	Creator = c;
	set_date(&Creation_date, d, m, y);
	Text = txt;

	cout << "Post number: " << Post_number << endl
		 << "Post title: " << Title << endl
		 << "Post creator: " << Creator << endl
		 << "Post creation date: "; print_date(&Creation_date);
	cout << "Post text: " << Text << endl << endl; 
}

Post::~Post(){
	cout << "Post number: " << Post_number << " is about to be destroyed" << endl << endl;
	delete_date(&Creation_date);
}

Post::get_Post_number() const{
	return Post_number;
}

void Post::print(){
	cout << "Post number: " << Post_number << endl
		 << "Post title: " << Title << endl
		 << "Post creator: " << Creator << endl
		 << "Post creation date: " ; print_date(&Creation_date);
	cout << "Post text: " << Text << endl << endl;
}

////////////////                   THREAD                                     /////////////////////////

Thread::Thread(string t, string c, int d, int m, int y){
	Subject = t;
	Creator = c;
	set_date(&Creation_date, d, m, y);
	
	cout << "Thread with subject: " << Subject << " has just been created!" << endl << endl;
}

Thread::~Thread(){
	cout << "Thread with subject: " << Subject << " is about to be destroyed" << endl << endl;
	delete_date(&Creation_date);
}

string Thread::get_Subject() const{
	return Subject;
}

int Thread::get_Post_number(int i) const{
	 	return Thread::Posts[i].get_Post_number();
}

void Thread::print(){
	cout << "Subject-> " << Subject << endl
		 << "Creator-> " << Creator << endl
		 << "Creation date: "; print_date(&Creation_date);
		 cout << endl;
		 cout << "Posts: " << endl;
		 for(int i=0; i<3; i++){
		 	Thread::Posts[i].print();
		 }
}

void Thread::print_post(int a){
	Thread::Posts[a].print();
}
/////////////////                       FORUM                                         //////////////////////////

Forum::Forum(string t){
	Title = t;
	Threads[0] = Thread("Kanones kai xrhsimes plhrofories", "Me", 3, 12, 2019);
	cout << "Forum with title: " << Title << " has just been created!" << endl << endl;
}

Forum::~Forum(){
	cout << "Forum with title: " << Title << " is about to be destroyed" << endl << endl;
}

void Forum::print(){
		 for(int i=0; i<3; i++){
		 	Forum::Threads[i].print();
		 }
}

void Forum::print_by_thread(string t){
	cout << "--------------------------------------------------" << endl;
	cout << "Posts in Thread: " << endl;
	for(int i=0; i<3; i++){
		if(t == Forum::Threads[i].get_Subject()){
			Forum::Threads[i].print();			
		}
	}
}

void Forum::print_by_post(int a){
	for(int i=0; i<3; i++){
		for (int j=0; j<3; j++){
			if (a == Forum::Threads[i].get_Post_number(j)){
				cout << "Prtinting post with number :" << a << endl << "--------------------" << endl;
				Forum::Threads[i].print_post(j);
				return;
			}
		}
	}
	cout << "Post with number: " << a << " does not exist" << endl << endl;
}
