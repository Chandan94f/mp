#include <bits/stdc++.h>
using namespace std;


int main()
{


    int arr[m] = {-1};

    for(int j=1; j<=m; j++) pardo
    {
        WITNESS(j) = 0;
    }

    if(PATTERN(1) != PATTERN(2))
    {
        // start stage 1 at box 2


        // code for BOX-4
        if(LEFT(k, 2) != NULL)
        {
            int x = LEFT(k, 2);

            for(int j=1; j<=pow(2, k+2)-x+1 ; j++) pardo
            {
                if(PATTERN(j) != PATTERN(x-1+j))
                {
                    WITNESS[x] = j;
                }
            }

            if(WITNESS[x] == 0)
            {
                PERIODICITY[k+1] = x-1;
            }
        }

        // code for BOX-3

        if(LEFT[k, 2*a] == NULL)
        {
            LEFT[k+1, a] = LEFT[k, 2*a-1];
        }
        else if(LEFT[k, 2*a-1] == NULL)
        {
            LEFT[k+1, a] = LEFT[k, 2*a];
        }
        else
        {
            w = WITNESS[j1-j2+1];
            
            x = PATTERN[w];
            y = PATTERN[j1-j2+w];
            z = PATTERN[j1-1+w];

            if(z!=y)
            {
                WITNESS[j2] = j1-j2+w;
            }

            if(z!=x)
            {
                WITNESS[j1] = w;
            }

            if(WITNESS[j2]==0)
            {
                LEFT(k+1, a) = j2;
            }
            else if(WITNESS[j1]==0)
            {
                LEFT(k+1, a) = j1;
            }
            else
            {
                LEFT[k+1, a] = NULL;
            }

        }




    }
    else
    {
        // start stage at box 4 (enter a periodic mode)
    }



    return 0;
}