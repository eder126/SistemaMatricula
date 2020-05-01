#pragma once
#include <iostream>
#include <string>
#include "ListaEstudiantes.h"

using namespace std;

class Grupo
{
private:
	string numeroGrupo;
	bool status;
	int cantidadMaxima;
	string codigoMateria;
	ListaEstudiantes* estudiantes;
public:
	Grupo();
	Grupo(string, bool, int, string);//string numeroGrupo, bool status, int cantidadMaxima, string codigoMateria
	~Grupo();
	string estudiantesTemp;

	void setNumeroGrupo(string);//string numeroGrupo
	void setStatus(bool);//bool status
	void setCantidadMaxima(int);//int cantidadMx
	void setCodigoMateria(string);//string codigoMat
	void setListaEstudiantes(ListaEstudiantes*);//ListaEstudiantes* pEstudiantes

	string getNumeroGrupo();
	bool getStatus();
	int getCantidadMaxima();
	int getCantidadMatriculados();
	string getCodigoMateria();
	ListaEstudiantes* getListaEstudiantes();
	void modificar();
	string datosGrupo();
	string datosGrupoEstudiantes();
	string estadisticas78_1(bool);//12.Estudiantes activos o inactivos(cédula - nombre) de una materia
	string estadistica9();

	friend std::ostream& operator << (std::ostream& out, const Grupo& obj);
	friend std::istream& operator >> (std::istream& in, Grupo& obj);
};