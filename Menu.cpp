// FCAI – OOP Programming – 2023 - Assignment 1 
// Program Name:				RotatingFilter.cpp
// Last Modification Date:	6/10/2023
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
string Options();
void saveImage();
void invertImage();
void rotateImage();
void enlargeImage();
void copyImage();
void BAW();
void flip ();

using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char imaGS[SIZE][SIZE];

int main(){
    cout << "Welcome User! \n";
    loadImage();
    string operation, exit;
    operation = "1";
    exit = "0";
    while(operation != exit){
        operation = Options();
        cout << operation << "\n";
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

string Options(){
    string option;
    string line;
    fstream menu("Menu.txt");  // Menu.txt contains the options of filters to choose from
    while(getline(menu, line)){   //This reads the menu file and displays it
        cout << line << "\n";

    }
    menu.close();
    bool invalid = 0;
    cin >> option;
    do
    {
        if (option == "1")
        {
            BAW();
        }else if (option == "2")
        {
            invertImage();
        }else if (option == "3")
        {
            /* code */
        }else if (option == "4")
        {
            flip();
        }else if (option == "5")
        {
            rotateImage();
        }else if (option == "6")
        {
            /* code */
        }else if (option == "7")
        {
            /* code */
        }else if (option == "8")
        {
            /* code */
        }else if (option == "9")
        {
            /* code */
        }else if (option == "a")
        {
            /* code */
        }else if (option == "b")
        {
            /* code */
        }else if (option == "c")
        {
            /* code */
        }else if (option == "d")
        {
            /* code */
        }else if (option == "e")
        {
            /* code */
        }else if (option == "f")
        {
            /* code */
        }else if (option == "s")
        {
            saveImage();
        }else if (option == "0")
        {
            /* code */
        }else{
            invalid = 1;
            cout << "Sorry! Invalid option. Please choose a correct option.\n";
            cin >> option;
        }
     
    } while (invalid);
    
    return option;

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
void BAW() {

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {

            if (imaGS[i][j] > 115)
                imaGS[i][j] = 255;
            else
                imaGS[i][j] = 0;
        }
    }
}
void flip (){
    cout << "what do you want flip the image horizontally or vertically ? ";
    string s2;
    cin >> s2;
    if (s2[0]=='h')
    {
        for (int x = 0; x < SIZE; x++)
        {
            for (int y = 0; y < SIZE / 2; y++) {
                int temp = imaGS[x][y];
                imaGS[x][y] = imaGS[x][SIZE - y];
                imaGS[x][SIZE - y] = temp;
            }
        }
    }
    else if(s2[0]=='v')
    {
        for (int x = 0; x < SIZE/2; x++) //width
        {
            for (int y = 0; y < SIZE; y++)
            {
                int temp = imaGS[x][y];
                imaGS[x][y] = imaGS[SIZE-x][y];
                imaGS[SIZE-x][y] = temp;
            }
        }
    }

}