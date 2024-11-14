#include <iostream>
using namespace std;

class Vehiculo{
	protected:
		string numeroPlaca, color, marca;
		double velocimetro;
	public:
		Vehiculo(string, string, string, double);
		void mostrarDatos();
		void cambiarVelocidad(double);
};
Vehiculo::Vehiculo(string n, string c, string m, double v){
	numeroPlaca=n;
	color=c;
	marca=m;
	velocimetro=v;
}
void Vehiculo::mostrarDatos(){
	cout << "Vehiculo"<< endl
	 << "Numero de placa: " << numeroPlaca << endl
	 << "Color: " << color << endl
	 << "Marca: " << marca << endl
	 << "Velocimetro: " << velocimetro << endl;
}
void Vehiculo::cambiarVelocidad(double v){
	velocimetro=v;
	cout << "La nueva velocidad es: " << velocimetro << endl;
}
class Automovil: public Vehiculo{
	private:
		int cantPuertas, cantPasajeros;
	public:
		Automovil(string, string, string, double, int, int);
		void mostrarAutomovil();
		void subirPasajeros(int);
		void bajarPasajeros(int);
};
Automovil::Automovil(string n, string c, string m, double v, int cPuer, int cPasa):Vehiculo(n,c,m,v){
	cantPuertas=cPuer;
	cantPasajeros=cPasa;
}
void Automovil::mostrarAutomovil(){
	mostrarDatos();
	cout << "Es un automovil con " << cantPuertas << " puertas y " << cantPasajeros << " pasajeros." << endl;
}
void Automovil::subirPasajeros(int cant){
	cantPasajeros+=cant;
	cout << "Se subieron " << cant << " pasajeros. Hay: " << cantPasajeros << " pasajeros totales." << endl;
}
void Automovil::bajarPasajeros(int cant){
	if(cantPasajeros<cant){
		cout << "Solo hay " << cantPasajeros << " pasajeros, no puede bajar " << cant << " pasajeros." << endl;
	} else {
		cantPasajeros-=cant;
		cout << "Se bajaron " << cant << " pasajeros. Quedan: " << cantPasajeros << " pasajeros totales." << endl;
	}
}
class Camion: public Vehiculo{
	private:
		string carga;
	public:
		Camion(string, string, string, double, string);
		void mostrarCamion();
		void cambiarCarga(string);
};
Camion::Camion(string n, string c, string m, double v, string cg):Vehiculo(n,c,m,v){
	carga=cg;
}
void Camion::mostrarCamion(){
	mostrarDatos();
	cout << "Es un camion que lleva de carga: " << carga << endl;
}
void Camion::cambiarCarga(string cg){
	carga=cg;
	cout << "La nueva carga es: " << carga << endl;
}

int main(){
	
	Vehiculo v("A123", "Azul", "Hilux", 160);
	v.mostrarDatos(); cout << endl;
	
	Automovil a("B321", "Rojo", "Toyota", 120, 4, 6);
	a.mostrarAutomovil(); cout << endl;
	a.subirPasajeros(2); cout << endl;
	a.bajarPasajeros(9); cout << endl;
	
	Camion c("C453", "Amarillo", "CAT", 100, "Piedras Calizas");
	c.mostrarCamion(); cout << endl;
	c.cambiarCarga("Arena lisa"); cout << endl;
	c.mostrarCamion(); cout << endl;
	return 0;
}