//
//  Processing.cpp
//  ImageProcessing
//
//  Created by 李鑫 on 2018/10/10.
//

#include "Processing.hpp"
#include <math.h>


/* 
	c 图像反转 
	e 灰度均衡化 
	m 图像放缩
	t 测试模式
	f 傅立叶变换有FFT和DFT
	b 边缘提取 有拉普拉斯和sobel
	u 图像灰度切片
	g 灰度变换

*/
bool ImageProcessing::operation(const char* inputFileNmae, const char* outputFileName, const char operation){
	bool successed = false;
	int form =0;
	if(operation == 'c'){
		printf("in operation...\n");
		do{
			BITMAPFILEHEADER * fileHeader = new BITMAPFILEHEADER;
			BITMAPINFOHEADER * infoHeader = new BITMAPINFOHEADER;
			printf("ok new\n");
			IMAGEPIXEL **imageBUfF;
			readFromBMP(inputFileNmae,fileHeader,infoHeader);//, imageBUfF);
			printf("read over...\n");
			BMP_inverse();
			if(!strcmp(inputFileNmae,outputFileName)){
				form = 1;
			}
			else{
				form = 0;
			}
			printf("the form is %d.\n",form);
			writeToBMP(outputFileName,form,fileHeader,infoHeader, imageBUfF,taskH,taskW);
			printf("write over...\n");
			delete fileHeader;
			delete infoHeader;
			successed = true;
		}while(false);
	}
	else if(operation == 'e'){
		printf("in operation...\n");
		do{
			BITMAPFILEHEADER * fileHeader = new BITMAPFILEHEADER;
			BITMAPINFOHEADER * infoHeader = new BITMAPINFOHEADER;
			printf("ok new\n");
			IMAGEPIXEL **imageBUfF;
			readFromBMP(inputFileNmae,fileHeader,infoHeader);//, imageBUfF);
			printf("read over...\n");
			BMP_equlization();
			if(!strcmp(inputFileNmae,outputFileName)){
				form = 1;
			}
			else{
				form = 0;
			}
			printf("the form is %d.\n",form);
			writeToBMP(outputFileName,form,fileHeader,infoHeader, imageBUfF,taskH,taskW);
			printf("write over...\n");
			delete fileHeader;
			delete infoHeader;
			successed = true;
		}while(false);
	}
	else if(operation == 'm'){
		printf("in operation...\n");
		do{
			BITMAPFILEHEADER * fileHeader = new BITMAPFILEHEADER;
			BITMAPINFOHEADER * infoHeader = new BITMAPINFOHEADER;
			printf("ok new\n");
			IMAGEPIXEL **imageBUfF;
			readFromBMP(inputFileNmae,fileHeader,infoHeader);//, imageBUfF);
			printf("read over...\nplease input higt\n");
			scanf("%ud",&taskH);
			printf("please input width\n");
			scanf("%ud",&taskW);
			BMP_mini(taskH,taskW);
			if(!strcmp(inputFileNmae,outputFileName)){
				form = 1;
			}
			else{
				form = 0;
			}
			printf("the form is %d.\n",form);
			writeToBMP(outputFileName,form,fileHeader,infoHeader, imageBUfF,taskH,taskW);
			printf("write over...\n");
			delete fileHeader;
			delete infoHeader;
			successed = true;
		}while(false);
	}
	else if(operation == 't'){
		printf("in test...\n");
		do{
			BITMAPFILEHEADER * fileHeader = new BITMAPFILEHEADER;
			BITMAPINFOHEADER * infoHeader = new BITMAPINFOHEADER;
			printf("ok new\n");
			IMAGEPIXEL **imageBUfF;
			printf("It's OK\n");
			readFromBMP(inputFileNmae,fileHeader,infoHeader);//, imageBUfF);
			printf("read over...\n);//please input higt\n");
			//printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n",infoHeader->biSize,infoHeader->biPlanes,infoHeader->biCompression,infoHeader->biXPelsPerMeter,infoHeader->biYPelsPerMeter,infoHeader->biClrUsed,infoHeader->biClrImportant);
			// scanf("%ud",&taskH);
			// printf("please input width\n");
			// scanf("%ud",&taskW);
			// if(!strcmp(inputFileNmae,outputFileName)){
			// 	form = 1;
			// }
			// else{
			// 	form = 0;
			// }
			// printf("the form is %d.\n",form);
			// writeToBMP(outputFileName,form,fileHeader,infoHeader, imageBUfF,taskH,taskW);
			// printf("write over...\n");
			delete fileHeader;
			delete infoHeader;
			successed = true;
		}while(false);
	}
	else if(operation == 'f'){
		printf("in operation...\n");
		do{
			BITMAPFILEHEADER * fileHeader = new BITMAPFILEHEADER;
			BITMAPINFOHEADER * infoHeader = new BITMAPINFOHEADER;
			printf("ok new\n");
			IMAGEPIXEL **imageBUfF;
			readFromBMP(inputFileNmae,fileHeader,infoHeader);//, imageBUfF);
			printf("read over...\n");
			//BMP_XYDFT();
			BMP_XYFFT();
			if(!strcmp(inputFileNmae,outputFileName)){
				form = 1;
			}
			else{
				form = 0;
			}
			printf("the form is %d.\n",form);
			writeToBMP(outputFileName,form,fileHeader,infoHeader, imageBUfF,taskH,taskW);
			printf("write over...\n");
			delete fileHeader;
			delete infoHeader;
			successed = true;
		}while(false);
	}
	else if(operation == 'b'){
		printf("in operation...\n");
		do{
			BITMAPFILEHEADER * fileHeader = new BITMAPFILEHEADER;
			BITMAPINFOHEADER * infoHeader = new BITMAPINFOHEADER;
			printf("ok new\n");
			IMAGEPIXEL **imageBUfF;
			readFromBMP(inputFileNmae,fileHeader,infoHeader);//, imageBUfF);
			printf("read over...\n");
			//BMP_XYDFT();
			BMP_edge_detection();
			if(!strcmp(inputFileNmae,outputFileName)){
				form = 1;
			}
			else{
				form = 0;
			}
			printf("the form is %d.\n",form);
			writeToBMP(outputFileName,form,fileHeader,infoHeader, imageBUfF,taskH,taskW);
			printf("write over...\n");
			delete fileHeader;
			delete infoHeader;
			successed = true;
		}while(false);
	}
	else if(operation == 'u'){
		printf("in operation...\n");
		do{
			BITMAPFILEHEADER * fileHeader = new BITMAPFILEHEADER;
			BITMAPINFOHEADER * infoHeader = new BITMAPINFOHEADER;
			printf("ok new\n");
			IMAGEPIXEL **imageBUfF;
			readFromBMP(inputFileNmae,fileHeader,infoHeader);//, imageBUfF);
			printf("read over...\n");
			//BMP_XYDFT();
			BMP_cut();
			if(!strcmp(inputFileNmae,outputFileName)){
				form = 1;
			}
			else{
				form = 0;
			}
			printf("the form is %d.\n",form);
			writeToBMP(outputFileName,form,fileHeader,infoHeader, imageBUfF,taskH,taskW);
			printf("write over...\n");
			delete fileHeader;
			delete infoHeader;
			successed = true;
		}while(false);
	}
	else if(operation == 'g'){
		printf("in operation...\n");
		do{
			BITMAPFILEHEADER * fileHeader = new BITMAPFILEHEADER;
			BITMAPINFOHEADER * infoHeader = new BITMAPINFOHEADER;
			printf("ok new\n");
			IMAGEPIXEL **imageBUfF;
			readFromBMP(inputFileNmae,fileHeader,infoHeader);//, imageBUfF);
			printf("read over...\n");
			//BMP_XYDFT();
			BMP_gray();
			if(!strcmp(inputFileNmae,outputFileName)){
				form = 1;
			}
			else{
				form = 0;
			}
			printf("the form is %d.\n",form);
			writeToBMP(outputFileName,form,fileHeader,infoHeader, imageBUfF,taskH,taskW);
			printf("write over...\n");
			delete fileHeader;
			delete infoHeader;
			successed = true;
		}while(false);
	}
	
	for(int h=0;h<3;h++){
		for(int i=0;i<88888;i++){
			delete[] originimage[h][i];
			delete[] newimage[h][i];
		}
		//printf("over\n");
		delete[] newimage[h];
		delete[] originimage[h];
	}
	delete[] newimage;
	delete[] originimage;
	delete RGB_Buff;
	return successed;
}

void ImageProcessing::init(void){
	//if(RGB_Buff) delete[] RGB_Buff;
	RGB_Buff=0;

	image_width=0;
	image_height=0;
}

bool ImageProcessing::readFromBMP(const char* fileName, BITMAPFILEHEADER * fileHeader, BITMAPINFOHEADER * infoHeader){//}, IMAGEPIXEL **imagebuff){
	init();
	printf("OK\n");
	FILE* fp = fopen(fileName, "rb");
	if(fp==0) return false;

	bool successed=false;
	do
	{
		if(1 != fread(fileHeader, sizeof(BITMAPFILEHEADER), 1, fp)) break;
		if(fileHeader->bfType!=0x4D42) break;

		if(1 != fread(infoHeader, sizeof(BITMAPINFOHEADER), 1, fp)) break;
		if(infoHeader->biBitCount!=24 || infoHeader->biCompression!=0) break;
		int width = infoHeader->biWidth;
		int height = infoHeader->biHeight < 0 ? (-infoHeader->biHeight) : infoHeader->biHeight;
		if((width&7)!=0 || (height&7)!=0) break;	

		int bmpSize = width*height*3;
		/*
		for(int i=0;i<infoHeader->biHeight;i++){
			imagebuff[i] = new IMAGEPIXEL[infoHeader->biWidth];
		}
		if(imagebuff == 0){
			printf("new imagebuff error\n");
			break;
		}*/
		unsigned char* buffer = new unsigned char[bmpSize];
		if(buffer==0) break;
		printf("new buff ok");

		fseek(fp, fileHeader->bfOffBits, SEEK_SET);

		if(infoHeader->biHeight>0)
		{
			for(int i=0; i<height; i++)
			{
				if(width != fread(buffer+(height-1-i)*width*3, 3, width, fp)) 
				{
					delete[] buffer; buffer=0;
					break;
				}
			}
		}
		else
		{
			if(width*height != fread(buffer, 3, width*height, fp))
			{
				delete[] buffer; buffer=0;
				break;
			}
		}
        printf("%d\n",infoHeader->biBitCount);
        printf("%d * %d\n",width,height);
		RGB_Buff = buffer;
		image_width = width;
		image_height = height;
        BMP_bfOffBits = fileHeader->bfOffBits;
        BMP_biHeight = infoHeader->biHeight;
		taskH = height;
		taskW = width;
		//
		newimage = new unsigned char **[3];
		for(int i=0;i<3;i++){
			newimage[i] = new unsigned char *[88888];
			for(int j=0;j<88888;j++){
				newimage[i][j] = new unsigned char [88888];
			}
		}
		originimage = new unsigned char **[3];
		for(int i=0;i<3;i++){
			originimage[i] = new unsigned char *[88888];
			for(int j=0;j<88888;j++){
				originimage[i][j] = new unsigned char [8888];
			}
		}

		for(int i=0,j=0;i<image_width*image_height*3;i++){
			j=i/3;
			originimage[i%3][j/image_height][j%image_height]=RGB_Buff[i];
			//newimage[i%3][j/image_height][j%image_height]=RGB_Buff[i];
		}
		successed=true;

	}while(false);

	fclose(fp);fp=0;
	
	return successed;
}

bool ImageProcessing::writeToBMP(const char* fileName, int form, BITMAPFILEHEADER * fileHeader, BITMAPINFOHEADER * infoHeader,IMAGEPIXEL **imagebuff,unsigned int taskH,unsigned int taskW){
    bool successed=false;
	printf("I am in write to BMP\n");
    if(form == 1){
	    FILE* fp = fopen(fileName, "rb+");
	    if(fp==0) return false;
	    do
	    {
		    fseek(fp, BMP_bfOffBits, SEEK_SET);

		    if(BMP_biHeight>0)
	    	{
				for(int i=0; i<infoHeader->biHeight; i++)
		    	{
                    //fwrite(RGB_Buff+(BMP_biHeight-1-i)*infoHeader->biWidth*3, 3, infoHeader->biWidth, fp);
					for(int j=0;j<infoHeader->biWidth;j++){
						for(int h=0;h<3;h++){
							fwrite(newimage[h][BMP_biHeight-i-1]+j,1,1,fp);
						}
				    } 
	           }
				//fwrite(RGB_Buff, 3, image_width*image_height, fp);
		    	// for(int i=0; i<image_height; i++)
		    	// {
                //     fwrite(RGB_Buff+(image_height-1-i)*image_width*3, 3, image_width, fp);
                // }
                // printf("this image is over\n");
            }
            else
            {
                fwrite(RGB_Buff, 3, image_width*image_height, fp);
                printf("this image is nomoal\n");
            }
            successed=true;
    	}while(false);

	    fclose(fp);fp=0;
        printf("%d * %d\n",image_width,image_height);
	    return successed;
    }
	else{
		FILE* fp = fopen(fileName, "wb");
	    if(fp==0) return false;
		printf("load over\n");
		do{
			infoHeader->biWidth = taskW;
			infoHeader->biHeight = taskH;
			printf("begin write data\n%ud\n",infoHeader->biWidth);
			infoHeader->biSizeImage = infoHeader->biWidth * infoHeader->biHeight;
			fileHeader->bfSize = fileHeader->bfOffBits + infoHeader->biSizeImage;
			fwrite(fileHeader,sizeof(BITMAPFILEHEADER),1,fp);
			fwrite(infoHeader,sizeof(BITMAPINFOHEADER),1,fp);
			//printf("begin write data\n%ud\n",fileHeader->bfOffBits);
			fseek(fp, fileHeader->bfOffBits, SEEK_SET);
			printf("I am here");
			if(infoHeader->biHeight >0)
	    	{
				
		    	for(int i=0; i<infoHeader->biHeight; i++)
		    	{
                    //fwrite(RGB_Buff+(BMP_biHeight-1-i)*infoHeader->biWidth*3, 3, infoHeader->biWidth, fp);
					for(int j=0;j<infoHeader->biWidth;j++){
						for(int h=0;h<3;h++){
							fwrite(newimage[h][infoHeader->biHeight-i-1]+j,1,1,fp);
						}
				    }
	           }
                printf("this new image is over\n");
            }
            else
            {
				for(int i=0; i<infoHeader->biHeight; i++)
		    	{
                    //fwrite(RGB_Buff+(BMP_biHeight-1-i)*infoHeader->biWidth*3, 3, infoHeader->biWidth, fp);
					for(int j=0;j<infoHeader->biWidth;j++){
						for(int h=0;h<3;h++){
							fwrite(newimage[h][infoHeader->biHeight-i],3,infoHeader->biWidth,fp);
						}
				    }
	           }
                //fwrite(newimage[0][0], 3, infoHeader->biWidth*infoHeader->biHeight, fp);
                printf("this image is nomoal\n");
            }
			successed = true;
		}while(false);
	}
    return successed;
}

bool ImageProcessing::BMP_inverse(void){
    bool successed = false;
    do{
        for(int i = 0;i < image_width*image_height*3;i++){
            RGB_Buff[i] = (char)(255-(int)RGB_Buff[i]);
        }
		for(int i=0,j=0;i<image_width*image_height*3;i++){
			j=i/3;
			newimage[i%3][j/image_height][j%image_height]=RGB_Buff[i];
		}
        successed = true;
    }while(false);
    return successed;
    return true;
}

bool ImageProcessing::BMP_gray(void){
    bool successed;
	do{
		for(int i=0,j=0;i<image_width*image_height*3;i++){
			j=i/3;
			originimage[i%3][j/image_height][j%image_height]=RGB_Buff[i];
			newimage[i%3][j/image_height][j%image_height]=RGB_Buff[i];
		}
		int ycrcb[3][512][512];
		for(int i=1;i<image_height;i++){
			for(int j=1;j<image_width;j++){
				ycrcb[0][i][j] = ((originimage[2][i][j]*0.299 + originimage[1][i][j]*0.587 + originimage[0][i][j]*0.114));  //
				ycrcb[1][i][j] = (originimage[2][i][j]*(-0.1687) + originimage[1][i][j]*(-0.3313) + originimage[0][i][j]*0.5+128);  //
				ycrcb[2][i][j] = (originimage[2][i][j]*0.5 + originimage[1][i][j]*(-0.4187) + originimage[0][i][j]*(-0.0813)+128);  //
			}
		}
		for(int i=1;i<image_height;i++){
			for(int j=1;j<image_width;j++){
				if(ycrcb[0][i][j] > 255)
					ycrcb[0][i][j] = 255;
				else if(ycrcb[0][i][j] < 0)
					ycrcb[0][i][j] = 0;
				if(ycrcb[1][i][j] > 255)
					ycrcb[1][i][j] = 255;
				else if(ycrcb[1][i][j] < 0)
					ycrcb[1][i][j] = 0;
				if(ycrcb[2][i][j] > 255)
					ycrcb[2][i][j] = 255;
				else if(ycrcb[2][i][j] < 0)
					ycrcb[2][i][j] = 0;
			}
		}
		for(int i=1;i<image_height;i++){
			for(int j=1;j<image_width;j++){
				originimage[0][i][j] = (unsigned char)ycrcb[0][i][j];	//Y
				originimage[1][i][j] = (unsigned char)ycrcb[1][i][j];	//Cb
				originimage[2][i][j] = (unsigned char)ycrcb[2][i][j];	//Cr
			}
		} 
		for(int i=1;i<image_height;i++){
			for(int j=1;j<image_width;j++){
				newimage[2][i][j] = (unsigned char)(originimage[0][i][j] + 1.402*(originimage[2][i][j] - 128) );	//R
				newimage[1][i][j] = (unsigned char)(originimage[0][i][j] - 0.34414*(originimage[1][i][j]*-128) -0.71414 *(originimage[2][i][j]-128)) ;	//G
				newimage[0][i][j] = (unsigned char)(originimage[0][i][j] + 1.772*(originimage[1][i][j]-128)) ;	//B
			}
		}
        successed = true;
	}while(false);
	return successed;
}

bool ImageProcessing::BMP_equlization(void){
	bool successed = false;
	do{
		int k=0,hist[3][256]={0};
		
		for(int i=0,j=0;i<image_width*image_height*3;i++){
			j=i/3;
			originimage[i%3][j/image_height][j%image_height]=RGB_Buff[i];
			newimage[i%3][j/image_height][j%image_height]=RGB_Buff[i];
		}
		//statistic histogram
		for(int h=0;h<3;h++){
			for(int i =0;i<image_height;i++){
				for(int j=0;j<image_width;j++){
					k=originimage[h][i][j];
					hist[h][k]++;
				}
			}
		}
		for(int i = 0;i < 3;i++){
			for(k=1;k<256;k++){
				hist[i][k] += hist[i][k-1];
			}
			for(k=0;k<256;k++){
				hist[i][k]=hist[i][k]*255.0/((double)image_width*(double)image_height)+0.5;
			}
		}
		//equalization
		for(int h = 0;h < 3;h++){
			for(int i=0;i<image_height;i++){
				for(int j=0;j<image_width;j++){
					k = originimage[h][i][j];
					newimage[h][i][j]=hist[h][k];
				}
			}
		}
		// for(int i,j;i<image_width*image_height*3;i++){
		// 	j=i/3;
		// 	RGB_Buff[i]=newimage[i%3][j/image_width][j%image_width];
		// }
        successed = true;
	}while(false);
	return successed;
}


double san_f(double x){
	if(x<0){
		x = -x;
	}else if(x>=0&&x<=1){
		return (1-2*pow(x,2)+pow(x,3));
	}else if(x>=2){
		return 0.0;
	}
	return 0.0;
}

bool ImageProcessing::BMP_mini(unsigned int taskH,unsigned int taskW){//, BITMAPFILEHEADER * fileHeader, BITMAPINFOHEADER * infoHeader){
	bool successed;
	do{
		//
		for(int i=0,j=0;i<image_width*image_height*3;i++){
			j=i/3;
			originimage[i%3][j/image_height][j%image_height]=RGB_Buff[i];
			newimage[i%3][j/image_height][j%image_height]=RGB_Buff[i];
		}


		 for(int h=0;h<3;h++){   //sanxian
			for(int i=0;i<taskH;i++){
				double y = ((double)i+0.5)*(double)image_height/(double)taskH-0.5;
				for(int j=0;j<taskW;j++){
					double x = ((double)j+0.5)*(double)image_width/(double)taskW-0.5;
					int iy = (int)y;
					int ix = (int)x;
					//printf("%d %d\n",ix,iy);
					int u = (int)((y-(int)y)*1);
					int v = (int)((x-(int)x)*1);
					if(ix >= (image_width-3)){
						ix = (image_width-3);
					}else if(ix <=1){
						ix = 1;
					}
					if(iy >= image_height-3){
						iy = image_height-3;
					}else if(iy <= 1){
						iy = 1;
					}
					double a1,a2,a3,a4;
					double re1,re2,re3,re4;
					double c1,c2,c3,c4;
					a1 = san_f(1+v);a2 = san_f(v);a3 = san_f(1-v);a4 = san_f(2-v);
					c1 = san_f(1+u);c2 = san_f(u);c3 = san_f(1-u);c4 = san_f(2-u);
					re1 = a1*(double)originimage[h][iy-1][ix-1]+a2*(double)originimage[h][iy][ix-1]+a3*(double)originimage[h][iy+1][ix-1]+a4*(double)originimage[h][iy+2][ix-1];
					re2 = a1*(double)originimage[h][iy-1][ix]+a2*(double)originimage[h][iy][ix]+a3*(double)originimage[h][iy+1][ix]+a4*(double)originimage[h][iy+2][ix];
					re3 = a1*(double)originimage[h][iy-1][ix+1]+a2*(double)originimage[h][iy][ix+1]+a3*(double)originimage[h][iy+1][ix+11]+a4*(double)originimage[h][iy+2][ix+1];
					re4 = a1*(double)originimage[h][iy-1][ix+2]+a2*(double)originimage[h][iy][ix+2]+a3*(double)originimage[h][iy+1][ix+2]+a4*(double)originimage[h][iy+2][ix+2];
					a1 = re1*c1+re2*c2+re3*c3+re4*c4;
					newimage[h][i][j]=(unsigned char)a1;//>>22;
					//printf("%d\n",(int)newimage[h][i][j]);
					}
			}





		// for(int h=0;h<3;h++){
		// 	for(int i=0;i<taskH;i++){
		// 		double y = ((double)i+0.5)*(double)image_height/(double)taskH-0.5;
		// 		for(int j=0;j<taskW;j++){
		// 			double x = ((double)j+0.5)*(double)image_width/(double)taskW-0.5;
		// 			int iy = (int)y;
		// 			int ix = (int)x;
		// 			//printf("%d %d\n",ix,iy);
		// 			int u = (int)((y-(int)y)*1);
		// 			int v = (int)((x-(int)x)*1);
		// 			if(ix >= (image_width-1)){
		// 				ix = (image_width-1);
		// 			}else if(ix <=0){
		// 				ix = 0;
		// 			}
		// 			if(iy >= image_height-1){
		// 				iy = image_height-1;
		// 			}else if(iy <= 0){
		// 				iy = 0;
		// 			}
		// 			newimage[h][i][j]=(unsigned char)((double)originimage[h][iy][ix]*(1-u)*(1-v)
		// 							+(double)originimage[h][iy+1][ix]*(1-u)*v
		// 							+(double)originimage[h][iy][ix+1]*u*(1-v)
		// 							+(double)originimage[h][iy+1][ix+1]*u*v);//>>22;
		// 			//printf("%d\n",(int)newimage[h][i][j]);
		// 			}
		// 	}
		 }
        successed = true;
	}while(false);
	return successed;
}

bool ImageProcessing::BMP_edge_detection(void){//, BITMAPFILEHEADER * fileHeader, BITMAPINFOHEADER * infoHeader){
	bool successed;
	do{
		for(int i=0,j=0;i<image_width*image_height*3;i++){
			j=i/3;
			originimage[i%3][j/image_height][j%image_height]=RGB_Buff[i];
			newimage[i%3][j/image_height][j%image_height]=RGB_Buff[i];
		}
		for(int i=1;i<image_height-1;i++){
			for(int j=1;j<image_width-1;j++){
				originimage[0][i][j] = originimage[2][i][j]*0.299 + originimage[1][i][j]*0.587 + originimage[0][i][j]*0.114;
			}
		}
		for(int h=0;h<1;h++){   //sanxian
			for(int i=1;i<image_height;i++){
				for(int j=1;j<image_width;j++){
					// if(i >= (image_height-2)){
					// 	i = (image_height-2);
					// }else if(i <=1){
					// 	i = 1;
					// }
					// if(j >= image_width-2){
					// 	j = image_width-2;
					// }else if(j <= 1){
					// 	j = 1;
					// }
					double f_x = fabs((originimage[h][i+1][j-1]+2*originimage[h][i+1][j]+originimage[h][i+1][j+1]-originimage[h][i-1][j-1]-2*originimage[h][i-1][j]-originimage[h][i-1][j+1]));
					double f_y = fabs((originimage[h][i-1][j+1]+2*originimage[h][i][j+1]+originimage[h][i+1][j+1]-originimage[h][i-1][j-1]-2*originimage[h][i][j-1]-originimage[h][i+1][j+1]));
					//  lapulasi double f_x = fabs((4*originimage[h][i+1][j]+4*originimage[h][i-1][j]+4*originimage[h][i][j+1]+4*originimage[h][i][j-1]-20*originimage[h][i][j]+originimage[h][i+1][j+1]+originimage[h][i-1][j+1]+originimage[h][i+1][j-1]+originimage[h][i-1][j-1]));
					// double f_y = fabs((originimage[h][i-1][j+1]+2*originimage[h][i][j+1]+originimage[h][i+1][j+1]-originimage[h][i-1][j-1]-2*originimage[h][i][j-1]-originimage[h][i+1][j+1]));
					double a = pow((pow(f_x,2)+pow(f_y,2)),0.5);
					// int ii=0,jj=0;
					//double a = f_x;
					if(a>=200){
						for(int hh =0;hh<3;hh++)
							newimage[hh][i][j] = 255;
					}
					else{
						for(int hh =0;hh<3;hh++)
							newimage[hh][i][j] = 0;
					}
					// double a1,a2,a3,a4;
					// double re1,re2,re3,re4;
					// double c1,c2,c3,c4;
					// a1 = san_f(1+v);a2 = san_f(v);a3 = san_f(1-v);a4 = san_f(2-v);
					// c1 = san_f(1+u);c2 = san_f(u);c3 = san_f(1-u);c4 = san_f(2-u);
					// re1 = a1*(double)originimage[h][iy-1][ix-1]+a2*(double)originimage[h][iy][ix-1]+a3*(double)originimage[h][iy+1][ix-1]+a4*(double)originimage[h][iy+2][ix-1];
					// re2 = a1*(double)originimage[h][iy-1][ix]+a2*(double)originimage[h][iy][ix]+a3*(double)originimage[h][iy+1][ix]+a4*(double)originimage[h][iy+2][ix];
					// re3 = a1*(double)originimage[h][iy-1][ix+1]+a2*(double)originimage[h][iy][ix+1]+a3*(double)originimage[h][iy+1][ix+11]+a4*(double)originimage[h][iy+2][ix+1];
					// re4 = a1*(double)originimage[h][iy-1][ix+2]+a2*(double)originimage[h][iy][ix+2]+a3*(double)originimage[h][iy+1][ix+2]+a4*(double)originimage[h][iy+2][ix+2];
					// a1 = re1*c1+re2*c2+re3*c3+re4*c4;
					// newimage[h][i][j]=(unsigned char)a;//>>22;
					//printf("%d\n",(int)newimage[h][i][j]);
				}
			}
		}
        successed = true;
	}while(false);
	return successed;
}

bool ImageProcessing::BMP_cut(void){//, BITMAPFILEHEADER * fileHeader, BITMAPINFOHEADER * infoHeader){
	bool successed;
	do{
		for(int i=0,j=0;i<image_width*image_height*3;i++){
			j=i/3;
			originimage[i%3][j/image_height][j%image_height]=RGB_Buff[i];
			newimage[i%3][j/image_height][j%image_height]=RGB_Buff[i];
		}
		for(int i=1;i<image_height-1;i++){
			for(int j=1;j<image_width-1;j++){
				originimage[0][i][j] = originimage[2][i][j]*0.299 + originimage[1][i][j]*0.587 + originimage[0][i][j]*0.114;
			}
		}
		for(int h=0;h<1;h++){   //sanxian
			for(int i=1;i<image_height;i++){
				for(int j=1;j<image_width;j++){
					//double f_x = fabs((originimage[h][i+1][j-1]+2*originimage[h][i+1][j]+originimage[h][i+1][j+1]-originimage[h][i-1][j-1]-2*originimage[h][i-1][j]-originimage[h][i-1][j+1]));
					//double f_y = fabs((originimage[h][i-1][j+1]+2*originimage[h][i][j+1]+originimage[h][i+1][j+1]-originimage[h][i-1][j-1]-2*originimage[h][i][j-1]-originimage[h][i+1][j+1]));
					//  lapulasi double f_x = fabs((4*originimage[h][i+1][j]+4*originimage[h][i-1][j]+4*originimage[h][i][j+1]+4*originimage[h][i][j-1]-20*originimage[h][i][j]+originimage[h][i+1][j+1]+originimage[h][i-1][j+1]+originimage[h][i+1][j-1]+originimage[h][i-1][j-1]));
					// double f_y = fabs((originimage[h][i-1][j+1]+2*originimage[h][i][j+1]+originimage[h][i+1][j+1]-originimage[h][i-1][j-1]-2*originimage[h][i][j-1]-originimage[h][i+1][j+1]));
					//double a = pow((pow(f_x,2)+pow(f_y,2)),0.5);
					int a = originimage[0][i][j];
					// int ii=0,jj=0;
					//double a = f_x;
					if(a>=50&&a<100){
						for(int hh =0;hh<3;hh++)
							newimage[hh][i][j] = 255;
					}
					else{
						for(int hh =0;hh<3;hh++)
							newimage[hh][i][j] = 0;
					}
					// double a1,a2,a3,a4;
					// double re1,re2,re3,re4;
					// double c1,c2,c3,c4;
					// a1 = san_f(1+v);a2 = san_f(v);a3 = san_f(1-v);a4 = san_f(2-v);
					// c1 = san_f(1+u);c2 = san_f(u);c3 = san_f(1-u);c4 = san_f(2-u);
					// re1 = a1*(double)originimage[h][iy-1][ix-1]+a2*(double)originimage[h][iy][ix-1]+a3*(double)originimage[h][iy+1][ix-1]+a4*(double)originimage[h][iy+2][ix-1];
					// re2 = a1*(double)originimage[h][iy-1][ix]+a2*(double)originimage[h][iy][ix]+a3*(double)originimage[h][iy+1][ix]+a4*(double)originimage[h][iy+2][ix];
					// re3 = a1*(double)originimage[h][iy-1][ix+1]+a2*(double)originimage[h][iy][ix+1]+a3*(double)originimage[h][iy+1][ix+11]+a4*(double)originimage[h][iy+2][ix+1];
					// re4 = a1*(double)originimage[h][iy-1][ix+2]+a2*(double)originimage[h][iy][ix+2]+a3*(double)originimage[h][iy+1][ix+2]+a4*(double)originimage[h][iy+2][ix+2];
					// a1 = re1*c1+re2*c2+re3*c3+re4*c4;
					// newimage[h][i][j]=(unsigned char)a;//>>22;
					//printf("%d\n",(int)newimage[h][i][j]);
				}
			}
		}
        successed = true;
	}while(false);
	return successed;
}


//

struct Complex_{
    double real;
    double imagin;
};
typedef struct Complex_ Complex;
int isBase2(int size_n){
    int k=size_n;
    int z=0;
    while (k/=2) {
        z++;
    }
    k=z;
    if(size_n!=(1<<k))
        return -1;
    else
        return k;
}
void Copy_Complex(Complex * src,Complex *dst){
    dst->real=src->real;
    dst->imagin=src->imagin;
}
int DFT2D(double *src,Complex *dst,int size_w,int size_h){
    for(int u=0;u<size_w;u++){
        for(int v=0;v<size_h;v++){
            double real=0.0;
            double imagin=0.0;
            for(int i=0;i<size_w;i++){
                for(int j=0;j<size_h;j++){
                    double I=src[i*size_w+j];
                    double x=M_PI*2*((double)i*u/(double)size_w+(double)j*v/(double)size_h);
                    real+=cos(x)*I;
                    imagin+=-sin(x)*I;

                }
            }
            dst[u*size_w+v].real=real;
            dst[u*size_w+v].imagin=imagin;

        }

    }
    return 0;
}
/*

 */
int IDFT2D(Complex *src,Complex *dst,int size_w,int size_h){
    for(int i=0;i<size_w;i++){
        for(int j=0;j<size_h;j++){
            double real=0.0;
            double imagin=0.0;
            for(int u=0;u<size_w;u++){
                for(int v=0;v<size_h;v++){
                    double R=src[u*size_w+v].real;
                    double I=src[u*size_w+v].imagin;
                    double x=M_PI*2*((double)i*u/(double)size_w+(double)j*v/(double)size_h);
                    real+=R*cos(x)-I*sin(x);
                    imagin+=I*cos(x)+R*sin(x);

                }
            }
            dst[i*size_w+j].real=(1./(size_w*size_h))*real;
            dst[i*size_w+j].imagin=(1./(size_w*size_h))*imagin;

        }
    }
    return 0;
}
/*



 */
void ColumnVector(Complex * src,Complex * dst,int size_w,int size_h){
    for(int i=0;i<size_h;i++)
        Copy_Complex(&src[size_w*i], &dst[i]);

}
/*

 */
void IColumnVector(Complex * src,Complex * dst,int size_w,int size_h){
    for(int i=0;i<size_h;i++)
        Copy_Complex(&src[i],&dst[size_w*i]);

}
/*
 */
 ////////////////////////////////////////////////////////////////////
//FFT«∞£¨∂‘ ‰»Î ˝æ›÷ÿ–¬≈≈–Ú
///////////////////////////////////////////////////////////////////
int FFTReal_remap(double * src,int size_n){

    if(size_n==1)
        return 0;
    double * temp=(double *)malloc(sizeof(double)*size_n);
    for(int i=0;i<size_n;i++)
        if(i%2==0)
            temp[i/2]=src[i];
        else
            temp[(size_n+i)/2]=src[i];
    for(int i=0;i<size_n;i++)
        src[i]=temp[i];
    free(temp);
    FFTReal_remap(src, size_n/2);
    FFTReal_remap(src+size_n/2, size_n/2);
    return 1;


}
int FFTComplex_remap(Complex * src,int size_n){

    if(size_n==1)
        return 0;
    Complex * temp=(Complex *)malloc(sizeof(Complex)*size_n);
    for(int i=0;i<size_n;i++)
        if(i%2==0)
            Copy_Complex(&src[i],&(temp[i/2]));
        else
            Copy_Complex(&(src[i]),&(temp[(size_n+i)/2]));
    for(int i=0;i<size_n;i++)
        Copy_Complex(&(temp[i]),&(src[i]));
    free(temp);
    FFTComplex_remap(src, size_n/2);
    FFTComplex_remap(src+size_n/2, size_n/2);
    return 1;


}
////////////////////////////////////////////////////////////////////
//º∆À„WN
///////////////////////////////////////////////////////////////////
void getWN(double n,double size_n,Complex * dst){
    double x=2.0*M_PI*n/size_n;
    dst->imagin=-sin(x);
    dst->real=cos(x);
}
////////////////////////////////////////////////////////////////////
//∏¥ ˝ª˘±æ‘ÀÀ„
///////////////////////////////////////////////////////////////////
void Add_Complex(Complex * src1,Complex *src2,Complex *dst){
    dst->imagin=src1->imagin+src2->imagin;
    dst->real=src1->real+src2->real;
}
void Sub_Complex(Complex * src1,Complex *src2,Complex *dst){
    dst->imagin=src1->imagin-src2->imagin;
    dst->real=src1->real-src2->real;
}
void Multy_Complex(Complex * src1,Complex *src2,Complex *dst){
    double r1=0.0,r2=0.0;
    double i1=0.0,i2=0.0;
    r1=src1->real;
    r2=src2->real;
    i1=src1->imagin;
    i2=src2->imagin;
    dst->imagin=r1*i2+r2*i1;
    dst->real=r1*r2-i1*i2;
}
 void RealFFT(double * src,Complex * dst,int size_n){


    int k=size_n;
    int z=0;
    while (k/=2) {
        z++;
    }
    k=z;
    if(size_n!=(1<<k))
        exit(0);
    Complex * src_com=(Complex*)malloc(sizeof(Complex)*size_n);
    if(src_com==NULL)
        exit(0);
    for(int i=0;i<size_n;i++){
        src_com[i].real=src[i];
        src_com[i].imagin=0;
    }
    FFTComplex_remap(src_com, size_n);
    for(int i=0;i<k;i++){
        z=0;
        for(int j=0;j<size_n;j++){
            if((j/(1<<i))%2==1){
                Complex wn;
                getWN(z, size_n, &wn);
                Multy_Complex(&src_com[j], &wn,&src_com[j]);
                z+=1<<(k-i-1);
                Complex temp;
                int neighbour=j-(1<<(i));
                temp.real=src_com[neighbour].real;
                temp.imagin=src_com[neighbour].imagin;
                Add_Complex(&temp, &src_com[j], &src_com[neighbour]);
                Sub_Complex(&temp, &src_com[j], &src_com[j]);
            }
            else
                z=0;
        }

    }


    for(int i=0;i<size_n;i++){
        Copy_Complex(&src_com[i], &dst[i]);
    }
    free(src_com);

}
void FFT(Complex * src,Complex * dst,int size_n){

    int k=size_n;
    int z=0;
    while (k/=2) {
        z++;
    }
    k=z;
    if(size_n!=(1<<k))
        exit(0);
    Complex * src_com=(Complex*)malloc(sizeof(Complex)*size_n);
    if(src_com==NULL)
        exit(0);
    for(int i=0;i<size_n;i++){
        Copy_Complex(&src[i], &src_com[i]);
    }
    FFTComplex_remap(src_com, size_n);
    for(int i=0;i<k;i++){
        z=0;
        for(int j=0;j<size_n;j++){
            if((j/(1<<i))%2==1){
                Complex wn;
                getWN(z, size_n, &wn);
                Multy_Complex(&src_com[j], &wn,&src_com[j]);
                z+=1<<(k-i-1);
                Complex temp;
                int neighbour=j-(1<<(i));
                temp.real=src_com[neighbour].real;
                temp.imagin=src_com[neighbour].imagin;
                Add_Complex(&temp, &src_com[j], &src_com[neighbour]);
                Sub_Complex(&temp, &src_com[j], &src_com[j]);
            }
            else
                z=0;
        }

    }


    for(int i=0;i<size_n;i++){
        Copy_Complex(&src_com[i], &dst[i]);
    }
    free(src_com);


}
int FFT2D(double *src,Complex *dst,int size_w,int size_h){
    if(isBase2(size_w)==-1||isBase2(size_h)==-1)
        exit(0);
    Complex *temp=(Complex *)malloc(sizeof(Complex)*size_h*size_w);
    if(temp==NULL)
        return -1;
    for(int i=0;i<size_h;i++){
        RealFFT(&src[size_w*i], &temp[size_w*i], size_w);
    }

    Complex *Column=(Complex *)malloc(sizeof(Complex)*size_h);
    if(Column==NULL)
        return -1;
    for(int i=0;i<size_w;i++){
        ColumnVector(&temp[i], Column, size_w, size_h);
        FFT(Column, Column, size_h);
        IColumnVector(Column, &temp[i], size_w, size_h);

    }



    for(int i=0;i<size_h*size_w;i++)
        Copy_Complex(&temp[i], &dst[i]);
    free(temp);
    free(Column);
    return 0;
}
/*
 */
 ////////////////////////////////////////////////////////////////////
//IFFT µœ÷
////////////////////////////////////////////////////////////////////
void IFFT(Complex * src,Complex * dst,int size_n){
    for(int i=0;i<size_n;i++)
        src[i].imagin=-src[i].imagin;
    FFTComplex_remap(src, size_n);
    int z,k;
    if((z=isBase2(size_n))!=-1)
        k=isBase2(size_n);
    else
        exit(0);
    for(int i=0;i<k;i++){
        z=0;
        for(int j=0;j<size_n;j++){
            if((j/(1<<i))%2==1){
                Complex wn;
                getWN(z, size_n, &wn);
                Multy_Complex(&src[j], &wn,&src[j]);
                z+=1<<(k-i-1);
                Complex temp;
                int neighbour=j-(1<<(i));
                Copy_Complex(&src[neighbour], &temp);
                Add_Complex(&temp, &src[j], &src[neighbour]);
                Sub_Complex(&temp, &src[j], &src[j]);
            }
            else
                z=0;
        }

    }
    for(int i=0;i<size_n;i++){
            dst[i].imagin=(1.0/size_n)*src[i].imagin;
            dst[i].real=(1./size_n)*src[i].real;
        }
}
int IFFT2D(Complex *src,Complex *dst,int size_w,int size_h){

    if(isBase2(size_w)==-1||isBase2(size_h)==-1)
        exit(0);

    Complex *temp=(Complex *)malloc(sizeof(Complex)*size_h*size_w);
    if(temp==NULL)
        return -1;
    Complex *Column=(Complex *)malloc(sizeof(Complex)*size_h);
    if(Column==NULL)
        return -1;

    for(int i=0;i<size_w;i++){
        ColumnVector(&src[i], Column, size_w, size_h);
        IFFT(Column, Column, size_h);
        IColumnVector(Column, &src[i], size_w, size_h);

    }
    for(int i=0;i<size_w*size_h;i++)
        src[i].imagin=-src[i].imagin;
    for(int i=0;i<size_h;i++){
        IFFT(&src[size_w*i], &temp[size_w*i], size_w);

    }


    for(int i=0;i<size_h*size_w;i++)
        Copy_Complex(&temp[i], &dst[i]);
    free(temp);
    free(Column);
    return 0;

}

//

bool ImageProcessing::BMP_XYFFT(void){
	bool successed = false;
	do{
		//double src[PI_NUM*PI_NUM];
		//Complex det[PI_NUM*PI_NUM];
		//Complex s_out_rc[PI_NUM*PI_NUM];
		double *src = new double[taskH*taskW];
		Complex *det = new Complex[taskH*taskW];
		Complex *s_out_rc = new Complex[taskH*taskW];
		for(int h=0;h<3;h++){

			for(int i=0;i<taskH;i++){
				for(int j=0;j<taskW;j++){
					src[i*taskW+j] = 0;
					det[i*taskW+j].real = 0;
					det[i*taskW+j].imagin = 0;
					s_out_rc[i*taskW+j].real = 0;
					s_out_rc[i*taskW+j].imagin = 0;
				}
			}

			for(int i=0;i<taskH;i++){
				for(int j=0;j<taskW;j++){
					src[i*taskW+j]=originimage[h][i][j];
				}
			}
			FFT2D(src,det,taskH,taskW);
			double D;
			double H_d,W_d;
			H_d = (double)(taskH+1.0);
			W_d = (double)(taskW+1.0);
			H_d = H_d/2.0;
			W_d = W_d/2.0;
			for(int i=0;i<taskH;i++){
				for(int j=0;j<taskW;j++){
					double i_d = (double)(i+1);
					double j_d = (double)(j+1);
					D = sqrt(  (( i_d-H_d )*( i_d-H_d ) + (j_d-W_d)*(j_d-H_d))   );
					if(D == 0)
						return - 1;
					//D = sqrt( ((i_d-H_d)*(i_d*H_d)+(j_d-W_d)*(j_d*W_d) ));
					//D = sqrt(( (((double)i-H_d)/2.0)*((double)i-H_d/2.0) + ((double)j-W_d/2.0)*((double)j-W_d/2.0)));
					if(D <= 325){//363
						det[i*taskW+j].real = 0.0;
						det[i*taskW+j].imagin = 0.0;
					}
					// else if(D >= 400){//363
					// 	det[i*taskW+j].real = 0.0;
					// 	det[i*taskW+j].imagin = 0.0;
					// }
				}
				if(i%64==0)
				printf("%lf %lf %lf\n",det[i].real,det[i].imagin,D);
			}
			IFFT2D(det,s_out_rc,taskH,taskW);
			for(int i=0;i<taskH;i++){
				for(int j=0;j<taskW;j++){
					if(s_out_rc[i*taskW+j].real > 255){
						//printf("%lf\n",s_out_rc[i*taskW+j].real);
						s_out_rc[i*taskW+j].real = 255;
					}
					else if(s_out_rc[i*taskW+j].real < 0){
						//printf("%lf\n",s_out_rc[i*taskW+j].real);
						s_out_rc[i*taskW+j].real = 0;
					}
					newimage[h][i][j]=(unsigned char)(s_out_rc[i*taskW+j].real);
				}
			}
		}
		printf("FFT over\n");
        successed = true;
	}while(false);
	return successed;
}




bool DFT2D(double **src,Complex **dst,int size_w,int size_h){
	bool successed = false;
    for(int u=0;u<size_w;u++){
        for(int v=0;v<size_h;v++){
            double real=0.0;
            double imagin=0.0;
            for(int i=0;i<size_w;i++){
                for(int j=0;j<size_h;j++){
                    double I=src[i][j];
                    double x=M_PI*2*((double)i*u/(double)size_w+(double)j*v/(double)size_h);
                    real+=cos(x)*I;
                    imagin+=-sin(x)*I;

                }
            }
            dst[u][v].real=real;
            dst[u][v].imagin=imagin;
        }
    }
	successed = true;
    return successed;
}
bool IDFT2D(Complex **src,Complex **dst,int size_w,int size_h){
	bool successed = false;
    for(int i=0;i<size_w;i++){
        for(int j=0;j<size_h;j++){
            double real=0.0;
            double imagin=0.0;
            for(int u=0;u<size_w;u++){
                for(int v=0;v<size_h;v++){
                    double R=src[u][v].real;
                    double I=src[u][v].imagin;
                    double x=M_PI*2*((double)i*u/(double)size_w+(double)j*v/(double)size_h);
                    real+=R*cos(x)-I*sin(x);
                    imagin+=I*cos(x)+R*sin(x);

                }
            }
            dst[i][j].real=(1./(size_w*size_h))*real;
            dst[i][j].imagin=(1./(size_w*size_h))*imagin;
        }
    }
	successed = true;
    return successed;
}


bool ImageProcessing::BMP_XYDFT(void){
	bool successed = false;
	do{
		double **src = new double*[taskH];
		Complex **det = new Complex*[taskH];
		Complex **s_out_rc = new Complex*[taskH];
		for(int i = 0;i<taskH;i++){
			src[i] = new double[taskW];
			det[i] = new Complex[taskW];
			s_out_rc[i] = new Complex[taskW]; 
		}
		for(int h=0;h<3;h++){
			for(int i=0;i<taskH;i++){
				for(int j=0;j<taskW;j++){
					src[i][j] = 0;
					det[i][j].real = 0;
					det[i][j].imagin = 0;
					s_out_rc[i][j].real = 0;
					s_out_rc[i][j].imagin = 0;
				}
			}

			for(int i=0;i<taskH;i++){
				for(int j=0;j<taskW;j++){
					src[i][j]=originimage[h][i][j];
				}
			}
			DFT2D(src,det,taskH,taskW);
			double D;
			double H_d,W_d;
			H_d = (double)(taskH+1.0);
			W_d = (double)(taskW+1.0);
			H_d = H_d/2.0;
			W_d = W_d/2.0;
			for(int i=0;i<taskH;i++){
				for(int j=0;j<taskW;j++){
					double i_d = (double)(i+1);
					double j_d = (double)(j+1);
					D = sqrt(  (( i_d-H_d )*( i_d-H_d ) + (j_d-W_d)*(j_d-H_d))   );
					if(D == 0)
						return - 1;
					//D = sqrt( ((i_d-H_d)*(i_d*H_d)+(j_d-W_d)*(j_d*W_d) ));
					//D = sqrt(( (((double)i-H_d)/2.0)*((double)i-H_d/2.0) + ((double)j-W_d/2.0)*((double)j-W_d/2.0)));
					if(D <= 35){//363
						det[i][j].real = 0.0;
						det[i][j].imagin = 0.0;
					}
					// else if(D >= 400){//363
					// 	det[i*taskW+j].real = 0.0;
					// 	det[i*taskW+j].imagin = 0.0;
					// }
				}
				if(i%64==0)
				printf("%lf %lf %lf\n",det[i][0].real,det[i][0].imagin,D);
			}
			IDFT2D(det,s_out_rc,taskH,taskW);
			for(int i=0;i<taskH;i++){
				for(int j=0;j<taskW;j++){
					if(s_out_rc[i][j].real > 255){
						//printf("%lf\n",s_out_rc[i*taskW+j].real);
						s_out_rc[i][j].real = 255;
					}
					else if(s_out_rc[i][j].real < 0){
						//printf("%lf\n",s_out_rc[i*taskW+j].real);
						s_out_rc[i][j].real = 0;
					}
					newimage[h][i][j]=(unsigned char)(s_out_rc[i][j].real);
				}
			}
		}
		printf("DFT over\n");
        successed = true;
	}while(false);
	return successed;
}