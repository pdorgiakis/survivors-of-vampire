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

struct TransformedDimentions {
  float w, h;
};

class GameActor {
public:
  GameActor(map<State, Animation> animations, bool main_player)
      : animations(std::move(animations)), main_player(main_player) {};
  // TICK
  virtual void tick(float delta_time);
  // MOVEMENT
  virtual void moveUp() {}
  virtual void moveDown() {}
  virtual void moveLeft() {}
  virtual void moveRight() {}

protected:
  // MEMBER FUNCTIONS
  virtual void draw();
  virtual Rectangle getSourceTexture();
  virtual Rectangle getDestTexture();
  virtual float getTextureWidth();
  virtual TransformedDimentions getTransformedDimentions();
  void calculateFrame(float delta_time);
  State state_{IDLE};
  float size_{2.f};
  // Animation
  float update_time_{1 / 8.f};
  float running_time_{0};
  int frame_{0};
  float rotation{1.f};
  map<State, Animation> animations;
  bool main_player{false};
};
#endif
