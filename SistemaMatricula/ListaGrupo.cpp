#include "ListaGrupo.h"

ListaGrupo::ListaGrupo()
{
	this->setCab(NULL);
	this->setLargo(0);
}

ListaGrupo::~ListaGrupo()
{
	if (!this->esVacio()) {
		int _largo = this->getLargo();
		for (int i = 0; i < _largo; i++) {
			this->eliminar(this->getCab()->getGrp()->getNumeroGrupo());
		}
	}
}

NodoGrupo* ListaGrupo::getCab() {
	return this->cab;
}
int ListaGrupo::getLargo() {
	return this->largo;
}
void ListaGrupo::setCab(NodoGrupo* pcab) {
	this->cab = pcab;
}
void ListaGrupo::setLargo(int plargo) {
	this->largo = plargo;
}

NodoGrupo* ListaGrupo::buscar(string codigo) {
	NodoGrupo* aux = NULL;
	if (!this->esVacio()) {
		aux = this->getCab();
		for (int i = 0; i < cantidad(); i++) {
			if (aux->getGrp()->getNumeroGrupo() != codigo) {
				aux = aux->getSgte();
			}
			else {
				return aux;
			}
		}
		aux = NULL;
	}
	return aux;
}

NodoGrupo* ListaGrupo::dirFinal() {
	NodoGrupo* aux = NULL;
	if (this->getCab() != NULL) {
		aux = this->getCab()->getAnte();
	}
	return aux;
}

NodoGrupo* ListaGrupo::anterior(string x) {
	NodoGrupo* aux = buscar(x)->getAnte();

	if (aux == NULL)
		return NULL;

	return aux;
}

NodoGrupo* ListaGrupo::primer() {
	return this->getCab();
}

bool ListaGrupo::agregar(Grupo* x) {
	bool agregado = false;
	if (!this->esVacio()) {
		//Encontrar workaround a esto?
		if (this->buscar(x->getNumeroGrupo()) == NULL) {
			NodoGrupo* n = new NodoGrupo(x);
			n->setAnte(this->getCab()->getAnte());
			n->setSgte(this->getCab());

			this->getCab()->getAnte()->setSgte(n);
			this->getCab()->setAnte(n);

			this->setCab(n);
			this->setLargo((this->getLargo() + 1));
			agregado = true;
		}
	}
	else {
		NodoGrupo* n = new NodoGrupo(x);
		n->setAnte(n);
		n->setSgte(n);

		this->setCab(n);
		this->setLargo((this->getLargo() + 1));
		agregado = true;
	}
	return agregado;
}

bool ListaGrupo::eliminar(string x) {
	bool eliminado = false;
	if (!this->esVacio()) {
		NodoGrupo* aux = NULL;
		aux = this->buscar(x);
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

NodoGrupo* ListaGrupo::consultar(string x) {
	NodoGrupo* aux = NULL;
	aux = this->buscar(x);
	return aux;
}

bool ListaGrupo::modificar(Grupo* pgrupo) {
	NodoGrupo* aux = NULL;
	bool modificado = false;
	aux = this->buscar(pgrupo->getNumeroGrupo());
	if (aux != NULL) {
		aux->setGrp(pgrupo);
		modificado = true;
	}
	return modificado;
}

string ListaGrupo::mostrar() {
	string texto = "";
	if (!this->esVacio()) {
		NodoGrupo* aux = getCab();
		for (int i = 0; i < getLargo(); i++) {
			texto += aux->getGrp()->datosGrupo() + "\n\n";
			aux = aux->getSgte();
		}
	}
	else
		texto = "No hay grupos registrados para esta materia.";
	return texto;
}

string ListaGrupo::mostrarCompleto() {
	string texto = "";
	if (!this->esVacio()) {
		NodoGrupo* aux = getCab();
		for (int i = 0; i < getLargo(); i++) {
			texto += aux->getGrp()->datosGrupoEstudiantes() + "\n\n";
			aux = aux->getSgte();
		}
	}
	else
		texto = "No hay grupos registrados para esta materia.";
	return texto;
}

string ListaGrupo::mostrar(string numeroGrupo) {
	NodoGrupo* aux = NULL;
	string texto = "";
	aux = this->buscar(numeroGrupo);
	if (aux != NULL) {
		texto = aux->getGrp()->datosGrupo() + "\n";
	}
	else {
		texto = "No se ha encontrado el grupo registrado que busca.";
	}
	return texto;
}

void ListaGrupo::limpiarParaCargar()
{
	int cant = this->cantidad();
	for (int i = 0; i < cant; i++) {
		Grupo* grp = this->getCab()->getGrp();
		int cantEstud = grp->getListaEstudiantes()->cantidad();
		for (int j = 0; j < cantEstud; j++) {
			grp->getListaEstudiantes()->eliminar(grp->getListaEstudiantes()->primero());
		}
		eliminar(this->getCab()->getGrp()->getNumeroGrupo());
	}
}

int ListaGrupo::cantidad() {
	return this->getLargo();
}

bool ListaGrupo::esVacio() {
	return this->getLargo() == 0;
}

int ListaGrupo::estadisticas4_1() {
	int suma = 0;
	if (!esVacio()) {
		NodoGrupo* aux = this->getCab();
		for (int i = 0; i < this->getLargo(); i++) {
			suma += aux->getGrp()->getCantidadMatriculados();
			aux = aux->getSgte();
		}
	}
	return suma;
}

NodoGrupo* ListaGrupo::estadisticas4_2() {
	NodoGrupo* menor = NULL;
	if (!esVacio()) {
		NodoGrupo* aux = this->getCab();
		menor = this->getCab();
		for (int i = 0; i < this->getLargo(); i++) {

			if (aux->getGrp()->getCantidadMatriculados() < menor->getGrp()->getCantidadMatriculados())
				menor = aux;
			aux = aux->getSgte();
		}
	}
	return menor;
}

NodoGrupo* ListaGrupo::estadisticas5_2() {
	NodoGrupo* mayor = NULL;
	if (!esVacio()) {
		NodoGrupo* aux = this->getCab();
		mayor = this->getCab();
		for (int i = 0; i < this->getLargo(); i++) {
			if (aux->getGrp()->getCantidadMatriculados() > mayor->getGrp()->getCantidadMatriculados())
				mayor = aux;
			aux = aux->getSgte();
		}
	}
	return mayor;
}

string ListaGrupo::estadisticas78_1(bool estado) {
	string respuesta = "Grupo(s)	{\n";

	if (!this->esVacio()) {
		NodoGrupo* aux = this->getCab();
		for (int i = 0; i < this->getLargo(); i++) {
			respuesta += "========================\n";
			respuesta += aux->getGrp()->estadisticas78_1(estado);
			respuesta += "\n========================\n";
			aux = aux->getSgte();
		}
		respuesta += "\n	}";
	}
	else {
		respuesta += "No hay grupos registrados.\n	}\n";
	}

	return respuesta;
}

string ListaGrupo::estadisticas9() {
	string respuesta = "	Grupos {\n";
	if (!this->esVacio()) {
		NodoGrupo* aux = this->getCab();
		for (int i = 0; i < this->getLargo(); i++) {
			respuesta += "[" + aux->getGrp()->estadistica9() + "]\n";
			aux = aux->getSgte();
		}
		respuesta += "\n	}";
	}
	else {
		respuesta += "No hay grupos registrados }";
	}

	return respuesta;
}

string ListaGrupo::estadisticas10() {
	string respuesta = "";
	if (!this->esVacio()) {
		NodoGrupo* aux = this->getCab();
		NodoEstudianteG* auxEst = aux->getGrp()->getListaEstudiantes()->estadistica9();
		NodoGrupo* mayor = aux;
		NodoEstudianteG* est = auxEst;
		for (int i = 0; i < this->getLargo(); i++) {

			if (auxEst != NULL && est == NULL) {
				mayor = aux;
				est = auxEst;
			}
			else if(auxEst != NULL && est != NULL) {
				if (auxEst->getNota() > est->getNota()) {
					mayor = aux;
					est = auxEst;
				}
			}

			aux = aux->getSgte();
			auxEst = aux->getGrp()->getListaEstudiantes()->estadistica9();
		}

		if (est != NULL) {
			respuesta = "	Grupo " + mayor->getGrp()->getCodigoMateria() + " {\n";
			respuesta += "[		Matriculados " + to_string(mayor->getGrp()->getCantidadMatriculados()) + "\n";
			respuesta += "		Estudiante " + est->getSalto()->getEst()->getNombreCompleto() + "\n";
			respuesta += "		Cedula " + est->getCedula() + "\n";
			respuesta += "		Nota " + to_string(est->getNota()) + "\n	]";
			respuesta += "\n	}";
		}
		else {
			respuesta = "	Grupo " + mayor->getGrp()->getCodigoMateria() + " {\n";
			respuesta += "[		Matriculados " + to_string(mayor->getGrp()->getCantidadMatriculados()) + "\n";
			respuesta += "		Estudiante N/A\n";
			respuesta += "		Cedula N/A\n";
			respuesta += "		Nota N/A\n	]";
			respuesta += "\n	}";
		}
	}
	else {
		respuesta += "No hay grupos registrados.";
	}
	return respuesta;
}