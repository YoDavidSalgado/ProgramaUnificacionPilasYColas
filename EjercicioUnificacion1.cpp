#include <iostream>
#include <conio.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <locale>

using namespace std;

struct nodo {
    int nro;
    struct nodo *sgte;
};

struct cola{
    nodo *delante;
    nodo *atras;
};

struct pilas{
    int d;
    pilas *a;
} *c = NULL, *e = NULL; 

struct cola q; 

void inicializarCola() {
    q.delante = NULL;
    q.atras = NULL;
}

void encolar(int valor) {
    struct nodo *aux = new(struct nodo);
    
    aux->nro = valor;
    aux->sgte = NULL;
    
    if (q.delante == NULL)
        q.delante = aux;  
    else
        (q.atras)->sgte = aux;
        
    q.atras = aux;  
}

int desencolar() {
    
    int num ;
    struct nodo *aux ;
    
    aux = q.delante; 
    num = aux->nro;
    q.delante = (q.delante)->sgte;
    delete(aux);  
    
    return num;
}

void muestraCola() {
    struct nodo *aux;
    
    aux = q.delante;
        
    while (aux != NULL) {
        cout << "   " << aux->nro ;
        aux = aux->sgte;
    }    
}

void vaciaCola() {
    struct nodo *aux;
    
    while (q.delante != NULL) {
        aux = q.delante;
        q.delante = aux->sgte;
        delete(aux);
    }
    q.delante = NULL;
    q.atras   = NULL;
}

void muestraPrimerDesencolar() {
    if (q.delante != NULL) {
       cout << "\n Primer elemento a desencolar: " << q.delante->nro << endl;
    } else {
       cout << "\n La cola está vacía." << endl;
    }
}

void muestraUltimoDesencolar() {
    if (q.atras != NULL) {
       cout << "\n Ultimo elemento a desencolar: " << q.atras->nro << endl;
    } else {
       cout << "\n La cola está vacía." << endl;
    }
}

int numElementosCola() {
    int contador = 0;
    struct nodo *aux = q.delante;
        
    while (aux != NULL) {
       contador++;
       aux = aux->sgte;
    }

    return contador;
}

void ingresar (){
    
    if(!c){
        c=new(pilas);
        cout<<"\n Ingrese elemento: ";
        cin>>c->d;
        c->a=NULL;
        return;
    }
 
    e=new(pilas);
    cout<<"\n Ingrese elemento: ";
    cin>>e->d;
    e->a=c;
    c=e;
}

void ultimo(){
    if(c == NULL){
        cout << "\n La pila esta vacia, no hay elementos para ser mostrar.\n";
    } else {
        e = c;
        while(e != NULL){
            if(e->a == NULL){
                cout << "\n El primer dato ingresado fue: " << e->d;
            }
            e = e->a; 
        }
    }
}

void sacar(){
    if(!c){
        cout<<"\n No hay elementos!!";
        return;
    }
 
    e=new(pilas);
    e=c;
    cout<<"\n Elemento eliminado: " <<e->d;
    c=e->a;
    delete(e);
}

void actualizar_pila(){
    int y=2,i,ca=0;
    e=c;

    while(e){
        ca++;
        e=e->a;
    }
 
    for(i=0;i<=ca;i++){
        cout<<" ";
    }
    
    i=0;
    e=c;
    
    while(e){
        cout<<"\n";
        cout<<" "<<++i<<" - "<<e->d;
        e=e->a;
    }
}

bool estaVacia(){
    if(c == NULL){
        return true;
    } else {
        return false;
    }
}

int contarElementos(){
    int contador = 0;
    pilas* temp = c;
    while(temp != NULL){
        contador++;
        temp = temp->a;
    }
    return contador;
}

void vaciarPila(){
    while(c != NULL){
        pilas* temp = c;
        c = c->a;
        delete temp;
    }
    cout << "\n La pila ha sido vaciada.";
}

void menuColas(){
	system ("color e0");
    cout<<"\n\t IMPLEMENTACION DE COLAS EN C++\n\n";
    cout<<" 1. Encolar                               "<<endl;
    cout<<" 2. Desencolar                            "<<endl;
    cout<<" 3. Mostrar cola                          "<<endl;
    cout<<" 4. Vaciar cola                           "<<endl;
    cout<<" 5. Mostrar primer elemento a desencolar  "<<endl;
    cout<<" 6. Mostrar ultimo elemento a desencolar  "<<endl;
    cout<<" 7. Mostrar numero de elementos en la cola"<<endl;
    cout<<" 8. Salir al menu principal               "<<endl;
    cout<<" 9. Salir de todo el programa             "<<endl;
 
    cout<<"\n Ingrese la opción: ";
}

void menuPilas(){
	system ("color a0");
	cout<<"\n\t IMPLEMENTACION DE PILAS EN C++\n";
    cout<<"\n 1. Ingresar datos";
    cout<<"\n 2. Extraer datos";
    cout<<"\n 3. Ver el ultimo elemento";
    cout<<"\n 4. Verificar si la pila esta vacia";
    cout<<"\n 5. Contar los elementos de la pila";
    cout<<"\n 6. Vaciar pila";
    cout<<"\n 7. Mostrar pila";
    cout<<"\n 8. Salir al menu principal";
    cout<<"\n 9. Salir de todo el programa";
        
    cout<<"\n\n Ingrese opcion: ";
}

void menu() {
    int opc;
    int dato;  
    int op;  
    int x ; 

    for (;;) {
    	system ("color b0");
       cout << "\n\tIMPLEMENTACION DE COLAS Y PILAS EN C++\n" << endl;
       cout << " 1. Operaciones con la cola" << endl;
       cout << " 2. Operaciones con la pila" << endl;
       cout << " 3. Salir de todo el programa" << endl;
       cout << "\n Ingrese una opción: ";
       cin >> opc;
       system("cls");

       switch (opc) {
          case 1:
                do{
                    menuColas();  
                    cin>> op;
         
                    switch(op){
                        case 1:
                             cout<< "\n Numero a encolar: "; 
                             cin>> dato;
                             encolar(dato);
                             cout<<"\n Numero " << dato << " encolado...\n";
                        break;
             
             
                        case 2:
                        	if (q.delante == NULL) {
        						cout << "\n La cola está vacía. No se pueden desencolar elementos.\n";
    						} else {
                            	x = desencolar();
                            	cout<<"\n Numero "<< x <<" desencolado...\n";
                            }
                        break;
                         
             
                        case 3:
                             cout << "\n Mostrando cola\n";
                             if(q.delante!=NULL) muestraCola();
                             else   cout<<"\n Cola vacia...!"<<endl;
                        break;
             
             
                        case 4:
                             vaciaCola();
                             cout<<"\n Hecho...\n";
                        break;
            
                        case 5:
                            muestraPrimerDesencolar();
                        break;
                        
                        case 6:
                            muestraUltimoDesencolar();
                        break;
                        
                        case 7:
                            cout << "\n Numero de elementos en la cola: " << numElementosCola() << endl;
                        break;
                        
                        case 8:
                            system ("cls");
                            menu();
                        break;
                        
                        case 9:
                            exit(0);
                        break;
                        
                        default:
                            cout << "\n Opción no válida. Intente de nuevo." << endl;
                        break;
                    }
             
                    cout<<endl<<endl;
                    system("pause");  
                    system("cls");
             
                }while(op!=9);
                             
            case 2:
                do{
                    menuPilas();
                    cin>>opc;
                
                    switch(opc){
                    
                    case 1:
                        ingresar();
                        actualizar_pila();
                    break;
                    
                    case 2: 
                        sacar();
                    break;
                    
                    case 3: 
                        ultimo();
                    break;
            
                    case 4:
                        if(estaVacia()){
                            cout << "\n La pila esta vacia.\n";
                        } else {
                            cout << "\n La pila no esta vacia.\n";
                        }
                    break;
            
                    case 5:
                        cout << "\n Hay " << contarElementos() << " elementos en la pila.\n";
                    break;
                    
                    case 6:
                        vaciarPila();
                    break;
                    
                    case 7:
                    	if(c == NULL){
					        cout << "\n La pila esta vacia, no hay elementos para ser mostrar.\n";
					    } else {
					        actualizar_pila();
					    }
                    break;
                    
                    case 8:
                        system ("cls");
                        menu();
                    break;
                    
                    case 9: 
                        exit(0);
                        default: cout<<"\n Opcion no valida!!\n"; 
                    break;
                    }
            
                    cout<<"\n\n Oprima una tecla para continuar\n";
                    getch();
                    system ("cls");
                    
                }while(op!=9);
                
            break;

            case 3:
                exit(0);
            break;

            default:
                cout << "\n Opción no válida. Intente de nuevo.\n" << endl;
            break;
       }
    }
}

int main() {
    setlocale(LC_ALL,"");
    inicializarCola();
    menu();
    return 0;
}

