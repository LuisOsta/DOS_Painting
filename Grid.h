/*
 * Grid.h
 *
 *  Created on: Nov 18, 2017
 *      Author: luiso
 */

#ifndef GRID_H_
#define GRID_H_

//Luis D. Osta Lugo
//ldo160030

#include "GridNode.h"
#include <iostream>

using namespace std;



class Grid
{
private:
	GridNode *head;

	//defaults to false
	//sets true when the brush is DOWN
	bool painting;

	//holds the current location of the brush
	GridNode *current;

public:
	//creates the 50X50 grid, sets all of the default values
	Grid();
	//makes head point to the received pointer
	Grid(GridNode*);

	//creates the grid
	void createGrid();


	//accessors
	GridNode* getHead();

	//mutators
	void setHead(GridNode *);

	//prints out the grid
	friend ostream& operator << (ostream &, const Grid &);

	GridNode* getCurrent();

	void setCurrent(GridNode* node);

	virtual ~Grid();
};

#endif /* GRID_H_ */
