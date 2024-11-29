DSA MINI PROJECT: Snake and Ladder Solver using DSA in C

Problem Statement:
The objective of this project is to create a Snake and Ladder solver program using Data Structures and Algorithms (DSA) in C. The program should take a user-defined Snake and Ladder board as input and determine the minimum number of moves required to reach the final position.
By implementing this Snake and Ladder solver, we will not only reinforce our understanding of data structures and algorithms but also create a fun and interactive program for users to play and visualize the game.
METHODOLOGY:
1.Board Representation: Use a 1D or 2D array to represent the game board. Each cell of the array can represent a position on the board, and you can initialize it according to the rules of the game.
int board[100];
2.User Input: Implement a function to take user input for the number of players, snakes, and ladders, and initialize the game accordingly.
void takeUserInput();
3.Algorithm Design: Design the algorithm for simulating the game turns. This involves rolling the dice, moving players, checking for snakes and ladders, and determining the winner.
void playGame();
4.Pathfinding: Implement a function to find the shortest path from the current position to the final position on the board. You can use a simple algorithm like Breadth-First Search (BFS) to find the shortest path.
int findShortestPath(int start, int end);
5.Output: Design functions to display the current state of the board, the result of each dice roll, and the winner of the game.
CONCEPTS THAT WE WILL USE:
1.	LINKED LISTS
2.	POINTERS
3.	FUNCTIONS
4.	STRUCTURES
