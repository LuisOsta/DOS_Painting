/*
 * GridNode.h
 *
 *  Created on: Nov 18, 2017
 *      Author: luiso
 */

#ifndef GRIDNODE_H_
#define GRIDNODE_H_

#include "BaseNode.h"
#include <iostream>

//Luis D. Osta Lugo
//ldo160030

using namespace std;

class GridNode: public BaseNode
{
private:
	//pointers to access all the other GridNodes surrounding it
	GridNode *up;
	GridNode *right;
	GridNode *down;
	GridNode *left;

public:
	//default constructor, makes them all null, and calls the default BaseNode constructor
	GridNode();

	//constructor that receives a set of Indexes
	GridNode(int,int);

	//accessors
	//returns the respective adjacent pointeres
	GridNode* getUp();
	GridNode* getRight();
	GridNode* getDown();
	GridNode* getLeft();

	//mutators
	void setUp(GridNode *);
	void setRight(GridNode *);
	void setDown(GridNode *);
	void setLeft(GridNode *);




	virtual ~GridNode();
};

#endif /* GRIDNODE_H_ */
