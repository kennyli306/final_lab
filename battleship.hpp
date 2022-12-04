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
		void SetShips(int amt, char ship, char player);
		int GetInput(char c);
		int GetSize(char ship);
		bool PlaceShip(int x, int y, int dir, char ship);
   private:
		std::vector<std::vector<char>> pBoard;
		int pH = 0;
		int cH = 0;
};

#endif