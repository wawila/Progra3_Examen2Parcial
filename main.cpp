// queue::push/pop

#include <iostream>
#include <list>
#include <fstream>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include "Planeta.h"
#include "Evaluador.h"
#include "NodoBinario.h"

using namespace std;

//Escribe los datos del objeto mascota dado en un archivo binario con el nombre dado en la posicion dada
//Nota: Se deben poder agregar varias mascotas en un solo archivo
void escribir(string nombre_archivo, Planeta*planeta, int posicion)
{
    nombre_archivo+=".txt";
    ios::in;
    ofstream out(nombre_archivo.c_str(), ios::in);

    out.seekp(posicion*25);

    out.write(&planeta->categoria, 1);

    out.write(planeta->nombre.c_str(), 10);

    out.write((char*)&planeta->habitantes, 4);

    out.write((char*)&planeta->diametro, 8);

    out.close();
}

//Devuelve una mascota previamente escrita (con la funcion escribir()) en un archivo binario con nombre dado en la posicion dada
//Nota: Se deben poder leer varias mascotas de un solo archivo
Planeta* leer(string nombre_archivo, int posicion)
{
    Planeta *p = new Planeta("", -1, -1.0, ' ');

    ifstream in(nombre_archivo.c_str());
    in.seekg(posicion * 25);

    char n[10];
    in.read(n, 10);
     int h;
    in.read((char*)&h, 4);
    double d;
    in.read((char*)&d, 8);
     char c;
    in.read(&c, 1);

    p->nombre = n;
    p->habitantes = h;
    p->diametro = d;
    p->categoria = c;

    return p;
}

//Devuelve el primer valor fue ingresado en mi_pila (dada)
//Nota: devuelve el valor mas viejo
string getFondo(stack<string> mi_pila)
{
    string resultado;
    for(int i = 0; i < mi_pila.size(); mi_pila.pop())
    {
        resultado = mi_pila.top();
    }
    return resultado;
}

//Devuelve el ultimo valor que fue ingresado en mi_cola (dada)
//Nota: devuelve el valor mas nuevo
char getUltimo(queue<char> mi_cola)
{
    char resultado;
    for(int i = 0; i < mi_cola.size(); mi_cola.pop())
    {
        resultado = mi_cola.front();
    }
    return resultado;
}

//Dado una lista, devuelve un vector que contenga los datos de la lista en el mismo orden
vector<int> convertirAVector(list<int> mi_lista)
{
    vector<int> mi_vector;
    list<int>::iterator lst = mi_lista.begin();
    for(lst; lst != mi_lista.end(); lst++)
    {
        mi_vector.push_back((*lst));
    }

    return mi_vector;
}

//Dado un numero, devuelve un mapa que contenga su tabla de multiplicacion
//Ejemplo:
//Dado num = 5
//Devuelve el siguiente mapa
//{1=>5,2=>10,3=>15,4=>20,5=>25,6=>30,7=>35,8=>40,9=>45,10=>50}
map<int,int> getTabla(int num)
{
    map<int,int> mi_mapa;
    for(int i = 1; i <= 10; i++)
    {
        mi_mapa[i]=i*num;
    }
    return mi_mapa;
}

//Dado un arbol con raiz dada, devuelve un set que contenga todos los valores almacenados en el arbol
//Nota los valores estan almacendados en el atributo valor en la clase NodoBinario
set<string> getValores(NodoBinario* raiz)
{

    set<string> mi_set;

    if(raiz != NULL)
    {
        mi_set.insert(raiz->valor);

        if(raiz->hijo_der != NULL)
        {
            set<string> temp = getValores(raiz->hijo_izq);
            mi_set.insert(temp.begin(),temp.end());
        }

        if(raiz->hijo_izq != NULL)
        {
            set<string> temp = getValores(raiz->hijo_der);
            mi_set.insert(temp.begin(),temp.end());
        }

        return mi_set;

    }
}

//Dado un arbol con raiz dada, busca el nodo que contenga el valor buscado (dado) y lo reemplaza con la variable reemplazo (dada)
//Nota los valores estan almacendados en el atributo valor en la clase NodoBinario
void buscarYReemplazar(NodoBinario* raiz, string buscado, string reemplazo)
{

    if(raiz!=NULL)
    {
        if (raiz->valor==buscado)
        {
            raiz->valor=reemplazo;
        }

        if(raiz->hijo_izq != NULL)
            buscarYReemplazar(raiz->hijo_izq, buscado, reemplazo);

        if(raiz->hijo_der != NULL)
            buscarYReemplazar(raiz->hijo_der, buscado, reemplazo);
    }

}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}

