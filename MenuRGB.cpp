// FCAI – OOP Programming – 2023 - Assignment 1
// Program Name:				Menu.cpp
// Last Modification Date:	8/10/2023
// Author1 and ID :	    Donia Kareem Mohammed 20221051
// Email          :     dodi382004@gmail.com
// Author2 and ID :	    Mariam Amro Ahmed 20221217
// Email          :     11410120221217@stud.cu.edu.eg,  mariam.seifeldin.2005@gmail.com
// Author3 and ID :	    Menna  Ali Abd Elbaky 20221168
// Email          :     mennnakhatun4@gmail.com
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
void shrink();
void blur();
void  vertical();
void enlargeImage();
void shuffleImage();
void copyImage();
bool isEven(int n);
void BAW();
void flip();

using namespace std;
unsigned char image[SIZE][SIZE][RGB];
unsigned char image2[SIZE][SIZE][RGB];
unsigned char ImageGs1[SIZE][SIZE][RGB];

string path2;
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
    // Get RGB image file name
    cout << "Please enter file name of the image to process: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readRGBBMP(imageFileName, image);
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
            continue;
        }else if (option == "8")
        {
            copyImage();
            enlargeImage();
        }else if (option == "9")
        {
            void shrink ();
        }else if (option == "a")
        {
            continue;
        }else if (option == "b")
        {
           shuffleImage();
        }else if (option == "c")
        {
            void blur();
        }else if (option == "d")
        {
            continue;
        }else if (option == "e")
        {
            continue;
        }else if (option == "f")
        {
            void vertical();
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

    // Get RGB image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeRGBBMP(imageFileName, image);
}

// Author: Mariam Amro
// Last Modification Date:	16/10/2023
// Purpose: This program provides a copy of the image
//          and stores it in another array. The new array
//          is used by other filters such as the enlarging filter.

void copyImage(){       // This is to perserve the original data
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB ; k++)
            {
                image2[i][j][k] = image[i][j][k];
            }
            
        }

    }

}
// Author: Mariam Amro
// Last Modification Date:	16/10/2023
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
            for (int k = 0; k < RGB; k++)
            {
                image[i][j][k] = image2[int(i / 2) + x][int(j / 2) + y][k];   // This assigns each cell/bit in the chosen quarter

                // four bits in the original image; two bits in a row
                // and two bits in adjacent columns.
            }
            
        }

    }

}

// Author: Mariam Amro Ahmed
// Last Modification Date:	16/10/2023
// Inverts the bit values of the image to get the image inverse.

void invertImage() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {

            for (int k = 0; k < RGB; k++)
            {
                image[i][j][k] = 255 - image[i][j][k]; // Subtracting original value from 255 to get inverse colour
            }
        }
    }
}

// Author: Mariam Amro Ahmed
// Last Modification Date:	16/10/2023
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
    for (int l = 0; l < (degree / 90); l++)
    {
        for(int i = 0; i < SIZE; ++i){   // This mirrors the array from the middle to change the direction of the principal diagonal to become the off diagonal
            for(int j = 0; j < (SIZE / 2); ++j){  //Also make it easier to swap cell contents
                for (int k = 0; k < RGB; k++)
                {
                    temp = image[i][j][k];
                    image[i][j] [k]= image[i][SIZE - j - 1][k];
                    image[i][SIZE - j - 1][k] = temp;
                }
            }
        }
        for(int i = 0; i < SIZE ; ++i){   // This swaps the cell contents into their final place
            for(int j = 0; j < (SIZE - i - 1); ++j){
                for (int k = 0; k < RGB; k++)
                {
                    temp = image[i][j][k];
                    image[i][j][k] = image[SIZE - j - 1][SIZE - i - 1][k];
                    image[SIZE - j - 1][SIZE - i - 1][k] = temp;
                }
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

/*void BAW(){

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {

            if (image[i][j] > 115)
                image[i][j] = 255;
            else
                image[i][j] = 0;
        }
    }
}
*/




// Author: Donia Kareem Mohammed
// Last Modification Date:	4/10/2023
// Purpose:
// In this filter, we flip the image according to the user’s choice...
// If he requests to flip the image vertically or horizontally
// we will fulfill his request through these function.

/*void flip(){
    cout << "Do you want to flip the image (h)orizontally or (v)ertically? ";
    string s2;
    cin >> s2;
    if (s2[0] == 'h')
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
        for (int x = 0; x < SIZE / 2; x++) //width
        {
            for (int y = 0; y < SIZE; y++)
            {
                int temp = image[x][y];
                image[x][y] = image[SIZE-x][y];
                image[SIZE-x][y] = temp;
            }
        }
    }

}*/



// Author: Mariam Amro Ahmed
// Last Modification Date: 16/10/2023
// Purpose:
// This filter shuffles the order in which the quarters 
// of the image are ordered according to the user's preference 
// with the use of a copy of the image and increments 

void shuffleImage(){

    cout << "Please enter the order of the shuffle: ";
    int order[4];
    string input, space, ignore;
    space = " ";
    getline(cin, ignore);   // So it does not take the name of the file as input
    getline(cin, input);
    int j = 0;
    for (int i = 0; i < input.length(); i++)    // Takes only the numbers form the input in 
    {                                           // integer form an stores it in the array order
        
        if (input[i] != space[0])
        {
            string temp ="";
            temp += input[i];
            order[j] = stoi(temp);
            j++;
        }
        
    }
    copyImage();    // Saves a copy to retrieve data from
    int x, y;       // While the original is modified
    x = y = 0;
    for (int i = 0; i < SIZE; i++)      // x and y are the increments for i and j respectively.
    {                                   // x and y are defined differntly according to the quarter
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB; k++)
            {
                if (i < 128)
                {
                    if (j < 128)
                    {
                        //Use order[0] for quarter 1    // Here x is either 0 if quarters 1 or 2 are 
                        x = int(order[0] / 3) * 128;    // chosen or 128 if quarters 3 or 4 are chosen 
                        y = isEven(order[0]) * 128;     // Similarly y is 0 (quarters 1 & 3) or 128 (quarters 2 & 4)
                    }else{
                        //Use order[1] for quarter 2        // Here x is either 0 if quarters 1 or 2 are 
                        x = int(order[1] / 3) * 128;        // chosen or 128 if quarters 3 or 4 are chosen 
                        y  = ceil(order[1] % 2) * (-128);   // Similarly y is 0 (quarters 2 & 4) or -128 (quarters 1 & 3)
                    }
                    
                }else{
                    if (j < 128)
                    {
                        //Use order[2] for quarter 3        // Here x is either 0 if quarters 3 or 4 are 
                        x = (int(order[2] / 3) - 1) * 128;  // chosen or -128 if quarters 1 or 2 are chosen
                        y = isEven(order[2]) * 128;         // Similarly y is 0 (quarters 1 & 3) or 128 (quarters 2 & 4)
                        
                    }else{
                        //Use order[3] for quarter 4        // Here x is either 0 if quarters 3 or 4 are
                        x = (int(order[3] / 3) - 1) * 128;  // chosen or -128 if quarters 1 or 2 are chosen
                        y  = ceil(order[3] % 2) * (-128);   // Similarly y is 0 (quarters 2 & 4) or -128 (quarters 1 & 3)
                    }
                    
                }
                image[i][j][k] =  image2[(i + x)][(j + y)][k];
            
            }
        }
        
    }
    
}

bool isEven(int n) {    // Function to check if the number is even or not
    return (n % 2 == 0); 
    }
// Author: Menna Ali Abd Elbaky
// Last Modification Date:	9/10/2023
// Purpose:
// This filter lightens or darkens the image
// by changing the values of each pixel.
void Dark_Light(){
    std :: string op;
    std :: cout<<"option(D or L ): ";
    std :: cin>>op;
    if (op == "D") {
        for (int i=0 ; i<SIZE ; ++i){
            for (int j=0 ; j<SIZE ; ++j){
                for (int k=0 ; k<RGB ; ++k){
                    int sum=image[i][j][k];
                    int t=(255-sum)/2;
                    sum-=t;
                    if (sum <= 0)
                        image[i][j][k]=0;
                    else
                        image[i][j][k]=sum;
                }
            }
        }
    }
    else if (op == "L"){
        for (int i=0 ; i<SIZE ; ++i){
            for (int j=0 ; j<SIZE ; ++j){
                for (int k=0 ; k<RGB ; ++k){
                    int sum=image[i][j][k];
                    int t=(255-sum)/2;
                    sum+=t;
                    if (sum >= 255)
                        image[i][j][k]=255;
                    else
                        image[i][j][k]=sum;
                }
            }
        }
    }
}
// Author: Menna Ali Abd Elbaky
// Last Modification Date:	9/10/2023
// Purpose: Overlay two images together by adding the bit
//          values at [i][j] for the two images and
//          dividing it by half to create the new value
//          for image[i][j].


void MergePhotos(){
    std ::string  s;
    std :: cout<<"Enter another photo: ";
    std ::cin>>s;
    path2+=s;
    char cwd2 [PATH_MAX];
    readRGBBMP (strcat(getcwd(cwd2 , sizeof (cwd2)) , path2.c_str()) , image2 );
    for (int i=0 ; i<SIZE ; ++i){
        for (int j=0 ; j<SIZE ; ++j){
            for (int k=0 ; k<RGB ; ++k){
                int fr=image[i][j][k],sc=image2[i][j][k];
                int avr=(fr+sc)/2;
                image[i][j][k]=avr;
            }
        }
    }
}
void Shrink(){
    for (int i=0 ; i<SIZE ; ++i)
        for (int j=0 ; j<SIZE ; ++j){
            for (int k=0 ; k<RGB ; ++k)
                image2[i][j][k]=image[i][j][k];
        }
    for (int i=0 ; i<SIZE ; ++i)
        for (int j=0 ; j<SIZE ; ++j){
            for (int k=0 ; k<RGB ; ++k)
                image[i][j][k]=255;
        }
    std :: cout<<"Enter the ratio: ";
    int n;
    std :: cin>>n;
    if (n == 2){
        int row=0 , clm=0;
        for (int i=0 ; i<SIZE ; i+=2){
            clm=0;
            for (int j=0 ; j<SIZE ; j+=2){
                for (int k=0 ; k<RGB ; ++k)
                    image[row][clm][k]= image2[i][j][k];
                clm++;
            }
            row++;
        }
    }
    else if (n == 3){
        int m,y=0;
        for (int i=0 ; i<SIZE ; i+=3){
            m=0;
            for (int j=0 ; j<SIZE ; j+=3){
                for (int k=0 ; k<RGB ; ++k)
                    image[y][m][k]= image2[i][j][k];
                m++;
            }
            y++;
        }
    }
    else if (n == 4){
        int y=0,m;
        for (int i=0 ; i<SIZE ; i+=4){
            m=0;
            for (int j=0 ; j<SIZE ; j+=4){
                for (int k=0 ; k<RGB ; ++k)
                    image[y][m][k]= image2[i][j][k];
                m++;
            }
            y++;
        }
    }

}
void Blur(){
    for (int i=2 ; i<SIZE-2 ; i++){
        for (int j=2 ; j<SIZE-2 ; j++){
            for (int k=0 ; k<RGB ; ++k){
                int f=image[i][j][k];
                int sc=image[i][j+1][k],d=image[i+1][j][k], y=image[i][j-1][k],w=image[i-1][j][k];//4 d
                int dw=image[i+1][j+1][k], r=image[i+1][j-1][k],t=image[i-1][j-1][k],p=image[i-1][j+1][k];//dignal
                long long nw=(f+sc+d+y+w+dw+r+t+p)/9;
                image[i][j][k]=nw;
                image[i][j+1][k]=nw,image[i+1][j][k]=nw ,image[i-1][j][k]=nw,image[i][j-1][k]=nw;//1
                image[i-1][j+1][k]=nw,image[i+1][j+1][k]=nw ,image[i+1][j-1][k]=nw,image[i-1][j-1][k]=nw;//2
            }

        }
    }
}
void vertical(){
    for (int i=0 ; i<SIZE ; ++i)
        for (int j=0 ; j<SIZE ; ++j){
            for (int k=0 ; k<RGB ; ++k)
                image2[i][j][k]=image[i][j][k];
        }
    for (int i=0 ; i<SIZE ; ++i)
        for (int j=0 ; j<SIZE ; ++j){
            for (int k=0 ; k <RGB ; ++k)
                image[i][j][k]=255;
        }
    std::cout<<"Enter the degree : ";
    double  deg;
    std::cin>>deg;
    deg =(deg*22)/(7*180);
    double x=256/(1+tan(deg));
    double len=tan(deg)*SIZE , mv=len/256,t;

    unsigned char tm_imag[SIZE+(int)len][SIZE][RGB];
    for (int i=0 ; i<SIZE+(int)len ; ++i)
        for (int j=0 ; j<SIZE ; ++j){
            for (int k=0 ; k<RGB ; ++k)
                tm_imag[i][j][k]=255;
        }

    for (int  i=0 ; i<SIZE  ; i++){
        t=len;
        for (int  j=0 ; j<SIZE ; j++){
            for (int k=0 ; k<RGB ; ++k )
                tm_imag[i+(int)t][j][k]=image2[i][j][k];
            t-=mv;
        }
        len-=mv;
    }
    int cnt=255/(int)x;
    for (int i=0 ; i<SIZE ; i+=cnt)
        for (int j=0 ; j<SIZE ; j++){
            for (int k=0 ; k <RGB ; ++k)
                tm_imag[i][j][k]=tm_imag[i][j][k];
        }

    for (int i=0 ; i<SIZE   ; ++i){
        for (int j=0 ; j<SIZE ; j++){
            for (int k=0 ; k<RGB ; ++k )
                image[i][j][k]=tm_imag[i][j][k];

        }
    }


}

