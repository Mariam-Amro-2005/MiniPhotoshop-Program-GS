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
char Options();
void saveImage();
void invertImage();
void rotateImage();

using namespace std;
unsigned char image[SIZE][SIZE];

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

char Options(){
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
        switch (option[0])    //To allow users to choose options and prevent entering of invalid options
    {
        case "1":
            //
            break;
        case "2":
            invertImage();
            break;
        case "3":
            //
            break;
        case "4":
            //
            break;
        case "5":
            rotateImage();
            break;
        case "6":
            //
            break;
        case "7":
            //
            break;
        case "8":
            //
            break;
        case "9":
            //
            break;
        case "a":
            //
            break;
        case "b":
            //
            break;
        case "c":
            //
            break;
        case "d":
            //
            break;
        case "e":
            //
            break;
        case "f":
            //
            break;
        case "s":
            saveImage();
            break;
        case "0":
            break;
    
    default:
        invalid = 1;
        cout << "Sorry! Invalid option. Please choose a correct option.\n"
        break;
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