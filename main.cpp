/*********************************************************************************
Title :		main.cpp
Author :	Jonathan Trachtenberg
Created on :	Febuary 23rd, 2018
Description :	main file.
Purpose : 	Calls functions from multiple files.
Usage :		User inputs the .csv file, the .txt file, and the number of total 
		coin flips.
Build with : 	make
Modifications :	None
********************************************************************************/

#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <algorithm>
#include <math.h>
#include "pseudoserver.h"
#include "tree.h"
#include "bitcoin.h"

int main(int argc, char* argv[]){
	if ( 4 != argc ) { 
		cout << "ERROR, NOT ENOUGH ARGUEMENTS" << endl; 
		return 0; 
	}
		
	string input(argv[1]);
	string output(argv[2]);
	float check = atof(argv[3]);
	int seed = atoi(argv[3]);
	
	ifstream in;
	ofstream out;

	in.open(input.c_str());
	out.open(output.c_str());	
	
	if (check != seed) {
		cout << "Seed Not an Integer Error" <<endl;
	}
	if (!in.is_open()) {
		cout << "No Input File Error" << endl;
		return 0;
	}
	if (!out.is_open()) {
		cout << "No Output File Error" << endl;
	}

	Bitcoin mycoin(seed);	
	PseudoServer server;
	string s;

	bool x = true;
	while(x){
		if( 1 == mycoin() ){
			if (!server.read(in)){
				int left_In_Queue = server.queuesize();
				for( int i = 0; i < left_In_Queue; i++ ){
					server.extract(s);
					Tree t(s);
					t.string_With_Tabs = t.write();
					out << t;
				}
				break;
			}
		}
		else {
			if(server.extract(s)){
				server.decrease_Size();	
				Tree t(s);
				t.string_With_Tabs = t.write();	
				out << t;	
			}
			else{
				server.add_Empty();
			}		
		}	
	
	}
	server.report_stats();
}

