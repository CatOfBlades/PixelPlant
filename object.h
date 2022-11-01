#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

//#define NO_RAINFALL

#include <stack>
#include <math.h>

float plantwater = 0;

int RainFell = 1;

class loc
{
public:
    int X;
    int Y;
    int Z;
};

class Ico
{
public:
    bool pixeldat[8][8];
    bool alphadat[8][8];
};

float PT(float a,float b)
{
    float c;
    c = powf(a,2)+powf(b,2);
    return sqrtf(c);
}

//uint8_t
bool isinradius(int r,loc L1,loc L2)
{
    float x,y;
    if(L1.X == L2.X)
    {
        x = 0;
        if(L1.Y == L2.Y)
        {
            y = 0;
            return 1;
        }
        y = abs(L1.Y-L2.Y);
        if(y <= r)
        {
            return 1;
        }
        else return 0;
    }
    else if(L1.Y == L2.Y)
    {
        x = abs(L1.X-L2.X);
        y=0;
        if(x <= r)
        {
            return 1;
        }
        else return 0;
    }
    y = abs(L1.Y-L2.Y);
    x = abs(L1.X-L2.X);
    if(r > PT(x,y))
    {
        return 1;
    }
    else return 0;
}

void renderIco(HDC dv,Ico I,unsigned int x,unsigned int y,unsigned int r1,unsigned int g1,unsigned int b1,unsigned int r2,unsigned int g2,unsigned int b2,bool xinv,bool yinv)
{
    unsigned int i, j;
    for(i=0; i < 8; i++)
    {
        for(j=0; j < 8; j++)
        {
            if(I.alphadat[i][j])
            {
                if(I.pixeldat[i][j])
                {
                    if(xinv)
                    {
                        if(yinv)
                        {
                            SetPixel(dv,(8-j)+x-9,(8-i)+y-9,RGB(r1,g1,b1));
                        }
                        else
                        {
                            SetPixel(dv,(8-j)+x-9,(i)+y,RGB(r1,g1,b1));
                        }
                    }
                    else
                    {
                        SetPixel(dv,(j)+x,(i)+y,RGB(r1,g1,b1));
                    }
                }
                else
                {
                    if(xinv)
                    {
                        if(yinv)
                        {
                            SetPixel(dv,(8-j)+x-9,(8-i)+y-9,RGB(r2,g2,b2));
                        }
                        else
                        {
                            SetPixel(dv,(8-j)+x-9,(i)+y,RGB(r2,g2,b2));
                        }
                    }
                    else
                    {
                        SetPixel(dv,(j)+x,(i)+y,RGB(r2,g2,b2));
                    }
                }
            }
        }
    }
}

Ico iconlist[22];

void InitIcons()
{


    iconlist[0].pixeldat = {{{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{1},{0},{0},{0},{0},{0},{0},{0}}
    };

    iconlist[1].pixeldat = {{{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{1},{0},{0},{0},{0},{0},{0}},
        {{1},{0},{0},{0},{0},{0},{0},{0}}
    };

    iconlist[2].pixeldat = {{{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{1},{1},{0},{0},{0},{0},{0},{0}},
        {{1},{0},{0},{0},{0},{0},{0},{0}}
    };

    iconlist[3].pixeldat = {{{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{1},{1},{0},{0},{0},{0},{0},{0}},
        {{1},{1},{0},{0},{0},{0},{0},{0}}
    };

    iconlist[4].pixeldat = {{{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{1},{1},{1},{0},{0},{0},{0},{0}},
        {{1},{1},{0},{0},{0},{0},{0},{0}}
    };

    iconlist[5].pixeldat = {{{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{1},{0},{0},{0},{0},{0}},
        {{1},{1},{1},{0},{0},{0},{0},{0}},
        {{1},{1},{0},{0},{0},{0},{0},{0}}
    };


    iconlist[6].pixeldat = {{{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{1},{1},{0},{0},{0},{0},{0}},
        {{1},{1},{1},{0},{0},{0},{0},{0}},
        {{1},{1},{0},{0},{0},{0},{0},{0}}
    };


    iconlist[7].pixeldat = {{{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{1},{1},{1},{0},{0},{0},{0}},
        {{1},{0},{1},{0},{0},{0},{0},{0}},
        {{1},{1},{0},{0},{0},{0},{0},{0}}
    };


    iconlist[8].pixeldat = {{{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{1},{1},{0},{0},{0},{0}},
        {{0},{1},{1},{0},{0},{0},{0},{0}},
        {{1},{0},{1},{0},{0},{0},{0},{0}},
        {{1},{1},{0},{0},{0},{0},{0},{0}}
    };

    iconlist[9].pixeldat = {{{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{1},{1},{0},{0},{0},{0}},
        {{0},{1},{0},{1},{0},{0},{0},{0}},
        {{1},{0},{1},{0},{0},{0},{0},{0}},
        {{1},{1},{1},{0},{0},{0},{0},{0}}
    };

    iconlist[10].pixeldat = {{{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{1},{1},{1},{0},{0},{0}},
        {{1},{1},{0},{1},{0},{0},{0},{0}},
        {{1},{0},{0},{1},{0},{0},{0},{0}},
        {{1},{1},{1},{0},{0},{0},{0},{0}}
    };

    iconlist[11].pixeldat = {{{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{1},{0},{0},{0},{0}},
        {{0},{1},{1},{1},{0},{0},{0},{0}},
        {{1},{0},{0},{1},{0},{0},{0},{0}},
        {{1},{1},{0},{1},{0},{0},{0},{0}},
        {{1},{1},{1},{0},{0},{0},{0},{0}}
    };

    iconlist[12].pixeldat = {{{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{1},{1},{1},{0},{0},{0}},
        {{0},{1},{0},{0},{1},{0},{0},{0}},
        {{1},{0},{0},{0},{1},{0},{0},{0}},
        {{1},{1},{0},{1},{0},{0},{0},{0}},
        {{1},{1},{1},{0},{0},{0},{0},{0}}
    };

    iconlist[13].pixeldat = {{{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{1},{1},{0},{0},{0}},
        {{0},{0},{1},{0},{1},{0},{0},{0}},
        {{0},{1},{0},{0},{1},{0},{0},{0}},
        {{1},{0},{0},{0},{1},{0},{0},{0}},
        {{1},{1},{0},{1},{0},{0},{0},{0}},
        {{1},{1},{1},{0},{0},{0},{0},{0}}
    };

    iconlist[14].pixeldat = {{{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{1},{1},{0},{0}},
        {{0},{0},{1},{1},{0},{1},{0},{0}},
        {{0},{1},{0},{0},{1},{0},{0},{0}},
        {{1},{0},{0},{0},{1},{0},{0},{0}},
        {{1},{0},{0},{1},{0},{0},{0},{0}},
        {{1},{1},{1},{0},{0},{0},{0},{0}}
    };

    iconlist[15].pixeldat = {{{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{1},{0},{1},{0},{0}},
        {{0},{0},{1},{0},{1},{0},{1},{0}},
        {{0},{1},{0},{0},{0},{0},{1},{0}},
        {{0},{1},{0},{0},{1},{0},{1},{0}},
        {{0},{0},{1},{1},{0},{1},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}}
    };

    iconlist[16].pixeldat = {{{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{1},{0},{0},{0},{0},{0}},
        {{0},{0},{1},{0},{0},{0},{0},{0}},
        {{0},{1},{0},{1},{0},{0},{0},{0}},
        {{0},{1},{0},{1},{0},{0},{0},{0}},
        {{0},{0},{1},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}}
    };

    iconlist[17].pixeldat = {{{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{1},{0},{0},{0},{0},{0},{0}},
        {{0},{1},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}}
    };

    iconlist[18].pixeldat = {{{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{1},{1},{1},{0},{0},{0}},
        {{0},{1},{0},{0},{0},{1},{0},{0}},
        {{0},{1},{0},{0},{0},{1},{0},{0}},
        {{0},{1},{0},{0},{0},{1},{0},{0}},
        {{0},{0},{1},{1},{1},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}}
    };

    iconlist[19].pixeldat = {{{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{1},{0},{0},{1},{0}},
        {{0},{0},{1},{0},{0},{1},{0},{0}},
        {{0},{1},{0},{0},{1},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}}
    };

    iconlist[20].pixeldat = {{{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{1},{0},{0},{1},{1},{0},{1},{1}},
        {{0},{1},{1},{0},{0},{1},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}}
    };

    iconlist[21].pixeldat = {{{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{1},{0},{0},{0},{0}},
        {{0},{0},{0},{1},{0},{0},{0},{0}},
        {{0},{0},{0},{1},{0},{0},{0},{0}},
        {{0},{0},{0},{1},{0},{0},{0},{0}},
        {{0},{0},{0},{1},{0},{0},{0},{0}},
        {{0},{0},{0},{1},{0},{0},{0},{0}},
        {{0},{0},{0},{1},{0},{0},{0},{0}}
    };





    iconlist[0].alphadat = {{{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{1},{0},{0},{0},{0},{0},{0},{0}}
    };

    iconlist[1].alphadat = {{{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{1},{0},{0},{0},{0},{0},{0}},
        {{1},{0},{0},{0},{0},{0},{0},{0}}
    };

    iconlist[2].alphadat = {{{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{1},{1},{0},{0},{0},{0},{0},{0}},
        {{1},{0},{0},{0},{0},{0},{0},{0}}
    };

    iconlist[3].alphadat = {{{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{1},{1},{0},{0},{0},{0},{0},{0}},
        {{1},{1},{0},{0},{0},{0},{0},{0}}
    };

    iconlist[4].alphadat = {{{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{1},{1},{1},{0},{0},{0},{0},{0}},
        {{1},{1},{0},{0},{0},{0},{0},{0}}
    };

    iconlist[5].alphadat = {{{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{1},{0},{0},{0},{0},{0}},
        {{1},{1},{1},{0},{0},{0},{0},{0}},
        {{1},{1},{0},{0},{0},{0},{0},{0}}
    };


    iconlist[6].alphadat = {{{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{1},{1},{0},{0},{0},{0},{0}},
        {{1},{1},{1},{0},{0},{0},{0},{0}},
        {{1},{1},{0},{0},{0},{0},{0},{0}}
    };


    iconlist[7].alphadat = {{{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{1},{1},{1},{0},{0},{0},{0}},
        {{1},{1},{1},{0},{0},{0},{0},{0}},
        {{1},{1},{0},{0},{0},{0},{0},{0}}
    };


    iconlist[8].alphadat = {{{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{1},{1},{0},{0},{0},{0}},
        {{0},{1},{1},{0},{0},{0},{0},{0}},
        {{1},{1},{1},{0},{0},{0},{0},{0}},
        {{1},{1},{0},{0},{0},{0},{0},{0}}
    };

    iconlist[9].alphadat = {{{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{1},{1},{0},{0},{0},{0}},
        {{0},{1},{1},{1},{0},{0},{0},{0}},
        {{1},{1},{1},{0},{0},{0},{0},{0}},
        {{1},{1},{1},{0},{0},{0},{0},{0}}
    };

    iconlist[10].alphadat = {{{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{1},{1},{1},{0},{0},{0}},
        {{1},{1},{1},{1},{0},{0},{0},{0}},
        {{1},{1},{1},{1},{0},{0},{0},{0}},
        {{1},{1},{1},{0},{0},{0},{0},{0}}
    };

    iconlist[11].alphadat = {{{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{1},{0},{0},{0},{0}},
        {{0},{1},{1},{1},{0},{0},{0},{0}},
        {{1},{1},{1},{1},{0},{0},{0},{0}},
        {{1},{1},{1},{1},{0},{0},{0},{0}},
        {{1},{1},{1},{0},{0},{0},{0},{0}}
    };

    iconlist[12].alphadat = {{{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{1},{1},{1},{0},{0},{0}},
        {{0},{1},{1},{1},{1},{0},{0},{0}},
        {{1},{1},{1},{1},{1},{0},{0},{0}},
        {{1},{1},{1},{1},{0},{0},{0},{0}},
        {{1},{1},{1},{0},{0},{0},{0},{0}}
    };

    iconlist[13].alphadat = {{{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{1},{1},{0},{0},{0}},
        {{0},{0},{1},{1},{1},{0},{0},{0}},
        {{0},{1},{1},{1},{1},{0},{0},{0}},
        {{1},{1},{1},{1},{1},{0},{0},{0}},
        {{1},{1},{1},{1},{0},{0},{0},{0}},
        {{1},{1},{1},{0},{0},{0},{0},{0}}
    };

    iconlist[14].alphadat = {{{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{1},{1},{0},{0}},
        {{0},{0},{1},{1},{1},{1},{0},{0}},
        {{0},{1},{1},{1},{1},{0},{0},{0}},
        {{1},{1},{1},{1},{1},{0},{0},{0}},
        {{1},{1},{1},{1},{0},{0},{0},{0}},
        {{1},{1},{1},{0},{0},{0},{0},{0}}
    };

    iconlist[15].alphadat = {{{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{1},{0},{1},{0},{0}},
        {{0},{0},{1},{1},{1},{1},{1},{0}},
        {{0},{1},{1},{1},{1},{1},{1},{0}},
        {{0},{1},{1},{1},{1},{1},{1},{0}},
        {{0},{0},{1},{1},{0},{1},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}}
    };

    iconlist[16].alphadat = {{{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{1},{0},{0},{0},{0},{0}},
        {{0},{0},{1},{0},{0},{0},{0},{0}},
        {{0},{1},{1},{1},{0},{0},{0},{0}},
        {{0},{1},{1},{1},{0},{0},{0},{0}},
        {{0},{0},{1},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}}
    };

    iconlist[17].alphadat = {{{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{1},{0},{0},{0},{0},{0},{0}},
        {{0},{1},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}}
    };

    iconlist[18].alphadat = {{{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{1},{1},{1},{0},{0},{0}},
        {{0},{1},{1},{1},{1},{1},{0},{0}},
        {{0},{1},{1},{1},{1},{1},{0},{0}},
        {{0},{1},{1},{1},{1},{1},{0},{0}},
        {{0},{0},{1},{1},{1},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}}
    };

    iconlist[19].alphadat = {{{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{1},{0},{0},{1},{0}},
        {{0},{0},{1},{0},{0},{1},{0},{0}},
        {{0},{1},{0},{0},{1},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}}
    };

    iconlist[20].alphadat = {{{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{0},{0},{0},{0},{0}},
        {{1},{0},{0},{1},{1},{0},{1},{1}},
        {{1},{1},{1},{1},{1},{1},{1},{1}},
        {{1},{1},{1},{1},{1},{1},{1},{1}}
    };

    iconlist[21].alphadat = {{{0},{0},{0},{0},{0},{0},{0},{0}},
        {{0},{0},{0},{1},{0},{0},{0},{0}},
        {{0},{0},{0},{1},{0},{0},{0},{0}},
        {{0},{0},{0},{1},{0},{0},{0},{0}},
        {{0},{0},{0},{1},{0},{0},{0},{0}},
        {{0},{0},{0},{1},{0},{0},{0},{0}},
        {{0},{0},{0},{1},{0},{0},{0},{0}},
        {{0},{0},{0},{1},{0},{0},{0},{0}}
    };

}

class Miscobj
{
public:
    Ico icon;
    int R1;
    int R2;
    int G1;
    int G2;
    int B1;
    int B2;
    //loc oldlocation;
    loc location;
    void update();
};

Miscobj ObjList[20];
//std::stack<Miscobj*> ObjList;
std::stack<Miscobj*> ObjStack;
std::stack<Miscobj*> RainStack;
Miscobj *P_Rain;

Miscobj Cloud;
Miscobj Sun;
Miscobj Ground1;
Miscobj Ground2;
Miscobj Ground3;
Miscobj Ground4;
Miscobj Ground5;
Miscobj Raindrop;

void InitilizeObjs()
{

    Sun.icon = iconlist[18];
    Sun.R1 = 255;
    Sun.G1 = 0;
    Sun.B1 = 0;
    Sun.R2 = 255;
    Sun.G2 = 255;
    Sun.B2 = 0;
    //Sun.oldlocation.X = 150; Sun.oldlocation.Y = 10;
    Sun.location.X = 150;
    Sun.location.Y = 10;

    Ground1.icon = iconlist[20];
    Ground1.R1 = 128;
    Ground1.G1 = 64;
    Ground1.B1 = 0;
    Ground1.R2 = 128;
    Ground1.G2 = 128;
    Ground1.B2 = 64;
    //Ground1.oldlocation.X = 80; Ground1.oldlocation.Y = 102;
    Ground1.location.X = 80;
    Ground1.location.Y = 102;

    Ground2.icon = iconlist[20];
    Ground2.R1 = 128;
    Ground2.G1 = 64;
    Ground2.B1 = 0;
    Ground2.R2 = 128;
    Ground2.G2 = 128;
    Ground2.B2 = 64;
    //Ground2.oldlocation.X = 88; Ground2.oldlocation.Y = 102;
    Ground2.location.X = 88;
    Ground2.location.Y = 102;

    Ground3.icon = iconlist[20];
    Ground3.R1 = 128;
    Ground3.G1 = 64;
    Ground3.B1 = 0;
    Ground3.R2 = 128;
    Ground3.G2 = 128;
    Ground3.B2 = 64;
    //Ground3.oldlocation.X = 96; Ground3.oldlocation.Y = 102;
    Ground3.location.X = 96;
    Ground3.location.Y = 102;

    Ground4.icon = iconlist[20];
    Ground4.R1 = 128;
    Ground4.G1 = 64;
    Ground4.B1 = 0;
    Ground4.R2 = 128;
    Ground4.G2 = 128;
    Ground4.B2 = 64;
    //Ground4.oldlocation.X = 104; Ground4.oldlocation.Y = 102;
    Ground4.location.X = 104;
    Ground4.location.Y = 102;

    Ground5.icon = iconlist[20];
    Ground5.R1 = 128;
    Ground5.G1 = 64;
    Ground5.B1 = 0;
    Ground5.R2 = 128;
    Ground5.G2 = 128;
    Ground5.B2 = 64;
    //Ground5.oldlocation.X = 112; Ground5.oldlocation.Y = 102;
    Ground5.location.X = 112;
    Ground5.location.Y = 102;

    Cloud.icon = iconlist[15];
    Cloud.R1 = 100;
    Cloud.G1 = 100;
    Cloud.B1 = 255;
    Cloud.R2 = 128;
    Cloud.G2 = 255;
    Cloud.B2 = 255;
    //Cloud.oldlocation.X = 10; Cloud.oldlocation.Y = 20;
    Cloud.location.X = 10;
    Cloud.location.Y = 20;

    Raindrop.icon = iconlist[16];
    Raindrop.R1 = 0;
    Raindrop.G1 = 0;
    Raindrop.B1 = 128;
    Raindrop.R2 = 0;
    Raindrop.G2 = 0;
    Raindrop.B2 = 255;
    //Raindrop.oldlocation.X = 1; Raindrop.oldlocation.Y = 1;
    Raindrop.location.X = 1;
    Raindrop.location.Y = 1;

    ObjStack.push(&Ground5);
    ObjStack.push(&Ground4);
    ObjStack.push(&Ground3);
    ObjStack.push(&Ground2);
    ObjStack.push(&Ground1);
    ObjStack.push(&Sun);
    ObjStack.push(&Cloud);
}


void UpdateObjs()
{
    Miscobj* R;
    while(RainStack.size() > 0)
    {
        R = RainStack.top();
        //(*R).oldlocation.X = (*R).location.X;
        //(*R).oldlocation.Y = (*R).location.Y;
        (*R).location.X = Cloud.location.X;
        (*R).location.Y = Cloud.location.Y+8;
        ObjStack.push(R);
        RainStack.pop();
        P_Rain = R;
    }
#ifndef NO_RAINFALL

    if(P_Rain)
    {
        //(*P_Rain).oldlocation.Y = (*P_Rain).location.Y;
        if((*P_Rain).location.Y < 103)
        {
            //RainStack.pop();
            (*P_Rain).location.Y += 1;
        }
        else
        {
            (*P_Rain).location.X = 70000;
            RainFell = 1;
        }
        if((*P_Rain).location.Y == 99)
        {
            plantwater += 0.7;
        }
    }

#endif
}


void Renderobjs(HDC dv)
{
    std::stack<Miscobj*> A;
    Miscobj *C;
    while(ObjStack.size() > 0)
    {
        C = ObjStack.top();
        //renderIco(dv,(*C).icon,(*C).oldlocation.X,(*C).oldlocation.Y,210,210,210,210,210,210,0,0);
        renderIco(dv,(*C).icon,(*C).location.X,(*C).location.Y,(*C).R1,(*C).G1,(*C).B1,(*C).R2,(*C).G2,(*C).B2,0,0);
        A.push(C);
        ObjStack.pop();
    }
    while(A.size() > 0)
    {
        C = A.top();
        ObjStack.push(C);
        A.pop();
    }
}

#endif