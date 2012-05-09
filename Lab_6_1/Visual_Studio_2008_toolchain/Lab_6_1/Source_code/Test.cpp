/* device under test */
#include "Game.h"
#include "Bag.h"
#include "Ball.h"

/* Standard C++ Library */
#include <cstdlib> // srand()
#include <ctime>   // time()
#include <iostream>
#include <cstring>

using namespace std;

/* 顯示軟體說明訊息 */
void showHelp(const char command[]);

/* Ｖ字龍的函式庫蒐集*/
#include "pauseProgram/Pause_program.h"

int main(int argc, char *argv[])
{
  Game  bagBallGame, diceGame;
restart_program:
  if(argc > 1){
    if(!strcmp(argv[1], "--help") || !strcmp(argv[1], "-h")){
      showHelp(argv[0]);
      exit(0);
    }
  }

  srand(1);

  {
  double result;
  result = bagBallGame.bagBallExperiment(bagBallGame);
  std::cout << "The probability that remaining ball is red = "
            << result << "\n";
  }

  {
    double result;
    result = diceGame.diceExperiment(diceGame);
    std::cout << "步驟八的試驗得到的機率為"
              << result << endl;
  }

  if(argc != 1){
    if(!strcmp(argv[1], "--no-pause")){
      return 0;
    }
  }
  if(pauseProgram() == 1){
    goto restart_program;
  }
  return 0;
}

/* 顯示軟體說明訊息 */
void showHelp(const char command[])
{
  cout << "程式使用說明" << endl
       << "　命令語法：" << endl
       << "　　　" << command << " （選項參數）" << endl
       << "　選項參數：" << endl
       << "　　-h --help" << endl
       << "　　　顯示程式使用說明" << endl
       << "　　--no-pause" << endl
       << "　　　測試執行完不暫停運行直接結束" << endl;
  return;
}
