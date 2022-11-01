#ifndef PLANT_H_INCLUDED
#define PLANT_H_INCLUDED

#include "object.h"

class seg_flora
{
public:
    Ico icon;
    int R1;
    int R2;
    int G1;
    int G2;
    int B1;
    int B2;

};

class flora_plant
{
public:
    seg_flora leaf1;
    seg_flora leaf2;
    seg_flora petal1;
    seg_flora petal2;
    seg_flora petal3;
    seg_flora petal4;
    int hight;
    int pollinR;
    int pollinG;
    int pollinB;
    int pollinsize;
    void growleaf1(int size);
    void growleaf2(int size);
    void growpetal1(int size);
    void growpetal2(int size);
    void growpetal3(int size);
    void growpetal4(int size);
};

void flora_plant::growleaf1(int size)
{
    if(size > 14)
    {
        size = 14;
    }
    if(size < 0)
    {
        size = 0;
    }
    leaf1.icon = iconlist[size];
}

void flora_plant::growleaf2(int size)
{
    if(size > 14)
    {
        size = 14;
    }
    if(size < 0)
    {
        size = 0;
    }
    leaf2.icon = iconlist[size];
}

void flora_plant::growpetal1(int size)
{
    if(size > 14)
    {
        size = 14;
    }
    if(size < 0)
    {
        size = 0;
    }
    petal1.icon = iconlist[size];
}

void flora_plant::growpetal2(int size)
{
    if(size > 14)
    {
        size = 14;
    }
    if(size < 0)
    {
        size = 0;
    }
    petal2.icon = iconlist[size];
}

void flora_plant::growpetal3(int size)
{
    if(size > 14)
    {
        size = 14;
    }
    if(size < 0)
    {
        size = 0;
    }
    petal3.icon = iconlist[size];
}

void flora_plant::growpetal4(int size)
{
    if(size > 14)
    {
        size = 14;
    }
    if(size < 0)
    {
        size = 0;
    }
    petal4.icon = iconlist[size];
}

void clearplant(HDC dv,unsigned int x,unsigned int y)
{
    int i;
    int j;
    Sleep(1);
    for(i=0; i<32; i++)
    {
        for(j=0; j<32; j++)
        {
            SetPixel(dv,(i-16)+x,(j-16)+y,RGB(200,200,200));
        }
    }
}

void renderplant(HDC dv,flora_plant P,unsigned int x,unsigned int y)
{
    //SetPixel(devicecontext,i,j,RGB(,,));

    int i;
    int j;

    for(i=0; i < 8; i++)
    {
        for(j=0; j < 8; j++)
        {
            if(P.leaf1.icon.alphadat[i][j])
            {
                if(P.leaf1.icon.pixeldat[i][j])
                {
                    SetPixel(dv,(j)+x+1,(i)+y,RGB(P.leaf1.R1,P.leaf1.G1,P.leaf1.B1));
                }
                else
                {
                    SetPixel(dv,(j)+x+1,(i)+y,RGB(P.leaf1.R2,P.leaf1.G2,P.leaf1.B2));
                }
            }
        }
    }

    for(i=0; i < 8; i++)
    {
        for(j=0; j < 8; j++)
        {
            if(P.leaf2.icon.alphadat[i][j])
            {
                if(P.leaf2.icon.pixeldat[i][j])
                {
                    SetPixel(dv,(8-j)+x-9,(i)+y,RGB(P.leaf2.R1,P.leaf2.G1,P.leaf2.B1));
                }
                else
                {
                    SetPixel(dv,(8-j)+x-9,(i)+y,RGB(P.leaf2.R2,P.leaf2.G2,P.leaf2.B2));
                }
            }
        }
    }

    for(i=0; i < 8; i++)
    {
        for(j=0; j < 8; j++)
        {
            if(P.petal1.icon.alphadat[i][j])
            {
                if(P.petal1.icon.pixeldat[i][j])
                {
                    SetPixel(dv,(8-j)+x-9,(i)+y-P.hight-2,RGB(P.petal1.R1,P.petal1.G1,P.petal1.B1));
                }
                else
                {
                    SetPixel(dv,(8-j)+x-9,(i)+y-P.hight-2,RGB(P.petal1.R2,P.petal1.G2,P.petal1.B2));
                }
            }
        }
    }

    for(i=0; i < 8; i++)
    {
        for(j=0; j < 8; j++)
        {
            if(P.petal2.icon.alphadat[i][j])
            {
                if(P.petal2.icon.pixeldat[i][j])
                {
                    SetPixel(dv,(j)+x+1,(i)+y-P.hight-2,RGB(P.petal2.R1,P.petal2.G1,P.petal2.B1));
                }
                else
                {
                    SetPixel(dv,(j)+x+1,(i)+y-P.hight-2,RGB(P.petal2.R2,P.petal2.G2,P.petal2.B2));
                }
            }
        }
    }

    for(i=0; i < 8; i++)
    {
        for(j=0; j < 8; j++)
        {
            if(P.petal3.icon.alphadat[i][j])
            {
                if(P.petal3.icon.pixeldat[i][j])
                {
                    SetPixel(dv,(8-j)+x-9,(8-i)+y-P.hight+6,RGB(P.petal3.R1,P.petal3.G1,P.petal3.B1));
                }
                else
                {
                    SetPixel(dv,(8-j)+x-9,(8-i)+y-P.hight+6,RGB(P.petal3.R2,P.petal3.G2,P.petal3.B2));
                }
            }
        }
    }

    for(i=0; i < 8; i++)
    {
        for(j=0; j < 8; j++)
        {
            if(P.petal4.icon.alphadat[i][j])
            {
                if(P.petal4.icon.pixeldat[i][j])
                {
                    SetPixel(dv,(j)+x+1,(8-i)+y-P.hight+6,RGB(P.petal4.R1,P.petal4.G1,P.petal4.B1));
                }
                else
                {
                    SetPixel(dv,(j)+x+1,(8-i)+y-P.hight+6,RGB(P.petal4.R2,P.petal4.G2,P.petal4.B2));
                }
            }
        }
    }

    for(i=0; i <= P.hight; i++)
    {
        SetPixel(dv,x,y-i+6,RGB(P.leaf1.R2,P.leaf1.G2,P.leaf1.B2));
    }

    if(P.pollinsize > 3)
    {
        if(P.pollinsize < 10)
        {
            SetPixel(dv,x,y-P.hight+6,RGB(P.pollinR,P.pollinG,P.pollinB));
        }
    }
    if(P.pollinsize > 5)
    {
        SetPixel(dv,x+1,y-P.hight+6,RGB(P.pollinR,P.pollinG,P.pollinB));
        SetPixel(dv,x-1,y-P.hight+6,RGB(P.pollinR,P.pollinG,P.pollinB));
        SetPixel(dv,x,y-P.hight+5,RGB(P.pollinR,P.pollinG,P.pollinB));
        SetPixel(dv,x,y-P.hight+7,RGB(P.pollinR,P.pollinG,P.pollinB));
    }
    if(P.pollinsize > 8)
    {
        SetPixel(dv,x-1,y-P.hight+5,RGB(P.pollinR,P.pollinG,P.pollinB));
        SetPixel(dv,x-1,y-P.hight+7,RGB(P.pollinR,P.pollinG,P.pollinB));
        SetPixel(dv,x+1,y-P.hight+5,RGB(P.pollinR,P.pollinG,P.pollinB));
        SetPixel(dv,x+1,y-P.hight+7,RGB(P.pollinR,P.pollinG,P.pollinB));
    }
}

void defaultafyplant(flora_plant *P)
{
    (*P).growleaf1(7);
    (*P).growleaf2(5);
    (*P).growpetal1(3);
    (*P).growpetal2(4);
    (*P).growpetal3(7);
    (*P).growpetal4(9);
    (*P).pollinsize = 5;
    (*P).pollinR = 255;
    (*P).pollinG = 255;
    (*P).pollinB = 0;
    (*P).leaf1.R1 = 0;
    (*P).leaf1.G1 = 100;
    (*P).leaf1.B1 = 0;
    (*P).leaf1.R2 = 0;
    (*P).leaf1.G2 = 255;
    (*P).leaf1.B2 = 0;
    (*P).leaf2.R1 = 0;
    (*P).leaf2.G1 = 100;
    (*P).leaf2.B1 = 0;
    (*P).leaf2.R2 = 0;
    (*P).leaf2.G2 = 255;
    (*P).leaf2.B2 = 0;
    (*P).petal1.R1 = 150;
    (*P).petal1.G1 = 0;
    (*P).petal1.B1 = 255;
    (*P).petal1.R2 = 255;
    (*P).petal1.G2 = 0;
    (*P).petal1.B2 = 255;
    (*P).petal2.R1 = 150;
    (*P).petal2.G1 = 0;
    (*P).petal2.B1 = 255;
    (*P).petal2.R2 = 255;
    (*P).petal2.G2 = 0;
    (*P).petal2.B2 = 255;
    (*P).petal3.R1 = 150;
    (*P).petal3.G1 = 0;
    (*P).petal3.B1 = 255;
    (*P).petal3.R2 = 255;
    (*P).petal3.G2 = 0;
    (*P).petal3.B2 = 255;
    (*P).petal4.R1 = 150;
    (*P).petal4.G1 = 0;
    (*P).petal4.B1 = 255;
    (*P).petal4.R2 = 255;
    (*P).petal4.G2 = 0;
    (*P).petal4.B2 = 255;
    (*P).hight = 10;
}

#endif
