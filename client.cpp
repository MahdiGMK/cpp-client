#include <iostream>

#include <string>
#include <map>
#include <sstream>
#include <chrono>
#include "resources/GameHandler.h"
#include <mutex>
using namespace std;



// const int PORT = 12345;
const std::string HOST = "127.0.0.1";

extern Game game;


int main(int argc , char** argv) {
	const int PORT = stoi(argv[1]);
	
	curl_global_init(CURL_GLOBAL_DEFAULT);
	GameHandler handeler(HOST,PORT);
	game.SetHostsPort(PORT);
	game.SetHost(HOST);
	
	handeler.begin();
	
	game.SetToken(handeler.GetToken());
	game.SetClient();
	handeler.ready();
	
	while (handeler.GetGameOn());
	
	handeler.join();
	curl_global_cleanup();
   
   
}
