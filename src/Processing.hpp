//
//  Processing.hpp
//  ImageProcessing
//
//  Created by 李鑫 on 2018/10/10.
//

#ifndef Processing_hpp
#define Processing_hpp

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

class ImageProcessing{
public:
	bool operation(const char* inputFileName,const char * outputFileName,const char operation);
private:
#pragma pack(2)
	typedef struct {
		unsigned short	bfType;			//the type of the file 2B
		unsigned int	bfSize;			//tell us how bing this file is,by Byte	 4B
		unsigned short	bfReserved1;	//reserve. must be 0 2B
		unsigned short	bfReserved2;	//reserve. must be 0 2B
		unsigned int	bfOffBits; 		//this value tell us the distance from begin to the data 4B
	} BITMAPFILEHEADER;

	typedef struct {
		unsigned int	biSize;			//
		int				biWidth;		//width of the picture
		int				biHeight;		//height of the picture. And if(biHeght>0)picture is reverse store;if<0,is 
		unsigned short	biPlanes;		//
		unsigned short	biBitCount;		//1\4\8\24\32
		unsigned int	biCompression;	//
		unsigned int	biSizeImage;	//the size of image
		int				biXPelsPerMeter;//pixels-per-meter
		int				biYPelsPerMeter;//pixels-per-meter
		unsigned int	biClrUsed;
		unsigned int	biClrImportant;
	} BITMAPINFOHEADER;

	typedef struct{
		unsigned char rgbRed;
		unsigned char rgbGreen;
		unsigned char rgbBlue;
	}IMAGEPIXEL;
#pragma pack()
    int                 image_width;
    int                 image_height;
    unsigned char*      RGB_Buff;
    unsigned int        BMP_bfOffBits;
    int                 BMP_biHeight;
	//unsigned char originimage[3][1024][1024];
	//unsigned char newimage[3][1024][1024];
	unsigned char ***originimage;//[3][1024][1024];
	unsigned char ***newimage;//3][1024][1024];
	unsigned int taskH;
	unsigned int taskW;

private:
    bool readFromBMP(const char* fileName, BITMAPFILEHEADER * fileHeader, BITMAPINFOHEADER * infoHeader);//,IMAGEPIXEL **imagebuff);
    bool writeToBMP(const char* fileName, int form, BITMAPFILEHEADER * fileHeader, BITMAPINFOHEADER * infoHeader, IMAGEPIXEL **imagebuff,unsigned int taskH,unsigned int taskW);
	bool BMP_mini(unsigned int taskH,unsigned int taskW);//BITMAPFILEHEADER * fileHeader, BITMAPINFOHEADER * infoHeader);
    bool BMP_inverse(void);
	bool BMP_equlization(void);
    bool BMP_gray(void);
	bool BMP_XYFFT(void);
	bool BMP_XYDFT(void);
	bool BMP_edge_detection(void);
	bool BMP_cut(void);
    void init();


};

#endif /* Processing_hpp */
