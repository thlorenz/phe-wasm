#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "test.h"
#include "evaluator.h"

/*************************************************/
/*                                               */
/* Kevin L. Suffecool, 2001                      */
/* suffecool@bigfoot.com                         */
/*                                               */
/*************************************************/

int main(void)
{
    int freq[10];
    int a, b, c, d, e, f, g, i, j;

    // zero out the frequency array
    for ( i = 0; i < 10; i++ )
        freq[i] = 0;

    // loop over every possible five-card hand
	for(a=0; a<48; a++)
	{
		for(b=a+1; b<49; b++)
		{
			for(c=b+1; c<50; c++)
			{
				for(d=c+1; d<51; d++)
				{
					for(e=d+1; e<52; e++)
					{
						i = evaluate_5cards(a, b, c, d, e);
						j = hand_rank(i);
						freq[j]++;
					}
				}
			}
		}
	}

	for(i=1;i<=9;i++)
		printf( "%15s: %8d\n", value_str[i], freq[i] );

	return 0;
}
