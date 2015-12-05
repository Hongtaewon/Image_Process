#include <wand/magick_wand.h>
#include <stdlib.h>

void sharp(char* input,char* output)
{
        printf("sharped\n");
        MagickWand *m_wand = NULL;


        MagickWandGenesis();

        m_wand = NewMagickWand();
        //open
        MagickReadImage(m_wand,input);
        //sharpe
	MagickSharpenImage(m_wand,5,5);
	//save
        MagickWriteImage(m_wand,output);

        /* Clean up */
        if(m_wand)m_wand = DestroyMagickWand(m_wand);

        MagickWandTerminus();
}

