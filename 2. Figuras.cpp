#include <iostream>
using namespace std;

class Figura{
	protected:
		string color;
	public:
		Figura(string);
};
Figura::Figura(string c){
	color=c;
}

class Circulo: public Figura{
	private:
		double radio;
	public:
		Circulo(string, double);
		void calcularArea();
		void calcularPerimetro();
};
Circulo::Circulo(string c, double r):Figura(c){
	radio=r; 
}
void Circulo::calcularArea(){
	double area=radio*radio*3.1416;
	cout << "El area del circulo es " << area << endl;
} 
void Circulo::calcularPerimetro(){
	double perimetro=2*3.1416*radio;
	cout << "El perimetro del circulo es " << perimetro << endl;
}

class Rectangulo: public Figura{
	private:
		double base, altura;
	public:
		Rectangulo(string, double, double);
		void calcularArea();
};
Rectangulo::Rectangulo(string c, double b, double a): Figura(c){
	base=b;
	altura=a;
}
void Rectangulo::calcularArea(){
	double area=base*altura;
	cout << "El area del rectangulo es " << area << endl;
}

class Triangulo: public Figura{
	private:
		double base, altura;
		string tipo;
	public:
		Triangulo(string, double, double, string);
		void calcularArea();
};
Triangulo::Triangulo(string c, double b,double a, string t): Figura(c){
	base=b;
	altura=a;
	tipo=t;
}
void Triangulo::calcularArea(){
	double area=(base*altura)/2;
	cout << "El area del triangulo es " << area << endl;
} 

int main() {

    Circulo c("Rojo", 5.0);
    c.calcularArea();
    c.calcularPerimetro();
    
    Rectangulo r("Verde", 4.0, 6.0);
    r.calcularArea();
    
    Triangulo t("Azul", 3.0, 4.0, "Equilatero");
    t.calcularArea();
    
    return 0;
}