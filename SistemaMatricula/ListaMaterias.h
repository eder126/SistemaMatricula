#pragma once
#include "NodoMateria.h"
#include "Materia.h"
#include "MaestroEstudiante.h"

class ListaMaterias
{
private:

	int largo;
	NodoMateria* cab;

	void setLargo(int largo);
	void setCab(NodoMateria* cab);

	int getLargo();
	NodoMateria* getCab();
	void limpiarParaCargar();

public:

	ListaMaterias();
	~ListaMaterias();
	bool esVacia();
	bool agregar(Materia* pmateria);
	bool eliminar(string pcodigo);
	NodoMateria* consultar(string pcodigo);
	bool modificar(Materia* pmateria, string pcodigo);
	string mostrar();
	string mostrarCantidad();
	string mostrarCompleto();
	string mostrar(string pcodigo);

	string estadistica4_1();//4.Materia con menos matriculados
	string estadistica4_2();//5.Grupo con menos matriculados
	string estadistica5_1();//6.Materia con más matriculados
	string estadistica5_2();//7.Grupo con más matriculados
	string estadisticas8_1();//12.Estudiantes inactivos(cédula - nombre) de una materia
	string estadisticas9();//15.Estudiantes de mejor nota por grupo
	string estadisticas10();//16.Listado de estudiantes con máxima nota entre todas las materias

	void guardarGrupos();
	void cargarGrupos(MaestroEstudiante* mEstud);

	void guardar();
	void cargar();


	int estadisticaUno();
	string estadisticaDos();
	string estadisticaTres();
	string estadisticaSeis();
};