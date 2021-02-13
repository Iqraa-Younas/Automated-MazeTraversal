# Automated-MazeTraversal
It is an automated version of a game where ghost trapped in a maze find it's path out.

1-DATA MEMBERS:

char** maze;

int curr_row;

int curr_col;

int start_row;

int start_col;

int end_row;

int end_col;

char Dir; //direction, it will be needed for automation

const int size; //initialize it in member initializer list of class constructor

// data for MFC graphics display

int cellWidthPx; //A good value can be 40 or 60

int cellHeightPx;

2-FUNCTIONS(PUBLIC)


MazeTraversal(int size = 12);

void LoadMaze(); // call in constructor

void moveUp();

void moveLeft();

void moveDown();

void moveRight();

bool DestinationReached();

void display();

void moveToNextCell(); // it will be needed for automation

~MazeTraversal();


3-GETTER FUNCTIONS


int getCellWidthPx();

int getCellHeightPx();

int getSize();

int getStartRow();

int getStartCol();

int getCurrRow();

int getCurrCol();

char getCellValueAt(int i, int j); // the returned character is either ‘.’ or ‘#’



Data Members:

The 2d array maze will hold the data of maze.

The current position of ghost is stored by start_row and start_col.

The current position of ghost is stored by curr_row and curr_col. Initially it will be same as start position.

The destination point of maze is stored by end_row and end_col;


Member Functions:
1. MazeTraversal(int size = 12);

The Constructor initializes all the data members. Start and End cell values can be hard coded as will be
in the maze provided. It alos intitlizes char**maze 2D array to size by size.

2. void LoadMaze();

Loads the content of “maze.txt” (provided) into 2D array maze. It must be called in constructor
MazeTraversal(). In the two-dimensional array, the hashes represent the walls of the maze and the dots
represent squares in the possible paths through the maze. Moves can be made only to a location in the
array that contains a dot.

3. bool DestinationReached();

Checks if current position of ghost is same as the destination point, and returns true. Otherwise false is
returned.

4. void moveUp(); void moveLeft(); void moveDown(); void moveRight();

Move functions update the current position of ghost according to desired direction, Let us say current
position on maze is (i, j) then following possibilities of movements will occur in each function.

5. Getter Functions help access values of class data members in the View class

