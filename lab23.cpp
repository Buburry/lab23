#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber{				
	public:
		double real;
		double imag;
		ComplexNumber(double,double);
		ComplexNumber operator+(const ComplexNumber &);
		ComplexNumber operator-(const ComplexNumber &);
		ComplexNumber operator*(const ComplexNumber &);
		ComplexNumber operator/(const ComplexNumber &);
		bool operator==(const ComplexNumber &);
		double abs();
		double angle();
};

ComplexNumber::ComplexNumber(double x = 0,double y = 0){
	real = x; imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c){
	return ComplexNumber(real+c.real,imag+c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c){
	return ComplexNumber(real-c.real,imag-c.imag);
}

//Write your code here
ComplexNumber ComplexNumber::operator*(const ComplexNumber &c){
	return ComplexNumber((real*c.real)-(c.imag*imag),(real*c.imag)+(imag*c.real));                //a+bi * c+di = ac + adi+ bic - bd
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c){
		double z = pow(c.real,2) + pow(c.imag,2);

	

	return ComplexNumber(((c.real * real) + (c.imag * imag))/z , (-(c.imag * real) + (c.real * imag))/z);  
}
////////////////////////////

ComplexNumber operator+(double s,const ComplexNumber &c){
	return ComplexNumber(s+c.real,c.imag);
}
ComplexNumber operator-(double s,const ComplexNumber &c){
	return ComplexNumber(s-c.real,-c.imag);
}
ComplexNumber operator*(double s,const ComplexNumber &c){
    ComplexNumber x(s);
    return x*c;
	//return ComplexNumber(s*c.real,c.imag);
}
ComplexNumber operator/(double s,const ComplexNumber &c){
    ComplexNumber x(s);
    return x/c;

}
///////////////////

// ComplexNumber operator+(const ComplexNumber &c,double s){
// 	return ComplexNumber(c.real+s,c.imag);
// }
// ComplexNumber operator-(const ComplexNumber &c,double s){
// 	return ComplexNumber(c.real-s,c.imag);
// }
// ComplexNumber operator*(const ComplexNumber &c,double s){
// 	return ComplexNumber(c.real*s,c.imag);
// }
// ComplexNumber operator/(const ComplexNumber &c,double s){
// 	return ComplexNumber(c.real/s,c.imag);
//}
/////////////////////////


bool ComplexNumber::operator==(const ComplexNumber &c){
	if(real == c.real && imag == c.imag) {
		return true;
	} else {
		return false;
	}	
}

bool operator==(double s,const ComplexNumber &c){
	if(s == c.real && 0 == c.imag) {
		return true;
	} else {
		return false;
	}	
}

double ComplexNumber::abs(){
	double sum;

	sum = sqrt(pow(real,2) + pow(imag,2));
	return sum;
}

double ComplexNumber::angle(){
	double result;

	double param = imag/real;
 	result = atan(param) * 180 / M_PI;
 	
 	if(real < 0 && imag > 0) result = 180 + result;
	if (imag < 0 && real < 0) result = result - 180;
	return result;

}

ostream & operator<<(ostream &cout, const ComplexNumber &u){
    if(u.imag == 0) {           
        return cout << u.real ;
    } else if(u.real == 0){           
        return cout << u.imag << "i" ;
	} else if(u.imag >= 0){           
        return cout << u.real << "+" << u.imag << "i";
	} else if(u.imag < 0){           
        return cout << u.real  << u.imag << "i";
	} else if(u.real == 0 && u.imag == 0){           
        return cout << "0";
	} else {
        return cout << "0";
    }
}



int main(){
	ComplexNumber a(1.5,2),b(3.2,-2.5),c(-1,1.2);	
	cout << a << "\n";
	cout << b << "\n";
	cout << c << "\n";
	cout << a+2.5 << "\n";
	cout << 2.5+a << "\n";
	cout << a-1.5 << "\n";
	cout << 1.5-a << "\n";
	cout << b+ComplexNumber(0,2.5) << "\n";
	cout << c-c << "\n";
	cout << "-----------------------------------\n";
	
	ComplexNumber d = (a+b)/c;
	ComplexNumber e = b/(a-c);
	cout << d << "\n";
	cout << e << "\n";
	cout << c*2 << "\n";
	cout << 0.5*c << "\n";
	cout << 1/c << "\n";
	cout << "-----------------------------------\n";
	
	cout << ComplexNumber(1,1).abs() << "\n";
	cout << ComplexNumber(-1,1).abs() << "\n";
	cout << ComplexNumber(1.5,2.4).abs() << "\n";
	cout << ComplexNumber(3,4).abs() << "\n";
	cout << ComplexNumber(69,-9).abs() << "\n";		
	cout << "-----------------------------------\n";	
	
	cout << ComplexNumber(1,1).angle() << "\n";
	cout << ComplexNumber(-1,1).angle() << "\n";
	cout << ComplexNumber(-1,-1).angle() << "\n";
	cout << ComplexNumber(1,-1).angle() << "\n";
	cout << ComplexNumber(5,2).angle() << "\n";
	cout << "-----------------------------------\n";
	
	cout << (ComplexNumber(1,1) == ComplexNumber(1,2)) << "\n";
	cout << (ComplexNumber(1,1) == 1) << "\n";
	cout << (0 == ComplexNumber()) << "\n";
}






