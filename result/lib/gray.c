#include <wand/magick_wand.h>
#include <stdlib.h>

void gray(char* input,char* output)
{
        printf("gray\n");
        MagickWand *m_wand = NULL;


        MagickWandGenesis();

        m_wand = NewMagickWand();
	//open
        MagickReadImage(m_wand,input);
	//gray
	MagickSetImageColorspace(m_wand,GRAYColorspace);
	//save
        MagickWriteImage(m_wand,output);

        /* Clean up */
        if(m_wand)m_wand = DestroyMagickWand(m_wand);

        MagickWandTerminus();
}
