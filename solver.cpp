#include "solver.hpp"
#include <complex>
#include <math.h>


using namespace solver;

RealVariable::RealVariable() : _a(0), _b(1), _c(0)
{

}

// RealVariable::RealVariable(double c) : _a(0), _b(0), _c(c)
// {

// }

RealVariable::RealVariable(double a, double b, double c) : _a(a), _b(b), _c(c)
{

} 

RealVariable RealVariable::operator+ (const RealVariable& realVar) const
{
    return RealVariable(_a + realVar._a, _b + realVar._b, _c + realVar._c);
}

RealVariable solver::operator+ (double x, RealVariable const& realVar)
{
    return RealVariable(realVar._a, realVar._b, realVar._c + x);
}

// RealVariable operator+ (int x, const RealVariable& realVar)
// {
//     // return realVar + x;
//     return RealVariable(realVar._a, realVar._b, realVar._c + x);
// }

RealVariable solver::RealVariable :: operator+ (double x)
{
    return RealVariable(_a, _b, _c + x);
}



RealVariable RealVariable::operator- (const RealVariable& realVar) const
{
    return RealVariable(_a - realVar._a, _b - realVar._b, _c - realVar._c);
}


RealVariable solver::operator- (RealVariable const& realVar, double x)
{
    return RealVariable(realVar._a, realVar._b , realVar._c - x);
}

RealVariable solver::operator- (double x, const RealVariable& realVar)
{
    return RealVariable(realVar._a, realVar._b , x - realVar._c);
}

RealVariable& solver:: operator* (double x, const RealVariable& realVar)
{
    RealVariable * res = new RealVariable(realVar._a * x, realVar._b * x, realVar._c * x);
    return *res;
}

RealVariable RealVariable :: operator^ (int x)
{
    if(x < 0 || x > 2)
    {
        throw runtime_error("this power is illegal");
    }

    if(x == 2)
    {
       return RealVariable(1,0,0);
    }

    if(x == 1)
    {
       return RealVariable(0,1,0);
    }  

    if(x == 0)
    {
       return RealVariable(0,0,1);
    }
    
}

RealVariable RealVariable :: operator== (RealVariable x)
{
    return RealVariable(_a - x._a, _b - x._b, _c - x._c);
}
RealVariable RealVariable :: operator== (int x)
{
    return RealVariable(_a,_b,_c - x);
}

RealVariable RealVariable :: operator/ (int x)
{
    if(x != 0)
    {
    return RealVariable(_a / x, _b / x, _c / x); 
    }
    throw runtime_error("cant divide in 0");
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

double solver:: solve(const RealVariable& x)
{
    return (-(x._b - sqrt(x._b * x._b - 4 * x._a * x._c)) / (2 * x._a));
}

complex<double> solver:: solve(const ComplexVariable& x)
{
  return std:: complex <double>(2.2,4.0);
}

int main()
{
    RealVariable x;
    cout << solve((x ^ 3) == 100) ;
    //cout << solve((x^2) + 2*x + 4.0 == 6.0*x/2 + 20 - x) << endl;
    //cout << solve((x^2) + 7*x + 6 == 4 + x) << endl;
    //cout << solve(3*(x^2)) << endl;
    // solve((x^2) + 2*x + 4.0 == 20 + 6.0*x/2 - x);   
    // solve(4 + x == 2);   
}