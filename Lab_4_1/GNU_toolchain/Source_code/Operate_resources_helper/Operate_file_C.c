/*we need printf*/
#include <stdio.h>

/*we need list files*/
#include "../List_directory_files/listDirectoryFiles.h"

/*詢問欲開啟檔案的函式*/
void askFile(char filename[])
{
  listDirectoryFiles();
  printf("目前工作目錄(working directory)下的檔案資訊如上，請輸入要開啟的檔案名稱：");

  /*FIXME:目前尚無能夠完美處理stdin的解決方案*/
  gets(filename);

  /*done*/
  return;
}

/*開啟檔案函式*/
FILE * openFile(const char const filename[], const char const mode[])
  {
  FILE * filePtr = fopen(filename, mode);

  printf("嘗試開啟檔案(%s)...\nTrying to open the file(%s)...\n", filename, filename);

  if(filePtr == NULL){
    printf("失敗！\nFailed!\n"
            "請確認檔案(%s)是否放在正確的路徑以及是否可被這個使用者存取！\n"
            "Please check the file(%s)'s existance and if it is accessible by this user!\n",
            filename, filename);
    /*error end*/
    return NULL;
  }
  printf("成功！\nSucceeded!\n");
  return filePtr;
  }


/*關閉檔案函式*/
short closeFile(const char const filename[], FILE * * filePtrRef)
{
  printf("關閉檔案(%s)。\n"
          "Closing file(%s).\n"
          , filename, filename);
  if(fclose(*filePtrRef) == EOF){
    printf("關閉檔案失敗！\n"
            "Close file failed!\n");
    return -1;
  }

  *filePtrRef = NULL;
  /*done*/
  return 0;
}

