#define	STRAIGHT_FLUSH	1
#define	FOUR_OF_A_KIND	2
#define	FULL_HOUSE	3
#define	FLUSH		4
#define	STRAIGHT	5
#define	THREE_OF_A_KIND	6
#define	TWO_PAIR	7
#define	ONE_PAIR	8
#define	HIGH_CARD	9

#define	RANK(x)		((x >> 8) & 0xF)

static char *value_str[] = {
	"",
	"Straight Flush",
	"Four of a Kind",
	"Full House",
	"Flush",
	"Straight",
	"Three of a Kind",
	"Two Pair",
	"One Pair",
	"High Card"
};

int hand_rank(short val)
{
    if (val > 6185) return(HIGH_CARD);        // 1277 high card
    if (val > 3325) return(ONE_PAIR);         // 2860 one pair
    if (val > 2467) return(TWO_PAIR);         //  858 two pair
    if (val > 1609) return(THREE_OF_A_KIND);  //  858 three-kind
    if (val > 1599) return(STRAIGHT);         //   10 straights
    if (val > 322)  return(FLUSH);            // 1277 flushes
    if (val > 166)  return(FULL_HOUSE);       //  156 full house
    if (val > 10)   return(FOUR_OF_A_KIND);   //  156 four-kind
    return(STRAIGHT_FLUSH);                   //   10 straight-flushes
}
