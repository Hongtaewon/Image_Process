#include <wand/magick_wand.h>
#include <stdlib.h>

void flip(char* input,char* output)
{
        printf("x-axis mirror\n");
        MagickWand *m_wand = NULL;


        MagickWandGenesis();

        m_wand = NewMagickWand();
        //open
        MagickReadImage(m_wand,input);
        //flip
	MagickFlipImage(m_wand);
        //save
        MagickWriteImage(m_wand,output);

        /* Clean up */
        if(m_wand)m_wand = DestroyMagickWand(m_wand);

        MagickWandTerminus();
}

