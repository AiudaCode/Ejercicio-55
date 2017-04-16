#include "Estatuas.h"

Estatuas::Estatuas()
{
    // le asignamos valores por defecto a los atributos de la clase en el constructor
    tamano = 0;
    vector = NULL;
    vector_ordenado = NULL;
}

Estatuas::~Estatuas()
{
    //dtor
}

// métodos Setters y Getters
void Estatuas::setTamanoVector(int val)
{
    tamano = val;
}

int Estatuas::getTamanoVector()
{
    return tamano;
}

void Estatuas::setVector(int pos, int val)
{
    vector[pos] = val;
}

int Estatuas::getVector(int pos)
{
    return vector[pos];
}
void Estatuas::setVectorOrdenado(int pos, int val)
{
    vector_ordenado[pos] = val;
}

int Estatuas::getVectorOrdenado(int pos)
{
    return vector_ordenado[pos];
}

// método para crear el vector
void Estatuas::crearVector()
{
    // le asignamos al vector de tipo entero un tamaño del valor de la variable tamano
    vector = new int[tamano];
}

// método para crear el vector donde estaran todas estatuas que se requieren ordenadas de 1 en 1
void Estatuas::crearVectorOrdenado()
{
    // inicializamos una variable de tipo entero llamada tam en el valor de la variable tam mas
    // el valor del método estatuasRequeridas
    int tam = tamano+estatuasRequeridas();
    vector_ordenado = new int[tam];
}

// método para calcular el mayor tamaño entre todas las estatuas
int Estatuas::mayorTamano()
{
    // inicializamos una variable de tipo entero llamada may en 0
    int may = 0;
    // declaramos una variable de tipo entero llamada temp
    int temp;
    // recorremos el vector con el ciclo for
    for (int i = 0; i < getTamanoVector(); i++)
    {
        // le asignamos a la variable temp el valor de la posicion i del vector
        temp = getVector(i);
        // si el valor de temp es mayor al valor de la variable may
        if (temp > may)
        {
            // le asignamos a la variable may el valor de temp
            may = temp;
        }
    }
    // retornamos el valor de may
    return may;
}

// método para calcular el menor tamaño entre todas las estatuas
int Estatuas::menorTamano()
{
    // inicializamos una variable de tipo entero llamada men en el valor que retorne el metodo mayorTamano
    int men = mayorTamano();
    // declaramos una variable de tipo entero llamada temp
    int temp;
    // recorremos el vector con el ciclo for
    for (int i = 0; i < getTamanoVector(); i++)
    {
        // le asignamos a la variable temp el valor de la posicion i del vector
        temp = getVector(i);
        // si el valor de temp es menor al valor de la variable men
        if (temp < men)
        {
            // le asignamos a la variable men el valor de temp
            men = temp;
        }
    }
    // retornamos el valor de men
    return men;
}

// método para cambiar dos posiciones del vector
void Estatuas::cambiar(int p1, int p2)
{
    // inicializamos una variable de tipo entero llamada temp en el valor que hay en posicion p1 del vector
    int temp = getVector(p1);
    // en la posicion p1 del vector le asignamos el valor de la posicion p2 del vector
    setVector(p1, getVector(p2));
    // en la posicion p2 del vector le asignamos el valor de la variable temp
    setVector(p2, temp);
}

// método para ordenar los tamaños de las estatuas
void Estatuas::ordenar()
{
    // recorremos con el ciclo for el vector
    for (int i = 0; i < getTamanoVector(); i++)
    {
        // con este otro ciclo recorremos la siguiente posicion del vector
        for (int j = i+1; j < getTamanoVector(); j++)
        {
            // si la posicion i es mayor a la posicion j del vector
            if (getVector(i) > getVector(j))
            {
                // entonces cambiamos esas dos posiciones
                cambiar(i, j);
            }
        }
    }
}

// método para calcular las estatuas requeridas
int Estatuas::estatuasRequeridas()
{
    // retornamos el valo
    return (mayorTamano() - menorTamano() + 1) - getTamanoVector();
}

// método para llenar las estatuas faltantes al nuevo vector ordenado
void Estatuas::llenarEstatuasFaltantes()
{
    // inicializamos una variable de tipo entero llamada tam en el tamaño del vector mas las estatuas requeridas
    int tam = getTamanoVector()+estatuasRequeridas();
    // inicializamos una variable de tipo entero llamada temp en el valor de la posicion  0 del vector
    int temp = getVector(0);
    // recorremos el nuevo vector con el ciclo for
    for (int i = 0; i < tam; i++)
    {
        // si estamos en la primera posicion del vector
        if (i == 0)
        {
            // le asignamos en la posicion i el valor de temp
            setVectorOrdenado(i, temp);
        }
        else
        {
            // sino incrementamos el valor de la variable temp
            temp++;
            // le asignamos en la posicion i el valor de temp
            setVectorOrdenado(i, temp);
        }
    }
}
