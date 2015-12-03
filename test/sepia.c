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
//	MagickSetImageColorspace(mw,GRAYColorspace);
	MagickSepiaToneImage(mw,30000);
	MagickWriteImage(mw,"sepia.jpg");

	/* Tidy up */
	if(mw) mw = DestroyMagickWand(mw);

	MagickWandTerminus();
}
