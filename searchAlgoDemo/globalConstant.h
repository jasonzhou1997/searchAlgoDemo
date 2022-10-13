#pragma once
#ifndef _GLOBALCONSTANT_H
#define _GLOBALCONSTANT_H

const int GREEDY_OPTION = 1;
const int DIJSTRA_OPTION = 2;
const int ASTAR_OPTION = 3;
const int MAKE_MAP_OPTION = 4;
const int EXIT_PROGRAM_OPTION = 5;

const int LAST_OPTION_NUM = 5;
const int FIRST_OPTION_NUM = 1;

const int IGNORE_NUM_CHARACTERS = 50;

// The order at which .exe file gets entered as argument
const int EXE_INPUT_ARG_POSITION = 0;

const int TOTAL_INPUT_ARG_COUNT = 1;

//const int CELL_SIZE = 8;
//
//const int FONT_HEIGHT = 16;
//const int FONT_WIDTH = 9;
//
//const int SCREEN_RESIZE = 4;
// 
//The size of the cell
constexpr unsigned char CELL_SIZE = 16;
//Number of columns
constexpr unsigned char COLUMNS = 8;
//Hmm, I think this is the duration of the effect. But I'm not sure
constexpr unsigned char EFFECT_DURATION = 16;
//Vertical size of the font
constexpr unsigned char FONT_HEIGHT = 16;
//Horizontal size of the font
constexpr unsigned char FONT_WIDTH = 8;
//Number of rows
constexpr unsigned char ROWS = 8;
//Screen resize
constexpr unsigned char SCREEN_RESIZE = 4;
#endif // !_GLOBALCONSTANT_H
