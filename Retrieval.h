/*Retrieval class that tracks whenever an order has arrived. If an order
 *has arrived, it goes to fetch it and then sends it to a packaging
 *unit according to which assignment mode is being used./
 */
 
 #ifndef RETRIEVAL_H
 #define RETRIEVAL_H
 #include "Order.h"
 #include "Orderqueue.h"
 
 class Retrieval{
 
 public:
 	
 	//this function sends orders to the packer class depending on what mode
 	//it is run in.
 	//Order sendToPackaging();
 	
 	Order currOrder;
 	
 	Order copyTop(Orderqueue *x);
 	
 	//top order in the queue
 	//Order orderSend;
 	
 	//instance of orderqueue that contains a queue of orders currently being
	//fetched/processed
 	Orderqueue retrievalQueue;
 
 	Order sendToPacker(Retrieval* y, int x);
 	
 	int fetchTime;
 	
	
 
 
 
 
 private:
 	
 	
 };
 
 #endif
