#include <iostream>
#include <string>

struct Objeto {
    int id;
    std::string nombre;
    std::string categoria;
    int cantidad;
};

struct InventorySlot {
    int id_Objeto;
    int cantidad_Objeto = 64;
};

int cantidad_elementos = 0;

struct Inventario {
    InventorySlot Inventory[cantidad_elementos]; //Arreglar--> Sigue invetsigando como juntaar minecraft y pokemon
    int sumador_elementos = 0;
};


void imprimirObjeto(Objeto &objeto);

int main()
{
    //CREACION DEL INVENTARIO
    Inventario inventario;

    //CREACION DE 3 OBJETOS
    Objeto comida;
    comida.id = 0;
    comida.nombre = "Carne de Dragron Ahumado";
    comida.categoria = "Consumible";
    comida.cantidad = 15;

    Objeto monedas;
    monedas.id = 1;
    monedas.nombre = "Moneda de Oro Antiguo";
    monedas.categoria = "Intercambiable";
    monedas.cantidad = 30;

    Objeto curacion;
    curacion.id = 2;
    curacion.nombre = "Orbe de Almas";
    curacion.categoria = "Consumible";
    curacion.cantidad = 5;

    imprimirObjeto(comida);

    return 0;
}

void imprimirObjeto(Objeto &objeto)
{
    std::cout << objeto.id << "\n";
    std::cout << objeto.nombre << "\n";
    std::cout << objeto.categoria << "\n";
    std::cout << objeto.cantidad << "\n";
}