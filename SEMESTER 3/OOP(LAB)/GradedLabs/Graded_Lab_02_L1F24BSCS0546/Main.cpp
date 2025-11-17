#include<iostream>
#include "GameProfile.h"
using namespace std;
int main() {
	cout << "Creating profile p1.....\n\n";
	GameProfile p1("john", 3);
	cout << "Adding scores to p1....\n\n";
	p1.logScore(85);
	p1.logScore(95);
	p1.logScore(75);
	cout << "Player info for p1....\n\n";
	p1.printPlayerInfo();
	cout << "\nCreating player 2 p2 as a copy ....\n\n";
	GameProfile p2(p1);
	cout << "Copying GameProfile: John\n\n";
	cout << "Player info for p2....\n\n";
	p2.printPlayerInfo();


	return 0;
}