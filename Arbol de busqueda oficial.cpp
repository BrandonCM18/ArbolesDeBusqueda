#include <iostream>
using namespace std;
template<class T>
class arbol;

template<class T>
class nodo{
private:
    T data;
    nodo<T>* izq;
    nodo<T>* der;
public:
    nodo():izq(nullptr),der(nullptr){};
    friend class arbol<T>;
};

template<class T>
class arbol{
private:
    nodo<T>* raiz;
    void insertar(T, nodo<T>*&);
    nodo<T>* menor(nodo<T>*);
    nodo<T>* mayor(nodo<T>*);
    void  preorder(nodo<T>*);
    void  inorder(nodo<T>*);
    void  postorder(nodo<T>*);
    void  recorrido_hoja(nodo<T>*);
    void  elimina(nodo<T>*,nodo<T>*&);
public:
    arbol():raiz(nullptr){};
    void  inicializa(nodo<T>*);
    bool  vacio()const;
    T recupera(nodo<T>*)const;
    void  insertar(T);
    nodo<T>* localiza(T,nodo<T>*);
    void  menor();
    void  mayor();
    void  root();
    bool  es_hoja(nodo<T>*)const;
    void  preorder();
    void  inorder();
    void  postorder();
    void  recorrido_hoja();
    void  elimina(T);
    void  localiza(T);
};

template<class T>
void arbol<T>::inicializa(nodo<T>* arbol)
{
    arbol=nullptr;
}

template<class T>
bool arbol<T>::vacio()const{
    if(raiz==nullptr)
        return true;
    else
        return false;
}

template<class T>
T arbol<T>::recupera(nodo<T>* pos)const{
    if(vacio()|| pos==nullptr){
        return NULL;
    }
    else
        return pos->data;
}

template<class T>
void arbol<T>::insertar(T elem, nodo<T>*& nuevo){
    if(nuevo==nullptr){
        nodo<T>* aux = new nodo<T>();
        aux->data = elem;
        nuevo = aux;
    }
    else if(elem < nuevo->data)
            insertar(elem, nuevo->izq);
    else if(elem > nuevo->data)
            insertar(elem, nuevo->der);
}

template<class T>
void arbol<T>::insertar(T elem){
    if(vacio())
        inicializa(raiz);
    insertar(elem, raiz);
}

template<class T>
nodo<T>* arbol<T>::localiza(T elem, nodo<T>* arbol){
    if(arbol==nullptr)
    {
        return nullptr;
    }
    else
    {
        if(elem < arbol->data){
            return localiza(elem, arbol->izq);
        }
        else if (elem > arbol->data) {
            return localiza(elem, arbol->der);
        }
        else {
            return arbol;
        }
    }
}

template<class T>
void arbol<T>::localiza(T elem){
    nodo<T>* pos = new nodo<T>;
    pos = localiza(elem, raiz);
    if(pos==nullptr)
    {
        std::cout<<"\nNo se encontro el dato"<<std::endl;
    }
    else{
        std::cout<<"\nSe encontro el dato"<<std::endl;
    }
}


template<class T>
nodo<T>* arbol<T>::menor(nodo<T>* arbol){
    if(arbol==nullptr)
    {
        return nullptr;
    }
    else
    {
        if(arbol->izq == nullptr){
            return arbol;
        }
        else{
            return menor(arbol->izq);
        }
    }
}

template<class T>
void arbol<T>::menor(){
    nodo<T>* resp = new nodo<T>();
    resp = menor(raiz);
    if(resp == nullptr){
        std::cout<<"\n\t No se encontro"<<std::endl;
    }
    else{
        std::cout<<"\n\t El dato menor es "<<resp->data<<std::endl;
    }
    std::cout<<"\n\t ";
    system("pause");
}

template<class T>
nodo<T>* arbol<T>::mayor(nodo<T>* arbol){
    if(arbol==nullptr)
    {
        return nullptr;
    }
    else
    {
        if(arbol->der == nullptr){
            return arbol;
        }
        else{
            return mayor(arbol->der);
        }
    }
}

template<class T>
void arbol<T>::mayor(){
    nodo<T>* resp = new nodo<T>();
    resp = mayor(raiz);
    if(resp == nullptr){
        std::cout<<"\nNo se encontro"<<std::endl;
    }
    else{
        std::cout<<"\nEl dato mayor es "<<resp->data<<std::endl;
    }
    std::cout<<"\n\t ";
    system("pause");
}

template<class T>
void arbol<T>::root(){
    if(raiz == nullptr){
        std::cout<<"\n\t No se agregan datos al arbol"<<std::endl;
    }
    else{
        std::cout<<"\n\t El dato raiz es "<<raiz->data<<std::endl;
    }
    std::cout<<"\n\t ";
    system("pause");
}

template<class T>
bool arbol<T>::es_hoja(nodo<T>* arbol)const{
    if(arbol==nullptr)
        return false;
    else{
        if(arbol->izq==nullptr && arbol->der==nullptr)
            return true;
        else
            return false;
    }
}

template<class T>
void arbol<T>::preorder(nodo<T>* arbol){
    if(arbol==nullptr){
        return;
    }
        std::cout<<"\n\t ->"<<arbol->data<<std::endl;
        preorder(arbol->izq);
        preorder(arbol->der);
    }

template<class T>
void arbol<T>::preorder(){
    std::cout<<"\n\t Recorrido por preorden: \n\t "<<std::endl;
    preorder(raiz);
    std::cout<<"\n\t ";
    system("pause");
}

template<class T>
void arbol<T>::inorder(nodo<T>* arbol){
    if(arbol==nullptr){
        return;
    }
        inorder(arbol->izq);
        std::cout<<"\n\t ->"<<arbol->data<<std::endl;
        inorder(arbol->der);
    }

template<class T>
void arbol<T>::inorder(){
    std::cout<<"\n\t Recorrido por inorden: \n\t "<<std::endl;
    inorder(raiz);
    std::cout<<"\n\t ";
    system("pause");
}

template<class T>
void arbol<T>::postorder(nodo<T>* arbol){
    if(arbol==nullptr){
        return;
    }
        postorder(arbol->izq);
        postorder(arbol->der);
        std::cout<<"\n\t ->"<<arbol->data<<std::endl;
    }

template<class T>
void arbol<T>::postorder(){
    std::cout<<"\n\t Recorrido por postorden: \n\t "<<std::endl;
    postorder(raiz);
    std::cout<<"\n\t ";
    system("pause");
}

template<class T>
void arbol<T>::recorrido_hoja(nodo<T>* arbol){
    if(arbol==nullptr){
        return;
    }
        recorrido_hoja(arbol->izq);
        if(es_hoja(arbol)){
            std::cout<<"\n\t ES HOJA:"<<std::endl;
            std::cout<<"\n\t ->"<<arbol->data<<std::endl;
        }
        recorrido_hoja(arbol->der);
    }

template<class T>
void arbol<T>::recorrido_hoja(){
    std::cout<<"\n\t Recorrido por inorden: \n\t "<<std::endl;
    recorrido_hoja(raiz);
    std::cout<<"\n\t ";
    system("pause");
}

template<class T>
void arbol<T>::elimina(nodo<T>* pos, nodo<T>*& arbol) {
    if (arbol == nullptr || pos == nullptr){
        std::cout << "Error: árbol o posición nulos" << std::endl;
        return;
    }
    if(es_hoja(arbol))
    {
        delete arbol;
        arbol = nullptr;
        return;
    }
    else if(pos->data<arbol->data)
        elimina(pos,arbol->izq);
    else if(pos->data>arbol->data)
        elimina(pos,arbol->der);
    else if(arbol->izq && arbol->der){
        nodo<T>* high = mayor(arbol->izq);
        arbol->data = high->data;
        elimina(high,arbol->izq);
    }
    else{
        nodo<T>* temp = arbol;
        if(arbol->izq == nullptr)
            arbol = arbol->der;
        else if(arbol->der == nullptr)
            arbol = arbol->izq;
        delete temp;
    }
}

template<class T>
void arbol<T>::elimina(T elem){
    nodo<T>* pos = new nodo<T>;
    pos = localiza(elem, raiz);
    if(pos==nullptr)
    {
        std::cout<<"\nNo se encontro el dato"<<std::endl;
    }
    else{
        std::cout<<"\nSe encontro el dato"<<std::endl;
        elimina(pos, raiz);
        std::cout<<"\n     Se borro el dato"<<std::endl;
    }
}


void menu(){
    cout<<"\nMENU\n\n";
    cout<<"\n1. Insertar. ";
    cout<<"\n2. Eliminar. ";
    cout<<"\n3. Imprimir. ";
    cout<<"\n4. Buscar. ";
    cout<<"\n5. Salir.   ";
    cout<<"\nElige una opcion:\t";
}

void recorrido(){
    cout<<"MENU\n\n";
    cout<<"1.Preorden.\n";
    cout<<"2.Inorden.\n";
    cout<<"3.Postorden.\n";
    cout<<"4.Menor.\n";
    cout<<"5.Raiz.\n";
    cout<<"6.Mayor.\n";
    cout<<"7.Hojas.\n";
    cout<<"8.Salir.\n";
    cout<<"Opcion:\t";
}

int main()
{
    arbol<int> arbolito;
    int z, opc;
    int elem;
    do{
        menu();
        cin>>z;
        switch(z){
        case 1:
            std::cout<<"\nIngrese el dato:\n";
            std::cin >>elem;
            arbolito.insertar(elem);
            break;
        case 2:
            if(!arbolito.vacio()){
                std::cout<<"\nIngrese el elemento que desea eliminar:\n";
                std::cin >>elem;
                arbolito.elimina(elem);
            }
            else
            break;
        case 3:
            if(!arbolito.vacio()){
            do{
                recorrido();
                cin>>opc;
                switch(opc){
                    case 1:
                        arbolito.preorder();
                        break;
                    case 2:
                        arbolito.inorder();
                        break;
                    case 3:
                        arbolito.postorder();
                        break;
                    case 4:
                        arbolito.menor();
                        break;
                    case 5:
                        arbolito.root();
                        break;
                    case 6:
                        arbolito.mayor();
                        break;
                    case 7:
                        arbolito.recorrido_hoja();
                        break;
                    case 8:
                        break;
                }
            }while(opc!=8);
            }
        case 4:
            if(!arbolito.vacio()){
                cout<<"\nIngrese el elemento que deseas buscar:\n";
                cin >>elem;
                arbolito.localiza(elem);
            }
            break;
        case 5:
            break;
        }
    }while(z!=5);
return 0;
}
