#include "raylib.h"
#include <nlohmann/json.hpp>
using json = nlohmann::json;
using namespace std;

class Game {
public:
  Game();
  void Start();

private:
  void CreateWindow();
  void Loop();
  void DestroyWindow();
  void LoadConfiguration();
  json configFile;
};
