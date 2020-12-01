/* PROGRAM:  test_llist
 *
 * Student Name: Zechen Zhou
 * Student Number: 040970042
 * Lab 5
 * Course: C Language, CST8234
 * Lab Section: 012
 * Professor: Surbhi Bahri
 * Due Date: Nov 23, 2020
 * Submission Date: Nov 23, 2020
 * TOPIC:     
 * PURPOSE:  TEST LLIST
 * NOTES:  
 */  

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <check.h>

#include "llist.h"
#include "test_llist.h"


#define TEST_SUCCESS "SUCCESS: All current tests passed!"
#define TEST_FAILURE "FAILURE: At least one test failed or crashed"
#define FILLER "*****************************************************************************"
#define NUM_RANDOM( min, max ) ( min + (int)( (double)max * rand() / ( RAND_MAX + 1.0 ) ) )

/*******************************************************************/
/* Function Prototypes
 *******************************************************************/
Suite * test_suite(void);
int run_testsuite(void);

/*******************************************************************/
/* main( ) 
 *******************************************************************/
int main(int argc, char* argv[]){

	srand( time( NULL ) );

    	return run_testsuite();
}


/*******************************************************************/
/* test_suit( ) 
 *******************************************************************/
Suite * test_suite(void) {
	Suite *s;
	TCase *tc_llist;
	
	s = suite_create("ALL CASES Link List");
	tc_llist = tcase_create("Link List");

	/***************  TEST A **********************
	 * 10 Cases
	 **********************************************/
   	tcase_add_test(tc_llist, test_contains );
  	tcase_add_test(tc_llist, test_count );
   	tcase_add_test(tc_llist, test_find );
   	tcase_add_test(tc_llist, test_equal );
   	tcase_add_test(tc_llist, test_addlast );
   	/*tcase_add_test(tc_llist, test_insert );*/
   	tcase_add_test(tc_llist, test_remove );
	
	suite_add_tcase( s, tc_llist );
	
	
	return s;
}

/*******************************************************************/
/* run_testsuite( ) 
 *******************************************************************/
int run_testsuite(){

	int fail_nr;
	Suite *s;
	SRunner *sr;

	printf("%s\n", FILLER );
	
	s = test_suite();
	sr = srunner_create(s);
	
	srunner_run_all(sr, CK_VERBOSE);

	fail_nr = srunner_ntests_failed(sr);
	srunner_free(sr);
	printf("%s\n", FILLER );
	printf("%s\n", fail_nr ? TEST_FAILURE : TEST_SUCCESS );
	printf("%s\n", FILLER );

	return ( !fail_nr ) ? EXIT_SUCCESS : EXIT_FAILURE;
}