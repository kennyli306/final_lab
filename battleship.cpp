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