#include <wand/magick_wand.h>
void main()
{
	MagickWand *mw = NULL;

	MagickWandGenesis();

	/* Create a wand */
	mw = NewMagickWand();

	/* Read the input image */
	MagickReadImage(mw,"logo:");
	/* write it */
	MagickGammaImage(mw,3);
	MagickWriteImage(mw,"sepia.jpg");

	/* Tidy up */
	if(mw) mw = DestroyMagickWand(mw);

	MagickWandTerminus();
}
