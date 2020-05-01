#include "NodoEstudiante.h"
class MaestroEstudiante
{
private:
	NodoEstudiante* cab;
	int largo;

	NodoEstudiante* dirFinal();
	int getLargo();
	void setLargo(int);
public:
	MaestroEstudiante();
	~MaestroEstudiante();
	// Métodos

	NodoEstudiante* getCab();

	void setCab(NodoEstudiante*);
	NodoEstudiante* buscar(string);
	bool esVacia(); // TRUE si la estructura esta vacia
	int cantidad(); // Me devuelve la cantidad de elementos de la lista

	void limpiar();

	bool agregarInicio(Estudiante* x);
	bool agregarFinal(Estudiante* x);

	string desplegar();
	bool modificar(Estudiante* x);

	bool borrar(string cedula);

	void guardar();
	void cargar();

	string estadisticas78_3(bool);
};