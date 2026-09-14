#include "Assets.h"

map<State, Animation> Assets::load(Type type) {
  switch (type) {
  case PLAYER:
    return loadPlayerAssets();
  case ENEMY:
    break;
  }
}

map<State, Animation> Assets::loadPlayerAssets() {
  std::ifstream c("../config/player.json");
  json configFile = json::parse(c);

  map<State, Animation> animations;

  for (auto &assets : configFile["assets"]) {
    Animation animation{LoadTexture(assets["asset"].get<string>().c_str()),
                        assets["max_frames"]};
    State state;
    if (assets["state"] == "idle")
      state = IDLE;
    else if (assets["state"] == "walk")
      state = WALK;

    animations.insert({state, animation});
  }

  return animations;
}
