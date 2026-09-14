#ifndef ASSETS_H
#define ASSETS_H

#include "../entities/GameActor.h"
#include "Base.h"

enum Type { PLAYER, ENEMY };

class Assets : public Base {
public:
  Assets();
  ~Assets();
  static map<State, Animation> load(Type type);

private:
  static map<State, Animation> loadPlayerAssets();
};

#endif // !ASSETS_H
