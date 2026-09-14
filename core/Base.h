#ifndef BASE_H
#define BASE_H
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

class Base {
public:
  Base() {
    std::ifstream c("../config/config.json");
    configFile = json::parse(c);
    log("Config file loaded");
  }
  void log(std::string message) {
    std::cout << "#### DEBUG: ####\n" << message << std::endl;
  }

protected:
  json configFile;
};

#endif // !BASE_H
