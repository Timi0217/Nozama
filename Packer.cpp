#include <iostream>
#include "Packer.h"
#include <cstdlib>
using namespace std;

//an array of packaging units initialized with a number of packers(queues) 
//declared by the user

//this should be in a function
//packagingUnits = new Orderqueue[numPackingUnits];

//an array of packing units(queues/sequences)
Packer::Packer(){

}

Packer::~Packer(){
//	delete [] packingUnits;
}

void Packer::makePackingUnits(int x){
	packingUnits = new Orderqueue[x];
}

//this returns the queue in the array of orderqueues with the shortest time
int Packer::shortTimeReferee(Orderqueue x[], int size){
//orderqueue passed in is a dead squirell
	cerr << "Size is " << size <<endl;
	int winningPacker = 100000;
	Orderqueue *temp;
	for(int i = 0; i < size; i++){
		temp = &x[i];
		if(winningPacker > getInSummation(temp)){
			winningPacker = getInSummation(temp);
		}
	}
	return winningPacker;
}

//gets the sum of the pack durations in each orderqueue 
//in an array of orderqueues
int Packer::getInSummation(Orderqueue *x){
	//im passing in a dead squirell order array in here
	int sum = 0;
	//y is a dead squirell
	int y = x -> numberOrders();
	for(int i = 0; i < y; i++){
		sum += x -> queuePtr[i].pack_duration;
	}
	return sum;
}

void Packer::sendToPackerUnit(int x, Order y){
	packingUnits[x].enQueue(y);  
}

/*
bool Packer::toPack(int x){
	if(packingUnits[x].queuePtr[0].pack_time_left == 0){
		packingUnits[x].queuePtr[0].toPack = true;
	}
	else{
		packingUnits[x].queuePtr[0].toPack = false;
	}
}
*/

void Packer::print(Orderqueue travel[], int numPackers, int time){
	cerr << travel[0].queuePtr[0].pack_time_left << endl;
	int timeMean = 0;
	for(int i = 0; i < numPackers; i++){
		if(travel[i].queuePtr[0].pack_time_left == 0 && 
		travel[i].queuePtr[0].to_pack == true){
			int orderTime;
			orderTime = 
			travel -> queuePtr[0].arrival_timestamp-time;
			int orderNum = travel -> queuePtr[0].id;
			cout << "<Order(" << orderNum <<") arrival_timestamp = "
			<< travel -> queuePtr[0].arrival_timestamp
			<<" fetch_duration = "
			<< travel -> queuePtr[0].fetch_duration
			<< " pack_duration = "
			<< travel -> queuePtr[0].pack_duration
			<< " total_time = "
			<< orderTime << ">" << endl;
			timeMean = timeMean += orderTime;
			cerr << "whahahah" <<endl;
			cerr << "whahahah" <<endl;
			travel[i].deQueue(0);	
		}
		else{
			travel[i].queuePtr[0].pack_time_left -= 1;
			cerr << travel[i].queuePtr[0].pack_time_left << endl;	
		}
	}
}
