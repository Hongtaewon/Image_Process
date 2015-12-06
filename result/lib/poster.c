#include <wand/magick_wand.h>
#include <stdlib.h>

void poster(char* input,char* output)
{
        printf("poster\n");
        MagickWand *m_wand = NULL;


        MagickWandGenesis();

        m_wand = NewMagickWand();
        //open
        MagickReadImage(m_wand,input);
        //poster
	MagickPosterizeImage(m_wand,10,1);
        //save
        MagickWriteImage(m_wand,output);

        /* Clean up */
        if(m_wand)m_wand = DestroyMagickWand(m_wand);

        MagickWandTerminus();
}

