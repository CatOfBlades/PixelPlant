#ifndef COLORCODE_HPP_INCLUDED
#define COLORCODE_HPP_INCLUDED

#include <windows.h>


// 1 2 4 8   ; 192 128 64 32 R
// 16 32 64 128 ; G
//  256 512 1024 2048 ;B


#define RLOW  8
#define RMED  4
#define RMOD  2
#define RHIGH 1

#define GLOW  128
#define GMED  64
#define GMOD  32
#define GHIGH 16

#define BLOW  2048
#define BMED  1024
#define BMOD  512
#define BHIGH 256

#define BLACK 0
#define BLUE 1280
#define RED 5
#define GREEN 80

#define TURQUISE 1360
#define MAGENTA 1285
#define YELLOW 85
#define WHITE 1365

COLORREF ConvertToRGB(unsigned int Inpt)
{

	int R =0;
	int G =0;
	int B =0;
	if((Inpt&RLOW) > 0){R  += 32;};
	if((Inpt&RMED) > 0){R  += 64;};
	if((Inpt&RMOD) > 0){R  += 128;};
	if(Inpt > 0){R  += 192;};

	if((Inpt&GLOW) > 0){G  += 32;};
	if((Inpt&GMED) > 0){G  += 64;};
	if((Inpt&GMOD) > 0){G  += 128;};
	if((Inpt&GHIGH) > 0){G  += 192;};

	if((Inpt&BLOW) > 0){B  += 32;};
	if((Inpt&BMED) > 0){B  += 64;};
	if((Inpt&BMOD) > 0){B  += 128;};
	if((Inpt&BHIGH) > 0){B  += 192;};
	_sleep(1);
	return RGB(R,G,B);
};

#endif // COLORCODE_HPP_INCLUDED
