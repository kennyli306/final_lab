/* Kenny Li    battleship.hpp
   Andy Li Test
   7 Dec 2022 */

#ifndef BATTLESHIP_HPP
#define BATTLESHIP_HPP

#include <iostream>
#include <vector>
/* Implement a hit
	Then Implement different types of weapons
	Also implement a randomizer for AI */
class BShip {
	public:
		BShip(int n = 15);
		~BShip();
      void PrintBoard();
		void SetShips(int amt, char ship, char player);
		void Game();
		void Torpedo();
		int GetSize(char ship);
		bool PlaceShip(int x, int y, char dir, char ship);
		bool CheckHit(int x, int y);
   private:
		std::vector<std::vector<char>> board;
		int Health = 0;
};

#endif