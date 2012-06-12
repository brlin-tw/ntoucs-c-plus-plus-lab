
#include <vector>
using namespace std;

#include "Student.h"

int main()
{
	int i;
	vector<Student *> sVector;

	for (i=0; i<10; i++)
		sVector.push_back(new Student("Carol Chen", "333331111",
									  "0933333111", "Business"));

//	for (i=0; i<10; i++)
//	    delete sVector[i];
    return 0;
}

