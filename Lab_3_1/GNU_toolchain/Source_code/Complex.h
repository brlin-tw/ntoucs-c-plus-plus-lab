#pragma once

class CComplex
{
public:
  CComplex(void);
  virtual ~CComplex(void);
  /*method to set value to a CComplex*/
  void setValue(double real, double imaginary);
  /*method to add another CComplex to this CComplex*/
  void add(CComplex target);
  /*method to subtract another CComplex to this CComplex*/
  void subtract(CComplex target);
  /*method to multiply another CComplex to this CComplex*/
  void multiply(CComplex target);
  /*method to divide another CComplex to this CComplex*/
  bool divide(CComplex target);

private:
  double m_real;
  double m_imaginary;
};
