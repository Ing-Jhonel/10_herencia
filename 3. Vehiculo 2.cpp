#include <iostream>
using namespace std;

class Vehiculo {
	protected:
		int asientos;
		string color, numPlaca;
		bool disponible;
	public:
		Vehiculo(int, string, string, bool);
		
		void setDisponible(bool d) { disponible = d;};
		bool getDisponible() { return disponible;};
		bool calcularDisponible(int, int);
		void setColor(const string& c) { color = c; };
		void mostrarDatos();
};
Vehiculo::Vehiculo(int a, string co, string nP, bool d){
	asientos = a;
	color = co;
	numPlaca = nP;
	disponible = d;
}
void Vehiculo::mostrarDatos() {
	cout << "Vehiculo" << endl << endl
		<< "Cantidad de Asientos: " << asientos << endl
		<< "Color: " << color << endl
		<< "Numero de placa: " << numPlaca << endl
		<< "Estado: ";
		
	if (disponible) {
		cout << "Disponible" << endl;
	} else {
		cout << "No disponible" << endl;
	}
}
bool calcularDisponible(int n, int max){
	if(n>max){
		cout << "Unidades no disponibles." << endl;
	} else if (max==0){
		return false;
	}
	return true;
}

class Terrestre : public Vehiculo {
	protected:
	    int ruedas, caballos;
	public:
	    Terrestre(int, string, string, bool, int, int);
	    void mostrarDatosTerrestre();
};
Terrestre::Terrestre(int a, string co, string nP, bool d, int r, int c) : Vehiculo(a, co, nP, d) {
	ruedas = r;
	caballos = c;
}
void Terrestre::mostrarDatosTerrestre() {
	mostrarDatos();
	cout << "Vehiculo terrestre: Carro" << endl
		<< "Ruedas: " << ruedas << endl
		<< "Caballos de fuerza: " << caballos << " HP" << endl;
}

class Aereo : public Vehiculo {
	protected:
	    int alturaMax, peso;
	public:
	    Aereo(int, string, string, bool, int, int);
	    void mostrarDatosAereo();
};
Aereo::Aereo(int a, string co, string nP, bool d, int h, int p) : Vehiculo(a, co, nP, d) {
	alturaMax = h;
	peso = p;
}
void Aereo::mostrarDatosAereo() {
	mostrarDatos();
	cout << "Vehiculo aereo: Helicoptero" << endl
		<< "Altura maxima: " << alturaMax << " metros" << endl
		<< "Peso: " << peso << " kg" << endl;
}

class Maritimo : public Vehiculo {
	protected:
	    double velocidadMax, velocidadMin;
	public:
	    Maritimo(int, string, string, bool, double, double);
	    void mostrarDatosMaritimo();
};
Maritimo::Maritimo(int a, string co, string nP, bool d, double vMax, double vMin) : Vehiculo(a, co, nP, d) {
	velocidadMax = vMax;
	velocidadMin = vMin;
}
void Maritimo::mostrarDatosMaritimo() {
	mostrarDatos();
	cout << "Vehiculo maritimo: Lancha" << endl
		<< "Velocidad maxima: " << velocidadMax << " nudos" << endl
		<< "Velocidad minima: " << velocidadMin << " nudos" << endl;
}

class Carro : public Terrestre {
	protected:
	    string marca;
	public:
		Carro() : Terrestre(0, "", "", false, 0, 0), marca("") {}
	    Carro(int, string, string, bool, int, int, string);
	    void mostrarDatosCarro();
};
Carro::Carro(int a, string co, string nP, bool d, int r, int c, string m) : Terrestre(a, co, nP, d, r, c) {
	marca = m;
}
void Carro::mostrarDatosCarro() {
	mostrarDatosTerrestre();
	cout << "Marca: " << marca << endl;
}

class Helicoptero : public Aereo {
	protected:
	    string marca;
	public:
		Helicoptero() : Aereo(0, "", "", false, 0, 0), marca("") {}
	    Helicoptero(int, string, string, bool, int, int, string);
	    void mostrarDatosHelicoptero();
};
Helicoptero::Helicoptero(int a, string co, string nP, bool d, int h, int p, string m) : Aereo(a, co, nP, d, h, p) {
	marca = m;
}
void Helicoptero::mostrarDatosHelicoptero() {
	mostrarDatosAereo();
	cout << "Marca: " << marca << endl;
}

class Lancha : public Maritimo {
	protected:
	    string marca;
	public:
		Lancha() : Maritimo(0, "", "", false, 0.0, 0.0), marca("") {}
	    Lancha(int, string, string, bool, double, double, string);
	    void mostrarDatosLancha();
};
Lancha::Lancha(int a, string co, string nP, bool d, double vMax, double vMin, string m) : Maritimo(a, co, nP, d, vMax, vMin) {
	marca = m;
}
void Lancha::mostrarDatosLancha() {
	mostrarDatosMaritimo();
	cout << "Marca: " << marca << endl;
}


int main(){
	
	int cantCarros=10, cantHelicopteros=1, cantLanchas=2;
 	Carro carros[cantCarros] = {
        Carro(4, "Rojo", "A123BC", true, 4, 120, "Toyota"),
        Carro(4, "Azul", "B234CD", true, 4, 150, "Honda"),
        Carro(4, "Negro", "C345DE", true, 4, 110, "Ford"),
        Carro(4, "Blanco", "D456EF", true, 4, 200, "Chevrolet"),
        Carro(4, "Gris", "E567FG", true, 4, 140, "Hyundai"),
        Carro(4, "Verde", "F678GH", true, 4, 160, "Jeep"),
        Carro(4, "Amarillo", "G789HI", true, 4, 300, "Ferrari"),
        Carro(4, "Plateado", "H890IJ", true, 4, 130, "Volkswagen"),
        Carro(4, "Marrón", "I901JK", true, 4, 180, "Nissan"),
        Carro(4, "Rosa", "J012KL", true, 4, 115, "Kia")
    };
	Helicoptero helicopteros[cantHelicopteros]= {
	    Helicoptero(5, "Blanco", "A123BC", true, 500, 1000, "Bell")
	};
	Lancha lanchas[cantLanchas] = {
	    Lancha(5, "Marrón", "I901JK", true, 75, 48, "Crownline"),
	    Lancha(5, "Rosa", "J012KL", true, 60, 38, "Four Winns")
	};

 	string color; bool disponible;
	int ruedas, caballos;
	int alturaMax, peso; 
	double vMax, vMin;
	string marca;
	
	int opcion;
	do{
		cout << "MENU" << endl << endl
			<< "1) Crear vehiculo personalizado (carros, helicopteros, cruceros)." << endl
			<< "2) Opciones de transporte terrestre disponibles." << endl
			<< "3) Reservar vehiculo." << endl
			<< "4) Salir." << endl << endl
			<< "= "; cin >> opcion;
			
			char elegir;
			system("cls");
			switch(opcion){
				case 1:
					do {
                        cout << "Crea tu vehiculo" << endl << endl
                             << "Elije" << endl << endl
                             << "A) Carro" << endl
                             << "B) Helicoptero" << endl
                             << "C) Lancha" << endl
                             << "D) Salir" << endl << endl
                             << "= "; cin >> elegir;
                             
						system("cls");
                        switch (elegir) {
                            case 'A':
                                cout << "Color: "; cin >> color;
                                for (int i = 0; i < cantCarros; i++) {
                                    if (carros[i].getDisponible()) {
                                        //carros[i].setDisponible(false);
                                        carros[i].setColor(color);
                                        break;
                                    }
                                }
                                break;
                            case 'B':
                                cout << "Color: "; cin >> color;
                                for (int i = 0; i < cantHelicopteros; i++) {
                                    if (helicopteros[i].getDisponible()) {
                                        helicopteros[i].setDisponible(false);
                                        helicopteros[i].setColor(color);
                                        break;
                                    }
                                }
                                break;
                            case 'C':
                                cout << "Color: "; cin >> color;
                                for (int i = 0; i < cantLanchas; i++) {
                                    if (lanchas[i].getDisponible()) {
                                        lanchas[i].setDisponible(false);
                                        lanchas[i].setColor(color);
                                        break;
                                    }
                                }
                                break;
                            case 'D':
                                cout << "Saliendo..." << endl;
                                break;
                            default:
                                cout << "Opción no válida." << endl;
                        }
                        system("cls");
                    } while (elegir != 'D');
					break;
				case 2:
					if(cantCarros!=0 && cantHelicopteros!=0 && cantLanchas!=0){
						for (int i = 0; i < cantCarros; i++) {
		                    if (carros[i].getDisponible()) {
		                        cout << "Carro " << i + 1 << endl << endl;
		                        carros[i].mostrarDatosCarro(); cout << endl;
		                    }
		                }
		                for (int i = 0; i < cantHelicopteros; i++) {
		                    if (helicopteros[i].getDisponible()) {
		                        cout << "Helicoptero " << i + 1 << endl << endl;
		                        helicopteros[i].mostrarDatosHelicoptero();cout << endl;
		                    }
		                }
		                for (int i = 0; i < cantLanchas; i++) {
		                    if (lanchas[i].getDisponible()) {
		                        cout << "Lancha " << i + 1 << endl << endl;
		                        lanchas[i].mostrarDatosLancha();cout << endl;
		                    }
		                }
					} else {
						cout << "No hay ningun transporte disponible." << endl;
					}
					break;
				case 3:
					do{
						cout << "Reserva tu vehiculo" << endl << endl
						<< "Elije" << endl << endl
						<< "A) Carro" << endl
						<< "B) Helicoptero" << endl
						<< "C) Lancha" << endl
						<< "D) Salir" << endl << endl
						<< "= "; cin >> elegir;
						
						system("pause");
						int num; char seguir;
						switch(elegir){
							case 'A':
								if(cantCarros>0){
									do{
										for(int i=0; i<cantCarros; i++){
												cout << "Carro " << i+1 << endl << endl; carros[i].mostrarDatosCarro(); cout << endl;
										}
										cout << "Indique el numero de carro: "; cin >> num;
										carros[num-1].setDisponible(false);
										cout << endl << "Otro? (s/n): "; cin >> seguir;
										cout << endl << endl;
									} while (seguir=='s');
								} else {
									cout << "Unidades no disponibles." << endl;
								}
								break;
							case 'B':
								if(cantHelicopteros>0){
									do{
										for(int i=0; i<cantHelicopteros; i++){
												cout << "Helicoptero " << i+1 << endl << endl; helicopteros[i].mostrarDatosHelicoptero(); cout << endl;
										}
										cout << "Indique el numero de Helicoptero: "; cin >> num;
										helicopteros[num-1].setDisponible(false);
										cout << endl << "Otro? (s/n): "; cin >> seguir;
										cout << endl << endl;
									} while (seguir=='s');
								} else {
									cout << "Unidades no disponibles." << endl;
								}
								break;
							case 'C':
								if(cantLanchas>0){
									do{
										for(int i=0; i<cantLanchas; i++){
												cout << "Lancha " << i+1 << endl << endl; lanchas[i].mostrarDatosLancha(); cout << endl;
										}
										cout << "Indique el numero de Lancha: "; cin >> num;
										lanchas[num-1].setDisponible(false);
										cout << endl << "Otro? (s/n): "; cin >> seguir;
										cout << endl << endl;
									} while (seguir=='s');
								} else {
									cout << "Unidades no disponibles." << endl;
								}
								break;
							case 'D':
								cout << "Saliendo..." << endl;
								break;
							default:
								cout << "No valido." << endl;
								break;
						}
						system("pause");
						system("cls");
					} while (elegir!='D');
					break;
				case 4:
					cout << "Saliendo del programa." << endl;
					break;	
				
			}
			system("pause");
			system("cls");
	}while(opcion!=4);
	return 0;
}
