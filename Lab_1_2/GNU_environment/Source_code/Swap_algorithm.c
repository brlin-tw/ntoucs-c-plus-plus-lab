/* swap演算法
 * 智慧財產授權人(Copyright holder)：林博仁(Henry Lin, pika1021@gmail.com)於2012
Copyright 2012 林博仁(Henry Lin, pika1021@gmail.com)
本程式採用的授權條款 | The license used by this software
  LGPL version 3 or later

  This program is free software: you can redistribute it and/or modify
  it under the terms of the Lesser GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  Lesser GNU General Public License for more details.

  You should have received a copy of the Lesser GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * -----------------------------------
 * 程式框架版本(program framework version)：A
 * 程式框架修訂號(program framework revision number)：201109251624
 * 更新紀錄(changelog)：
 *  Changelog is now stored on github
 * 已知問題(known issues)：
 *  Known issues is now stored on github
 * 待辦事項(todo)：
 *  Todo is now stored on github
*/

/*swap函式(整數專用版本)
  版本：1.01(2)
  傳入值：指向要swap的兩個整數變數的指標
  傳回值：無*/
void swapInt(int * swap_a, int * swap_b)
	{
		/*宣告與定義(declaration & definition)*/
        int buffer;/*暫時保存數值的變數*/

		/*－－－－－－－－－－－－－－－－－－－－－*/
        /*swap*/
            buffer = *swap_a;/*backup a*/
            *swap_a = *swap_b;/*assign a with *b*/
            *swap_b = buffer;/*assign *b with backuped *a*/
		/*－－－－－－－－－－－－－－－－－－－－－*/
		return;
	}

/*swap func.(unsigned整數專用版本)
  版本：1.00(0)*/
void swap_unsigned_int(unsigned int * swap_a, unsigned int * swap_b)
	{
        /*宣告與定義(Declaration & Definition)*/
        /*mem*/
            unsigned int buffer;

        /*－－－－－－－－－－－－－－－－－－－－－*/
        /*swap*/
        /*backup a*/
            buffer = *swap_a;
        /*assign a with *b*/
            *swap_a = *swap_b;
        /*assign *b with backuped a*/
            *swap_b = buffer;
        /*－－－－－－－－－－－－－－－－－－－－－*/
        return;
	}

/*swapLongInt func.(長整數專用版本)
  版本：1.01(1)*/
void swapLongInt(long int * a,long int * b)
	{
		/*宣告與定義(Declaration & Definition)*/
        /*mem*/
            long int mem;

		/*－－－－－－－－－－－－－－－－－－－－－*/
        /*swap*/
            /*backup a*/
                mem = *a;
            /*assign a with *b*/
                *a = *b;
            /*assign *b with backuped a*/
                *b = mem;
		/*－－－－－－－－－－－－－－－－－－－－－*/
		return;
	}

/*Swap(無負短整數專用版本)
  版本：1.01(1)*/
void swapUnsignedShortInt(unsigned short int * swap_a, unsigned short int * swap_b)
	{
		/*宣告與定義(Declaration & Definition)*/
        /*mem*/
            unsigned short int buffer;

		/*－－－－－－－－－－－－－－－－－－－－－*/
        /*swap*/
            /*backup a*/
                buffer = *swap_a;
            /*assign a with *b*/
                *swap_a = *swap_b;
            /*assign *b with backuped a*/
                *swap_b = buffer;
		/*－－－－－－－－－－－－－－－－－－－－－*/
		return;
	}

/*swap func.(雙精確度浮點數通用版本)
  版本：1.01(2)*/
void swapDouble(double * a,double * b)
	{
		/*宣告與定義(Declaration & Definition)*/
        /*mem*/
            double mem;

		/*－－－－－－－－－－－－－－－－－－－－－*/
        /*swap*/
            /*backup a*/
                mem = *a;
            /*assign a with *b*/
                *a = *b;
            /*assign *b with backuped a*/
                *b = mem;
		/*－－－－－－－－－－－－－－－－－－－－－*/
		return;
	}
