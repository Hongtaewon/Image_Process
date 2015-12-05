#include <wand/magick_wand.h>
void main()
{
	MagickWand *mw = NULL;
	PixelWand *background;
	DrawingWand *dw = NULL;
	PixelWand *pw = NULL;
	MagickWandGenesis();

	/* Create a wand */
	mw = NewMagickWand();
	dw = NewDrawingWand();
	pw = NewPixelWand();
	background = NewPixelWand();
	PixelSetColor(background,"#ffffff");
	/* Read the input image */
	MagickReadImage(mw,"dog.png");
	/* write it */
	MagickSharpenImage(mw,5,5);
	//MagickShadowImage(mw,0,1,1,1);
	//MagickAnnotateImage(mw,dw,0,0,0,"Gel");
	//MagickTrimImage(mw,100);
	//MagickNegateImage(mw,MagickFalse);
	//MagickRollImage(mw,5,10);
	//MagickEvaluateImage(mw,MultiplyEvaluateOperator,2);
	//MagickNegateImage(mw,MagickFalse);
	//MagickShadeImage(mw,1,10,20);
	//MagickBlurImage(mw,0,3);
	//MagickSetImageAlphaChannel(mw,DeactivateAlphaChannel);
	//MagickRotateImage(mw,background,90);
	MagickWriteImage(mw,"qq.jpg");

	/* Tidy up */
	if(mw) mw = DestroyMagickWand(mw);

	MagickWandTerminus();
}
