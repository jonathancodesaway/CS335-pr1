/******************************************************************************

Title :		pseudoserver.h
Author :	Jonathan Trachtenberg
Created on :	Febuary 23rd, 2018
Description :	The Header file for the PseudoServer class.
Purpose : 	This class contains its own internal queue as well as functions
		to track the queues stats. The queue takes in nodes which are 
		built using input from a .csv file.
Usage :		PseudoServer
		Call to create a new server.
Build with : 	
Modifications :	Nonee

******************************************************************************/

#include <string>
#include <vector>
using namespace std;
#ifndef pseudo_h_
#define pseudo_h_

class PseudoServer{
private:
	
	struct queNode{
		string input;		// This is a string that contains all values from a line of the .csv file.
		queNode * next;		// Connects one node to the next one.
		queNode ( string s ) { input = s; next = NULL; }; // Constructor for Node
	};
	queNode *head;  // head of queue.
	queNode *rear;  // rear of queue.
	int queSize;    // Current size of queue.
	int queEmpt;	// Amount of times the queue was empty when extraction was attempted.
	int queMax;	// Max size of the queue during runtime.
	

public:
	vector <int> sizes; // stores all sizes of the queue over time until the eof.

	//Constructor and Destructor
	PseudoServer() { head = rear = NULL; queSize = 0; queMax = 0; queEmpt = 0; };
	~PseudoServer() { queNode * temp; while( head != NULL) {temp = head; head = head->next; delete temp; } rear == NULL; };
	
	// Basic queue functions
	void enqueue( const string & s ); // add into queue, at the rear.
	void dequeue();			  // remove from queue, at the head.
	
	/*  
	if another line of text is available for reading in the open input stream passed into the function as a parameter, 
	create a new Node for the queue using the next line and insert that Node into the queue. Return true. 
	if no other line, return false.
	*/
	bool read(istream & is); 
	
	/*
	 if queue is not empty, take head node of queue, copy the nodes string value into the string parameter and return true. 
	 Else retun false.
	*/	
	bool extract(string & s);
	
	int queuesize(); // return # of elements in queue 
        
	void report_stats(); // Used to report Stats
	void decrease_Size(); // Decreases the size of the queSize counter.
	void add_Empty(); // Increases the size of the queEmpt counter.
};

#endif
