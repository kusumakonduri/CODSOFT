#include<iostream>
using namespace std;
char matrix[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char player = 'X';
int guesses = 0;
void Draw() {
    cout << "Tic Tac Toe" << endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
void Input() {
    int a;
    cout << "Choose your number: ";
    cin >> a;
    if(a == 1)
        matrix[0][0] = player;
    else if(a == 2) 
        matrix[0][1] = player;
    else if(a == 3) 
        matrix[0][2] = player;
    else if(a == 4) 
        matrix[1][0] = player;
    else if(a == 5) 
        matrix[1][1] = player;
    else if(a == 6) 
        matrix[1][2] = player;
    else if(a == 7) 
        matrix[2][0] = player;
    else if(a == 8) 
        matrix[2][1] = player;
    else if(a == 9) 
        matrix[2][2] = player;
    guesses++;
}
char Win() {
    for(int i = 0; i < 3; i++) {
        if(matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2])
            return matrix[i][0];
    }
        for(int i = 0; i < 3; i++) {
        if(matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i])
            return matrix[0][i];
    }
        if(matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2])
        return matrix[0][0];
    if(matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0])
        return matrix[0][2];
    return ' ';
}
int main() {
    Draw();
    while(true) {
        Input();
        Draw();
        if(Win() != ' ') {
            cout << "Player " << player << " wins!" << endl;
            cout << "Number of guesses: " << guesses << endl;
            break;
        }
        player = (player == 'X') ? 'O' : 'X';
    }
    return 0;
}
