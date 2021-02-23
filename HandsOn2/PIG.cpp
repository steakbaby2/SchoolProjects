//Name:     Chloe Taylor
//Date:     1/2/2021
//Language: C++
//Purpose:  To make a Jeopardy style dice game called PIG where either the player or computer can win

#include <iostream>
#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */

using namespace std;

struct Pig{
    // Variables
    int score;

    //Constructor
    Pig() {
       score = 0;
    }

};


bool game(Pig &, int);
bool checkScore(Pig, int);
int diceRoll();
void rules();
void taunt();

int main() {
    // Variables
    int currentTurn = 0;
    char selection;
    char playAgain;
    bool winner = false;
    Pig player1, computer;


    // Option to see rules
    cout << "Hello! Welcome to the game PIG! " << endl;
    cout << "Would you like to see the rules? \nPlease enter Y for yes or a different letter for no"<< endl;
    cin >> selection;

    //  Displays rules if desired
    if (selection == 'y' || selection == 'Y'){
        rules();
    }

    // Loop while there is no winner
    do {
        if (currentTurn % 2 == 0) {
            currentTurn++;
            cout << "\nTurn: " << currentTurn << endl << endl;
            cout << "It is Player 1's turn\n" << endl;
            winner = game(player1, currentTurn);

            //Leave the loop if player1 wins; if winner is true
            if (winner){
                cout << "Congrats Player 1, you've won\n";
                cout << "The game was won in " << currentTurn << " turns\n";

                cout << "\nDo you want to play again? Enter y for yes or a different letter for no\n";
                cin >> playAgain;

                // Resets all of the variables if the player wishes to play again and resets the loop
                if (playAgain == 'y' || playAgain == 'Y'){
                    currentTurn = 0;
                    player1.score = 0;
                    computer.score = 0;
                    winner = false;
                    playAgain = 'x';
                    continue;
                }

                break;
            }
        }
        else {
            currentTurn++;
            cout << "\nTurn: " << currentTurn << endl << endl;
            cout << "It is the Computer's Turn\n" << endl;
            winner = game(computer, currentTurn);

            //Leave the loop if player1 wins; if winner is true
            if (winner){
                cout << "Oh no! You've lost\nBetter luck next time..";
                cout << "The game was lost in " << currentTurn << " turns";

                cout << "\nDo you want to play again? Enter y for yes or a different letter for no\n";
                cin >> playAgain;

                // Resets all of the variables if the player wishes to play again and resets the loop
                if (playAgain == 'y' || playAgain == 'Y'){
                    currentTurn = 0;
                    player1.score = 0;
                    computer.score = 0;
                    winner = false;
                    playAgain = 'x';
                    continue;
                }
            }
        }


    }
    while (!winner);



    // End program
    return 0;
}

// This is where most of the logic behind the game is
bool game(Pig & tempPlayer, int turn) {
    int temp = 0;
    int sum = 0;
    int count = 0;
    char choice = 'z';

    cout << "Your current score is: " << tempPlayer.score << endl;

    // Checks to see if the score is over 100 and asks the player if they want to say pig
    if (checkScore(tempPlayer, turn)){
        return true;
    }

    temp = diceRoll();

    // If the first roll is a 1, the player's turn is over. Otherwise, the turn continues
    if (temp == 1){
        cout << "Your first roll was a " << temp << ". You will receive no points and your turn is over\n";

        // May cause the computer to taunt
        taunt();

        // A pause to allow time for processing the loss
        system("pause");
        return false;
    }
    else {
        cout << "Your first roll was a " << temp << " \n";

        while (choice != 'h' || choice != 'H'){

            // If it is the first roll, the sum is the current score plus whatever the first dice roll was
            // otherwise, the total sum for subsequent rolls is the sum + that roll
            if (count < 1)
                sum = tempPlayer.score + temp;
            else
                sum = sum + temp;

            // To check if it is the first turn or not
            count++;
            cout << "Your updated score is " << sum << endl;

            taunt();

            cout << "Would you like to roll again or hold?\nPlease enter R to roll again or H to hold\n";

            //Checks to see if the player is the computer or the player be checking the turn
            //The computers turn will be an even number
            if (turn % 2 == 0){
                //random number generator
                srand(time(0));
                if ((rand() % 100 + 1) % 2 == 0) {
                    cout << "The computer chose to roll again!\n";
                    choice = 'r';
                }
                else {
                    cout << "The computer choose to hold!\n";
                    choice = 'h';
                }
            }
            else{
                cin >> choice;
            }

            // While choice is not r & R & h & H, the user will have to put in another char
            while (choice != 'R' && choice != 'r' && choice != 'H' && choice != 'h') {
                cout << "Invalid choice. Please try again\n";
                cin >> choice;
            }

            // Will roll the dice again
            if (choice == 'R' || choice == 'r'){
                cout << "Rolling Again!\n";
                cout << "Your roll is a . . . ";

                // A pause for dramatic effect
                system("pause");

                temp = diceRoll();
                cout << temp << endl << endl;

                // If the dice roll is 1, all points are lost
                if (temp == 1){
                    cout << "Oh no your score was a 1! You loose all the points from this turn!" << endl;
                    cout << "Your final score from this turn is " << tempPlayer.score << endl;
                    cout << "Better luck next turn!" << endl;

                    taunt();

                    // A pause to allow time for processing the loss
                    system("pause");
                    return false;
                }
            }
            // This will make the sum the total score
            else if (choice == 'H' || choice == 'h'){
                tempPlayer.score = sum;

                // Checks the score again to see if over 100
                if (checkScore(tempPlayer, turn)){
                    return true;
                }

                cout << "Turn over!\n";
                cout << "Your final score from this turn is " << tempPlayer.score << endl;

                taunt();

                // A pause to allow time for the player to see their score
                system("pause");
                return false;
            }
        }

        //Returns false once the turn is over
        return false;
    }

}

// Check if the score is over 100. Returns true if the player or computer says pig
bool checkScore(Pig tempPlayer, int turn){
    char choice = 'x';

    if (tempPlayer.score >= 100) {
        cout << "Would you like to shout pig? Please enter P otherwise, press x" << endl;

        //Checks to see if the player is the computer or the player be checking the turn
        if (turn % 2 == 0)
        {
            //random num generator
            srand(time(0));
            if ((rand() % 1) == 0) {
                cout << "The computer said PIG!\n";
                choice = 'p';
            }
            else {
                cout << "The computer choose not to say PIG! You have been spared!\n";
                choice = 'x';
            }
        }
        else{
            cin >> choice;
        }

        if (choice == 'P' || choice == 'p') {
            return true;
        }
        else
            return false;
    }
    else
        return false;
}

// Rolls the dice
int diceRoll() {
    srand(time(0));
    return rand() % 6 + 1;
}

// Displays the rules
void rules(){
    cout << "Your goal is to get a total score of at least 100. \n";
    cout << "Once your score is at 100, hold then shout PIG and you will win the game. \n";
    cout << "Each turn, you will get a chance to roll the dice. \n";
    cout << "If you roll a 1, you loose all the points you've scored that turn. \n";
    cout << "If you do not roll a 1, the number will be added to your total score and \nyou can choose to roll again or hold your turn.\n" << endl;
}

// A collection of fun taunts the computer can say at any time
void taunt(){
    int taunt = 0;
    srand(time(0));

    // If the random number is even, the computer will taunt
    if ((rand() % 100 + 1) % 2 == 0){

        //taunt
        srand(time(0));
        taunt = (rand() % 10 + 1);

        cout << "\n!!!The computer used a taunt!!!" << endl;

        switch (taunt)
        {
            case 1: cout << "Think you can handle me?\n";
                break;
            case 2: cout << "You're never gonna beat me!!\n";
                break;
            case 3: cout << "Winner winner chicken dinner\n";
                break;
            case 4: cout << "Is that all you've got?? \n";
                break;
            case 5: cout << "You bad at this aren't you? \n";
                break;
            case 6: cout << "You can do it\n";
                break;
            case 7: cout << "Good Luck!!\n";
                break;
            case 8: cout << "Do your best\n";
                break;
            case 9: cout << "Are you having fun?\n";
                break;
            case 10: cout << "Keep it up\n";
                break;
        }

        cout << endl;

    }
}