#include <wand/magick_wand.h>
#include <stdlib.h>

void blur(char* input,char* output)
{
        printf("%s\n%s\n",input,output);
        MagickWand *m_wand = NULL;


        MagickWandGenesis();

        m_wand = NewMagickWand();
        //open
        MagickReadImage(m_wand,input);
	//blur
	MagickGaussianBlurImage(m_wand,5,0x8);
	//MagickBlurImage(m_wand,5,3);
        //save
        MagickWriteImage(m_wand,output);

        /* Clean up */
        if(m_wand)m_wand = DestroyMagickWand(m_wand);

        MagickWandTerminus();
}
