#include <iostream>
#include <fstream>
#include "Orderqueue.h"
#include <string>

using namespace std;

/*Orderqueue()
 *purpose: creates an empty sequence
 *parameters: none
 *return: none
 */
Orderqueue::Orderqueue(){
	queuePtr = new Order[1];
	currSize = 0;
	numOrders = 0;
}

/*~Orderqueue()
 *purpose: deletes allocated memory
 *parameters: none
 *return: none
 */
Orderqueue::~Orderqueue(){
	delete [] queuePtr;
}

/*enQueue()
 *purpose: adds an order to a queue
 *parameters: an order
 *return: none
 */
void Orderqueue::enQueue(Order x){
	if (currSize == numOrders){
		expand();
	}
	
	queuePtr[numOrders].id = x.id;
	queuePtr[numOrders].arrival_timestamp = x.arrival_timestamp;
	queuePtr[numOrders].fetch_duration = x.fetch_duration;
	queuePtr[numOrders].pack_duration = x.pack_duration;
	queuePtr[numOrders].fetch_time_left = x.fetch_duration;
	queuePtr[numOrders].pack_time_left = x.pack_duration;
	queuePtr[numOrders].to_pack = false;
	numOrders += 1;
	cerr <<"ID of order sent to queue " <<queuePtr[numOrders - 1].id << endl;
	cerr <<"fetch time left of order sent to queue " <<queuePtr[numOrders - 1].fetch_time_left << endl;
}

/*deQueue()
 *purpose: removes an order from a given index in the queue
 *parameters: index of order to be removed
 *return: none
 */
void Orderqueue::deQueue(int x){
	cerr <<"ID of order dequeued " <<queuePtr[x].id << endl;
	for (int i = x; i < numOrders - 1; i++){
	queuePtr[i] = queuePtr[i + 1];
	}
	numOrders -= 1;
}


/*expand()
 *purpose: expands the size of the queue
 *parameters: none
 *return: none
 */
void Orderqueue::expand(){
	int newSize = (currSize * 2) + 2;
	Order* temp = new Order [newSize];
	for(int i = 0; i < currSize; i++){
		temp[i] = queuePtr[i];
	}
	delete [] queuePtr;
	currSize = newSize;
	queuePtr = temp;
}

/*isEmpty()
 *purpose: checks whether or not a queue is empty
 *parameters: none
 *return: none
 */
bool Orderqueue::isEmpty(){
	if (numOrders < 1){
		return true;
	}
	else{
		return false;
	}
}


Order Orderqueue::returnOrder(int x){
	return queuePtr[x];
}


//returns the size of the queue
int Orderqueue::numberOrders(){
	return numOrders;
}

int Orderqueue::size(){
	return currSize;
}

int Orderqueue::print(int x){
	return queuePtr[x].id;
}
