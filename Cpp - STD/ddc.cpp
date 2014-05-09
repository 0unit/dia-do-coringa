/*
  Name: Dia do Curinga
  Copyright: GPL v2
  Author: Jeison Cardoso
  Date: 11/01/08 03:21 - 21/04/09 22:09
  Description: Um conversor para o calendario ficticio do livro de Jostein 
               Gaarder "O Dia do Curinga". Tendo como base um baralho.
                
    364 dias representados cada um por uma carta
    52 semanas, uma para cada carta
    13 meses, um para cada numero
    28 dias em cada mes
    O dia 365 é o um dia extra o dia do curinga
    A cada quatro anos a dois dias extras o Duplo dia do curinga
    
    A contagem dos anos começa em 1790, o dia em 17, e o mes em janeito a data
    em que o personagem chegou na ilha.
    A contagem de semanas e dias começa entçao em 17/1/1790 
    
    !Não está no livro é coisa da minha cabeça e leva em conta o hemisfério sul!
    As estações do ano são marcados por diferentes naipes assim fornecendo os
    naipes dos meses.
    * outono é paus;
    * verão e ouros;
    * primavera é copas;
    * inverno é espadas;
    
    A primeira semana do ano 1790 é semana de ás de ouros
    A ordem dos naipes é ouros -> paus -> espadas ->copas
    
    Ás de espadas dá azar :)
    */

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int DiaDoAno(unsigned int dia,unsigned int mes,unsigned int ano);   
unsigned int CorrigeDiaFrode(unsigned int dia, unsigned int ano);
unsigned int NaipeAnoFrode(unsigned int ano);
unsigned int CartaAnoFrode(unsigned int ano);
unsigned int EstacaoFrode(unsigned int dia, unsigned int ano);
bool AnoBissexto(unsigned int ano);
unsigned int Mes(unsigned int dia);
unsigned int NaipeSemanaFrode(unsigned int dia);
unsigned int CartaSemanaFrode(unsigned int dia);
unsigned int NaipeDiaFrode(unsigned int dia);
unsigned int CartaDiaFrode(unsigned int dia);
unsigned int CorrigeAnoFrode (unsigned int ano);
int ImprimeCalendarioFrode(unsigned int dia, unsigned int mes, unsigned int ano);
string FrodeSimples(unsigned int dia, unsigned int mes, unsigned int ano);

int main(){

	unsigned int dia, mes, ano = 0;	
    int numerodedia = 0;
    int tmp_dia, tmp_mes, tmp_ano = 0;
    
do {
	cout << "\n\tEntre com dia mes e ano (separados por espaco):" << endl;
	cout << "\tDigite -1 para terminar"<< endl;
	cout << "\t$>";
    
    cin >> tmp_dia;
    if(tmp_dia == -1) return 0;
    cin >> tmp_mes >> tmp_ano;
 
    dia = tmp_dia;
    mes = tmp_mes;
    ano = tmp_ano;
    
    ImprimeCalendarioFrode(dia,mes,ano);
    
    cout << "\n\tSimples -- " << FrodeSimples(dia,mes,ano) << endl;
    
    } while (tmp_dia != -1);
    return(0);
}

string FrodeSimples(unsigned int dia, unsigned int mes, unsigned int ano){ //RECEBE DATA ORIGINAL
    string cartas[14] ={"1","2","3","4","5","6","7","8","9","10","J","Q","K","JO"};
    string naipes[4] ={"O","P","C","E"};
    int numerodedia;
    numerodedia = DiaDoAno(dia,mes,ano);
    if(numerodedia == -1)return "00000000";
    numerodedia = CorrigeDiaFrode( numerodedia , ano );
    
    string s_frode, s_dia, s_semana, s_mes, s_ano;
    
    if(numerodedia < 365){ //imprime dias
              s_dia = cartas[CartaDiaFrode(numerodedia)] + naipes[NaipeDiaFrode(numerodedia)];
              }
    else if(numerodedia == 365) s_dia = cartas[13];
    else if(numerodedia == 366) s_dia = cartas[13];
        	
    s_semana = cartas[CartaSemanaFrode(numerodedia)] + naipes[NaipeSemanaFrode(numerodedia)];
	s_mes = cartas[Mes(numerodedia)] + naipes[EstacaoFrode(dia, ano)];
	s_ano = cartas[CartaAnoFrode(ano)] + naipes[NaipeAnoFrode(ano)];
	s_frode = s_dia + s_semana + s_mes + s_ano;
    return s_frode; //formato de retorno dia semana mes ano sempre numero/naipe
    }

int ImprimeCalendarioFrode(unsigned int dia, unsigned int mes, unsigned int ano){ //RECEBE DATA ORIGINAL
    string cartas[14] ={"de As","de Dois","de Tres","de Quatro","de Cinco",
                          "de Seis","de Sete","de Oito","de Nove","de Dez",
                          "de Valete","de Dama","de Rei","do Curinga"};
    string naipes[4] ={" de ouros"," de paus"," de copas"," de espadas"};
    int numerodedia = 0;
    
    numerodedia = DiaDoAno(dia,mes,ano);
    if(numerodedia == -1)return -1;
    
	numerodedia = CorrigeDiaFrode( numerodedia , ano );
		
	cout << "\n\tCalendario de Paciencia de Frode";
    cout << "\n\t---------------------------------\n" << endl;
    
    if(numerodedia < 365){ //imprime dias
              cout << "\tDia de " << cartas[CartaDiaFrode(numerodedia)] 
              << naipes[NaipeDiaFrode(numerodedia)] << endl;
              }
    else if(numerodedia == 365){ //excecão a regra pelos dias do curinga
                   cout << "\tDia " << cartas[13] << endl;
                   }
    else if(numerodedia == 366) cout << "\tDuplo dia " << cartas[13] << endl;
        	
    cout << "\tSemana de " << cartas[CartaSemanaFrode(numerodedia)] 
         << naipes[NaipeSemanaFrode(numerodedia)] << endl;
	
    cout << "\tMes de " << cartas[Mes(numerodedia)] 
         << " estacao" << naipes[EstacaoFrode(dia, ano)] << endl;
	
    cout << "\tAno de " << cartas[CartaAnoFrode(ano)] 
         << naipes[NaipeAnoFrode(ano)] << endl; 
	
	cout << "\n\t" << dia << "/" << mes << "/" << ano 
         << " e dia numero " << numerodedia << endl;
    return 0;
    }

unsigned int CartaDiaFrode(unsigned int dia){
	return --dia % 13; // dia decrementando por causa da natureza da array de char
	}

unsigned int NaipeDiaFrode(unsigned int dia){
	return (--dia / 13) % 4; // dia decrementando por causa da natureza da array de char
	}

unsigned int CartaSemanaFrode(unsigned int dia){
    return (dia / 7) % 13;
	}

unsigned int NaipeSemanaFrode(unsigned int dia){
	return ((dia / 7)/ 13) % 4;
	}	

unsigned int Mes(unsigned int dia){ //segue o sistema de mes de 28 dias de frode
    dia = (--dia / 28) % 13; // dia decrementando por causa da natureza da array de char
	}

unsigned int EstacaoFrode(unsigned int dia, unsigned int ano){ //DIA NORMAL SEM CONVERSAO
	unsigned int biss = 0;                //marcador de ano bissexto
	if(AnoBissexto(ano-1)) biss = 1;      //ano - 1 se anoterio e bissexto
	if (dia <= (62-biss)) return 1;       //Verão 22/12 339 paus 1
    else if (dia <= (154-biss)) return 2; //Outono 21/3 63 copas 2
    else if (dia <= (247-biss)) return 3; //Inverno 22/6 155 espadas 3
    else if (dia <= (338-biss)) return 0; //Primavera 23/9 248 ouros 0
    else if (dia <= (367-biss)) return 1; //Verão 22/12 339 paus 1
    }

unsigned int CartaAnoFrode(unsigned int ano){ //ANO NORMAL
		ano = CorrigeAnoFrode(ano);
		return ano % 13; 
		}

unsigned int NaipeAnoFrode(unsigned int ano){ //ANO NORMAL
		ano = CorrigeAnoFrode(ano);
		return (ano / 13) % 4; 
		}

unsigned int CorrigeAnoFrode (unsigned int ano){ //ANO NORMAL
         ano = ano - 1790; //1970 é o ano que frode chegou na ilha
         return ano;
         }

unsigned int CorrigeDiaFrode(unsigned int dia, unsigned int ano){ //ANO E DIA NORMAIS
			if(dia > 60) dia = dia - 60; //frode chegou na ilha no dia 17 de janeiro
			else dia = dia + 305;
			if(AnoBissexto(ano-1)) dia++; //se o ano anterior foi bissexto
			return dia;
			}
	
bool AnoBissexto(unsigned int ano){ //ANO NORMAL
	if ((!(ano%4))||((!(ano%100))&&(!(ano&400)))) return true; //eh ano bissexto
	else return false;
}

int DiaDoAno(unsigned int dia,unsigned int mes,unsigned int ano){ //DIA, MES e ANO NORMAIS

    unsigned int contador = 0;
    unsigned int biss = 0;
    
    string diaerrado = "\t!!!!!!!!!!!!!!! dia errado !!!!!!!!!!!!!!!!!!!\n";
    string meserrado = "\t!!!!!!!!!!!!!!! mes errado !!!!!!!!!!!!!!!!!!!\n";
    string anoerrado = "\t!! ano errado <anos validos de 1790 a 9999> !!\n";
    
     if (AnoBissexto(ano)) biss = 1;

    if (dia<1){ // Verifica se dia não é negativo
		cout << diaerrado << endl;
		return -1;
		}
    
    if ((mes<1)||(mes>12)){ // Veifica se mes está correto
		cout << meserrado << endl;
		return -1;
		}

    if ((ano<1790)||(ano>9999)){ //Verifica se o ano esta dentro dos padrões
		cout << anoerrado << endl;
		return -1;
		}

    if ((mes==1)||(mes==3)||(mes==5)||(mes==7)||(mes==8)||(mes==10)||(mes==12)){
               if (dia>31){
				cout << diaerrado << endl;
				return -1;
				}
    }

    if ((mes==4)||(mes==6)||(mes==9)||(mes==11)){
               if (dia>30){
				cout << diaerrado << endl;
				return -1;
				}
    }

    if (mes==2){
               if (biss != 0){

                    if (dia>29){
						cout << diaerrado << endl;
						return -1;
						}
               }
               else{
                    if (dia>28){
						cout << diaerrado << endl;
						return -1;
						}
               }
    }

    switch (mes)
    /* Simplismente a cada mes soma-se os dias do mes 
    anterior, mais os dia enviados pelo ''dia'' */
    {
           case 1: //31
                contador = dia;
           break;
           case 2: //28
                contador = 31 + dia;
           break;
           case 3: //31
                contador = 59 + biss + dia;
           break;
           case 4: //30
                contador = 90 + biss + dia;
           break;
           case 5: //31
                contador = 120 + biss + dia;
           break;
           case 6: //30
                contador = 151 + biss + dia;
           break;
           case 7: //31
                contador = 181 + biss + dia;
           break;
           case 8: //31
                contador = 212 + biss + dia;
           break;
           case 9: //30
                contador = 243 + biss + dia;
           break;
           case 10: //31
                contador = 273 + biss + dia;
           break;
           case 11: //30
                contador = 304 + biss + dia;
           break;
           case 12: //31
                contador = 334 + biss + dia;
           break;
    }
    return (contador);
}
