#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Node structure for the game board
struct Node {
int data;
struct Node* next;
};
// Function to roll a six-sided die
int rollDie() {
return rand() % 6 + 1;
}
// Function to create a new node
struct Node* createNode(int data) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->next = NULL;
return newNode;
}
// Function to print the board
void printBoard(struct Node* head) {
struct Node* current = head;
while (current != NULL) {
printf("%d\t", current->data);
current = current->next;
}
printf("\n");
}
// Function to move the player
int movePlayer(int currentPlayer, int roll, struct Node* snakesAndLadders) {
int newPosition = currentPlayer + roll;
// Check if the new position has a snake or ladder
struct Node* current = snakesAndLadders;
while (current != NULL) {
if (current->data == newPosition) {
return current->next->data; // Move to the next position after snake or ladder
}
current = current->next;
}
if (newPosition > 100) {
return currentPlayer; // Player cannot move beyond square 100
}
return newPosition;
}
int main() {
srand(time(0)); // Initialize random seed
// Initialize the game board as a linked list
struct Node* head = createNode(1);
struct Node* current = head;
for (int i = 2; i <= 100; i++) {
current->next = createNode(i);
current = current->next;
}
// Initialize snakes and ladders as a linked list
struct Node* snakesAndLadders = createNode(6);
snakesAndLadders->next = createNode(40);
snakesAndLadders->next->next = createNode(23);
snakesAndLadders->next->next->next = createNode(-10);
// Add more snakes and ladders as needed
int player1 = 1, player2 = 1;
int currentPlayer = 1;
int won = 0;
printf("Snake and Ladder Game\n");
while (!won) {
printf("\nPlayer %d, press Enter to roll the die...", currentPlayer);
getchar(); // Wait for the player to press Enter
int roll = rollDie();
printf("You rolled a %d.\n", roll);
if (currentPlayer == 1) {
player1 = movePlayer(player1, roll, snakesAndLadders);
printf("Player 1 is now at square %d.\n", player1);
printBoard(head);
if (player1 == 100) {
printf("Player 1 wins!\n");
won = 1;
}
} else {
player2 = movePlayer(player2, roll, snakesAndLadders);
printf("Player 2 is now at square %d.\n", player2);
printBoard(head);
if (player2 == 100) {
printf("Player 2 wins!\n");
won = 1;
}
}
currentPlayer = (currentPlayer == 1) ? 2 : 1; // Switch to the other player
}
// Free memory
current = head;
while (current != NULL) {
struct Node* temp = current;
current = current->next;
free(temp);
}
current = snakesAndLadders;
while (current != NULL) {
struct Node* temp = current;
current = current->next;
free(temp);
}
return 0;
}