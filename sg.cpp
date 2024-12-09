#include <iostream>
#include <cstdlib>


using namespace std;

struct Node {
    int x, y;
    Node *next;
};
const int height=5;
const int width=10;
enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };

bool gameOver;
Direction dir;
Node *head;
int foodX, foodY;
int score;

void Setup() {
    gameOver = false;
    dir = STOP;
    head = (Node*)malloc(sizeof(Node));
    head->x = width/2;
    head->y = height/2;
    head->next = nullptr;
    foodX = rand() % width;
    foodY = rand() % height;
    score = 0;
}

void Draw() {
    system("cls"); // Clear the console

    //----------------------------------Drawing top boundary-----------------------------------------------------
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    //-------------------------------- Drawing game area-----------------------------------------
    for (int i = 0; i < height; i++) { //columns
        for (int j = 0; j < width + 2; j++) { //rows
            if (j == 0 || j == width + 1){
                cout << "#"; // Left and right borders
            }
            else if (i == head->y && j == head->x + 1){ //x+1 because width+2 is real width so half is +1
                cout << "O"; // Snake head
            }
            else if (i == foodY && j == foodX + 1){ //same here random generated but to place it at correct random position
                cout << "F"; // Food
            }
            else {
                bool print = false;
                Node *temp = head; //checking for body segments
                while (temp!= nullptr) {
                   if (temp != head && temp->x == j - 1 && temp->y == i) { // temp should not be head
                        cout << "o"; // Snake body
                        print = true;
                    }
                    temp = temp->next;
                }
                if (print==false) {
                    cout << " ";
                }
            }
        }
        cout << endl;
    }

    // Draw bottom boundary
    for (int i = 0; i < width + 2; i++){
        cout << "#";
    }
    cout << endl;

    cout << "Score: " << score << endl;
}



void Input() {
    char input;
    cin >> input;

    switch (input) {
        case 'l':
            dir = LEFT;
            break;
        case 'r':
            dir = RIGHT;
            break;
        case 'u':
            dir = UP;
            break;
        case 'd':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        default:
            gameOver=true;
            break;
    }
}
void Update() {
    // Create a new node for the new head
    Node* newHead = (Node*)malloc(sizeof(Node));
    newHead->x = head->x;
    newHead->y = head->y;

    // Update the new head's position based on the direction
    switch (dir) {
        case LEFT:
            newHead->x--;
            break;
        case RIGHT:
            newHead->x++;
            break;
        case UP:
            newHead->y--;
            break;
        case DOWN:
            newHead->y++;
            break;
        default:
            break;
    }

    // Check for collision with boundaries
    if (newHead->x < 0 || newHead->x >= width || newHead->y < 0 || newHead->y >= height) {
        gameOver = true;
        return;
    }

    // Check for collision with itself
    Node* current = head->next; //if moves in a loop and return backs to original position then fake collision detected
    while (current != nullptr) {
        if (current->x == newHead->x && current->y == newHead->y) {
            gameOver = true;
            return;
        }
        current = current->next;
    }

    // If no collisions, update the snake's position
    // Move the new head to the front
    newHead->next = head;
    head = newHead;

    // Check if the snake has eaten the food
    if (head->x == foodX && head->y == foodY) {
        // Increase the score
        score += 10;

        // Generate new food position
        foodX = rand() % width;
        foodY = rand() % height;
    } else {
        // If the snake hasn't eaten the food, remove the tail
        Node* tail = head;
        while (tail->next->next != nullptr) {
            tail = tail->next;
        }
        delete tail->next;
        tail->next = nullptr;
    }
}

void ExitGame() {
    system("cls");
    cout << "Game Over!" << endl;
    cout << "Score: " << score << endl;

    while (head != nullptr) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    exit(0);
}

int main() {
    Setup();

    while (gameOver==false) {
        Draw();
        Input();
        Update();
    }

    ExitGame();
    return 0;
}
