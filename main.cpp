#include <iostream>
#include <string>
#include "BaseNode.h"
#include "GridNode.h"
#include "Grid.h"
#include <fstream>

//Luis D. Osta Lugo
//ldo160030

using namespace std;

//draws the vertical line to the paint file
void drawVertical(Grid *&grid, bool pen_status, char brush, int movement, string direction)
{
	//if the pen is up
	if(pen_status==false)
	{
		//loops through each row the user wants the pen to move up
		for(int x =0;x<movement;x++)
		{
			if(direction=="N")
			{
				//moves the cursor 52 bytes to the left
				//which is equal to one row up
				grid->setCurrent(grid->getCurrent()->getUp());
			}
			//south
			else
			{
				//moves the cursor 52 bytes to the right
				//which is equal to one row down
				grid->setCurrent(grid->getCurrent()->getDown());
			}
		}
	}
	//if the pen is down(when it can draw)
	else
	{
		//loops through each row the user wants the pen to move up and fills each
		//cell with either * or #
		for(int x =0;x<movement;x++)
		{
            if(direction=="N")
            {
            	grid->setCurrent(grid->getCurrent()->getUp());
            	grid->getCurrent()->setBrush(brush);
            }

            //south
            else
            {
            	grid->setCurrent(grid->getCurrent()->getDown());
            	grid->getCurrent()->setBrush(brush);
            }
		}
	}
}

//draws the horizontal line to the paint file
void drawHorizontal(Grid *&grid, bool pen_status, char brush, int movement, string direction)
{
	//if the pen is up
	if(pen_status==false)
	{
		for(int x =0;x<movement;x++)
		{
			//if the direction is to the right
			if(direction=="E")
			{
				grid->setCurrent(grid->getCurrent()->getRight());
			}
			//if the direction is to the left
			else
			{
				grid->setCurrent(grid->getCurrent()->getLeft());
			}
		}
	}
	//if the pen is down(and can draw)
	else
	{
		//loops through each row the user wants the pen to move up and fills each
		//cell with either * or #
		for(int x =0;x<movement;x++)
		{
		    if(direction=="E")
		    {
		        grid->setCurrent(grid->getCurrent()->getRight());
		        grid->getCurrent()->setBrush(brush);
		    }

		    //west
		    else
		    {

		        grid->setCurrent(grid->getCurrent()->getLeft());
		        grid->getCurrent()->setBrush(brush);
		    }
		}
	}

}

//checks whether the vertical move is valid
bool validMoveVert(Grid *&grid, string direction, int movement)
{
	bool valid = true;

	//if the movement will get it passed the lower boundery
	if(grid->getCurrent()->getRow()+movement>=50&&direction=="S")
	{
		valid = false;
	}
	//if the movement will get it passed the lower boundery
	if(grid->getCurrent()->getRow()-movement<0&&direction=="N")
	{
		valid = false;
	}


	return valid;
}

//checks whether the horizontal move is valid
bool validMoveHor(Grid *&grid, string direction, int movement)
{
	bool valid = true;

	//if the movement will get it passed the rightmost boundery
	if(grid->getCurrent()->getColumn()+movement>=50&&direction=="E")
	{
		valid = false;
	}
	//if the movement will get it passed the leftmost boundery
	if(grid->getCurrent()->getColumn()-movement<0&&direction=="W")
	{
		valid = false;
	}

	return valid;
}
int main()
{
	//boolean
	bool pen_status = false;
	char brush = '*';

	//text files
	string inputName = "commands.txt";
	string outputName = "paint.txt";

	//The grid that the painting will be done on
	Grid* grid = new Grid();

	//the input and output files
	ifstream inputFile;
	ofstream outputFile;

	//opens the files
	inputFile.open(inputName.c_str());
	outputFile.open(outputName.c_str());

	if(inputFile.fail())
	{
		cout<<"Error opening the input file in main."<<endl;
	}

	if(outputFile.fail())
	{
		cout<<"Error opening the input file in main."<<endl;
	}

	string line;

	getline(inputFile,line);

	while(inputFile)
	{
		//sets the command to the first character of line
				string command = line.substr(0,1);

				//checks if the command asked for the pen to be bolded
				if(command=="B")
				{
					brush = '#';
				}

				//checks if the command asked for the pen to be unbolded
				else if(command=="b")
				{
					brush = '*';
				}

				//Logic for the numbered commands
				else
				{
					//switches in between every numbered commnad
					//converts the string into an integer
					int c = stoi(command);
					switch(c)
					{
						//The pen is up and so CAN'T draw
						case 1:
						{
							pen_status = false;
							break;
						}
						//the pen is down and so it CAN draw
						case 2:
						{
							pen_status = true;
							break;
						}
						//drawing/movement command
						case 3:
						{
							//gets the direction and the movement of the line
							string direction = line.substr(2,1);
							int movement = stoi(line.substr(4,5));

							//draw call for north and south
							if(direction=="N"||direction=="S")
							{
								//calls the function to make sure
								//the movement doesn't take the brush out of bounds
								if(validMoveVert(grid,direction,movement))
								{
									drawVertical(grid,pen_status,brush,movement,direction);
								}
							}
							//draw call for west and east
							else
							{
								//calls the function to make sure
								//the movement doesn't take the brush out of bounds
								if(validMoveHor(grid,direction,movement))
								{
									drawHorizontal(grid,pen_status,brush,movement,direction);
								}

							}

							break;
						}

						//prints the paint file into the console

						case 4:
						{
							cout << *grid << endl;
							break;
						}

						default:
							break;

					}

				}
				getline(inputFile,line);
	}
	outputFile << *grid;

	return 0;
}
