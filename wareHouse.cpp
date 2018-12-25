#include <iostream>
#include "wareHouse.h"
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

//reads the data into a warehouse's queue from a file
//void wareHouse::populateWareHouse(){
//	wareHouseQueue.readData(string filename);
//}
	
//function that sends to packer and keeps track of time passed since it fetched
//and packed, also takes in the number of packing units to be made

//need to send from warehousequeue to goldenretrieverqueue

wareHouse::wareHouse(){

}

void wareHouse::chronoKinesis(string File, int numPackers, string method){
	//warehouse queue has been made and sent a queue of order
	Order x;
	robinHood = 0;
	numOrders = 0;
	readData(File);
	cerr << "order sent to warehouse" << endl;
	time = 0;
	packerNum = 0;
	timeMean = 0;
	timeMax = 0;
	timeMin = 10000;
	//read data here
	//make a number of packing units
	mailServices.makePackingUnits(numPackers);
	//warehousequeue copy and pasted to retrieval's queue
	Retrieval *temp;
	Orderqueue *temp2;
	temp = &goldenRetriever;
	temp2 = &wareHouseQueue;
	//remember to access these queues using these pointers
	while(true){;
		//sends to fetcher at the arrival times
		copyQueue(temp2, temp, time);
		//works up to here fine

		if(temp -> retrievalQueue.isEmpty() == false){
			if(temp -> retrievalQueue.queuePtr[0].to_pack == false){
				x = temp -> sendToPacker(temp, time );
				x.to_pack = true;
			}
		}
		if(method == "ROUND_ROBIN"){
			packerGet = roundRobin(robinHood, numPackers);
		}
		cerr << "comparing x.to_pack" << endl;
		if(x.to_pack == true){
			x.to_pack = false;
			mailServices.sendToPackerUnit(packerGet, x);
		}
		
		if (check > 0){
			for (int i = 0; i < numPackers; i++){
				shipOff(&mailServices.packingUnits[packerNum], 
				numPackers, time);
			}
		}
		
		deductPackTime(mailServices);
		
		time += 1;
		
		cerr << "about to call poison apple" << endl;
		cerr << poisonApple(numPackers, mailServices, temp) << endl;
		cerr << "call poison apple once " << endl;
		cerr << "about to enter if stmnt" << endl;
		if(poisonApple(numPackers, mailServices, temp) == true 
		   && temp2 -> isEmpty() == true
                   && temp -> retrievalQueue.isEmpty() == true){
			return;
		}
		
	}
}

void wareHouse::copyQueue(Orderqueue *x, Retrieval *y, int time){
	if(x -> isEmpty() != true){
		cerr << time << endl;
		int arrivalt = x -> queuePtr[0].arrival_timestamp;
		if(arrivalt == time){
			Order temp;
			temp.id = (x -> queuePtr[0]).id;
			temp.arrival_timestamp = (x -> queuePtr[0]).arrival_timestamp;
			temp.fetch_duration = (x -> queuePtr[0]).fetch_duration;
			temp.pack_duration = (x -> queuePtr[0]).pack_duration;
			temp.fetch_time_left = (x -> queuePtr[0]).fetch_duration;
			temp.pack_time_left = (x -> queuePtr[0]).pack_duration;
			temp.to_pack = false;
			y -> retrievalQueue.enQueue(temp);
			x -> deQueue(0);
		}
	}
}

//didn't initialize time mean
//what is num?
void wareHouse::shipOff(Orderqueue *toShip, int num, int time){
(void) num;
//The issue is that i starts at 1 instead of 0 
	iterate = 0;
		if(toShip -> queuePtr[0].pack_time_left == 0){
			//if(iterate == 0){
			//	i = 0;
			//}
			//cerr << "This is i inside loop" << i << endl;
			numOrders -= 1;
			orderTime=toShip -> queuePtr[0].arrival_timestamp-time;
			toShip -> queuePtr[0].pack_time_left -= 1;
			int orderNum = toShip -> queuePtr[0].id;
			//cerr << "This is i inside loop" << i << endl;
			cout << "<Order(" << orderNum <<") arrival_timestamp = "
			<< toShip -> queuePtr[0].arrival_timestamp
			<<" fetch_duration = "
			<< toShip -> queuePtr[0].fetch_duration
			<< " pack_duration = "
			<< toShip -> queuePtr[0].pack_duration
			<< " total_time = "
			<< orderTime << ">" << endl;
			timeMean = timeMean += orderTime;
			toShip -> deQueue(0);
			iterate += 1;
		}
		if(timeMin > orderTime){
			timeMin = orderTime;
		}
		if(timeMax < orderTime ){
			timeMax = orderTime;
		}
		
	printTimeHelp(timeMean, timeMin, timeMax, numOrders);
	cout << endl;
}

//sends to packer class using whatever method specified
int wareHouse::roundRobin(int x, int packerNum){
	if(x == packerNum){
		x = 0;
	}
	x += 1;
	return x;

}


void wareHouse::printTimeHelp(int mean, int min, int max, int order){
	cout << "min elapsed time " << min << " minutes" << endl;
	cout << "max elapsed time " << min << " minutes" << endl;
	//cout << "mean elapsed time " << mean/order << " minutes" << endl;
	cout << order << " orders processed" << endl;
	(void) mean;
	(void) max;
}

int wareHouse::checkPackingUnits(Packer dummy, int x){
	int count = 0;
	for(int i = 0; i < x; i++){
		if(dummy.packingUnits[i].isEmpty() == true){
			count += count;
		}
		else{
			count += 1;
		}
	}
	return count;
}

bool wareHouse::poisonApple(int x, Packer dummy, Retrieval *holder){
	if(checkPackingUnits(dummy, x) == 0 ||
				 holder -> retrievalQueue.isEmpty() == true){
		return true;
	}
	else{
		return false;
	}
}

//figures out which queue has the shortest time left
int wareHouse::shortestTime(int y){
	int x;
	cout << "This is y " << y << endl;
	//problem is here! what I'm passing in as a parameter
	x = mailServices.shortTimeReferee(mailServices.packingUnits, y);
	cout << "This is y " << y << endl;
	return x;
}



//reads data in from a file
void wareHouse::readData(string filename){
	Parser p(filename);
	while (!p.is_done()){
		Order order = p.read_order();
		wareHouseQueue.enQueue(order);
	}
}

//not being initialized with values is the issue
//helper function to copy the queue in a warehouse to the retrieval's

void wareHouse::deductPackTime(Packer x){
		x.packingUnits[0].queuePtr[0].pack_time_left -= 1;
}

/*
void wareHouse::shipOff(Packer *toShip[], int num, int time){
	for(int i = 0; i < num; i++){
		if(toShip -> packingUnits[i].queuePtr[0].pack_time_left == 
		0 || toShippackingUnits[i].queuePtr[0].to_pack == true ){
			numOrders -= 1;
			orderTime=
			toShip.packingUnits[i].queuePtr[0].arrival_timestamp-
			time;
			toShip.packingUnits[i].queuePtr[0].pack_time_left -= 1;
			int orderNum = toShip.packingUnits[i].queuePtr[0].id;
			cout << "<Order(" << orderNum <<") arrival_timestamp = "
			<< toShip.packingUnits[i].queuePtr[0].arrival_timestamp
			<<" fetch_duration = "
			<< toShip.packingUnits[i].queuePtr[0].fetch_duration
			<< " pack_duration = "
			<< toShip.packingUnits[i].queuePtr[0].pack_duration
			<< " total_time = "
			<< orderTime << ">" << endl;
			timeMean = timeMean += orderTime;
			cerr << "whahahah" <<endl;
			toShip.packingUnits[i].deQueue(0);
			cerr << "whahahah" <<endl;
		}
		if(timeMin > orderTime){
			timeMin = orderTime;
		}
		if(timeMax < orderTime ){
			timeMax = orderTime;
		}
	}
	cerr << "here?" << endl;
	printHelp(timeMean, timeMin, timeMax, numOrders);
	cout << endl;
}
*/









