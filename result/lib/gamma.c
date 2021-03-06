#include <wand/magick_wand.h>
#include <stdlib.h>

void bright(char* input,char* output)
{
        printf("bright\n");
        MagickWand *m_wand = NULL;


        MagickWandGenesis();

        m_wand = NewMagickWand();
        //open
        MagickReadImage(m_wand,input);
        //brightness
	MagickGammaImage(m_wand,2);
        //save
        MagickWriteImage(m_wand,output);

        /* Clean up */
        if(m_wand)m_wand = DestroyMagickWand(m_wand);

        MagickWandTerminus();
}

