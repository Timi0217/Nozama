//previous shortest time function

if(packerNum > number_packers){
			packerNum = 0;
		}
		int tag = shortestTime(number_packers);
		cerr << "here" << endl;
		//it's not increasing size cause it trues to call it a second
		//time and then it breaks
		cout <<"This is tag"<< tag << endl;
		//seg faults here
		mailServices.packingUnits[tag].enQueue(y);
		cerr << "boom" << mailServices.packingUnits[1].queuePtr[0].id << endl;
		cerr << "here2" << endl;
		//time += y.pack_duration
		
		
		//previous shipoff function
		void wareHouse::shipOff(Packer toShip, int num, int time){
	for(int i = 0; i < num; i++){
		if(toShip.packingUnits[i].queuePtr[0].pack_time_left == 0 || toShip.packingUnits[i].queuePtr[0].to_pack == true ){
			numOrders -= 1;
			orderTime=toShip.packingUnits[i].queuePtr[0].arrival_timestamp-time;
			toShip.packingUnits[i].queuePtr[0].pack_time_left -= 1;
			int orderNum = toShip.packingUnits[i].queuePtr[0].id;
			cerr << orderNum<<"this is order num" <<endl;
			cerr << "What is in packer?"<<mailServices.packingUnits[0].print(0) << endl;
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
