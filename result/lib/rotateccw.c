#include <wand/magick_wand.h>
#include <stdlib.h>

void rotateccw(char* input,char* output)
{
        printf("counterclockwise 90\n");
        MagickWand *m_wand = NULL;
	PixelWand * backpixel;

        MagickWandGenesis();
	backpixel = NewPixelWand();
	PixelSetColor(backpixel,"#000000");
        m_wand = NewMagickWand();
        //open
        MagickReadImage(m_wand,input);
        //rotate
	MagickRotateImage(m_wand,backpixel,270);
        //save
        MagickWriteImage(m_wand,output);

        /* Clean up */
        if(m_wand)m_wand = DestroyMagickWand(m_wand);

        MagickWandTerminus();
}
