#include <iostream>
#include <complex>
#include <string>

using namespace std;

namespace solver {

    class RealVariable
    {
        // private:
        //     double _a, _b, _c;

        public:
         double _a, _b, _c;
        //constructor
            RealVariable();
            // RealVariable(double c);
            RealVariable(double a, double b, double c);

        // //getters
        //     double get_a(){return this->_a;};
        //     double get_b(){return this->_b;};     
        //     double get_c(){return this->_c;};     
     

        //operators   
            RealVariable operator+ (const RealVariable& realVar) const;
            friend RealVariable operator+ (double x, RealVariable const& realVar);
            RealVariable operator+ (double x);

           
            RealVariable operator- (const RealVariable& x) const;
            friend RealVariable operator- (double x, RealVariable const& realVar);
            friend RealVariable operator- (const RealVariable& realVar, double x);

            friend RealVariable& operator* (double x, const RealVariable& realVar);

            RealVariable operator^ (int x);

            RealVariable operator== (RealVariable x);
            RealVariable operator== (int x);

            RealVariable operator/ (int x);



    };

     class ComplexVariable
    {

        public:

        //constructor
            complex<double>  c_a, c_b, c_c; 
            ComplexVariable (): c_a(complex<double> (0,0)),  c_b(complex<double> (1,0)), c_c(complex<double> (0,0)){};
            ComplexVariable (complex<double> _a, complex<double> _b, complex<double> _c) 
            {
                c_a = _a ;
                c_b = _b ;
                c_c = _c;
            } 

        //operators   
            // ComplexVariable operator* (int x);
            ComplexVariable operator* (ComplexVariable y);
            friend ComplexVariable operator* (double x, ComplexVariable y);
        //    friend double operator* (double x, complex<double> y);

            ComplexVariable operator- (double x);
            ComplexVariable operator- (ComplexVariable x);

            ComplexVariable operator+ (ComplexVariable x);
            ComplexVariable operator+ (complex<double> x);
            ComplexVariable operator+ (double x);
            friend ComplexVariable operator+ (double x, ComplexVariable y);

            ComplexVariable operator/ (double x);

            ComplexVariable operator^ (int x);

            // ComplexVariable operator() (int x);

            ComplexVariable operator== (ComplexVariable x);
            ComplexVariable operator== (double x);

            //complex<double> solve(bool x);
    };

        complex<double> solve(const ComplexVariable& x);
        double solve(const RealVariable& x);




}