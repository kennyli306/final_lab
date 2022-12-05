/* Kenny Li
   Andy Li
   7 Dec 2022 */

#include "battleship.hpp"
#include <iomanip>
using namespace std;

BShip::BShip(int n) {
   board.resize(n);
   for (int i = 0; i < n; i++) {
      board[i].resize(n);
      for (int j = 0; j < n; j++)
         board[i][j] = '~';
   }
}
BShip::~BShip() {

}

void BShip::PrintBoard() {
   int n = board.size();
   
   for (int i = 0; i < 4*n+6; i++)
      cout << '~';
   cout << endl;

   cout << "         ";
   for (int j = 0; j < n; j++)
      cout << setw(2) << j << ' ';
   cout << endl << endl;

   for (int i = 0; i < n; i++) {
      cout << "         ";
      for (int j = 0; j < n; j++)
         cout << setw(2) << board[i][j] << ' ';
      
      cout << "   " << i << ' ' << endl;
   }

   for (int i = 0; i < 4*n+6; i++)
      cout << '~';
   cout << endl;
}

void BShip::SetShips(int amt, char ship, char player) {
   int x, y;
   char dir;
   if (player == 'P') {
      while (amt != 0) {
         if (ship == 'D') cout << "Destroyer:   ";
         else if (ship == 'S') cout << "Submarine:   ";
         else if (ship == 'B') cout << "Battleship:   ";
         else if (ship == 'C') cout << "Carrier:   ";

         cout << "PLACE [x] [y] [h or v]: ";
         if (!(cin >> x >> y >> dir) || !(dir == 'v' || dir == 'h')) {
            cout << endl << "USAGE:      (int)[x]       (int)[y]       (char)[(h)orizontal || (v)ertical]" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
         }
         
         if (PlaceShip(x, y, dir, ship)) {
            PrintBoard();
            amt--;
            Health += GetSize(ship);
         }
         else {
            PrintBoard();
            cout << endl << "Invalid Spot" << endl;
         }
      }
   }
}

void BShip::Game() {
   while (Health) {
      Torpedo();
      PrintBoard();
   }
}

void BShip::Torpedo() {
   int x, n = board.size();

   while (true) {
      cout << "Torpedo: ";
      if (cin >> x && x >= 0 && x < n) 
         break;
      else {
         cout << "Invalid Input" << endl
              << "Usage: (int)[x]" << endl;
         cin.clear();
         cin.ignore(1000, '\n');
      }
   }

   for (int i = 0; i < n; i++) {
      if (board[n-i-1][x] == '~')
         board[n-i-1][x] = '^';
      else if (CheckHit(x, n-i-1)) {
         board[n-i-1][x] = 'X';
         Health--;
         break;
      }
      else break;
   }
}

int BShip::GetSize(char ship) {
   if (ship == 'D') return 2;
   else if (ship == 'S') return 3;
   else if (ship == 'B') return 4;
   else if (ship == 'C') return 5;
   else return -1;
}

bool BShip::PlaceShip(int x, int y, char dir, char ship) {
   int i, *p, *q, *s;
   int size = GetSize(ship), n = board.size();
   if (dir == 'h') {
      p = &y;
      q = &i;
      s = &x;
   } 
   else if (dir == 'v') {
      p = &i;
      q = &x;
      s = &y;
   } else return false;

   if (x >= n || y >= n || x < 0 || y < 0) return false;
   
   for (i = *s; i < *s + size; i++) 
      if (board[*p][*q] != '~') return false;

   for (i = *s; i < *s + size; i++)
      board[*p][*q] = ship;
   return true;
}

bool BShip::CheckHit(int x, int y) {
   switch(board[y][x]) {
      case 'D':
      case 'S':
      case 'B':
      case 'C':
         return true;
   }

   return false;
}