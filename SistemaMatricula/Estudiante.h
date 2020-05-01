#pragma once
#include <string>
#include <fstream>
using namespace std;
class Estudiante
{
private:
    string cedula, nombreCompleto, numeroCel, correoE;
    bool activo;

public:
    Estudiante();
    Estudiante(string cedula, string nombreCompleto, string numeroCel, string correoE, bool activo);
    ~Estudiante();
    string getCedula() const;
    void setCedula(string cedula);

    string getNombreCompleto() const;
    void setNombreCompleto(string nombreCompleto);

    string getNumeroCel() const;
    void setNumeroCel(string numeroCel);

    string getCorreoE() const;
    void setCorreoE(string correoE);

    bool getActivo() const;
    void setActivo(bool activo);
    void modificar();

    string datos();
    string datosFormato();

    friend std::ostream& operator << (std::ostream& out, const Estudiante& obj);
    friend std::istream& operator >> (std::istream& in, Estudiante& obj);
};
