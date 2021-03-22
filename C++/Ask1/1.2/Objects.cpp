#include <iostream>
#include <string>
#include <array>
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

int Post::get_Post_number() const{
	return Post_number;
}

string Post::get_Creator() const{
	return Creator;
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
/*
	Posts[0] = Post(1, "title1", "user1", 12, 12, 2019, "text1");
	Posts[1] = Post(2, "title2", "user2", 13, 12, 2019, "text2");
	Posts[2] = Post(3, "title3", "user3", 14, 12, 2019, "text3");
*/
	cout << "Thread with subject: " << Subject << " has just been created!" << endl << endl;
}

Thread::~Thread(){
	cout << "Thread with subject: " << Subject << " is about to be destroyed" << endl << endl;
	delete_date(&Creation_date);
}

string Thread::get_Subject() const{
	return Subject;
}

int Thread::get_Post_number() const{
	 for(int i=0; i<3; i++){
	 	return Thread::Posts[i].get_Post_number();
	 }
}

string Thread::get_Creator() const{
	return Creator;
}

Post Thread::get_Post(int a) const{
	return Posts[a];
}

void Thread::print(){
	cout << "Subject-> " << Subject << endl
		 << "Creator-> " << Creator << endl
		 << "Creation date: "; print_date(&Creation_date);
		 for(int i=0; i<3; i++){
		 	Thread::Posts[i].print();
		 }
}

void Thread::print_post(int a){
	 for(int i=0; i<3; i++){
	 	if (a == Thread::Posts[i].get_Post_number());
	 		Thread::Posts[i].print();
	 }
}

/////////////////////////                    TREE                              /////////////////////

Tree::Tree(Thread t){
	cout << "Tree created." << endl << endl;
	Root->Creator = t.get_Creator();
	for (int i=0; i<3; i++){
		Root->Posts[i] = t.get_Post(i);
	}

}

void Tree::remove(Node *temp){
	if (temp == NULL)
        return;
    remove(temp->Left);
    remove(temp->Right);
    delete temp;	
}

Tree::~Tree(){ 
	cout << "Deleting Tree" << endl << endl;
	remove(Root);
}

Node* Tree::insert(Post p){
	
	Node *newnode;
	newnode->Creator = p.get_Creator();
	
	Node *temp = Root;
	Node *trail = NULL;
	
	while(temp != NULL){
		trail = temp;
		if (p.get_Creator().compare(temp->Creator) < 0)
			temp = temp->Left;
		else
			temp = temp->Right;
	}
	
	if (trail == NULL)
		trail = newnode;
	else if (p.get_Creator().compare(trail->Creator) < 0)
		trail->Left = newnode;
	else
		trail->Right = newnode;
		
	return trail;
}

string Tree::get_Creator() const{
	return Root->Creator;
}

void Tree::print_node_posts(Node *temp){
	for (int i=0; i<3; i++){
		temp->Posts[i].print();
	}
}

void Tree::print(){
	cout << "PRINTING TREE" << endl << "------------------------" << endl;
	if (Root){
		print_node_posts(Root);
		Node *temp1 = Root;
		Node *temp2 = Root;
		while (temp1->Right != NULL){
			print_node_posts(temp1);
			temp1 = temp1->Right;
		}
		while (temp2->Left != NULL){
			print_node_posts(temp2);
			temp2 = temp2->Left;
		}
	}
	cout << "------------------------" << endl;
}

Tree Tree::operator+(Tree& t){
	if(Root->Creator.compare(t.Root->Creator) == 0){
		for(int i=0; i<3; i++){
			Root->Posts[i] = t.Root->Posts[i];
		}
	}
	else{
		for(int i=0; i<3; i++){
			insert(t.Root->Posts[i]);
		}
	}
}

/////////////////                       FORUM                                         //////////////////////////

Forum::Forum(string t){
	Title = t;
	Thread Threads[0] = Thread("Kanones kai xrhsimes plhrofories", "Me", 3, 12, 2019);
	
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
	for(int i=0; i<3; i++){
		if(t == Forum::Threads[i].get_Subject()){
			Forum::Threads[i].print();			
		}
	}
}

void Forum::print_by_post(int a){
	for (int i=0; i<3; i++){
			if (a == Forum::Threads[i].get_Post_number())
			Forum::Threads[i].print_post(a);
		}
}

void Forum::print_sorted(){
	cout << "PRINT SORTED" << endl 
	 	 << "------------------------------"
	     << endl << endl;
	     
	Tree tree1(Forum::Threads[0]);
	cout << "Printing first tree: " << endl;
	tree1.print();
	Tree tree2(Forum::Threads[1]);
	cout << "Printing second tree: " << endl;
	tree2.print();
	Tree tree3(Forum::Threads[2]);
	cout << "Printing third tree: " << endl;
	tree3.print();
	
	cout << "Printing appended tree: " << endl;
	tree1 = tree1 + tree2 + tree3;
	
	tree1.print();
}
