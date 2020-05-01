#include "NodoMateria.h"

NodoMateria::NodoMateria()
{
	setAnte(NULL);
	setSgte(NULL);

}

NodoMateria::NodoMateria(Materia* pmateria)
{
	setMateria(pmateria);
}

NodoMateria::~NodoMateria()
{
}
void NodoMateria::setMateria(Materia* pmateria)
{
	this->materia = pmateria;
}

void NodoMateria::setSgte(NodoMateria* sgte)
{
	this->sgte = sgte;
}

void NodoMateria::setAnte(NodoMateria* ante)
{
	this->ante = ante;
}

Materia* NodoMateria::getMateria()
{
	return this->materia;
}

NodoMateria* NodoMateria::getSgte()
{
	return this->sgte;
}

NodoMateria* NodoMateria::getAnte()
{
	return this->ante;
}
