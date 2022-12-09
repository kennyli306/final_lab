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

   display.resize(n);
   for (int i = 0; i < n; i++) {
      display[i].resize(n);
      for (int j = 0; j < n; j++)
         display[i][j] = '~';
   }
}

void BShip::PrintBoard(vector<vector<char>> b) {
   int n = b.size();
   
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
         cout << setw(2) << b[i][j] << ' ';
      
      cout << "   " << i << ' ' << endl;
   }

   for (int i = 0; i < 4*n+6; i++)
      cout << '~';
   cout << endl;
}

/* Will first determind the location to place the ship, whether by asking it from the player or randomly.
   Then it will attempt to place ship. */
void BShip::SetShips(int amt, char ship, char player) {
   int x, y, d, n = board.size();
   char dir;
   while (amt != 0) {
      if (player == 'P') {
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
      }
      else {
         x = rand() % n - 1;
         y = rand() % n - 1;
         d = rand() % 2 - 1;
         if (d) dir = 'h';
         else dir = 'v';

      }
         
      if (PlaceShip(x, y, dir, ship)) {
         if (player == 'P') 
            PrintBoard(board);
         amt--;
         Health += GetSize(ship);
      }
      else if (player == 'P'){
         PrintBoard(board);
         cout << endl << "Invalid Spot" << endl;
      }
   }
}

/* Game and Weapon are explained in main. */
void BShip::Game() {
   int turns = 0;
   char input;
   vector<vector<char>> *b;

   while(true) {
      cout << "Display ships(y or n)? ";
      if (cin >> input) {
         if (input == 'y')
            b = &board;
         else if (input == 'n')
            b = &display;
         else {
            cout << "Invalid Choice." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
         }
      }
      else {
         cout << "Invalid Input." << endl;
         cin.clear();
         cin.ignore(1000, '\n');
         continue;
      }

      break;
   }

   while (Health) {
      PrintBoard(*b);
      cout << "T or B or S: ";
      if (cin >> input) {
         if (input == 'B')
            Barrage();
         else if (input == 'T')
            Torpedo();
         else if (input == 'S')
            Strike();
         else {
            cout << "Invalid Choice." << endl;
            cin.ignore(1000, '\n');
         }
      }
      else {
         cout << "Invalid Input."<< endl;
         cin.clear();
         cin.ignore(1000, '\n');
      }

      turns++;
   }

   PrintBoard(*b);
   cout << "Win" << endl;
   cout << "Turns: " << turns;
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
      if (CheckHit(x, n-i-1)) {
         board[n-i-1][x] = 'X';
         display[n-i-1][x] = 'X';
         Health--;
         break;
      }
      else if (board[n-i-1][x] != 'X'){
         if (board[n-i-1][x] == '~') {
            board[n-i-1][x] = '^';
            display[n-i-1][x] = '^';
         }
      }
      else break;
   }
}

void BShip::Barrage() {
   int x, y, n = board.size();

   while (true) {
      cout << "Barrage: ";
      if (cin >> x >> y && x >= 0 && x < n && y >= 0 && y < n) 
         break;
      else {
         cout << "Invalid Input" << endl
              << "Usage: (int)[x]   (int)[x]" << endl;
         cin.clear();
         cin.ignore(1000, '\n');
      }
   }
   int p, q;

   for (int i = 0; i < 17; i++) {
      p = x + (rand() % 7 - 3);
      q = (rand() % 10);

      if (q < 4) q = y + 1;
      else if (q > 8) q = y - 1;
      else q = y;

      if (p < 0 || p >= n || q < 0 || q >= n)
         continue;
      
      if (CheckHit(p, q)) {
         if (board[q][p] != 'X')
            Health--;

         board[q][p] = 'X';
         display[q][p] = 'X';
      }
      else if (board[q][p] == '~') {
         board[q][p] = 'o';
         display[q][p] = 'o';
      }
   }
}

void BShip::Strike() {
   int x, y, n = board.size();

   while (true) {
      cout << "Strike: ";
      if (cin >> x >> y && x >= 0 && x < n && y >= 0 && y < n) 
         break;
      else {
         cout << "Invalid Input" << endl
              << "Usage: (int)[x]   (int)[x]" << endl;
         cin.clear();
         cin.ignore(1000, '\n');
      }
   }

   XPlode(x, y, -1, -1);
}

/* If it hits a ship, it will recursively expand outwards like normal explodions.
   Continues until it no longer hits an alive ship part. */
void BShip::XPlode(int x, int y, int pX, int pY) {
   int n = board.size();
   if (x < 0 || x >= n || y < 0 || y >= n)
      return;

   if (CheckHit(x, y)) {
      if (pX != x+1)
         XPlode(x+1, y, x, y);
      if (pX != x-1)
         XPlode(x-1, y, x, y);
      if (pY != y+1) 
         XPlode(x, y+1, x, y);
      if (pY != y-1)
         XPlode(x, y-1, x, y);

      board[y][x] = 'X';
      display[y][x] = 'X';
      Health--;
   }
   else if (board[y][x] == '~') {
      board[y][x] = '*';
      display[y][x] = '*';
   }

   return;
}

int BShip::GetSize(char ship) {
   if (ship == 'D') return 2;
   else if (ship == 'S') return 3;
   else if (ship == 'B') return 4;
   else if (ship == 'C') return 5;
   else return -1;
}

/* Will first check if it can place the ship. Places it and return true if it can 
   and returning false if it cannot. */
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