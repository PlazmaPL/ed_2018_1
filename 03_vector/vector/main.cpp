#include <iostream>

using namespace std;

struct Vetor{
    int _data;//bloco de dados
    int _capacidade;//tamanho maximo do vetor
    int _size; //quantos elementos estao inseridos

    Vetor(int capacidade){
        this->_capacidade = capacidade;
        this->_size = 0;
//        this->data = (int*) malloc(capacidade * 4);//retorno lixo
        this->_data = new int[capacidade];//retorno zerado
    }
    void push_back(int value){
        if(this->_size == this->_capacidade)
            return;
            //this->reserve(2 * _capacitade);
        this->_data[this->_size] = value;
        this->_size += 1;
    }
    void pop_back(){
        if(this->_size == 0)
            return;
        this->_data[_size] = 0;
        this->_size -= 1;
    }

    //retornar a refencia à variavel dessa posicao
    int& at(int indice){
        return this->_data[indice];
    }
    int& front(){
        return this->_data[0];
    }
    int& back(){
        return this->_data[this->_size - 1];
    }
    int * begin(){
        return &this->_data[0];
    }
    int * end(){
        return &this->_data[this->_size];
    }

    int capacity(){
           return _capacidade;
        }
        int size(){
            return _size;
        }

    void reserve(int capacity){
        Vetor vet(_capacidade);
        for (int i = 0; i < this->size(); i++){
            vet.push_back(this->at(i));
        }
       if(capacity <= _capacidade){
           this->_capacidade = capacity;
           this->_size = 0;
           this->_data = new int[capacity];

           for (int i = 0; i < capacity; ++i) {
               this->push_back(vet.at(i));
           }
        }else{
           this->_capacidade = capacity;
           this->_size = 0;
           this->_data = new int[capacity];
           for (int i = 0; i < vet.size(); ++i) {
               this->push_back(vet.at(i));
           }
       }
    }


};

#include <vector>
int main()
{

//    list<int> list = {3, 2, 5, 4, 3, 6, 8, 6};
//    for(int x : list)
//        cout << x << " ";
//    for(auto it = list.begin(); it != list.end(); it++)
//        cout << *it << " ";

    Vetor pivet(5);
    for (int i = 0; i < pivet.capacity(); ++i) {
        pivet.push_back(i);
        cout << pivet.at(i) << endl;
    }






    return 0;
}










