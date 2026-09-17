#ifndef MAINPLAYER_H
#define MAINPLAYER_H

#include "GameActor.h"
#include <raylib.h>

class MainPlayer : public GameActor {
public:
  MainPlayer();
  virtual void moveUp() override;
  virtual void moveDown() override;
  virtual void moveLeft() override;
  virtual void moveRight() override;

private:
};

#endif // MAINPLAYER_H
