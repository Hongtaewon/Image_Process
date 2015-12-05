#include <wand/magick_wand.h>
void main()
{
	MagickWand *mw = NULL;
	PixelWand *background;
	MagickWandGenesis();

	/* Create a wand */
	mw = NewMagickWand();
	background = NewPixelWand();
	PixelSetColor(background,"#ffffff");
	/* Read the input image */
	MagickReadImage(mw,"dog.png");
	/* write it */
	MagickRotateImage(mw,background,90);
	MagickWriteImage(mw,"sepia.jpg");

	/* Tidy up */
	if(mw) mw = DestroyMagickWand(mw);

	MagickWandTerminus();
}
