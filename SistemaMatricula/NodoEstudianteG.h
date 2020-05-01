#pragma once
#include <iostream>
#include <string>
#include "NodoEstudiante.h"

using namespace std;

class NodoEstudianteG
{
private:
	string cedula;
	double nota;
	NodoEstudiante* salto;
	NodoEstudianteG* sgte;
	NodoEstudianteG* ante;
public:
	NodoEstudianteG();
	NodoEstudianteG(double nota, NodoEstudiante* salto);
	~NodoEstudianteG();

	NodoEstudiante* getSalto();
	void setSalto(NodoEstudiante* salto);

	NodoEstudianteG* getSgte();
	void setSgte(NodoEstudianteG* sgte);
	NodoEstudianteG* getAnte();
	void setAnte(NodoEstudianteG* ante);

	string getCedula();
	void setCedula(string cedula);
	double getNota();
	void setNota(double nota);

	string datos();
	string datosCompleto();
};

