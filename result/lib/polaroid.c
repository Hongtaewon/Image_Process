#include <wand/magick_wand.h>
#include <stdlib.h>

void polaroid(char* input,char* output)
{
        printf("polaroid\n");
        MagickWand *m_wand = NULL;
	DrawingWand *dw = NULL;

        MagickWandGenesis();

        m_wand = NewMagickWand();
	dw = NewDrawingWand();

        //open
        MagickReadImage(m_wand,input);
        //polaroid
	MagickPolaroidImage(m_wand,dw,30);
        //save
        MagickWriteImage(m_wand,output);

        /* Clean up */
        if(m_wand)m_wand = DestroyMagickWand(m_wand);

        MagickWandTerminus();
}

