/*This class creates a sequence of strings that holds a queue of order structs 
 *that have been sent to the warehouse.
 */
 
 #ifndef ORDERQUEUE_H
 #define ORDERQUEUE_H
 #include "Order.h"
 #include <fstream>
 
 using namespace std;
 
 class Orderqueue{
 
 public:
 	//constructor for a queue sequence
 	Orderqueue();
 	
 	//destructor to delete all allocated memory in the constructor once the 
 	//program finishes running.
 	~Orderqueue();
 	
 	//This function adds orders to the sequence
 	void enQueue(Order order);
 	
 	
 	//This function removes orders from a sequence once it is completed
 	void deQueue(int x);
 	
 	//This function returns the number of orders in the queue
 	int numberOrders();
 	
 	//this function checks whether a queue sequence is empty or not
 	bool isEmpty();
 	
 	Order returnOrder(int x);
 	
 	 //This pointer is used to traverse through the sequence by subscripting
 	//it based on what order is to be accessed.
 	Order* queuePtr; 
 	
 	int size();
 	
 	int print(int x);
 
 
 
 private:
 	
 	//this function expands the sequence to be able to accommodate whatever
 	//amount of orders are saved in a file.
 	void expand();
 	
 	//This keeps track of the number of orders in a queue sequence
 	int numOrders;
 	
 	//tracks the current size of the sequence queue
 	int currSize;
 	
 	ifstream instream;
 
 
 
 
 };
 
 #endif 
