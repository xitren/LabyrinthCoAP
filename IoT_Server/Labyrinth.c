/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Labyrinth.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

uint8_t map[MAP_SIZE][MAP_SIZE];

uint32_t x = 0,y = 0,alpha = 0;

Node *nodes; //Nodes array
int width, height; //Maze dimensions

int init( )
{
	int i, j;
	Node *n;
	
	//Allocate memory for maze
	nodes = calloc( width * height, sizeof( Node ) );
	if ( nodes == NULL ) return 1;
		
	//Setup crucial nodes
	for ( i = 0; i < width; i++ )
	{
		for ( j = 0; j < height; j++ )
		{
			n = nodes + i + j * width;
			if ( i * j % 2 ) 
			{
				n->x = i;
				n->y = j;
				n->dirs = 15; //Assume that all directions can be explored (4 youngest bits set)
				n->c = ' '; 
			}
			else n->c = '#'; //Add walls between nodes
		}
	}
	return 0;
}

Node *link( Node *n )
{
	//Connects node to random neighbor (if possible) and returns
	//address of next node that should be visited

	int x, y;
	char dir;
	Node *dest;
	
	//Nothing can be done if null pointer is given - return
	if ( n == NULL ) return NULL;
	
	//While there are directions still unexplored
	while ( n->dirs )
	{
		//Randomly pick one direction
		dir = ( 1 << ( rand( ) % 4 ) );
		
		//If it has already been explored - try again
		if ( ~n->dirs & dir ) continue;
		
		//Mark direction as explored
		n->dirs &= ~dir;
		
		//Depending on chosen direction
		switch ( dir )
		{
			//Check if it's possible to go right
			case 1:
				if ( n->x + 2 < width )
				{
					x = n->x + 2;
					y = n->y;
				}
				else continue;
				break;
			
			//Check if it's possible to go down
			case 2:
				if ( n->y + 2 < height )
				{
					x = n->x;
					y = n->y + 2;
				}
				else continue;
				break;
			
			//Check if it's possible to go left	
			case 4:
				if ( n->x - 2 >= 0 )
				{
					x = n->x - 2;
					y = n->y;
				}
				else continue;
				break;
			
			//Check if it's possible to go up
			case 8:
				if ( n->y - 2 >= 0 )
				{
					x = n->x;
					y = n->y - 2;
				}
				else continue;
				break;
		}
		
		//Get destination node into pointer (makes things a tiny bit faster)
		dest = nodes + x + y * width;
		
		//Make sure that destination node is not a wall
		if ( dest->c == ' ' )
		{
			//If destination is a linked node already - abort
			if ( dest->parent != NULL ) continue;
			
			//Otherwise, adopt node
			dest->parent = n;
			
			//Remove wall between nodes
			nodes[n->x + ( x - n->x ) / 2 + ( n->y + ( y - n->y ) / 2 ) * width].c = '+';
			
			//Return address of the child node
			return dest;
		}
	}
	
	//If nothing more can be done here - return parent's address
	return n->parent;
}

void draw( )
{
	int i, j;

	//Outputs maze to terminal - nothing special
	for ( i = 0; i < height; i++ )
	{
		for ( j = 0; j < width; j++ )
		{
			printf( "%c", nodes[j + i * width].c );
		}
		printf( "\n" );
	}
	printf( "\n" );
}

int InitLabyrinth()
{
    Node *start, *last;

    width = MAP_SIZE;
    height = MAP_SIZE;

    //Seed random generator
    srand( time( NULL ) );

    //Initialize maze
    if ( init( ) )
    {
        fprintf( stderr, "out of memory!\n");
        exit( 1 );
    }

    //Setup start node
    start = nodes + 1 + width;
    start->c = 'S';
    start->parent = start;
    last = start;

    //Connect nodes until start node is reached and can't be left
    while ( ( last = link( last ) ) != start );
    nodes[(width-1) + (height-1) * width].c = 'F';
    draw( );
        
    int i, j;

    //Outputs maze to terminal - nothing special
    for ( i = 0; i < height; i++ )
    {
        for ( j = 0; j < width; j++ )
        {
            if (nodes[j + i * width].c == '#')
                map[i][j] = 1;
            else
                map[i][j] = 0;
            if (nodes[j + i * width].c == 'F')
                map[i][j] = 2;
            if (nodes[j + i * width].c == 'S')
                map[i][j] = 3;
        }
    }
    return 0;
}

int ISWALLGet(ParameterList_t *TempParam)
{
    int  ret_val = 0;
    int  ax = 0,ay = 0,ap = 0;
    char buffer[STRING_SIZE];

//    DBG_LOG_DEBUG("Into ISWALLGet.\n");
    AddToTransmit("<ISWALLGet>\r\n\r");
    /* First check to see if the parameters required for the execution of*/
    /* this function appear to be semi-valid.                            */
    if ((TempParam))
    {
        switch (alpha) {
            case 0:
                ax = x + 1;
                ay = y;
                break;
            case 1:
                ax = x;
                ay = y + 1;
                break;
            case 2:
                ax = x - 1;
                ay = y;
                break;
            case 3:
                ax = x;
                ay = y - 1;
                break;
            default:
                ap = 0;
                break;
        }
        if (ax < 0)
            ap = 1;
        else if (ay < 0)
            ap = 1;
        else if (ax >= MAP_SIZE)
            ap = 1;
        else if (ay >= MAP_SIZE)
            ap = 1;
        else
            ap = map[ax][ay];
        snprintf((char*)buffer,sizeof(buffer)," %d\r\n\r",(int)ap);
        AddToTransmit((char*)buffer);
    }
    else
    {
        /* One or more of the necessary parameters are invalid.           */
        ret_val = INVALID_PARAMETERS_ERROR;
        AddToTransmit("<INVALID_PARAMETERS_ERROR/>\r\n\r");
//        DBG_LOG_ERROR("Invalid parameters.\n");
    }
    AddToTransmit("</ISWALLGet>\r\n\r");

    return(ret_val);
}
int RotateCC(ParameterList_t *TempParam)
{
    int  ret_val = 0;
    int  ax = 0,ay = 0,ap = 0;
    char buffer[STRING_SIZE];

//    DBG_LOG_DEBUG("Into RotateCC.\n");
    AddToTransmit("<RotateCC>\r\n\r");
    /* First check to see if the parameters required for the execution of*/
    /* this function appear to be semi-valid.                            */
    if ((TempParam))
    {
        if (alpha = 0)
            alpha = 3;
        else
            alpha = alpha - 1;
        snprintf((char*)buffer,sizeof(buffer)," Rotated\r\n\r");
        AddToTransmit((char*)buffer);
    }
    else
    {
        /* One or more of the necessary parameters are invalid.           */
        ret_val = INVALID_PARAMETERS_ERROR;
        AddToTransmit("<INVALID_PARAMETERS_ERROR/>\r\n\r");
//        DBG_LOG_ERROR("Invalid parameters.\n");
    }
    AddToTransmit("</RotateCC>\r\n\r");

    return(ret_val);
}
int RotateCCW(ParameterList_t *TempParam)
{
    int  ret_val = 0;
    int  ax = 0,ay = 0,ap = 0;
    char buffer[STRING_SIZE];

//    DBG_LOG_DEBUG("Into RotateCCW.\n");
    AddToTransmit("<RotateCCW>\r\n\r");
    /* First check to see if the parameters required for the execution of*/
    /* this function appear to be semi-valid.                            */
    if ((TempParam))
    {
        if (alpha = 3)
            alpha = 0;
        else
            alpha = alpha + 1;
        snprintf((char*)buffer,sizeof(buffer)," Rotated\r\n\r");
        AddToTransmit((char*)buffer);
    }
    else
    {
        /* One or more of the necessary parameters are invalid.           */
        ret_val = INVALID_PARAMETERS_ERROR;
        AddToTransmit("<INVALID_PARAMETERS_ERROR/>\r\n\r");
//        DBG_LOG_ERROR("Invalid parameters.\n");
    }
    AddToTransmit("</RotateCCW>\r\n\r");

    return(ret_val);
}
int MoveForward(ParameterList_t *TempParam)
{
    int  ret_val = 0;
    int  ax = 0,ay = 0,ap = 0;
    char buffer[STRING_SIZE];

//    DBG_LOG_DEBUG("Into MoveForward.\n");
    AddToTransmit("<MoveForward>\r\n\r");
    /* First check to see if the parameters required for the execution of*/
    /* this function appear to be semi-valid.                            */
    if ((TempParam))
    {
        switch (alpha) {
            case 0:
                ax = x + 1;
                ay = y;
                break;
            case 1:
                ax = x;
                ay = y + 1;
                break;
            case 2:
                ax = x - 1;
                ay = y;
                break;
            case 3:
                ax = x;
                ay = y - 1;
                break;
            default:
                ap = 0;
                break;
        }
        if (ax < 0)
            ap = 1;
        if (ay < 0)
            ap = 1;
        if (ax >= MAP_SIZE)
            ap = 1;
        if (ay >= MAP_SIZE)
            ap = 1;
        if (ap)
        {
            x = ax;
            y = ay;
            snprintf((char*)buffer,sizeof(buffer)," Moved\r\n\r");
        }
        else
            snprintf((char*)buffer,sizeof(buffer)," Cant move\r\n\r");
        AddToTransmit((char*)buffer);
    }
    else
    {
        /* One or more of the necessary parameters are invalid.           */
        ret_val = INVALID_PARAMETERS_ERROR;
        AddToTransmit("<INVALID_PARAMETERS_ERROR/>\r\n\r");
//        DBG_LOG_ERROR("Invalid parameters.\n");
    }
    AddToTransmit("</MoveForward>\r\n\r");

    return(ret_val);
}