/*  Board.cpp
    Author: Chris Adkins
    Module: 17
    Project: Final
    File Description: This class handles the drawing of the board and the spaces on the board as well as communication with the player.
*/

#include "Board.h"
#include "Slot.h"
using namespace std;

string center(int width, const string& str) {
	int len = str.length();
	if (width < len) { return str; }

	int diff = width - len;
	int pad1 = diff / 2;
	int pad2 = diff - pad1;
	return string(pad1, ' ') + str + string(pad2, ' ');
}
// Drawing the board
void draw_edge_line(int width, const string* line) {
	cout << "|" << string((width) * 5 + 4, '-') << "|" << endl;
	cout << "|" << string((width) * 5 + 4, ' ') << "|" << endl;
	cout << "|";
	for (int col = 0; col < 5; col++)
		cout << center(width, line[col]) << "|";
	cout << endl;
	cout << "|" << string((width) * 5 + 4, ' ') << "|" << endl;
	cout << "|" << string((width) * 5 + 4, '-') << "|" << endl;
}

void draw_inner_line(int width, const string* line, bool last) {
	cout << "|" << string(width * 5 + 4, ' ') << "|" << endl;
	cout << "|" << center(width, line[0]) << "|";
	cout << string(width * 3 + 2, ' ') << "|";
	cout << center(width, line[4]) << "|" << endl;
	cout << "|" << string(width * 5 + 4, ' ') << "|" << endl;
	if (!last) {
		cout << "|" << string(width, '-') << "|" << string((width * 3 + 3), ' ');
		cout << string(width, '-') << "|" << endl;
	}
}

ostream& operator<<(ostream& os, const Board& b) {
	draw_edge_line(b.m_slot_width, b.m_board_image[0]);
	for (int row = 1; row < 5; row++)
		draw_inner_line(b.m_slot_width, b.m_board_image[row], row == 4);
	draw_edge_line(b.m_slot_width, b.m_board_image[5]);
	return os;
}

void Board::initBoardImage() {
	m_board_image[0][0] = m_arr[9]->getName();
	m_board_image[0][1] = m_arr[10]->getName();
	m_board_image[0][2] = m_arr[11]->getName();
	m_board_image[0][3] = m_arr[12]->getName();
	m_board_image[0][4] = m_arr[13]->getName();
	m_board_image[1][0] = m_arr[8]->getName();
	m_board_image[1][1] = "";
	m_board_image[1][2] = "";
	m_board_image[1][3] = "";
	m_board_image[1][4] = m_arr[14]->getName();
	m_board_image[2][0] = m_arr[7]->getName();
	m_board_image[2][1] = "";
	m_board_image[2][2] = "";
	m_board_image[2][3] = "";
	m_board_image[2][4] = m_arr[15]->getName();
	m_board_image[3][0] = m_arr[6]->getName();
	m_board_image[3][1] = "";
	m_board_image[3][2] = "";
	m_board_image[3][3] = "";
	m_board_image[3][4] = m_arr[16]->getName();
	m_board_image[4][0] = m_arr[5]->getName();
	m_board_image[4][1] = "";
	m_board_image[4][2] = "";
	m_board_image[4][3] = "";
	m_board_image[4][4] = m_arr[17]->getName();
	m_board_image[5][0] = m_arr[4]->getName();
	m_board_image[5][1] = m_arr[3]->getName();
	m_board_image[5][2] = m_arr[2]->getName();
	m_board_image[5][3] = m_arr[1]->getName();
	m_board_image[5][4] = m_arr[0]->getName();

	m_slot_width = 0;
	for (int row = 0; row < 6; row++) {
		for (int col = 0; col < 5; col++)
			if (m_board_image[row][col].size() > m_slot_width)
				m_slot_width = m_board_image[row][col].size();
	}
	m_slot_width += 2;
}

// Populating the board with assets.
Board::Board() :m_arr(nullptr) {
	srand(time_t(NULL));
	size = 0;
	addGoSlot("GO!");
	addAssetSlot("Mediterranean Avenue");
	addAssetSlot("Baltic Avenue");
	addAssetSlot("Vermont Avenue");
	addJailSlot("JAIL! Wait 1 turn");

	addAssetSlot("Virginia Avenue");
	addAssetSlot("St. James Place");
	addChanceSlot("\nChance!\nYou found a wallet on the sidewalk with $", 25);
	addAssetSlot("Tennessee Avenue");
	addAssetSlot("New York Avenue");

	addAssetSlot("Atlantic Avenue");
	addAssetSlot("Ventnor Avenue");
	addAssetSlot("Marvin Gardens");
	addAssetSlot("Pacific Avenue");

	addAssetSlot("Pennsylvania Avenue");
	addChanceSlot("Tax Return! Get $", 50);
	addAssetSlot("Park Place");
	addAssetSlot("Boardwalk");
	initBoardImage();
}

Board::~Board() {
	// Deleting everything in m_arr
	for (int i = 0; i < size; i++)
		delete m_arr[i];
	delete[] m_arr;
}

void Board::increaseBoard() {
	Slot ** tmp = new Slot *[size + 1];
	int i;
	for (i = 0; i < size; i++)
		tmp[i] = m_arr[i];
	size++;
	delete[] m_arr;
	m_arr = tmp;
}

void Board::addAssetSlot(const string& asset_name) {
	increaseBoard();
	m_arr[size - 1] = new Asset(size, asset_name);
}


void Board::addGoSlot(const string& text) {
	increaseBoard();
	m_arr[size - 1] = new Go(size, text);
}

void Board::addJailSlot(const string& text) {
	increaseBoard();
	m_arr[size - 1] = new Jail(size, text);
}

void Board::addChanceSlot(const string& text, int amount) {
	increaseBoard();
	m_arr[size - 1] = new Chance(size, text, amount);
}

int Board::getSize() {return size;}

Slot * Board::operator[](int idx) const {return m_arr[idx];}

istream& operator >> (istream& is, Board::action& i) {
	int tmp;
	if (is >> tmp)
		i = (Board::action)(tmp);
	return is;
}

void Board::printHelp() {
	cout << "\nContinue ("<< PLAY <<"),";
	cout << " Print Board ("<< PRINT_BOARD <<"),";
	cout << " Print Assets ("<< PRINT_ASSETS<< "),";
	cout << " End Game ("<< END_GAME<< "): ";
}

Board::action Board::getCommand() const {
	Board::action cmd;
	cin >> cmd;
	if (cin.fail() || cmd < 0 || cmd > 3) {
		cin.clear();
		cin.ignore();
		return getCommand();
	}
	return cmd;
}

void Board::play(Player* players) {
	int player = 0;
	action a;
	while (1) {
		cout << endl << players[player].getName() << "'s turn: ";
		printHelp();
		a = (action)getCommand();
		// Get input from the user prior to each turn.
		switch(a) {
			case END_GAME:
			cout << "Closing Game...";
				return;
			case PRINT_BOARD:
				cout << *this;
				break;
			case PRINT_ASSETS:
				cout << *this;
				cout << players[player];
				break;
			case PLAY:
				cout << *this;
				if (!(players[player]).drawDice()) {
					cout << "GAME OVER!" << endl;
					exit(EXIT_SUCCESS);
					break;
				}
				// Advance to the next player's turn.
				player = (player + 1) % Player::getNumPlayers();
		}
	}
	cout << "Closing Game..." << endl;
}

Slot* Board::getSlot(int inx) const {return m_arr[inx];}
