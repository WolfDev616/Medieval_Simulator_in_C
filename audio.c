// audio.c
#include "audio.h"

// Definitions of the globals declared as extern in audio.h.
// Remove "Sound coinDrop;" and "Sound hammerSound;" from main.c, or you'll get
// a "multiple definition" linker error.
Sound coinDropSound;
Sound buildingSound;
Sound chatterSound;
Sound introBirdSound;


bool randomSoundOnDay(int day, int everyNDays, int chancePercent, Sound sound)
{
    if (everyNDays <= 0) return false;
    if (day % everyNDays != 0) return false;   // not a cycle day

    if (GetRandomValue(0, 99) < chancePercent) {
        PlaySound(sound);
        return true;
    }
    return false;
}