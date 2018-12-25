/*This class takes care of creating a queue to hold all the orders, and then
 *sending them to the retrieval class based on their arrival timestamp and 
 *fetch duration
 */
 
 #ifndef WAREHOUSE_H
 #define WAREHOUSE_H
 #include "Orderqueue.h"
 #include "Retrieval.h"
 #include "Packer.h"
 #include "Parser.h"
 
 class wareHouse{
 
 public:
 	//constructor of the warehouse that starts the process of nozama online
 	wareHouse();
 	
 	void readData(std::string filename);
 	
 	void printTimeHelp(int mean, int min, int max, int order);
 	
 	//This function simulates a clock and helps to keep 
 	//track of processing and packing times. would be done with an infinite
 	//while loop that is stopped when all queues are empty.
 	//would also call a tick function in other classes that let them 
 	//know how much time has passed
 	void chronoKinesis(string file, int x, std::string method );
 	
 private:
 
 	//instance of orderqueue that contains a queue of orders read in from a 
 	//file.
 	Orderqueue wareHouseQueue;
 	
 	
 	Orderqueue getFromRetrieval;
 	
 	//helper function of timeCheck function that sends orders to the 
 	//retrieval. 
 	void orderSend();
 	
 	//instance of the retrieval class and receives current orders from the 
 	//warehouse and then sends orders to the packer based 
 	//on method specified by the client.
 	Retrieval goldenRetriever;
 	
 	//instance of the packer class that tracks the time taken to package the
 	//order and knows when an order has been completed.
 	Packer mailServices;
 	
 	//tracks the total amount of time passed
 	int time;
 	
 	//current order to be sent to the packer
 	Order currOrder;
 	
 	//total number of orders
 	int totalOrders_w;
 	
 	//populating a warehouse with orders
 	void populateWareHouse();
 	
 	//function that assigns orders to packaging units using the 
 	//round robin method
 	int shortestTime(int x);
 	
 	//copy constructor to copy a queue in the warehouse into a retrieval
 	//queue
 	void copyQueue(Orderqueue *x, Retrieval *y, int z);
 	
 	//handles sending to packing units of the packer
 	//void sendToPackingUnit(std::string x, Order y, int z);
 	
 	//what packaging unit was used last;
 	int packerNum;
 	
 	void sendToPacker(Retrieval *y, int);
 	
 	void shipOff(Orderqueue *x, int numPackers, int y);
 	
 	void deductPackTime(Packer x);
 	
 	bool poisonApple(int x, Packer dummy, Retrieval *holder);
 	
 	int checkPackingUnits(Packer dummy, int x);
 	
	int numOrders;
 	
 	int orderTime;
 	
 	int timeMin;

	int timeMax;
	
	int timeMean;
	
	int check;
	
	int overLord;
	
	int shortestTimeCount;
	
	int iterate;
	
	int robinHood;
	
	int roundRobin(int x, int y);
	
	int packerGet;
	
	Order myOrder;
	
	void printHelp(int timeMean, int timeMin, int timeMax,int numOrders);
 };

 #endif
 
 
