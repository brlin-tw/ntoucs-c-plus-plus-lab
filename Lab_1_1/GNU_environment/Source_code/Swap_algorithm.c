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
