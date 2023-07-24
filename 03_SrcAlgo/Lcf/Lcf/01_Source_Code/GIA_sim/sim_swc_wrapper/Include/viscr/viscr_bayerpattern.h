#ifndef _viscr_BayerPattern_h_
#define _viscr_BayerPattern_h_

#ifdef __cplusplus
extern "C" {
#endif

/** @name Bayer Pattern decoding. This was taken from SLA. Only names were
 * changed. */
/*@{*/


#define VISCR_BAYER_RGGB 1   /**< \brief RGRGRGRG
                                       GBGBGBGB */
#define VISCR_BAYER_GBRG 2   /**< \brief GBGBGBGB
                                       RGRGRGRG */
#define VISCR_BAYER_GRBG 3   /**< \brief GRGRGRGR
                                       BGBGBGBG */
#define VISCR_BAYER_BGGR 4   /**< \brief BGBGBGBG
                                       GRGRGRGR */

/************************  GrayToColorXXXX  **********************************/
/** \brief convert grayvaluepointer holding data with overlaying bayerpattern 
           to color
    \param p_gray    : input pointer to whole image
    \param p_col     : outputpointer to whole image (3* size of p_gray)
    \param W,H       : Width and Height of input and output image
    \param sx,sy,w,h : region to be color converted (rest remains untouched)
    \param Bpp       : Byte per pixel (1 uchar, 2: ushort)
******************************************************************************/
void viscr_GrayToColorRGGB(unsigned char *p_gray, unsigned char *p_col, int W, int H, 
					 int sx, int sy, int w, int h, int Bpp);

void viscr_GrayToColorGBRG(unsigned char *p_gray, unsigned char *p_col, int W, int H, 
					 int sx, int sy, int w, int h, int Bpp);

void viscr_GrayToColorGRBG(unsigned char *p_gray, unsigned char *p_col, int W, int H, 
					 int sx, int sy, int w, int h, int Bpp);

void viscr_GrayToColorBGGR(unsigned char *p_gray, unsigned char *p_col, int W, int H, 
					 int sx, int sy, int w, int h, int Bpp);

void viscr_GrayToColorRGLB(unsigned char *p_gray, unsigned char *p_col, int W, int H, 
					 int sx, int sy, int w, int h, int Bpp);

/************************  SlaBayerDecode  ***********************************/
/** \brief convert grayvaluepointer holding data with overlaying bayerpattern 
           to color. The type of the bayerpattern is given as one of the 
           defines above
    \param p_gray    : input pointer to whole image
    \param p_col     : outputpointer to whole image (3* size of p_gray)
    \param W,H       : Width and Height of input and output image
    \param sx,sy,w,h : region to be color converted (rest remains untouched)
    \param Bpp       : Byte per pixel (1 uchar, 2: ushort)
    \param colortype : type of imprinted bayer pattern (SLA_BAYER_RGGB,
                       SLA_BAYER_GBRG, SLA_BAYER_GRBG, SLA_BAYER_BGGR )
    \return success 1 or not 0
******************************************************************************/
int  viscr_BayerDecode(unsigned char *p_gray, unsigned char *p_col, int W, int H, 
					 int sx, int sy, int w, int h, int Bpp, int colortype);
int viscr_BayerDemosaicing(unsigned char *p_gray, unsigned char *p_col, 
        int W, int H, int sx, int sy, int w, int h, int Bpp, int ctype);
                     
/************************  SlaBayerColorGray  ********************************/
/** \brief convert grayvaluepointer holding data with overlaying bayerpattern 
           to color and back to gray, removing most of the bayerpattern noise.
           The type of the bayerpattern is given as one of the 
           defines above
    \param p_gray    : input pointer to whole image
    \param p_col     : outputpointer to whole image (3* size of p_gray)
    \param W,H       : Width and Height of input and output image
    \param sx,sy,w,h : region to be color converted (rest remains untouched)
    \param Bpp       : Byte per pixel (1 uchar, 2: ushort)
    \param colortype : type of imprinted bayer pattern (SLA_BAYER_RGGB,
                       SLA_BAYER_GBRG, SLA_BAYER_GRBG, SLA_BAYER_BGGR )
    \return success 1 or not 0
******************************************************************************/
int viscr_BayerColorGray(unsigned char *p_gray, unsigned char *p_col, int W,int H,
					 int sx, int sy, int w, int h, int Bpp, int ctype);

/************************  SlaBayerColorToGray  ******************************/
/** \brief convert rgb color image to grayvalues by using (R+G+B)/3.
           input and output may be the same pointer. If fitExact the wxh
           output will be written to the first wxhxBpp bytes of p_gray
    \param p_gray    : output pointer to whole image (if !fitExact) or to 
                       region of necessary size
    \param p_col     : inputpointer to whole image (RGB)
    \param W,H       : Width and Height of input image
    \param sx,sy,w,h : region to be converted (rest remains untouched)
    \param Bpp       : Byte per pixel (1 uchar, 2: ushort)
    \param fitExact  : flag: if set the output region will be the first wxhxBpp
                       bytes of p_gray. otherwise the output will go to the 
                       region defined by sx,sy
    \return success 1 or not 0
******************************************************************************/
int viscr_BayerColorToGray(unsigned char *p_gray, unsigned char *p_col, 
                        int W, int H, int sx, int sy, int w, int h, int Bpp,
                        int fitExact);

void viscr_ComputeFastGray(unsigned char *iimg, 
                unsigned char *oimg,int W, int H,int Bpp);

/*@}*/

#ifdef __cplusplus
}
#endif
#endif
