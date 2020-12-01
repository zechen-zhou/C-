/* PROGRAM:  llist.c 
 *
 * Student Name: Zechen Zhou
 * Student Number: 040970042
 * Lab 5
 * Course: C Language, CST8234
 * Lab Section: 012
 * Professor: Surbhi Bahri
 * Due Date: Nov 23, 2020
 * Submission Date: Nov 23, 2020 
   	     
 * TOPIC:    simple linked list implementation 
 * PURPOSE:  Simple data structures 
*/

/**************************************************************************/
/* Declare include files
 **************************************************************************/
#include "llist.h"

/**************************************************************************/
/* Provided functions
 **************************************************************************/
 
/**************************************************************************/
/* llist_push:  Add an element to the head of the list
 **************************************************************************/
int llist_push( node_t **headRef, int data ) {

	node_t *new;

	if ( ( new = ( node_t *) malloc( sizeof( node_t ) ) ) == NULL )
		return EXIT_FAILURE;
	
	new->data = data;
	new->next = *headRef;
	*headRef  = new; 

	return 0;

}
/**************************************************************************/
/* llist_pop:   Removes first element of the list
 **************************************************************************/
void llist_pop   ( node_t **headRef ) {

	node_t *h = * headRef;
	
	if ( h == NULL ) return;
	
	*headRef = h->next;
	free( h );

	return;
}
/**************************************************************************/
/* llist_size:  Returns number of elements in the list
 **************************************************************************/ 
int  llist_size  ( node_t * head ) {
	int cnt = 0;
	
	struct node * tmp = head;

	while( tmp != NULL ) {
		cnt++;
		tmp = tmp->next;
	}
	return cnt;

}
/**************************************************************************/
/* llist_print:   Prints a list
 **************************************************************************/
void llist_print ( node_t * head ){

	int nodes = 0;
	struct node *current = head;


	fprintf( stdout, "{ " );
	while( current != NULL ) {
		fprintf( stdout, "%4d -->", current->data );
		nodes++;
		current = current->next;
	}
	fprintf( stdout, " NULL }\n" );
		
	fprintf(stdout, "Number of elements in the list: %d\n", nodes );

	return;

}

/*****************************************************************llist_size*********/
/* llist_contains:  Returns 1 if an element is contained in the list, 0 otherwise
 **************************************************************************/
int llist_contains ( node_t *h, int value ){
	struct node *tmp = h;
	while(tmp != NULL){
		if(value == tmp->data)
			return 1;
	}
	return 0;
}
/*****************************************************************llist_size*********/
/* llist_count:  Return the number of times an element is the list
 **************************************************************************/
int  llist_count    ( node_t *h, int value ){
	int count = 0;
	struct node *tmp = h;
	while(tmp != NULL){
		if(value == tmp->data){
			count++;
			tmp = tmp->next;
		}
	}
	return count;
}

/*****************************************************************llist_size*********/
/* llist_find:  Returns the index of the first element given it finds, -1 if not found 
 **************************************************************************/
int  llist_find     ( node_t *h, int value ) {
	int index = 0;
	struct node *tmp = h;
	while(tmp != NULL){
		if(value == tmp->data)
			return index;
		index++;
		tmp = tmp->next;	
	}
	return -1;
}


/*****************************************************************llist_size*********/
/* llist_is_equal:  Returns 1 if lists are the same, 0 if not 
 **************************************************************************/
int  llist_is_equal ( node_t *h1, node_t *h2 ){
	while(h1 != NULL && h2 != NULL){
		if(h1->data != h2->data)
		return 0;

		/*If we reach here, then h1 and h2 are not NULL 
		and their data is same, so move to next nodes in both lists*/
		h1 = h1->next;
		h2 = h2->next;
	}
	/*If linked list are identical, then 'h1' and 'h2' 
	must be NULL at this point.*/
	if(h1 == NULL && h2 == NULL){
		return 1;
	}else{
		return 0;
	}
}

/*************************************************************llist_pop*************/
/* llist_addlast:  Add an element to the tail of the list
 **************************************************************************/
void llist_addlast  ( node_t **href, int value ){
	node_t *current = *href;
	if(current == NULL){
		llist_push(href, value);
	}else{
	while(current->next != NULL){
		current = current->next;
	}
	/*now we can add a new node next to node D*/
	current->next = malloc(sizeof(node_t));
	current->next->data = value;
	current->next->next = NULL;
	}
}

/*************************************************************llist_pop*************/
/* llist_insert:  Add an element at index
 **************************************************************************/
/*How to do if the index greater than the max index of the list*/
/*void llist_insert   ( node_t **href, int value , int index ){
	int i = 0;
	node_t *current = *href;
	node_t *temp_node = NULL;
	if(index == 0){
		llist_push(**href, value);//////////////////////////////////
	}else{
		for(i=0;i<index-1;i++){
			if(current->next == NULL){
				i=index;
			}
			current = current->next;
		}
	}
}*/

/*************************************************************llist_pop*************/
/* llist_insert:  Removes first instance of values
 **************************************************************************/
void llist_remove   ( node_t **href, int value ){
	int i = 0;
	node_t *current = *href;
	node_t *temp_node = NULL;

	if(current == NULL){
		/************QUESTION********what should put here****************/
		href = NULL;
		free(current);
	}
	if(current != NULL && value == current->data){
		llist_pop(href);
		free(current);
	}
/*
	while(current != NULL && i == 0){
		if(current->)
	}*/
	while(current->next != NULL && i == 0){
		if(value == current->next->data && current->next->next != NULL){
			temp_node = current->next;
			current->next = temp_node->next;
			free(temp_node);
			current = current->next;
			i=1;
		}else if(value == current->next->data && current->next->next == NULL){
			current->next = NULL;
		}	
	}
/*
	while(current->next->next != NULL && i == 0){
		if(value == current->next->data){
			temp_node = current->next;
			current->next = temp_node->next;
			free(temp_node);
			current = current->next;
			i = 1;
		}
		current = current->next;
	}

	if(i == 0 && value == current->next->data){
		free(current->next);
		current->next = NULL;
	}
**/



	/*

	if(value == current->data){
		if(current->next != NULL){
			current = current->next;
		}else{
			
		}
		llist_pop(href);
	}
	
*/
}

/**************************************************************************/
/* llist_free:  Free all elements in the list
 **************************************************************************/
void llist_free ( node_t **href ){
	node_t *current = *href;
	node_t *next_node;
	while(current != NULL){
		next_node = current->next;
		free(current);
		current = next_node;
	}
	*href = NULL;
}


/**************************************************************************/
/* Functions to be implemented by you
 **************************************************************************/
int llist_contains ( node_t *h, int value );
int  llist_count    ( node_t *h, int value );
/*int  llist_find     ( node_t *h, int value ) ;*/
int  llist_is_equal ( node_t *h1, node_t *h2 );


void  llist_addlast  ( node_t **href, int value );
/*void  llist_insert   ( node_t **href, int value , int index );*/
void llist_remove   ( node_t **href, int value );
void llist_free     ( node_t **href );

