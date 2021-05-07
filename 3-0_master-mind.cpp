#include <stdio.h> /* printf, scanf, puts, NULL */
#include <iostream>
#include <time.h> /* time */
#include <conio.h>
#include <cctype> // uppercase
#include <stdlib.h>// para limpar a variavel  /* srand, rand */
#include <string> // atribuir variavel do tipo string
#include<bits/stdc++.h> // usar a função transform() e ::toupper no STL
#include <cstring>

using namespace std;

#define NUM_PINS 6
static string pins = "ABCDEF";
#define NUM_CHAVE 4
#define FIM "\n"
#define CHAVE_SEM_REPETICOES true
void jogar();
void contarCertos();
void contarTrocados();
void apresentaResultados();


int geraPin( int const n){

    return ( rand() % n);


}

void desenhaSegmento(string& chave, char& b){
	int cont= 0;
	for(int i= 0; i< NUM_CHAVE; i++){ // calculando total de letras
		chave[i]= b;
		cout<< "-" << b;
		cont++;//letras restantes
	}
	cout << endl;
}

void geraSequencia( string& chave){

    //srand(time(NULL));
    chave= "";
    for ( int i = 0; i < NUM_CHAVE; i++){

        int chave_1pin;
            chave_1pin = geraPin(NUM_PINS);
            chave += pins[chave_1pin];
// como fazer sem repetição
	}

}

void apresentaResultados( string const numCertos, string const numTrocados){

	cout << '[';
	cout << numCertos;
	cout << numTrocados;
    cout << ']';


}

int contarCertos(string const chave, string const s){
    bool acertos = false;
	int i, done;
	for(i= 0; i < NUM_CHAVE; i++){
        if(s[i] == chave[0]){
            acertos = true;
            done++;
            return 0;
        }else if(!acertos){
            acertos = false;
        }

		switch(done){
	        case 1:
	            cout << "+";
	            break;
	        case  2:
	            cout << "++";
	            break;
	        case 3:
	            cout << "+++";
	            break;
	        case 4:
	            cout << "++++";
	            break;
	        case 0:
	            cout << "";
	            break;
	        default:
	            cout << "";
                return 0;
		}
    }
}

int contarTrocados( string const chave, string const s){
   bool acertos = false;
    int i;
    int done;

    int ntrocados = 0;

    for(i= 0; i < NUM_CHAVE; i++){
        if(s[i] == chave[0]){
            acertos = true;
            done++; // saber se a posicao e elemento estao certos.
        }
        else if(s[1] == chave.length()){
            ntrocados ++;
            return 0;

        }else if(!acertos){
            acertos = false;
        }
        switch(ntrocados){
            case 1:
                cout << "-";
                break;
            case  2:
                cout << "--";
                break;
            case 3:
                cout << "---";
                break;
            case 4:
                cout << "----";
                break;
           case 0:
                cout << "";
                break;
            default:
                return 0;

    	}
    }
}


bool caractereValido( char& c){// Verificar se os caractere introduzidos são validos

   for (int i= 0; i < NUM_PINS; i++){
       if (c == pins[i]){
           return 1;
       }
   }
   return 0;

}

void  lerCaractere(string const s, char &c){

    do {
    	//cin.get(c);
        cout << s ;
        cin >> c;
        c = toupper(c);

        if(caractereValido(c)){
            cout << " "<< endl;
            return;

        } else {
            cout << " " << "Caracter Ilegal" << endl;
            cin.clear();
        }

    } while(true);
}

void jogar(){

 int num;

    cout << "====================================="<< endl;
    cout << "           *** MasterMind *** "       << endl;
    cout << "====================================="<< endl;
    cout<< "Introduza o numero maximo de tentativas admitido(max 10): ";
    cin >> num;
    if(num < 1 || num > 10){

        cout << "ATENCAO..Numero Invalido!"<< endl;
        jogar();

    } else{

        string chave;
        string resp = "";
        char c, b;
        int numCertos =0,  chances = 0;;


        srand(time(NULL));
        geraSequencia(chave);
        cout << "Chave Gerada: " << chave << endl;

        desenhaSegmento(chave, b);
        while((chances < num) && (resp != chave)){

            cout << "Jogada "<< chances+1 <<": ";

            resp = "";

            for(int i = 0; i < NUM_CHAVE; i++){

                lerCaractere(resp, c);
                resp += c;
            }

            cout << "Jogada Inserida: " << resp << endl;
            string nCerto, nTrocados;

            nCerto = contarCertos(chave, resp);
            nTrocados = contarTrocados(chave, resp);

            apresentaResultados(nCerto, nTrocados);

            chances++;

            cout<< "\n Tentativas restantes: " << num-chances << endl;

	    	if(chances >= num){
			 	if(resp == chave){
					cout << "    PARABENS '-' " << "\n         Voce acertou na "<< chances << " tentativa."<< endl;
				} else {
	        		cout << "    VOCE PERDEU! " << "A sequencia correta era: " << chave << endl;
				}
			}
        }
    }
}

void instrucoes(){

    cout << "====================================="<< endl;
    cout << "             Instrucoes             " << endl;
    cout << "====================================="<< endl;
    cout << "Simbolos possiveis: A C B D E F.\nIntroduza um simbolo de cada vez. \nPor cada simbolo na posicao correta e exibido um '+'. \nPor cada simbolo correto na posicao errada e exibido um '-'." << endl;
	cout <<"\n\n Enter -- To be Continue" << endl;
}

int main(){
    int opcao;

    while(opcao != 3){
        cout << "====================================="<< endl;
        cout << "           *** MasterMind *** "       << endl;
        cout << "====================================="<< endl;
        cout << "\nMenu principal: \n"         << endl;
        cout << "1. Jogar jogo \n" << "2. Instrucoes \n"<< "3. Sair \n\n" <<"Opcao:";
        cin >> opcao;
        if ( opcao < 1 or opcao > 3 ){

            cout << "ATENCAO..Opcao Invalida!"<< endl;

        }else{
            switch (opcao) {
                case  1:
                    jogar();
                    break;
                    system("cls");
                case  2:
                    instrucoes();
                    break;

                case 3:
                    cout << "Ate breve!!" << "\n     Obrigada por jogar Master Mind!!!" << endl;
                    break;
                default:
                    cout << "Saindo do programa";
            }
            getch();
        }
    };
    return 0;
}
