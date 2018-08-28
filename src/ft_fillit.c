#include "../includes/fillit.h"



void ft_fillone(variables gl,int cnv[gl.m][gl.m],int y,int x)
{
    int yt;
    int xt;

    yt = -1;
    while (++yt < gl.ttr[gl.tet].y )
    {
        xt = -1;
        while (++xt < gl.ttr[gl.tet].x)
            if (gl.ttr[gl.tet].tt[yt][xt] > 0)
                cnv[y + yt][x + xt] = gl.ttr[gl.tet].tt[yt][xt];
    }
}

int ft_chekones(variables gl,int cnv[gl.m][gl.m],int yc,int xc)
{

    int xt;
    int yt;
    int x;

    xt = -1;
    x = xc;
    yt = 0;
    if(yc + gl.ttr[gl.tet].y > gl.m)
        return 0;
    while (gl.ttr[gl.tet].tt[0][++xt] == 0 && x > 0)
        x--;
    if(x + gl.ttr[gl.tet].x > gl.m)
        return 0;
    while (yt < gl.ttr[gl.tet].y)
    {
        xt = -1;
        while (++xt < gl.ttr[gl.tet].x)
            if(cnv[yc + yt][x + xt] != 0 && gl.ttr[gl.tet].tt[yt][xt] != 0)
                return 0;
        yt++;
    }
    ft_fillone(gl,cnv,yc,x);
    return 1;
}

void ft_afis(int m,int cnv[m][m])
{
    int x;
    int y;

    y = -1;
    while(++y < m)
    {
        x = -1;
        while(++x < m)
        {
            if(cnv[y][x] == 0)
                write(1,".",1);
            else
                write(1,&cnv[y][x],1);
        }
        write(1,"\n",1);
    }
}

void ft_copy(int m,int cnv[m][m],int cpy[m][m])
{
    int y;
    int x;

    y = -1;
    while (++y < m)
    {
        x = -1;
        while (++x < m)
            cpy[y][x] = cnv[y][x];
    }
}

int ft_pass(variables gl,int cnv [gl.m][gl.m],int y,int x)
{
    int cpy[gl.m][gl.m];

    if (gl.tet == gl.vld)
            {
                ft_afis(gl.m,cnv);
                exit(0);
            }
    ft_copy(gl.m,cnv,cpy);
    while (y < gl.m)
    {
        while (x < gl.m)
        {
            if (ft_chekones(gl, cpy, y, x))
            {
                gl.tet++;
                ft_pass(gl, cpy, 0, 0);
                gl.tet--;
            }
            ft_copy(gl.m,cnv,cpy);
            x++;
            }
            x = 0;
            y++;
        }
    return 0;
}

void ft_fillzero(int m,int cnv[m][m])
{
    int x;
    int y;

    y = -1;
    while (++y < m)
    {
        x = -1;
        while (++x < m)
            cnv[y][x] = 0;
    }
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
    while(!ft_pass(gl, cnv, 0, 0))
        ft_fill(m + 1,gl.vld, gl.ttr);
}
