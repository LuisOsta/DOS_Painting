/*
 * BaseNode.h
 *
 *  Created on: Nov 18, 2017
 *      Author: luiso
 */

#ifndef BASENODE_H_
#define BASENODE_H_

#include <iostream>

using namespace std;

//Luis D. Osta Lugo
//ldo160030
class BaseNode
{
private:
	//the location that the base node is at
	int row;
	int column;

	//what will be painted to the canvas
	//# , * , or space
	//will be the same for all base nodes
	char brush;
public:
	//defaults to 0,0, character defaults to *
	BaseNode();

	//receives the row and column
	BaseNode(int,int);

	//accessors
	int getRow();
	int getColumn();
	char getBrush();

	//mutators
	void setRow(int);
	void setColumn(int);
	void setBrush(char);

	//destructor
	virtual ~BaseNode();

	friend ostream& operator <<(ostream &, const BaseNode&);
};

#endif /* BASENODE_H_ */
