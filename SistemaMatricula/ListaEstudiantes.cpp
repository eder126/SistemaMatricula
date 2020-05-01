#include "ListaEstudiantes.h"

ListaEstudiantes::ListaEstudiantes()
{
	this->setCab(NULL);
	this->setLargo(0);
}

ListaEstudiantes::~ListaEstudiantes()
{
	if (this->getLargo() > 0) {
		int _largo = this->getLargo();
		for (int i = 0; i < _largo; i++) {
			this->eliminar(this->getCab()->getCedula());
		}
	}
}

NodoEstudianteG* ListaEstudiantes::getCab() {
	return this->cab;
}
int ListaEstudiantes::getLargo() {
	return this->largo;
}
void ListaEstudiantes::setCab(NodoEstudianteG* pcab) {
	this->cab = pcab;
}
void ListaEstudiantes::setLargo(int plargo) {
	this->largo = plargo;
}

NodoEstudianteG* ListaEstudiantes::buscar(string cedula) {
	NodoEstudianteG* aux = NULL;
	if (!this->esVacio()) {
		aux = this->getCab();

		for (int i = 0; i < this->cantidad(); i++) {
			if (aux->getCedula() == cedula) {
				break;
			}
			if (aux->getSgte() != this->getCab())
				aux = aux->getSgte();
			else {
				aux = NULL;
				break;
			}
		}
	}
	return aux;
}

NodoEstudianteG* ListaEstudiantes::dirFinal() {
	NodoEstudianteG* aux = NULL;
	if (this->getCab() != NULL) {
		aux = this->getCab()->getAnte();
	}
	return aux;
}

NodoEstudianteG* ListaEstudiantes::anterior(string cedula) {
	NodoEstudianteG* aux = buscar(cedula)->getAnte();
	if (aux == NULL)
		return NULL;
	return aux;
}

string ListaEstudiantes::primero()
{
	return this->getCab()->getCedula();
}

bool ListaEstudiantes::agregar(double nota, NodoEstudiante* x) {
	bool agregado = false;
	if (!this->esVacio()) {
		if (this->buscar(x->getEst()->getCedula()) == NULL) {
			NodoEstudianteG* n = new NodoEstudianteG(nota, x);

			n->setAnte(this->getCab()->getAnte());
			n->setSgte(this->getCab());

			this->getCab()->getAnte()->setSgte(n);
			this->getCab()->setAnte(n);

			agregado = true;
			this->setCab(n);
			this->setLargo((this->getLargo() + 1));
		}
	}
	else {
		NodoEstudianteG* n = new NodoEstudianteG(nota, x);

		n->setAnte(n);
		n->setSgte(n);

		agregado = true;
		this->setCab(n);
		this->setLargo((this->getLargo() + 1));
	}
	return agregado;
}

bool ListaEstudiantes::eliminar(string cedula) {
	bool eliminado = false;
	if (this->getLargo() > 0) {
		NodoEstudianteG* aux = NULL;
		aux = this->buscar(cedula);
		if (aux != NULL) {
			aux->getAnte()->setSgte(aux->getSgte());
			aux->getSgte()->setAnte(aux->getAnte());

			if (aux == this->getCab())
				this->setCab(aux->getSgte());

			delete aux;
			eliminado = true;
			this->setLargo(this->getLargo() - 1);
		}
	}
	return eliminado;
}

NodoEstudianteG* ListaEstudiantes::consultar(string x) {
	NodoEstudianteG* aux = NULL;
	aux = this->buscar(x);
	return aux;
}

bool ListaEstudiantes::modificar(NodoEstudianteG* pest) {
	bool modificado = false;
	if (this->getLargo() > 0) {
		NodoEstudianteG* aux = NULL;
		aux = this->buscar(pest->getCedula());
		if (aux != NULL) {
			aux->setSalto(pest->getSalto());
			aux->setCedula(pest->getCedula());
			aux->setNota(pest->getNota());
			modificado = true;
		}
	}
	return modificado;
}

string ListaEstudiantes::mostrarParaEstadistica(bool estado)
{
	string texto = "";
	if (this->getLargo() > 0) {
		NodoEstudianteG* aux = this->getCab();
		for (int i = 0; i < this->getLargo(); i++) {
			if (aux->getSalto()->getEst()->getActivo() == estado) texto += "\n" + aux->getCedula() + " || " + aux->getSalto()->getEst()->getNombreCompleto();
			aux = aux->getSgte();
		}
	}
	else
		texto = "";


	if (texto == "") texto = "\nNo hay estudiantes en dicho estado en este grupo.";

	return texto;
}

string ListaEstudiantes::mostrar() {
	string texto = "";
	if (this->getLargo() > 0) {
		NodoEstudianteG* aux = this->getCab();
		for (int i = 0; i < this->getLargo(); i++) {
			texto += aux->datos() + "\n\n";
			aux = aux->getSgte();
		}
	}
	else
		texto = "No hay estudiantes registrados para este grupo.";
	return texto;
}

string ListaEstudiantes::mostrarCompleto() {
	string texto = "";
	if (this->getLargo() > 0) {
		NodoEstudianteG* aux = this->getCab();
		for (int i = 0; i < this->getLargo(); i++) {
			texto += aux->datosCompleto() + "\n\n";
			aux = aux->getSgte();
		}
	}
	else
		texto = "No hay estudiantes registrados para este grupo.";
	return texto;
}


string ListaEstudiantes::desplegarParaOut() {
	string texto = "";
	if (this->getLargo() > 0) {
		NodoEstudianteG* aux = this->getCab();
		for (int i = 0; i < this->getLargo(); i++) {
			texto += aux->getCedula() + "=" + to_string(aux->getNota()) + ",";
			aux = aux->getSgte();
		}
	texto = texto.substr(0, texto.length() - 1);
	}
	else
		texto = "";
	return texto;
}


string ListaEstudiantes::mostrar(string cedula) {
	NodoEstudianteG* aux = NULL;
	string texto = "";
	aux = this->buscar(cedula);
	if (aux != NULL) {
		texto = aux->datos() + "\n\n";
	}
	else {
		texto = "No se ha encontrado el estudiante registrado que busca.";
	}
	return texto;
}

int ListaEstudiantes::cantidad()
{
	return this->getLargo();
}

bool ListaEstudiantes::esVacio() {
	return this->getLargo() == 0;
}

string ListaEstudiantes::estadistica78_1(bool estado) {
	string texto = "";
	if (!this->esVacio()) {
		NodoEstudianteG* aux = this->getCab();
		int contador = 0;
		for (int i = 0; i < this->getLargo(); i++) {
			if (aux->getSalto()->getEst()->getActivo() == estado) {
				texto += aux->getSalto()->getEst()->datosFormato() + "\n";
				contador++;
			}
			aux = aux->getSgte();
		}
		if (contador == 0) {
			string extra = estado ? "activos" : "inactivos";
			texto = "No hay estudiantes " + extra + " en este grupo.\n";
		}
	}
	else {
		texto = "No hay estudiantes registrados en este grupo.\n";
	}
	return texto;
}

NodoEstudianteG* ListaEstudiantes::estadistica9()//Estudiantes de mejor nota por grupo
{
	NodoEstudianteG* mejor = NULL;
	if (!this->esVacio()) {
		NodoEstudianteG* aux = this->getCab();
		mejor = this->getCab();

		for (int i = 0; i < this->getLargo(); i++) {
			
			if (aux->getNota() > mejor->getNota()) {
				mejor = aux;
			}
			aux = aux->getSgte();
		}
	}
	return mejor;
}