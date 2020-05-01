#pragma once
#include "Grupo.h"
class NodoGrupo
{
private:
	Grupo* grp;
	NodoGrupo* sgte;
	NodoGrupo* ante;
public:
	NodoGrupo();
	NodoGrupo(Grupo*);//Grupo* pGrupo
	~NodoGrupo();

	void setGrp(Grupo*);//Grupo* pGrupo
	void setSgte(NodoGrupo*);//NodoGrupo* pSgte
	void setAnte(NodoGrupo*);//NodoGrupo* pAnte

	Grupo* getGrp();
	NodoGrupo* getSgte();
	NodoGrupo* getAnte();
};
