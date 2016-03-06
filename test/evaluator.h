/*
 * Card id, ranged from 0 to 51.
 *
 * The two least significant bits represent the 4 suits, ranged from 0-3.
 *
 * The rest of it represent the 13 ranks, ranged from 0-12.
 * More specifically:
 * deuce = 0, trey = 1, four = 2, five = 3, six = 4, seven = 5, eight = 6,
 * nine = 7, ten = 8, jack = 9, queen = 10, king = 11, ace = 12.
 *
 * 13 * 4 gives all 52 ids.
 */
int evaluate_7cards(int a, int b, int c, int d, int e, int f, int g);
int evaluate_5cards(int a, int b, int c, int d, int e);

