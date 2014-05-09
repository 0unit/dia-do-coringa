
#include "ddcuringa.h"

DDCuringa::DDCuringa(unsigned int dia, unsigned int mes, unsigned int ano){
	setAno(ano);
	setDia(dia);
	setMes(mes);
	setNumeroDias(getDia(),getMes(),getAno());
	}
//FUNCOES LIVRES
unsigned int DDCuringa::rotacionaAno (unsigned int ano){ //ANO NORMAL
         ano = ano - 1789; //1970 é o ano que frode chegou na ilha
         return ano;	   //mas a data na função é 1789 por que um ano que começa no domingo.
         }
         
unsigned int DDCuringa::rotacionaData(unsigned int dia, unsigned int ano){ //ANO E DIA NORMAIS
			if(dia > 60) dia = dia - 60; //frode chegou na ilha no dia 17 de janeiro
			else dia = dia + 305;
			if(eBissexto(ano-1)) dia++; //se o ano anterior foi bissexto
			return dia;
			}		 
			
bool DDCuringa::eBissexto(unsigned int ano){
	if ((!(ano%4))||((!(ano%100))&&(!(ano&400)))) return true; //eh ano bissexto
    else return false;
	}
    	
//DIA
void DDCuringa::setDia(unsigned int dia){
	if((dia > 0)&&(dia < 32)) ddia = dia;
	setNumeroDias(ddia,dmes,dano);
}

unsigned int DDCuringa::getDia(){ 
         return ddia; 
         }

unsigned int DDCuringa::getNaipeDia(){
       naipeDia(rotacionaData(getNumeroDias(),getAno()));
       return ndia; 
       }

unsigned int DDCuringa::getCartaDia(){
       cartaDia(rotacionaData(getNumeroDias(),getAno()));
       return cdia; 
       }

void DDCuringa::cartaDia(unsigned int dia){ // dia decrementando por causa da natureza da array de char
	if(dia < 365){
            cdia = (--dia) % 13; 
            }
	else {
         cdia = 14;
         }
}

void DDCuringa::naipeDia(unsigned int dia){ 
	if(dia < 365) ndia = ((--dia / 13)) % 4; 
	else if(dia == 365) ndia = 14;
	else if(dia == 366) ndia = 15;
}// dia decrementando por causa da natureza da array de char


//SEMANA	
unsigned int DDCuringa::getNaipeSemana(){ 
       naipeSemana(rotacionaData(getNumeroDias(),getAno()));
       return nsemana; 
       }
       
unsigned int DDCuringa::getCartaSemana(){
       cartaSemana(rotacionaData(getNumeroDias(),getAno()));
       return csemana; 
       }
       
void DDCuringa::cartaSemana(unsigned int dia){ 
     csemana = (dia / 7) % 13; 
     }

void DDCuringa::naipeSemana(unsigned int dia){ 
     nsemana = ((dia / 7)/ 13) % 4;  
     }	


//MES	
void DDCuringa::setMes(unsigned int mes){ 
	if((mes > 0)&&(mes < 13)){
		dmes = mes; 
	}
	setNumeroDias(ddia,dmes,dano);
}

unsigned int DDCuringa::getMes(){ 
         return dmes; 
         }
         
unsigned int DDCuringa::getNaipeMes(){
       naipeMes((getNumeroDias()),getAno());      
       return nmes; 
       }
       
unsigned int DDCuringa::getCartaMes(){ 
       cartaMes(rotacionaData(getNumeroDias(),getAno()));
       return cmes; 
       }
       
void DDCuringa::cartaMes(unsigned int dia){ //segue o sistema de mes de 28 dias de frode
    unsigned numero = 0;
	dia = getNumeroDias();
	cmes = (--dia / 28) % 13; // dia decrementando por causa da natureza da array de char
	}
	
void DDCuringa::naipeMes(unsigned int dia, unsigned int ano){ //DIA NORMAL SEM CONVERSAO
	unsigned int biss = 0;	//marcador de ano bissexto
	unsigned int figura = 0;
	if(eBissexto(ano-1)) biss = 1;      //ano - 1 se anoterio e bissexto
	if (dia <= (62-biss)) figura = 1;       //Verão 22/12 339 paus 1
    else if (dia <= (154-biss)) figura = 2; //Outono 21/3 63 copas 2
    else if (dia <= (247-biss)) figura = 3; //Inverno 22/6 155 espadas 3
    else if (dia <= (338-biss)) figura = 0; //Primavera 23/9 248 ouros 0
    else if (dia <= (367-biss)) figura =  1; //Verão 22/12 339 paus 1
	nmes = figura;
    }

//ANO	
void DDCuringa::setAno(unsigned int ano){ 
	if((ano > 1789)&&(ano <= 9999)) dano = ano;
	setNumeroDias(ddia,dmes,dano);
}

unsigned int DDCuringa::getAno(){ 
         return dano; 
         }
         
unsigned int DDCuringa::getNaipeAno(){ 
       naipeAno(getAno());
       return nano; 
       }
       
unsigned int DDCuringa::getCartaAno(){
       cartaAno(getAno());
       return cano; 
       }
       
void DDCuringa::cartaAno(unsigned int ano){ //ANO NORMAL
		ano = rotacionaAno(ano);
		cano = ano % 13;
		}
		
void DDCuringa::naipeAno(unsigned int ano){ //ANO NORMAL
		ano = rotacionaAno(ano);
		nano = (ano / 13) % 4;
		}
		
//NUMERO DE DIAS
unsigned int DDCuringa::getNumeroDias(){ 
         return numdia; 
         }
         		
void DDCuringa::setNumeroDias(unsigned int dia,unsigned int mes,unsigned int ano){ //DIA, MES e ANO NORMAIS
    unsigned int contador = 0;
    unsigned int biss = 0;
    
    if (eBissexto(ano)) biss = 1;

    if (dia<1){ // Verifica se dia não é negativo
		ddia = 1;
		}
    
    if ((mes<1)||(mes>12)){ // Veifica se mes está correto
		dmes = 1;
		}

    if ((ano<1789)||(ano>9999)){ //Verifica se o ano esta dentro dos padrões
		dano = 1789;
		}

    if ((mes==1)||(mes==3)||(mes==5)||(mes==7)||(mes==8)||(mes==10)||(mes==12)){
               if (dia>31) 	ddia = 1;
    }

    if ((mes==4)||(mes==6)||(mes==9)||(mes==11)){
               if (dia>30) ddia = 1;
    }

    if (mes==2){
               if (biss != 0){
                    if (dia>29) ddia = 1;
               }
               else{
                    if (dia>28) ddia = 1;
               }
    }

    switch (mes){
    /* Simplismente a cada mes soma-se os dias do mes 
    anterior, mais os dia enviados pelo ''dia'' */
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
    numdia = contador;
}


