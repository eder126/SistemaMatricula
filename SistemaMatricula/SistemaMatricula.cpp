#include <iostream>
#include <string>
#include <stdlib.h>
#include <chrono>
#include <thread>
using namespace std;
#include "ListaMaterias.h"
//#include "ListaGrupo.h" //ListaMaterias ahora lo incluira

MaestroEstudiante* est = new MaestroEstudiante();
ListaMaterias* mat = new ListaMaterias();

void animacion();
int menuInicial();
int menuEstadisticas();
int menuEstudiante();
int menuMateria();
int manejarGrupoMateria(Materia*);
int manejarEstudianteGrupo(Grupo*);

void procesarInicial(int);
void procesarEstadisticas(int);
void procesarEstudiante(int);
void procesarMateria(int);
void procesarGrupo(int, Materia*);
void procesarEstudiante(int, Grupo*);

int main()
{   
    //Cargar los datos de los archivos de texto
    cout << "Leyendo estudiantes.txt" << endl;
    est->cargar();
    //Solamente animacion
    animacion();
    //Cargar los datos de los archivos de texto
    cout << "Leyendo materias.txt" << endl;
    mat->cargar();
    //Solamente animacion
    animacion();
    //Cargar los datos de los archivos de texto
    cout << "Leyendo grupos.txt" << endl;
    mat->cargarGrupos(est);
    //Solamente animacion
    animacion();

    system("color f");
   
    system("CLS");
    
    int opc = 0;
    do {
        opc = menuInicial();
        cin.clear();
        cin.ignore();
        procesarInicial(opc);
    } while (opc != 0);
    return opc;

}

void animacion() {
    system("color 0e");
    std::cout << "[";
    for (int i = 0; i < 35; i++) {
        std::this_thread::sleep_for(0.04s);
        std::cout << ":";
    }
    std::cout << "]" << endl;
    std::this_thread::sleep_for(0.3s);
}

int menuInicial() {
    string texto = "\nMenu Principal\n";
    texto += "1.Manejo de Estudiantes\n2.Manejo de Materias\n3.Estadisticas\n";
    texto += "0.Salir\n";
    texto += "Opcion: ";

    std::cout << texto;
    int opcion;
    cin.clear();
    cin >> opcion;
    if (cin.fail())
    {
        cout << "Porfavor digite un numero";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << texto;
    }
    system("CLS");
    return opcion;
}

int menuEstadisticas() {
    string texto = "\nMenu Principal\n";
    texto += "1.Materias abiertas\n";
    texto += "2.Cursos abiertos por materia\n";
    texto += "3.Estudiantes matriculados por materia\n";
    texto += "4.Materia con menos matriculados\n";
    texto += "5.Grupo con menos matriculados\n";
    texto += "6.Materia con mas matriculados\n";
    texto += "7.Grupo con mas matriculados\n";
    texto += "8.Listado de grupos cerrados (Desactivados)\n";
    texto += "9.Estudiantes activos (cedula-nombre) de una materia\n";
    texto += "10.Estudiantes activos (cedula-nombre) de un grupo\n";
    texto += "11.Estudiantes activos (cedula-nombre) de toda la universidad\n";
    texto += "12.Estudiantes inactivos( cedula-nombre) de una materia\n";
    texto += "13.Estudiantes inactivos( cedula-nombre) de un grupo\n";
    texto += "14.Estudiantes inactivos( cedula-nombre) de toda la universidad\n";
    texto += "15.Estudiantes de mejor nota por grupo\n";
    texto += "16.Listado de estudiantes con máxima nota entre todas las materias\n";
    texto += "0.Volver\n";
    texto += "Opcion: ";

    std::cout << texto;
    int opcion;
    cin.clear();
    cin >> opcion;
    if (cin.fail())
    {
        cout << "Porfavor digite un numero";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << texto;
    }
    system("CLS");
    return opcion;
}

int menuEstudiante() {
    string texto = "\nMenu Estudiantes\n";
    texto += "1.Registrar nuevo estudiante\n2.Modificar estudiante\n3.Borrar estudiante\n";
    texto += "\nConsultas\n";
    texto += "4.Buscar estudiante\n5.Mostrar todos los estudiantes\n6.Vaciar lista de estudiantes\n";
    texto += "7.La lista esta vacia?\n8.Cuantos estudiantes hay registrados?\n";
    texto += "0.Volver\n";
    texto += "Opcion: ";
    std::cout << texto;
    int opcion;
    cin.clear();
    cin >> opcion;
    if (cin.fail())
    {
        cout << "Porfavor digite un numero";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << texto;
    }
    system("CLS");
    return opcion;
}

int menuMateria() {
    string texto = "\nMenu Materias\n";
    texto += "1.Registrar nueva materia\n2.Modificar materia\n3.Borrar materia\n";
    texto += "Consultas\n";
    texto += "4.Buscar materia\n5.Mostrar todas las materias\n";
    texto += "6.Mostrar todas las materias y cantidad de grupos\n7.Mostrar todas las materias y grupos en detalle\n";
    texto += "8.Administrar grupos de materia\n";
    texto += "0.Volver\n";
    texto += "Opcion: ";
    std::cout << texto;
    int opcion;
    cin.clear();
    cin >> opcion;
    if (cin.fail())
    {
        cout << "Porfavor digite un numero";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << texto;
    }
    system("CLS");
    return opcion;
}

int manejarGrupoMateria(Materia* materia) {
    string texto = "\nMenu de materia "+ materia->getCodigoMateria()+"\n";
    texto += "1.Registrar grupo\n2.Modificar grupo\n3.Borrar grupo\n";
    texto += "Consultas\n";
    texto += "4.Buscar grupo\n";
    texto += "5.Mostrar todos los grupos\n6.Mostrar todos los grupos y estudiantes en detalle\n";
    texto += "7.Administrar estudiantes de grupo\n";
    texto += "0.Volver\n";
    texto += "Opcion: ";
    std::cout << texto;
    int opcion;
    cin.clear();
    cin >> opcion;
    if (cin.fail())
    {
        cout << "Porfavor digite un numero";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << texto;
    }
    system("CLS");
    return opcion;
}

int manejarEstudianteGrupo(Grupo* grp) {
    string texto = "\nMenu de grupo " + grp->getNumeroGrupo() + "\n";
    texto += "1.Registrar estudiante\n2.Borrar estudiante\n3.Modificar nota estudiante\n";
    texto += "Consultas\n";
    texto += "4.Cantidad de estudiantes en el grupo\n5.Buscar estudiante\n6.Mostrar todos los estudiantes\n7.Mostrar todos los estudiantes en detalle\n";
    texto += "0.Volver\n";
    texto += "Opcion: ";
    std::cout << texto;
    int opcion;
    cin.clear();
    cin >> opcion;
    if (cin.fail())
    {
        cout << "Porfavor digite un numero";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << texto;
    }
    system("CLS");
    return opcion;
}

/*AGREGAR OPCION PARA MANIPULAR ESTUDIANTES DE GRUPO*/

void procesarInicial(int opcion) {
    std::cout << endl;
    system("CLS");
    int opc = 0;
    switch (opcion) {
    case 1:
        do {
            opc = menuEstudiante();
            procesarEstudiante(opc);
        } while (opc != 0);
        break;
    case 2:
        do {
            opc = menuMateria();
            procesarMateria(opc);
        } while (opc != 0);
        break;
    case 3:
        do {
            opc = menuEstadisticas();
            procesarEstadisticas(opc);
        } while (opc != 0);
        break;
    case 0:
        std::cout << "Adios!" << endl;
        break;
    default:
        std::cout << "Opcion invalida" << endl;
        break;
    }
    std::cout << endl;
}

void procesarEstadisticas(int opcion) {
    switch (opcion) {
    case 1://1.Materias abiertas
        {
        int total = mat->estadisticaUno();
        cout << "Hay " << total << (total == 1 ? " materia abierta." : " materias abiertas.") << endl;
        break;
        }
    case 2://2.Cursos abiertos por materia
        cout << mat->estadisticaDos() << endl;
        break;
    case 3://3.Estudiantes matriculados por materia
        cout << mat->estadisticaTres() << endl;
        break;
    case 4://4.Materia con menos matriculados
        cout << mat->estadistica4_1() << endl;
        break;
    case 5://5.Grupo con menos matriculados
        cout << mat->estadistica4_2() << endl;
        break;
    case 6://6.Materia con más matriculados
        cout << mat->estadistica5_1() << endl;
        break;
    case 7://7.Grupo con más matriculados
        cout << mat->estadistica5_2() << endl;
        break;
    case 8://8.Listado de grupos cerrados(Desactivados)
        cout << mat->estadisticaSeis() << endl;
        break;
    case 9://9.Estudiantes activos(cédula - nombre) de una materia
    {
        string codigoMateria;
        cout << "Codigo de materia a investigar por estudiantes activos: "; cin >> codigoMateria;
        NodoMateria* materia = mat->consultar(codigoMateria);
        if (materia != NULL) {
            cout << "Estudiantes activos de materia - " << codigoMateria << "\n" << materia->getMateria()->estadisticas78_1(true) << endl;
        }
        else {
            cout << "No se ha encontrado la materia que desea investigar por estudiantes activos." << endl;
        }
    }
    break;
    case 10://10.Estudiantes activos(cédula - nombre) de un grupo
    {
        string codigoMateria;
        cout << "Codigo de materia a investigar por estudiantes activos: "; cin >> codigoMateria;
        NodoMateria* materia = mat->consultar(codigoMateria);
        if (materia != NULL) {
            string codigoGrupo;
            cout << "Codigo de grupo a investigar por estudiantes activos: "; cin >> codigoGrupo;
            NodoGrupo* nGrupo = materia->getMateria()->getGrupos()->consultar(codigoGrupo);
            if (nGrupo!= NULL) {
                cout << "Estudiantes activos del grupo (" << codigoGrupo << ")\n" << nGrupo->getGrp()->estadisticas78_1(true) << endl;
            }
            else {
                cout << "No ha encontrado el grupo que desea investigar por estudiantes activos." << endl;
            }
        }
        else {
            cout << "No ha encontrado la materia que busca." << endl;
        }
    }
    break;
    case 11://11.Estudiantes activos(cédula - nombre) de toda la universidad
        cout << "Estudiantes activos de la universidad\n" << est->estadisticas78_3(true) << endl;
        break;
    /*8.Listado de estudiantes inactivos( cédula-nombre) de un curso, grupo o de toda la universidad.*/
    case 12://12.Estudiantes inactivos(cédula - nombre) de una materia
    {
        string codigoMateria;
        cout << "Codigo de materia a investigar por estudiantes inactivos: "; cin >> codigoMateria;
        NodoMateria* materia = mat->consultar(codigoMateria);
        if (materia != NULL) {
            cout << "Estudiantes inactivos de materia - " << codigoMateria << "\n" << materia->getMateria()->estadisticas78_1(false) << endl;
        }
        else {
            cout << "No se ha encontrado la materia que desea investigar por estudiantes inactivos." << endl;
        }
    }
        break;
    case 13://13.Estudiantes inactivos(cédula - nombre) de un grupo
    {
        string codigoMateria;
        cout << "Codigo de materia a investigar por estudiantes inactivos: "; cin >> codigoMateria;
        NodoMateria* materia = mat->consultar(codigoMateria);
        if (materia != NULL) {
            string codigoGrupo;
            cout << "Codigo de grupo a investigar por estudiantes inactivos: "; cin >> codigoGrupo;
            NodoGrupo* nGrupo = materia->getMateria()->getGrupos()->consultar(codigoGrupo);
            if (nGrupo != NULL) {
                cout << "Estudiantes inactivos del grupo (" << codigoGrupo << ")\n" << nGrupo->getGrp()->estadisticas78_1(false) << endl;
            }
            else {
                cout << "No ha encontrado el grupo que desea investigar por estudiantes inactivos." << endl;
            }
        }
        else {
            cout << "No ha encontrado la materia que busca." << endl;
        }
    }
        break;
    case 14://14.Estudiantes inactivos(cédula - nombre) de toda la universidad
        cout << "Estudiantes inactivos de la universidad\n" << est->estadisticas78_3(false) << endl;
        break;
    case 15://15.Estudiantes de mejor nota por grupo
        cout << mat->estadisticas9() << endl;
        break;
    case 16://16.Listado de estudiantes con máxima nota entre todas las materias
        cout << "Maxima nota por materia\n" << mat->estadisticas10() << endl;
        break;
    case 0:
        std::cout << "Regresar" << endl;
        system("CLS");
        break;
    default:
        std::cout << "Opcion invalida" << endl;
        break;
    }
    std::cout << endl;
}


void procesarEstudiante(int opcion) {
    std::cout << endl;
    system("CLS");
    Estudiante* estud;
    NodoEstudiante* nEstud;
    string cedulaEstudiante, nombreCompletoEstudiante, numeroCelEstudiante, correoEEstudiante;
    bool estadoEstudiante, error = false;
    switch (opcion) {
    case 1:
        cin.clear();
        cin.ignore();
        std::cout << "Cedula del estudiante" << endl;
        cin >> cedulaEstudiante;
        if (est->buscar(cedulaEstudiante)) {
            std::cout << "Ya existe un estudiante con dicha cedula";
            break;
        }
        cin.ignore();
        cin.clear();
        std::cout << "Nombre completo" << endl;
        getline(cin, nombreCompletoEstudiante);
        cin.clear();
        std::cout << "Celular" << endl;
        getline(cin, numeroCelEstudiante);
        cin.clear();
        std::cout << "Correo del estudiante" << endl;
        getline(cin, correoEEstudiante);
        cin.clear();
        std::cout << "Estado del estudiante (0 = inactivo, 1 = activo)" << endl;
        if (!(cin >> estadoEstudiante)) error = true;
        cin.clear();

        if (cedulaEstudiante.empty() || nombreCompletoEstudiante.empty() || numeroCelEstudiante.empty() || correoEEstudiante.empty()) {
            std::cout << "Debe llenar todos los datos." << endl;
            error = true;
        }


        if (!error) {
            estud = new Estudiante(cedulaEstudiante, nombreCompletoEstudiante, numeroCelEstudiante, correoEEstudiante, estadoEstudiante);
            est->agregarInicio(estud);
            est->guardar();
        }
        else {
            std::cout << "Ocurrio un error" << endl;
        }

        break;

    case 2:
        std::cout << "Porfavor digite la cedula del estudiante que le desea cambiar el estado" << endl;
        cin >> cedulaEstudiante;
        nEstud = est->buscar(cedulaEstudiante);
        if (nEstud) {
            estud = nEstud->getEst();
            estud->modificar();
            std::cout << "El estado de " + estud->getNombreCompleto() + " ahora es: " + (estud->getActivo() == 1 ? "Activo" : "Inactivo") << endl;
            est->guardar();
        }
        else 
            std::cout << "No se ha encontrado dicho estudiante" << endl;
        
        break;

    case 3:
        std::cout << "Porfavor digite la cedula del estudiante que desea eliminar" << endl;
        cin >> cedulaEstudiante;
        if (est->borrar(cedulaEstudiante)) {
           std::cout << "Se ha eliminado el estudiante con dicha cedula" << endl;
           est->guardar();
           //Se actualiza para que se borren de los grupos dicho estudiante. Hay que mejorar el eliminarTodoParaCargar dentro de la funcion
           mat->cargarGrupos(est);
        }
        else 
            std::cout << "No se ha encontrado dicho estudiante" << endl;
        
        break;

    case 4:
        std::cout << "Porfavor digite la cedula del estudiante que desea buscar" << endl;
        cin >> cedulaEstudiante;
        nEstud = est->buscar(cedulaEstudiante);
        if (nEstud) {
            std::cout << "El estudiante consultado es: " + nEstud->getEst()->datos() << endl;
        }
        else 
            std::cout << "No se ha encontrado dicho estudiante" << endl;
        
        break;

    case 5:
        if (est->esVacia())
            std::cout << "No hay estudiantes registrados." << endl;
        else
            std::cout << est->desplegar() << endl;
        break;

    case 6:
        if (est->esVacia())
            std::cout << "No hay estudiantes registrados." << endl;
        else {
            est->limpiar();
            est->guardar();
            est->cargar();
            mat->cargar();
            mat->cargarGrupos(est);
            std::cout << "Se ha limpiado la lista." << endl;
        }
            
        break;
    case 7:         //La lista esta vacia
        if (est->esVacia())
            std::cout << "No hay estudiantes registrados." << endl;
        else
            std::cout << "Hay estudiantes registrados." << endl;

        break;
    case 8:
        //Cuantos estudiantes hay registrados
        if (est->esVacia())
            std::cout << "No hay estudiantes registrados." << endl;
        else
            std::cout << "Hay " << est->cantidad() << " estudiantes registrados." << endl;

        break;
    case 0:
        std::cout << "Regresar" << endl;
        system("CLS");
        break;
    default:
        std::cout << "Opcion invalida" << endl;

        break;
    }
    std::cout << endl;
}

void procesarMateria(int opcion) {
    std::cout << endl;
    system("CLS");
    NodoMateria* nMat;
    Materia* materia;
    string codigo = "";
    string descripcion = "";
    cin.clear();
    switch (opcion) {
    case 1:
        //Registrar nueva materia
        std::cout << "Codigo de materia: " << endl; cin >> codigo;
        cin.ignore();
        std::cout << "Descripcion: " << endl; getline(cin, descripcion);
        if (codigo.empty() || descripcion.empty()) {
            std::cout << "Debe llenar todos los datos." << endl;
            break;
        }
        if (mat->agregar(new Materia(codigo, descripcion))) {
            std::cout << "Materia registrada.\n" << endl;
            mat->guardar();
        }
        else
            std::cout << "\nEl codigo de la materia ya existe.\n" << endl;
        break;
    case 2:         //Modificar materia
        std::cout << "Porfavor digite el codigo de la materia que desea modificar" << endl;
        cin >> codigo;
        nMat = mat->consultar(codigo);
        if (nMat) {
            std::cout << "Porfavor digite la nueva descripcion" << endl;
            cin.ignore();
            getline(cin, descripcion);
            if (descripcion.empty()) {
                std::cout << "La descripcion no puede ser vacia" << endl;
                break;
            }
            materia = nMat->getMateria();
            materia->modificar(descripcion);
            std::cout << "La nueva descripcion de la materia " + materia->getCodigoMateria() << " es: " << materia->getDescripcionMateria() << endl;
            mat->guardar();
        }
        else
            std::cout << "No se ha encontrado dicha materia" << endl;

        break;
    case 3:         //Borrar materia

        std::cout << "Porfavor digite el codigo de la materia que desea eliminar" << endl;
        cin >> codigo;

        nMat = mat->consultar(codigo);
        if (nMat) {
            if (!nMat->getMateria()->getGrupos()->esVacio()) {
                std::cout << "La materia tiene uno o mas grupos asignados. Por ende no podra ser eliminada."<<endl;
                break;
            }
        }

        if (mat->eliminar(codigo)) {
            std::cout << "Se ha eliminado la materia con dicho codigo" << endl;
            mat->guardar();
        }
        else
            std::cout << "No se ha encontrado dicha materia" << endl;

        break;
    case 4:         //Buscar materia
        std::cout << "Porfavor digite el codigo de la materia que desea buscar" << endl;
        cin >> codigo;
        nMat = mat->consultar(codigo);
        if (nMat) {
            std::cout << "La materia consultada es: " + nMat->getMateria()->datos() << endl;
        }
        else
            std::cout << "No se ha encontrado dicha materia" << endl;

        break;
    case 5:         //Mostrar todas las materias
        std::cout << mat->mostrar() << endl;
        break;
    case 6:         //Mostrar todas las materias y cantidad de grupos
        std::cout << mat->mostrarCantidad() << endl;
        break;
    case 7:         //Mostrar todas las materias y grupos en detalle
        std::cout << mat->mostrarCompleto() << endl;
        break;
    case 8:
    {
        std::cout << "Codigo de materia a administrar: " << endl; cin >> codigo;
        nMat = mat->consultar(codigo);

        if (nMat) {
            materia = nMat->getMateria();
            do {
                opcion = manejarGrupoMateria(materia);
                procesarGrupo(opcion, materia);
            } while (opcion != 0);
        }
        else {
            std::cout << "No se ha encontrado la materia que desea administrar." << endl;
        }
    }
        break;
    case 0:
        std::cout << "Regresar" << endl;
        break;
    default:
        std::cout << "Opcion invalida" << endl;
        break;
    }
    std::cout << endl;
}

//Grupos tiene que accederse por medio de una materia
void procesarGrupo(int opcion, Materia* materia) {
    std::cout << endl;
    system("CLS");
    string numeroG = "";
    int cantidadMaxima = 0;
    bool status = false;
    NodoGrupo* ngrp;
    switch (opcion) {
    case 1:
    {
        //Registrar grupo
        if (materia != NULL) {
            cout << "Numero de grupo: GRP"; cin >> numeroG;
            cin.clear();

            std::cout << "Esta activo(Si(1),No(0)): " << endl;
            if (!(cin >> status)) {
                std::cout << "El status será inactivo.";
                status = false;
            }
            std::cout << "Cupo de estudiantes: " << endl; cin >> cantidadMaxima;

            materia->getGrupos()->agregar(new Grupo(("GRP" + numeroG), status, cantidadMaxima, materia->getCodigoMateria()));
            mat->guardarGrupos();
        }
        else {
            std::cout << "No se ha encontrado la materia que busca." << endl;
        }
    }
        break;
    case 2:         //Modificar grupo
    {
        cin.clear();
        std::cout << "Codigo de grupo a modificar (abrir/cerrar): " << endl; cin >> numeroG;
        ngrp = materia->getGrupos()->consultar(numeroG);
        if (ngrp != NULL) {

            ngrp->getGrp()->modificar();
            std::cout << "El estado de " + ngrp->getGrp()->getNumeroGrupo() + " ahora es: " + (ngrp->getGrp()->getStatus() == 1 ? "Activo" : "Inactivo") << endl;
            mat->guardarGrupos();

        }
        else {
            std::cout << "No se ha encontrado el grupo que desea modificar." << endl;
        }
    }
        break;
    case 3:         //Borrar grupo
    {
        cin.clear();
        std::cout << "Codigo de grupo a eliminar: " << endl; cin >> numeroG;
        ngrp = materia->getGrupos()->consultar(numeroG);
        if (ngrp != NULL) {
            
            if (ngrp->getGrp()->getListaEstudiantes()->esVacio()) {
                materia->getGrupos()->eliminar(numeroG);
                std::cout << "\nSe ha eliminado el grupo." << endl;
            }
            else {
                std::cout << "\nHay estudiantes registrados. No se puede eliminar este grupo." << endl;
            }
        }
        else {
            std::cout << "No se ha encontrado el grupo que desea eliminar." << endl;
        }
        break;
    }
    case 4:         //Buscar grupo
    {
        cin.clear();
        std::cout << "Codigo de grupo a buscar: " << endl; cin >> numeroG;
        ngrp = materia->getGrupos()->consultar(numeroG);
        if (ngrp != NULL) {
            std::cout << ngrp->getGrp()->datosGrupo() << "Estudiantes\n" << ngrp->getGrp()->getListaEstudiantes()->mostrar() << endl;
        }
        else {
            std::cout << "No se ha encontrado el grupo que busca." << endl;
        }
        break;
    }
    case 5:         //Mostrar todos los grupos
    {
        std::cout << materia->getGrupos()->mostrar() << endl;
    }
        break;
    case 6:         //Mostrar todos los grupos con estudiantes
    {
        std::cout << materia->getGrupos()->mostrarCompleto() << endl;
    }
    break;
    case 7:         //Administrar estudiantes de grupo
    {
        std::cout << "Codigo de grupo a administrar: " << endl; 
        cin >> numeroG;
        cin.clear();
        NodoGrupo* nGrupo = materia->getGrupos()->consultar(numeroG);
        if (nGrupo) {
            Grupo* temp = nGrupo->getGrp();
            do {
                opcion = manejarEstudianteGrupo(temp);
                procesarEstudiante(opcion, temp);
            } while (opcion != 0);
        }
        else {
            std::cout << "No se ha encontrado el grupo que desea administrar." << endl;
        }
    }
        break;
    case 0:
        std::cout << "Regresar" << endl;
        break;
    default:
        std::cout << "Opcion invalida" << endl;
        break;
    }
    std::cout << endl;
}

void procesarEstudiante(int opcion, Grupo* grp) {
    std::cout << endl;
    system("CLS");
    string cedula;
    switch (opcion) {
    case 1:         //Registrar estudiante
    {
        if (grp != NULL) {
            if (grp->getListaEstudiantes()->cantidad() >= grp->getCantidadMaxima()) {
                std::cout << "El grupo ya esta en la cantidad maxima de estudiantes matriculados." << endl;
                break;
            }
            std::cout << "Cedula del estudiante" << endl;
            cin >> cedula;

            NodoEstudiante* estudianteTemp = est->buscar(cedula);
            if (estudianteTemp) {
                if (estudianteTemp->getEst()->getActivo()) {
                    double nota = 0;
                    std::cout << "Digite la nota del estudiante." << endl;
                    cin >> nota;
                    if (nota < 0 || nota>100) {
                        std::cout << "La nota debe estar entre 0 y 100." << endl;
                        break;
                    }
                    if (grp->getListaEstudiantes()->agregar(nota, estudianteTemp)) {
                        mat->guardarGrupos();
                        std::cout << "Se ha agregado con exito el estudiante." << endl;
                    }
                    else
                        std::cout << "El estudiante ya se encuentra matriculado en el grupo." << endl;
                }
                else {
                    std::cout << "El estudiante esta desactivado y no podra ser añadido al grupo." << endl;
                }

            }
            else {
                std::cout << "No se ha encontrado el estudiante que busca." << endl;
            }

        }
        else {
            std::cout << "No se ha encontrado el grupo que busca." << endl;
        }
    }
    break;
    case 2:         //Borrar estudiante
    {
        std::cout << "Porfavor digite la cedula del estudiante que desea retirar" << endl;
        cin >> cedula;
        if (grp->getListaEstudiantes()->eliminar(cedula)) {
            std::cout << "Se elimino con exito al estudiante del grupo." << endl;
            mat->guardarGrupos();
        }
        else
            std::cout << "No se ha encontrado a dicho estudiante" << endl;
        break;
    }
    case 3:         //Modificar nota del estudiante
    {
        std::cout << "Cedula del estudiante" << endl;
        cin >> cedula;

        NodoEstudianteG* estudianteTemp = grp->getListaEstudiantes()->consultar(cedula);
        if (estudianteTemp) {

            double nota = 0;
            std::cout << "Digite la nueva nota del estudiante." << endl;
            cin >> nota;

            if (nota < 0 || nota>100) {
                std::cout << "La nota debe estar entre 0 y 100." << endl;
                break;
            }

            estudianteTemp->setNota(nota);
            mat->guardarGrupos();
            std::cout << "Se ha agregado con exito el estudiante." << endl;


        }
        else {
            std::cout << "No se ha encontrado el estudiante que busca." << endl;
        }
        break;
    }
    case 4:         //Cantidad de estudiantes en el grupo
    {
        int cant = grp->getListaEstudiantes()->cantidad();
        if (cant > 0)
            if(cant == 1)
                cout << "Hay 1 estudiante matriculado." << endl;
            else
                cout << "Hay " << cant << " estudiantes matriculados." << endl;
        else
            std::cout << "No hay estudiantes matriculados en este grupo." << endl;
        break;
    }
    case 5:         //Buscar estudiante
    {
        std::cout << "Cedula del estudiante a buscar: "; cin >> cedula;
        NodoEstudianteG* estu = grp->getListaEstudiantes()->consultar(cedula);
        if (est != NULL) {
            std::cout << estu->datos() << endl; //CAMBIAR TODOS LOS DATOS A STRING
        }
        else {
            std::cout << "No se ha encontrado en este grupo el estudiante que busca." << endl;
        }
        break;
    }
    case 6:         //Mostrar todos los estudiantes
    {
        if (!grp->getListaEstudiantes()->esVacio())
            std::cout << grp->getListaEstudiantes()->mostrar() << endl;
        else
            std::cout << "No hay estudiantes matriculados en este grupo." << endl;
        break;
    }
    case 7:         //Mostrar todos los estudiantes en detalle
    {
        if (!grp->getListaEstudiantes()->esVacio())
            std::cout << grp->getListaEstudiantes()->mostrarCompleto() << endl;
        else
            std::cout << "No hay estudiantes matriculados en este grupo." << endl;
        break;
    }
    case 0:
        std::cout << "Regresar" << endl;
        break;
    default:
        std::cout << "Opcion invalida" << endl;
        break;
    }
    std::cout << endl;
    
}