/*	Daniel Dooley
	C++ 1st Semester 2019
	Due: Due Date 12 / 11 / 19
	Lab number 7
	Description : Make a Battleship game within rules described in classroom
	*/
#include <iostream> //default libraries used for code

using namespace std; //inherits standard namespace

//int hitDetection();
//void memoryReset();
//void ships();
//void playAgain(bool keepPlaying);
//int shipPlacement();
//int playerTurn();
int battleship();
void setup();
void display(char grid[10][10]);
int menu();
//int fireForEffect();
int playerSetShip(int shipNumber);
int coordinateSelection(int max);
//int playerSetDirection(int shipNumber);
//int checkAndDisplay(int tempX, int tempY, int direction, int length, int grid[10][10]);


int main() {
	bool keepPlaying = false;
	bool win = true;
	do {
		//playerHome();
		battleship();
		//setup();
		do {
			//playerTurn();
			//winCheck();
			//cpuTurn();
			//winCheck();
		} while (!win);
	} while (keepPlaying);
	//playerHome();
	return 0;
}
int playerTurn() {
	
	return 0;
}
void display(char grid[10][10],int length) {
	int x = 0;
	int y = 0;
	cout << endl<< endl << endl;
	for (int i = 0; i < 10; i++) {
		if (x != 0 && y != 0)
			cout << "	";
		while (y < 11) {
			if (y != 0)
				cout << y << "	";
			else
				cout << "	";
			y++;
		};
		cout << endl;
		if (y == 11 && x == 0)
			x++;
			cout << x;
		x++;
		for (int j = 0; j < 10; j++) {
			cout << "	" << grid[i][j];
		}
		cout << endl;
	}

}
//int checkAndDisplay(int tempX, int tempY, int direction, int length, char grid[10][10]) {
//	int x;
//	int y;
//	bool check = false;
//	
//	if (direction == 1) {
//		for (length > 0; length--;) {
//			if (grid[x][y-length] == '~') {
//				grid[x][y-length] = '#';
//			}
//		}
//	}
//	return 0;
//}

void setup() {
	string input;
	cout << endl << "Welcome to battleship." << endl << endl << "Press any key to continue";
	cin >> input;
}

int battleship() {
	//{	struct ship {
	//	int size;
	//	int health;
	//	int ypos;
	//	int xpos;
	//	int yposf;
	//	int xposf;
	//};
	//enum shipType {
	//	carrier, battleship, cruiser, submarine, destroyer
	//};
	//struct fleet {
	//	ship carrier;
	//	ship battleship;
	//	ship cruiser;
	//	ship sumbarine;
	//	ship destroyer;
	//	//carrier.size = 5;
	//	/*p5.carrier.health = 5;
	//	p4.battleship.size = 4;
	//	p4.battleship.health = 4;
	//	p3.cruiser.size = 3;
	//	p3.cruiser.health = 3;*/
	//};
	//fleet Player;
	//fleet Computer;
	//Player.battleship.health = 5;
	//Player.battleship.size = 5;
	//Player.carrier.health = 4;
	//Player.carrier.size = 4;
	//Player.cruiser.health = 3;
	//Player.cruiser.size = 3;
	//Player.sumbarine.health = 3;
	//Player.sumbarine.size = 3;
	//Player.destroyer.health = 2;
	//Player.destroyer.size = 2;
	//Computer.battleship.health = 5;
	//Computer.battleship.size = 5;
	//Computer.carrier.health = 4;
	//Computer.carrier.size = 4;
	//Computer.cruiser.health = 3;
	//Computer.cruiser.size = 3;
	//Computer.sumbarine.health = 3;
	//Computer.sumbarine.size = 3;
	//Computer.destroyer.health = 2;
	//Computer.destroyer.size = 2;


	int wins = 0;
	int losses = 0;
	bool keepPlaying = 1;
	int playerChoiceX;
	int playerChoiceY;
	int computerChoiceX;
	int computerChoiceY;
	bool win = true;
	int y=0;
	int x=0;
	char cpuHome[10][10];
	char cpuAway[10][10];
	char playerHome[10][10];
	char playerAway[10][10];
	int length = 100;
	int menuSelection;
	int direction;
	int xPos;
	int yPos;
	do {
		win = false;
		setup();
		for (int i = 0; i < 10; i++) {
			//cout << "	";
			while (y < 11) {
				//cout << y << "	";
				y++;
			};
			//cout << endl;
			if (y == 11&&x==0)
				x++;
			//cout << x;
			x++;
			for (int j = 0; j < 10; j++) {

				cpuHome[i][j] = '~';
				cpuAway[i][j] = '~';
				playerAway[i][j] = '~';
				playerHome[i][j] = '~';

				//cout << "	" << cpuHome[i][j];
			}
			//cout << endl;
		}
		//player setup
		//computer setup



		/*playerAway[5][8] = 'H';
		cout << endl << "CPU Home screen";
		display(cpuHome, length);
		cout << "CPU Away screen";
		display(cpuAway, length);*/
		cout << "Player Home screen";
		display(playerHome, length);
		cout << "Player Away screen";
		display(playerAway, length);
		int shipPlacementPosition;
		//bool XCoord = true;
		int tempX;
		int tempY;
		string coord = "playerSetShip(shipNumber);";
		int direction;
		int shiplength;
		for (int shipNumber = 1; shipNumber <= 15; shipNumber++) {
			cout << shipNumber<<endl << endl;
			//shipPlacementPosition = playerSetShip(shipNumber);
			switch(shipNumber){
			case 1: tempX = playerSetShip(shipNumber);
				break;
			case 2: tempY = playerSetShip(shipNumber);
				break;
			case 3: direction = playerSetShip(shipNumber);
				shiplength = 5;
				if (direction == 10) {
					tempX--;
					tempY--;
					for (shiplength > 0; shiplength--;) {
						if (playerHome[tempY-shiplength][tempX] == '~') {
							playerHome[tempY - shiplength][tempX] = '#';
						}
						else {
							shipNumber = 0;
							cout << "\n That is an invalid location \n";
						}
						cout << "Length: " << shiplength << "   temp Y: " << playerHome[tempX][tempY];
					}
				}			
				if (direction == 20) {
					tempX--;
					tempY--;
					for (shiplength > 0; shiplength--;) {
						if (playerHome[tempY + shiplength][tempX] == '~') {
							playerHome[tempY + shiplength][tempX] = '#';
						}
						else {
							shipNumber = 0;
							cout << "\n That is an invalid location \n";
						}
						cout << "Length: " << shiplength << "   temp Y: " << playerHome[tempX][tempY];
					}
				}
				if (direction == 30) {
					tempX--;
					tempY--;
					for (shiplength > 0; shiplength--;) {
						if (playerHome[tempY][tempX-shiplength] == '~') {
							playerHome[tempY][tempX-shiplength] = '#';
						}
						else {
							shipNumber = 0;
							cout << "\n That is an invalid location \n";
						}
						cout << "Length: " << shiplength << "   temp Y: " << playerHome[tempX][tempY];
					}
				}
				if (direction == 40) {
					tempX--;
					tempY--;
					for (shiplength > 0; shiplength--;) {
						if (playerHome[tempY][tempX + shiplength] == '~') {
							playerHome[tempY][tempX + shiplength] = '#';
						}
						else {
							shipNumber = 0;
							cout << "\n That is an invalid location \n";
						}
						cout << "Length: " << shiplength << "   temp Y: " << playerHome[tempX][tempY];
					}
				}
				break;
			case 4: display(playerHome, length);
				tempX = playerSetShip(shipNumber);
				break;
			case 5: tempY = playerSetShip(shipNumber);
				break;
			case 6: direction = playerSetShip(shipNumber);
				shiplength = 4;
				if (direction == 10) {
					tempX--;
					tempY--;
					for (shiplength > 0; shiplength--;) {
						if (playerHome[tempY - shiplength][tempX] == '~') {
							playerHome[tempY - shiplength][tempX] = '#';
						}
						else {
							shipNumber = 3;
							cout << "\n That is an invalid location! \n";
						}
						cout << "Length: " << shiplength << "   temp Y: " << playerHome[tempX][tempY];
					}
				}
				if (direction == 20) {
					tempX--;
					tempY--;
					for (shiplength > 0; shiplength--;) {
						if (playerHome[tempY + shiplength][tempX] == '~') {
							playerHome[tempY + shiplength][tempX] = '#';
						}
						else {
							shipNumber = 3;
							cout << "\n That is an invalid location \n";
						}
						cout << "Length: " << shiplength << "   temp Y: " << playerHome[tempX][tempY];
					}
				}
				if (direction == 30) {
					tempX--;
					tempY--;
					for (shiplength > 0; shiplength--;) {
						if (playerHome[tempY][tempX - shiplength] == '~') {
							playerHome[tempY][tempX - shiplength] = '#';
						}
						else {
							shipNumber = 3;
							cout << "\n That is an invalid location \n";
						}
						cout << "Length: " << shiplength << "   temp Y: " << playerHome[tempX][tempY];
					}
				}
				if (direction == 40) {
					tempX--;
					tempY--;
					for (shiplength > 0; shiplength--;) {
						if (playerHome[tempY][tempX + shiplength] == '~') {
							playerHome[tempY][tempX + shiplength] = '#';
						}
						else {
							shipNumber = 3;
							cout << "\n That is an invalid location \n";
						}
						cout << "Length: " << shiplength << "   temp Y: " << playerHome[tempX][tempY];
					}
				}
				break;
			case 7: display(playerHome, length);
				tempX = playerSetShip(shipNumber);
				break;
			case 8: tempY = playerSetShip(shipNumber);
				break;
			case 9: direction = playerSetShip(shipNumber);
				shiplength = 3;
				if (direction == 10) {
					tempX--;
					tempY--;
					for (shiplength > 0; shiplength--;) {
						if (playerHome[tempY - shiplength][tempX] == '~') {
							playerHome[tempY - shiplength][tempX] = '#';
						}
						else {
							shipNumber = 6;
							cout << "\n That is an invalid location! \n";
						}
						cout << "Length: " << shiplength << "   temp Y: " << playerHome[tempX][tempY];
					}
				}
				if (direction == 20) {
					tempX--;
					tempY--;
					for (shiplength > 0; shiplength--;) {
						if (playerHome[tempY + shiplength][tempX] == '~') {
							playerHome[tempY + shiplength][tempX] = '#';
						}
						else {
							shipNumber = 6;
							cout << "\n That is an invalid location \n";
						}
						cout << "Length: " << shiplength << "   temp Y: " << playerHome[tempX][tempY];
					}
				}
				if (direction == 30) {
					tempX--;
					tempY--;
					for (shiplength > 0; shiplength--;) {
						if (playerHome[tempY][tempX - shiplength] == '~') {
							playerHome[tempY][tempX - shiplength] = '#';
						}
						else {
							shipNumber = 6;
							cout << "\n That is an invalid location \n";
						}
						cout << "Length: " << shiplength << "   temp Y: " << playerHome[tempX][tempY];
					}
				}
				if (direction == 40) {
					tempX--;
					tempY--;
					for (shiplength > 0; shiplength--;) {
						if (playerHome[tempY][tempX + shiplength] == '~') {
							playerHome[tempY][tempX + shiplength] = '#';
						}
						else {
							shipNumber = 6;
							cout << "\n That is an invalid location \n";
						}
						cout << "Length: " << shiplength << "   temp Y: " << playerHome[tempX][tempY];
					}
				}
				break;
			case 10: display(playerHome, length);
				tempX = playerSetShip(shipNumber);
				break;
			case 11: tempY = playerSetShip(shipNumber);
				break;
			case 12: direction = playerSetShip(shipNumber);
				shiplength = 3;
				if (direction == 10) {
					tempX--;
					tempY--;
					for (shiplength > 0; shiplength--;) {
						if (playerHome[tempY - shiplength][tempX] == '~') {
							playerHome[tempY - shiplength][tempX] = '#';
						}
						else {
							shipNumber = 9;
							cout << "\n That is an invalid location! \n";
						}
						cout << "Length: " << shiplength << "   temp Y: " << playerHome[tempX][tempY];
					}
				}
				if (direction == 20) {
					tempX--;
					tempY--;
					for (shiplength > 0; shiplength--;) {
						if (playerHome[tempY + shiplength][tempX] == '~') {
							playerHome[tempY + shiplength][tempX] = '#';
						}
						else {
							shipNumber = 9;
							cout << "\n That is an invalid location \n";
						}
						cout << "Length: " << shiplength << "   temp Y: " << playerHome[tempX][tempY];
					}
				}
				if (direction == 30) {
					tempX--;
					tempY--;
					for (shiplength > 0; shiplength--;) {
						if (playerHome[tempY][tempX - shiplength] == '~') {
							playerHome[tempY][tempX - shiplength] = '#';
						}
						else {
							shipNumber = 9;
							cout << "\n That is an invalid location \n";
						}
						cout << "Length: " << shiplength << "   temp Y: " << playerHome[tempX][tempY];
					}
				}
				if (direction == 40) {
					tempX--;
					tempY--;
					for (shiplength > 0; shiplength--;) {
						if (playerHome[tempY][tempX + shiplength] == '~') {
							playerHome[tempY][tempX + shiplength] = '#';
						}
						else {
							shipNumber = 9;
							cout << "\n That is an invalid location \n";
						}
						cout << "Length: " << shiplength << "   temp Y: " << playerHome[tempX][tempY];
					}
				}
				break;
			case 13: display(playerHome, length);
				tempX = playerSetShip(shipNumber);
				break;
			case 14: tempX = playerSetShip(shipNumber);
				break;
			case 15:  direction = playerSetShip(shipNumber);
				shiplength = 2;
				if (direction == 10) {
					tempX--;
					tempY--;
					for (shiplength > 0; shiplength--;) {
						if (playerHome[tempY - shiplength][tempX] == '~') {
							playerHome[tempY - shiplength][tempX] = '#';
						}
						else {
							shipNumber = 12;
							cout << "\n That is an invalid location! \n";
						}
						cout << "Length: " << shiplength << "   temp Y: " << tempX << "    " << tempY;
					}
				}
				if (direction == 20) {
					tempX--;
					tempY--;
					for (shiplength > 0; shiplength--;) {
						cout << "DEBUG" << shiplength << " : " << tempX << " : " << tempY;
						if (playerHome[tempY + shiplength][tempX] == '~') {
							playerHome[tempY + shiplength][tempX] = '#';
						}
						else {
							shipNumber = 12;
							cout << "\n That is an invalid location \n";
						}
						cout << "Length: " << shiplength << "   temp Y: " << playerHome[tempX][tempY];
					}
				}
				if (direction == 30) {
					tempX--;
					tempY--;
					for (shiplength > 0; shiplength--;) {
						if (playerHome[tempY][tempX - shiplength] == '~') {
							playerHome[tempY][tempX - shiplength] = '#';
						}
						else {
							shipNumber = 12;
							cout << "\n That is an invalid location \n";
						}
						cout << "Length: " << shiplength << "   temp Y: " << playerHome[tempX][tempY];
					}
				}
				if (direction == 40) {
					tempX--;
					tempY--;
					for (shiplength > 0; shiplength--;) {
						if (playerHome[tempY][tempX + shiplength] == '~') {
							playerHome[tempY][tempX + shiplength] = '#';
						}
						else {
							shipNumber = 12;
							cout << "\n That is an invalid location \n";
						}
						cout << "Length: " << shiplength << "   temp Y: " << playerHome[tempX][tempY];
					}
				}
				break;
			}

			/*if (shipPlacementPosition % 10 == 0) {
				cout << shipPlacementPosition / 10 << "Direction";
				display(playerHome, length);
				cout << "Player Home Screen";
				XCoord = true;
			}
			else if(XCoord==false) {
				cout << "Y POS! \n";
			}
			else if (XCoord == true) {
				cout << "X POS! \n";
				XCoord = false;
			}*/

			


			//cout << shipPlacementPosition;
			
		}
		do {
			menuSelection = menu();
			
			if (menuSelection == 1) {
				/*cout <<endl << "CPU Home screen";
				display(cpuHome, length);
				cout << "CPU Away screen";
				display(cpuAway, length);*/
				cout << "Player Home screen";
				display(playerHome, length);
				cout << "Player Away screen";
				display(playerAway, length);
			}
			if (menuSelection == 2) {
				int XGuess;
				int YGuess;
				cout << endl << "You are firing at the enemy fleet. Enter an integer between 1-10 for the X coordinate: " << endl;
				XGuess = coordinateSelection(10);
				cout << endl << "Enter an integer between 1-10 for the Y coordinate: " << endl;
				YGuess=coordinateSelection(10);
				cout << XGuess << YGuess;
			}
			if (menuSelection == 3) {
				win = true;
				losses++;
				cout << "Quitter.... no one likes a quitter.." << endl;
			}
			//menu();
			if(win==true)
				cout << "Wins: " << wins << " Losses: " << losses << endl;
		} while (!win);
	} while (keepPlaying);
	return 0;
}
int menu() {
	int choice = 0;
	/*for (int i = 0; i < 40; i++) {
		cout << endl;
	}*/
	cout << "If you would like to display the grid enter 1: " << endl << endl << "If you would like to fire enter 2: " <<endl<< endl << "If you would like to surrender enter 3: ";
	for (int i = 0; i < 10; i++) {
		cout << endl;
	}
	do {
		cin >> choice;
		while (cin.fail()) {
			cout << "That is not a valid input, enter 1, 2, or 3: " << endl;
			cin.clear();
			cin.ignore(100, '\n');
			cin >> choice;
		}
		if (choice >= 1 && choice <= 3) {
			if (choice == 1)
				return 1;
			if (choice == 2)
				return 2;
			if (choice == 3)
				return 3;
		}
		else
			cout << "That is not a valid input enter 1, 2, or 3: " << endl;
	} while (choice < 1 || choice>3);
	return 1;
}

int coordinateSelection(int max) {
	int XY;
	cin >> XY;
	while (cin.fail() || XY < 1 || XY>max) {
		cout << "That is not a valid input, enter an integer 1-"<<max << ":" << endl;
		cin.clear();
		cin.ignore(100, '\n');
		cin >> XY;
	}
	return XY;
}

int playerSetDirection(int ShipDirection) {
	string direction = "Which direction do you want the ship to point? \n Enter 1, 2, 3, 4 for up, down, left, right, respectively: ";
	int Face=0;
	switch(ShipDirection){
	case 1: cout << direction;
		Face = coordinateSelection(4);
		break;
	case 2: cout << direction;
		Face = coordinateSelection(4);
		break;
	case 3: cout << direction;
		Face = coordinateSelection(4);
		break;
	case 4:cout << direction;
		Face = coordinateSelection(4);
		break;
	};
	return Face;
}

int playerSetShip(int shipNumber) {
	string direction = "Which direction do you want the ship to point? \n Enter 1, 2, 3, 4 for up, down, left, right, respectively: ";
	int Pos = 0;
	switch (shipNumber) {
	case 1: cout << "You are placing the Carrier (5 long). Choose a X starting position: ";
		Pos = coordinateSelection(10);
		break;
	case 2: cout << "You are placing the Carrier (5 long). Choose a Y starting position: ";
		Pos = coordinateSelection(10);
		break;
	case 3: cout << direction;
		Pos = coordinateSelection(4);
		Pos *= 10;
		break;
	case 4: cout << "You are placing the Battleship (4 long). Choose a X starting position: ";
		Pos = coordinateSelection(10);
		break;
	case 5: cout << "You are placing the Battleship (4 long). Choose a Y starting position: ";
		Pos = coordinateSelection(10);
		break;
	case 6: cout << direction;
		Pos = coordinateSelection(4);
		Pos *= 10;
		break;
	case 7: cout << "You are placing the Cruiser (3 long). Choose a X starting position: ";
		Pos = coordinateSelection(10);
		break;
	case 8: cout << "You are placing the Cruiser (3 long). Choose a Y starting position: ";
		Pos = coordinateSelection(10);
		break;
	case 9: cout << direction;
		Pos = coordinateSelection(4);
		Pos *= 10;
		break;
	case 10: cout << "You are placing the Submarine (3 long). Choose a X starting position: ";
		Pos = coordinateSelection(10);
		break;
	case 11: cout << "You are placing the Submarine (3 long). Choose a Y starting position: ";
		Pos = coordinateSelection(10);
		break;
	case 12: cout << direction;
		Pos = coordinateSelection(4);
		Pos *= 10;
		break;
	case 13: cout << "You are placing the Destroyer (2 long). Choose a X starting position: ";
		Pos = coordinateSelection(10);
		break;
	case 14: cout << "You are placing the Destroyer (2 long). Choose a Y starting position: ";
		Pos = coordinateSelection(10);
		break;
	case 15: cout << direction;
		Pos = coordinateSelection(4);
		Pos *= 10;
		break;
	}
	return Pos;
}

//int main2() {
//	bool keepPlaying = false;
//	bool win = false;
//	int x = 2;
//	int y = 3;
//	do {
//		setup();
//		do {
//			playerTurn(pos[x][y]);
//			winCheck();
//			cpuTurn();
//			winCheck();
//		} while (!win);
//	} while (keepPlaying);
//	playerHome();
//}

//void playAgain(bool keepPlaying) {
//	keepPlaying = false;
//	do {
//		int game();
//		keepPlaying = false;
//		string input;
//		cout << "Would you like to play again? \n";
//		cin >> input;
//		if (input == "y" || input == "Y" || input == "yes" || input == "Yes") {
//			keepPlaying = true;
//		}
//		
//	} while (keepPlaying);
//}

//int playerHome() {
//	char pos[10][10];
//	int x=1;
//	int y=1;
//	for (int i = 0; i < 10; i++) {
//		cout << "	";
//		while(y<11){
//			cout << y<< "	";
//			y++;
//		};
//		cout << endl;
//		cout << x;
//		x++;
//		for (int j = 0; j < 10; j++) {
//			
//			pos[i][j] = '~';
//			cout << "	" << pos[i][j];
//		}
//		cout << endl;
//	}
//	return 0;
//}