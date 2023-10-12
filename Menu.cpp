// FCAI – OOP Programming – 2023 - Assignment 1
// Program Name:				Menu.cpp
// Last Modification Date:	8/10/2023
// Author1 and ID :	    Donia Kareem Mohammed 20221051
// Author2 and ID :	    Mariam Amro Ahmed 20221217
// Author3 and ID :	    Menna  ali abd elbaky 20221168
// email          :     mennnakhatun4@gmail.com
// Purpose: This is the main program that edits photos
//          and contains all the filters available.

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
void Shrink ();
void  Blur ();
void BAW();
void flip();

using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char ImageGs2[SIZE][SIZE];
//unsigned char imaGS[SIZE][SIZE];
//unsigned char ImageGs2[SIZE][SIZE];
unsigned char ImageGs1[SIZE][SIZE];
//unsigned char ImageGs[SIZE][SIZE];

std :: string name,ord,path="\\photos\\",path2="\\photos\\",path3="\\photos\\" ;
void loadImage () {
    char imageFileName[100];
    // Get gray scale image file name
    cout << "Please enter file name of the image to process: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, image);
}

// Author: Mariam Amro
// Last Modification Date:	8/10/2023
// Purpose: This program enlarges the selected
//          quarter of the photo being edited.
//          The final photo is still 256 x 256.

class op {
public:
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
            image[i][j] = image2[int(i / 2) + x][int(j / 2) + y];   // This assigns each cell/bit in the chosen quarter
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
        if (direction[0] == compare[0]){
            degree = 360 - degree;
        }
        for (int k = 0; k < (degree / 90); k++){
            for(int i = 0; i < SIZE; ++i){   // This mirrors the array from the middle to change the direction of the principal diagonal to become the off diagonal
                for(int j = 0; j < (SIZE / 2); ++j){  //Also make it easier to swap cell contents
                     temp = image[i][j];
                     image[i][j] = image[i][SIZE - j - 1];
                    image[i][SIZE - j - 1] = temp;
                }
            }
            for(int i = 0; i < SIZE ; ++i){   // This swaps the cell contents into their final place
                 for(int j = 0; j < (SIZE - i - 1); ++j){
                     temp = image[i][j];
                     image[i][j] = image[SIZE - j - 1][SIZE - i - 1];
                     image[SIZE - j - 1][SIZE - i - 1] = temp;
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
    // Author: Menna ali abd elbaky
    // Last Modification Date:	9/10/2023
    // Purpose: to make image  extra dark or light

    void Dark_Light(){
        std :: string k;
        std :: cout << "Would you like to (D)arken or (L)ighten your image? ";
        std :: cin >> k; // input option
        if (k == "D" || k == "d" || k == "Darken" || k == "darken") { // if  option is dark
            for (int i = 0 ; i < SIZE; ++i){
                for (int j = 0 ; j < SIZE; ++j){
                    int num = image[i][j]; // take degree of pixl
                    int t=(255 - num) / 2; // find average the inverse
                    num -= t; // pixl - = average
                    if (num <= 0)  // if new degree became out of range make it = min degree
                        image[i][j] = 0;
                    else{
                        image[i][j] = (num); // else make it new degree
                         }
                }
            }
        }
        else if (k == "L" || k == "l" || k == "Lighten" || k == "lighten"){
            for (int i = 0 ; i < SIZE; ++i){
                for (int j = 0 ; j < SIZE; ++j){
                    int num = image[i][j]; // take degree of pixl
                    int t = (255-  num) / 2;// find average the inverse
                    num += t; // pixl + = average
                    if (num >= 255) // if new degree became out of range make it = min degree
                        image[i][j] = 255;
                    else{
                        image[i][j] = num; // else make it new degree
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
        if (s2[0] == 'h'){
            for (int x = 0; x < SIZE; x++){
                for (int y = 0; y < SIZE / 2; y++) {
                    int temp = image[x][y];
                    image[x][y] = image[x][SIZE - y];
                    image[x][SIZE - y] = temp;
                }
            }
        }
        else if (s2[0]=='v'){
            for (int x = 0; x < SIZE / 2; x++) {//width
             for (int y = 0; y < SIZE; y++){
                  int temp = image[x][y];
                  image[x][y] = image[SIZE-x][y];
                  image[SIZE-x][y] = temp;
                }
             }
        }

    }

    // Author: Menna ali abd elbaky
    // Last Modification Date:	9/10/2023
    // Purpose: Overlay two images together by adding the bit
    //          values at [i][j] for the two images and
    //          dividing it by half to create the new value
    //          for image[i][j].

    void MergePhotos(){
        //std ::string  s;
        char s[100];
        std :: cout << "Enter another photo: ";
        std ::cin >> s;
        strcat (s, ".bmp");
        readGSBMP(s, ImageGs1);

        for (int i=0 ; i < SIZE; ++i){
            for (int j = 0 ; j < SIZE; ++j){
                int t = image[i][j]; // take degree of pixl of first image
                int n = ImageGs1[i][j]; // take degree of pixl of image2
                int y = (t + n) / 2; // find average of them
                image[i][j] = y; // put the average in pixl in first image
            }
        }
    }
    // Author: Menna ali abd elbaky
    // Last Modification Date:	9/10/2023
    // Purpose: minimize the size of image
    void Shrink (){
        for (int i=0 ; i<SIZE ; ++i)
            for (int j=0 ; j<SIZE ; ++j){ // make image2 == image1
                ImageGs2[i][j]=image[i][j];
            }
        for (int i=0 ; i<SIZE ; ++i)
            for (int j=0 ; j<SIZE ; ++j){ // make image1 while image
                image[i][j]=255;
            }
        std :: cout<<"Enter the ratio: ";
        int n;
        std :: cin>>n; // take the ratio of new image from user
        if (n == 2){ // if ratio == 1/2
            int row=0 , clm;
            for (int i=0 ; i<SIZE ; i+=2){
                clm=0;
                for (int j=0 ; j<SIZE ; j+=2){
                    image[row][clm]= ImageGs2[i][j]; // save pixel and skip pixel
                    clm++;
                }
                row++;
            }
        }
        else if (n == 3){ // if ratio == 1/3
            int m,y=0;
            for (int i=0 ; i<SIZE ; i+=3){
                m=0;
                for (int j=0 ; j<SIZE ; j+=3){
                    image[y][m]=ImageGs2[i][j]; // save pixel and skip  three pixels
                    m++;
                }
                y++;
            }
        }
        else if (n == 4){ // if ratio == 1/4
            int y=0,m;
            for (int i=0 ; i<SIZE ; i+=4){
                m=0;
                for (int j=0 ; j<SIZE ; j+=4){
                    image[y][m]=ImageGs2[i][j]; // save pixel and skip 4 pixels
                    m++;
                }
                y++;
            }
        }

    }
    // Author: Menna ali abd elbaky
    // Last Modification Date:	9/10/2023
    // Purpose: to make photo more  blural
    void  Blur (){
        for (int i=2 ; i<SIZE-2 ; i++){
            for (int j=2 ; j<SIZE-2 ; j++){ //take the degree of all pixels around the pixel that have been chosen
                int f=image[i][j];          // and make all these pixels == the average of them
                int sc=image[i][j+1],d=image[i+1][j], y=image[i][j-1],w=image[i-1][j];//4 d
                int dw=image[i+1][j+1], r=image[i+1][j-1],t=image[i-1][j-1],p=image[i-1][j+1];//diagonal
                long long nw=(f+sc+d+y+w+dw+r+t+p)/9;
                image[i][j]=nw;
                image[i][j+1]=nw,image[i+1][j]=nw ,image[i-1][j]=nw,image[i][j-1]=nw;//1
                image[i-1][j+1]=nw,image[i+1][j+1]=nw ,image[i+1][j-1]=nw,image[i-1][j-1]=nw;//2
            }
        }
    }
};
int main(){
    cout << "Welcome User! \n";
    loadImage();
    string operation, exit;
    operation = "1";
    exit = "0";
    while(operation != exit) {
        string option;
        string line;
        fstream menu("Menu.txt");  // Menu.txt contains the options of filters to choose from
        while (getline(menu, line)) {   //This reads the menu file and displays it
            cout << line << "\n";

        }
        menu.close();
        bool isInvalid = 0;
        cin >> option;
        op val;
        if (option == "1") {
            val.BAW();
        } else if (option == "2") {
            val.invertImage();
        } else if (option == "3") {
            val.MergePhotos();
        } else if (option == "4") {
            val.flip();
        } else if (option == "5") {
            val.Dark_Light();
        } else if (option == "6") {
            val.rotateImage();
        } else if (option == "7") {
            continue;
        } else if (option == "8") {
            val.copyImage();
            val.enlargeImage();
        } else if (option == "9") {
            val.Shrink();
        } else if (option == "a") {
            continue;
        } else if (option == "b") {
            continue;
        } else if (option == "c") {
            val.Blur();
        } else if (option == "d") {
            continue;
        } else if (option == "e") {
            continue;
        } else if (option == "f") {
            continue;
        } else if (option == "s") {
            val.saveImage();
        } else if (option == "l") {
            val.loadImage();
        }else{      // This condition ensures no invalid option is choosen
            isInvalid = 1;
            cout << "Sorry! Invalid option. Please choose a correct option.\n";
            cin >> option;
        }

    }

}