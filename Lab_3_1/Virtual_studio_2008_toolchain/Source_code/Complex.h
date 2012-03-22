#pragma once

class CComplex
{
public:
  CComplex(void);
  virtual ~CComplex(void);
  void setValue(double real, double imaginary);
private:
  double m_real;
  double m_imaginary;
};
