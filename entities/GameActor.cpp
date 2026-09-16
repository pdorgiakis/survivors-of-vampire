#include "GameActor.h"

Rectangle GameActor::getSourceTexture() {
  Rectangle source = {frame_ * getTextureWidth(), 0, getTextureWidth(),
                      static_cast<float>(animations[state_].texture.height)};
  return source;
}

float GameActor::getTextureWidth() {
  return animations[state_].texture.width / animations[state_].max_frames;
}

void GameActor::draw() {
  DrawTexturePro(animations[state_].texture, getSourceTexture(),
                 getDestTexture(), {0, 0}, 0.f, WHITE);
}

TransformedDimentions GameActor::getTransformedDimentions() {
  TransformedDimentions dimentions;
  dimentions.w = getTextureWidth() * size_;
  dimentions.h = animations[state_].texture.height * size_;
  return dimentions;
}

Rectangle GameActor::getDestTexture() {
  TransformedDimentions dimentions = getTransformedDimentions();

  Rectangle dest = {static_cast<float>(GetScreenWidth()) / 2 - dimentions.w / 2,
                    static_cast<float>(GetScreenHeight()) / 2 -
                        dimentions.h / 2,
                    dimentions.w, dimentions.h};
  return dest;
}

void GameActor::tick(float delta_time) {
  calculateFrame(delta_time);
  draw();
}

void GameActor::calculateFrame(float delta_time) {
  running_time_ += delta_time;
  if (running_time_ > update_time_) {
    frame_ = (frame_ + 1) % animations[state_].max_frames;
    running_time_ = 0;
  }
}
