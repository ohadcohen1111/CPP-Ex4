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

RealVariable RealVariable::operator+(const RealVariable &realVar) const
{
    return RealVariable(_a + realVar._a, _b + realVar._b, _c + realVar._c);
}

RealVariable solver::operator+(double x, RealVariable const &realVar)
{
    return RealVariable(realVar._a, realVar._b, realVar._c + x);
}

RealVariable solver::RealVariable ::operator+(double x)
{
    return RealVariable(_a, _b, _c + x);
}

RealVariable RealVariable::operator-(const RealVariable &realVar) const
{
    return RealVariable(_a - realVar._a, _b - realVar._b, _c - realVar._c);
}

RealVariable solver::operator-(RealVariable const &realVar, double x)
{
    return RealVariable(realVar._a, realVar._b, realVar._c - x);
}

RealVariable solver::operator-(double x, const RealVariable &realVar)
{
    return RealVariable(realVar._a, realVar._b, x - realVar._c);
}

RealVariable &solver::operator*(double x, const RealVariable &realVar)
{
    RealVariable *res = new RealVariable(realVar._a * x, realVar._b * x, realVar._c * x);
    return *res;
}

RealVariable RealVariable ::operator^(int x)
{
    if (x < 0 || x > 2)
    {
        throw runtime_error("this power is illegal");
    }

    if (x == 2)
    {
        return RealVariable(1, 0, 0);
    }

    if (x == 1)
    {
        return RealVariable(0, 1, 0);
    }

    if (x == 0)
    {
        return RealVariable(0, 0, 1);
    }
}

RealVariable RealVariable ::operator==(RealVariable x)
{
    return RealVariable(_a - x._a, _b - x._b, _c - x._c);
}
RealVariable RealVariable ::operator==(int x)
{
    return RealVariable(_a, _b, _c - x);
}

RealVariable RealVariable ::operator/(int x)
{
    if (x != 0)
    {
        return RealVariable(_a / x, _b / x, _c / x);
    }
    throw runtime_error("cant divide in 0");
}

ComplexVariable solver ::operator*(double x, ComplexVariable y)
{
    return ComplexVariable(y.c_a * x, y.c_b * x, y.c_c * x);
}

// double  solver :: operator* (double x, complex<double> y)
// {
//     return ComplexVariable (y.real() * x, y.c_b * x, y.c_c * x);
// }

ComplexVariable ComplexVariable::operator*(ComplexVariable y)
{
    complex<double> a = c_a.real() * y.c_a.real() + c_a.real() * y.c_a.imag() + y.c_a.real() * c_a.imag() - c_a.imag() * y.c_a.imag();
    complex<double> b = c_b.real() * y.c_b.real() + c_b.real() * y.c_b.imag() + y.c_b.real() * c_b.imag() - c_b.imag() * y.c_b.imag();
    complex<double> c = c_c.real() * y.c_c.real() + c_c.real() * y.c_c.imag() + y.c_c.real() * c_c.imag() - c_c.imag() * y.c_c.imag();
    return ComplexVariable(a, b, c);
}

ComplexVariable ComplexVariable ::operator-(double x)
{
    return ComplexVariable(c_a, c_b, c_c.real() - x);
}

ComplexVariable ComplexVariable ::operator-(ComplexVariable x)
{
    return ComplexVariable(c_a - x.c_a, c_b - x.c_b, c_c - x.c_c);
}

ComplexVariable ComplexVariable ::operator+(ComplexVariable x)
{
    return ComplexVariable(c_a + x.c_a, c_b + x.c_b, c_c + x.c_c);
}

ComplexVariable ComplexVariable ::operator+(complex<double> x)
{
    return ComplexVariable(c_a, c_b, c_c + x);
}

ComplexVariable ComplexVariable ::operator+(double x)
{
    return ComplexVariable(c_a, c_b, c_c + x);
}

ComplexVariable solver::operator+(double x, ComplexVariable y)
{
    return ComplexVariable(y.c_a, y.c_b, y.c_c.real() + x);
}

ComplexVariable ComplexVariable ::operator/(double x)
{
    if (x == 0)
    {
        throw runtime_error("illegal");
    }
    return ComplexVariable(c_a / x, c_b / x, c_c / x);
}

ComplexVariable ComplexVariable ::operator^(int x)
{
    if (x < 0 || x > 2)
    {
        throw runtime_error("this power is illegal");
    }

    if (x == 2)
    {
        return ComplexVariable(1, 0, 0);
    }

    if (x == 1)
    {
        return ComplexVariable((0, 0), (1, 0), (0, 0));
        ;
    }

    if (x == 0)
    {
        return ComplexVariable((0, 0), (0, 0), (1, 0));
    }
}

ComplexVariable ComplexVariable ::operator==(ComplexVariable x)
{
    return ComplexVariable(c_a - x.c_a, c_b - x.c_b, c_c - x.c_c);
}
ComplexVariable ComplexVariable ::operator==(double x)
{
    return ComplexVariable(c_a, c_b, c_c.real() - x);
}

double solver::solve(const RealVariable &x)
{
    if (x._a != 0 && x._b != 0)
    {
        return ((-(x._b) + sqrt(x._b * x._b - (4 * x._a * x._c))) / (2 * x._a));
    }
    if (x._a == 0 && x._b != 0)
    {
        return (-x._c) / x._b;
    }
    if (x._a != 0 && x._b == 0)
    {
        if ((x._c > 0 && x._a > 0) || (x._c < 0 && x._a < 0))
        {
            throw runtime_error("illegal");
        }
        return sqrt((-x._c) / x._a);
    }
    if (x._a == 0 && x._b == 0 && x._c != 0)
    {
        throw runtime_error("illegal");
    }
}

complex<double> solver::solve(const ComplexVariable &x)
{
    if ((x.c_a.real() == 0 && x.c_a.imag() == 0) && (x.c_b.real() == 0 && x.c_b.imag() == 0))
    {
        throw runtime_error("illegal");
    }
    if ((x.c_a.real() != 0 || x.c_a.imag() != 0))
    {
        complex<double> dis = x.c_b * x.c_b - (4.0 * x.c_a * x.c_c);
        if (dis.real() > 0 || dis.imag() > 0)
        {
            return ((-(x.c_b) + sqrt(x.c_b * x.c_b - (4.0 * x.c_a * x.c_c))) / (x.c_a * 2.0));
        }
        else if (dis == complex<double>(0, 0))
        {
            return ((-x.c_b) / 2.0 * x.c_a);
        }
        else
        {
            return ((-x.c_b) / (2.0 * x.c_a), (sqrt(x.c_b * x.c_b - (4.0 * x.c_a * x.c_c))) / (x.c_a * 2.0));
        }
    }
    if (x.c_a.real() == 0 || x.c_a.imag() == 0)
    {
        return (-x.c_c) / x.c_b;
    }
}

// int main()
// {
//     ComplexVariable y;
//     cout << solve((y ^ 2) == 9) << endl;
// }