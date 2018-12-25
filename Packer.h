/*Packer class that takes in the number of packaging units in the warehouse
 *from the terminal and keeps track of the number of orders currently in the 
 *queue and the total time needed to package all of the orders currently in 
 *the queue.
 */
 
 #ifndef PACKER_H
 #define PACKER_H
 #include "Orderqueue.h"
 
 class Packer{
 
 public:
 
 	//This function is called in the chronokinesis function of the warehouse
 	//and increments by one for every second that has passed, and returns
 	//the amount of time that has passed.
 	int tickPacker();
 	
 	//gets initialized with the number of packing units entered into the 
  	//terminal by the user.
 	int numPackingUnits;
 	
 	void makePackingUnits(int x);
  	
  	 //pointer to an array of packing units
 	Orderqueue *packingUnits;
 	
 	//used to pick what packer has the smallest time left
 	int shortTimeReferee(Orderqueue x[], int size);
 	
 	int getInSummation(Orderqueue *x);
 	
 	//bool toPack(int x);
 	
 	void sendToPackerUnit(int x, Order y);
 	
 	void print(Orderqueue x[], int numPackers, int time);
 	
 	~Packer();
 	
 	Packer();
 	
 private:
 
 	//pointer to the packaging units
 	//Orderqueue *packagingUnits;
 
 	//tracks the number of orders currently being packaged in the queue.
 	int numInQueue;
 
 	//time it takes to process an item (pack time) 
 	int processingTime;
 
 	//unique id of each order.
 	int ID;
 
  	//tracks the total time needed to package all the orders currently in 
  	//the queue by adding all the pack durations of all orders
 	int totalTime;
 
 	//tracks the amount of time elapsed since an order 
 	int timeElapsed;
 
 	//tracks the time left to complete an order
 	int timeLeft;


 
 
 
 };
 
 #endif
