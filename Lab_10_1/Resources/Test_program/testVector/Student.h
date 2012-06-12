// Student.h: interface for the Student class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STUDENT_H__54F7FB01_0F6E_4B42_8A5C_6B8FEC9A5808__INCLUDED_)
#define AFX_STUDENT_H__54F7FB01_0F6E_4B42_8A5C_6B8FEC9A5808__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Student
{
public:
    Student(const char *name, const char *ID,
            const char *phone, const char *department);
    ~Student();
//    void display(ostream &os) const;
private:
    char *m_name;
    char *m_ID;
    char *m_phone;
    char *m_department;
};

#endif // !defined(AFX_STUDENT_H__54F7FB01_0F6E_4B42_8A5C_6B8FEC9A5808__INCLUDED_)
