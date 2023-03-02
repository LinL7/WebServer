CXX = g++
CFLAGS = -std=c++11
TARGET = server
OBJS = ../code/log/*.cpp ../code/mysql/*.cpp ../code/timer/*.cpp ../code/server/*.cpp ../code/config/*.cpp ../code/main.cpp

all: $(OBJS)
		$(CXX) $(CFLAGS) $(OBJS) -g -o ../bin/$(TARGET) -pthread -lmysqlclient

clean:
	rm -rf ../bin/$(OBJS) $(TARGET)
