#include "solver.hpp"
#include <complex>


using namespace solver;

RealVariable::RealVariable() : _a(0), _b(1), _c(0)
{

}

RealVariable::RealVariable(double c) : _a(0), _b(0), _c(c)
{

}

RealVariable::RealVariable(double a, double b, double c) : _a(a), _b(b), _c(c)
{

} 

RealVariable RealVariable::operator+ (const RealVariable& realVar) const
{
    return RealVariable(_a + realVar._a, _b + realVar._b, _c + realVar._c);
}

RealVariable operator+ (double x, const RealVariable& realVar)
{
    return realVar + x;
}

RealVariable RealVariable::operator- (const RealVariable& realVar) const
{
    return RealVariable(_a - realVar._a, _b - realVar._b, _c - realVar._c);
}

RealVariable operator- (double x, const RealVariable& realVar)
{
    return RealVariable(x) - realVar;
}

RealVariable RealVariable :: operator^ (int x)
{
    RealVariable r;
    return r;
}

RealVariable RealVariable :: operator== (RealVariable x)
{
    return true;
}
RealVariable   RealVariable :: operator== (int x)
{
    return true;
}

RealVariable  RealVariable :: operator/ (int x)
{
    RealVariable r;
    return r;
}

ComplexVariable  solver :: operator* (int x, ComplexVariable y)
{
    ComplexVariable c;
    return c;
}


ComplexVariable ComplexVariable :: operator- (int x)
{
    ComplexVariable c;
    return c;
}

ComplexVariable ComplexVariable ::operator- (ComplexVariable x)
{
    ComplexVariable c;
    return c;
}

ComplexVariable ComplexVariable :: operator+ (ComplexVariable x)
{
    ComplexVariable c;
    return c;
}

ComplexVariable  ComplexVariable :: operator+ (complex<double> x)
{
    ComplexVariable c;
    return c;
}

ComplexVariable ComplexVariable ::operator+ (int x)
{
    ComplexVariable c;
    return c;
}

 ComplexVariable solver:: operator+ (int x, ComplexVariable y)
 {
    ComplexVariable c;
    return c;
 }

ComplexVariable  ComplexVariable ::operator/ (int x)
{
    ComplexVariable c;
    return c;
}

ComplexVariable  ComplexVariable :: operator^ (int x)
{
    ComplexVariable c;
    return c;
}

ComplexVariable   ComplexVariable ::operator== (ComplexVariable x)
{
    return true;

}
ComplexVariable  ComplexVariable :: operator== (int x)
{
    return true;
}

double solver:: solve(RealVariable x)
{
    return 2;
}

complex<double> solver:: solve(ComplexVariable x)
{
  return std:: complex <double>(2.2,4.0);
}