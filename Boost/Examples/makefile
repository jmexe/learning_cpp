CXX = g++
CXFLAGS = -std=c++11

client: chat_message.hpp chat_client.cpp
	$(CXX) $(CXFLAGS) chat_client.cpp -o client -L/usr/lib -I/usr/include -I/usr/include/freetype2 -lpthread -lboost_system
server: chat_message.hpp chat_server.cpp
	$(CXX) $(CXFLAGS) chat_server.cpp -o server -L/usr/lib -I/usr/include -I/usr/include/freetype2 -lpthread -lboost_system
clean:
	rm client server
