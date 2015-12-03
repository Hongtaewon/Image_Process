#include <wand/magick_wand.h>
#include <stdlib.h>

void main(int argc,char* argv[])
{
        printf("%s\n%s\n",argv[1],argv[2]);

        MagickWand *m_wand = NULL;


        MagickWandGenesis();

        m_wand = NewMagickWand();
        //open
        MagickReadImage(m_wand,argv[1]);
        //blur
	MagickGaussianBlurImage(m_wand,1,0x2);
        //MagickBlurImage(m_wand,5,3);

        //save
        MagickWriteImage(m_wand,argv[2]);

        // Clean up
        if(m_wand)m_wand = DestroyMagickWand(m_wand);

        MagickWandTerminus();
}
