#include <iostream>
#include <fstream>
#include "wareHouse.h"
#include "string2int.h"
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]){
	if(argc < 3){
		cout << "Please input all required files" << endl;
		exit (1);
	}
	string filename = argv[1];
	string integerConvert = argv[2];
	int numPackers = string2int(integerConvert);
	string mode = argv[3];
	wareHouse run;
	run.chronoKinesis(filename, numPackers, mode);
	return 0;
}

