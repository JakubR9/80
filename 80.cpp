#include <iostream>
#include <fstream>
using namespace std;

const int SIZE = 500;
int tab[SIZE];


void wyswietl(int a, int b, int c) {
	cout << a << ", " << b << ", " << c << endl;
}

bool saDlugosciamiTrojkataProstokatnego(int a, int b, int c) {
	return (a * a + b * b == c * c ||
			a * a + c * c == b * b ||
			c * a + c * b == a * a);
}

void z1() {
	cout << "Zadanie 1:" << endl;
	for (int i = 0; i < SIZE - 2; i++) {
		if (saDlugosciamiTrojkataProstokatnego(tab[i], tab[i+1], tab[i+2])) {
			wyswietl(tab[i], tab[i+1], tab[i+2]);
		}
	}
	cout << endl;
}


bool saTrojkatem(int a, int b, int c) {
	return (a + b > c && a + c > b && b + c > a);
}


void z3() {
	cout << "Zadanie 3:" << endl;
	int counter = 0;
	for (int i = 0; i < SIZE - 2; i++) {
		for (int j = i + 1; j < SIZE - 1; j++) {
			for (int k = j + 1; k < SIZE; k++) {
				if (saTrojkatem(tab[i], tab[j], tab[k])) counter++;
			}
		}
	}
	cout << counter << endl << endl;
}

int main() {
	ifstream in("dane_trojkaty.txt");
	for (int i = 0; i < SIZE; i++) {
		in >> tab [i];
	}
	in.close();
	
	z1();
	z3();
}
