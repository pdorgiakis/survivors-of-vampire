#ifndef GAMEACTOR_H
#define GAMEACTOR_H

#include "../core/Base.h"
#include "raylib.h"
#include <nlohmann/json.hpp>
using json = nlohmann::json;
using namespace std;

enum State { IDLE, WALK, JUMP, FALL, ATTACK, HURT, DEAD };
struct Animation {
  Texture texture;
  int max_frames;
};

class GameActor : public Base {
class GameActor {
public:
  GameActor(map<State, Animation> animations, bool main_player)
      : animations(std::move(animations)), main_player(main_player) {};

protected:
  State state_{IDLE};
  map<State, Animation> animations;
  bool main_player{false};
};
#endif
