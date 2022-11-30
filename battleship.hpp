/* Kenny Li    battleship.hpp
   Andy Li Test
   7 Dec 2022 */

#ifndef BATTLESHIP_HPP
#define BATTLESHIP_HPP

#include <iostream>
#include <vector>
#include <map>

class BShip {
	public:
		BShip(int n = 10);
		~BShip();
      void PrintBoard();
   private:
		std::vector<std::vector<char>> pBoard;

		struct Destroyer {
			char name = 'D';
			int size = 2;
		};
		struct Submarine {
			char name = 'S';
			int size = 3;
		};
		struct Battleship {
			char name = 'B';
			int size = 4;
		};
		struct Carrier {
			char name = 'C';
			int size = 5;
		};
};

#endif