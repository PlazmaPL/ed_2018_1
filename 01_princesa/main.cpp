#include <iostream>

using namespace std;

void rodar(int pessoas[], int qtdPessoas)
{

    int aux = pessoas[0];

    for(int i = 0; i < qtdPessoas - 1; i++ )
        pessoas[i] = pessoas[i + 1];

    pessoas[qtdPessoas - 1] = aux;

}

void matar(int pessoas[], int qtdPessoas)
{

    for(int i = 1; i < qtdPessoas - 1; i++ )
        pessoas[i] = pessoas[i + 1];


}
int main()
{

    int qtdPessoas, posseArma;
    int i;

    cout << "Digite o numero maximo de pessoas." << endl;
    cin >> qtdPessoas;
    cout << "Quem vai receber a arma." << endl;
    cin >> posseArma;

    int pessoas[qtdPessoas];


    for(i = 0; i <= qtdPessoas - 1; i++ )
        pessoas[i] = i + 1;


    while(pessoas[0] != posseArma)
    {

        rodar(pessoas, qtdPessoas);

    }

    while(qtdPessoas > 1)
    {

        matar(pessoas, qtdPessoas);
        qtdPessoas--;
        rodar(pessoas, qtdPessoas);

    }

    cout << "O vencedor: " << endl;
    cout << pessoas[0] << endl;

    return 0;
}
