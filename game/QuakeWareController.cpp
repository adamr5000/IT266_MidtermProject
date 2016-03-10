/*
  QuakeWareController.cpp (for QuakeWare mod) by amr48
  Manages instantiation of microgames, application/removal of status effects, and corresponding HUD elements.
*/

#include "../idlib/precompiled.h"
#pragma hdrstop

#include "Game_local.h"

void idQuakeWareController::Spawn() {

}

void idQuakeWareController::AddNewStatusEffect(idStatusEffect* ptr) {
	allStatusEffects[statusEffectsCount] = ptr;
	gameLocal.Printf("QWDEBUG: Pointer value supplied: %x", ptr);
	gameLocal.Printf("QWDEBUG: Pointer value just added: %x", allStatusEffects[statusEffectsCount]);
	statusEffectsCount++;
	gameLocal.Printf("QWDEBUG: New number of effects: %i\n", statusEffectsCount);		// TODO: delete the console printout lines
}