#include<iostream>
#include<math.h>
using namespace std;

double h(int num1, int num2);

int main() {
	int num1;
	int num2;
	cout << "give me two numbers" << endl;
	cin >> num1;
	cin >> num2;
	cout << h(num1,num2) << endl;

}
double h(int num1, int num2) {
	double h = 0;
	num1 = num1 * num1;
	num2 = num2 * num2;
	h = num1 + num2;
	h = sqrt(h);
	return h;
}
