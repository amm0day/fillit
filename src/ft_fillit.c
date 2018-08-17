
#include "../includes/fillit.h"

void ft_copy(int n,int a[n][n],int copy[n][n])
{
    int x;
    int y = -1;

    while(++y < n)
    {
        x = -1;
        while (++x < n)
            copy[y][x] = a[y][x];
    }
}

int ft_chek(int n,int a[n][n],int xa,int ya,int tet,t_tetris *ttr)
{
    int i;
    int j = -1;

    i = 0;
    if(xa + ttr[tet].x > n || ya + ttr[tet].y > n)
        return 1;
    while (i < ttr[tet].y)
    {
        while (++j < ttr[tet].x)
            if(a[ya + i][xa + j] != 0 && ttr[tet].tt[i][j] != 0)
                break;
        if(j != ttr[tet].x)
            break;
        j = -1;
        i++;
    }
    if (i != ttr[tet].y)
        return 1;
    return 0;
}

void ft_fillzero(int n,int a[n][n])
{
    int ya = 0;
    int xa;

    while (ya < n)
    {
        xa = 0;
        while (xa < n)
        {
            a[ya][xa] = 0;
            xa++;
        }
        ya++;
    }
}
void ft_afis(int n,int copy[n][n])
{
    int xa;
    int ya;
    ya = -1;
    while (++ya < n)
    {
        xa = -1;
        while (++xa < n)
            if(copy[ya][xa] == 0)
                printf(".");
            else
                printf("%c", copy[ya][xa]);
        puts(" ");
    }
}

int ft_pass(int n,int a[n][n],int tet,int ya,int xa,t_tetris *ttr,int vld)
{
    int copy[n][n];
    int yt;
    int xt;
    int count = 0;
    int m = vld;

    ft_copy(n, a, copy);
    xa--;
    while (++xa < n && tet < m)
    {
        if (copy[ya][xa] > 0)
            continue;
        if (ft_chek(n, copy, xa, ya, tet, ttr))
            continue;
        yt = -1;
        while (++yt < ttr[tet].y)
        {
            xt = -1;
            while (++xt < ttr[tet].x)
                if (ttr[tet].tt[yt][xt] > 0)
                    copy[ya + yt][xa + xt] = ttr[tet].tt[yt][xt];
        }
        count = 1;
        break;
    }
    if (count == 0)
        return 0;
    yt = 0;
    while (ft_pass(n, copy, tet + 1, yt, 0, ttr, vld) == 0 && ++yt < n && tet < m - 1);
    if (tet == m - 1 ||
        (tet < ft_pass(n, a, tet, ya, xa + 1, ttr, vld) || tet < ft_pass(n, a, tet, ya + 1, 0, ttr, vld)))
        if (tet == m - 1)
        {
            ft_afis(n,copy);
                exit(0);
        }
    return tet;
}
void ft_fill(int n,int tet,t_tetris *ttr)
{
    int canvas[n][n];
    ft_fillzero(n, canvas);
    while(!ft_pass(n, canvas, 0, 0, 0,ttr,tet))
        ft_fill(n + 1,tet, ttr);
}
