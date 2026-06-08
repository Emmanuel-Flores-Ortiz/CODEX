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


void agregarObjeto(Inventario& el_inventario, int &id_objeto, int &cantidad, int &opcion, std::string &x);
void buscarObjeto(Inventario& el_inventario, int &id_objeto, int &opcion, std::string &x);
void listadoObjetos(Inventario& el_inventario, int &opcion);
void imprimirObjeto(Inventario& el_inventario, int &opcion);
void menuObjetos(std::string &x, int &opcion);


int main()
{
    //VARIABLES DECORATIVAS
    std::string x = "===========================\n";

    //VARIABLES
    int opcion = 0, opcion_menu = 0, id_objeto = 0, cantidad = 0;


    //CREACION DEL INVENTARIO
    Inventario el_inventario;
    el_inventario.total_de_casillas = 3; //Oye memoria, ten tu valor para el tipo de dato que guardaras.
    el_inventario.lista_de_casilla = new Casilla_del_objeto[el_inventario.total_de_casillas]; //Oye memeoria, guardame una pedacito de memoria de este tipo de dato

    do
    {
        std::cout << x << "       INVENTARIO\n" << x <<
            "1. Agregar Objeto\n" <<
            "2. Buscar Objeto\n" <<
            "3. Listar Objeto\n" <<
            "4. salir\n";
        std::cin >> opcion_menu;

        switch (opcion_menu)
        {
            case 1:
                agregarObjeto(el_inventario, id_objeto, cantidad, opcion, x);
                break;
            case 2:
                buscarObjeto(el_inventario, id_objeto, opcion, x);
                break;
            case 3:
                listadoObjetos( el_inventario, opcion);
                break;
            case 4:
                delete [] el_inventario.lista_de_casilla;
                std::cout << "FINALIZANDO LA TRANSMISION...\n";
                exit(0);
            default:
                std::cout << "ERROR. Opcion Invalida";
                break;
        }
    } while (opcion != 4);

    return 0;
}


void agregarObjeto(Inventario& el_inventario, int &id_objeto, int &cantidad, int &opcion, std::string &x)
    {
        menuObjetos(x, opcion);
        int max_objetos = 64;
        id_objeto = opcion;
        std::cout << "INGRESE LA CANTIDAD A REGISTRAR: \n";
        std::cin >> cantidad;


        //RECORRE TODA LA LISTA DE CASILLAS BUSCANDO UN ID SIMILAR AAL ID DEL OBJETO QUE EL USUARIO QUIERE AGREGAR
        for (int i = 0; i < el_inventario.total_de_casillas; i++)
        {
            if (el_inventario.lista_de_casilla[i].id == id_objeto)
            {
                if (el_inventario.lista_de_casilla[i].cantidad + cantidad > max_objetos)
                {
                    std::cout << "Limite de objeto alcanzado\n";
                    el_inventario.lista_de_casilla[i].cantidad == max_objetos;
                    return;
                }
                else
                {
                    el_inventario.lista_de_casilla[i].cantidad += cantidad;
                    std::cout << "Se acumularon " << cantidad << " unidades en la casilla " << i << "\n";
                    return;
                }
            }
        }
        std::cout << "El objeto con ID " << id_objeto << " no esta en el inventario.\n" <<
            "Agregando al inventario...\n\n";

        //SI EN EL PRIMER FOR NO SE ECONTRO UN SIMILITUD, TOCO GUARDAR ESE OBJETO AGREGADO EN UNA NUEVA CASILLA, SIENDO LA PRIMERA QUE ESTA VACIA (ID DE 0)
        for (int i = 0; i < el_inventario.total_de_casillas; i++)
        {
            if (el_inventario.lista_de_casilla[i].id == 0)
            {
                el_inventario.lista_de_casilla[i].id = id_objeto;
                el_inventario.lista_de_casilla[i].cantidad = cantidad;
                std::cout << "El objeto fue agregado con exito al inventario.";
                return;
            }
        }
    }


void buscarObjeto(Inventario& el_inventario, int &id_objeto, int &opcion, std::string &x)
{
    menuObjetos(x, opcion);
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

void menuObjetos(std::string &x, int &opcion)
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
    } while (opcion > 6);
}