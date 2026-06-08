#include <iostream>
#include <string>

struct Objeto //CADA OBJETO --> Aun no conectados
{
    int id;
    std::string nombre;
    std::string categoria;
};

const int objetos = 3; // CANTIDAD DE OBJETOS EXISTENTES EN EL JUEGO
Objeto universo_de_objetos[objetos] =
{
    {0, "Objeto Nulo", "N/A"},
    {1, "Monedas", "Consumible"},
    {2, "Carnde de Dragon Ahumado", "Consumible"}
};

struct Casilla_del_objeto //CADA CASILLA DEL INVENTARIO --> Es el tickect de busqueda
{
    int id;
    int cantidad = 1;
};

struct Inventario //ES EL INVENTARIO COMPLETO
{
    Casilla_del_objeto* lista_de_casilla; //Aqui 'lista_de_casilla' tiene acceso por un * a 'Casilla_del objeto' y a su contenido
    int total_de_casillas;
};

void imprimir_objeto(const Casilla_del_objeto& casilla, const Inventario& inventario);


int main()
{
    //VARIABLES DECORATIVAS
    std::string x = "===============================================\n";


    //CREACION DEL INVENTARIO
    Inventario el_inventario;
    el_inventario.total_de_casillas = 3; //Oye memoria, ten tu valor para el tipo de dato que guardaras.
    el_inventario.lista_de_casilla = new Casilla_del_objeto[el_inventario.total_de_casillas]; //Oye memeoria, guardame una pedacito de memoria de este tipo de dato

    //ESTAA PARTE EXPLICA QUE ID TIENE CADA CASILLA Y CUANTAS CASILLAS ESTAN HABILITADAS
    std:: cout << x << "INVENTARIO (Que id, tiene cada casilla | Cuantas casillas hay registrados)\n";
    for (int i = 0; i < el_inventario.total_de_casillas; i++) {
        el_inventario.lista_de_casilla[i].id = i;
        std::cout << el_inventario.lista_de_casilla[i].id << std::endl;
    }

    //std::cout << el_inventario.lista_de_casilla[0].id << std::endl;
    std:: cout << el_inventario.total_de_casillas << "\n" << x << "\n";


    //ESO SIRVE PARA IMPRIMIR UN OBJETO GUARDADO PARA VER COMO FUE EL FUNCIONAMIENTO DE CONEXION ENTRE OBJETO-CASILLA-INVENTARIO
    std:: cout << x << "OBJETO (Imprime el objeto dentro del id) \n";
    Casilla_del_objeto vacio;
    vacio.id = 0;
    vacio.cantidad = 0;
   // imprimir_objeto(vacio);


    //PROTOTIPO POCHO DE BUSCAR UN OBJETO DENTRO DEL ARREGLO... resultado: no optimo
    int opcion = 0;
    do {
        std:: cout << x << "BUSCAR UN OBJETO (Imprime el objeto dentro del id) \n" <<
            "Ingrese el nuevo objeto del inventario: \n" <<
            "1. Monedas\n"
            "2. Carne de Dragon Ahumado\n\n";

        std ::cin >> opcion;
        switch (opcion) {
            case 1:
            Casilla_del_objeto moneda;
            el_inventario.lista_de_casilla[1].id = 1;
            imprimir_objeto(moneda, el_inventario);
                break;
        }
    }while (opcion != 0);



    delete [] el_inventario.lista_de_casilla;

    return 0;
}

void imprimir_objeto(const Casilla_del_objeto& casilla, const Inventario& el_inventario)
{
    int id_objeto = casilla.id;

    for (int i = 0; i < el_inventario.total_de_casillas; i++)
    {
        if (id_objeto == el_inventario.lista_de_casilla[i].id) {
            std::cout << id_objeto << std::endl;
            std::cout << "Objeto seleccionado: " << universo_de_objetos[id_objeto].nombre << "\n";
            std::cout << "Categoria: " << universo_de_objetos[id_objeto].categoria << "\n";
            std::cout << "Cantidad: " << casilla.cantidad << "\n\n";
            break;
        }
    }


}

