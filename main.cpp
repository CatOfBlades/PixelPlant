#define WINVER 0x0410
//#include <wingdi.h>
#include <windows.h>
#include "plant.h"
#include <time.h>
#include "colorcode.hpp"

#define PLANT_X 95
#define PLANT_Y 100

long int StartTime;
long int UpTime;

LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

char szClassName[ ] = "CodeBlocksWindowsApp";

int cloudpos = 10;
int cloudlpos = 0;
bool cloudflop = 0;

HWND g_hwnd;
HDC g_hdc;
HDC g_desktop;

flora_plant g_plant;
float leafsize = 1;
float planthight = 0;
float plantfood = 0;

float plantsun = 0;
float plantenergy = 0;

int NewTime;
int OldTime;

void UpdatePlant(flora_plant* P)
{
    if(plantwater >= 0.5)
    {
        if(plantsun >= 0.5)
        {
            plantwater -= 0.5;
            plantsun -= 0.5;
            plantenergy += 2;
        }
    }
    int RN;
    if(plantenergy >= 10)
    {
        //RN = rand();
        RN = 101;
        plantenergy -= 10;
        if(RN > 100)
        {
            planthight += 0.5;
        }
        if(RN > 50)
        {
            leafsize += 0.5;
        }
    }
    (*P).growleaf1(leafsize);
    (*P).growleaf2(leafsize);
    (*P).hight = ((int)planthight)+1;
    return;
}

int WINAPI WinMain (HINSTANCE hThisInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpszArgument,
                    int nCmdShow)
{
    StartTime = GetTickCount();
    HWND hwnd;
    MSG messages;
    WNDCLASSEX wincl;

    //g_plant.hight = 3;
    InitIcons();
    InitilizeObjs();
    defaultafyplant(&g_plant);

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;
    wincl.style = CS_DBLCLKS;
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;
    wincl.cbClsExtra = 0;
    wincl.cbWndExtra = 0;
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;
    hwnd = CreateWindowEx (
               0,
               szClassName,
               "Plants",
               WS_OVERLAPPEDWINDOW,
               CW_USEDEFAULT,
               CW_USEDEFAULT,
               200,
               200,
               HWND_DESKTOP,
               NULL,
               hThisInstance,
               NULL
           );
    ShowWindow (hwnd, nCmdShow);
    g_hwnd = hwnd;
    g_hdc=GetDC(hwnd);
    g_desktop=GetDC(0);
    while (GetMessage (&messages, NULL, 0, 0))
    {
        TranslateMessage(&messages);
        DispatchMessage(&messages);
        UpTime = GetTickCount()-StartTime;
        cloudlpos = cloudpos;
        cloudpos = 200-((UpTime/50)%200);
        /*
        if(cloudflop)
        {
            cloudlpos = cloudpos;
            cloudpos -= 1;
            cloudpos += (rand()/15000);
            if(cloudpos < -5)
            {
                cloudlpos = cloudpos+1;
                cloudpos = 200;
            }
        }
        cloudflop = !cloudflop;
        */
        Sleep(1);
    }
    return messages.wParam;
}

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
        //PaintDesktop(g_hdc);
        break;
    case WM_SHOWWINDOW:
        //PaintDesktop(g_hdc);
        break;
    case WM_SETFOCUS:
        //PaintDesktop(g_hdc);
        break;
    case WM_DESTROY:
        PostQuitMessage (0);
        break;
    case WM_PAINT:
        //TransparentBlt(g_hdc,0,0,32,32,g_desktop,0,0,32,32,10);
        //PaintDesktop(g_hdc);
        //UpdateColors(g_hdc);
        //wglSwapLayerBuffers(g_hdc,5);
        //SwapBuffers(g_hdc);
        NewTime = time(0);
        OldTime = NewTime;
        //FloodFill(g_hdc,32,32,RGB(0,0,0));
        //GdiFlush();
        //Cloud.oldlocation.X = cloudlpos;
        Cloud.location.X = cloudpos;
        UpdatePlant(&g_plant);
        UpdateObjs();
        renderplant(g_hdc,g_plant,PLANT_X,PLANT_Y);
        //renderplant(wglGetCurrentDC(),g_plant,PLANT_X,PLANT_Y);
        //SetTextColor(g_hdc,RGB(1,1,255));
        //TextOutA(g_hdc,0,0,"jjjjjjj",7);
        Renderobjs(g_hdc);
        SetPixel(g_hdc,10,10,ConvertToRGB(BLACK));
        //renderIco(g_hdc,iconlist[15],cloudlpos,20,210,210,210,210,210,210,0,0);
        //renderIco(g_hdc,iconlist[15],cloudpos,20,0,0,255,0,100,255,0,0);
        Sleep(1);
        NewTime = time(0);
        if(NewTime > OldTime)
        {
            plantsun += 0.2f;
        }
        //renderplant(g_hdc,g_plant,60,30);
        break;
    case WM_KEYDOWN:
    {
        switch (wParam)
        {
        case VK_SPACE:
            if(RainFell)
            {
                RainStack.push(&Raindrop);
                RainFell = 0;
                //plantenergy += 0.5;
                //plantwater += 0.7;
            }
            break;
        case VK_UP:
            /*
            g_plant.hight += 1;
            //clearplant(g_hdc,PLANT_X,PLANT_Y);
            PaintDesktop(g_hdc);
            */
            break;
        case VK_DOWN:
            /*
            g_plant.hight += -1;
            //clearplant(g_hdc,PLANT_X,PLANT_Y);
            PaintDesktop(g_hdc);
            */
            break;
        case VK_LEFT:
            /*
            if(leafsize > 0)
            {
                leafsize -= 1;
                g_plant.hight = leafsize;
                g_plant.pollinsize = leafsize;
                g_plant.growleaf1(leafsize);
                g_plant.growleaf2(leafsize);
                g_plant.growpetal1(leafsize);
                g_plant.growpetal2(leafsize);
                g_plant.growpetal3(leafsize);
                g_plant.growpetal4(leafsize);
                //clearplant(g_hdc,PLANT_X,PLANT_Y);
                PaintDesktop(g_hdc);
            }
            */
            break;
        case VK_RIGHT:
            /*
            if(leafsize < 14)
            {
                leafsize += 1;
                g_plant.hight = leafsize;
                g_plant.pollinsize = leafsize;
                g_plant.growleaf1(leafsize);
                g_plant.growleaf2(leafsize);
                g_plant.growpetal1(leafsize);
                g_plant.growpetal2(leafsize);
                g_plant.growpetal3(leafsize);
                g_plant.growpetal4(leafsize);
                //clearplant(g_hdc,PLANT_X,PLANT_Y);
                PaintDesktop(g_hdc);
            }
            */
            break;
        }
    }
    default:
        return DefWindowProc (hwnd, message, wParam, lParam);
    }
    return 0;
}
