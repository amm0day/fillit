
#include "../includes/fillit.h"


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
void ft_afis(int m,int cnv[m][m])
{
    int xa;
    int ya;

    ya = -1;
    while (++ya < m)
    {
        xa = -1;
        while (++xa < m)
            if(cnv[ya][xa] == 0)
                printf(".");
            else
                printf("%c", cnv[ya][xa]);
        puts(" ");
    }
}
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

int ft_pass(variables gl ,int cnv[gl.m][gl.m],int ya,int xa)
{
    int cpy[gl.m][gl.m];
    int yt;
    int xt;
    int count = 0;

    ft_copy(gl.m,cnv,cpy);
    xa--;
    while (++xa < gl.m && gl.tet < gl.vld)
    {
        if (cpy[ya][xa] > 0 || ft_chek(gl.m, cpy, xa, ya, gl.tet, gl.ttr))
            continue;
        yt = -1;
        while (++yt < gl.ttr[gl.tet].y)
        {
            xt = -1;
            while (++xt < gl.ttr[gl.tet].x)
                if (gl.ttr[gl.tet].tt[yt][xt] > 0)
                    cpy[ya + yt][xa + xt] = gl.ttr[gl.tet].tt[yt][xt];
        }
        count = 1;
        break;
    }
    if (count == 0)
        return 0;
    yt = 0;
    gl.tet++;
    while (ft_pass(gl, cpy, yt, 0) == 0 && ++yt < gl.m && gl.tet < gl.vld);
    gl.tet--;
    if (gl.tet == gl.vld - 1|| gl.tet < ft_pass(gl, cnv, ya, xa + 1)) {
        if (gl.tet == gl.vld - 1)
        {
            ft_afis(gl.m, cpy);
            exit(0);
        }
    }
    return 0;
}
void ft_fill(int m,int vld,t_tetris *ttr)
{
    variables gl;
    int cnv[m][m];

    gl.ttr = ttr;
    gl.m = m;
    gl.vld = vld;
    gl.tet = 0;
    ft_fillzero(gl.m,cnv);
//    printf("%d\n",m);
//    printf("%d",m);
    while(!ft_pass(gl, cnv, 0, 0))
        ft_fill(gl.m + 1,gl.vld, gl.ttr);
}
