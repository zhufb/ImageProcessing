//
//  main.cpp
//  ImageProcessing
//
//  Created by 李鑫 on 2018/10/10.
//

#include "main.hpp"

int main(int argc,char **argv){
    if(argc<3){
        printf("The processing need a filename");
        return 1;
    }
    const char* inputFileName = argv[1];
    const char* outputFileName = argv[2];
    const char operation = argv[3][1];
    ImageProcessing image;
    if(!image.operation(inputFileName,outputFileName,operation)){
        return 1;
    }
    return 0;
}
