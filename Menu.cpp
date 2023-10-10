// FCAI – OOP Programming – 2023 - Assignment 1 
// Program Name:				Menu.cpp
// Last Modification Date:	8/10/2023
// Author1 and ID and Group:	Donia Kareem Mohammed 20221051
// Author2 and ID and Group:	Mariam Amro Ahmed 20221217
// Author3 and ID and Group:	Menna 2022xx
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
void MergePhotos();
void Dark_Light();
void enlargeImage();
void copyImage();
void BAW();
void flip();

using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char imaGS[SIZE][SIZE];
unsigned char ImageGs2[SIZE][SIZE];
unsigned char ImageGs1[SIZE][SIZE];
unsigned char ImageGs[SIZE][SIZE];

std :: string name,ord,path="\\photos\\",path2="\\photos\\",path3="\\photos\\" ;

int main(){
    cout << "Welcome User! \n";
    loadImage();
    string operation, exit;
    operation = "1";
    exit = "0";
    while(operation != exit){
        operation = Options();
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

// Authors: Mariam Amro, Donia Kareem, Menna
// Last Modification Date:	6/10/2023
// Purpose: This function displays the filters that can be choosen  
//          and calls the functions. It allows the user to load, edit
//          and save more than one image and then exit the program.

string Options(){
    string option;
    string line;
    fstream menu("Menu.txt");  // Menu.txt contains the options of filters to choose from
    while(getline(menu, line)){   //This reads the menu file and displays it
        cout << line << "\n";

    }
    menu.close();
    bool isInvalid = 0;
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
            MergePhotos();
        }else if (option == "4")
        {
            flip();
        }else if (option == "5")
        {
            Dark_Light();
        }else if (option == "6")
        {
            rotateImage();
        }else if (option == "7")
        {
            /* code */
        }else if (option == "8")
        {
            copyImage();
            enlargeImage();
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
        }else if (option == "l")
        {
            loadImage();
        }else if (option == "0")
        {
            /* code */
        }else{      // This condition ensures no invalid option is choosen
            isInvalid = 1;
            cout << "Sorry! Invalid option. Please choose a correct option.\n";
            cin >> option;
        }
     
    } while (isInvalid);
    
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

// Author: Mariam Amro
// Last Modification Date:	8/10/2023
// Purpose: This program provides a copy of the image
//          and stores it in another array. The new array
//          is used by other filters such as the enlarging filter.

void copyImage(){       // This is to perserve the original data
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image2[i][j] = image[i][j];
        }
        
    }
    
}
// Author: Mariam Amro
// Last Modification Date:	8/10/2023
// Purpose: This program enlarges the selected 
//          quarter of the photo being edited. 
//          The final photo is still 256 x 256. 

void enlargeImage(){
    int quarter, x, y;
    cout << "Which quarter would you like to enlarge - 1, 2, 3, or 4 ? ";
    cin >> quarter;
    x = y = 0;
    if (quarter == 4)       // Assigning a value to x and y to adjust the for 
    {                       // loop according to quarter chosen
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
            image[i][j] = image2[int(i/2) + x][int(j/2) + y];   // This assigns each cell/bit in the chosen quarter
                                                                // four bits in the original image; two bits in a row
                                                                // and two bits in adjacent columns.
        }
        
    }

}

// Author: Mariam Amro Ahmed
// Last Modification Date:	4/10/2023
// Inverts the bit values of the image to get the image inverse.

void invertImage() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {

            image[i][j] = 255 - image[i][j]; // Subtracting original value from 255 to get inverse colour
        }

    }
}
// Author: Mariam Amro Ahmed
// Last Modification Date:	6/10/2023
// Purpose: This rotates grayscaled bmp images leftl or right
//          according to the degree choosen by the user.
//          The degrees that can be chosen are: 90, 180, 270 and 360 degrees.

void rotateImage() { 
    int temp, degree;
    string direction, compare;
    compare = "anticlockwise";
    cout << "Please choose which degree of rotation: ";
    cin >> degree;
    cout << "Please choose the direction of rotation - (c)lockwise or (a)nticlockwise: "; // anticlockwise in x degrees is the same as clockwise (360 - x) degrees
    cin >> direction;
    if (direction[0] == compare[0])
    {
        degree = 360 - degree;
    }
    for (int k = 0; k < (degree/90); k++)
    {
        for(int i = 0; i < SIZE ; ++i){   // This mirrors the array from the middle to change the direction of the principal diagonal to become the off diagonal
            for(int j = 0; j <SIZE/2; ++j){  //Also make it easier to swap cell contents
                temp = image[i][j];
                image[i][j] = image[i][SIZE-j-1];
                image[i][SIZE-j-1] = temp;
            }
        }
        for(int i = 0; i < SIZE ; ++i){   // This swaps the cell contents into their final place
            for(int j = 0; j < SIZE-i-1; ++j){
                temp = image[i][j];
                image[i][j] = image[SIZE-j-1][SIZE-i-1];
                image[SIZE-j-1][SIZE-i-1] = temp;
            }
        }
    }

}
// Author: Donia Kareem Mohammed
// Last Modification Date:	4/10/2023
// Purpose:
// In this filter, we convert the image to black and white by:
// If the pixel that I am standing on is larger than 115
// I will turn it to white, if less, I will turn it to black.

void BAW(){

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {

            if (image[i][j] > 115)
                image[i][j] = 255;
            else
                image[i][j] = 0;
        }
    }
}

// Author: Menna
// Last Modification Date:	x/10/2023
// Purpose:

void Dark_Light(){
    std :: string k;
    std :: cout<<"option(D or L ): ";
    std :: cin>>k;
    if (k == "D") {
        for (int i=0 ; i<SIZE ; ++i){
            for (int j=0 ; j<SIZE ; ++j){
                int num=ImageGs[i][j];
                int t=(255-num)/2;
                num-=t;
                if (num <= 0)
                    ImageGs[i][j]=0;
                else{
                    ImageGs[i][j]=(num);}

            }
        }
    }
    else if (k == "L"){
        for (int i=0 ; i<SIZE ; ++i){
            for (int j=0 ; j<SIZE ; ++j){
                int num=ImageGs[i][j];
                int t=(255-num)/2;
                num +=t;
                if (num >= 255)
                    ImageGs[i][j]=255;
                else{
                    ImageGs[i][j]=num;
                }
            }
        }
    }
}

// Author: Donia Kareem Mohammed
// Last Modification Date:	4/10/2023
// Purpose:
// In this filter, we flip the image according to the user’s choice...
// If he requests to flip the image vertically or horizontally
// we will fulfill his request through these function.

void flip(){
    cout << "Do you want to flip the image (h)orizontally or (v)ertically? ";
    string s2;
    cin >> s2;
    if (s2[0]=='h')
    {
        for (int x = 0; x < SIZE; x++)
        {
            for (int y = 0; y < SIZE / 2; y++) {
                int temp = image[x][y];
                image[x][y] = image[x][SIZE - y];
                image[x][SIZE - y] = temp;
            }
        }
    }
    else if (s2[0]=='v')
    {
        for (int x = 0; x < SIZE/2; x++) //width
        {
            for (int y = 0; y < SIZE; y++)
            {
                int temp = image[x][y];
                image[x][y] = image[SIZE-x][y];
                image[SIZE-x][y] = temp;
            }
        }
    }

}

// Author: Menna
// Last Modification Date:	x/10/2023
// Purpose:

void MergePhotos(){
    std ::string  s;
    //char s[100];
    std :: cout<<"Enter another photo: ";
    std ::cin>>s;
    path2+=s;
    char cwd2 [PATH_MAX];
    readGSBMP(strcat(getcwd(cwd2 , sizeof (cwd2)) , path2.c_str()) , ImageGs1 );
    //readGSBMP(s, ImageGs1);
    for (int i=0 ; i<SIZE ; ++i){
        for (int j=0 ; j<SIZE ; ++j){
            int t=image[i][j],n=ImageGs1[i][j];
            int y = (t+n)/2;
            image[i][j]=y;
        }
    }
}

