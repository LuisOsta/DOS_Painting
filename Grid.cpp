/*
 * Grid.cpp
 *
 *  Created on: Nov 18, 2017
 *      Author: luiso
 */

#include "Grid.h"
#include "GridNode.h"
#include <iostream>


//Luis D. Osta Lugo
//ldo160030
using namespace std;

Grid::Grid()
{
	head = new GridNode(0,0);
	painting = false;

	//creates the memory for the current node
	//then moves it to point to the head
	current = new GridNode();
	current = head;
	//calls the createGrid function
	createGrid();
	// TODO Auto-generated constructor stub

}

//a second constructor that receives an already created grid
Grid::Grid(GridNode* h)
{
	head = h;
	painting = false;
	current = head;
	//copies the rest of the constructor
}

Grid::~Grid()
{
	//go through each node in the 50X50 canvas
	//and delete it
	// TODO Auto-generated destructor stub
}

GridNode* Grid::getHead()
{
	return head;
}

void Grid::setHead(GridNode *node)
{
	head = node;
}

//Creates a new 50X50 grid
void Grid::createGrid()
{
	GridNode* row1 = head;
	GridNode* row2;

	GridNode* p;

	//creates the first row
	for(int x =1;x<50;x++)
	{
		//creates a new gridnow
		p = new GridNode(0,x);
		//the new node will be set to the right of row1
		p->setLeft(row1);
		row1->setRight(p);

		//moves row1 to the next one
		row1 = row1->getRight();
	}

	//resets the row back to the head
	row1  = head;

	//creates rows 2 - 50
	for(int x = 1;x<50;x++)
	{
		//row2 will always point to the new row to be set
		//since row2 is the beginning node in the row
		//the coordinates will begin with 0, then with x-1
		row2 = new GridNode(x,0);
		//connects the rows vertically
		//row2 is the one below row 1
		row2->setUp(row1);
		row1->setDown(row2);

		//moves row1 to the next row
		row1 = row2;

		//creates the next row
		//row2 will always represent the previous node
		//here the columns of the row are created
		for(int y = 1;y<50;y++)
		{
			p = new GridNode(x,y);

			//connects the new node to the previous one
			p->setLeft(row2);
			row2->setRight(p);

			//NOTE: row2.getUp().getRight()
			//refers to the node right above the current node we're creating

			//connect the new node to the one above it
			p->setUp(row2->getUp()->getRight());

			//sets the down, to the node above, to P
			row2->getUp()->getRight()->setDown(p);

			row2 = p;
		}


	}

	//end of the loop that creates rows 2-50
}

ostream& operator<<(ostream &output, const Grid &grid)
{
	//print out the grid
	GridNode* row = grid.head;
	GridNode* node = grid.head;

	for(int x =0;x<50;x++)
	{
		for(int y = 0;y<50;y++)
		{

			output<<*node;
			node = node->getRight();
		}
		output<<"\n";
		node = row->getDown();
		row = row->getDown();
	}
	return output;
}

GridNode* Grid::getCurrent()
{
	return current;
}

void Grid::setCurrent(GridNode *node)
{
	current = node;
}
