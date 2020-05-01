#include "NodoEstudianteG.h"

NodoEstudianteG::NodoEstudianteG()
{
    this->setSalto(NULL);
    this->setCedula("");
    this->setNota(0);
    this->setSgte(NULL);
    this->setAnte(NULL);
}

NodoEstudianteG::NodoEstudianteG(double nota, NodoEstudiante* salto)
{
    this->setSalto(salto);
    this->setCedula(salto->getEst()->getCedula());
    this->setNota(nota);
    this->setSgte(NULL);
    this->setAnte(NULL);
}

NodoEstudianteG::~NodoEstudianteG()
{
}

NodoEstudiante* NodoEstudianteG::getSalto() {
    return this->salto;
}

void NodoEstudianteG::setSalto(NodoEstudiante* salto) {
    this->salto = salto;
}

NodoEstudianteG* NodoEstudianteG::getSgte()
{
    return this->sgte;
}

void NodoEstudianteG::setSgte(NodoEstudianteG* sgte)
{
    this->sgte = sgte;
}

NodoEstudianteG* NodoEstudianteG::getAnte()
{
    return this->ante;
}

void NodoEstudianteG::setAnte(NodoEstudianteG* ante)
{
    this->ante = ante;
}

string NodoEstudianteG::getCedula() {
    return this->cedula;
}

void NodoEstudianteG::setCedula(string cedula) {
    this->cedula = cedula;
}

double NodoEstudianteG::getNota() {
    return this->nota;
}

void NodoEstudianteG::setNota(double nota) {
    this->nota = nota;
}

string NodoEstudianteG::datos() {
    return "Estudiante: " + this->getSalto()->getEst()->getNombreCompleto() + " Ced " + this->getSalto()->getEst()->getCedula() + "\nNota: " + to_string(this->getNota());
}

string NodoEstudianteG::datosCompleto() {
    return this->getSalto()->getEst()->datos() + "\nNota: " + to_string(this->getNota());
}