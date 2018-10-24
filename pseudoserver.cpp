/*********************************************************************************
Title :		pseudoserver.cpp
Author :	Jonathan Trachtenberg
Created on :	Febuary 23rd, 2018
Description :	The .cpp file for the PseudoServer class.
Purpose : 	Defines the methods declared in the PseudoServer Class found 
		in the pseudoserver.h file.
Usage :		PseudoServer
		read(istream & is)	Checks if there is another line in the
					file and if there is, copys it and 
					calls enqueue.
		extract(string & s)	Checks if queue is empty, if not then
					pops a value from the queue and and
					stores it into the string that was
					passed as a parameter. Also decreases
					queueSize by one. Meant for use before
					EOF
		queuesize()		Returns the size of the queue.
		final_extract(string&s)	Same as extract(string & s) but for use
					after the EOF. DOES NOT DECREASE queSize.			
		enqueue() + dequeue	Standard queue operations.
		report_stats()		Reports the queue statistics.	
Build with : 	make
Modifications :	Nonee
********************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
#include "pseudoserver.h"

using namespace std;

bool PseudoServer::read(istream & is){
	string next_Line;
	int check_Next_Line = is.peek();
		if( -1 == check_Next_Line ){	
        	        return false;
		}
		else{
			getline(is,next_Line);
			enqueue(next_Line);
	        	return true;

		}
}

void PseudoServer::decrease_Size() {
	queSize--;
        sizes.push_back(queSize);
}

void PseudoServer::add_Empty(){
        queEmpt++;
	sizes.push_back(queSize);
}

bool PseudoServer::extract(string & s){	
	if ( NULL != head ){	
		s = head->input;
		dequeue();
		return true;
	}
	else{
		return false;
	}
}

int PseudoServer::queuesize(){
	return queSize;
}

void PseudoServer::enqueue(const string & s){

	queNode * added_Node = new queNode(s);	
	if ( NULL == head ){
		head = added_Node;
		rear = added_Node;
	}

	else{	
		rear->next = added_Node;
		rear = added_Node;
	}

	queSize++;
	sizes.push_back(queSize);
	if (queSize > queMax){
		queMax = queSize;
	}
}

void PseudoServer::dequeue(){
	if ( head == rear) {
		delete head;
		rear = NULL;
		head = NULL;
	}
	else {
		queNode * temp = head;
		head = temp->next;
		delete temp;
		temp = NULL;	
	}
}
void PseudoServer::report_stats(){
	float sum = accumulate(sizes.begin(),sizes.end(),0);
	float average = sum / sizes.size();
	
	cout << "average queue size: " << average << endl;
	cout << "maximum queue size: " << queMax  << endl;
        cout << "empty queue count:  " << queEmpt << endl;
        cout << "queue size on eof:  " << queSize << endl;
}
