#ifndef BASE_H
#define BASE_H

#include <cstddef>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

class Base {
public:
  static Base &instance() {
    static Base *instance = new Base();
    return *instance;
  }

  void log(std::string message) {
    std::cout << "#### DEBUG: ####\n" << message << std::endl;
  }

  json configFile;

private:
  Base() {
    std::ifstream c("../config/config.json");
    configFile = json::parse(c);
    log("Config file loaded");
  }
};

#endif // !BASE_H
