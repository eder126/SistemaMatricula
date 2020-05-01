#include "Grupo.h"

Grupo::Grupo() {
    this->setNumeroGrupo("");
    this->setStatus(false);
    this->setCantidadMaxima(0);
    this->setCodigoMateria("");
    this->setListaEstudiantes(new ListaEstudiantes());
    this->estudiantesTemp = "";
}

Grupo::Grupo(string numeroGrupo, bool status, int cantidadMaxima, string codigoMateria) {
    this->setNumeroGrupo(numeroGrupo);
    this->setStatus(status);
    this->setCantidadMaxima(cantidadMaxima);
    this->setCodigoMateria(codigoMateria);
    this->setListaEstudiantes(new ListaEstudiantes());
    this->estudiantesTemp = "";
}

Grupo::~Grupo() {

}

void Grupo::setNumeroGrupo(string num) {
    this->numeroGrupo = num;
}

void Grupo::setStatus(bool sts) {
    this->status = sts;
}

void Grupo::setCantidadMaxima(int max) {
    this->cantidadMaxima = max;
}

void Grupo::setCodigoMateria(string cod) {
    this->codigoMateria = cod;
}

void Grupo::setListaEstudiantes(ListaEstudiantes* ests) {
    this->estudiantes = ests;
}

string Grupo::getNumeroGrupo() {
    return this->numeroGrupo;
}

bool Grupo::getStatus() {
    return this->status;
}

int Grupo::getCantidadMaxima() {
    return this->cantidadMaxima;
}

int Grupo::getCantidadMatriculados() {
    return this->getListaEstudiantes()->cantidad();
}

string Grupo::getCodigoMateria() {
    return this->codigoMateria;
}

ListaEstudiantes* Grupo::getListaEstudiantes() {
    return this->estudiantes;
}

void Grupo::modificar()
{
    this->setStatus(!this->getStatus());
}

string Grupo::datosGrupo() {
    string texto = "Grupo (" + this->getNumeroGrupo() + ") para materia (" + this->getCodigoMateria() + ")\nEstatus: " + (this->getStatus() ? "Activo" : "Inactivo");
    texto += "\nCupo maximo: " + to_string(this->getCantidadMaxima()) + "\nMatriculados: " + to_string(this->getCantidadMatriculados()) + "\n";
    return texto;
}

string Grupo::datosGrupoEstudiantes() {
    string texto = "Grupo (" + this->getNumeroGrupo() + ") para materia (" + this->getCodigoMateria() + ")\nEstatus: " + (this->getStatus() ? "Activo" : "Inactivo");
    texto += "\nCupo maximo: " + to_string(this->getCantidadMaxima());
    texto += "\nEstudiantes matriculados (" + to_string(this->getCantidadMatriculados()) + ")\n";
    texto += this->getListaEstudiantes()->mostrar();
    return texto;
}

string Grupo::estadisticas78_1(bool estado) {
    return "Grupo (" + this->getNumeroGrupo() + ")\n  {\n" + this->getListaEstudiantes()->estadistica78_1(estado) + "  }";
}

string Grupo::estadistica9() {
    NodoEstudianteG* aux = this->getListaEstudiantes()->estadistica9();
    if (aux != NULL) {
        string texto = "Grupo (" + this->getNumeroGrupo() + ")\nEstatus: " + (this->getStatus() ? "Activo" : "Inactivo");
        texto += "\nMatriculados: " + to_string(this->getCantidadMatriculados()) + "\nMejor nota\n" + aux->datos();
        return texto;
    }
    else {
        string texto = "Grupo (" + this->getNumeroGrupo() + ")\nEstatus: " + (this->getStatus() ? "Activo" : "Inactivo");
        texto += "\nMatriculados: " + to_string(this->getCantidadMatriculados()) + "\nNo hay estudiantes registrados en este grupo.";
        return texto;
    }
}


std::ostream& operator<<(std::ostream& out, const Grupo& obj)
{
    out << obj.numeroGrupo << "\n" << obj.status << "\n" << obj.cantidadMaxima << "\n" << obj.codigoMateria << "\n" << obj.estudiantes->desplegarParaOut() << "\n" << std::endl;
    return out;
}

std::istream& operator>>(std::istream& in, Grupo& obj)
{
    getline(in, obj.numeroGrupo);
    in >> obj.status;
    in.ignore(1);
    in >> obj.cantidadMaxima;
    in.ignore(1);
    getline(in, obj.codigoMateria);
    getline(in, obj.estudiantesTemp);
    in.ignore(1);
    return in;
}
