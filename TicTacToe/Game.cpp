#include "Game.h"


class Board
{
public:
	void DrawBoard();
	void CheckBoard();
	
	const char* boardSpace[9] = { " ", " ", " ", " ", " ", " ", " ", " ", " " };
	bool isGameFinished = false;
};

void NewGame()
{
	ClearScreen();
	Print("### TIC TAC TOE ###");
	ShowScore();

	Board board;
	board.DrawBoard();

	int position;

	int round = 0;

	while (!board.isGameFinished)
	{
		
		std::cin >> position;
		if (round % 2 == 0)
		{
			if (board.boardSpace[position] == " ") board.boardSpace[position] = "X";
			else round--;
		}
		else
		{
			if (board.boardSpace[position] == " ") board.boardSpace[position] = "O";
			else round--;
		}

		ClearScreen();
		Print("### TIC TAC TOE ###");
		ShowScore();
		board.DrawBoard();
		board.CheckBoard();

		if (board.isGameFinished)
		{
			if (round % 2 == 0)
			{
				Print(" PLAYER X IS THE WINNER ");
				xVictories++;
			}
			else
			{
				Print(" PLAYER O IS THE WINNER ");
				oVictories++;
			}
		}

		if (round == 8 && !board.isGameFinished)
		{
			Print("Tie");
		}
		round++;
	}

	AskToPlayAgain();
}

void AskToPlayAgain()
{
	std::cout << "DO YOU WISH TO PLAY AGAIN? 1-YES 2-NO" << std::endl;
	int answer;
	std::cin >> answer;
	if (answer == 1)
	{
		NewGame();
	}
}

void ShowScore()
{
	std::cout << "Player X: " << xVictories << " " << "Player O: " << oVictories << std::endl;
	Print("");
}

void Board::CheckBoard()
{
	//Horizontal verification
	if (boardSpace[0] != " " && boardSpace[0] == boardSpace[1] && boardSpace[0] == boardSpace[2])
	{
		isGameFinished = true;
	}
	else if (boardSpace[3] != " " && boardSpace[3] == boardSpace[4] && boardSpace[3] == boardSpace[5])
	{
		isGameFinished = true;
	}
	else if (boardSpace[6] != " " && boardSpace[6] == boardSpace[7] && boardSpace[6] == boardSpace[8])
	{
		isGameFinished = true;
	}
	//Vertical verification
	else if (boardSpace[0] != " " && boardSpace[0] == boardSpace[3] && boardSpace[0] == boardSpace[6])
	{
		isGameFinished = true;
	}
	else if (boardSpace[1] != " " && boardSpace[1] == boardSpace[4] && boardSpace[1] == boardSpace[7])
	{
		isGameFinished = true;
	}
	else if (boardSpace[2] != " " && boardSpace[2] == boardSpace[5] && boardSpace[2] == boardSpace[8])
	{
		isGameFinished = true;
	}
	//Diagonal verification
	else if (boardSpace[0] != " " && boardSpace[0] == boardSpace[4] && boardSpace[0] == boardSpace[8])
	{
		isGameFinished = true;
	}
	else if (boardSpace[2] != " " && boardSpace[2] == boardSpace[4] && boardSpace[2] == boardSpace[6])
	{
		isGameFinished = true;
	}

}

void Board::DrawBoard()
{
	// Draw the Board
	std::cout << "  " << boardSpace[0] << "  |  " << boardSpace[1] << "  |  " << boardSpace[2] << std::endl;
	std::cout << " --------------- " << std::endl;
	std::cout << "  " << boardSpace[3] << "  |  " << boardSpace[4] << "  |  " << boardSpace[5] << std::endl;
	std::cout << " --------------- " << std::endl;
	std::cout << "  " << boardSpace[6] << "  |  " << boardSpace[7] << "  |  " << boardSpace[8] << std::endl;
}

int main()
{
	NewGame();
	
	system("PAUSE");
}