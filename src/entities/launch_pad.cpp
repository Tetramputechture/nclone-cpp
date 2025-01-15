#include "launch_pad.hpp"
#include "../physics/physics.hpp"
#include "../ninja.hpp"

LaunchPad::LaunchPad(Simulation *sim, float xcoord, float ycoord, int orientation)
    : Entity(ENTITY_TYPE, sim, xcoord, ycoord), orientation(orientation)
{
}

void LaunchPad::logicalCollision()
{
  auto ninja = sim->getNinja();
  if (!ninja || !ninja->isValidTarget())
    return;

  if (Physics::overlapCircleVsCircle(xpos, ypos, RADIUS, ninja->xpos, ninja->ypos, ninja->RADIUS))
  {
    auto [boostX, boostY] = Physics::mapOrientationToVector(orientation);
    ninja->xlpBoostNormalized = boostX;
    ninja->ylpBoostNormalized = boostY;
    ninja->launchPadBuffer = 0;
  }
}