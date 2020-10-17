#include <stdio.h>

void printMaze(char **maze, const int HT, const int WD); // prints the maze

int solveMaze(char **maze, const int HT, const int WD, int y, int x); // draws a path to the exit on the maze string

int main(){
	char mazeStr[] ="  ##############"
		   		    "#     #     ####"
		   	 	    "# ####* ### ####"
		   		    "#    ###### ####"
		   		    "#### # #### ####"
		   		    "#    # #### ####"
		   		    "#### # #### ####"
		   		    "####        ####"
		   		    "################";
	const int HT = 9;
	const int WD = 16;
	char *maze[HT];

	for (int i=0; i<HT ; i++)		// filling the 2D char array
	maze[i]=&mazeStr[i*WD];
    
	solveMaze(maze, HT, WD, 0, 0);
    
	printMaze(maze, HT, WD);
   
	return 0;
}


int solveMaze(char **maze, const int HT, const int WD, int y, int x){
    
    // solve recursively
    // however you might want to mark wrong paths with some other character
    // your functions should be able to solve other such mazes
    // pay attention to the bounds of the arrays
    // make sure you don't enter an infinite recursion

	if(y < 0 || x < 0 || y > HT-1 || x > WD - 1)
		return 0;  //Here we make sure that we dont get out of the boundaries 
	if(maze[y][x] == '#' || maze[y][x] == '.')
		return 0;  //It should also return 0(end function), if we confronted with '#' or '.'
    
	if(maze[y][x] == '*')
		return 1;  //if we reached at destination the function will stop and will not do recursion again

	maze[y][x] = '.';   //if the previous statements are not evaluated, we put dots to mark our path


    /*in these if and else if statements we check all the possible ways to go,if it is possible to go in particular direction
    function will call itself again and again until it reaches the destination, when it goes in wrong way it will backtrack and try another way*/
	if(solveMaze(maze, HT, WD, y, x+1)) return 1;
	else if(solveMaze(maze, HT, WD, y, x-1)) return 1;
	else if(solveMaze(maze, HT, WD, y+1, x)) return 1;
	else if(solveMaze(maze, HT, WD, y-1, x)) return 1;

    //if all the ways are blocked it will put a blank space and stop there,go back, and try other ways until it finds the right one.
	maze[y][x] = ' ';
	return 0;

}

void printMaze(char **maze, const int HT, const int WD){
    for (int i=0; i<HT ; i++){
	for(int j=0; j<WD-1; j++)
	  printf("%c",maze[i][j]);
	printf("%c\n",maze[i][WD-1]);
    }
}
