#include<iostream>
using namespace std;
//class definition-------------------------------------------
class piggy {
private: //private variables can only be seen/used by members of the class
	int xpos;
	int ypos;
	bool hungry;
	bool isAsleep;
	bool boredom;
	int number;
public: //can be seen and used by everything in your program
	piggy(int num); //parameterized constructor
	void walk();
	void sleep();
	void draw();
	void oink();
};//---------------------------------------------------------
int main() {
	piggy p1(1); //instantiate a pig object
	piggy p2(2);

	char input;
	cout << "press any letter" << endl;
	cin >> input;
	while (input != 'q') { //look for events-----------------------
		cout << "press any letter" << endl;
		cin >> input;
		p1.walk();
		cout << "2";
		p1.draw();
		cout << "3";
		p2.walk();
		p2.draw();


	}
}//end event loop----------------------------------


piggy::piggy(int num) {
	xpos = rand() % 600 + 100;
	ypos = rand() % 600 + 100;
	isAsleep = false;
	hungry = true;
	boredom = true;
	number = num;
}
void piggy::walk() {
	//randomly move in one of 8 directions when isWalking is true
	if (boredom == true) {
		xpos += rand() % 10 - 5;
		ypos += rand() % 10 - 5;
		int off = rand() % 100 + 1;
		oink();

		if (off < 30) { //30% chance walking will turn off each turn
			boredom = false;
			cout << "Bored!" << endl;
		}

		if (xpos >= 799) {
			xpos = 799;
		}

		if (xpos <= 1) {
			xpos = 1;
		}

		if (ypos >= 799) {
			ypos = 799;
		}

		if (ypos <= 1) {
			ypos = 1;
		}
	}
	else {
		sleep();
	}
	//10% chance any turn that isWalking will turn ON
	int num = rand() % 100 + 1;
	if (num < 30 and boredom == false and isAsleep == false) {
		boredom = true;
		cout << "not bored!" << endl;
	}
}
void piggy::sleep() {
	//you do this one
	int num = rand() % 100 + 1;
	if (num < 50) {
		isAsleep = true;
	}
	else {
		isAsleep = false;
	}
}
void piggy::oink() {
	int num = rand() % 100 + 1;
	if (num < 10) {
		hungry = true;
	}
	else {
		hungry = false;
	}
}
void piggy::draw() {
	//eventually this will hold drawing functions to make it graphical
	cout << "Hello I am pig # " << number << endl;
	if (hungry == true) cout << "give me food!" << endl;
	cout << "My position is " << xpos << " , " << ypos << endl;
	cout << "I am ";
	if (isAsleep == true) cout << " asleep, and";
	else cout << " not asleep, and";
	if (boredom == true) cout << " bored." << endl;
	else cout << " not bored." << endl;
	//system("pause");
}
