#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include <vector>
#include <array>


struct Pos
{
protected:
	int row;
	int collumn;
public:

	int returnPos()
	{
		//Take into account how arrays work in C++ by minusing by 1, as 0 is the first
		//element in an array.
		return ((this->row - 1) * 5) + this->collumn - 1;
	}

	//Determine Beginning of Maze
	void genBeginning()
	{

		int RoworCollumns = 1 + (rand() % 2);
		Pos Entrance;
		if (RoworCollumns == 1)
		{
			do
			{
				Entrance.row = 1 + (rand() % 5);
				Entrance.collumn = 1 + (rand() % 5);
			} while (Entrance.row != 1 && Entrance.row != 5);
		}
		if (RoworCollumns == 2)
		{
			do
			{
				Entrance.row = 1 + (rand() % 5);
				Entrance.collumn = 1 + (rand() % 5);
			} while (Entrance.collumn != 1 && Entrance.collumn != 5);
		}
		this->row = Entrance.row;
		this->collumn = Entrance.collumn;
	}


	//Determine Ending of Maze
	void genExit()
	{

		int RoworCollumns = 1 + (rand() % 2);
		Pos Exit;
		if (RoworCollumns == 1)
		{
			do
			{
				Exit.row = 1 + (rand() % 5);
				Exit.collumn = 1 + (rand() % 5);
			} while (Exit.row != 1 && Exit.row != 5);
		}
		if (RoworCollumns == 2)
		{
			do
			{
				Exit.row = 1 + (rand() % 5);
				Exit.collumn = 1 + (rand() % 5);
			} while (Exit.collumn != 1 && Exit.collumn != 5);
		}
		this->row = Exit.row;
		this->collumn = Exit.collumn;
	}


};

class Maze {
protected:
	std::array<char, 25> mazeField;
	int Start;
	int End;
public:
	//Create/Randomize Maze
	Maze()
	{

		for (int i = 0; i < this->mazeField.size(); i++)
		{
			this->mazeField[i] = '#';
		}
	}
	//Destroy Maze
	~Maze()
	{
		for (int i = 0; i < this->mazeField.size(); i++)
		{
			this->mazeField[i] = '#';
		}

	}

	void PrintMaze()
	{
		for (int i = 0; i < this->mazeField.size() / 5; i++)
		{
			for (int j = 0; j < this->mazeField.size() / 5; j++)
			{
				std::cout << this->mazeField[i * 5 + j];
			}
			std::cout << std::endl;
		}
	}
	void setCharMaze(int pos, char type)
	{

		this->mazeField[pos] = type;

	}
	void setExit(int exit)
	{

		this->mazeField[exit] = '$';

	}
	void setStart(int start)
	{

		this->mazeField[start] = '=';

	}

};


void main()
{
	while(!GetAsyncKeyState(VK_END))
	{
		if (GetAsyncKeyState(VK_INSERT))
		{
			Maze newMaze;
			Pos Exit, Entrance;
			do
			{
				Exit.genExit();
				Entrance.genBeginning();
			} while (Exit.returnPos() == Entrance.returnPos());
			newMaze.setExit(Exit.returnPos());
			newMaze.setStart(Entrance.returnPos());
			newMaze.PrintMaze();
			std::cout << std::endl;
		}
	}

}