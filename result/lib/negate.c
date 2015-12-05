#include <wand/magick_wand.h>
#include <stdlib.h>

void negate(char* input,char* output)
{
        printf("negative\n");
        MagickWand *m_wand = NULL;


        MagickWandGenesis();

        m_wand = NewMagickWand();
        //open
        MagickReadImage(m_wand,input);
        //negate
        MagickNegateImage(m_wand,MagickFalse);
        //save
        MagickWriteImage(m_wand,output);

        /* Clean up */
        if(m_wand)m_wand = DestroyMagickWand(m_wand);

        MagickWandTerminus();
}

