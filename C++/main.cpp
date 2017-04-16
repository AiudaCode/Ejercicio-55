#include <iostream>
#include "Estatuas.h"

using namespace std;

// método para mostrar el vector
void mostrar(Estatuas *obj)
{
    // recorremos el vector con el ciclo for
    for (int i = 0; i < obj->getTamanoVector(); i++)
    {
        // si el llegamos a la ultima posicion del vector cerramos con un corchete
        if (i == obj->getTamanoVector()-1)
        {
            cout << obj->getVector(i) << "]" << endl;
        }
        else
        {
            // sino separamos cada valor del vector con una ,
            cout << obj->getVector(i) << ", ";
        }
    }
}

// método para mostrar todas estatuas ordenadas de 1 en 1
void mostrarTodo(Estatuas *obj)
{
    // inicializamos una variable de tipo entera llamada tam en la suma del tamaño del vector mas las estatuas requeridas
    int tam = obj->getTamanoVector()+obj->estatuasRequeridas();
    // recorremos el vector ordenado con el ciclo for
    for (int i = 0; i < tam; i++)
    {
        // si llegamos a la ultima posicion
        if (i == tam-1)
        {
            // si el llegamos a la ultima posicion del vector cerramos con un corchete
            cout << obj->getVectorOrdenado(i) << "]" << endl;
        }
        else
        {
            // sino separamos cada valor del vector con una ,
            cout << obj->getVectorOrdenado(i) << ", ";
        }
    }
}

int main(void)
{
    // creamos un objeto de la clase Estatuas (Instanciación)
    Estatuas *obj = new Estatuas();
    // declaramos dos variables de tipo entero
    int tam, dato;
    // pedimos el tamaño del vector
    cout << "Digite tama" << (char) 164 << "o del vector" << endl;
    cout << ">> ";
    cin >> tam;
    // encapsulamos la variable tam
    obj->setTamanoVector(tam);
    // creamos el vector
    obj->crearVector();
    // recorremos el vector con el ciclo for
    for (int i = 0; i < obj->getTamanoVector(); i++)
    {
        do
        {
            // pedimos el tamaño de la estatua en la posicion i
            cout << "Digite tama" << (char) 164 << "o de la estatua " << i << endl;
            cout << ">> ";
            cin >> dato;
            // encapsumalos en la posicion la variable dato
            obj->setVector(i, dato);
        }
        while (dato < 0); // repetiremos esto hasta si el dato es menor a 0
    }
    //mostramos en pantalla el vector
    cout << "Tama" << (char) 164 << "o de las estatuas de Timmy: [";
    mostrar(obj);
    // si el tamaño es mayor 1
    if (obj->getTamanoVector() > 1)
    {
        // mostramos las estatuas ordenas y todas las estatuas ordenadas de 1 en 1
        obj->ordenar();
        cout << "Estatuas ordenadas: [";
        mostrar(obj);
        obj->crearVectorOrdenado();
        obj->llenarEstatuasFaltantes();
        cout << "Todas las estatuas ordenadas de 1 en 1: [";
        mostrarTodo(obj);
    }
    // mostramos la cantidad de estatuas necesitadas
    cout << "Se necesitaron " << obj->estatuasRequeridas() << " estatuas para ordenarlas de 1 en 1." << endl;
}
