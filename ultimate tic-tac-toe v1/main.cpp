/*
 * main.cpp
 *
 *  Created on: Apr 19, 2020
 *      Author: Solomon Segbefia
 */

#include <iostream>
using namespace std;

//creates a 3*3 matrix
char matrix[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

char player = 'X'; //Creates the default player X

//This function draws matrix as a grid
void DrawGrid()
{
	//system("clear");
	cout << "\t\tULTIMATE TIC TAC TOE 1st draft\n" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}


//This functions reads the player input and places it accordingly on the grid
void PlayerInput()
{
	int choice;
	cout << "\nPick the number matching where you want to play."
			"\nUse the X and O buttons.\nIt's player "
			<<  player << "'s turn to play." << endl;

	cin >> choice; //reads the user input
	if (choice == 1)
		matrix[0][0] = player;
	else if (choice == 2)
		matrix[0][1] = player;
	else if (choice == 3)
		matrix[0][2] = player;
	else if (choice == 4)
		matrix[1][0] = player;
	else if (choice == 5)
		matrix[1][1] = player;
	else if (choice == 6)
		matrix[1][2] = player;
	else if (choice == 7)
		matrix[2][0] = player;
	else if (choice == 8)
		matrix[2][1] = player;
	else if (choice == 9)
		matrix[2][2] = player;
}

//This functions determines whose turn it is
void switchPlayer()
{
	if (player == 'X')
		player = 'O';

	else
		player = 'X';
}


//This function determines the winner or Tie
char winner()
{
	//Player X
	if (matrix[0][0] == 'X' && matrix[0][1] == 'X' && matrix[0][2] == 'X') //    }
		return 'X';
	if (matrix[1][0] == 'X' && matrix[1][1] == 'X' && matrix[1][2] == 'X') //    } ----> Rows
		return 'X';
	if (matrix[2][0] == 'X' && matrix[2][1] == 'X' && matrix[2][2] == 'X') //    }
		return 'X';

	if (matrix[0][0] == 'X' && matrix[1][0] == 'X' && matrix[2][0] == 'X') //    }
		return 'X';
	if (matrix[0][1] == 'X' && matrix[1][1] == 'X' && matrix[2][1] == 'X') //    } ----> Columns
		return 'X';
	if (matrix[0][2] == 'X' && matrix[1][2] == 'X' && matrix[2][2] == 'X') //    }
		return 'X';

	if (matrix[0][0] == 'X' && matrix[1][1] == 'X' && matrix[2][2] == 'X') //    }
		return 'X';														   //      ----> Diagonals
	if (matrix[2][0] == 'X' && matrix[1][1] == 'X' && matrix[0][2] == 'X') //    }
		return 'X';

	//Player O
	if (matrix[0][0] == 'O' && matrix[0][1] == 'O' && matrix[0][2] == 'O') //    }
		return 'O';
	if (matrix[1][0] == 'O' && matrix[1][1] == 'O' && matrix[1][2] == 'O') //    } ----> Rows
		return 'O';
	if (matrix[2][0] == 'O' && matrix[2][1] == 'O' && matrix[2][2] == 'O') //    }
		return 'O';

	if (matrix[0][0] == 'O' && matrix[1][0] == 'O' && matrix[2][0] == 'O') //    }
		return 'O';
	if (matrix[0][1] == 'O' && matrix[1][1] == 'O' && matrix[2][1] == 'O') //    } ----> Columns
		return 'O';
	if (matrix[0][2] == 'O' && matrix[1][2] == 'O' && matrix[2][2] == 'O') //    }
		return 'O';

	if (matrix[0][0] == 'O' && matrix[1][1] == 'O' && matrix[2][2] == 'O') //    }
		return 'O'; 													   //      ----> Diagonals
	if (matrix[2][0] == 'O' && matrix[1][1] == 'O' && matrix[0][2] == 'O') //    }
		return 'O';

	return 'T'; //Its a tie!

}

int main()
{
	DrawGrid();

	while(true)
	{
		PlayerInput();
		DrawGrid();
		if (winner() == 'X')
		{
			cout << "Player X wins!";
			break;
		}
		else if (winner() == 'O')
		{
			cout << "Player O wins!";
			break;
		}
		switchPlayer();
	}

}
