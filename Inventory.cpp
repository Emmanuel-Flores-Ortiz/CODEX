#include <iostream>
#include <string>

struct Objeto //CADA OBJETO --> Aun no conectados
{
    int id;
    std::string nombre;
    std::string categoria;
};

struct Casilla_del_objeto //CADA CASILLA DEL INVENTARIO --> Es el tickect de busqueda
{
    int id;
    int cantidad;
};

struct Inventario //ES EL INVENTARIO COMPLETO
{
    Casilla_del_objeto* lista_de_casilla; //Aqui 'lista_de_casilla' tiene acceso por un * a 'Casilla_del objeto' y a su contenido
    int total_de_casillas;
};


int main()
{
    Inventario el_inventario;
    el_inventario.total_de_casillas;
    std:: cout << "Ingrese la cantidad de caaillas iniciales: ";
    std:: cin >> el_inventario.total_de_casillas;

    el_inventario.lista_de_casilla = new Casilla_del_objeto[el_inventario.total_de_casillas];
    el_inventario.lista_de_casilla[0].id = 30;


    std::cout << el_inventario.lista_de_casilla[0].id << std::endl;
    std:: cout << el_inventario.total_de_casillas << std::endl;

    delete [] el_inventario.lista_de_casilla;

    return 0;
}