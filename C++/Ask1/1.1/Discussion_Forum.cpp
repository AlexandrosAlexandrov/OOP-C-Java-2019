#include <iostream>
#include <string>
#include <time.h>
#include "Objects.h"
#include "Objects.cpp"

using namespace std;

int main(){
	srand (time(NULL));	
	
	Forum forum("Antikeimenostrafis Programmatismos");
	
	forum.print();
	
	forum.print_by_thread("Kanones kai xrhsimes plhrofories");

	for(int i=0; i<10; i++){
		forum.print_by_post(rand() % 10);
	}
}
