#include <wand/magick_wand.h>
#include <stdlib.h>

void sepia(char* input,char* output)
{
        printf("%s\n%s\n",input,output);
        MagickWand *m_wand = NULL;


        MagickWandGenesis();

        m_wand = NewMagickWand();
        //open
        MagickReadImage(m_wand,input);
        //sepia
	MagickSepiaToneImage(m_wand,30000);
        //save
        MagickWriteImage(m_wand,output);

        /* Clean up */
        if(m_wand)m_wand = DestroyMagickWand(m_wand);

        MagickWandTerminus();
}

