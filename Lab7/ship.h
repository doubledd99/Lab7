#ifndef SHIP_H
#define SHIP_H

void ships() {
	struct fleet {
		int size;
		int health;
		int ypos;
		int xpos;
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

#endif // !SHIP_H