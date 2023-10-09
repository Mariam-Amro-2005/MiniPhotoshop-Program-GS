/*#include <iostream>
#include "bmplib.cpp"
#include <cstdio> 
#include <algorithm>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int num;
    cout << "2\n\n";
    //freopen(“fruit.bmp”, “r”, stdin);

    int readGSBMP(const char* filename, unsigned char image[][SIZE]);
    //int writeGSBMP(const char* filename, unsigned char outputImage[][SIZE]);
    return 0;
}*/

// Program: demo2.cpp
// Purpose: Demonstrate use of bmplip for handling
//          bmp colored and grayscale images
//          Program load a gray image and store in another file
// Author:  Mohammad El-Ramly
// Date:    30 March 2018
// Version: 1.0

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];

void loadImage ();
void saveImage ();
void doSomethingForImage ();

int main()
{
  loadImage();
  doSomethingForImage();
  saveImage();
  return 0;
}

//_________________________________________
void loadImage () {
   char imageFileName[100];

   // Get gray scale image file name
   cout << "Enter the source image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readGSBMP(imageFileName, image);
}

//_________________________________________
void saveImage () {
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, image);
}

//_________________________________________
void doSomethingForImage() {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
        //int temp = image[i][j];
        //cout << temp << " || ";
        image[i][j] = 255 - image[i][j];

/* Example code to convert to BW the image
   A better version should NOt use 127 but the
   average of the pixels*/

        /*if (image[i][j] > 127)
            image[i][j] = 255;
        else
            image[i][j] = 0;*/

// do something with the image
    }
    //cout << "\n\n";
  }
}
