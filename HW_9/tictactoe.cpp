//******************************************************************************
// tictactoe.cpp
// Runs a simulation of the game, Tic-Tac-Toe.
//******************************************************************************
// Name: Gabriel Etrata
// Class: MTH 3300
// Professor: Evan Fink
// Homework_9
//******************************************************************************
// Collaborators/outside sources used: NONE
//******************************************************************************
// @author Gabriel Etrata
// @version 1.0 05/20/17
//******************************************************************************
//Comments: Program runs extremely slow.

#include <stdlib.h>
#include <iostream>
#include <ctime>

using namespace std;


/**
 * Class simulates the game of Tic-Tac Toe.
 */
class TicTacBoard{
private:
    char board[3][3];
    bool row_full(int, char);
    bool col_full(int, char);
    bool diag_full(char);
    
public:
    TicTacBoard();
    void board_print();
    void set(int, int, char);
    void random_move(char);
    bool occupied(int, int);
    bool win_for(char);

};
/**
 * Constructor that initializes an object of type TicTacBoard.
 */
TicTacBoard::TicTacBoard(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            board[i][j] = ' ';
        }
    }
}

/** Prints the board to the console.
 */
void TicTacBoard::board_print(){
    
    cout << board[0][2] << " | " << board[1][2] << " | " << board[2][2] << endl;
    cout << "__________" << endl;
    cout << board[0][1] << " | " << board[1][1] << " | " << board[2][1] << endl;
    cout << "__________" << endl;
    cout << board[0][0] << " | " << board[1][0] << " | " << board[2][0] << endl;
    cout << "__________" << endl;
    cout << "END OF GAME" << endl;
    cout << " " << endl;
}
/** Sets a character, c to the game board's position at [a][b].
    
    @param a row
    @param b column
    @param c character--x, o, or " "
 */
void TicTacBoard::set(int a, int b, char c){
    board[a][b] = c;
}

/** Checks if game board at position [a][b] is occupied.
    
    @param a row
    @param b column
*/
bool TicTacBoard::occupied(int a, int b){
    if(board [a][b] == 'x' || board [a][b] == 'o'){
        return true;
    } else {
        return false;
    }
}

/** Checks if a full row, a is occupied by a character c.
 
 @param a row
 @param c character
 */
bool TicTacBoard::row_full(int a, char c){
        if(board [a][0] == c && board[a][1] == c && board[a][2] == c){
            return true;
        } else {
            return false;
        }
}

/** Checks if a full column, a is occupied by a character c.
 
 @param a column
 @param c character
 */
bool TicTacBoard::col_full(int a, char c){
    if(board [0][a] == c && board[1][a] == c && board[2][a] == c){
        return true;
    } else {
        return false;
    }
}

/** Checks if a there is a diagonal, is occupied by a character c.
 
 @param c character
 */
bool TicTacBoard::diag_full(char c){
    if((board [0][0] == c && board[1][1] == c && board[2][2] == c) || (board [0][2] == c && board[1][1] == c && board[2][0] == c)){
        return true;
    } else {
        return false;
    }
}

/** Checks if a there's a winning position on the game baord
 
 @param c character
 */
bool TicTacBoard::win_for(char c){
        if(row_full(0, c) ||row_full(1, c) || row_full(2, c) || col_full(0, c) || col_full(1, c)|| col_full(2, c) || diag_full(c)){
            return true;
        } else {
            return false;
        }
}

/** Plays as a letter and randomly chooses a position on the game board.
 
 @param c character
 */
void TicTacBoard::random_move(char c){
    int randR;
    int randC;
    do{
        srand(time(NULL));
        randR = rand()%3;
        randC = rand()%3;
        set(randR, randC, c);
    }while (board[randR][randC] == ' ');
        
}

//Initializes the program and runs a simulation of 1e6 games.
int main()
{
    srand(time(NULL));
 
 
    TicTacBoard myGame;
    myGame.board_print();
    
    //
    // Only run the following lines after you've written .set()
    //
    myGame.set(0,0,'x');myGame.set(0,1,'o');myGame.set(1,0,'o');
    myGame.set(0,2,'x');myGame.set(1,1,'x');myGame.set(2,0,'x');
    myGame.board_print();
 
 
    //
    // Only run the following lines after you've written .occupied()
    //
    cout << "The following line should be: 111110100" << endl;
    cout << myGame.occupied(0,0) << myGame.occupied(0,1) <<myGame.occupied(0,2);
    cout << myGame.occupied(1,0) << myGame.occupied(1,1) <<myGame.occupied(1,2);
    cout << myGame.occupied(2,0) << myGame.occupied(2,1) <<myGame.occupied(2,2) << endl;
    
 
 
    //
    // Only run the following lines after you've written .win()
    //
    cout << "The following line should be: 10" << endl;
    cout << myGame.win_for('x') << myGame.win_for('o') << endl << endl;
    
    
    //
    // Only run the following lines after you've written .random_move()
    //
    myGame.random_move('x');
    myGame.board_print();
    myGame.random_move('o');
    myGame.board_print();
    
    int numOfGames = 1e6;
    int xWins = 0;
    for(int i = 0; i < numOfGames; i++){
        
        TicTacBoard newGame;
        do{
            newGame.random_move('x');
            newGame.random_move('o');
            if(newGame.win_for('x')){
                xWins++;
                cout << "x won" << endl;
                break;
            }
            if(newGame.win_for('o')){
                cout << "o won" << endl;
                break;
            }
        } while (!newGame.win_for('x') || !newGame.win_for('o'));
    
    }
    cout << "Number of Wins by X: " << xWins << endl;
    cout << "Probability of winning: " << (xWins / numOfGames) * 100 << endl;
    system("pause");
    return 0;   
}


