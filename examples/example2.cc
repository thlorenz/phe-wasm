#include "evaluator.h"
#include <iostream>
#include <unordered_map>

/*
 * This C++ example gives the mapping from a string to a card id.
 *
 * Note that this is just one possible mapping, as the suits can be swapped in
 * groups.
 */

int main(void)
{
	std::unordered_map <std::string, int> cardid = {
		{"2c", 0}, {"2d", 1}, {"2h", 2}, {"2s", 3},
		{"3c", 4}, {"3d", 5}, {"3h", 6}, {"3s", 7},
		{"4c", 8}, {"4d", 9}, {"4h", 10}, {"4s", 11},
		{"5c", 12}, {"5d", 13}, {"5h", 14}, {"5s", 15},
		{"6c", 16}, {"6d", 17}, {"6h", 18}, {"6s", 19},
		{"7c", 20}, {"7d", 21}, {"7h", 22}, {"7s", 23},
		{"8c", 24}, {"8d", 25}, {"8h", 26}, {"8s", 27},
		{"9c", 28}, {"9d", 29}, {"9h", 30}, {"9s", 31},
		{"Tc", 32}, {"Td", 33}, {"Th", 34}, {"Ts", 35},
		{"Jc", 36}, {"Jd", 37}, {"Jh", 38}, {"Js", 39},
		{"Qc", 40}, {"Qd", 41}, {"Qh", 42}, {"Qs", 43},
		{"Kc", 44}, {"Kd", 45}, {"Kh", 46}, {"Ks", 47},
		{"Ac", 48}, {"Ad", 49}, {"Ah", 50}, {"As", 51},
	};

	/*
	 * This demonstrated scenario is the same as the one shown in example 1.
	 * Community cards: 9c 4c 4s 9d 4h (both player share this cards)
	 * Player 1: Qc 6c
	 * Player 2: 2c 9h
	 */

	int x = evaluate_7cards(cardid["9c"], cardid["4c"], cardid["4s"],
			cardid["9d"], cardid["4h"], cardid["Qc"], cardid["6c"]);

	int y = evaluate_7cards(cardid["9c"], cardid["4c"], cardid["4s"],
			cardid["9d"], cardid["4h"], cardid["2c"], cardid["9h"]);

	// expected 292
	std::cout << "The rank of the hand in player 1 is " << x << std::endl;
	// expected 236
	std::cout << "The rank of the hand in player 2 is " << y << std::endl;

	// As the value of player 2 is less than player 1, the hand of player 2 is
	// considered to be a stronger one.
}
