/* Kenny Li
   Andy Li
   7 Dec 2022 */

/* Game is similar to battleship, but since it's single player, we decide to make it PvE, and give 
   the player more weapons. 
      Ships:
         [D]estroyer    = 2 spaces
         [S]ubmarine    = 3 spaces
         [B]attleship   = 4 spaces
         [C]arrier      = 5 spaces
   
   First the program will ask if player wants to display the ships, then it begins game. 
      [T]orpedo: travels from bottom to top of the board, stopping when it hits something. 
         Won't pass through destoryed or undestroyed ships. 
      [B]arrage: Fires 17 times in a 3 by 7 grid around the selected coordinate.
         Has higher chance to hit center row and cam hit a spot more than once.
      [S]trike: hits a single spot. If it hits a intact ship part, it will explode and damage 
         the surrounding. If it hits another intact ship part, it will explode again.
         
   Once all ships are destroyed, game prints amount of turns it took.

   Grid size and amount of ships can be changed, but only in the code.
   Also, if you want to manually place a ship, just change the last parameter of set ship
   to P. A means auto place. */

#include "battleship.hpp"
using namespace std;

int main() {
   BShip b;
   b.SetShips(4, 'D', 'A');
   b.SetShips(3, 'S', 'A');
   b.SetShips(2, 'B', 'A');
   b.SetShips(1, 'C', 'A');
   b.Game();

   cout << endl;
   return 0;
}