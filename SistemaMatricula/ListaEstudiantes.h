#pragma once
#include "NodoEstudianteG.h"

class ListaEstudiantes
{
private:
	NodoEstudianteG* cab;
	int largo;

	int getLargo();
	void setCab(NodoEstudianteG*);//NodoEstudianteG* pcab
	void setLargo(int);//int largo

	NodoEstudianteG* buscar(string);//string x
	NodoEstudianteG* dirFinal();
	NodoEstudianteG* anterior(string);//string x

public:
	ListaEstudiantes();
	~ListaEstudiantes();


	NodoEstudianteG* getCab();
	string primero();
	bool agregar(double nota, NodoEstudiante*);//NodoEstudianteG* pnodoGrupo
	bool eliminar(string);//string cedula
	NodoEstudianteG* consultar(string);// string numeroGrupo
	bool modificar(NodoEstudianteG*);//grupo* pgrupo
	string mostrarParaEstadistica(bool);
	string mostrar();
	string mostrarCompleto();
	string desplegarParaOut();
	string mostrar(string);//string numeroGrupo
	int cantidad();
	bool esVacio();

	string estadistica78_1(bool);
	NodoEstudianteG* estadistica9();
};

