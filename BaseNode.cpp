/*
 * BaseNode.cpp
 *
 *  Created on: Nov 18, 2017
 *      Author: luiso
 */

#include "BaseNode.h"
#include <iostream>

using namespace std;

//Luis D. Osta Lugo
//ldo160030

//default constructor
BaseNode::BaseNode()
{
	row = 0;
	column = 0;
	brush = ' ';
}

//constructor that receives the location
BaseNode::BaseNode(int r, int c)
{
	row = r;
	column = c;
	brush = ' ';
}

BaseNode::~BaseNode()
{
	// TODO Auto-generated destructor stub
}


//accessors for the member variables
int BaseNode::getRow()
{
	return row;
}

int BaseNode::getColumn()
{
	return column;
}

char BaseNode::getBrush()
{
	return brush;
}


//mutators
void BaseNode::setRow(int r)
{
	row = r;
}

void BaseNode::setColumn(int c)
{
	column = c;
}

void BaseNode::setBrush(char b)
{
	if(brush!='#')
	{
		brush = b;
	}
}

ostream& operator <<(ostream &output, const BaseNode& node)
{
	output << node.brush;

	return output;
}

