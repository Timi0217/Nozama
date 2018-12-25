CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -std=c++11
LDFLAGS  = -g3


nozama: wareHouse.o Orderqueue.o Packer.o Retrieval.o Parser.o main.o \
	string2int.o
	${CXX} ${LDFLAGS} ${CXXFLAGS} Orderqueue.o Packer.o Parser.o \
	Retrieval.o wareHouse.o main.o string2int.o -o nozama
	
main.o: wareHouse.h string2int.h main.cpp
	${CXX} ${LDFLAGS} ${CXXFLAGS} -c main.cpp
	
Orderqueue.o: Orderqueue.cpp Orderqueue.h Order.h
	${CXX} ${LDFLAGS} ${CXXFLAGS} -c Orderqueue.cpp
	
wareHouse.o: wareHouse.h wareHouse.cpp Orderqueue.h Retrieval.h Packer.h \
	Parser.h
	${CXX} ${LDFLAGS} ${CXXFLAGS} -c wareHouse.cpp
	
string2int.o: string2int.cpp string2int.h
	${CXX} ${LDFLAGS} ${CXXFLAGS} -c string2int.cpp	
	
Packer.o: Packer.cpp Packer.h Orderqueue.h
	${CXX} ${LDFLAGS} ${CXXFLAGS} -c Packer.cpp
	
Retrieval.o: Retrieval.cpp Retrieval.h Orderqueue.h Order.h
	${CXX} ${LDFLAGS} ${CXXFLAGS} -c Retrieval.cpp
	
Parser.o: Parser.cpp Parser.h
	${CXX} ${LDFLAGS} ${CXXFLAGS} -c Parser.cpp
	
Order.o: Order.h
	
clean:
	rm *.o
	
provide:
	provide comp15 proj1part2 wareHouse.cpp wareHouse.h Orderqueue.h \
	Orderqueue.cpp Packer.h Packer.cpp Retrieval.h Retrieval.cpp \
	Parser.h Parser.cpp string2int.h string2int.cpp Order.h \
	README Makefile main.cpp
	
