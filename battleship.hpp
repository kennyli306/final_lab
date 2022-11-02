/* Kenny Li    battleship.hpp
   Andy Li
   31 Oct 2022 */

/* Questions 
   1) All the functions and data are in one place. Also when coding the game, I don't need to worry about the codes in the function
		or what data the structs for ships hold. I just need to access the functions. The structs for ship and all the data will only be manipulated
		be the functions (like Fire()), so I wouldn't need to worry about them either.

   2) A map to store where all the places have been hit. The value is always true, since it's been hit.
      The key can be the x and y coords manipulated together where most will be unique, like x^y or something.
      I think it's main perk is that I only worry about inputing a coord and then check if that has
		already been targeted. Creating a vector could also be useful, though I think the map might maybe require less coding.

   3) Firstly is to generate some boards that is always similar to each other, then shoot a few times and output the board.
		This way, the input will be a a bunch of ints and the outputs should always be the same every time. Placing ships will likely
		just be ints for x and y axis plus 1 - 4 for directions it is facing. */

/* Test Case
		1. One test case is to print each ship, with 3 integer inputs, x, y, and directions (1 - 4 will be N - W). So 0 0 3 will place a ship a (0, 0) facing south.
			so a test case for building board can just be 0 0 3 1 0 3 2 0 3 3 0 3, where 3 ships are place one the top row all facing south. 
			
			A test case for fire will also be integer inputs, 2 for x and 7.
			test case will be 0 0 6 6 0 0 69 420. The first should hit, second should miss, and the last two should be invalid 
			
		A rubric for the official version can just be a bunch of test cases with a bunch of integers for how the game is played, a
		nd what the final board should look like. */

#ifndef BATTLESHIP_HPP
#define BATTLESHIP_HPP

#include <iostream>
#include <vector>
#include <map>

class Game {
	public:
      /* Generates a game board 7 by 7. When placing ships, it may be possible to generate a random board using recursion, a bit 
      	similar to the nqueens lab. A possible edge condition is when generating a random board or letting the player build one,
      	the ships could be place where they hit each other or are off the map. */
		Game(int size = 7);
		~Game();
		int PlaceShip(int size, int num);

      /* One possible danger for Fire is a player shooting a coordinate that is either invalid or already hit.
      	Fire will use CheckHit, and if it is hit, then it will damage the specific ship. */
		int Fire(int x, int y);
		int CheckHit(int x, int y);

      /* Checks for the end of the game if all of a player's ship have no health. */
      bool GameEnd();

      void PrintBoard();
   private:
		/* Structures for each ships, and will contain datas for their stats like their size, how many times they've been hit, and where. 
			Putting them as structs will probably let me access each ship individually. So if there are 3 destroyers, they will be 3 structs,
			each with seperate values. Destroyer is an examplem, the rest will likely be similar. */
		struct Destroyer {
			char name = 'D';
			char direction;
			int size = 2;
			// Will use bit masking here, so if I have a if statement, I can probably do something like if (!d1.health) cout << "ship brok" << endl;
			int health = 3; // (0b 0011)
		};
		struct Cruiser {};
		struct Battleship {};
		struct Carrier {};

		int turn;
      /* Boolean board where 0 is water and 1 is a ship. */
		std::vector<std::vector<bool>> board;
		/* Map to store hits */
      std::map<int, bool> shots;
};

#endif