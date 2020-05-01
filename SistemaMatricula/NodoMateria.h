#pragma once
#include "Materia.h"
class NodoMateria
{
private:
	Materia* materia;
	NodoMateria* sgte;
	NodoMateria* ante;

public:

	NodoMateria();
	NodoMateria(Materia* materia);
	~NodoMateria();
	void setMateria(Materia*);
	void setSgte(NodoMateria*);
	void setAnte(NodoMateria*);

	Materia* getMateria();
	NodoMateria* getSgte();
	NodoMateria* getAnte();
};
