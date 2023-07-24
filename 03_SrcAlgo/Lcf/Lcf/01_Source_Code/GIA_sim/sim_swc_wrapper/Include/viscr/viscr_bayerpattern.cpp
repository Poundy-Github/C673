#ifndef DEFINED_ONLY_IN_BAYER_PATTERN_C
#define DEFINED_ONLY_IN_BAYER_PATTERN_C

#include <string.h>
#include <stdio.h>

#include <viscr_bayerpattern.h>
  
/*four cases: */
/* g r g */ /* x y01 x */
/* b G b */ /* x y11 x */
/* g r g */ /* x y21 x */
#define BAYER_DECODE1GBRG(p_c11,p_y01,p_y11,p_y21)        \
    *p_c11++ =(BAYER_PIXTYPE)( ((int)*p_y01++ + *p_y21++)  >>1); /*R*/    \
    *p_c11++ = *p_y11++ ;/*G*/\
    *p_c11++ =(BAYER_PIXTYPE)( ((int)*(p_y11-2) + *(p_y11))>>1); /*B*/
    
/* r g r */
/* g B g */
/* r g r */
#define BAYER_DECODE1BGGR(p_c11,p_y01,p_y11,p_y21)                            \
    *p_c11++ =(BAYER_PIXTYPE)(((int)*(p_y01-1)+ *(p_y01+1)+ *(p_y21-1)+ *(p_y21+1))>>2);/*R*/ \
    *p_c11++ =(BAYER_PIXTYPE)(((int)*p_y01++  + *(p_y11-1)+ *(p_y11+1)+ *p_y21++  )>>2);/*G*/ \
    *p_c11++ = *p_y11++;                                                 /*B*/ 

/* g b g */
/* r G r */
/* g b g */
#define BAYER_DECODE1GRBG(p_c11,p_y01,p_y11,p_y21)      \
    *p_c11++ =(BAYER_PIXTYPE)(((int)*(p_y11-1)+ *(p_y11+1))>>1);          /*R*/ \
    *p_c11++ = *p_y11++ ;/*G*/\
    *p_c11++ =(BAYER_PIXTYPE)(((int)*p_y01++ + *p_y21++)>>1);              /*B*/ 

/* b g b */
/* g R g */
/* b g b */
#define BAYER_DECODE1RGGB(p_c11,p_y01,p_y11,p_y21)                           \
    *p_c11++ = *p_y11++;                                               /*R*/ \
    *p_c11++ =(BAYER_PIXTYPE)(((int)*p_y01++   + *(p_y11-2)+ *p_y11+ *p_y21++)>>2);/*G*/ \
    *p_c11++ =(BAYER_PIXTYPE)(((int)*(p_y01-2) + *p_y01    + *(p_y21-2)+ *p_y21  )>>2);/*B*/


#define BAYER_DECODEGBRG(p_c11,p_y01,p_y11,p_y21) \
    BAYER_DECODE1GBRG(p_c11,p_y01,p_y11,p_y21)    \
    BAYER_DECODE1BGGR(p_c11,p_y01,p_y11,p_y21) 

#define BAYER_DECODEBGGR(p_c11,p_y01,p_y11,p_y21) \
    BAYER_DECODE1BGGR(p_c11,p_y01,p_y11,p_y21)    \
    BAYER_DECODE1GBRG(p_c11,p_y01,p_y11,p_y21) 
    
#define BAYER_DECODEGRBG(p_c11,p_y01,p_y11,p_y21) \
    BAYER_DECODE1GRBG(p_c11,p_y01,p_y11,p_y21)    \
    BAYER_DECODE1RGGB(p_c11,p_y01,p_y11,p_y21) 
    
#define BAYER_DECODERGGB(p_c11,p_y01,p_y11,p_y21) \
    BAYER_DECODE1RGGB(p_c11,p_y01,p_y11,p_y21)    \
    BAYER_DECODE1GRBG(p_c11,p_y01,p_y11,p_y21) 


#define BAYER_DECODE_FIRSTPIX(p_cy,Bpp)             \
    memcpy(p_cy,p_cy+3,3*Bpp);
    
#define BAYER_DECODE_FIRSTROW(p_cy,W,w,Bpp)         \
    memcpy(p_cy,p_cy+W*3,3*w*Bpp); 

#define BAYER_DECODE_LASTPIX(p_cy,Bpp)              \
    memcpy(p_cy,p_cy-3,3*Bpp);
    
#define BAYER_DECODE_LASTROW(p_cy,W,w,Bpp)          \
    memcpy(p_cy,p_cy-3*W,3*w*Bpp); 

/*specials for Bayer to Color to Gray*/
#define BAYER_DECODE_FIRSTPIX_BCG(p_cy,Bpp)         \
    memcpy(p_cy,p_cy+1,Bpp);
    
#define BAYER_DECODE_FIRSTROW_BCG(p_cy,W,w,Bpp)     \
    memcpy(p_cy,p_cy+W,w*Bpp); 
    
#define BAYER_DECODE_LASTPIX_BCG(p_cy,Bpp)          \
    memcpy(p_cy,p_cy-1,Bpp);
    
#define BAYER_DECODE_LASTROW_BCG(p_cy,W,w,Bpp)      \
    memcpy(p_cy,p_cy-W,w*Bpp); 


/* R G R G*/
/* G B G B*/
/* R G R G*/
/* G B G B*/
/*sx,sy,w,h,W,H have to be even!!, decode starts in second line->TWO1,TWO2*/
void viscr_GrayToColorRGGB(unsigned char *p_gray, unsigned char *p_col, int W, int H, 
					 int sx, int sy, int w, int h, int Bpp)
{
    #define BAYER_DECODETWO1  BAYER_DECODEBGGR
    #define BAYER_DECODETWO2  BAYER_DECODEGRBG
    #define BAYER_DECODEPIXEL BAYER_DECODE1BGGR
    if(Bpp == 1)
    {
        #define BAYER_PIXTYPE unsigned char
        #include "viscr_bayerpattern.cpp"
        #undef  BAYER_PIXTYPE
    }
    else
    {
        #define BAYER_PIXTYPE unsigned short
        #include "viscr_bayerpattern.cpp"
        #undef  BAYER_PIXTYPE
 
    }
    #undef BAYER_DECODETWO1 
    #undef BAYER_DECODETWO2
    #undef BAYER_DECODEPIXEL
}

/* G B G B*/
/* R G R G*/
/* G B G B*/
/* R G R G*/
/*sx,sy,w,h,W,H have to be even!!*/
void viscr_GrayToColorGBRG(unsigned char *p_gray, unsigned char *p_col, int W, int H, 
					 int sx, int sy, int w, int h, int Bpp)
{
    #define BAYER_DECODETWO1  BAYER_DECODEGRBG
    #define BAYER_DECODETWO2  BAYER_DECODEBGGR
    #define BAYER_DECODEPIXEL BAYER_DECODE1GRBG
    if(Bpp == 1)
    {
        #define BAYER_PIXTYPE unsigned char
        #include "viscr_bayerpattern.cpp"
        #undef  BAYER_PIXTYPE
    }
    else
    {
        #define BAYER_PIXTYPE unsigned short
        #include "viscr_bayerpattern.cpp"
        #undef  BAYER_PIXTYPE
 
    }
    #undef BAYER_DECODETWO1 
    #undef BAYER_DECODETWO2
    #undef BAYER_DECODEPIXEL
}

/* G R G R*/
/* B G B G*/
/* G R G R*/
/* B G B G*/
/*sx,sy,w,h,W,H have to be even!!*/
void viscr_GrayToColorGRBG(unsigned char *p_gray, unsigned char *p_col, int W, int H, 
					 int sx, int sy, int w, int h, int Bpp)
{
    #define BAYER_DECODETWO1  BAYER_DECODEGBRG
    #define BAYER_DECODETWO2  BAYER_DECODERGGB
    #define BAYER_DECODEPIXEL BAYER_DECODE1GBRG
    if(Bpp == 1)
    {
        #define BAYER_PIXTYPE unsigned char
        #include "viscr_bayerpattern.cpp"
        #undef  BAYER_PIXTYPE
    }
    else
    {
        #define BAYER_PIXTYPE unsigned short
        #include "viscr_bayerpattern.cpp"
        #undef  BAYER_PIXTYPE
 
    }
    #undef BAYER_DECODETWO1 
    #undef BAYER_DECODETWO2
    #undef BAYER_DECODEPIXEL
}

/* B G B G*/
/* G R G R*/
/* B G B G*/
/* G R G R*/
/*sx,sy,w,h,W,H have to be even!!*/
void viscr_GrayToColorBGGR(unsigned char *p_gray, unsigned char *p_col, int W, int H, 
					 int sx, int sy, int w, int h, int Bpp)
{
    #define BAYER_DECODETWO1  BAYER_DECODERGGB
    #define BAYER_DECODETWO2  BAYER_DECODEGBRG
    #define BAYER_DECODEPIXEL BAYER_DECODE1RGGB
    if(Bpp == 1)
    {
        #define BAYER_PIXTYPE unsigned char
        #include "viscr_bayerpattern.cpp"
        #undef  BAYER_PIXTYPE
    }
    else
    {
        #define BAYER_PIXTYPE unsigned short
        #include "viscr_bayerpattern.cpp"
        #undef  BAYER_PIXTYPE
 
    }
    #undef BAYER_DECODETWO1 
    #undef BAYER_DECODETWO2
    #undef BAYER_DECODEPIXEL
}


/* R G R G*/
/* G B G B*/
/* R G R G*/
/* G B G B*/
/*sx,sy,w,h,W,H have to be even!!, decode starts in second line->TWO1,TWO2*/
void viscr_GrayToColorRGGB_BCG(unsigned char *p_gray, unsigned char *p_col, 
                         int W, int H, int sx, int sy, int w, int h, int Bpp)
{
    #define BAYER_COLOR_GRAY
    #define BAYER_DECODETWO1  BAYER_DECODEBGGR
    #define BAYER_DECODETWO2  BAYER_DECODEGRBG
    #define BAYER_DECODEPIXEL BAYER_DECODE1BGGR
    if(Bpp == 1)
    {
        #define BAYER_PIXTYPE unsigned char
        #include "viscr_bayerpattern.cpp"
        #undef  BAYER_PIXTYPE
    }
    else
    {
        #define BAYER_PIXTYPE unsigned short
        #include "viscr_bayerpattern.cpp"
        #undef  BAYER_PIXTYPE
 
    }
    #undef BAYER_DECODETWO1 
    #undef BAYER_DECODETWO2
    #undef BAYER_DECODEPIXEL
    #undef BAYER_COLOR_GRAY
}

/* G B G B*/
/* R G R G*/
/* G B G B*/
/* R G R G*/
/*sx,sy,w,h,W,H have to be even!!*/
void viscr_GrayToColorGBRG_BCG(unsigned char *p_gray, unsigned char *p_col, 
                         int W, int H, int sx, int sy, int w, int h, int Bpp)
{
    #define BAYER_COLOR_GRAY
    #define BAYER_DECODETWO1  BAYER_DECODEGRBG
    #define BAYER_DECODETWO2  BAYER_DECODEBGGR
    #define BAYER_DECODEPIXEL BAYER_DECODE1GRBG
    if(Bpp == 1)
    {
        #define BAYER_PIXTYPE unsigned char
        #include "viscr_bayerpattern.cpp"
        #undef  BAYER_PIXTYPE
    }
    else
    {
        #define BAYER_PIXTYPE unsigned short
        #include "viscr_bayerpattern.cpp"
        #undef  BAYER_PIXTYPE
 
    }
    #undef BAYER_DECODETWO1 
    #undef BAYER_DECODETWO2
    #undef BAYER_DECODEPIXEL
    #undef BAYER_COLOR_GRAY
}

/* G R G R*/
/* B G B G*/
/* G R G R*/
/* B G B G*/
/*sx,sy,w,h,W,H have to be even!!*/
void viscr_GrayToColorGRBG_BCG(unsigned char *p_gray, unsigned char *p_col, 
                         int W, int H, int sx, int sy, int w, int h, int Bpp)
{
    #define BAYER_COLOR_GRAY
    #define BAYER_DECODETWO1  BAYER_DECODEGBRG
    #define BAYER_DECODETWO2  BAYER_DECODERGGB
    #define BAYER_DECODEPIXEL BAYER_DECODE1GBRG
    if(Bpp == 1)
    {
        #define BAYER_PIXTYPE unsigned char
        #include "viscr_bayerpattern.cpp"
        #undef  BAYER_PIXTYPE
    }
    else
    {
        #define BAYER_PIXTYPE unsigned short
        #include "viscr_bayerpattern.cpp"
        #undef  BAYER_PIXTYPE
 
    }
    #undef BAYER_DECODETWO1 
    #undef BAYER_DECODETWO2
    #undef BAYER_DECODEPIXEL
    #undef BAYER_COLOR_GRAY
}

/* B G B G*/
/* G R G R*/
/* B G B G*/
/* G R G R*/
/*sx,sy,w,h,W,H have to be even!!*/
void viscr_GrayToColorBGGR_BCG(unsigned char *p_gray, unsigned char *p_col, 
                         int W, int H, int sx, int sy, int w, int h, int Bpp)
{
    #define BAYER_COLOR_GRAY
    #define BAYER_DECODETWO1  BAYER_DECODERGGB
    #define BAYER_DECODETWO2  BAYER_DECODEGBRG
    #define BAYER_DECODEPIXEL BAYER_DECODE1RGGB
    if(Bpp == 1)
    {
        #define BAYER_PIXTYPE unsigned char
        #include "viscr_bayerpattern.cpp"
        #undef  BAYER_PIXTYPE
    }
    else
    {
        #define BAYER_PIXTYPE unsigned short
        #include "viscr_bayerpattern.cpp"
        #undef  BAYER_PIXTYPE
 
    }
    #undef BAYER_DECODETWO1 
    #undef BAYER_DECODETWO2
    #undef BAYER_DECODEPIXEL
    #undef BAYER_COLOR_GRAY
}

static int BayerCheckParam(unsigned char *p_gray, unsigned char *p_col, 
                           int W, int H, int *sx, int *sy, int *w, int *h, 
                           int Bpp, int ctype)
{
    if(!p_gray                || !p_col                ) return 0;
    if(Bpp   < 1              || Bpp   > 2             ) return 0; 
    if(ctype < VISCR_BAYER_RGGB || ctype > VISCR_BAYER_BGGR) return 0;
    if(W     < 2              || H     < 2             ) return 0;
    if(*sx<0) {*w += *sx; *sx = 0;}
    if(*sy<0) {*h += *sy; *sy = 0;}
    if(*sx%2) {*sx -=1; *w += 1;}
    if(*sy%2) {*sy -=1; *h += 1;}
    if(*sx + *w > W) {*w = W - *sx; if(*w%2) *w -= 1;}
    if(*sy + *h > H) {*h = H - *sy; if(*h%2) *h -= 1;}
    if(*w%2) *w -= 1;
    if(*h%2) *h -= 1;
    if(*w    < 2              || *h    < 2             ) return 0;
    return 1;
}

int viscr_BayerDecode(unsigned char *p_gray, unsigned char *p_col, int W, int H, 
					 int sx, int sy, int w, int h, int Bpp, int ctype)
{
    if(!BayerCheckParam(p_gray, p_col,W, H,&sx,&sy,&w, &h,Bpp,ctype)) return 0;
    if(ctype==VISCR_BAYER_RGGB) viscr_GrayToColorRGGB(p_gray,p_col,W,H,sx,sy,w,h,Bpp); 
    if(ctype==VISCR_BAYER_GBRG) viscr_GrayToColorGBRG(p_gray,p_col,W,H,sx,sy,w,h,Bpp); 
    if(ctype==VISCR_BAYER_GRBG) viscr_GrayToColorGRBG(p_gray,p_col,W,H,sx,sy,w,h,Bpp); 
    if(ctype==VISCR_BAYER_BGGR) viscr_GrayToColorBGGR(p_gray,p_col,W,H,sx,sy,w,h,Bpp);
    return 1;
}

int viscr_BayerColorGray(unsigned char *p_gray, unsigned char *p_col,int W,int H, 
					 int sx, int sy, int w, int h, int Bpp, int ctype)
{
   if(!BayerCheckParam(p_gray, p_col,W, H,&sx,&sy,&w, &h,Bpp,ctype)) return 0;
   if(ctype==VISCR_BAYER_RGGB) viscr_GrayToColorRGGB_BCG(p_gray,p_col,W,H,sx,sy,w,h,Bpp);
   if(ctype==VISCR_BAYER_GBRG) viscr_GrayToColorGBRG_BCG(p_gray,p_col,W,H,sx,sy,w,h,Bpp);
   if(ctype==VISCR_BAYER_GRBG) viscr_GrayToColorGRBG_BCG(p_gray,p_col,W,H,sx,sy,w,h,Bpp);
   if(ctype==VISCR_BAYER_BGGR) viscr_GrayToColorBGGR_BCG(p_gray,p_col,W,H,sx,sy,w,h,Bpp);
    return 1;
}

static const unsigned char col2GrayTab[3*255+1] = {  
  0,   0,   1,   1,   1,   2,   2,   2,   3,   3,   3,   4,   4,   4,   5,   5,
  5,   6,   6,   6,   7,   7,   7,   8,   8,   8,   9,   9,   9,  10,  10,  10,
 11,  11,  11,  12,  12,  12,  13,  13,  13,  14,  14,  14,  15,  15,  15,  16,
 16,  16,  17,  17,  17,  18,  18,  18,  19,  19,  19,  20,  20,  20,  21,  21,
 21,  22,  22,  22,  23,  23,  23,  24,  24,  24,  25,  25,  25,  26,  26,  26,
 27,  27,  27,  28,  28,  28,  29,  29,  29,  30,  30,  30,  31,  31,  31,  32,
 32,  32,  33,  33,  33,  34,  34,  34,  35,  35,  35,  36,  36,  36,  37,  37,
 37,  38,  38,  38,  39,  39,  39,  40,  40,  40,  41,  41,  41,  42,  42,  42,
 43,  43,  43,  44,  44,  44,  45,  45,  45,  46,  46,  46,  47,  47,  47,  48,
 48,  48,  49,  49,  49,  50,  50,  50,  51,  51,  51,  52,  52,  52,  53,  53,
 53,  54,  54,  54,  55,  55,  55,  56,  56,  56,  57,  57,  57,  58,  58,  58,
 59,  59,  59,  60,  60,  60,  61,  61,  61,  62,  62,  62,  63,  63,  63,  64,
 64,  64,  65,  65,  65,  66,  66,  66,  67,  67,  67,  68,  68,  68,  69,  69,
 69,  70,  70,  70,  71,  71,  71,  72,  72,  72,  73,  73,  73,  74,  74,  74,
 75,  75,  75,  76,  76,  76,  77,  77,  77,  78,  78,  78,  79,  79,  79,  80,
 80,  80,  81,  81,  81,  82,  82,  82,  83,  83,  83,  84,  84,  84,  85,  85,
 85,  86,  86,  86,  87,  87,  87,  88,  88,  88,  89,  89,  89,  90,  90,  90,
 91,  91,  91,  92,  92,  92,  93,  93,  93,  94,  94,  94,  95,  95,  95,  96,
 96,  96,  97,  97,  97,  98,  98,  98,  99,  99,  99, 100, 100, 100, 101, 101,
101, 102, 102, 102, 103, 103, 103, 104, 104, 104, 105, 105, 105, 106, 106, 106,
107, 107, 107, 108, 108, 108, 109, 109, 109, 110, 110, 110, 111, 111, 111, 112,
112, 112, 113, 113, 113, 114, 114, 114, 115, 115, 115, 116, 116, 116, 117, 117,
117, 118, 118, 118, 119, 119, 119, 120, 120, 120, 121, 121, 121, 122, 122, 122,
123, 123, 123, 124, 124, 124, 125, 125, 125, 126, 126, 126, 127, 127, 127, 128,
128, 128, 129, 129, 129, 130, 130, 130, 131, 131, 131, 132, 132, 132, 133, 133,
133, 134, 134, 134, 135, 135, 135, 136, 136, 136, 137, 137, 137, 138, 138, 138,
139, 139, 139, 140, 140, 140, 141, 141, 141, 142, 142, 142, 143, 143, 143, 144,
144, 144, 145, 145, 145, 146, 146, 146, 147, 147, 147, 148, 148, 148, 149, 149,
149, 150, 150, 150, 151, 151, 151, 152, 152, 152, 153, 153, 153, 154, 154, 154,
155, 155, 155, 156, 156, 156, 157, 157, 157, 158, 158, 158, 159, 159, 159, 160,
160, 160, 161, 161, 161, 162, 162, 162, 163, 163, 163, 164, 164, 164, 165, 165,
165, 166, 166, 166, 167, 167, 167, 168, 168, 168, 169, 169, 169, 170, 170, 170,
171, 171, 171, 172, 172, 172, 173, 173, 173, 174, 174, 174, 175, 175, 175, 176,
176, 176, 177, 177, 177, 178, 178, 178, 179, 179, 179, 180, 180, 180, 181, 181,
181, 182, 182, 182, 183, 183, 183, 184, 184, 184, 185, 185, 185, 186, 186, 186,
187, 187, 187, 188, 188, 188, 189, 189, 189, 190, 190, 190, 191, 191, 191, 192,
192, 192, 193, 193, 193, 194, 194, 194, 195, 195, 195, 196, 196, 196, 197, 197,
197, 198, 198, 198, 199, 199, 199, 200, 200, 200, 201, 201, 201, 202, 202, 202,
203, 203, 203, 204, 204, 204, 205, 205, 205, 206, 206, 206, 207, 207, 207, 208,
208, 208, 209, 209, 209, 210, 210, 210, 211, 211, 211, 212, 212, 212, 213, 213,
213, 214, 214, 214, 215, 215, 215, 216, 216, 216, 217, 217, 217, 218, 218, 218,
219, 219, 219, 220, 220, 220, 221, 221, 221, 222, 222, 222, 223, 223, 223, 224,
224, 224, 225, 225, 225, 226, 226, 226, 227, 227, 227, 228, 228, 228, 229, 229,
229, 230, 230, 230, 231, 231, 231, 232, 232, 232, 233, 233, 233, 234, 234, 234,
235, 235, 235, 236, 236, 236, 237, 237, 237, 238, 238, 238, 239, 239, 239, 240,
240, 240, 241, 241, 241, 242, 242, 242, 243, 243, 243, 244, 244, 244, 245, 245,
245, 246, 246, 246, 247, 247, 247, 248, 248, 248, 249, 249, 249, 250, 250, 250,
251, 251, 251, 252, 252, 252, 253, 253, 253, 254, 254, 254, 255, 255 };

int viscr_BayerColorToGray(unsigned char *p_gray, unsigned char *p_col, 
                        int W, int H, int sx, int sy, int w, int h, int Bpp,
                        int fitExact)
{
    int x,y;
    if(!BayerCheckParam(p_gray, p_col,W, H,&sx,&sy,&w, &h,Bpp,VISCR_BAYER_RGGB)) 
        return 0;
    if(!fitExact)
    {
        if(Bpp==1)
        {
            unsigned char *p_c = ((unsigned char *)p_col ) + (sy * W +sx) * 3;
            unsigned char *p_d = ((unsigned char *)p_gray) + (sy * W +sx);
            for(y = h; y; y--, p_d += W-w, p_c += (W-w)*3)
                for(x = w; x; x--,p_c+=3)
                    *p_d++ = col2GrayTab[(int)(*p_c) + *(p_c+1) +*(p_c+2)];
        }
        else if(Bpp==2)
        {
            unsigned short *p_c = ((unsigned short *)p_col ) + (sy * W +sx)*3;
            unsigned short *p_d = ((unsigned short *)p_gray) + (sy * W +sx);
            for(y = h; y; y--, p_d += W-w, p_c += (W-w)*3)
                for(x = w; x; x--,p_c+=3)
                    *p_d++ =(unsigned short)( ((int)(*p_c) + *(p_c+1) +*(p_c+2))/3);
        }
        else return 0;
    }
    else /*the returnpointer is p_col and is filled with values from the input*/
    {
        if(Bpp==1)
        {
            unsigned char *p_c = ((unsigned char *)p_col ) + (sy * W +sx) * 3;
            unsigned char *p_d = ((unsigned char *)p_gray);
            for(y = h; y; y--, p_c += (W-w)*3)
                for(x = w; x; x--,p_c+=3)
                    *p_d++ = col2GrayTab[(int)(*p_c) + *(p_c+1) +*(p_c+2)];
        }
        else if(Bpp==2)
        {
            unsigned short *p_c = ((unsigned short *)p_col ) + (sy * W +sx)*3;
            unsigned short *p_d = ((unsigned short *)p_gray);
            for(y = h; y; y--, p_c += (W-w)*3)
                for(x = w; x; x--,p_c+=3)
                    *p_d++ =(unsigned short)( ((int)(*p_c) + *(p_c+1) +*(p_c+2))/3);
        }
        else return 0;

    }
    return 1;
}

#define COMPUTE_BAYER_REDCENTER_VALS              \
    int B1 =  p_idata[-1*W-1] + p_idata[-1*W+1] + \
              p_idata[+1*W-1] + p_idata[+1*W+1] ; \
    int R0 =  p_idata[+0*W+0];                    \
    int R1 =  p_idata[-2*W-0] + p_idata[+2*W+0] + \
              p_idata[-0*W-2] + p_idata[+0*W+2] ; \
    int G1 =  p_idata[-0*W-1] + p_idata[+0*W+1] ; \
    int G2 =  p_idata[-1*W-0] + p_idata[+1*W+0] ; \
    int RR = ( 8*R0 + 2*R1              )/16;     \
    int GG = ( 8*R0 - 2*R1 + 4*G1 + 4*G2)/16;     \
    int BB = (12*R0 - 3*R1 + 4*B1       )/16; 

#define COMPUTE_BAYER_GREENCENTERR_VALS                               \
    int G3 =  p_idata[-1*W-1] + p_idata[-1*W+1] +                     \
              p_idata[+1*W-1] + p_idata[+1*W+1] ; /*LumenAdd*/        \
    int G0 =  p_idata[+0*W+0];                    /*Centerpix*/       \
    int G1 =  p_idata[-2*W-0] + p_idata[+2*W+0] ; /*VertGreen*/       \
    int G2 =  p_idata[-0*W-2] + p_idata[+0*W+2] ; /*HorizGreen*/      \
    int R1 =  p_idata[-0*W-1] + p_idata[+0*W+1] ; /*Horizontal Red*/  \
    int B1 =  p_idata[-1*W-0] + p_idata[+1*W+0] ; /*Vertical Blue*/   \
    int RR = (10*G0 - 2*G3 + 1*G1 - 2*G2 + 8*R1)/16;                  \
    int GG = ( 8*G0 + 1*G3 + 1*G1 + 1*G2       )/16;                  \
    int BB = (10*G0 - 2*G3 - 2*G1 + 1*G2 + 8*B1)/16;

#define COMPUTE_BAYER_BLUECENTER_VALS                                 \
    int R1 =  p_idata[-1*W-1] + p_idata[-1*W+1] +                     \
              p_idata[+1*W-1] + p_idata[+1*W+1] ; /*RedAdd*/          \
    int B0 =  p_idata[+0*W+0];                    /*Centerpix*/       \
    int B1 =  p_idata[-2*W-0] + p_idata[+2*W+0] +                     \
              p_idata[-0*W-2] + p_idata[+0*W+2] ; /*Red*/             \
    int G2 =  p_idata[-0*W-1] + p_idata[+0*W+1] ; /*Horizontal Red*/  \
    int G1 =  p_idata[-1*W-0] + p_idata[+1*W+0] ; /*Vertical Blue*/   \
    int RR = (12*B0 - 3*B1 + 4*R1       )/16;                         \
    int GG = ( 8*B0 - 2*B1 + 4*G1 + 4*G2)/16;                         \
    int BB = ( 8*B0 + 2*B1              )/16;


#define COMPUTE_BAYER_GREENCENTERB_VALS                               \
    int G4 =  p_idata[-1*W-1] + p_idata[-1*W+1] +                     \
              p_idata[+1*W-1] + p_idata[+1*W+1] ; /*GreenAdd*/        \
    int G0 =  p_idata[+0*W+0];                    /*Centerpix*/       \
    int G1 =  p_idata[-2*W-0] + p_idata[+2*W+0] ; /*VertLumen*/       \
    int G2 =  p_idata[-0*W-2] + p_idata[+0*W+2] ; /*HorizLumen*/      \
    int B1 =  p_idata[-0*W-1] + p_idata[+0*W+1] ; /*Horizontal Red*/  \
    int R1 =  p_idata[-1*W-0] + p_idata[+1*W+0] ; /*Vertical Blue*/   \
    int RR = (10*G0 - 2*G4 - 2*G1 + 1*G2 + 8*R1)/16;                  \
    int GG = ( 8*G0 + 1*G4 + 1*G1 + 1*G2       )/16;                  \
    int BB = (10*G0 - 2*G4 + 1*G1 - 2*G2 + 8*B1)/16;

#define CUT_RESPECTIVE_VALUES_USHORT                                  \
    *R =(unsigned short)((RR>0)?((RR<4095)?RR:4095):0);               \
    *G =(unsigned short)((GG>0)?((GG<4095)?GG:4095):0);               \
    *B =(unsigned short)((BB>0)?((BB<4095)?BB:4095):0); 

#define CUT_RESPECTIVE_VALUES_UCHAR                                   \
    *R =(unsigned char)((RR>0)?((RR<255)?RR:255):0);                  \
    *G =(unsigned char)((GG>0)?((GG<255)?GG:255):0);                  \
    *B =(unsigned char)((BB>0)?((BB<255)?BB:255):0); 
   
static void getContributingValuesRedCenterShort(unsigned short *p_idata, int W, 
                unsigned short *R, unsigned short *G, unsigned short *B)
{
    COMPUTE_BAYER_REDCENTER_VALS;
    CUT_RESPECTIVE_VALUES_USHORT;
}

static void getContributingValuesGreenCenterRShort(unsigned short *p_idata, 
        int W, unsigned short *R, unsigned short *G, unsigned short *B)
{
    COMPUTE_BAYER_GREENCENTERR_VALS;
    CUT_RESPECTIVE_VALUES_USHORT;
}

static void getContributingValuesBlueCenterShort(unsigned short *p_idata, 
        int W, unsigned short *R, unsigned short *G, unsigned short *B)
{
    COMPUTE_BAYER_BLUECENTER_VALS;
    CUT_RESPECTIVE_VALUES_USHORT;
}

static void getContributingValuesGreenCenterBShort(unsigned short *p_idata, 
        int W, unsigned short *R, unsigned short *G, unsigned short *B)
{
    COMPUTE_BAYER_GREENCENTERB_VALS;
    CUT_RESPECTIVE_VALUES_USHORT;
}

static void getContributingValuesRedCenterUChar(unsigned char *p_idata, 
        int W, unsigned char *R, unsigned char *G, unsigned char *B)
{
    COMPUTE_BAYER_REDCENTER_VALS;
    CUT_RESPECTIVE_VALUES_UCHAR;
}

static void getContributingValuesGreenCenterRUChar(unsigned char *p_idata, 
        int W, unsigned char *R, unsigned char *G, unsigned char *B)
{
    COMPUTE_BAYER_GREENCENTERR_VALS;
    CUT_RESPECTIVE_VALUES_UCHAR;
}

static void getContributingValuesBlueCenterUChar(unsigned char *p_idata, 
        int W, unsigned char *R, unsigned char *G, unsigned char *B)
{
    COMPUTE_BAYER_BLUECENTER_VALS;
    CUT_RESPECTIVE_VALUES_UCHAR;
}

static void getContributingValuesGreenCenterBUChar(unsigned char *p_idata, 
        int W, unsigned char *R, unsigned char *G, unsigned char *B)
{
    COMPUTE_BAYER_GREENCENTERB_VALS;
    CUT_RESPECTIVE_VALUES_UCHAR;
}

static void GrayToColorDemosaicingGRBGUShort(unsigned short *p_gray, 
         unsigned short *p_col, int W, int sx, int sy, int w, int h)
{
    int             x,y;
    unsigned short *p_cy, *p_c0;
	unsigned short *p_y , *p_l0;
	int             H2 = h/2-2;
    int             W2 = w/2-2;

	p_c0 = p_col  +3*((sy+1+2)*W + sx+2);/*+1,leave   */
	p_l0 = p_gray +   (sy+1+2)*W + sx+2 ;/*first alone*/
    for(y = 0; y < H2; y++)
    {
        /*first the rgr-line on top*/
        p_cy  = p_c0  +  6*y    * W;
        p_y   = p_l0  + (2*y  ) * W;
        for(x = 0; x < W2; x++)
        {
            getContributingValuesBlueCenterShort(p_y, W, p_cy, p_cy+1, p_cy+2);
            p_y++; p_cy += 3;
            getContributingValuesGreenCenterBShort(p_y, W, p_cy,p_cy+1,p_cy+2);
            p_y++; p_cy += 3;
        }
        /*now the lbl-line on top*/
        p_cy  = p_c0  + (6*y+3) * W;
        p_y   = p_l0  + (2*y+1) * W;
        if(y < H2-1) for(x = 0; x < W2; x++)
        {
            getContributingValuesGreenCenterRShort(p_y, W, p_cy,p_cy+1,p_cy+2);
            p_y++; p_cy += 3;
            getContributingValuesRedCenterShort(p_y, W, p_cy, p_cy+1, p_cy+2);
            p_y++; p_cy += 3;
        }
    }
}

static void GrayToColorDemosaicingGRBGUChar(unsigned char *p_gray, 
         unsigned char *p_col, int W, int sx, int sy, int w, int h)
{
    int            x,y;
    unsigned char *p_cy, *p_c0;
	unsigned char *p_y , *p_l0;
	int            H2 = h/2-2;
    int            W2 = w/2-2;

	p_c0 = p_col  +3*((sy+1+2)*W + sx+2);/*+1,leave   */
	p_l0 = p_gray +   (sy+1+2)*W + sx+2 ;/*first alone*/
    for(y = 0; y < H2; y++)
    {
        /*first the rgr-line on top*/
        p_cy  = p_c0  +  6*y    * W;
        p_y   = p_l0  + (2*y  ) * W;
        for(x = 0; x < W2; x++)
        {
            getContributingValuesBlueCenterUChar(p_y, W, p_cy, p_cy+1, p_cy+2);
            p_y++; p_cy += 3;
            getContributingValuesGreenCenterBUChar(p_y, W, p_cy,p_cy+1,p_cy+2);
            p_y++; p_cy += 3;
        }
        /*now the lbl-line on top*/
        p_cy  = p_c0  + (6*y+3) * W;
        p_y   = p_l0  + (2*y+1) * W;
        if(y < H2-1) for(x = 0; x < W2; x++)
        {
            getContributingValuesGreenCenterRUChar(p_y, W, p_cy,p_cy+1,p_cy+2);
            p_y++; p_cy += 3;
            getContributingValuesRedCenterUChar(p_y, W, p_cy, p_cy+1, p_cy+2);
            p_y++; p_cy += 3;
        }
    }
}

static void GrayToColorDemosaicingBGGRUChar(unsigned char *p_gray, 
         unsigned char *p_col, int W, int sx, int sy, int w, int h)
{
    int            x,y;
    unsigned char *p_cy, *p_c0;
	unsigned char *p_y , *p_l0;
	int            H2 = h/2-2;
    int            W2 = w/2-2;
	p_c0 = p_col  +3*((sy+1+2)*W + sx+2);/*+1,leave   */
	p_l0 = p_gray +   (sy+1+2)*W + sx+2 ;/*first alone*/
    for(y = 0; y < H2; y++)
    {
        /*first the grg-line on top*/
        p_cy  = p_c0  +  6*y    * W;
        p_y   = p_l0  + (2*y  ) * W;
        for(x = 0; x < W2; x++)
        {
            getContributingValuesGreenCenterRUChar(p_y, W, p_cy,p_cy+1,p_cy+2);
            p_y++; p_cy += 3;
            getContributingValuesRedCenterUChar(p_y, W, p_cy, p_cy+1, p_cy+2);
            p_y++; p_cy += 3;
        }
        /*now the bgb-line on top*/
        p_cy  = p_c0  + (6*y+3) * W;
        p_y   = p_l0  + (2*y+1) * W;
        if(y < H2-1) for(x = 0; x < W2; x++)
        {
            getContributingValuesBlueCenterUChar(p_y, W, p_cy, p_cy+1, p_cy+2);
            p_y++; p_cy += 3;
            getContributingValuesGreenCenterBUChar(p_y, W, p_cy,p_cy+1,p_cy+2);
            p_y++; p_cy += 3;
        }
    }
}

static void GrayToColorDemosaicingBGGRShort(unsigned short *p_gray, 
         unsigned short *p_col, int W, int sx, int sy, int w, int h)
{
    int             x, y;
    unsigned short *p_cy, *p_c0;
	unsigned short *p_y , *p_l0;
	int             H2 = h/2-2;
    int             W2 = w/2-2;
	p_c0 = p_col  +3*((sy+1+2)*W + sx+2);/*+1,leave   */
	p_l0 = p_gray +   (sy+1+2)*W + sx+2 ;/*first alone*/
    for(y = 0; y < H2; y++)
    {
        /*first the grg-line on top*/
        p_cy  = p_c0  +  6*y    * W;
        p_y   = p_l0  + (2*y  ) * W;
        for(x = 0; x < W2; x++)
        {
            getContributingValuesGreenCenterRShort(p_y, W, p_cy,p_cy+1,p_cy+2);
            p_y++; p_cy += 3;
            getContributingValuesRedCenterShort(p_y, W, p_cy, p_cy+1, p_cy+2);
            p_y++; p_cy += 3;
        }
        /*now the bgb-line on top*/
        p_cy  = p_c0  + (6*y+3) * W;
        p_y   = p_l0  + (2*y+1) * W;
        if(y < H2-1) for(x = 0; x < W2; x++)
        {
            getContributingValuesBlueCenterShort(p_y, W, p_cy, p_cy+1, p_cy+2);
            p_y++; p_cy += 3;
            getContributingValuesGreenCenterBShort(p_y, W, p_cy,p_cy+1,p_cy+2);
            p_y++; p_cy += 3;
        }
    }
}
int viscr_BayerDemosaicing(unsigned char *p_gray, unsigned char *p_col, 
        int W, int H, int sx, int sy, int w, int h, int Bpp, int ctype)
{
    if(!BayerCheckParam(p_gray, p_col,W, H,&sx,&sy,&w, &h,Bpp,ctype)) return 0;
    if(ctype==VISCR_BAYER_RGGB) return 0;
    if(ctype==VISCR_BAYER_GBRG) return 0; 
    if(ctype==VISCR_BAYER_GRBG)
    { 
      if(Bpp==1)GrayToColorDemosaicingGRBGUChar(p_gray,p_col,W,sx,sy,w,h);
      else      GrayToColorDemosaicingGRBGUShort((unsigned short*)p_gray,
                             (unsigned short*)p_col,W,sx,sy,w,h);
    }
    if(ctype==VISCR_BAYER_BGGR) 
    {
        if(Bpp==1)GrayToColorDemosaicingBGGRUChar(p_gray,p_col,W,sx,sy,w,h);
        else      GrayToColorDemosaicingBGGRShort((unsigned short*)p_gray,
                                          (unsigned short*)p_col,W,sx,sy,w,h);
    }
    return 1;
}

static void SlaComputeFastGrayShort(unsigned short *iimg, unsigned short *oimg,
                                                             int W, int H)
{
    int x, y;
    unsigned short *inext = iimg+W;
    for(y = 0; y < H-1; y++, oimg++,iimg++,inext++)
    {
        for(x = 0; x < W-1; x++,iimg++,inext++)
        {
            *oimg++ = (iimg[0] + iimg[1] + inext[0] + inext[1])>>2;
        }
        *oimg = *(oimg-1); /*last in row*/
    }
    memcpy(oimg,oimg-W,2*W);    /*last row*/
}

static void SlaComputeFastGrayUchar(unsigned char *iimg, 
                                          unsigned char *oimg,int W, int H)
{
    int x, y;
    unsigned char *inext = iimg+W;
    for(y = 0; y < H-1; y++, oimg++,iimg++,inext++)
    {
        for(x = 0; x < W-1; x++,iimg++,inext++)
        {
          *oimg++ = 
            (unsigned char)(((int)iimg[0] + iimg[1] + inext[0] + inext[1])>>2);
        }
        *oimg = *(oimg-1); /*last in row*/
    }
    memcpy(oimg,oimg-W,W);    /*last row*/
}

void viscr_ComputeFastGray(unsigned char *iimg, 
                unsigned char *oimg,int W, int H,int Bpp)
{
    if(Bpp == 1) SlaComputeFastGrayUchar(iimg, oimg,W, H);
    else if(Bpp == 2) SlaComputeFastGrayShort((unsigned short *)iimg, 
        (unsigned short *)oimg,  W,  H);
    else fprintf(stderr, "SlaComputeFastGray not implemented for Bpp %d\n",Bpp);
}

#undef DEFINED_ONLY_IN_BAYER_PATTERN_C

#else /*DEFINED_ONLY_IN_BAYER_PATTERN_C :to be included if in local c-file*/
  #ifndef BAYER_COLOR_GRAY /*not defined -> simple color decoding*/
	BAYER_PIXTYPE *p_cy, *p_y01, *p_y11, *p_y21, *p_c0, *p_l0;
    int x,y;
	int H2 = h/2-1;
    int W2 = w/2-1;
    H=0; /*to remove warning*/

	p_c0 = (BAYER_PIXTYPE *)(p_col)  + 3 * ((sy+1) * W + sx+1);
	p_l0 = (BAYER_PIXTYPE *)(p_gray) +      (sy+1) * W + sx+1 ;
    for(y = 0; y < H2; y++)
	{
        p_cy  = p_c0  + 6*y * W;
	    p_y01 = p_l0  + (2*y-1) * W;
		p_y11 = p_y01 + W;
		p_y21 = p_y11 + W;
		for(x=0; x<W2; x++){BAYER_DECODETWO1(p_cy,p_y01,p_y11,p_y21);}/*even*/
        BAYER_DECODE_LASTPIX(p_cy,Bpp);          /*last pixel          */
        p_cy  = p_c0  + (2*y + 1) * 3*W;
	    p_y01 = p_l0  + (2*y)     *   W;
		p_y11 = p_y01 +  W;
		p_y21 = p_y11 +  W;
		for(x = 0;x<W2;x++){BAYER_DECODETWO2(p_cy,p_y01,p_y11,p_y21);}/*odd*/
        BAYER_DECODE_LASTPIX(p_cy,Bpp);          /*last pixel          */
	}
	/*last lines need special attention, since there might be no further*/
    p_cy = (BAYER_PIXTYPE *)(p_col)  + 3 * ((sy) * W + sx) + 3*(h-1)*W;
    BAYER_DECODE_LASTROW(p_cy,W,w,Bpp);
    /*firstrow, firstpixels*/
    p_c0 = (BAYER_PIXTYPE *)(p_col)  + 3 * ((sy) * W + sx);
    BAYER_DECODE_FIRSTROW(p_c0,W,w,Bpp);
    for(y = 0; y < h; y++,p_c0+=3*W) BAYER_DECODE_FIRSTPIX(p_c0, Bpp);

#else /*BAYER_COLOR_GRAY defined -> convert color and back to gray*/
    
    BAYER_PIXTYPE  cy[6], *p_cy;
	BAYER_PIXTYPE *p_cyo, *p_y01, *p_y11, *p_y21, *p_c0, *p_l0;
    int x,y;
	int H2 = h/2-1;
    int W2 = w/2-1;
    H=0; /*to remove warning*/

	p_c0 = (BAYER_PIXTYPE *)(p_col)  + (sy+1) * W + sx+1;
	p_l0 = (BAYER_PIXTYPE *)(p_gray) + (sy+1) * W + sx+1;
    for(y = 0; y < H2; y++)
	{
        p_cyo = p_c0  + 2*y * W;
	    p_y01 = p_l0  + (2*y-1) * W;
		p_y11 = p_y01 + W;
		p_y21 = p_y11 + W;
		for(x=0; x<W2; x++)
        {
            p_cy = &cy[0];
            BAYER_DECODETWO1(p_cy,p_y01,p_y11,p_y21);
            *p_cyo++ = (BAYER_PIXTYPE)(((int)cy[0] + cy[1] + cy[2])/3);
            *p_cyo++ = (BAYER_PIXTYPE)(((int)cy[3] + cy[4] + cy[5])/3);
        }/*even*/
        BAYER_DECODE_LASTPIX_BCG(p_cyo,Bpp);          /*last pixel          */
        p_cyo = p_c0  + (2*y + 1) * W;
	    p_y01 = p_l0  + (2*y)     * W;
		p_y11 = p_y01 +  W;
		p_y21 = p_y11 +  W;
		for(x = 0;x<W2;x++)
        {
            p_cy = &cy[0];
            BAYER_DECODETWO2(p_cy,p_y01,p_y11,p_y21);
            *p_cyo++ = (BAYER_PIXTYPE)(((int)cy[0] + cy[1] + cy[2])/3);
            *p_cyo++ = (BAYER_PIXTYPE)(((int)cy[3] + cy[4] + cy[5])/3);
        }/*odd*/
        BAYER_DECODE_LASTPIX_BCG(p_cyo,Bpp);          /*last pixel          */
	}
	/*last lines need special attention, since there might be no further*/
    p_cy = (BAYER_PIXTYPE *)(p_col)  +  ((sy) * W + sx) + (h-1)*W;
    BAYER_DECODE_LASTROW_BCG(p_cy,W,w,Bpp);
    /*firstrow, firstpixels*/
    p_c0 = (BAYER_PIXTYPE *)(p_col)  + ((sy) * W + sx);
    BAYER_DECODE_FIRSTROW_BCG(p_c0,W,w,Bpp);
    for(y = 0; y < h; y++,p_c0+=W) BAYER_DECODE_FIRSTPIX_BCG(p_c0, Bpp);
  #endif /*BAYER_COLOR_GRAY*/
#endif /*DEFINED_ONLY_IN_BAYER_PATTERN_C*/

