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
            /* code */
        }else if (option == "2")
        {
            /* code */
        }else if (option == "3")
        {
            /* code */
        }else if (option == "4")
        {
            /* code */
        }else if (option == "5")
        {
            /* code */
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
            /* code */
        }else if (option == "0")
        {
            /* code */
        }else{
            invalid = 1;
            cout << "Sorry! Invalid option. Please choose a correct option.\n";
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