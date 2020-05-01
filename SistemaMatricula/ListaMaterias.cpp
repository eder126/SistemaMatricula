#include "ListaMaterias.h"
#include <sstream>
#include <vector>

ListaMaterias::ListaMaterias()
{
	setLargo(0);
	setCab(NULL);
}


ListaMaterias::~ListaMaterias()
{
}

bool ListaMaterias::esVacia()
{
	if (getLargo() == 0)
	{
		return true; //es vacia 
	}
	return false; //no es vacia
}

void ListaMaterias::setLargo(int largo)
{
	this->largo = largo;
}

void ListaMaterias::setCab(NodoMateria* cab)
{
	this->cab = cab;
}

int ListaMaterias::getLargo()
{
	return this->largo;
}

NodoMateria* ListaMaterias::getCab()
{
	return this->cab;
}


bool ListaMaterias::agregar(Materia* pmateria) //se agrega la materia al inicio 
{
	NodoMateria* nuevaMateria = new NodoMateria(pmateria);

	if (!esVacia()) {

		string codigo = pmateria->getCodigoMateria();

		if (consultar(codigo) != NULL)
		{
			return false;
		}
		else
		{
			nuevaMateria->setSgte(getCab());
			getCab()->setAnte(nuevaMateria);
			setCab(nuevaMateria);
			setLargo((getLargo() + 1));
		}
	}
	else
	{
		setCab(nuevaMateria);
		setLargo((getLargo() + 1));
	}

	return true;
}

bool ListaMaterias::eliminar(string pcodigo)//borrar por el codigo de la materia
{
	bool borrar = false;
	if (!esVacia()) {
		NodoMateria* aux = NULL;

		if (getCab()->getMateria()->getCodigoMateria() == pcodigo) {
			aux = getCab();

			if (aux->getSgte() != NULL)
				aux->getSgte()->setAnte(NULL);

			setCab(aux->getSgte());

			delete aux;

			borrar = true;
			setLargo((getLargo() - 1));
		}
		else {
			aux = consultar(pcodigo);
			if (aux != NULL) {
				aux->getAnte()->setSgte(aux->getSgte());
				aux->getSgte()->setAnte(aux->getAnte());

				delete aux;


				borrar = true;
				setLargo((getLargo() - 1));
			}
		}
	}
	return borrar;
}

NodoMateria* ListaMaterias::consultar(string pcodigo)//buscar la materia por el codigo
{

	NodoMateria* aux = NULL;
	if (!this->esVacia()) {
		aux = this->getCab();
		while (aux != NULL && aux->getMateria()->getCodigoMateria() != pcodigo) {
			aux = aux->getSgte();
		}
	}
	return aux;
}

bool ListaMaterias::modificar(Materia* x, string desc)
{
	x->modificar(desc);
	return true;
}

string ListaMaterias::mostrar() //muestra todas las materias 
{
	string texto = "";
	if (!esVacia()) {
		NodoMateria* aux = getCab();

		for (int i = 0; i < getLargo(); i++) {
			//cout << "Posicion: " << i << ", Materia: " << aux->getMateria()->datos() << endl;
			texto += aux->getMateria()->datos() + "\n\n";
			aux = aux->getSgte();
		}
	}
	else {
		//cout << "No hay datos disponibles" << endl;
		texto = "No hay materias registradas.";
	}
	return texto;
}

string ListaMaterias::mostrarCantidad() {
	string texto = "";
	if (!esVacia()) {
		NodoMateria* aux = getCab();

		for (int i = 0; i < getLargo(); i++) {
			//cout << "Posicion: " << i << ", Materia: " << aux->getMateria()->datos() << endl;
			texto += aux->getMateria()->datosGruposCantidad() + "\n\n";
			aux = aux->getSgte();
		}
	}
	else {
		//cout << "No hay datos disponibles" << endl;
		texto = "No hay materias registradas.";
	}
	return texto;
}

string ListaMaterias::mostrarCompleto() {
	string texto = "";
	if (!esVacia()) {
		NodoMateria* aux = getCab();

		for (int i = 0; i < getLargo(); i++) {
			//cout << "Posicion: " << i << ", Materia: " << aux->getMateria()->datos() << endl;
			texto += aux->getMateria()->datosGruposCompleto() + "\n\n";
			aux = aux->getSgte();
		}
	}
	else {
		//cout << "No hay datos disponibles" << endl;
		texto = "No hay materias registradas.";
	}
	return texto;
}

string ListaMaterias::mostrar(string pcodigo)//muestra una materia en especifico
{
	string texto = "";
	if (!esVacia())
	{
		NodoMateria* materia = consultar(pcodigo);
		if (materia != NULL)
			texto = materia->getMateria()->datos();
		else
			texto = "No se ha encontrado la materia que busca.";
		//cout << "Materia: " << materia->getMateria()->datos() << endl;
	}
	else
	{
		//cout << "La materia que busca no se encuentra" << endl;
		texto = "No hay materias registradas.";
	}
	return texto;
}

void ListaMaterias::limpiarParaCargar()
{
	int cant = this->getLargo() - 1;
	for (int i = 0; i <= cant; i++) {
		eliminar(this->getCab()->getMateria()->getCodigoMateria());
	}
}

void ListaMaterias::guardar()
{
	std::ofstream out("materias.txt");
	NodoMateria* aux = this->getCab();
	for (int i = 0; i < this->getLargo(); i++) {
		out << *aux->getMateria();
		aux = aux->getSgte();
	}
	out.close();
}

void ListaMaterias::cargar()
{
	limpiarParaCargar();
	std::ifstream in("materias.txt");
	bool seguir = true;

	while (seguir)
	{
		Materia mat;
		in >> mat;
		if (!mat.getCodigoMateria().empty()) {
			agregar(new Materia(mat.getCodigoMateria(), mat.getDescripcionMateria()));
		}
		else {
			seguir = false;
		}
	}
	in.close();

}


void ListaMaterias::guardarGrupos()
{
	std::ofstream out("grupos.txt");
	NodoMateria* aux = this->getCab();
	NodoGrupo* auxG;
	for (int i = 0; i < this->getLargo(); i++) {
		auxG = aux->getMateria()->getGrupos()->primer();
		for (int j = 0; j < aux->getMateria()->getGrupos()->cantidad(); j++) {
			out << *auxG->getGrp();
			auxG = auxG->getSgte();
		}
		aux = aux->getSgte();
	}
	out.close();
}

vector<string> split(string& s, char delim) {
	std::vector<string> elems;
	std::stringstream ss(s);
	std::string temp;
	while (std::getline(ss, temp, delim)) {
		elems.push_back(temp);
	}
	return elems;
}

void ListaMaterias::cargarGrupos(MaestroEstudiante* mEstud)
{
	std::ifstream in("grupos.txt");
	bool seguir = true;
	NodoMateria* aux = this->getCab();

	for (int i = 0; i < this->getLargo(); i++) {
		aux->getMateria()->getGrupos()->limpiarParaCargar();
		aux = aux->getSgte();
	}

	while (seguir)
	{

		Grupo grup;
		in >> grup;
		if (!grup.getNumeroGrupo().empty()) {
			aux = consultar(grup.getCodigoMateria());
			if (aux) {
				Grupo* grp = new Grupo(grup.getNumeroGrupo(), grup.getStatus(), grup.getCantidadMaxima(), grup.getCodigoMateria());

				vector<string> tempVector = split(grup.estudiantesTemp, ',');
				for (int i = 0; i < tempVector.size(); i++) {
					vector<string> tempEstud = split(tempVector[i], '=');
					NodoEstudiante* nEstud;
					nEstud = mEstud->buscar(tempEstud[0]);
					if (nEstud) {
						grp->getListaEstudiantes()->agregar(stod(tempEstud[1]), nEstud);
					}
					else {
						cout << "\nNo se encontro estudiante" << endl;
					}
				}


				aux->getMateria()->getGrupos()->agregar(grp);
			}
			else {
				cout << "No se encontro dicho grupo a consultar" << endl;
			}
		}
		else {
			seguir = false;
		}


	}
	in.close();
	guardarGrupos();
}



int ListaMaterias::estadisticaUno()
{
	return this->getLargo();
}



string ListaMaterias::estadisticaDos()
{
	string texto = "";
	if (!esVacia()) {
		NodoMateria* aux = getCab();
		for (int i = 0; i < getLargo(); i++) {
			int num = 0;

			NodoGrupo* auxG = aux->getMateria()->getGrupos()->primer();

			for (int j = 0; j < aux->getMateria()->getGrupos()->cantidad(); j++) {
				if(auxG->getGrp()->getStatus()) num++;
				auxG = auxG->getSgte();
			}

			texto += aux->getMateria()->getCodigoMateria() + " tiene: " + to_string(num) + " cursos abiertos."+ "\n\n";
			aux = aux->getSgte();
		}
	}
	else {
		texto = "No hay materias registradas.";
	}


	return texto;
	
}

string ListaMaterias::estadisticaTres()
{
	string texto = "";
	if (!esVacia()) {
		NodoMateria* aux = getCab();
		for (int i = 0; i < getLargo(); i++) {
			int numEstudiantes = 0;

			NodoGrupo* auxG = aux->getMateria()->getGrupos()->primer();

			for (int j = 0; j < aux->getMateria()->getGrupos()->cantidad(); j++) {
				numEstudiantes += auxG->getGrp()->getCantidadMatriculados();
				auxG = auxG->getSgte();
			}

			texto += aux->getMateria()->getCodigoMateria() + " tiene: " + to_string(numEstudiantes) + (numEstudiantes==1? " estudiante matriculado.": " estudiantes matriculados.") + "\n\n";
			aux = aux->getSgte();
		}
	}
	else {
		texto = "No hay materias registradas.";
	}


	return texto;

}


string ListaMaterias::estadisticaSeis()
{
	string texto = "";
	if (!esVacia()) {
		NodoMateria* aux = getCab();
		for (int i = 0; i < getLargo(); i++) {
			NodoGrupo* auxG = aux->getMateria()->getGrupos()->primer();
			for (int j = 0; j < aux->getMateria()->getGrupos()->cantidad(); j++) {
				if (!auxG->getGrp()->getStatus()) texto += "El grupo: " + auxG->getGrp()->getNumeroGrupo() + " de la materia " + auxG->getGrp()->getCodigoMateria() + " esta desactivado." + "\n\n";
				auxG = auxG->getSgte();
			}
			aux = aux->getSgte();
		}
	}
	else {
		texto = "No hay materias registradas.";
	}


	return texto;

}


string ListaMaterias::estadistica4_1()//4.Materia con menos matriculados
{
	NodoMateria* menor = NULL;
	if (!esVacia()) {
		NodoMateria* aux = this->getCab();
		menor = this->getCab();
		for (int i = 0; i < this->getLargo(); i++) {
			if (aux->getMateria()->getGrupos()->estadisticas4_1() < menor->getMateria()->getGrupos()->estadisticas4_1())
				menor = aux;
			aux = aux->getSgte();
		}
	}
	if (menor != NULL)
		return menor->getMateria()->datosGruposCompletoEstudiantes();
	else
		return "No hay materias registradas.";
}

string ListaMaterias::estadistica4_2()//5.Grupo con menos matriculados
{
	NodoGrupo* menor = NULL;
	if (!esVacia()) {
		NodoMateria* aux = this->getCab();
		menor = aux->getMateria()->getGrupos()->estadisticas4_2();
		for (int i = 0; i < this->getLargo(); i++) {
			if (aux->getMateria()->getGrupos()->cantidad() > 0 && menor == NULL)
				menor = aux->getMateria()->getGrupos()->estadisticas4_2();
			else if (aux->getMateria()->getGrupos()->cantidad() > 0 && menor != NULL)
				if (aux->getMateria()->getGrupos()->estadisticas4_2()->getGrp()->getCantidadMatriculados() < menor->getGrp()->getCantidadMatriculados())
					menor = aux->getMateria()->getGrupos()->estadisticas4_2();

			aux = aux->getSgte();
		}
	}
	if (menor != NULL)
		return menor->getGrp()->datosGrupo();
	else
		return "No hay grupos registrados.";
}

string ListaMaterias::estadistica5_1()//4.Materia con ms matriculados
{
	NodoMateria* mayor = NULL;
	if (!esVacia()) {
		NodoMateria* aux = this->getCab();
		mayor = this->getCab();
		for (int i = 0; i < this->getLargo(); i++) {
			if (aux->getMateria()->getGrupos()->estadisticas4_1() > mayor->getMateria()->getGrupos()->estadisticas4_1())
				mayor = aux;
			aux = aux->getSgte();
		}
	}
	else
	{
		return "No hay materias registradas.";
	}

	if (mayor != NULL)
		return mayor->getMateria()->datosGruposCompletoEstudiantes();
	else
		return "No hay materias registradas.";
}

string ListaMaterias::estadistica5_2()//5.Grupo con ms matriculados
{
	NodoGrupo* mayor = NULL;
	if (!esVacia()) {
		NodoMateria* aux = this->getCab();
		mayor = aux->getMateria()->getGrupos()->estadisticas5_2();
		for (int i = 0; i < this->getLargo(); i++) {

			if (aux->getMateria()->getGrupos()->cantidad() > 0 && mayor == NULL)
				mayor = aux->getMateria()->getGrupos()->estadisticas5_2();
			else if (aux->getMateria()->getGrupos()->cantidad() > 0 && mayor != NULL)
				if (aux->getMateria()->getGrupos()->estadisticas5_2()->getGrp()->getCantidadMatriculados() > mayor->getGrp()->getCantidadMatriculados())
					mayor = aux->getMateria()->getGrupos()->estadisticas5_2();

			aux = aux->getSgte();
		}
	}
	else
	{
		return "No hay materias registradas.";
	}

	if (mayor != NULL)
		return mayor->getGrp()->datosGrupo();
	else
		return "No hay grupos registrados.";
}

string ListaMaterias::estadisticas9()//15.Estudiantes de mejor nota por grupo
{
	string texto = "";
	if (!esVacia()) {
		NodoMateria* aux = this->getCab();
		for (int i = 0; i < this->getLargo(); i++) {
			texto += aux->getMateria()->estadisticas9() + "\n\n";
			aux = aux->getSgte();
		}
	}
	else {
		return "No hay materias registradas.";
	}

	return texto;
}

string ListaMaterias::estadisticas10()//16.Listado de estudiantes con mxima nota entre todas las materias
{
	string texto = "";
	if (!this->esVacia()) {
		NodoMateria* aux = this->getCab();
		for (int i = 0; i < this->getLargo(); i++) {
			texto += aux->getMateria()->estadisticas10() + "\n\n";
			aux = aux->getSgte();
		}
	}
	else {
		return "No hay materias registradas.";
	}

	return texto;
}
