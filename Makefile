p2: main.o Date.o Call.o Array.o Subscriber.o Time.o Telco.o Control.o View.o
	g++ -o p2 main.o Date.o Call.o Array.o Subscriber.o Time.o Telco.o Control.o View.o

main.o: main.cc Control.h
	g++ -c main.cc

Date.o: Date.cc Date.h
	g++ -c Date.cc

Call.o: Call.cc Call.h
	g++ -c Call.cc

Array.o: Array.cc Array.h Call.h
	g++ -c Array.cc

Subscriber.o: Subscriber.cc Subscriber.h
	g++ -c Subscriber.cc

Time.o: Time.cc Time.h
	g++ -c Time.cc

Telco.o: Telco.cc Telco.h Array.h Subscriber.h Call.h
	g++ -c Telco.cc

Control.o: Control.cc Control.h Telco.h View.h
	g++ -c Control.cc

View.o: View.cc View.o
	g++ -c View.cc
	
clean:
	rm -f *.o p2
