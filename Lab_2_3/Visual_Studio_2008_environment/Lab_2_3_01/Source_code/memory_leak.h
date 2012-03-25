/*
 * TEST_MEM_LEAKS
 */
#ifndef MEMORY_LEAK_H
#define MEMORY_LEAK_H


#define TEST_MEM_LEAKS      1          /* 1 to test for memory leaks */


#ifdef TEST_MEM_LEAKS

////////////////////////////////////////////////////////////////////////////
/* allocation # at which to break */
#define TEST_MEM_LEAKS_BREAK_NUM 51

#define TEST_MEM_LEAKS_BREAK 1          /* 1 to break at an allocation*/

void set_initial_leak_test();

#endif 

#endif