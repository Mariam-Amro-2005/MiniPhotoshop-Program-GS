// FCAI – OOP Programming – 2023 - Assignment 1 
// Program Name:				EnlargingFilter.cpp
// Last Modification Date:	8/10/2023
// Author1 and ID and Group:	xxxxx xxxxx
// Author2 and ID and Group:	Mariam Amro 20221217
// Author3 and ID and Group:	xxxxx xxxxx
// Teaching Assistant:		xxxxx xxxxx
// Purpose: This is the main program that edits photos

#include <iostream>
#include <fstream>
#include <cstdio>  
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

void loadImage ();
void saveImage();

using namespace std;
unsigned char image[SIZE][SIZE];

int main(){
    int pic[8][8];
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            pic[i][j] = 0;
        }
        
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << pic[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n\n";

    for (int i = 4; i < 8; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            pic[i][j] = 1;
        }
        
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << pic[i][j] << " ";
        }
        cout << "\n";
    }
    
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