/******************************************************************************
Title :		tree.h
Author :	Jonathan Trachtenberg
Created on :	Febuary 23rd, 2018
Description :	The Header file for the Tree class.
Purpose : 	This class is for the tree objects that are created through
		reading input from a .csv file. These objects are then stored
		into a queue. Each Tree represents a single line of the input
		file. 
Usage :		Tree
Build with : 	make
Modifications :	Nonee

******************************************************************************/

#include <string>

using namespace std;

#ifndef _Tree_h_
#define _Tree_h_

class Tree{
private:
	string spc_common; // common name of tree
	unsigned int tree_id; // non negative int. Uniquley indentifies the tree
	unsigned int tree_dbh; // non negative int. Tree diameter
	string status; // status of tree. Valid values are ALIVE, DEAD, STUMP
	string health; // health of tree. Valid values are GOOD, FAIR, POOR
	string address; // nearest address to the tree
	string boroname; // Borough of tree. Valid values are MANHATTAN, BRONX, BROOKLYN, QUEENS, STATEN ISLAND 
	unsigned int zipcode; // positive 5 digit int. 00000 - 99999. Zipcode of tree.
	double latitude; // GPS latitude of tree, in decimal degrees.
	double longitude; // GPS longitude of tree, in decimal degrees.
public:
	string string_With_Tabs;; // string of all the member variables seperated by tabs

	Tree(const string & treedata); // Constructor using input from csv dataset file

	/*
	 Prints in output file a single string containingall private members of a Tree object with all
	 fields seperated by commas.
	*/
	friend ostream& operator<<(ostream & os, const Tree & t );

 	string write(); // returns a string from the data members of the Tree object. Members seperated by tabs.
};


#endif
