//*************************************************************
//  Student Names: Julia Ju and Maia Tse
//
//  SYDE 121 Lab:  Assignment: 4
//  Filename: a4_q1
//
// I hereby declare that this code, submitted for credit for the course
//  SYDE121, is a product of my own efforts.  This coded solution has
//  not been plagiarized from other sources and has not been knowingly
//  plagiarized by others.
//
// Project:  Tic Tac Toe
// Purpose: Simulates a tic tac toe game, using a 4x4 playing board where each square is represented by a number from 1 - 16.
//

/* Test Runs:
 * Row win:
 *        X         X         X         X
 O         O         7         8
 9        10         O        12
 13        14        15        16
 Player x  got a row!
 X is the winner!
 Play another round? Enter "y" to continue
 
 * Column win:
 *        X         O         3         4
 X         6         7         O
 X        10        11        12
 X         O        15        16
 Player x  got a column!
 X is the winner!
 Play another round? Enter "y" to continue
 *
 * Diagonal win:
 O         X         X         4
 5         O         7         8
 9         X         O         X
 13        14        15         O
 Player O  got a diagonal!
 O is the winner!
 Play another round? Enter "y" to continue
 *
 * X win:
 *       X         O         3         4
 X         6         7         O
 X        10        11        12
 X         O        15        16
 Player x  got a column!
 X is the winner!
 Play another round? Enter "y" to continue
 * O win:
 *        O         X         X         4
 5         O         7         8
 9         X         O         X
 13        14        15         O
 Player O  got a diagonal!
 O is the winner!
 Play another round? Enter "y" to continue
 * Tie game:
 *        X         O         X         O
 O         X         X         O
 X         O         O         X
 O         X         X         O
 Tie Game
 Play another round? Enter "y" to continue
 *
 * Play again:
 *       Play another round? Enter "y" to continue
 y
 A new game has started!
 1         2         3         4
 5         6         7         8
 9        10        11        12
 13        14        15        16
 Enter an element in the board to replace with O
 
 * Quits game:
 *
 >>> FINAL SCOREBOARD <<<
 
 It's a tie game!
 
 
 Verification Justification:
 
 We tested snearios which a row wins the game, a column wint he game, and when a diagonal wins the game.
 We Tested to make sure both X and O can win the game. And that the game can end in a tie.
 Finally, we tested to make sure that players can play the game again, and that the board will reset for
 when they want to play.
 When the user quits the game, the final scoreboard is shown. To test, we played a game where X won, and one
 where O won, so there was a tie game
 Some limitation to the game include that the game only has two player, and the board is a set size (4x4)
 */

//*************************************************************


#include <iostream>
#include <iomanip>
using namespace std;



//FUNCTION Declarations

void refresh_board(string board[4][4]);

void O_start_game(string board[4][4], int&, int&);

void X_start_game(string board[4][4], int&, int&);

bool check_winner(string board[4][4], string);




/*Function starts Tic Tac Toe
 * Input: Into the start tic tac toe game includes the board to play tic tac toe,as well as asks if they players want             to
 *         to play again. In addition, x_start_game and 0_start_game are also used.
 * Process: The function uses a do while function. So while play again, which asks the user is they want to play again
 *          is true, the program will print out a blank board and then use x_start_game and 0_start_game to play the game.
 *           When the game end. The program will ask if they want to play again. The program will also determine the final
 *           score by comapreing the amount of X win compared the O wins. Whoever has more wins, and if they are the
 *           same its a tie.
 * Output: If it is the start of a round, the function prints out a blank board and says "A new game has started!". If
 *           it is the end of the game, the program will ask if the user wants to play again. Program will also show
 *           final scorebaord.
 */

void start_tictactoe() {
    
    //Variable Declarations
    int x_wins = 0;
    int o_wins = 0;
    string num;
    string play_again;
    int count = 0;
    
    //Do while loop decides whether the game starts with player o or x, depending on how many rounds they've played.
    //he program starts with player x starting first, and player o if the user wants to play a new round.
    do {
        string board[4][4] = { {"1","2","3","4"},{"5","6","7","8"},{"9","10","11","12"},{"13","14","15","16"} }; //Blank board set up
        cout << "A new game has started! " << endl;
        
        //Prints out a blank 4x4 board
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cout << setw(10) << board[i][j];
            }
            cout << endl;
        }
        cout << endl;
        
        //Player x starts first (even rounds)
        if (count % 2 == 0) {
            X_start_game(board, x_wins, o_wins);
        }
        
        //player o starts next game (odd rounds)
        else {
            O_start_game(board, x_wins, o_wins);
        }
        
        //round is played again if user wishes to continue
        cout << "Play another round? Enter \"y\" to continue" << endl;
        cin >> play_again;
        ++count;
    } while (play_again == "y");
    
    
    //FINAL SCOREBOARD:
    
    cout << endl;
    cout << ">>> FINAL SCOREBOARD <<< " << endl;
    cout << endl;
    
    
    if (x_wins > o_wins) {
        cout << "Player x has most number of wins at " << x_wins << " win (s)!" << endl;
    }
    
    else if (x_wins < o_wins) {
        cout << "Player o has most number of wins at " << o_wins << " win (s)!" << endl;
    }
    
    else if (x_wins == o_wins) {
        cout << "It's a tie game!" << endl;
        
    }
}



//Function where player X starts the game
/*
 * Input: The inputs for this function are the board, the users number they want to select, and the check winner function.
 * Process: The fucntion will replace the value the user picked on the board with an X by updating the string with
 a new value " X" , it will then determine if there is a winner with the check winner fucntion.
 * Output: The Output of this function is the updated board with the X inserted. If there is a winner on the turn.
 *          Function will also output the winner.
 */
void X_start_game(string board[4][4], int& x_wins, int& o_wins) {
    
    
    
    //Varaible declarations
    string num;
    int turn_count = 0;     // number of times
    bool play_again = true;
    
    //do while function that checks if there is a winner is true
    do {
        //        if (count % 2 == 0) {
        cout << "Enter an element in the board to replace with X" << endl;
        cin >> num;
        
        
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                // turn count will only increase if the element in the chart is not already taken up by an X or O
                if (board[i][j] == num && board[i][j] != "X" && board[i][j] != "O") {
                    board[i][j] = "X"; //replaces element on board with X
                    turn_count++;
                }
            }
        }
        //updated board is output for user
        refresh_board(board);
        
        //checks if player X won
        if (check_winner(board, "Player x ") == true) {
            cout << "X is the winner!" << endl;
            x_wins++;
            play_again = false; // will not loop again
            break;
        }
        cout << "Enter an element in the board to replace with O" << endl;
        cin >> num;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                // turn count will only increase if the element in the chart is not already taken up by an X or O
                if (board[i][j] == num && board[i][j] != "X" && board[i][j] != "O") {
                    board[i][j] = "O";
                    turn_count++;
                }
            }
            
        }
        refresh_board(board);
        
        //checks if player O won
        if (check_winner(board, "Player O ") == true) {
            
            cout << "O is the winner!" << endl;
            o_wins++;
            play_again = false; // will not loop again
            break;
        }
        
        if (turn_count == 16) {
            cout << "Tie Game" << endl;  //the entire board is filled, there there was no winner
            break;
        }
    } while (play_again == true);
    
}









//Function where player O starts the game
/*
 * Input: The inputs for this function are the board, the users number they want to select, and the check winner function.
 * Process: The fucntion will replace the value the user picked on the board with an O by updating the string with
 a new value "O" , it will then determine if there is a winner with the check winner fucntion.
 * Output: The Output of this function is the updated board with the O inserted. If there is a winner on the turn.
 *          Function will also output the winner.
 */
void O_start_game(string board[4][4], int& x_wins, int& o_wins) {
    //do while function that checks if there is a winner is true
    string num;
    int turn_count = 0;
    bool play_again = true;
    do {
        cout << "Enter an element in the board to replace with O" << endl;
        cin >> num;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                // turn count will only increase if the element in the chart is not already taken up by an X or O
                if (board[i][j] == num && board[i][j] != "X" && board[i][j] != "O") {
                    board[i][j] = "O";  //replaces element on board with O
                    turn_count++;
                }
            }
        }
        
        refresh_board(board);
        
        //checks if Player o wins
        if (check_winner(board, "Player O ") == true) {
            cout << "O is the winner!" << endl;
            o_wins++;
            play_again = false; // will not loop again
            break;              //exits loop
        }
        
        cout << "Enter an element in the board to replace with X" << endl;
        cin >> num;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                // turn count will only increase if the element in the chart is not already taken up by an X or O
                if (board[i][j] == num && board[i][j] != "X" && board[i][j] != "O") {
                    
                    board[i][j] = "X"; //replaces element on board with X
                    turn_count++;
                }
                
            }
            
        }
        
        refresh_board(board);
        
        //checks if player X won
        if (check_winner(board, "Player  X ") == true) {
            cout << "X is the winner!" << endl;
            x_wins++;
            play_again = false;
            break;
        }
        // checks for tie game
        if (turn_count == 16) {     //the entire board is filled, there there was no winner
            cout << "Tie Game" << endl;
            break;
        }
    } while (play_again == true);
}


/*
 * Input: The input for this function is the board and what player is playing.
 * Process: The fucntion will compare every cell in a row to eachother. If they are the same, it a win.
 *           It will also compare all the cells in a column. If they are the same. There is a win.
 *           The diagonals are also comapared.
 * Output: The output of this fucntion if returned into the x_start_game and O_start_game function to be used to deteremine
 *           if there is a winner.
 */
bool check_winner(string board[4][4], string player) {
    //row 1
    if (board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][2] == board[0][3]) {
        cout << player << " got a row! " << endl;
        return true;
    }
    
    //row 2
    else if (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][2] == board[1][3]) {
        cout << player << " got a row! " << endl;
        return true;
    }
    
    //row 3
    else   if (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][2] == board[2][3]) {
        cout << player << " got a row! " << endl;
        return true;
    }
    
    //row 4
    else  if (board[3][0] == board[3][1] && board[3][1] == board[3][2] && board[3][2] == board[3][3]) {
        cout << player << " got a row! " << endl;
        return true;
    }
    //column 1
    if (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[2][0] == board[3][0]) {
        cout << player << " got a column! " << endl;
        return true;
    }
    
    //column 2
    else if (board[0][1] == board[1][1] && board[2][1] == board[2][1] && board[2][1] == board[3][1]) {
        cout << player << " got a column! " << endl;
        return true;
    }
    
    //column 3
    else   if (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[2][2] == board[3][2]) {
        cout << player << " got a column! " << endl;
        return true;
    }
    
    //column 4
    else      if (board[0][3] == board[1][3] && board[1][3] == board[2][3] && board[2][3] == board[3][3]) {
        cout << player << " got a column! " << endl;
        return true;
    }
    
    //diagonal top left to bottom right
    else     if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3]) {
        cout << player << " got a diagonal! " << endl;
        return true;
    }
    
    //diagonal bottm left to top right
    else     if (board[3][0] == board[1][2] && board[1][2] == board[1][2] && board[1][2] == board[0][3]) {
        cout << player << " got a diagonal! " << endl;
        return true;
    }
    else  {
        return false;
    }
}



//Function outputs a refreshed boards
/*
 * Input: The board in the input
 * Process: The funciton will reset the board so that the player may play another round.
 * Output: The output is a refreshed board that if used in the start game fucntions.
 */
void refresh_board(string board[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << setw(10) << board[i][j];
        }
        cout << endl;
    }
}


//The main function runs the game.

int main() {
    start_tictactoe();
}
