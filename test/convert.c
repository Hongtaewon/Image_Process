#include <wand/magick_wand.h>
void main(void)
{
	MagickWand *mw = NULL;

	MagickWandGenesis();

	/* Create a wand */
	mw = NewMagickWand();

	/* Read the input image */
	MagickReadImage(mw,"logo:");
	/* write it */
	MagickSetImageColorspace(mw,GRAYColorspace);

	MagickWriteImage(mw,"gray.jpg");

	/* Tidy up */
	if(mw) mw = DestroyMagickWand(mw);

	MagickWandTerminus();
}
