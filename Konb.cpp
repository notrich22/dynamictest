#include <stdio.h>
#include <stdlib.h>
#include "Header.h"
int n = 8; 
int sqr = n * n;
int dx[9] = { 0,  2,  1, -1, -2, -2, -1, 1 ,2 };
int dy[9] = { 0, -1, -2, -2,  1, -1,  2, 2, 1 };
char txt[80];
int board[20][20];
int it = 1000;
int ntry[1000];
int set(int i, int x, int y)
{
    if (it > 0)
        --it;
    else
        return 1;
    ntry[i - 1] += 1;
    for (int k = 1; k <= n; ++k)
    {
        txt[0] = 0;
        for (int j = 1; j <= n; ++j)
            sprintf_s(txt, "%s%4d", txt, board[k][j]);
        printf("%s\n", txt);
    }
    printf("%d\n\n", i);
    int j, u, v, q1 = 0;
    for (j = 1; (!q1) && (j <= 8); j++)
    {
        u = x + dx[j];
        v = y + dy[j];
        if (1 <= u && u <= n &&
            1 <= v && v <= n &&
            board[u][v] == 0)
        {
            board[u][v] = i;
            if (i < sqr)
            {
                q1 = set(i + 1, u, v);
                if (q1 == 0) board[u][v] = 0;
            }
            else q1 = 1;
        }
    }
    return q1;
}
int konb()
{
    board[1][1] = 1;
    for (int k = 0; k < 1000; ++k)
        ntry[k] = 0;
    set(2, 1, 1);
    for (int k = 0; k < n * n; ++k)
        printf("%d - %d\n", k, ntry[k]);
    for (int i = 1; i <= n; ++i)
    {
        txt[0] = 0;
        for (int j = 1; j <= n; ++j)
            sprintf_s(txt, "%s%4d", txt, board[i][j]);
        printf("%s\n", txt);
    }
    return 0;
}