#pragma once
#include "Estudiante.h";
class NodoEstudiante
{
private:
	Estudiante* est;
	NodoEstudiante* sgte;
	NodoEstudiante* ante;
public:
	NodoEstudiante();
	NodoEstudiante(Estudiante* est);
	~NodoEstudiante();


public:
	Estudiante* getEst();
	void setEst(Estudiante* est);

	NodoEstudiante* getSgte();
	void setSgte(NodoEstudiante* sgte);

	NodoEstudiante* getAnte();
	void setAnte(NodoEstudiante* ante);

};