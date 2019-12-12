/*	Daniel Dooley
	C++ 1st Semester 2019
	Due: Due Date 12 / 11 / 19
	Lab number 7
	Description : Make a Battleship game within rules described in classroom
	*/
#include <iostream> //default libraries used for code

using namespace std; //inherits standard namespace

int battleship();//function prototype for battleship function
void setup();//function prototype for setup which is called to start program
void display(char grid[10][10]);//function prototype to easily display information to screen
int menu();//function prototype that displays a menu and has user pick options.
int playerSetShip(int shipNumber); //Function prototype to let user pick origin point for ship
int coordinateSelection(int max); //function prototype that ensures user's input is valid

int main() {//main function call
	bool keepPlaying = false;//bool value to see if user wants to keep playing
	bool win = true; //bool value to see if game should be reset
	do {
		battleship();//function call the "game" itself
		do {
		} while (!win);//if win condition true game is reset
	} while (keepPlaying);//if user wants to keep playing game resets
	return 0;
}

void display(char grid[10][10],int length) { //function definition that displays grid to screen
	int x = 0;//x coordinate to select location in 2D array
	int y = 0; // y coord to select location in 2D array
	cout << endl<< endl << endl;// spaces for aestetics
	for (int i = 0; i < 10; i++) { //outer for loop to cycle through array
		if (x != 0 && y != 0) //adds space for begining of scale for grid
			cout << "	";//adds space
		while (y < 11) {//logic to display scale for game
			if (y != 0)//ensures space lines up numbers
				cout << y << "	"; // adds correct spacing
			else
				cout << "	";//fixes spacing if only one digit number
			y++;
		};
		cout << endl; //spacing for after scale is finished
		if (y == 11 && x == 0)//
			x++;
			cout << x; // displays numbers down the left side of screen
		x++;//increments x by 1
		for (int j = 0; j < 10; j++) {//inner for loop to cycle thru X coordinates
			cout << "	" << grid[i][j];// adds spacing and displays grid character
		}
		cout << endl;//new line
	}

}

void setup() {//function definition for beginning of program run
	string input; //used to intake user input "press any key to continue"
	cout << endl << "Welcome to battleship." << endl << endl << "Press any key to continue"; // if user presses any key the game continues
	cin >> input;//intakes user input
}

int battleship() {//game's 'game engine' of sorts, handles all aspects of game
	int wins = 0; //win counter initialized to be 0
	int losses = 0;//loss counter initialized to be 0
	bool keepPlaying = true;//if the user wished to keep playing value is true
	//int playerChoiceX;
	//int playerChoiceY;
	//int computerChoiceX;
	//int computerChoiceY;
	bool win = true;//if user win conditions are met game closes and adds to tally
	int y=0;//variable used to make scale
	int x=0;//variable used to make scale
	char cpuHome[10][10];//grid for cpu player ships
	char cpuAway[10][10];//grid for cpu player hit and misses
	char playerHome[10][10];//grid for player ships
	char playerAway[10][10];//grid for player hits and misses
	int length = 100;//used to declare size of array to pass
	int menuSelection;//local variable to determine which path to follow when user selects from menu
	int direction;//which direction the user wishes to go after origin point chosen.
	//int xPos;
	//int yPos;
	do {
		win = false;//win condition set to false at beginning of each game
		setup();//intro message and wait for user input
		for (int i = 0; i < 10; i++) {//outer for loop to change all values in array to water
			while (y < 11) {//while loop to display scale
				y++;//increments up by 1
			};
			if (y == 11&&x==0)//when at the end of the scale it switches to display Y scale
				x++;//adds 1 to x
			x++;
			for (int j = 0; j < 10; j++) {//inner for loop to set all values default water.

				cpuHome[i][j] = '~';		//Sets
				cpuAway[i][j] = '~';		//Grids
				playerAway[i][j] = '~';		//to
				playerHome[i][j] = '~';		//Water

			}
		}
		cout << "Player Home screen";//displays information to let user understand which grid is which
		display(playerHome, length);//call of display function which displays grid to screen
		cout << "Player Away screen";//displays information to let user understand which grid is which
		display(playerAway, length);//call of display function which displays grid to screen
		//int shipPlacementPosition;
		int tempX; //modifyable x value that is initially what player selected as X coordinate
		int tempY; //modifyable x value that is initially what player selected as X coordinate
		//string coord = "playerSetShip(shipNumber);";
		int direction;//stores which direction user wishes to have ship lie
		int shiplength;//value that changes how many slots to display up down left or right depending
		for (int shipNumber = 1; shipNumber <= 15; shipNumber++) {//runs through switch statement sequentially with logic to revert if player incorrectly inputs info
			switch(shipNumber){//switch statement decides which ship player is placing
			case 1: tempX = playerSetShip(shipNumber); //sets X position for ship
				break;
			case 2: tempY = playerSetShip(shipNumber);//sets Y position for ship
				break;
			case 3: direction = playerSetShip(shipNumber);//sets direction ship will lie
				shiplength = 5;//sets length of ship//sets length of ship//sets length of ship
				if (direction == 10) {//if direction is upwards
					tempX--;//changes x value from 1 base to 0 base
					tempY--;//changes y value from 1 base to 0 base
					for (shiplength > 0; shiplength--;) {//displays another # for how long ship is
						if (playerHome[tempY-shiplength][tempX] == '~') {//only displays # if tile is water
							playerHome[tempY - shiplength][tempX] = '#';//displays # to grid
						}
						else {//if input was invalid
							shipNumber = 0;//reverts to choosing x coord again
							cout << "\n That is an invalid location \n";//tells user to re choose position
						}
					}
				}			
				if (direction == 20) {
					tempX--;//changes x value from 1 base to 0 base
					tempY--;//changes y value from 1 base to 0 base
					for (shiplength > 0; shiplength--;) {//displays another # for how long ship is
						if (playerHome[tempY + shiplength][tempX] == '~') {//only displays # if tile is water
							playerHome[tempY + shiplength][tempX] = '#';//displays # to grid
						}
						else {//if input was invalid
							shipNumber = 0;//reverts to choosing x coord again
							cout << "\n That is an invalid location \n";//tells user to re choose position
						}
					}
				}
				if (direction == 30) {
					tempX--;//changes x value from 1 base to 0 base
					tempY--;//changes y value from 1 base to 0 base
					for (shiplength > 0; shiplength--;) {//displays another # for how long ship is
						if (playerHome[tempY][tempX-shiplength] == '~') {//only displays # if tile is water
							playerHome[tempY][tempX-shiplength] = '#';//displays # to grid
						}
						else {//if input was invalid
							shipNumber = 0;//reverts to choosing x coord again
							cout << "\n That is an invalid location \n";//tells user to re choose position
						}
					}
				}
				if (direction == 40) {
					tempX--;//changes x value from 1 base to 0 base
					tempY--;//changes y value from 1 base to 0 base
					for (shiplength > 0; shiplength--;) {//displays another # for how long ship is
						if (playerHome[tempY][tempX + shiplength] == '~') {//only displays # if tile is water
							playerHome[tempY][tempX + shiplength] = '#';//displays # to grid
						}
						else {//if input was invalid
							shipNumber = 0;//reverts to choosing x coord again
							cout << "\n That is an invalid location \n";//tells user to re choose position
						}
					}
				}
				break;
			case 4: display(playerHome, length);//displays grid to screen
				tempX = playerSetShip(shipNumber); //sets X position for ship
				break;
			case 5: tempY = playerSetShip(shipNumber);//sets Y position for ship;
				break;
			case 6: direction = playerSetShip(shipNumber);//sets direction ship will lie
				shiplength = 4;//sets length of ship//sets length of ship//sets length of ship
				if (direction == 10) {//if direction is upwards
					tempX--;//changes x value from 1 base to 0 base
					tempY--;//changes y value from 1 base to 0 base
					for (shiplength > 0; shiplength--;) {//displays another # for how long ship is
						if (playerHome[tempY - shiplength][tempX] == '~') {//only displays # if tile is water
							playerHome[tempY - shiplength][tempX] = '#';//displays # to grid
						}
						else {//if input was invalid
							shipNumber = 3;
							cout << "\n That is an invalid location! \n";//tells user to re choose position
						}
					}
				}
				if (direction == 20) {
					tempX--;//changes x value from 1 base to 0 base
					tempY--;//changes y value from 1 base to 0 base
					for (shiplength > 0; shiplength--;) {//displays another # for how long ship is
						if (playerHome[tempY + shiplength][tempX] == '~') {//only displays # if tile is water
							playerHome[tempY + shiplength][tempX] = '#';//displays # to grid
						}
						else {//if input was invalid
							shipNumber = 3;
							cout << "\n That is an invalid location \n";//tells user to re choose position
						}
					}
				}
				if (direction == 30) {
					tempX--;//changes x value from 1 base to 0 base
					tempY--;//changes y value from 1 base to 0 base
					for (shiplength > 0; shiplength--;) {//displays another # for how long ship is
						if (playerHome[tempY][tempX - shiplength] == '~') {//only displays # if tile is water
							playerHome[tempY][tempX - shiplength] = '#';//displays # to grid
						}
						else {//if input was invalid
							shipNumber = 3;
							cout << "\n That is an invalid location \n";//tells user to re choose position
						}
					}
				}
				if (direction == 40) {
					tempX--;//changes x value from 1 base to 0 base
					tempY--;//changes y value from 1 base to 0 base
					for (shiplength > 0; shiplength--;) {//displays another # for how long ship is
						if (playerHome[tempY][tempX + shiplength] == '~') {//only displays # if tile is water
							playerHome[tempY][tempX + shiplength] = '#';//displays # to grid
						}
						else {//if input was invalid
							shipNumber = 3;
							cout << "\n That is an invalid location \n";//tells user to re choose position
						}
					}
				}
				break;
			case 7: display(playerHome, length);//displays grid to screen
				tempX = playerSetShip(shipNumber); //sets X position for ship
				break;
			case 8: tempY = playerSetShip(shipNumber);//sets Y position for ship;
				break;
			case 9: direction = playerSetShip(shipNumber);//sets direction ship will lie
				shiplength = 3;//sets length of ship//sets length of ship//sets length of ship
				if (direction == 10) {//if direction is upwards
					tempX--;//changes x value from 1 base to 0 base
					tempY--;//changes y value from 1 base to 0 base
					for (shiplength > 0; shiplength--;) {//displays another # for how long ship is
						if (playerHome[tempY - shiplength][tempX] == '~') {//only displays # if tile is water
							playerHome[tempY - shiplength][tempX] = '#';//displays # to grid
						}
						else {//if input was invalid
							shipNumber = 6;
							cout << "\n That is an invalid location! \n";
						}
					}
				}
				if (direction == 20) {
					tempX--;//changes x value from 1 base to 0 base
					tempY--;//changes y value from 1 base to 0 base
					for (shiplength > 0; shiplength--;) {//displays another # for how long ship is
						if (playerHome[tempY + shiplength][tempX] == '~') {//only displays # if tile is water
							playerHome[tempY + shiplength][tempX] = '#';//displays # to grid
						}
						else {//if input was invalid
							shipNumber = 6;
							cout << "\n That is an invalid location \n";//tells user to re choose position
						}
					}
				}
				if (direction == 30) {
					tempX--;//changes x value from 1 base to 0 base
					tempY--;//changes y value from 1 base to 0 base
					for (shiplength > 0; shiplength--;) {//displays another # for how long ship is
						if (playerHome[tempY][tempX - shiplength] == '~') {//only displays # if tile is water
							playerHome[tempY][tempX - shiplength] = '#';//displays # to grid
						}
						else {//if input was invalid
							shipNumber = 6;
							cout << "\n That is an invalid location \n";//tells user to re choose position
						}
					}
				}
				if (direction == 40) {
					tempX--;//changes x value from 1 base to 0 base
					tempY--;//changes y value from 1 base to 0 base
					for (shiplength > 0; shiplength--;) {//displays another # for how long ship is
						if (playerHome[tempY][tempX + shiplength] == '~') {//only displays # if tile is water
							playerHome[tempY][tempX + shiplength] = '#';//displays # to grid
						}
						else {//if input was invalid
							shipNumber = 6;
							cout << "\n That is an invalid location \n";//tells user to re choose position
						}
					}
				}
				break;
			case 10: display(playerHome, length);//displays grid to screen
				tempX = playerSetShip(shipNumber); //sets X position for ship
				break;
			case 11: tempY = playerSetShip(shipNumber);//sets Y position for ship;
				break;
			case 12: direction = playerSetShip(shipNumber);//sets direction ship will lie
				shiplength = 3;//sets length of ship//sets length of ship//sets length of ship
				if (direction == 10) {//if direction is upwards
					tempX--;//changes x value from 1 base to 0 base
					tempY--;//changes y value from 1 base to 0 base
					for (shiplength > 0; shiplength--;) {//displays another # for how long ship is
						if (playerHome[tempY - shiplength][tempX] == '~') {//only displays # if tile is water
							playerHome[tempY - shiplength][tempX] = '#';//displays # to grid
						}
						else {//if input was invalid
							shipNumber = 9;
							cout << "\n That is an invalid location! \n";
						}

					}
				}
				if (direction == 20) {
					tempX--;//changes x value from 1 base to 0 base
					tempY--;//changes y value from 1 base to 0 base
					for (shiplength > 0; shiplength--;) {//displays another # for how long ship is
						if (playerHome[tempY + shiplength][tempX] == '~') {//only displays # if tile is water
							playerHome[tempY + shiplength][tempX] = '#';//displays # to grid
						}
						else {//if input was invalid
							shipNumber = 9;
							cout << "\n That is an invalid location \n";//tells user to re choose position
						}

					}
				}
				if (direction == 30) {
					tempX--;//changes x value from 1 base to 0 base
					tempY--;//changes y value from 1 base to 0 base
					for (shiplength > 0; shiplength--;) {//displays another # for how long ship is
						if (playerHome[tempY][tempX - shiplength] == '~') {//only displays # if tile is water
							playerHome[tempY][tempX - shiplength] = '#';//displays # to grid
						}
						else {//if input was invalid
							shipNumber = 9;
							cout << "\n That is an invalid location \n";//tells user to re choose position
						}

					}
				}
				if (direction == 40) {
					tempX--;//changes x value from 1 base to 0 base
					tempY--;//changes y value from 1 base to 0 base
					for (shiplength > 0; shiplength--;) {//displays another # for how long ship is
						if (playerHome[tempY][tempX + shiplength] == '~') {//only displays # if tile is water
							playerHome[tempY][tempX + shiplength] = '#';//displays # to grid
						}
						else {//if input was invalid
							shipNumber = 9;
							cout << "\n That is an invalid location \n";//tells user to re choose position
						}

					}
				}
				break;
			case 13: display(playerHome, length);//displays grid to screen
				tempX = playerSetShip(shipNumber); //sets X position for ship
				break;
			case 14: tempX = playerSetShip(shipNumber); //sets X position for ship
				break;
			case 15:  direction = playerSetShip(shipNumber);//sets direction ship will lie
				shiplength = 2;//sets length of ship//sets length of ship//sets length of ship
				if (direction == 10) {//if direction is upwards
					tempX--;//changes x value from 1 base to 0 base
					tempY--;//changes y value from 1 base to 0 base
					for (shiplength > 0; shiplength--;) {//displays another # for how long ship is
						if (playerHome[tempY - shiplength][tempX] == '~') {//only displays # if tile is water
							playerHome[tempY - shiplength][tempX] = '#';//displays # to grid
						}
						else {//if input was invalid
							shipNumber = 12;
							cout << "\n That is an invalid location! \n";
						}
					}
				}
				if (direction == 20) {
					tempX--;//changes x value from 1 base to 0 base
					tempY--;//changes y value from 1 base to 0 base
					for (shiplength > 0; shiplength--;) {//displays another # for how long ship is
						cout << "DEBUG" << shiplength << " : " << tempX << " : " << tempY;
						if (playerHome[tempY + shiplength][tempX] == '~') {//only displays # if tile is water
							playerHome[tempY + shiplength][tempX] = '#';//displays # to grid
						}
						else {//if input was invalid
							shipNumber = 12;
							cout << "\n That is an invalid location \n";//tells user to re choose position
						}

					}
				}
				if (direction == 30) {
					tempX--;//changes x value from 1 base to 0 base
					tempY--;//changes y value from 1 base to 0 base
					for (shiplength > 0; shiplength--;) {//displays another # for how long ship is
						if (playerHome[tempY][tempX - shiplength] == '~') {//only displays # if tile is water
							playerHome[tempY][tempX - shiplength] = '#';//displays # to grid
						}
						else {//if input was invalid
							shipNumber = 12;
							cout << "\n That is an invalid location \n";//tells user to re choose position
						}

					}
				}
				if (direction == 40) {
					tempX--;//changes x value from 1 base to 0 base
					tempY--;//changes y value from 1 base to 0 base
					for (shiplength > 0; shiplength--;) {//displays another # for how long ship is
						if (playerHome[tempY][tempX + shiplength] == '~') {//only displays # if tile is water
							playerHome[tempY][tempX + shiplength] = '#';//displays # to grid
						}
						else {//if input was invalid
							shipNumber = 12;
							cout << "\n That is an invalid location \n";//tells user to re choose position
						}

					}
				}
				break;
			}

		}
		do {
			menuSelection = menu();//calls menu location and sets local variable to what user chose
			
			if (menuSelection == 1) {//if first option is selected
				cout << "Player Home screen";//tells user what grid is which
				display(playerHome, length);//displays grid to screen
				cout << "Player Away screen";//tells user what grid is which
				display(playerAway, length);//displays grid to screen
			}
			if (menuSelection == 2) {//if second option chosen user gets to fire.
				int XGuess;//initializes x coord for player guess
				int YGuess;//initializes y cord for player guess
				cout << endl << "You are firing at the enemy fleet. Enter an integer between 1-10 for the X coordinate: " << endl;//informs user what is happening for guess
				XGuess = coordinateSelection(10);//verifies user chooses between 1-10
				cout << endl << "Enter an integer between 1-10 for the Y coordinate: " << endl;//informs user what is happening for guess
				YGuess=coordinateSelection(10);//verifies user chooses between 1-10
			}
			if (menuSelection == 3) {//if menu option 3 is selected by user
				win = true;//resets game
				losses++;//adds one to loss counter
				cout << "Quitter.... no one likes a quitter.." << endl;//informs user of surrender state
			}
			if(win==true)//if game is over
				cout << "Wins: " << wins << " Losses: " << losses << endl;//tells user wins and losses
		} while (!win);//game loop while game is not over
	} while (keepPlaying);//program loop while user wishes to keep playing
	return 0;//ends function
}
int menu() {//function definition for menu screen
	int choice = 0;//resets choice to 0
	cout << "If you would like to display the grid enter 1: " << endl << endl << "If you would like to fire enter 2: " <<endl<< endl << "If you would like to surrender enter 3: ";// informs user of possible choices
	for (int i = 0; i < 10; i++) {//adds 10 spaces end line
		cout << endl;//displays empty line
	}
	do {
		cin >> choice;//inputs user input to select menu item
		while (cin.fail()) {//if user does not enter valid information
			cout << "That is not a valid input, enter 1, 2, or 3: " << endl;//informs user of failed input
			cin.clear();//resets input variable
			cin.ignore(100, '\n');//resets input variable
			cin >> choice;//asks for user input again
		}
		if (choice >= 1 && choice <= 3) {//if input is valid
			if (choice == 1)//returns 1 to battleship function
				return 1;
			if (choice == 2)//returns 2 to battleship function
				return 2;
			if (choice == 3)//returns 3 to battleship function
				return 3;
		}
		else
			cout << "That is not a valid input enter 1, 2, or 3: " << endl;//informs user to re choose
	} while (choice < 1 || choice>3);//if choice is invalid try again
	return 1;
}

int coordinateSelection(int max) {//ensures user enters valid info
	int XY;//local variable for x or y cord
	cin >> XY; //inputs user input
	while (cin.fail() || XY < 1 || XY>max) {//if user inputs invalid character or if out of bounds
		cout << "That is not a valid input, enter an integer 1-"<<max << ":" << endl;//informs user of invalid response
		cin.clear();//resets input variable
		cin.ignore(100, '\n');//resets input variable
		cin >> XY;//try to enter valid info
	}
	return XY;//returns x or y cord to place where it was called
}

int playerSetShip(int shipNumber) {//function definition for choosing x, y, and direction to place ship
	string direction = "Which direction do you want the ship to point? \n Enter 1, 2, 3, 4 for up, down, left, right, respectively: ";//string shorthand to save time
	int Pos = 0;//initiates Pos as 0
	switch (shipNumber) {//switch determined by value passed into this function
	case 1: cout << "You are placing the Carrier (5 long). Choose a X starting position: ";//tells user to choose X pos
		Pos = coordinateSelection(10);//ensures user chooses value between 1-10
		break;
	case 2: cout << "You are placing the Carrier (5 long). Choose a Y starting position: ";//tells user to choose Y pos
		Pos = coordinateSelection(10);//ensures user chooses value between 1-10
		break;
	case 3:	cout << "Choose the direction of the ship. 1, 2, 3, or 4 for up, down, left, and right respectively \n";
		Pos = coordinateSelection(4);//ensures user chooses value between 1-4
		Pos *= 10;//multiplies by 10 to easily distinguish x,y and direction
		break;
	case 4: cout << "You are placing the Battleship (4 long). Choose a X starting position: ";//tells user to choose X pos
		Pos = coordinateSelection(10);//ensures user chooses value between 1-10
		break;
	case 5: cout << "You are placing the Battleship (4 long). Choose a Y starting position: ";//tells user to choose Y pos
		Pos = coordinateSelection(10);//ensures user chooses value between 1-10
		break;
	case 6:	cout << "Choose the direction of the ship. 1, 2, 3, or 4 for up, down, left, and right respectively \n";
		Pos = coordinateSelection(4);//ensures user chooses value between 1-4
		Pos *= 10;//multiplies by 10 to easily distinguish x,y and direction
		break;
	case 7: cout << "You are placing the Cruiser (3 long). Choose a X starting position: ";//tells user to choose X pos
		Pos = coordinateSelection(10);//ensures user chooses value between 1-10
		break;
	case 8: cout << "You are placing the Cruiser (3 long). Choose a Y starting position: ";//tells user to choose Y pos
		Pos = coordinateSelection(10);//ensures user chooses value between 1-10
		break;
	case 9: cout << "Choose the direction of the ship. 1, 2, 3, or 4 for up, down, left, and right respectively \n";
		Pos = coordinateSelection(4);//ensures user chooses value between 1-4
		Pos *= 10;//multiplies by 10 to easily distinguish x,y and direction
		break;
	case 10: cout << "You are placing the Submarine (3 long). Choose a X starting position: ";//tells user to choose X pos
		Pos = coordinateSelection(10);//ensures user chooses value between 1-10
		break;
	case 11: cout << "You are placing the Submarine (3 long). Choose a Y starting position: ";//tells user to choose Y pos
		Pos = coordinateSelection(10);//ensures user chooses value between 1-10
		break;
	case 12: cout << "Choose the direction of the ship. 1, 2, 3, or 4 for up, down, left, and right respectively \n"; 
		Pos = coordinateSelection(4);//ensures user chooses value between 1-4
		Pos *= 10;//multiplies by 10 to easily distinguish x,y and direction
		break;
	case 13: cout << "You are placing the Destroyer (2 long). Choose a X starting position: ";//tells user to choose X pos
		Pos = coordinateSelection(10);//ensures user chooses value between 1-10
		break;
	case 14: cout << "You are placing the Destroyer (2 long). Choose a Y starting position: ";//tells user to choose Y pos
		Pos = coordinateSelection(10);//ensures user chooses value between 1-10
		break;
	case 15: cout << "Choose the direction of the ship. 1, 2, 3, or 4 for up, down, left, and right respectively \n"; 
		Pos = coordinateSelection(4);//ensures user chooses value between 1-4
		Pos *= 10;//multiplies by 10 to easily distinguish x,y and direction
		break;
	}
	return Pos;//returns x,y or direction information to where it was called from
}