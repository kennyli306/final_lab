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
		/* Main game functions */
		BShip(int n = 15);
      void PrintBoard(std::vector<std::vector<char>> b);
		void SetShips(int amt, char ship, char player);
		void Game();

		/*Weapon functions */
		void Torpedo();
		void Barrage();
		void Strike();

		/* Helper functions*/
		void XPlode(int x, int y, int pX, int pY);
		int GetSize(char ship);
		bool PlaceShip(int x, int y, char dir, char ship);
		bool CheckHit(int x, int y);
   private:
		/* board is the "behind the scene" that shows all ships 
			display is only intended for the player and shows it as it appears. */
		std::vector<std::vector<char>> board;
		std::vector<std::vector<char>> display;
		int Health = 0;
};

#endif