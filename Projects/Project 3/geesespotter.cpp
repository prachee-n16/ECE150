#include <iostream>
#include "geesespotter_lib.h"

//Function declarations
// 1. skeleton definitions - include return statements

char *createBoard(std::size_t xdim, std::size_t ydim)
{

    //Make a char array, dynamically allocated and is a pointer
    //make every element as 0
    // size = xdim * ydim
    //return character array

    std::size_t size{xdim * ydim};

    char *board{new char[size]{0}}; // {} here are equivalent to char *board = new  char[size];
    return board;
}

void computeNeighbors(char *board, std::size_t xdim, std::size_t ydim)
{
    //go through the board to find which element is 9

    for (int i{0}; i < (xdim * ydim); i++)
    {

        //go through board to find if there's any 9s
        if (board[i] == 9)
        {

            if ((i == (xdim - 1)))
            { //upper right corner
                if (board[i - 1] != 9)
                { //for element - left
                    board[i - 1] += 1;
                }
                if (board[i + (xdim - 1)] != 9)
                { //diagonal
                    board[i + (xdim - 1)] += 1;
                }
                if (board[i + xdim] != 9)
                { // bottom
                    board[i + xdim] += 1;
                }
            }
            else if ((i == ((xdim * ydim) - 1)))
            { //lower right corner
                if (board[i - 1] != 9)
                { //element to left
                    board[i - 1] += 1;
                }
                if (board[i - xdim] != 9)
                { //above
                    board[i - xdim] += 1;
                }
                if (board[i - (xdim + 1)] != 9)
                { //diagonal
                    board[i - (xdim + 1)] += 1;
                }
            }
            else if ((i == 0))
            { //upper left corner             *** changed i%xdim (same in reveal)
                if (board[i + 1] != 9)
                { //element to right
                    board[i + 1] += 1;
                }
                if (board[i + xdim + 1] != 9)
                { //diagonal
                    board[i + xdim + 1] += 1;
                }
                if (board[i + xdim] != 9)
                { //below
                    board[i + xdim] += 1;
                }
            }
            else if ((i == ((xdim * ydim) - xdim)))
            {   //lower left corner
                /*
            0000
            0000
            1000
            */
                if (board[i + 1] != 9)
                { //element to right
                    board[i + 1] += 1;
                }
                if (board[i - xdim] != 9)
                { //above
                    board[i - xdim] += 1;
                }
                if (board[i - (xdim + 1)] != 9)
                { //diagonal  ***
                    board[i - (xdim + 1)] += 1;
                }
            }
            else if ((i % xdim == (xdim - 1)))
            {   //for right column
                //^-- for elements in rightmost column
                if (board[i - 1] != 9)
                { //left element --> also works for the element to the left of the lower right corner
                    board[i - 1] += 1;
                }
                if (board[i + (xdim - 1)] != 9)
                { //diagonal element for upper right corner
                    board[i + (xdim - 1)] += 1;
                }
                if (board[i + xdim] != 9)
                { //bottom element  for upper right corner
                    board[i + xdim] += 1;
                }
                if (board[i - xdim] != 9)
                { //element above the right lower corner
                    board[i - xdim] += 1;
                }
                if (board[i - (xdim + 1)] != 9)
                { //element diagonal to the lower right corner
                    board[i - (xdim + 1)] += 1;
                }
            }
            else if ((i % xdim) == 0)
            { //for left column

                if (board[i + 1] != 9)
                { //element to the right of upper corner and lower corner
                    board[i + 1] += 1;
                }
                if (board[i - xdim] != 9)
                { //element above the lower left corner
                    board[i - xdim] += 1;
                }
                if (board[i + xdim] != 9)
                { //element below the upper corner
                    board[i + xdim] += 1;
                }
                if (board[i + xdim + 1] != 9)
                { //element diagonal to the upper corner
                    board[i + xdim + 1] += 1;
                }
                if (board[i - (xdim + 1)] != 9)
                { //element diagonal to the lower left corner  ****
                    board[i - (xdim + 1)] += 1;
                }
            }
            else if ((i % xdim != 0) && (i % ydim != 0) && (i % xdim != (xdim - 1)) && (i % ydim != (ydim - 1)))
            { //condition to make sure i is not on the edges or corners

                if (board[i + (-xdim - 1)] != 9)
                {
                    board[i + (-xdim - 1)] += 1;
                }
                if (board[i - xdim] != 9)
                {
                    board[i - xdim] += 1;
                }
                if (board[i + (-xdim + 1)] != 9)
                {
                    board[i + (-xdim + 1)] += 1;
                }
                if (board[i - 1] != 9)
                {
                    board[i - 1] += 1;
                }
                if (board[i + 1] != 9)
                {
                    board[i + 1] += 1;
                }
                if (board[i + (xdim - 1)] != 9)
                {
                    board[i + (xdim - 1)] += 1;
                }
                if (board[i + xdim] != 9)
                {
                    board[i + xdim] += 1;
                }
                if (board[i + (xdim + 1)] != 9)
                {
                    board[i + (xdim + 1)] += 1;
                }
            }
        }
    }
}
//Check compute neighbours for 5 by 5 with 4 geese in the middle of each boundary

void hideBoard(char *board, std::size_t xdim, std::size_t ydim)
{
    // board is a char array and all of these elements need to be made into hidden fields
    for (int i{0}; i < xdim * ydim; i++)
    {
        board[i] ^= hiddenBit();
    }
}

void cleanBoard(char *board)
{
    //de-allocate the given board
    //from the slides

    delete[] board;
    board = nullptr;
}

void printBoard(char *board, std::size_t xdim, std::size_t ydim)
{

    for (int i{0}; i < ydim; i++)
    {

        for (int k{0}; k < xdim; k++)
        {

            if (board[(i * xdim) + k] & markedBit())
            {
                std::cout << 'M';
            }
            else if (board[(i * xdim) + k] & hiddenBit())
            {
                std::cout << '*';
            }
            else
            {
                (board[(i * xdim) + k] += 48);
                std::cout << (board[(i * xdim) + k]);
                (board[(i * xdim) + k] -= 48);
            }
        }
        std::cout << std::endl;
    }

    // if(board[k] |= hiddenBit()){
    //     std::cout<< board[k];
    // } else {
    //     std::cout<< '*';
    // }

    //char array = {0x01, 0x09, ...}
    /* 
     19
     11
     00

     //if visible,  --> no flag in the hidden bit       0000 xxxx
     0x01 0x09
     0x01 0x01
     0x00 0x00

     print out values:
     19
     11
     00

     //if not visible (its hidden)  ---> there is a bit in the hidden flag
     0x21 0x29
     0x21 0x21
     0x20 0x20

     print out
     **
     **
     **

     //if its marked              0000 xxxx
     0x21 0x39
     0x21 0x21
     0x21 0x21

     print out 

     *M
     **
     ** 

     */
}

int reveal(char *board, std::size_t xdim, std::size_t ydim, std::size_t xloc, std::size_t yloc)
{

    //get to location to be revealed
    int num = ((yloc * xdim) + xloc);

    //if field is marked, return 1
    //if field is revealed, return 2    basically hiddenBit == 0
    // if field is goose, reveal the goose and return 9
    //else remove hiddenBit
    if (!(board[num] & hiddenBit()))
    {
        return 2;
    }

    if (board[num] & markedBit())
    {
        return 1;
    }
    // if(!(board[num] & hiddenBit())){
    //     // board[num] ^= hiddenBit();
    if ((board[num] & valueMask()) == 9)
    {
        board[num] ^= hiddenBit();
        return 9;
    }
    else if (board[num] & valueMask() == 0)
    {
        board[num] ^= hiddenBit();

        if ((num == (xdim - 1)))
        { //upper right corner
            if ((board[num - 1] & valueMask()) != 9)
            { //for element - left
                board[num - 1] &= valueMask();
            }
            if ((board[num + (xdim - 1)] & valueMask()) != 9)
            { //diagonal
                board[num + (xdim - 1)] &= valueMask();
            }
            if ((board[num + xdim] & valueMask()) != 9)
            { // bottom
                board[num + xdim] &= valueMask();
            }
        }
        else if ((num == ((xdim * ydim) - 1)))
        { //lower right corner
            if ((board[num - 1] & valueMask()) != 9)
            { //element to left
                board[num - 1] &= valueMask();
            }
            if ((board[num - xdim] & valueMask()) != 9)
            { //above
                board[num - xdim] &= valueMask();
            }
            if ((board[num - (xdim + 1)] & valueMask()) != 9)
            { //diagonal
                board[num - (xdim + 1)] &= valueMask();
            }
        }
        else if ((num == 0))
        { //upper left corner
            if ((board[num + 1] & valueMask()) != 9)
            { //element to right
                board[num + 1] &= valueMask();
            }
            if ((board[num + xdim + 1] & valueMask()) != 9)
            { //diagonal
                board[num + xdim + 1] &= valueMask();
            }
            if ((board[num + xdim] & valueMask()) != 9)
            { //below
                board[num + xdim] &= valueMask();
            }
        }
        else if (num == ((xdim * ydim) - xdim))
        { //lower left corner
            if ((board[num + 1] & valueMask()) != 9)
            { //element to right
                board[num + 1] &= valueMask();
            }
            if ((board[num - xdim] & valueMask()) != 9)
            { //above
                board[num - xdim] &= valueMask();
            }
            if ((board[num - (xdim + 1)] & valueMask()) != 9)
            { //diagonal
                board[num - (xdim + 1)] &= valueMask();
            }
        }
        else if ((num % xdim == (xdim - 1)))
        {   //for right upper and lower corners  //&& (i%xdim == (ydim-1))
            //^-- for elements in rightmost column
            if ((board[num - 1] & valueMask()) != 9)
            { //left element --> also works for the element to the left of the lower right corner
                board[num - 1] &= valueMask();
            }
            if ((board[num + (xdim - 1)] & valueMask()) != 9)
            { //diagonal element for upper right corner
                board[num + (xdim - 1)] &= valueMask();
            }
            if ((board[num + xdim] & valueMask()) != 9)
            { //bottom element  for upper right corner
                board[num + xdim] &= valueMask();
            }
            if ((board[num - xdim] & valueMask()) != 9)
            { //element above the right lower corner
                board[num - xdim] &= valueMask();
            }
            if ((board[num - (xdim + 1)] & valueMask()) != 9)
            { //element diagonal to the lower right corner
                board[num - (xdim + 1)] &= valueMask();
            }
        }
        else if ((num % xdim) == 0)
        {
            if ((board[num + 1] & valueMask()) != 9)
            { //element to the right of upper corner and lower corner
                board[num + 1] &= valueMask();
            }
            if ((board[num - xdim] & valueMask()) != 9)
            { //element above the lower left corner
                board[num - xdim] &= valueMask();
            }
            if ((board[num + xdim] & valueMask()) != 9)
            { //element below the upper corner
                board[num + xdim] &= valueMask();
            }
            if ((board[num + xdim + 1] & valueMask()) != 9)
            { //element diagonal to the upper corner
                board[num + xdim + 1] &= valueMask();
            }

            if ((board[num - (xdim - 1)] & valueMask()) != 9)
            { //element diagonal to the lower left corner
                board[num - (xdim - 1)] &= valueMask();
            }
        }
        else if (num < xdim)
        {
            if ((board[num + 1] & valueMask()) != 9)
            {
                board[num + 1] &= valueMask();
            }
            if ((board[num - 1] & valueMask()) != 9)
            {
                board[num - 1] &= valueMask();
            }
            if ((board[num + (xdim + 1)] & valueMask()) != 9)
            { //lower right diagonal
                board[num + (xdim + 1)] &= valueMask();
            }
            if ((board[num + (xdim - 1)] & valueMask()) != 9)
            {
                board[num + (xdim - 1)] &= valueMask();
            }
            if ((board[num + xdim] & valueMask()) != 9)
            { // top right
                board[num + xdim] &= valueMask();
            }
            else if (num >= xdim * (ydim - 1))
            {
                if ((board[num - 1] & valueMask()) != 9)
                { // left
                    board[num - 1] &= valueMask();
                }
                if ((board[num + 1] & valueMask()) != 9)
                { // right
                    board[num + 1] &= valueMask();
                }
                if ((board[num - xdim - 1] & valueMask()) != 9)
                { // top left
                    board[num - xdim - 1] &= valueMask();
                }
                if ((board[num - xdim] & valueMask()) != 9)
                { // top
                    board[num - xdim] &= valueMask();
                }
                if ((board[num - xdim + 1] & valueMask()) != 9)
                { // top right
                    board[num - xdim + 1] &= valueMask();
                }
            }
            else if ((num % xdim != 0) && (num % xdim != (xdim - 1)))
            { //condition to make sure num is not on the edges or corners
                //(num%ydim != 0) &&      && (num%ydim != (ydim-1))
                if ((board[num + (-xdim - 1)] & valueMask()) != 9)
                {
                    board[num + (-xdim - 1)] &= valueMask();
                }
                if ((board[num - xdim] & valueMask()) != 9)
                {
                    board[num - xdim] &= valueMask();
                }
                if ((board[num + (-xdim + 1)] & valueMask()) != 9)
                {
                    board[num + (-xdim + 1)] &= valueMask();
                }
                if ((board[num - 1] & valueMask()) != 9)
                {
                    board[num - 1] &= valueMask();
                }
                if ((board[num + 1] & valueMask()) != 9)
                {
                    board[num + 1] &= valueMask();
                }
                if ((board[num + (xdim - 1)] & valueMask()) != 9)
                {
                    board[num + (xdim - 1)] &= valueMask();
                }
                if ((board[num + xdim] & valueMask()) != 9)
                {
                    board[num + xdim] &= valueMask();
                }
                if ((board[num + (xdim + 1)] & valueMask()) != 9)
                {
                    board[num + (xdim + 1)] &= valueMask();
                }
            }
        }
    }
    return 0;
}

// if(board[num] & hiddenBit()){
//     if(board[num] & valueMask() == 0x09){
//         return 9;
//     }
//     if(board[num] & markedBit()){
//         return 1;
//     }
//     if(board[num] | markedBit()){
//         return 2;
//     }

//         if (board[num] & valueMask() == 0){
//             //using same stuff as compute neighbours
//             for (int i {0}; i < (xdim*ydim); i++){

//         //go through board to find if there's any 9s
//                 if(board[num] & valueMask() == 9){

//                     if ((i%xdim != 0) && (i%ydim != 0) && (i%xdim != (xdim-1)) && (i%ydim != (ydim-1))){   //condition to make sure i is not on the edges or corners

//                         if(board[i+(-xdim-1)] != 9){
//                             board[i+(-xdim-1)] += 1;
//                         }
//                         if (board[i-xdim]!=9){
//                             board[i-xdim] += 1;
//                         }
//                         if (board[i+(-xdim+1)]!=9){
//                             board[i+(-xdim+1)] += 1;
//                         }
//                         if (board[i-1]!=9){
//                             board[i-1] += 1;
//                         }
//                         if (board[i+1]!=9){
//                             board[i+1] += 1;
//                         }
//                         if (board[i+(xdim -1)]!=9){
//                             board[i+(xdim-1)] += 1;
//                         }
//                         if (board[i+xdim]!=9){
//                             board[i+xdim] += 1;
//                         }
//                         if (board[i+(xdim +1)]!=9){
//                             board[i+(xdim+1)] += 1;
//                         }

//                 } else if ((i%xdim == (xdim-1)) ){     //for right upper and lower corners  //&& (i%xdim == (ydim-1))
//                         //^-- for elements in rightmost column
//                         if(board[i-1] != 9){       //left element --> also works for the element to the left of the lower right corner
//                             board[i-1] += 1;
//                         }
//                         if(board[i+(xdim-1)] != 9){        //diagonal element for upper right corner
//                             board[i+(xdim-1)] += 1;
//                         }
//                         if(board[i+xdim] != 9){          //bottom element  for upper right corner
//                             board[i+xdim] += 1;
//                         }
//                         if(board[i-xdim] != 9){     //element above the right lower corner
//                             board[i-xdim] += 1;
//                         }
//                         if(board[i-(xdim+1)] != 9){      //element diagonal to the lower right corner
//                             board[i-(xdim+1)] += 1;
//                         }
//                     } else if((i%xdim) == 0){
//                         if(board[i+1] != 9){      //element to the right of upper corner and lower corner
//                             board[i+1] += 1;
//                         }
//                         if(board[i+xdim] != 9){    //element below the upper corner
//                             board[i+xdim] += 1;
//                         }
//                         if(board[i+xdim+1] != 9){   //element diagonal to the upper corner
//                             board[i+xdim+1] += 1;
//                         }
//                         if(board[i-xdim] != 9){   //element above the lower left corner
//                             board[i-xdim] += 1;
//                         }
//                         if(board[i-(xdim-1)] != 9){      //element diagonal to the lower left corner
//                             board[i-(xdim-1)] += 1;
//                         }
//                     }
//                 }
//             }
//         }
//     } else if (board[num] & hiddenBit() && board[num] | markedBit()){
//         return 2;
//     }
// }

int mark(char *board, std::size_t xdim, std::size_t ydim, std::size_t xloc, std::size_t yloc)
{

    int num = ((yloc * xdim) + xloc);

    if (board[num] & hiddenBit())
    {
        board[num] ^= markedBit();
        return 0;
    }
    else
    {
        return 2;
    }

    // for(int i{0}; i < xdim*ydim; i++){
    //     if(i == num){
    //         if(board[num] & hiddenBit()){
    //             return 0;
    //         }
    //     }
    //     count++;
    // }
    // return 1;
}

bool isGameWon(char *board, std::size_t xdim, std::size_t ydim)
{

    for (int i{0}; i < (xdim * ydim); i++)
    {
        if (((board[i] & valueMask()) != 9) && (board[i] & hiddenBit()))
        {
            return false;
        }
    }
    return true;
    //if all fields containing goose are hidden and marked --> not won yet
    //whether are not all fields that are NOT goose are revealed

    //look through board

    // if any field that is NOT goose is revealed --> you win
    //if any field that is not a goose and is hidden --> no win
}

/*
011
01*
011

for (....){
    if(field is revealed){
        if (contains goose){
            you lose;
        } else if
    }
}
*/

// int main();
// int main(){
//     int xdim{0};
//     int ydim{0};
//     int numGeese{0};

//     std::cout << "Welcome to GeeseSpotter!" << std::endl;
//     std::cout << "Please enter the x dimensions:" << std::endl;
//     std::cin >> xdim;
//     std::cout <<"Please enter the y dimensions: " << std::endl;
//     std::cin>> ydim;

//     std::cout << *createBoard(xdim, ydim);

// //     // std::cout <<"Please enter the number of geese: " << std::endl;
// //     // std::cin>> numGeese;

// //     // std::cout<< "Please enter the action ([S]how; [M]ark; [R]estart; [Q]uit): "<< std::endl;
// }

// char *createBoard(std::size_t xdim, std::size_t ydim){

//     char board[xdim*ydim]{};

//     for (int i; i < (xdim*ydim); i++){
//         board[i] = '\0';
//     }

//     char *p_board = board;

//     return p_board;
// }

// double *a_data{ nullptr};                  // Declaring an array with 100 elements using new double
// a_data = new double [100];
// delete [] a_data;
// a_data = nullptr;

// void geometric (double a, double r, std::size_t n){

//     double *a_tmp{new double [n]};
//     double term{1.0};

//     for (std::size_t k{0}; k < n; ++k){
//         a_tmp[k] = a*term;                                //Memory Leak
//         term *= r;

//     }
