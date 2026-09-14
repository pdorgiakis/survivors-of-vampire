#include "Base.h"
#include "raylib.h"
#include <nlohmann/json.hpp>
using json = nlohmann::json;
using namespace std;

class Game : public Base {
public:
  Game() = default;
  void Start();

private:
  void CreateWindow();
  void Loop();
  void DestroyWindow();
};
