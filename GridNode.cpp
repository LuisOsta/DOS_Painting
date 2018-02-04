/*
 * GridNode.cpp
 *
 *  Created on: Nov 18, 2017
 *      Author: luiso
 */

#include "GridNode.h"

//Luis D. Osta Lugo
//ldo160030

GridNode::GridNode():BaseNode()
{
	up = nullptr;
	right = nullptr;
	down = nullptr;
	left = nullptr;

}

GridNode::GridNode(int a, int b):BaseNode(a,b)
{
	up = nullptr;
	right = nullptr;
	down = nullptr;
	left = nullptr;

}
GridNode::~GridNode()
{

}


//accessors for the attributes
GridNode* GridNode::getUp()
{
	return up;
}

GridNode* GridNode::getRight()
{
	return right;
}

GridNode* GridNode::getDown()
{
	return down;
}

GridNode* GridNode::getLeft()
{
	return left;
}

//mutators for the attributes
void GridNode::setUp(GridNode *node)
{
	up = node;
}

void GridNode::setRight(GridNode *node)
{
	right = node;
}

void GridNode::setDown(GridNode *node)
{
	down = node;
}

void GridNode::setLeft(GridNode *node)
{
	left = node;
}
