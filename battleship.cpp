/* Kenny Li
   Andy Li
   7 Dec 2022 */

#include "battleship.hpp"
#include <iostream>
using namespace std;

BShip::BShip(int n) {
   pBoard.resize(n);
   for (int i = 0; i < n; i++) {
      pBoard[i].resize(n);
      for (int j = 0; j < n; j++)
         pBoard[i][j] = '~';
   }
}
BShip::~BShip() {

}

void BShip::PrintBoard() {
   for (int i = 0; i < (int)pBoard.size(); i++) {
      for (int j = 0; j < (int)pBoard.size(); j++)
         cout << "| " << pBoard[i][j] << ' ';
      
      cout << '|' << endl;
   }
}

void BShip::SetShips(int amt, char ship, char player) {
   int x, y, dir;
   if (player == 'P') {
      while (amt != 0) {
         if (ship == 'D') cout << "Destroyer";
         else if (ship == 'S') cout << "Submarine";
         else if (ship == 'B') cout << "Battleship";
         else if (ship == 'C') cout << "Carrier";
         cout << endl;

         x = GetInput('x');
         y = GetInput('y');
         dir = GetInput('h');
         if (PlaceShip(x, y, dir, ship)) {
            amt--;
            pH += GetSize(ship);
         }
         else
            cout << "Invalid Spot" << endl;
         PrintBoard();
      }
   }
}

int BShip::GetInput(char c) {
   int out;
   while (true) {
      cout << "Input " << c << ": ";
      if (cin >> out) return out;
      else {
         cout << "Bad Input" << endl;
         cin.clear();
         cin.ignore(1000, '\n');
      }
   }

   return out;
}

int BShip::GetSize(char ship) {
   if (ship == 'D') return 2;
   else if (ship == 'S') return 3;
   else if (ship == 'B') return 4;
   else if (ship == 'C') return 5;
   else return -1;
}

bool BShip::PlaceShip(int x, int y, int dir, char ship) {
   int i, *p, *q, *s;
   int size = GetSize(ship);
   if (dir) {
      p = &y;
      q = &i;
      s = &x;
   } 
   else {
      p = &i;
      q = &x;
      s = &y;
   }
   
   for (i = *s; i < *s + size; i++) 
      if (pBoard[*p][*q] != '~') return false;

   for (i = *s; i < *s + size; i++)
      pBoard[*p][*q] = ship;
   return true;
}