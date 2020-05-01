#include "MaestroEstudiante.h"
#include <stddef.h>
#include <iostream>

using namespace std;

MaestroEstudiante::MaestroEstudiante()
{
	this->setCab(NULL);
	this->setLargo(0);
}

MaestroEstudiante::~MaestroEstudiante()
{
	delete this;
}

NodoEstudiante* MaestroEstudiante::getCab()
{
	return this->cab;
}


NodoEstudiante* MaestroEstudiante::dirFinal()
{
	NodoEstudiante* aux = NULL;
	if (this->getCab() != NULL) {
		aux = this->getCab();
		while (aux->getSgte() != NULL) {
			aux = aux->getSgte();
		}
	}
	return aux;
}

int MaestroEstudiante::getLargo()
{
	return this->largo;
}

void MaestroEstudiante::setCab(NodoEstudiante* _cab)
{
	this->cab = _cab;
}

void MaestroEstudiante::setLargo(int _largo)
{
	this->largo = _largo;
}

bool MaestroEstudiante::agregarInicio(Estudiante* est) {
	//Paso 1 Crear el nodo
	NodoEstudiante* n = new NodoEstudiante(est);

	if (!esVacia()) {
		//Paso 2. Enlazar el nuevo nodo a la lista
		n->setSgte(getCab());
		//Paso 3. Reacomodar la lista con el nuevo nodo
		getCab()->setAnte(n);

	}

	this->setCab(n);
	this->setLargo(this->getLargo() + 1);
	return true;

}

bool MaestroEstudiante::agregarFinal(Estudiante* est)
{
	bool agregado = false;
	if (!esVacia()) {
		NodoEstudiante* n = new NodoEstudiante(est);
		NodoEstudiante* aux = dirFinal();
		aux->setSgte(n);
		n->setAnte(aux);
		this->setLargo(this->getLargo() + 1);
		agregado = true;
	}
	else {
		agregado = agregarInicio(est);
	}
	return agregado;
}


string MaestroEstudiante::desplegar() {
	// Desplegar toda la estructura
	string retornar = "";
	NodoEstudiante* aux = this->getCab();
	//for ( Nodo * aux = getCab(); aux!=NULL; aux=aux->getSgte())
	for (int i = 0; i < this->cantidad(); i++) {
		retornar += "Posicion " + to_string(i) + " valores: { \n" + aux->getEst()->datos() + "\n}\n\n";
		aux = aux->getSgte();
	}
	return retornar;
}

bool MaestroEstudiante::modificar(Estudiante* x)
{
	x->modificar();
	return true;
}

bool MaestroEstudiante::borrar(string cedula) {
	bool borrado = false; // bandera que me indica si se borro o no el nodo
	if (!esVacia()) {
		if (getCab()->getEst()->getCedula() == cedula) {
			if (getCab()->getSgte() != NULL) { // if (getLargo() >1 )
				getCab()->getSgte()->setAnte(NULL);
			}
			NodoEstudiante* aux = getCab();
			setCab(getCab()->getSgte());
			delete aux;
			borrado = true;
			this->setLargo(this->getLargo() - 1);
		}
		else {
			NodoEstudiante* aux = buscar(cedula);
			if (aux != NULL) {
				aux->getAnte()->setSgte(aux->getSgte());
				if (aux->getSgte() != NULL)
					aux->getSgte()->setAnte(aux->getAnte());
				delete aux;
				borrado = true;
				this->setLargo(this->getLargo() - 1);
			}
		}
	}
	return borrado;

}

void MaestroEstudiante::guardar()
{
	std::ofstream out("estudiantes.txt");
	NodoEstudiante* aux = this->getCab();
	//for ( Nodo * aux = getCab(); aux!=NULL; aux=aux->getSgte())
	for (int i = 0; i < this->cantidad(); i++) {
		out << *aux->getEst();
		aux = aux->getSgte();
	}
	out.close();
}

void MaestroEstudiante::cargar()
{
	limpiar();
	std::ifstream in("estudiantes.txt");
	bool seguir = true;

	while (seguir)
	{
		//cout << "Estudiante" << endl;
		Estudiante est;
		in >> est;
		if (est.getNombreCompleto().compare("Estudiante Default")) {
		agregarInicio(new Estudiante(est.getCedula(), est.getNombreCompleto(), est.getNumeroCel(), est.getCorreoE(), est.getActivo()));
		//cout << "Estudiante es: " << est.datos() << endl;
		}
		else {
			seguir = false;
		}
	}
	in.close();

}

NodoEstudiante* MaestroEstudiante::buscar(string cedula)
{
	NodoEstudiante* aux = NULL;
	if (this->cantidad() >= 1) {
		aux = this->getCab();
		while (aux != NULL && aux->getEst()->getCedula() != cedula) {
			aux = aux->getSgte();
		}
	}
	return aux;
}



bool MaestroEstudiante::esVacia()
{
	return cantidad() == 0;
}

int MaestroEstudiante::cantidad()
{
	return this->getLargo();
}

void MaestroEstudiante::limpiar()
{
	int cant = this->cantidad() - 1;
	for (int i = 0; i <= cant; i++) {
		borrar(this->getCab()->getEst()->getCedula());
	}
}

string MaestroEstudiante::estadisticas78_3(bool estado) {//14.Estudiantes activos o inactivos(cédula - nombre) de toda la universidad
	string texto = "";
	if (!this->esVacia()) {
		NodoEstudiante* aux = this->getCab();

		for (int i = 0; i < this->getLargo(); i++) {
			if (aux->getEst()->getActivo() == estado)
				texto += aux->getEst()->datosFormato() + "\n";
			aux = aux->getSgte();
		}
	}
	else {
		texto = "No hay estudiantes registrados.";
	}
	return texto;
}