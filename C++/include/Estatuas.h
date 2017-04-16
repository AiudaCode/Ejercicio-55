#ifndef ESTATUAS_H
#define ESTATUAS_H
#include <iostream>

using namespace std;

class Estatuas
{
    public:
        Estatuas();
        virtual ~Estatuas();
        void setTamanoVector(int val);
        int getTamanoVector();
        void setVector(int pos, int val);
        int getVector(int pos);
        void setVectorOrdenado(int pos, int val);
        int getVectorOrdenado(int pos);
        void crearVector();
        void crearVectorOrdenado();
        int mayorTamano();
        int menorTamano();
        void cambiar(int p1, int p2);
        void ordenar();
        int estatuasRequeridas();
        void llenarEstatuasFaltantes();
    protected:

    private:
        int tamano;
        int *vector;
        int *vector_ordenado;
};

#endif // ESTATUAS_H
