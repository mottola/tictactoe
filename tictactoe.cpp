// Chapter 8 Exercise: 10
// Rick Mottola
// 18 Mar 2014

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

// function prototypes
void displayBoard(string game[][3]);
void makeMove(string player, string game[][3]);
void checkWinner(string game[][3], bool &hasWinner, string &winner);

// constants for elements
const int ROW = 3;
const int COL = 3;


int main()
{
  string userInput;
  do
  {
    int row, col, round = 0;
    bool hasWinner = false;
    string winner, game[][COL] =
	  {
	    { "*", "*", "*", },
	    { "*", "*", "*", },
	    { "*", "*", "*", }
	  };

    string player[] = {"X", "O"};

    if (userInput == "n" || userInput == "N") cout << endl << "******NEW GAME******" << endl;

    while (!hasWinner && round < 9)
	  {
	    displayBoard(game);
	    makeMove(player[round % 2], game);
	    round++;
	    checkWinner(game, hasWinner, winner);
	  } // end while statement

    if (hasWinner) cout << endl << "Player " << winner << " WINS!!" << endl;
    else cout << endl << "TIE GAME!" << endl;

      displayBoard(game);

      cout << "\n" << "Press n to start a NEW GAME or any other key to QUIT" << endl;
      cin >> userInput;
  } // end do statement
    while (userInput == "n" || userInput == "N");

    cout << endl << "GOODBYE!" << endl;

  //system("Pause");
  return 0;
} // end main

void checkWinner(string game[][3], bool &hasWinner, string &winner)
{
  for (int i = 0; i < 3; i++)
  {
    if (game[i][0] == game[i][1] && game[i][0] == game[i][2] && game[i][0] != "*")
    {
	    hasWinner = true;
	    winner = game[i][0];
    } // end if
    if (game[0][i] == game[1][i] && game[0][i] == game[2][i] && game [0][i] != "*")
    {
	    hasWinner = true;
	    winner = game[0][i];
    } // end if
    if (game[0][0] == game[1][1] && game[0][0] == game[2][2] && game[1][1] != "*")
    {
	    hasWinner = true;
	    winner = game[1][1];
    } // end if
    if (game[0][2] == game[1][1] && game[0][2] == game[2][0] && game[1][1] != "*")
    {
	    hasWinner = true;
	    winner = game[1][1];
    } // end if
  } // end for loop
} // end checkWinner

void makeMove(string player, string game[][3])
{
  int row, col;
  bool invalidInput = false;

  do
  {
	  if (invalidInput)
    {
      cout << endl << "Please enter a valid row and column. Each should be" << endl;
      cout << "between 1 and 3 and should not contain a previous move." << endl;
    } // end if statement

    cout << endl << "Player " << player << " enter row: " << endl;
    cin >> row;
    cout << endl << "Player "<< player << " enter column: " << endl;
    cin >> col;
    invalidInput = true;
  } // end do

    while (game[row-1][col-1] != "*" || row < 1 || row > 3 || col < 1 || col > 3);

    game[row-1][col-1] = player;
} // end makeMove

void displayBoard(string game[][3])
{
  int row, col;
  cout << "\n  1" << "  2" << "  3" << endl;
  for(row = 0; row < 3; row++)
  {
    cout << row+1 << " ";

    for(col = 0; col < 3; col++)
	  {
			cout << game[row][col] << "  ";
	  } // end for loop
      cout << endl;
  } // end for loop
} // end displayBoard

