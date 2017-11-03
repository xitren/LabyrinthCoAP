/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Labyrinth.h
 * Author: xitre
 *
 * Created on 3 ноября 2017 г., 3:18
 */

#ifndef LABYRINTH_H
#define LABYRINTH_H

#include "Handler.h"

#define MAP_SIZE 100

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
	int x, y; //Node position - little waste of memory, but it allows faster generation
	void *parent; //Pointer to parent node
	char c; //Character to be displayed
	char dirs; //Directions that still haven't been explored
} Node;
    
extern Node *nodes; //Nodes array
extern int width, height; //Maze dimensions

int InitLabyrinth();

int ISWALLGet(ParameterList_t *TempParam);
int RotateCC(ParameterList_t *TempParam);
int RotateCCW(ParameterList_t *TempParam);
int MoveForward(ParameterList_t *TempParam);

#ifdef __cplusplus
}
#endif

#endif /* LABYRINTH_H */

