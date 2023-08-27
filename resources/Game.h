#ifndef GAME
#define GAME
const int NumberOfRegions=43;
#include <iostream>
#include <string>
#include <vector>
#include <curl/curl.h>
#include <stdexcept>
#include "../externals/httplib.h"
#include "../externals/json.hpp"
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* user_data);

using namespace nlohmann;
class Game {
public:

	
	
	
	
	//setters getters with Capital letters first
	void SetToken(std::string token);
	void SetHostsPort(int port);
	void SetHost(std::string host);
	//requests with ordinary naming
	int getNumberOfTroopsToPut();
	bool testServer();
	std::map<int, std::vector <int>> getAdj();
	std::map<int, int> getOwners();
	std::map<int, int> getTroopsCount();
	int getState();
	int getTurnNumber();
	void nextState();
	int getPlayerID();
	std::vector<std::pair<int, int>> getStrategicNodes();
	void putOneTroop(int node);
	void putTroop(int node, int number_of_troops);
	void attack(int origin_node, int target_node, float fraction);
	void moveTroops(int origin_node, int dest_node, int number_of_troops);
	std::vector<int> getReachable(int node);
	void SetClient();

	

	
	


private:


	struct curl_slist* headers = nullptr;
	httplib::Client* client;
	std::string host;
	int port;
	std::string token;
	json get(std::string url, std::string api, int port = 12345);
	json post(std::string url, std::string api, std::vector<std::pair<std::string,std::string>> items, int port = 12345);

};
#endif
