#include "std_lib_facilities.h"

int main(){
	cout << "Please enter your name:\n";
	string first_name; // variable of type string
	string friend_name;// variable of type string
	int age;// variable of tyoe string

	cin >> first_name; // read characters into first name

	cout << "Please enter your friend name:\n";
	cin >> friend_name;
	cout << "Please enter age:";
	cin >> age;


	if (age < 0 or age>110){
		simple_error("you're kidding!");
	}

	cout << "Dear " << first_name << " Have you seen your friend "
	<< friend_name << " "<< "You are now " << age << " ages! ";
	if (age < 15){
		cout <<"You are young to NYU!";
	}


}