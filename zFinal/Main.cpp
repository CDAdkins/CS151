#include "Board.h"
#include "Slot.h"
#include <string>
#include <iostream>
using namespace std;

int main() {
	Board monopoly;
	cout << monopoly;
	Player players[2] = { Player("Chris", monopoly, 300), Player("Sam", monopoly, 300) };
	monopoly.play(players);
}