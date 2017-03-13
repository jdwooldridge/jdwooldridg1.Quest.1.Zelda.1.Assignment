#pragma once

//Basic Types
typedef unsigned int	Uint32;
typedef float			GAME_FLT;
typedef Uint32			GAME_INT;
typedef struct GAME_VEC
{
    GAME_FLT x;
    GAME_FLT y;
} GAME_VEC;

//========================================
//Base Game Constants
//========================================
const GAME_INT SCREEN_WIDTH = 800;
const GAME_INT SCREEN_HEIGHT = 600;
const GAME_INT GAME_FPS = 60;
const GAME_INT FRAME_DELAY = 1000 / GAME_FPS;
const GAME_INT LEVEL_WIDTH = 1600;
const GAME_INT LEVEL_HEIGHT = 1200;

//Event Types
enum GAME_EVENT {GAME_NA,GAME_UP,GAME_DOWN,GAME_LEFT,GAME_RIGHT, GAME_QUIT};

//Constants
const GAME_FLT PI = 3.14159f;

