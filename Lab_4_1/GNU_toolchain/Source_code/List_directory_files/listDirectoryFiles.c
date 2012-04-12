#include <stdio.h>
#include <stdlib.h>
#include "../Project_specific_configurations/System_category.h"


void listDirectoryFiles(void)
  {
    if(SYSTEM_CATEGORY == 1){
      system("ls --almost-all");
    }else{
      system("dir");
    }
    putchar('\n');
    return;
  }
