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



	//Determine Ending of Maze
	void genExit()
	{
		Pos Exit;
		do
		{
			Exit.row = 1 + (rand() % 5);
			Exit.collumn = 1 + (rand() % 5);
		} while (Exit.row != 1 && Exit.row != 5 || Exit.collumn != 1 && Exit.collumn != 5);

		this->row = Exit.row;
		this->collumn = Exit.collumn;
	}


};

class Maze {
protected:
	std::array<char, 25> mazeField;
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

};


void main()
{
	Maze newMaze;
	Pos Exit;
	Exit.genExit();
	newMaze.setCharMaze(Exit.returnPos(), '$');
	newMaze.PrintMaze();
}