#include"pch.h"
#include "MazeTraversal.h"

#include<iostream>
#include<string>
#include<fstream>



using namespace std;

MazeTraversal::MazeTraversal(int size ):size(size){
    maze = new char* [size];
	for (int i = 0; i < size; i++) {
		maze[i] = new char[size];
	}
    for (int i = 0; i < size; i++)
	{
      for (int j = 0; j < size; j++)
		{
			maze[i][j] = NULL;
	    }
	}
	
    LoadMaze();
	curr_col = 0;
	start_col = 0;
	for (int i = 0; i < size; i++) {
		if (maze[i][curr_col] == '.') {
			curr_row = i;
			start_row = i;
		}

	}
	end_col = size - 1;
	for (int i = 0; i < size; i++) {
		if (maze[i][end_col] == '.') {
			end_row = i;
			break;
		}
		else {
			end_row = -1;
		}
	}
	
	Dir = 'R';    
	cellHeightPx = 50;
	cellWidthPx = 50;
	

	
} 
void MazeTraversal::LoadMaze(){ // call in constructor
	ifstream input;
	char c;
	int i = 0,j = 0;
	input.open("maze.txt");
	if (input.fail()) {
		cout << "UNABLE TO OPEN FILE" << endl;
	}
	if (input.is_open()) {
		while (input >> c) {
			
			maze[i][j] = c;
			j++;
			if (j % 12 == 0) {
				i++;
				j = 0;
			}
		}
	}
	
	input.close();
	
}   
void MazeTraversal::moveUp() {
	
	if (maze[curr_row - 1][curr_col] == '.') {
		Beep(100, 50);
		Dir = 'U';
		curr_row = curr_row - 1;
	}
	//noend
	/*if (curr_col == end_col - 1 && end_row == -1 && curr_row == this->size - 2) {
		end_row = start_row;
		end_col = start_col;
	}*/
}
void MazeTraversal::moveLeft() {
	
	if (maze[curr_row][curr_col - 1] == '.') {
		Beep(100, 50);
		Dir = 'L';
		curr_col = curr_col - 1;
	}
	//noend
	/*if (curr_col == end_col - 1 && end_row == -1 && curr_row == this->size - 2) {
		end_row = start_row;
		end_col = start_col;
		
	}*/

}
void MazeTraversal::moveDown() {
	
	if (maze[curr_row + 1][curr_col] == '.') {
		Beep(100, 50);
		Dir = 'D';
		curr_row = curr_row + 1;
	}
	//noend
	/*if (curr_col == end_col - 1 && end_row == -1 && curr_row == this->size - 2) {
		end_row = start_row;
		end_col = start_col;
		
		
	}*/
	
}
void MazeTraversal::moveRight() {
	if (maze[curr_row][curr_col + 1] == '.') {
		Beep(100, 50);
		Dir = 'R';
		curr_col = curr_col + 1;
	}
	//noend
	/*if (curr_col == end_col - 1 && end_row == -1 && curr_row == this->size - 2) {
		end_row = start_row;
		end_col = start_col;
	}*/
}
bool MazeTraversal::DestinationReached(){
	if (this->curr_col == this->end_col && this->curr_row == this->end_row) {
		return true;
	}
	return false;
}
void MazeTraversal::display() {
	for (int i = 0; i < this->size; i++) {
		for (int j = 0; j < this->size; j++) {
			cout << this->maze[i][j];
		}
		cout << endl;
	}
}
void MazeTraversal::moveToNextCell() {  // it will be needed for automation 

	//ifnoend
	/*if (curr_col == end_col - 1 && end_row == -1 && curr_row == this->size-2) {
		end_row = start_row;
		end_col = start_col;
	}*/
	
	//current
	if (curr_row == start_row && curr_col == start_col) {
		moveRight();
	}

	
	//1 left and bottom wall
	 else if (maze[curr_row][curr_col - 1] == '#' && maze[curr_row + 1][curr_col] == '#' && maze[curr_row - 1][curr_col] == '.' && maze[curr_row][curr_col + 1] == '.') {
		
			if (Dir == 'L') {
				//Dir = 'U';
				moveUp();
			}
			else if (Dir == 'D') {
				//Dir = 'R';
				moveRight();
			}
		
	}
	//2 up and down wall
	else if (maze[curr_row - 1][curr_col] == '#' && maze[curr_row + 1][curr_col] == '#' && maze[curr_row][curr_col + 1] == '.' && maze[curr_row][curr_col - 1] == '.') {
		
			if (Dir == 'R') {
				moveRight();
			}
			else if (Dir == 'L') {
				moveLeft();
			}
			else if (Dir == 'D') {
				moveDown();
			}
			else if (Dir == 'U') {
				moveUp();
			}
		
	}
	//3 right and botton wall
	else if (maze[curr_row][curr_col+1] == '#' && maze[curr_row+1][curr_col] == '#' && maze[curr_row][curr_col-1] == '.' && maze[curr_row-1][curr_col] == '.') {
		if (Dir == 'R') {
			//Dir = 'U';
			moveUp();
		}
		else if (Dir == 'D') {
			//Dir = 'L';
			moveLeft();
		}
	}
	//4 left and up wall
	else if (maze[curr_row][curr_col-1] == '#' && maze[curr_row-1][curr_col] == '#' && maze[curr_row][curr_col+1] == '.' && maze[curr_row+1][curr_col] == '.') {
		if (Dir == 'U') {
			//Dir = 'R';
			moveRight();
		}
		else if (Dir == 'L') {
			//Dir = 'D';
			moveDown();
		}
	}
	//5 right and up wall
	else if (maze[curr_row][curr_col+1] == '#' && maze[curr_row-1][curr_col] == '#' && maze[curr_row][curr_col-1] == '.' && maze[curr_row+1][curr_col] == '.') {
		if (Dir == 'R') {
			//Dir = 'D';
			moveDown();
		}
		else if (Dir == 'U') {
			//Dir = 'L';
			moveLeft();
		}
	}
	//6 wall on bottom only
	else if (maze[curr_row+1][curr_col] == '#' && maze[curr_row][curr_col-1] == '.' && maze[curr_row][curr_col+1] == '.' && maze[curr_row-1][curr_col] == '.') {
		if (Dir == 'D') {
			//Dir = 'L';
			moveLeft();
		}
		else if (Dir == 'R') {
			//Dir = 'R';
			moveRight();
		}
		else if (Dir == 'L') {
			//Dir = 'U';
			moveUp();
		}
	}
	//7 wall on top, bottom, left 
	else if (maze[curr_row-1][curr_col] == '#' && maze[curr_row+1][curr_col] == '#' && maze[curr_row][curr_col-1] == '#' && maze[curr_row][curr_col+1] == '.') {
		if (Dir == 'L') {
			//Dir = 'R';
			moveRight();
		}
		
	}
	//8 no wall on top,bottom,right and left
	else if (maze[curr_row+1][curr_col] == '.' && maze[curr_row-1][curr_col] == '.' && maze[curr_row][curr_col+1] == '.' && maze[curr_row][curr_col-1] == '.') {
		if (Dir == 'R') {
			//Dir = 'D';
			moveDown();
		}
		else if (Dir == 'U') {
			//Dir = 'R';
			moveRight();
		}
		else if (Dir == 'L') {
			//Dir = 'U';
			moveUp();
		}
		else if (Dir == 'D') {
			//Dir = 'L';
			moveLeft();
		}
	}
	//9 wall to left only
	else if (maze[curr_row][curr_col-1] == '#' && maze[curr_row-1][curr_col] == '.' && maze[curr_row+1][curr_col] == '.' && maze[curr_row][curr_col+1] == '.') {
		if (Dir == 'D') {
			//Dir = 'D';
			moveDown();
		}
		else if (Dir == 'U') {
			//Dir = 'R';
			moveRight();
		}
		else if (Dir == 'L') {
			//Dir = 'U';
			moveUp();
		}
	}
	//10 wall on top only
	else if (maze[curr_row-1][curr_col] == '#' && maze[curr_row+1][curr_col] == '.' && maze[curr_row][curr_col-1] == '.' && maze[curr_row][curr_col+1] == '.') {
		if (Dir == 'R') {
			//Dir = 'D';
			moveDown();
		}
		else if (Dir == 'L') {
			//Dir = 'L';
			moveLeft();
		}
		else if (Dir == 'U') {
			//Dir = 'R';
			moveRight();
		}
	}
	//11 wall on right only
	else if (maze[curr_row][curr_col+1] == '#' && maze[curr_row][curr_col-1] == '.' && maze[curr_row+1][curr_col] == '.' && maze[curr_row-1][curr_col] == '.') {
	     if (Dir == 'D') {
			//Dir = 'L';
			moveLeft();
		}
		else if (Dir == 'U') {
			//Dir = 'U';
			moveUp();
		}
		else if (Dir == 'R') {
			// Dir = 'D';
			 moveDown();
		 }
	}
	//12 wall on top,right,left
	else if (maze[curr_row-1][curr_col] == '#' && maze[curr_row][curr_col+1] == '#' && maze[curr_row][curr_col-1] == '#' && maze[curr_row+1][curr_col] == '.') {
	     if (Dir == 'U') {
			//Dir = 'D';
			moveDown();
		}
		
	}
	//13 wall on right,up and down
	else if (maze[curr_row-1][curr_col] == '#' && maze[curr_row][curr_col+1] == '#' && maze[curr_row+1][curr_col] == '#' && maze[curr_row][curr_col-1] == '.') {
	if (Dir == 'R') {
		//Dir = 'L';
		moveLeft();
	}
	
	}
	//14 wall on bottom,left,right
	else if (maze[curr_row+1][curr_col] == '#' && maze[curr_row][curr_col+1] == '#' && maze[curr_row][curr_col-1] == '#' && maze[curr_row-1][curr_col] == '.') {
	if (Dir == 'D') {
		//Dir = 'U';
		moveUp();
	}
	
	}
	//15 right and left wall
	else if (maze[curr_row ][curr_col-1] == '#' && maze[curr_row ][curr_col+1] == '#'&& maze[curr_row - 1][curr_col] == '.' && maze[curr_row + 1][curr_col] == '.') {
	 
		if (Dir == 'R') {
			moveRight();
		}
		else if (Dir == 'L') {
			moveLeft();
		}
		else if (Dir == 'D') {
			moveDown();
		}
		else if (Dir == 'U') {
			moveUp();
		}
	
	}
	//ifnoend
	//handeled in move functions
	

}
MazeTraversal::~MazeTraversal() {
	
	for (int i = 0; i < this->size; i++) {
		delete[]maze[i];
	 }
	delete[]maze;
}

//getter functions
int MazeTraversal::getCellWidthPx() {
	return this->cellWidthPx;
}
int MazeTraversal::getCellHeightPx() {
	return this->cellHeightPx;
}
int MazeTraversal::getSize() {
	return this->size;
}
int MazeTraversal::getStartRow() {
	return this->start_row;
}
int MazeTraversal::getStartCol() {
	return this->start_col;
}
int MazeTraversal::getCurrRow() {
	return this->curr_row;
}
int MazeTraversal::getCurrCol() {
	return this->curr_col;
}
char MazeTraversal::getDir() {
	return this->Dir;
}
char MazeTraversal::getCellValueAt(int i, int j) {
	if (i >= 0 && i < this->size) {
		if (j >= 0 && j < this->size) {
			return this->maze[i][j];
		}
	}
}
bool MazeTraversal::noend() {
	int endrow;
	for (int i = this->size - 2; i >=1; i--) {
		if (this->maze[i][this->size - 2] == '.') {
			endrow = i;
			break;
		}
	}
	if (curr_col == end_col - 1 && end_row == -1 && curr_row == endrow) {
		end_row = start_row;
		end_col = start_col;
		return true;

	}
	return false;
}