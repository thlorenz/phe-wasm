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
    int a, b, c, d, e, f, g, i, j, k;

    // zero out the frequency array
    for ( i = 0; i < 10; i++ )
        freq[i] = 0;

    // loop over every possible seven-card hand
	for(a=0; a<47; a++)
	{
		for(b=a+1; b<48; b++)
		{
			for(c=b+1; c<49; c++)
			{
				for(d=c+1; d<50; d++)
				{
					for(e=d+1; e<51; e++)
					{
						for(f=e+1; f<52; f++)
						{
							i = evaluate_6cards(a, b, c, d, e, f);

							j = hand_rank(i);
							freq[j]++;
						}
					}
				}
			}
		}
	}

	for(i=1; i<=9; i++)
		printf( "%15s: %8d\n", value_str[i], freq[i] );

	return 0;
}
