scheduler: scheduler.o read.o policy.o stats.o
	g++ -std=c++11 compile/scheduler.o compile/read.o compile/policy.o compile/stats.o -o scheduler

scheduler.o: scheduler.cpp
	g++ -std=c++11 -c scheduler.cpp -o compile/scheduler.o

read.o: read.cpp
	g++ -std=c++11 -c read.cpp -o compile/read.o

policy.o: policy.cpp
	g++ -std=c++11 -c policy.cpp -o compile/policy.o

stats.o: stats.cpp
	g++ -std=c++11 -c stats.cpp -o compile/stats.o

clean:
		rm -rvf *.o scheduler