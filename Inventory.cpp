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


void agregarObjeto(Inventario& el_inventario, int &id_objeto, int &cantidad, int &opcion, std::string &x, std::string &y);
void buscarObjeto(Inventario& el_inventario, int &id_objeto, int &opcion, std::string &x, std::string &y);
void listadoObjetos(Inventario& el_inventario, int &opcion,  std::string &y);
void imprimirObjeto(Inventario& el_inventario, int &opcion,  std::string &y);
void menuObjetos(std::string &x, std::string &y, int &opcion);


int main()
{
    //VARIABLES DECORATIVAS
    std::string x = "====================================================\n", y = "----------------------------------------------------\n";

    //VARIABLES
    int opcion = 0, opcion_menu = 0, id_objeto = 0, cantidad = 0;


    //CREACION DEL INVENTARIO
    Inventario el_inventario;
    el_inventario.total_de_casillas = 3; //Oye memoria, ten tu valor para el tipo de dato que guardaras.
    el_inventario.lista_de_casilla = new Casilla_del_objeto[el_inventario.total_de_casillas]; //Oye memeoria, guardame una pedacito de memoria de este tipo de dato

    do
    {
        std::cout << x << "        INVENTARIO\n" << x <<
            "1. Agregar Objeto\n" <<
            "2. Buscar Objeto\n" <<
            "3. Listar Objeto\n" <<
            "4. salir\n" << y <<
            "Selecciona una opcion: ";
        std::cin >> opcion_menu;
        std::cout << y;

        switch (opcion_menu)
        {
            case 1:
                menuObjetos(x, y, opcion);
                if (opcion == 6)
                {
                    break;
                }
                agregarObjeto(el_inventario, id_objeto, cantidad, opcion, x, y);
                break;
            case 2:
                menuObjetos(x, y, opcion);
                if (opcion == 6)
                {
                    break;
                }
                buscarObjeto(el_inventario, id_objeto, opcion, x, y);
                break;
            case 3:
                listadoObjetos(el_inventario, opcion, y);
                break;
            case 4:
                delete [] el_inventario.lista_de_casilla;
                std::cout << "FINALIZANDO LA TRANSMISION...\n";
                exit(0);
            default:
                std::cout << "ERROR. Opcion Invalida\n";
                break;
        }
    } while (opcion != 4);

    return 0;
}


void agregarObjeto(Inventario& el_inventario, int &id_objeto, int &cantidad, int &opcion, std::string &x, std::string &y)
{
    int max_objetos = 64;
    id_objeto = opcion;
    std::cout << x << "INGRESE LA CANTIDAD A REGISTRAR: ";
    std::cin >> cantidad;
    std::cout << y;


    //RECORRE TODA LA LISTA DE CASILLAS BUSCANDO UN ID SIMILAR AAL ID DEL OBJETO QUE EL USUARIO QUIERE AGREGAR
    for (int i = 0; i < el_inventario.total_de_casillas; i++)
    {
        if (el_inventario.lista_de_casilla[i].id == id_objeto)
        {
            if (el_inventario.lista_de_casilla[i].cantidad + cantidad > max_objetos)
            {
                std::cout << "ERROR. Limite de objetos alcanzado\n";
                el_inventario.lista_de_casilla[i].cantidad = max_objetos;
                std::cout << "Total : " << el_inventario.lista_de_casilla[i].cantidad << "\n\n";
                std::cout << el_inventario.lista_de_casilla[i].id;


                //DIGAMOS QUE EL JUGADOR FARMEO ACA BIEN INSANO Y CONSIGUIO 64 UNIDADES DEL MISMO OBJETO... QUE PROSIGUE? BUENO:
                if (el_inventario.lista_de_casilla[i].cantidad == max_objetos)         //ESTE IF VERIFICA QUE LA CASILLA ACTUAL ESTA LLENA.
                {
                    std::cout << "Asignando nueva casilla al objeto '" << universo_de_objetos[id_objeto].nombre << "' \n";

                    for (int j = 0; j < el_inventario.total_de_casillas; j++)          //ESTE FOR BUSCA UNA CASILLA VACIA Y ASI ASIGNARLE EL NUEVO OBJETO (ID), ESTO SE REPITE ABAJO SI ES LA PRIMERA VEZ QUE SE AGREGA UN OBJETO NUEVO.
                    {
                        if (el_inventario.lista_de_casilla[j].id == 0)
                        {
                            el_inventario.lista_de_casilla[j].id = id_objeto;
                            el_inventario.lista_de_casilla[j].cantidad = cantidad;
                            std::cout << "El objeto fue agregado con exito al inventario.\n";
                            return;
                        }
                    }
                    return;
                }
                el_inventario.lista_de_casilla[i].cantidad += cantidad;
                std::cout << "Se acumularon " << cantidad << " unidades al objeto '" << universo_de_objetos[id_objeto].nombre << "' \n";
                return;

            }
        }


        std::cout << "El objeto: '" << universo_de_objetos[id_objeto].nombre << "' no esta en el inventario.\n" <<
            "Agregando al inventario...\n\n";


        //SI EN EL PRIMER FOR NO SE ECONTRO UN SIMILITUD, TOCO GUARDAR ESE OBJETO AGREGADO EN UNA NUEVA CASILLA, SIENDO LA PRIMERA QUE ESTA VACIA (ID DE 0)
        for (int i = 0; i < el_inventario.total_de_casillas; i++)
        {
            if (el_inventario.lista_de_casilla[i].id == 0)
            {
                el_inventario.lista_de_casilla[i].id = id_objeto;
                el_inventario.lista_de_casilla[i].cantidad = cantidad;
                if (el_inventario.lista_de_casilla[i].cantidad  > max_objetos)
                {
                    std::cout << "ERROR. Limite de objetos alcanzado\n";
                    el_inventario.lista_de_casilla[i].cantidad = max_objetos;

                    std::cout << "Total : " << el_inventario.lista_de_casilla[i].cantidad << "\n\n";
                    std::cout << "El objeto fue agregado con exito al inventario.\n";
                    return;
                }

                std::cout << "El objeto fue agregado con exito al inventario.\n";
                return;
            }
        }
    }
}


void buscarObjeto(Inventario& el_inventario, int &id_objeto, int &opcion, std::string &x, std::string &y)
{
    id_objeto = opcion;

    for (int i = 0; i < el_inventario.total_de_casillas; i++)
    {
        if (el_inventario.lista_de_casilla[i].id == id_objeto)
        {
            opcion = i;
            imprimirObjeto(el_inventario, opcion, y);
            return;
        }
    }

    std::cout << "El objeto con ID " << id_objeto << " no esta en el inventario.\n";
}


void listadoObjetos(Inventario& el_inventario, int &opcion, std::string &y)
{
    for (int i = 0; i < el_inventario.total_de_casillas; i++)
    {
        opcion = i;
        imprimirObjeto(el_inventario, opcion, y);
    }
}


void imprimirObjeto(Inventario& el_inventario, int &opcion, std::string &y)
{
    int id_objeto = el_inventario.lista_de_casilla[opcion].id;

    std::cout << "id Objeto: " << id_objeto << "\n";
    std::cout << "Objeto seleccionado: " << universo_de_objetos[id_objeto].nombre << "\n";
    std::cout << "Categoria del objeto: " << universo_de_objetos[id_objeto].categoria << "\n";
    std::cout << "Cantidad del objeto: " << el_inventario.lista_de_casilla[opcion].cantidad << "\n" << y;
}

void menuObjetos(std::string &x, std::string &y, int &opcion)
{
    do
    {
        std::cout << x << "    OBJETOS DEL MUNDO\n" << x <<
        "1. Monedas\n" <<
        "2. Carne de Dragon Ahumado\n" <<
        "3. Pocion de Almas\n" <<
        "4. Espada de Sangre\n" <<
        "5. Llaves de Mazmorra\n" <<
        "6. salir\n" << y <<
        "Selecciona una opcion: ";
        std::cin >> opcion;
        std::cout << y;

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
                continue;
            default:
                std::cout << "ERROR. Opcion Invalida\n";
                break;
        }
    } while (opcion > 6);
}