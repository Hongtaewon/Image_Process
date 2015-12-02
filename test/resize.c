#include <wand/magick_wand.h>
#include <stdlib.h>

void main(int argc,char *argv[])
{
	printf("%s\n%s\n",argv[1],argv[2]);
	MagickWand *m_wand = NULL;

	int width,height;

	MagickWandGenesis();

	m_wand = NewMagickWand();
	// Read the image - all you need to do is change "logo:" to some other
	// filename to have this resize and, if necessary, convert a different file
	MagickReadImage(m_wand,argv[1]);

	// Get the image's width and height
	width = MagickGetImageWidth(m_wand);
	height = MagickGetImageHeight(m_wand);

	// Cut them in half but make sure they don't underflow
	if((width /= 2) < 1)width = 1;
	if((height /= 2) < 1)height = 1;

	// Resize the image using the Lanczos filter
	// The blur factor is a "double", where > 1 is blurry, < 1 is sharp
	// I haven't figured out how you would change the blur parameter of MagickResizeImage
	// on the command line so I have set it to its default of one.
	MagickResizeImage(m_wand,width,height,LanczosFilter,1);

	//gray
	MagickSetImageColorspace(m_wand,GRAYColorspace);

	// Set the compression quality to 95 (high quality = low compression)
	MagickSetImageCompressionQuality(m_wand,95);



	/* Write the new image */
	MagickWriteImage(m_wand,argv[2]);

	/* Clean up */
	if(m_wand)m_wand = DestroyMagickWand(m_wand);

	MagickWandTerminus();
}
