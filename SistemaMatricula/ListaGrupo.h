#pragma once
#include "NodoGrupo.h"
#include <iostream>

using namespace std;

class ListaGrupo
{
private:
	NodoGrupo* cab;
	int largo;

	void setCab(NodoGrupo*);//NodoGrupo* pcab
	void setLargo(int);//int largo
	NodoGrupo* getCab();
	int getLargo();

	NodoGrupo* buscar(string);//string x
	NodoGrupo* dirFinal();
	NodoGrupo* anterior(string);//string x

public:
	ListaGrupo();
	~ListaGrupo();

	NodoGrupo* primer();
	bool agregar(Grupo*);//NodoGrupo* pnodoGrupo
	bool eliminar(string);//string numeroGrupo
	NodoGrupo* consultar(string);// string numeroGrupo
	bool modificar(Grupo*);//grupo* pgrupo
	string mostrar();
	string mostrarCompleto();
	string mostrar(string);
	void limpiarParaCargar();
	int cantidad();
	bool esVacio();

	int estadisticas4_1();
	NodoGrupo* estadisticas4_2();
	NodoGrupo* estadisticas5_2();
	string estadisticas78_1(bool);//12.Estudiantes activos o inactivos(cédula - nombre) de una materia
	string estadisticas9();
	string estadisticas10();
};
