/* Kenny Li    battleship.hpp
   Andy Li Test
   31 Oct 2022 */

/* Rubric
+4    Interface is well formatted, commented, and makes sense for the problem
      outlined in the accompaying report.
+4    Describes what each member function would do on a high level and potential 
      edge conditions.        
+3    Pros and cons of using classes (OOP) for this specific idea/problem 
+2    Describe at least one data structure we have covered that would be useful 
      and explains why.
+4    Provides at least two test cases/unit tests for the problem outlined above 
      (2 pts each)
+3    Provides a rubric/contract for how we should grade an "official" version of
      this lab based on the information above. */

/* Requirements 
 * Describe, with words, what each member function would do on a high level and potential edge conditions you could run into

These 3 are just answering questions:
   1) What are the pros and cons of using classes (OOP) to implement this idea of yours?

   2) Describe at least one data structure we have covered so far in 140 that you think would be useful and explain why. 
   Think outside of the box... are the data sparse and therefore could benefit from a map/set? 
   Are vectors alone good enough? Have a rationale for your choice on top of simply it could be useful.

   3) Using words, what could you provide as test cases (aka make test/gradescript) to make sure your program is working? 
   Would someone have to play set games (similar to the Connect4 lab), is there defined behavior (ala the hashing lab), 
   or would would be in a screenshot that would suffice as correct output? */

#ifndef BATTLESHIP_HPP
#define BATTLESHIP_HPP

#include <iostream>
#include <vector>
#include <map>

class BattleShip {
	public:
		BattleShip(int size = 7);
		~BattleShip();
		// TODO: Put in some functions. Don't need to describe yet, just some possibly useful ones.
		int PlaceShip(int ship, int num);
		int Fire(int x, int y);
		int CheckHit(int x, int y);


   private:
   	const int DESTROYER = 2;
   	const int CRUISER = 3;
   	const int BATTLESHIP = 4;
   	const int CARRIER = 5;
		int turn;
		std::vector<std::vector<int>> board;
};

#endif