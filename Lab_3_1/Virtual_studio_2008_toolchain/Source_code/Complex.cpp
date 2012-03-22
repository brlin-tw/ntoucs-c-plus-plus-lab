#include "Complex.h"

CComplex::CComplex(void)
{
}

CComplex::~CComplex(void)
{
}

void CComplex::setValue(double real, double imaginary)
{
  m_real = real;
  m_imaginary = imaginary;
  return ;
}