class Complex{
	public:
		Copmlex();
		Complex(double a, double b);
		Complex operator+(constant Complex&);
		Complex operator*(constant Complex&);
		
		void setReal(double a);
		void setImag(double b);
		double getReal() constant;
		double getImag() constant;

	friend ostream& operator <<
