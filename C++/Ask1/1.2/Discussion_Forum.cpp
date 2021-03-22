#include <iostream>
#include <string>
#include <time.h>
#include "Objects.h"
#include "Objects.cpp"

using namespace std;

int main(){
	srand (time(NULL));		

	Forum forum("Antikeimenostrafis Programmatismos");
	
	Thread t("Walter");
	Post p(12, "WALTER");
	
	Tree tree1(t);
	tree1.print();
	Tree tree2(t);
	tree2.print();
	
	tree1 = tree1 + tree2;
	
	tree1.print();
	
	
		
}
