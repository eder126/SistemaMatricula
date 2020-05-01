#include "Materia.h"

Materia::Materia()
{
	setCodigoMateria("");
	setDescripcionMateria("");
	setGrupos(new ListaGrupo());
}

Materia::Materia(string pcodigo, string pdescripcion)
{
	setCodigoMateria(pcodigo);
	setDescripcionMateria(pdescripcion);
	setGrupos(new ListaGrupo());
}

void Materia::setCodigoMateria(string pcodigo)
{
	this->codigoMateria = pcodigo;
}

void Materia::setDescripcionMateria(string pdescripcion)
{
	this->descripcionMateria = pdescripcion;
}

string Materia::getCodigoMateria()
{
	return codigoMateria;
}

string Materia::getDescripcionMateria()
{
	return descripcionMateria;
}

string Materia::datos()
{
	return "Codigo: " + getCodigoMateria() + " \nDescripcion: " + getDescripcionMateria();
}

string Materia::datosGruposCantidad() {
	return "Codigo: " + getCodigoMateria() + " \nDescripcion: " + getDescripcionMateria() + "\nGrupos: ("+ to_string(this->getGrupos()->cantidad())+")";
}

string Materia::datosGruposCompleto() {
	return "Codigo: " + getCodigoMateria() + " \nDescripcion: " + getDescripcionMateria() + "\nGrupos: [" + this->getGrupos()->mostrar() + "]";
}

string Materia::datosGruposCompletoEstudiantes() {
	return "Codigo: " + getCodigoMateria() + " \nDescripcion: " + getDescripcionMateria() + "\nGrupos: [" + this->getGrupos()->mostrarCompleto() + "]";
}

ListaGrupo* Materia::getGrupos()
{
    return grupos;
}

void Materia::modificar(string desc)
{
	this->setDescripcionMateria(desc);
}

void Materia::setGrupos(ListaGrupo* grupos)
{
    this->grupos = grupos;
}

string Materia::estadisticas78_1(bool estado){
	return "Materia codigo - " + this->getCodigoMateria() + "\n" + this->getGrupos()->estadisticas78_1(estado);
}

string Materia::estadisticas9() {
	return "Materia codigo - " + this->getCodigoMateria() + "\n" + this->getGrupos()->estadisticas9();
}

string Materia::estadisticas10() {
	return "Materia codigo - " + this->getCodigoMateria() + "\n" + this->getGrupos()->estadisticas10();
}

std::ostream& operator<<(std::ostream& out, const Materia& obj)
{
    out << obj.codigoMateria << "\n" << obj.descripcionMateria << "\n" << std::endl;
    return out;
}

std::istream& operator>>(std::istream& in, Materia& obj)
{
    getline(in, obj.codigoMateria);
    getline(in, obj.descripcionMateria);
    in.ignore(1);
    return in;
}