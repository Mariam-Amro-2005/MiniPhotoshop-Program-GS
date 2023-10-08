// FCAI – OOP Programming – 2023 - Assignment 1 
// Program Name:				EnlargingFilter.cpp
// Last Modification Date:	8/10/2023
// Author1 and ID and Group:	xxxxx xxxxx
// Author2 and ID and Group:	Mariam Amro 20221217
// Author3 and ID and Group:	xxxxx xxxxx
// Teaching Assistant:		xxxxx xxxxx
// Purpose: This program enlarges the selected 
//          quarter of the photo being edited. 
//          The final photo is still 256 x 256.


#include <iostream>
#include <fstream>
#include <cstdio>  
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

void loadImage ();
void saveImage();
void enlargeImage();
void copyImage();

using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];

int main(){
    loadImage();
    copyImage();
    enlargeImage();
    saveImage();
}

void loadImage () {
   char imageFileName[100];
   // Get gray scale image file name
   cout << "Please enter file name of the image to process: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readGSBMP(imageFileName, image);
}


void saveImage() {
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, image);
}

void copyImage(){       //This is to perserve the original data
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image2[i][j] = image[i][j];
        }
        
    }
    
}

void enlargeImage(){
    int quarter, x, y;
    cout << "Which quarter would you like to enlarge - 1, 2, 3, or 4 ? ";
    cin >> quarter;
    x = y = 0;
    if (quarter == 4)       //Assigning a value to x and y to adjust the for 
    {                       //loop according to quarter choosen
        x = y = 128;
    }else if (quarter == 3)
    {
        x = 128;
    }else if (quarter == 2)
    {
        y = 128;
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image[i][j] = image2[int(i/2) + x][int(j/2) + y];   //This assigns each cell/bit in the chosen quarter
                                                                //four bits in the original image; two bits in a row
                                                                // and two bits in adjacent columns.
        }
        
    }

}