#include <iostream>
#include <string>
#include <fstream>
#include "game_of_life.h"
using namespace std;
int main() {
	srand(time(nullptr));
	game_of_life game;
	bool dalje;
	do {
		game.iscrtaj();
		cout << endl << endl << endl << endl << endl;
		cout << "Dalje (1/0): ";
		cin >> dalje;
	} while (dalje);
	return 0;
}