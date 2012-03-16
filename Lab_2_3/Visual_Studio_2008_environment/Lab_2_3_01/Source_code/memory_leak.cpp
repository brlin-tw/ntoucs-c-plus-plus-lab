#include "memory_leak.h"

#include <stdio.h>
#include <crtdbg.h>


void set_initial_leak_test()
{
	
    int tmpFlag;

    /* set flag to automatically report memory leaks at image exit */
    printf("\n[Leak test being performed]\n");

    tmpFlag =  _CrtSetDbgFlag( _CRTDBG_REPORT_FLAG );
 
		/*
		Causes _CrtCheckMemory to be called at every allocation and deallocation. This slows execution, but catches errors quickly.
		*/
    tmpFlag |= _CRTDBG_CHECK_ALWAYS_DF ;
		/*
		Prevents memory from actually being freed, as for simulating low-memory conditions. When this bit is on, freed blocks are kept in the debug heap¡¦s linked list but are marked as _FREE_BLOCK and filled with a special byte value.
		*/
    tmpFlag |= _CRTDBG_DELAY_FREE_MEM_DF ;

		/*
		Causes leak checking to be performed at program exit via a call to _CrtDumpMemoryLeaks. An error report is generated if the application has failed to free all the memory that it allocated.
		*/
    tmpFlag |= _CRTDBG_LEAK_CHECK_DF ;

		/*
		Causes blocks marked as type _CRT_BLOCK to be included in leak-detection and state-difference operations. When this bit is off, the memory used internally by the run-time library is ignored during such operations.
		*/
    // tmpFlag |= _CRTDBG_CHECK_CRT_DF ;


    _CrtSetDbgFlag( tmpFlag );

    /* Send all reports to STDOUT */
    _CrtSetReportMode( _CRT_WARN, _CRTDBG_MODE_FILE );
    _CrtSetReportFile( _CRT_WARN, _CRTDBG_FILE_STDOUT );

    _CrtSetReportMode( _CRT_ERROR, _CRTDBG_MODE_FILE );
    _CrtSetReportFile( _CRT_ERROR, _CRTDBG_FILE_STDOUT );

    _CrtSetReportMode( _CRT_ASSERT, _CRTDBG_MODE_FILE );
    _CrtSetReportFile( _CRT_ASSERT, _CRTDBG_FILE_STDOUT );

 


#ifdef TEST_MEM_LEAKS_BREAK_NUM
    /* force a leak to verify memory leak testing */
    _CrtSetBreakAlloc(TEST_MEM_LEAKS_BREAK_NUM);
#endif
}

