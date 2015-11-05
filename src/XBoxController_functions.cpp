/*
 *  Copyright 2010-2014 Fabric Software Inc. All rights reserved.
 */

#include <FabricEDK.h>
#include "XBox.h"
#include "global.h"

#define GAMEPAD_EXPORT 1
#include <gamepad.h>


void ContextCallback(bool opening, void const *contextPtr)
{
  if ( opening )
  {
    GamepadInit();
    printf("XBox: Library initialized.\n");
  }
  else
  {
    GamepadShutdown();
    printf("XBox: Library shutdown.\n");
  }
}

using namespace Fabric::EDK;
IMPLEMENT_FABRIC_EDK_ENTRIES_WITH_CONTEXT_CALLBACK( XBox, &ContextCallback )

// Defined at src\XBoxController.kl:82:1
FABRIC_EXT_EXPORT void XBoxController_Construct(
  KL::Traits< KL::XBoxController >::IOParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::SInt32 >::INParam device
) {
  this_->device = device;
}

// Defined at src\XBoxController.kl:99:1
FABRIC_EXT_EXPORT void XBoxController_Update(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::XBoxController >::INParam this_
) {
  GamepadUpdate();
}

// Defined at src\XBoxController.kl:107:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::Boolean XBoxController_IsConnected(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::XBoxController >::INParam this_
) {
  return GamepadIsConnected((GAMEPAD_DEVICE)this_->device) == GAMEPAD_TRUE;
}

// Defined at src\XBoxController.kl:116:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::Boolean XBoxController_ButtonDown(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::XBoxController >::INParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::SInt32 >::INParam button
) {
  return GamepadButtonDown((GAMEPAD_DEVICE)this_->device, (GAMEPAD_BUTTON)button) == GAMEPAD_TRUE;
}

// Defined at src\XBoxController.kl:125:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::Boolean XBoxController_ButtonTriggered(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::XBoxController >::INParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::SInt32 >::INParam button
) {
  return GamepadButtonTriggered((GAMEPAD_DEVICE)this_->device, (GAMEPAD_BUTTON)button) == GAMEPAD_TRUE;
}

// Defined at src\XBoxController.kl:134:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::Boolean XBoxController_ButtonReleased(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::XBoxController >::INParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::SInt32 >::INParam button
) {
  return GamepadButtonReleased((GAMEPAD_DEVICE)this_->device, (GAMEPAD_BUTTON)button) == GAMEPAD_TRUE;
}

// Defined at src\XBoxController.kl:143:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::SInt32 XBoxController_TriggerValue(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::XBoxController >::INParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::SInt32 >::INParam trigger
) {
  return GamepadTriggerValue((GAMEPAD_DEVICE)this_->device, (GAMEPAD_TRIGGER)trigger);
}

// Defined at src\XBoxController.kl:152:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::Float32 XBoxController_TriggerLength(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::XBoxController >::INParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::SInt32 >::INParam trigger
) {
  return GamepadTriggerLength((GAMEPAD_DEVICE)this_->device, (GAMEPAD_TRIGGER)trigger);
}

// Defined at src\XBoxController.kl:161:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::Boolean XBoxController_TriggerDown(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::XBoxController >::INParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::SInt32 >::INParam trigger
) {
  return GamepadTriggerDown((GAMEPAD_DEVICE)this_->device, (GAMEPAD_TRIGGER)trigger) == GAMEPAD_TRUE;
}

// Defined at src\XBoxController.kl:170:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::Boolean XBoxController_TriggerTriggered(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::XBoxController >::INParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::SInt32 >::INParam trigger
) {
  return GamepadTriggerTriggered((GAMEPAD_DEVICE)this_->device, (GAMEPAD_TRIGGER)trigger) == GAMEPAD_TRUE;
}

// Defined at src\XBoxController.kl:179:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::Boolean XBoxController_TriggerReleased(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::XBoxController >::INParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::SInt32 >::INParam trigger
) {
  return GamepadTriggerReleased((GAMEPAD_DEVICE)this_->device, (GAMEPAD_TRIGGER)trigger) == GAMEPAD_TRUE;
}

// Defined at src\XBoxController.kl:192:1
FABRIC_EXT_EXPORT void XBoxController_SetRumble(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::XBoxController >::INParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::Float32 >::INParam left,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::Float32 >::INParam right
) {
  GamepadSetRumble((GAMEPAD_DEVICE)this_->device, left, right);
}

// Defined at src\XBoxController.kl:207:1
FABRIC_EXT_EXPORT void XBoxController_StickXY(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::XBoxController >::INParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::SInt32 >::INParam stick,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::SInt32 >::IOParam outX,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::SInt32 >::IOParam outY
) {
  GamepadStickXY((GAMEPAD_DEVICE)this_->device, (GAMEPAD_STICK)stick, &outX, &outY);
}

// Defined at src\XBoxController.kl:222:1
FABRIC_EXT_EXPORT void XBoxController_StickNormXY(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::XBoxController >::INParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::SInt32 >::INParam stick,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::Float32 >::IOParam outX,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::Float32 >::IOParam outY
) {
  GamepadStickNormXY((GAMEPAD_DEVICE)this_->device, (GAMEPAD_STICK)stick, &outX, &outY);
}

// Defined at src\XBoxController.kl:234:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::Float32 XBoxController_StickLength(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::XBoxController >::INParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::SInt32 >::INParam stick
) {
  return GamepadStickLength((GAMEPAD_DEVICE)this_->device, (GAMEPAD_STICK)stick);
}

// Defined at src\XBoxController.kl:247:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::Float32 XBoxController_StickAngle(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::XBoxController >::INParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::SInt32 >::INParam stick
) {
  return GamepadStickAngle((GAMEPAD_DEVICE)this_->device, (GAMEPAD_STICK)stick);
}

// Defined at src\XBoxController.kl:259:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::SInt32 XBoxController_StickDir(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::XBoxController >::INParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::SInt32 >::INParam stick
) {
  return GamepadStickDir((GAMEPAD_DEVICE)this_->device, (GAMEPAD_STICK)stick);
}

// Defined at src\XBoxController.kl:274:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::Boolean XBoxController_StickDirTriggered(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::XBoxController >::INParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::SInt32 >::INParam stick,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::SInt32 >::INParam dir
) {
  return GamepadStickDirTriggered((GAMEPAD_DEVICE)this_->device, (GAMEPAD_STICK)stick, (GAMEPAD_STICKDIR)dir) == GAMEPAD_TRUE;
}
