#include "NodoEstudiante.h"

NodoEstudiante::NodoEstudiante()
{
    setEst(NULL);
    setSgte(NULL);
    setAnte(NULL);
}

NodoEstudiante::NodoEstudiante(Estudiante* est)
{
    setEst(est);
    setSgte(NULL);
    setAnte(NULL);
}

NodoEstudiante::~NodoEstudiante()
{
}

Estudiante* NodoEstudiante::getEst()
{
    return est;
}

void NodoEstudiante::setEst(Estudiante* est)
{
    this->est = est;
}

NodoEstudiante* NodoEstudiante::getSgte()
{
    return sgte;
}

void NodoEstudiante::setSgte(NodoEstudiante* sgte)
{
    this->sgte = sgte;
}

NodoEstudiante* NodoEstudiante::getAnte()
{
    return ante;
}

void NodoEstudiante::setAnte(NodoEstudiante* ante)
{
    this->ante = ante;
}
