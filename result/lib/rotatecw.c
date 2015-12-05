#include <wand/magick_wand.h>
#include <stdlib.h>

void rotatecw(char* input,char* output)
{
        printf("clockwise 90\n");
        MagickWand *m_wand = NULL;
	PixelWand * backpixel;

        MagickWandGenesis();
	backpixel = NewPixelWand();
	PixelSetColor(backpixel,"#000000");
        m_wand = NewMagickWand();
        //open
        MagickReadImage(m_wand,input);
        //rotate
	MagickRotateImage(m_wand,backpixel,90);
        //save
        MagickWriteImage(m_wand,output);

        /* Clean up */
        if(m_wand)m_wand = DestroyMagickWand(m_wand);

        MagickWandTerminus();
}
