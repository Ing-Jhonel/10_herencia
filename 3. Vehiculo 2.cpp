#include <iostream>
using namespace std;

class Vehiculo{
	protected:
		string color, numPlaca;
		int asientos;
		bool disponible;
	public:
		Vehiculo(string, string, int);
		void mostrarDatos();
};
Vehiculo::Vehiculo(string c, string n, int a, bool d){
	color=c;
	numPlaca=n;
	asientos=a;
	disponible=d;
} 
void Vehiculo::mostrarDatos(){
	cout << "Color: "<< color << endl
		<< "Numero de placa: "<< numPlaca << endl
		<< "Asientos: "<< asientos << endl
		<< "Disponibilidad: "<< disponible << endl << endl;
}

class Terrestre: public Vehiculo{
	private:
		int ruedas;
	public:
		Terrestre(string, string, int, bool, int);
		void mostrarDatosTerrestre();
};
Terrestre::Terrestre(string c, string n, int a, bool d, int r):Vehiculo(c,b,a,d){
	ruedas=r;
}
void Terrestre::mostrarDatosTerrestre(){
	//cout << "Vehiculo Terrestre" << endl << endl;
	mostrarDatos();
	cout << "Ruedas: "<< ruedas;
}

class Areo: public Vehiculo{
	public:
		void mostrarDatosAreo();
};
/*
void Areo::mostrarDatosAreos(){
	//cout << "Vehiculo Areo" << endl << endl;
	mostrarDatos();
}
*/
void Maritimo: public Vehiculo{
	public:
		void mostrarDatosMaritimo();
}

/*void Maritimo::mostrarDatosMaritimo(){
	//cout << "Vehiculo Maritimo" << endl << endl;
	mostrarDatos();
}*/
class Carro: public Terrestre{
	private:
		string marca[10];
		int cantidad;
	public:
		void mostrarDatosTerrestreCarro();
}

void Carro::mostrarDatosTerrestreCarro(){
	cout << "Carro"
	mostrarDatosTerrestre();
}
int main(){
	
	int opcion;
	do{
		cout << "MENU" << endl << endl
			<< "1) Crear vehiculo personalizado." << endl
			<< "2) Opciones de transporte terrestre." << endl
			<< "3) Reservar vehiculo." << endl
			<< "4) Salir." << endl << endl
			<< "= "; cin >> opcion;
			
			switch(opcion){
				case 1:
					cout << "Nombre: " <<
					break;
				case 2:
					break;
				case 3:
					break;
				case 4:
					cout << "Saliendo del programa." << endl;
					break;	
				
			}
	}while(opcion!=4);
	return 0;
}