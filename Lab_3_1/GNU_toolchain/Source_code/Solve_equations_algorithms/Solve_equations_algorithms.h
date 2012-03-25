/* Solve_equations_algorithms.h */
/* include guard：避免同一個header檔案被include第二次。*/
#ifndef SOLVE_EQUATIONS_ALGORITHMS_H_
  #define SOLVE_EQUATIONS_ALGORITHMS_H_

  /*我們需要Complex類別的定義*/
  #include "../Complex_number_abstract_data_structure/Complex.h"

/* 解一元二次方程式的函式
 * 參數：
 *   係數a, b, c
 *   根root1, root2的參考(reference)
 * 回傳值：
 *   0  正常運作
 *   -1 無解*/
  #define SOLVE_QUADRATIC_EQUATION_TAG "【解一元二次方程式模組】"
  short solveQuadraticEquation(double a, double b, double c, CComplex& root1, CComplex& root2);

#endif /* SOLVE_EQUATIONS_ALGORITHMS_H_ */
