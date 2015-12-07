#include <wand/magick_wand.h>
void main()
{
	MagickWand *mw = NULL;
	PixelWand *background;
	DrawingWand *dw;
	MagickWandGenesis();

	/* Create a wand */
	mw = NewMagickWand();
	background = NewPixelWand();
	dw = NewDrawingWand();
	PixelSetColor(background,"#000fff");
	/* Read the input image */
	MagickReadImage(mw,"dog.png");
	/* write it */
	MagickWaveImage(mw,2,30);
	//MagickSwirlImage(mw,90);
	//MagickStripImage(mw);
	//MagickShearImage(mw,background,20,20);
	//MagickSetImageFuzz(mw,2);
	//MagickSetImageGravity(mw,PartitionInterlace);
	//MagickSetImageBorderColor(mw,background);
	//MagickPolaroidImage(mw,dw,30);
	//MagickMagnifyImage(mw);
	//MagickEdgeImage(mw,5);
	//MagickCoalesceImages(mw);
	//MagickClampImage(mw);
	//MagickChopImage(mw,11,11,11,11);
	//MagickCharcoalImage(mw,0,10);
	//MagickFlopImage(mw);
	//MagickFlipImage(mw);
	//MagickSpliceImage(mw,3,3,1,1);
	//MagickOilPaintImage(mw,3);
	///MagickPosterizeImage(mw,12,1);
	//MagickEmbossImage(mw,1,0);
	///MagickSketchImage(mw,0,2,30);
	//MagickSmushImages(mw,1,3);
	//MagickSpreadImage(mw,5);
	//MagickSharpenImage(mw,5,5);
	//MagickShadowImage(mw,0.5,1,0,0);
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
