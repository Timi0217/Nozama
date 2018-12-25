#include <iostream>
#include "Retrieval.h"
#include "Order.h"
#include <string>
using namespace std;

//sends orders to the warehouse once it is time for them to be packaged who
//passes it to the packer.

Order Retrieval::sendToPacker(Retrieval *y, int timehere){
	Order temp;
	if(y -> retrievalQueue.queuePtr[0].arrival_timestamp + 
	y -> retrievalQueue.queuePtr[0].fetch_duration  == timehere){
		temp.id = (y -> retrievalQueue.queuePtr[0]).id;
		temp.arrival_timestamp = 
		(y -> retrievalQueue.queuePtr[0]).arrival_timestamp;
		temp.fetch_duration = 
		(y -> retrievalQueue.queuePtr[0]).fetch_duration;
		temp.pack_duration = 
		(y -> retrievalQueue.queuePtr[0]).pack_duration;
		temp.fetch_time_left = 
		(y -> retrievalQueue.queuePtr[0]).fetch_duration;
		temp.pack_time_left = 
		(y -> retrievalQueue.queuePtr[0]).pack_duration;
		temp.to_pack = true;
		y -> retrievalQueue.deQueue(0);
		return temp;
	}
	else{
		temp.to_pack = true;
		return temp;
	}
}

//copies an order
Order Retrieval::copyTop(Orderqueue* x){
	Order mimic;
	mimic = x -> returnOrder(0);
	return mimic;		
}

