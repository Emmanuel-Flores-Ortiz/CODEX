#include <iostream>
#include <string>

struct Objeto //CADA OBJETO
{
    int id;
    std::string nombre;
    std::string categoria;
};

const int objetos = 6; // CANTIDAD DE OBJETOS EXISTENTES EN EL JUEGO
Objeto universo_de_objetos[objetos] =
{
    {0, "Objeto Nulo", "N/A"},
    {1, "Monedas", "Consumible"},
    {2, "Carnde de Dragon Ahumado", "Consumible"},
    {3, "Pocion de Almas", "Consumible"},
    {4, "Espada de Sangre", "Arma"},
    {5, "Llaves de Mazmorra", "Interactuable"}
};


struct Casilla_del_objeto //CADA CASILLA DEL INVENTARIO --> Es el tickect de busqueda
{
    int id = 0;
    int cantidad = 0;
};


struct Inventario //ES EL INVENTARIO COMPLETO
{
    Casilla_del_objeto* lista_de_casilla; //Aqui 'lista_de_casilla' tiene acceso por un * a 'Casilla_del objeto' y a su contenido
    int total_de_casillas;
};


void agregarObjeto(Inventario& el_inventario, int &id_objeto, int &cantidad, int &opcion);
void buscarObjeto(Inventario& el_inventario, int &id_objeto, int &opcion);
void listadoObjetos(Inventario& el_inventario, int &opcion);
void imprimirObjeto(Inventario& el_inventario, int &opcion);


int main()
{
    //VARIABLES DECORATIVAS
    std::string x = "===============================================\n";

    //VARIABLES
    int opcion = 0, opcion_menu = 0, id_objeto = 0, cantidad = 0;


    //CREACION DEL INVENTARIO
    Inventario el_inventario;
    el_inventario.total_de_casillas = 3; //Oye memoria, ten tu valor para el tipo de dato que guardaras.
    el_inventario.lista_de_casilla = new Casilla_del_objeto[el_inventario.total_de_casillas]; //Oye memeoria, guardame una pedacito de memoria de este tipo de dato

    el_inventario.lista_de_casilla[0].id = 1;
    el_inventario.lista_de_casilla[0].cantidad = 10;

    el_inventario.lista_de_casilla[1].id = 2;
    el_inventario.lista_de_casilla[1].cantidad = 5;
    listadoObjetos(el_inventario, opcion);

    do
    {
        std::cout << x << "       INVENTARIO\n" << x <<
            "1. Agregar Objeto\n" <<
            "2. Buscar Objeto\n" <<
            "3. Listar Objeto\n" <<
            "4. salir\n\n";
        std::cin >> opcion_menu;

        switch (opcion_menu)
        {
            case 1:
                agregarObjeto(el_inventario, id_objeto, cantidad, opcion);
                break;
            case 2:
                buscarObjeto(el_inventario, id_objeto, opcion);
                break;
            case 3:
                listadoObjetos( el_inventario, opcion);
                break;
            case 4:
                std::cout << "QUE TENGA UN EXCELENTE DIA...";
                break;
            default:
                std::cout << "ERROR. Opcion Invalida";
                break;
        }
    } while (opcion != 4);

    do
    {
        std::cout << x << "       Seleccione su operacion\n" << x <<
            "1. Monedas\n" <<
            "2. Carne de Dragon Ahumado\n";
        std::cin >> opcion;

        switch (opcion)
        {
            case 1:
                agregarObjeto(el_inventario, id_objeto, cantidad, opcion);
                break;
            case 2:
                buscarObjeto(el_inventario, id_objeto, opcion);
                break;
            default:
                std::cout << "ERROR. Opcion Invalida";
                break;
        }

    } while (opcion != 3);


    delete [] el_inventario.lista_de_casilla;
    return 0;
}


void agregarObjeto(Inventario& el_inventario, int &id_objeto, int &cantidad, int &opcion)
    {
    int max_objetos = 64;
    id_objeto = opcion;
    std::cout << "INGRESE LA CANTIDAD A REGISTRAR: \n";
    std::cin >> cantidad;

    if (cantidad > max_objetos)
    {
        std::cout << "Limite alcanzado\n";
        return;
    }

        for (int i = 0; i < el_inventario.total_de_casillas; i++)
        {
            if (el_inventario.lista_de_casilla[i].id == id_objeto)
            {
                std::cout << "Se acumularon " << cantidad << " unidades en la casilla " << i << "\n";
                return;
            }
        }

    std::cout << "El objeto con ID " << id_objeto << " no esta en el inventario.\n";
    }


void buscarObjeto(Inventario& el_inventario, int &id_objeto, int &opcion)
{
    id_objeto = opcion;

    for (int i = 0; i < el_inventario.total_de_casillas; i++)
    {
        if (el_inventario.lista_de_casilla[i].id == id_objeto)
        {
            opcion = i;
            imprimirObjeto(el_inventario, opcion);
            return;
        }
    }

    std::cout << "El objeto con ID " << id_objeto << " no esta en el inventario.\n";
}


void listadoObjetos(Inventario& el_inventario, int &opcion)
{
    for (int i = 0; i < el_inventario.total_de_casillas; i++)
    {
        opcion = i;
        imprimirObjeto(el_inventario, opcion);
    }
}


void imprimirObjeto(Inventario& el_inventario, int &opcion)
{
    int id_objeto = el_inventario.lista_de_casilla[opcion].id;

    std::cout << "Objeto seleccionado: " << universo_de_objetos[id_objeto].nombre << "\n";
    std::cout << "Categoria del objeto: " << universo_de_objetos[id_objeto].categoria << "\n";
    std::cout << "Cantidad del objeto: " << el_inventario.lista_de_casilla[opcion].cantidad << "\n";
}

void menuObjetos(std::string &x, int opcion)
{
    do
    {
        std::cout << x << "       OBJETOS DEL MUNDO\n" << x <<
            "1. Monedas\n" <<
            "2. Carne\n" <<
            "3. Pocion de Almas\n" <<
            "4. Espada de Sangre\n" <<
            "5. Llaves de Mazmorr\n" <<
            "6. Salir\n\n";
        std::cin >> opcion;

        switch (opcion)
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            default:
                std::cout << "ERROR. Opcion Invalida";
                break;
        }
    } while (opcion != 6);
} //Quitar esta funcion... me derroto el inventario