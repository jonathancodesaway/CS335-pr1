/******************************************************************************
Title :		tree.cpp
Author :	Jonathan Trachtenberg
Created on :	Febuary 23rd, 2018
Description :	The .cpp file for the Tree class. 
Purpose : 	Defines the methods of the Tree class which are declared in the
		Tree.h file.
Usage :		Tree		Creates a new Tree object.
		<< operator	Prints all private members of a Tree object
				into a given ostream in order.	
		write()		Returns a string of member variables, seperated
				by tabs, in order.  
		Call to create a new server.
Build with : 	make
Modifications :	Nonee


******************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "tree.h"
#include "stdlib.h"

using namespace std;


Tree::Tree(const string & treedata){

	stringstream ss(treedata);
	string token;
	int i = 1;
	while(getline(ss, token)){
		const char *begin = token.c_str();
		bool good = true;
		for (const char * p = begin; *p; p++) {
			if ( '"' == *p ){
				good = !good;
			}
			else if ( (',' == *p) && (good) ){
				string t = string(begin, p-begin);
				switch (i){
                        		case 1 : tree_id = stoi(t); break;
                        		case 4 : tree_dbh = stoi(t); break;
          	                        case 7 : status = t; break;
                                        case 8 : health = t; break;
                                        case 10 : spc_common = t; break;
                                        case 25 : address = t; break;
                                        case 26 : zipcode = stoi(t); break;
                                        case 29 : boroname = t; break;
                                        case 38 : latitude = stod(t); break;
                                        case 39 : longitude = stod(t); break;
				}	
				i++;
				begin = p+1;	
			}
		}
	}
}

ostream& operator<<(ostream & os, const Tree & t){

string send = t.string_With_Tabs;
replace( send.begin(), send.end(), '	' , ',' );

os << send << endl;

return os;
}


string Tree::write(){
		
	string s;
	stringstream ss;
	ss << setfill('0') << setw(5) << zipcode;
	s += spc_common;
	s += '	';
	s += to_string(tree_id);
	s += '	';
	s += to_string(tree_dbh);
	s += '	';
	s += status;
        s += '	';
	s += health;
        s += '	';
	s += address;
        s += '	';
	s += boroname;
        s += '	';
	s += ss.str();
        s += '	';
	s += to_string(latitude);
        s += '	';
	s += to_string(longitude);

return s;
}





