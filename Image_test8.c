#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)

#define TRUE	1
#define FALSE	0


typedef struct
{
	char	M, N;
	int		width;
	int		height;
	int		max;
	unsigned char **pixels;
} PGMImage;


int fnReadPGM(char* fileNm, PGMImage* img);
void fnClosePGM(PGMImage* img);
int fnWritePGM(char* fileNm, PGMImage* img);

int main(int argc, char** argv)
{
	PGMImage	img;

	if(argc != 2)
	{
		fprintf(stderr, "How To USE : %s <filename>\n", argv[0]);
		return -1;
	}


	if(fnReadPGM(argv[1], &img) != TRUE)
	{
		return -1;
	}

	if(fnWritePGM("zzang.pgm", &img) == TRUE)
	{
		printf("File SAVE!\n");
	}

	fnClosePGM(&img);

	return 0;
}

int fnReadPGM(char* fileNm, PGMImage* img)
{
	int i = 0;
	int j = 0;

	FILE* fp;

	if(fileNm == NULL)
	{
		fprintf(stderr, "fnReadPGM ERROR\n");
		return FALSE;
	}

	fp = fopen(fileNm, "rb");
	if(fp == NULL)
	{
		fprintf(stderr, "FAIL : %s\n", fileNm);
		return FALSE;
	}

	fscanf(fp, "%c%c\n", &img->M, &img->N);

	if(img->M != 'P' || img->N != '5')
	{
		fprintf(stderr, "THIS IS NOT PGM : %c%c\n", img->M, img->N);
		return FALSE;
	}

	fscanf(fp, "%d %d\n", &img->width, &img->height);
	fscanf(fp, "%d\n"   , &img->max                );

	if(img->max != 255)
	{
		fprintf(stderr, "FAIL\n");
		return FALSE;
	}

	img->pixels = (unsigned char**)calloc(img->height, sizeof(unsigned char*));

	for(i=0; i<img->height; i++)
	{
		img->pixels[i] = (unsigned char*)calloc(img->width, sizeof(unsigned char));
	}

	for(i=0; i<img->height; i++)
	{
		for(j=0; j<img->width; j++)
		{
			fread(&img->pixels[i][j], sizeof(unsigned char), 1, fp);
		}
	}

	fclose(fp);

	return TRUE;
}

void fnClosePGM(PGMImage* img)
{
	int i = 0;

	for(i=0; i<img->height; i++)
	{
		free(img->pixels[i]);
	}

	free(img->pixels);
}

int fnWritePGM(char* fileNm, PGMImage* img)
{
	int i = 0;
	int j = 0;

	FILE* fp;

	fp = fopen(fileNm, "w");
	if(fp == NULL)
	{
		fprintf(stderr, "FAIL\n");
		return FALSE;
	}

	fprintf(fp, "%c%c\n", 'P', '2');
	fprintf(fp, "%d %d\n" , img->width, img->height);
	fprintf(fp, "%d\n", 255);

	int tmp;

	for(i=0; i<img->height; i++)
	{
		for(j=0; j<img->width; j++)
		{
			tmp = img->pixels[i][j] + 40;

			if(tmp > 255)
			{
				tmp = 255;
			}

			fprintf(fp, "%d ", tmp);
		}
	}

	fclose(fp);

	return TRUE;
}


