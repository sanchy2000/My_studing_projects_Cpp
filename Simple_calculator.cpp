#include <iostream>
#include <typeinfo>	
 
double add(double d1, double d2);
double subtract(double d1, double  d2);
double multiply(double d1, double  d2);
double divide(double d1, double  d2);
 

double getValue();
char getOperator();
void printResult(double a, char sm, double b);


typedef double (*arithmeticFcn)(double, double);
arithmeticFcn getArithmeticFcn(char op);

struct arithmeticStruct
{
	char op;
	arithmeticFcn fcn;
};

static arithmeticStruct arithmeticArray[] {
	{ '+', add },
	{ '-', subtract },
	{ '*', multiply },
	{ '/', divide }
};


int main()
{
    double a = getValue();
    char sm = getOperator();
    double b = getValue();
 
    printResult(a, sm, b);
 
    return 0;
}

//..........................

double add(double d1, double  d2){
return d1+d2;
}
double subtract(double d1,  double  d2){
return d1-d2;
}
double multiply(double d1, double  d2){
return d1*d2;
}
double divide(double d1, double  d2){
return d1/d2;
}

//.............................

arithmeticFcn getArithmeticFcn(char op)
{
	
	for (auto &arith : arithmeticArray)
	{
		if (arith.op == op)
			return arith.fcn;
	}
 
	return add; // функцией по умолчанию будет add()

}

double getValue()
{

	while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
    {
	
    std::cout << "Enter a double value: ";
    double a;
    std::cin >> a;
    
    if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            std::cout << "Oops, that input is invalid.  Please try again.\n";
        }
        else{
        	std::cin.ignore(32767,'\n');
            return a;
            }
    }
    
}

char getOperator()
{
	while (true) 
    {
        std::cout << "Enter one of the following: +, -, *, or /: ";
        char sm;
        std::cin >> sm;
 
        
        if (sm == '+' || sm == '-' || sm == '*' || sm == '/')    
            return sm; // возвращаем данные в функцию main() 
        else // в противном случае, сообщаем пользователю, что что-то пошло не так
            std::cout << "Oops, that input is invalid.  Please try again.\n";
        } 
}

void printResult(double a, char sm, double b)
{
	arithmeticFcn fcn = getArithmeticFcn(sm);
	std::cout << a << ' ' << sm << ' ' << b << " = " << fcn(a, b) << '\n';
}
