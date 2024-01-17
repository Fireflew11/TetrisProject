#include "gameConfig.h"
#include <Windows.h>

//const int gameConfig::COLORS[] = { FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED,3,14,5,2,12,9,6 };
const int gameConfig::COLORS[] = {
    FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED,   // White
    FOREGROUND_BLUE | FOREGROUND_INTENSITY,                // Blue (intense)
    FOREGROUND_GREEN | FOREGROUND_INTENSITY,               // Green (intense)
    FOREGROUND_RED | FOREGROUND_INTENSITY,                 // Red (intense)
    FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY, // Yellow (intense)
    FOREGROUND_BLUE | FOREGROUND_GREEN,                    // Cyan
    FOREGROUND_RED | FOREGROUND_BLUE,                      // Purple
    FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY  // Light Blue (intense)
};