#include <wand/magick_wand.h>
#include <stdlib.h>

void sketch(char* input,char* output)
{
        printf("sketch\n");
        MagickWand *m_wand = NULL;


        MagickWandGenesis();

        m_wand = NewMagickWand();
        //open
        MagickReadImage(m_wand,input);
        //sketch
        MagickSketchImage(m_wand,0,2,30);
        //save
        MagickWriteImage(m_wand,output);

        /* Clean up */
        if(m_wand)m_wand = DestroyMagickWand(m_wand);

        MagickWandTerminus();
}

