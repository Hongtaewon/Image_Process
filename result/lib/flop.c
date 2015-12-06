#include <wand/magick_wand.h>
#include <stdlib.h>

void flop(char* input,char* output)
{
        printf("y-axis mirror\n");
        MagickWand *m_wand = NULL;


        MagickWandGenesis();

        m_wand = NewMagickWand();
        //open
        MagickReadImage(m_wand,input);
        //flop
	MagickFlopImage(m_wand);
        //save
        MagickWriteImage(m_wand,output);

        /* Clean up */
        if(m_wand)m_wand = DestroyMagickWand(m_wand);

        MagickWandTerminus();
}

