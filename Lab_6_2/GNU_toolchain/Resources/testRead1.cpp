// cl -GX testRead1.cpp

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char buf[50];
    fstream infile("ntou1.txt");

    if (!infile)
    {
        cout << "無法開啟 ntou1.txt\n";
        cout << "Press <enter> to continue ...\n";
        cin.getline(buf, 50, '\n');
        return -1;
    }

    char campusName[50];
    infile.getline(campusName, 50, '\n');
    cout << "學校名稱: " << campusName << endl;

    int numberOfColleges;
    infile >> numberOfColleges;
    infile.getline(buf, 50, '\n');    

    int iCol;
    for (iCol=0; iCol<numberOfColleges; iCol++)
    {
        char collegeName[50];
        infile.getline(collegeName, 50, '\n');
        cout << "  學院名稱: " << collegeName << endl;

        int numberOfDepartments;
        infile >> numberOfDepartments;
        infile.getline(buf, 50, '\n');

        int iDept;
        for (iDept=0; iDept<numberOfDepartments; iDept++)
        {
            char departmentName[50];
            infile.getline(departmentName, 50, '\n');
            cout << "    學系名稱: " << departmentName << endl;
        }
    }
    cout << "Press <enter> to continue ...\n";
    cin.getline(buf, 50, '\n');
    return 0;
}