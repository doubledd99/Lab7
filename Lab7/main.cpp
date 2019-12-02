#include <iostream>

using namespace std;

int hitDetection();
int playerHome();
int playerAway();
int CPUHome();
int CPUAway();
void memoryReset();
void ships();
void playAgain(bool keepPlaying);
int shipPlacement();
int playerTurn(char pos[10][10]);

int main() {
	//bool keepPlaying = false;
	//bool win = false;
	//do {
	//	setup();
	//	do {
	//		playerTurn();
	//		winCheck();
	//		cpuTurn();
	//		winCheck();
	//	} while (!win);
	//} while (keepPlaying);
	playerHome();
	return 0;
}
int playerTurn(char pos[10][10]) {

	return 1;
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

void playAgain(bool keepPlaying) {
	keepPlaying = false;
	do {
		int game();
		keepPlaying = false;
		string input;
		cout << "Would you like to play again? \n";
		cin >> input;
		if (input == "y" || input == "Y" || input == "yes" || input == "Yes") {
			keepPlaying = true;
		}
		
	} while (keepPlaying);
}

int playerHome() {
	char pos[10][10];
	int x=1;
	int y=1;
	for (int i = 0; i < 10; i++) {
		cout << "	";
		while(y<11){
			cout << y<< "	";
			y++;
		};
		cout << endl;
		cout << x;
		x++;
		for (int j = 0; j < 10; j++) {
			
			pos[i][j] = '~';
			cout << "	" << pos[i][j];
		}
		cout << endl;
	}
	return 0;
}

int shipPlacement() {
	return 0;
}

int hitDetection() {
	struct battleship {
		int xpos;
		int ypos;
		bool hit1;
		bool hit2;
		bool hit3;
		bool hit4;
	};



	return 0;
}

void memoryReset() {
	char pos[10][10];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			pos[i][j] = '~';
			//cout <<"	" << pos[i][j];
		}
		cout << endl << endl;
	}
}


void ships() {
	struct fleet {
		int size;
		int health;
		int ypos;
		int xpos;
		int yposf;
		int xposf;
	};
	enum shipType {
		carrier, battleship, cruiser, submarine, destroyer
	};
	struct ship {
		fleet carrier;
		fleet battleship;
		fleet cruiser;
		fleet sumbarine;
		fleet destroyer;
		//carrier.size = 5;
		/*p5.carrier.health = 5;
		p4.battleship.size = 4;
		p4.battleship.health = 4;
		p3.cruiser.size = 3;
		p3.cruiser.health = 3;*/
	};
	ship p5;
	ship p4;
	ship p3;
	ship p2;
	p5.carrier.size = 5;
	p5.carrier.health = 5;
	p4.battleship.size = 4;
	p4.battleship.health = 4;
	p3.cruiser.size = 3;
	p3.cruiser.health = 3;
}