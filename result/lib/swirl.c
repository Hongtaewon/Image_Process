#include <wand/magick_wand.h>
#include <stdlib.h>

void swirl(char* input,char* output)
{
        printf("swirl\n");
        MagickWand *m_wand = NULL;


        MagickWandGenesis();

        m_wand = NewMagickWand();
        //open
        MagickReadImage(m_wand,input);
        //swirl
	MagickSwirlImage(m_wand,70);
        //save
        MagickWriteImage(m_wand,output);

        /* Clean up */
        if(m_wand)m_wand = DestroyMagickWand(m_wand);

        MagickWandTerminus();
}

