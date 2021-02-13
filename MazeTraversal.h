#pragma once
#include"pch.h"
#include<iostream>
#include<fstream>
#include<string>


using namespace std;
class MazeTraversal
{
    char** maze;
    int curr_row; 
    int curr_col; 
    int start_row;  
    int start_col;  
    int end_row;  
    int end_col; 
    char Dir;  //direction, it will be needed for automation 
    const int size; //initialize it in member initializer list of class constructor   
                    // data for MFC graphics display 
    int cellWidthPx;    //A good value can be 40 or 60 
    int cellHeightPx; 


public: 
    MazeTraversal(int size = 12); 
    void LoadMaze();  // call in constructor  
    void moveUp(); 
    void moveLeft(); 
    void moveDown();
    void moveRight(); 
    bool DestinationReached(); 
    void display();
    void moveToNextCell();  // it will be needed for automation 
    ~MazeTraversal(); 

       //getter functions
    int getCellWidthPx(); 
    int getCellHeightPx(); 
    int getSize(); 
    int getStartRow(); 
    int getStartCol(); 
    int getCurrRow(); 
    int getCurrCol();
    char getDir();
    char getCellValueAt(int i, int j);  // the returned character is either ‘.’ or ‘#’   
                                        //You may add further functions if you need to 
    bool noend();
};

