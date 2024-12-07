#include <iostream>
using namespace std;

class Persona{
	protected:
		string nombres;
		string DNI;
		int edad;
	public:
		Persona(string, string, int);
		void mostrarDatos();
};

Persona::Persona(string n, string d, int e){
	nombres=n;
	DNI=d;
	edad=e;
}

void Persona::mostrarDatos(){
	cout << nombres << " tiene el DNI# " << DNI << " y tiene " << edad << " anios de edad." << endl;
}
class Docente: public Persona{
	private:
		int sueldo;
		string especialidad;
	public:
		Docente(string, string, int, int, string);
		void mostrarDocente();
		//void ingresarNotas();
		//void visualizarRegistros();
};

Docente::Docente(string n, string d, int e, int s, string es):Persona(n,d,e){
	sueldo=s;
	especialidad=es;
}

void Docente::mostrarDocente(){
	mostrarDatos();
	cout << "\tes un docente con un sueldo de S/. " << sueldo << " y tiene la especialidad: " << especialidad << endl;
}

class Estudiante: public Persona{
	private:
		int notas[5];
		int nNota;
		string codigo;
	public:
		Estudiante(string, string, int, int[], int, string);
		//void visualizarNotas();
		void mostrarEstudiante();
};

Estudiante::Estudiante(string n, string d, int e, int no[], int nn, string c):Persona(n,d,e){
	for(int i=0; i<nn; i++){
		notas[i]=no[i];
	}
	nNota=nn;
	codigo=c;
}

void Estudiante::mostrarEstudiante(){
	mostrarDatos();
	cout << "\tes un estudiante con codigo " << codigo << " y tiene " << nNota << " notas: " << endl;
	for(int i=0; i<nNota; i++){
		cout << notas[i] << " ";
		cout << endl;
	}
}

int main(){
	
	string nombre;
	Persona p("Juan Perez", "40343432", 25);
	p.mostrarDatos(); cout << endl;
	
	Docente d("Pepe Pepe", "2345345", 45, 5000, "Tecnico en celulares");
	d.mostrarDocente(); cout << endl;
	
	int nota[]={18,19,20};
	cout << "Ingrese el nombre de estudiante: "; fflush(stdin); getline(cin, nombre);
	Estudiante e(nombre, "53423434", 17, nota, 3, "2024-119026");
	e.mostrarEstudiante(); cout << endl;
	return 0;
}
