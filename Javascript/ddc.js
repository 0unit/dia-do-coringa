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

//inferno de  Math.abs que nao funciona cmg
function Infer(nume){ 
	var i = 0;
	while(i < nume){
		i++
		}	
	return (--i);
}		

//RECEBE DATA ORIGINAL	
function FrodeSimples(dia, mes, ano){ 
    var cartas =["1","2","3","4","5","6","7","8","9","10","J","Q","K","JO"];
    var naipes =["O","P","C","E"];
    var numerodedia;
    numerodedia = DiaDoAno(dia,mes,ano);
    if(numerodedia == -1) return "00000000";
    var numerodedia = CorrigeDiaFrode( numerodedia , ano );
    
    var s_frode;
	var s_dia;
	var s_semana;
	var s_mes;
	var s_ano;
	
    //imprime dias
    if(numerodedia < 365){ 
              s_dia = cartas[CartaDiaFrode(numerodedia)] + naipes[NaipeDiaFrode(numerodedia)];
              }
    else if(numerodedia == 365) s_dia = cartas[13];
    else if(numerodedia == 366) s_dia = cartas[13];
        	
    s_semana = cartas[ CartaSemanaFrode(numerodedia) ] + naipes[ NaipeSemanaFrode(numerodedia) ];
	s_mes = cartas[ Mes(numerodedia) ] + naipes[ EstacaoFrode(dia, ano) ];
	s_ano = cartas[ CartaAnoFrode(ano) ] + naipes[ NaipeAnoFrode(ano) ];
	s_frode = s_dia + s_semana + s_mes + s_ano;
	//formato de retorno dia semana mes ano sempre numero/naipe
    return s_frode; 
    }

//RECEBE DATA ORIGINAL
function ImprimeCalendarioFrode(dia, mes, ano){ 
    var cartas = ["&aacute;s","dois","tr&ecirc;s","quatro","cinco","seis","sete","oito","nove","dez","Valete","Dama","Rei","Curinga"];
    var naipes = [" de ouros"," de paus"," de copas"," de espadas"];
    var numerodedia = 0;
    
    numerodedia = DiaDoAno(dia,mes,ano);
    if(numerodedia == -1)return -1;
    
	numerodedia = CorrigeDiaFrode( numerodedia , ano );
	

	//Armazena o valor do dia como ele muda muito eh algo necessario
	var master; 
	if(numerodedia < 365) master = "\tDia  " + cartas[CartaDiaFrode(numerodedia)] + naipes[NaipeDiaFrode(numerodedia)];
    else if(numerodedia == 365) { master = "\tDia " + cartas[13]; }
    else if(numerodedia == 366) { master = "\tDuplo dia " + cartas[13]; }
		
    document.writeln(master + "<br />" +
	"Semana  " + cartas[CartaSemanaFrode(numerodedia)] + naipes[NaipeSemanaFrode(numerodedia)] + "<br />" +
	"\n\tM&ecirc;s  " + cartas[Mes(numerodedia)] + " na esta&ccedil;&atilde;o" + naipes[EstacaoFrode(dia, ano)] + "<br />" +
	"\n\tAno  " + cartas[CartaAnoFrode(ano)] + naipes[NaipeAnoFrode(ano)] + "<br />" +
	"\n\t e dia n&uacute;mero " + numerodedia + "<br />");
    return 0;
    };

function CartaDiaFrode(dia){
	return (Infer(dia % 13)); 
	}

function NaipeDiaFrode(dia){
	// dia decrementando por causa da natureza da array de char
	return (Infer(((dia-1) / 13) % 4)); 
	}

function CartaSemanaFrode(dia){
    return (Infer(dia / 7) % 13);
	}

function NaipeSemanaFrode(dia){
	return (Infer((dia / 7)/ 13) % 4);
	}	

function Mes(dia){
	//segue o sistema de mes de 28 dias de frode	
	return (Infer((dia / 28) % 13));
	}

//RECEBE DIA NORMAL SEM CONVERSAO	
function EstacaoFrode(dia, ano){ 
	var biss = 0;                		  //marcador de ano bissexto
	if(AnoBissexto(ano-1)) biss = 1;      //ano - 1 se anoterio e bissexto
	if (dia <= (62-biss)) return 1;       //Verão 22/12 339 paus 1
    else if (dia <= (154-biss)) return 2; //Outono 21/3 63 copas 2
    else if (dia <= (247-biss)) return 3; //Inverno 22/6 155 espadas 3
    else if (dia <= (338-biss)) return 0; //Primavera 23/9 248 ouros 0
    else if (dia <= (367-biss)) return 1; //Verão 22/12 339 paus 1
    }

//RECEBE ANO NORMAL
function CartaAnoFrode(ano){ 
		var temp = Infer(CorrigeAnoFrode(ano) % 13)
		if(temp < 0) temp = 12;
		return (temp); 
		}
		
//RECEBE ANO NORMAL
function NaipeAnoFrode(ano){
		return (Infer((CorrigeAnoFrode(ano) / 13) % 4));
		}

//RECEBE ANO NORMAL
function CorrigeAnoFrode (ano){
         return (ano - 1789); //1970 é o ano que frode chegou na ilha
         }

//RECEBE ANO E DIA NORMAIS		 
function CorrigeDiaFrode(dia, ano){
			if(dia > 60){
				//frode chegou na ilha no dia 17 de janeiro
				dia = dia - 60; 
				}
			else { 
				dia = dia + 305;
				}
			//se o ano anterior foi bissexto
			if(AnoBissexto(ano-1)) dia++; 
			return (dia);
			}

//RECEBE ANO NORMAL			
function AnoBissexto(ano){
	if ((!(ano % 4 ))||((!(ano % 100))&&(!(ano & 400)))){
		return true; 
		}
	else {
		return false; 
		}
}

//RECEBE DIA, MES e ANO NORMAIS
function DiaDoAno(dia,mes,ano){ 
    var contador = 0;
    var biss = 0;
	
	if (AnoBissexto(ano)) biss = 1;
	
    var diaerrado = "dia errado";
    var meserrado = "mes errado";
    var anoerrado = "ano errado <anos validos de 1790 a 9999>";
	
    if (dia<1){ 
		alert(diaerrado);
		return -1;
		}
    
    if ((mes<1)||(mes>12)){ 
		alert(meserrado);
		return -1;
		}
	
    if ((ano<1790)||(ano>9999)){ 
		alert(anoerrado);
		return -1;
		}

    if ((mes==1)||(mes==3)||(mes==5)||(mes==7)||(mes==8)||(mes==10)||(mes==12)){
               if (dia>31){
				alert(diaerrado);
				return -1;
				}
    }

    if ((mes==4)||(mes==6)||(mes==9)||(mes==11)){
               if (dia>30){
				alert(diaerrado);
				return -1;
				}
    }

    if (mes==2){
               if (biss != 0){
                    if (dia>29){
						alert(diaerrado);
						return -1;
						}
               }
               else{
                    if (dia>28){
						alert(diaerrado);
						return -1;
						}
               }
    }
	
	var mess = [0,1,31,59,90,120,151,181,212,243,273,304,334];
	var tempo = 0;
	if(mes < 3){ 
		tempo = mess[mes];
		contador = tempo + dia;
		}
	else{
		tempo = mess[mes];
		contador = tempo + biss + dia;
		}
		
    return (contador);
}


