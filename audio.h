#ifndef AUDIO_H
#define AUDIO_H

#include "raylib.h"

extern Sound coinDropSound;   // declaration: "this exists somewhere else"
extern Sound buildingSound;   // declaration: "this exists somewhere else"
extern Sound introBirdSound;   // declaration: "this exists somewhere else"

bool randomSoundOnDay(int day, int everyNDays, int chancePercent, Sound sound);

#endif