#ifndef OBJECTS_H
#define OBJECTS_H
#include <string>
#include <array>

using namespace std;

struct Date
{
	int day;
	int month;
	int year;
	
	void set_date(Date *date ,int d, int m, int y);
	void print_date(Date *date);
	void delete_date(Date *date);
};


class Post
{
	private:
		int Post_number;
		string Title;
		string Creator;
		Date Creation_date;
		string Text;
		
	public:
		Post(int i = rand() % 10, string t = "default" , string c = "creator", int d = (rand() % 10 +1) * 3,
		 int m =12, int y = 2019, string txt = "text here");
		~Post();
		
		int get_Post_number() const;
		string get_Creator() const;
		
		void print();
};

class Thread
{
	private:
		string Subject;
		string Creator;
		Date Creation_date;
		Post Posts[3];
		
	public:
		Thread(string t = "default", string c = "user", int d = (rand() % 10 +1) * 3, int m = 12, int y = 2019);
		~Thread();
		
		string get_Subject() const;
		int get_Post_number() const;
		string get_Creator() const;
		Post get_Post(int a) const;
		
		void print();
		void print_post(int a);

};

struct Node
{
	string Creator;
	Post Posts[3];
	Node *Left;
	Node *Right;
};

class Tree
{
	private:		
		Node *Root = new Node;
		
	public:
		Tree(Thread t = Thread());
		~Tree();
		
		void remove(Node* temp);
		Node* insert(Post p);
		
		string get_Creator() const;
		
		void print_node_posts(Node *temp);
		void print();
		
		Tree operator+(Tree& t);
		
};

class Forum
{
	private:
		string Title;
		Thread Threads[3];
		
	public:
		Forum(string t = "title!");
		~Forum();
		
		void print();
		void print_by_thread(string t);
		void print_by_post(int a);
		void print_sorted();
};

#endif
