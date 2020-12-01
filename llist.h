/* PROGRAM:  llist.h
 *
 * Student Name: Zechen Zhou
 * Student Number: 040970042
 * Lab 5
 * Course: C Language, CST8234
 * Lab Section: 012
 * Professor: Surbhi Bahri
 * Due Date: Nov 23, 2020
 * Submission Date: Nov 23, 2020 
 * 
 * TOPIC:    simple linked list implementation 
 * PURPOSE:  Simple data structures 
             
*/
#ifndef __LINKLIST_H
#define __LINKLIST_H


/**************************************************************************/
/* Declare include files
 **************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**************************************************************************/
/* Struct Definitions 
 **************************************************************************/
typedef struct node {
	int data;
	struct node *next;
}node_t;


/**************************************************************************/
/* Provided functions
 * llist_push:  Add an element to the head of the list
 * llist_pop:   Removes first element of the list
 * llist_size:  Returns number of elements in the list
 **************************************************************************/
int llist_push  ( node_t **, int );
void llist_pop   ( node_t ** );
int  llist_size  ( node_t * );
void llist_print ( node_t * );


/**************************************************************************/
/* Functions you need to implement
 * 1> EASY (no need to modify the list)
 * llist_contains:  Returns 1 if an element is contained in the list
 		    0 otherwise
 * llist_count:     Returns the number of times an element give is the list
 * llist_find:      Returns the index of the first element given it finds, 
 *		    -1 if not found
 * llist_is_equal:  Returns 1 if lists are the same, 0 if not
 *                  Two lists are the same if they have the same number of elements
 *                  and the elements are presented in the same order
 * 
 * 2> MEDIUM (needs to modify the list)
 * llist_addlast:   Adds an element to the tail of the list
 * llist_insert:    Adds an element at index
 * llist_remove:    Removes first instance of value
 *
 * llist_free:      Free all elements in the list
 * 
 **************************************************************************/
int llist_contains ( node_t *h, int value );
int  llist_count    ( node_t *h, int value );
/*int  llist_find     ( node_t *h, int value ) ;
int  llist_is_equal ( node_t *h1, node_t *h2 );
*/

void  llist_addlast  ( node_t **href, int value );
/*void  llist_insert   ( node_t **href, int value , int index );*/
void llist_remove   ( node_t **href, int value );
/*void llist_free     ( node_t **href );*/

#endif
