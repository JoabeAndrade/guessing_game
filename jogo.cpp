#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(void){

    cout << "**************************************" << endl;
    cout << "* Bem-vindos ao jogo de adivinhacao! *" << endl;
    cout << "**************************************" << endl;

    cout << "Selecione o nivel de dificuldade: " << endl;
    cout << "Facil - (F)" "\n" << "Medio - (M)" << "\n" << "Dificil - (D)" << endl;

    char dificuldade;

    cin >> dificuldade;

    int numeros_de_tentativas;

    if(dificuldade == 'F'){
        numeros_de_tentativas = 15;
    }else if(dificuldade == 'M'){
        numeros_de_tentativas = 10;
    }else{
        numeros_de_tentativas = 5;
    }
    
    srand(time(NULL));
    const int NUMERO_SECRETO = rand() % 100;
    
    int chute, tentativas = 0;
    bool nao_acertou = true;
    double pontos = 1000.0;

    for(tentativas = 1; tentativas <= numeros_de_tentativas; tentativas++){
        
        cout << "Tentativa numero " << tentativas << endl;
        cout << "Qual e seu chute?: ";
        cin >> chute;
        cout << "Seu chute foi: " << chute << endl;

        double pontos_perdidos = abs(chute - NUMERO_SECRETO)/2.0;
        pontos = pontos - pontos_perdidos;
        bool acertou = chute == NUMERO_SECRETO;
        bool maior = chute > NUMERO_SECRETO;
    
        if (acertou){
            cout << "Parabens! Voce acertou o numero secreto!" << endl;
            nao_acertou = false; 
            break;   
        } else if(maior){
            cout << "Seu chute foi maior que o numero secreto." << endl << "Tente novamente!" << endl;
        } else{
            cout << "Seu chute foi menor que o numero secreto." << endl << "Tente novamente!" << endl;
        } 
    }

    cout << "Fim de jogo!" << endl;
    if(nao_acertou){
        cout << "Voce perdeu! Tente novamente!" << endl;
    }else{
        cout << "Voce acertou o numero secreto " << tentativas << " tentativas" << endl;
        cout.precision(2);
        cout << fixed;
        cout << "Sua pontuacao foi de " << pontos << " pontos." << endl;
    }
    
 return 0;
}
