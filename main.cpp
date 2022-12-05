/* Kenny Li
   Andy Li
   7 Dec 2022 */

#include "battleship.hpp"
using namespace std;

int main() {
   BShip b;
   //b.SetShips(1, 'D', 'P');
   //b.SetShips(1, 'S', 'P');
   b.SetShips(1, 'B', 'P');
   b.SetShips(1, 'C', 'P');
   b.Game();

   cout << endl;
   return 0;
}