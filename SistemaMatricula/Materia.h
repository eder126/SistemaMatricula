#pragma once
#include <string>
#include <iostream>
#include "ListaGrupo.h"
using namespace std;

class Materia
{
private:
	string codigoMateria;
	string descripcionMateria;
	ListaGrupo* grupos = new ListaGrupo();

	void setCodigoMateria(string pcodigo);
	void setDescripcionMateria(string pnombre);

public:

	Materia();
	Materia(string codigo, string nombre);
	string datos();
	string datosGruposCantidad();
	string datosGruposCompleto();
	string datosGruposCompletoEstudiantes();
	string getCodigoMateria();
	string getDescripcionMateria();
    ListaGrupo* getGrupos();
	void modificar(string);
    void setGrupos(ListaGrupo* grupos);
	
	string estadisticas78_1(bool);
	string estadisticas9();
	string estadisticas10();

	friend std::ostream& operator << (std::ostream& out, const Materia& obj);
	friend std::istream& operator >> (std::istream& in, Materia& obj);
};