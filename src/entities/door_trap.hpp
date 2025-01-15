#pragma once

#include "door_base.hpp"

class EntityDoorTrap : public EntityDoorBase
{
public:
  static constexpr int ENTITY_TYPE = 8;
  static constexpr float RADIUS = 5.0f;
  static constexpr int MAX_COUNT_PER_LEVEL = 256;

  EntityDoorTrap(Simulation *sim, float xcoord, float ycoord,
                 int orientation, float swXcoord, float swYcoord);

  void logicalCollision() override;
};