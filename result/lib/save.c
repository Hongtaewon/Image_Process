#include <wand/magick_wand.h>
#include <stdlib.h>

void saveImage(char* input,char* output)
{
        printf("save-Image\n");
        MagickWand *m_wand = NULL;
        MagickWandGenesis();
        m_wand = NewMagickWand();
        //open
        MagickReadImage(m_wand,input);
        //save
        MagickWriteImage(m_wand,output);

        /* Clean up */
        if(m_wand)m_wand = DestroyMagickWand(m_wand);

        MagickWandTerminus();
}

