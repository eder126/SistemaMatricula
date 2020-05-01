#include "NodoGrupo.h"

NodoGrupo::NodoGrupo()
{
	setGrp(NULL);
	setSgte(NULL);
	setAnte(NULL);
}

NodoGrupo::NodoGrupo(Grupo* grp)
{
	setGrp(grp);
	setSgte(NULL);
	setAnte(NULL);
}

NodoGrupo::~NodoGrupo()
{
}

void NodoGrupo::setGrp(Grupo* grp)
{
	this->grp = grp;
}

void NodoGrupo::setSgte(NodoGrupo* pSgte)
{
	this->sgte = pSgte;
}

void NodoGrupo::setAnte(NodoGrupo* pAnte)
{
	this->ante = pAnte;
}

Grupo* NodoGrupo::getGrp()
{
	return this->grp;
}

NodoGrupo* NodoGrupo::getSgte()
{
	return this->sgte;
}

NodoGrupo* NodoGrupo::getAnte()
{
	return this->ante;
}