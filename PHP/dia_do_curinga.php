<?php    
    //dia = tmp_dia;
    //mes = tmp_mes;
    //ano = tmp_ano;
    
// só precisa disso 

    
echo "<html><title>ha</title><body>";

echo ImprimeCalendarioFrode(25,12,1998);
echo FrodeSimples(25,12,1998);
	
function FrodeSimples($dia,$mes,$ano){ //RECEBE DATA ORIGINAL
	echo "FrodeSimples</br>";
    $cartas = array("1","2","3","4","5","6","7","8","9","10","J","Q","K","JO");
    $naipes = array("O","P","C","E");
    
	$numerodedia;
    $numerodedia = DiaDoAno($dia,$mes,$ano);
    if($numerodedia == -1)return "00000000";
    $numerodedia = CorrigeDiaFrode($numerodedia , $ano );
   
    if($numerodedia < 365){ //imprime dias
              $s_dia = $cartas[CartaDiaFrode($numerodedia)] . $naipes[NaipeDiaFrode($numerodedia)];
              }
    else if($numerodedia == 365) $s_dia = $cartas[13];
    else if($numerodedia == 366) $s_dia = $cartas[13];
        	
    $s_semana = $cartas[CartaSemanaFrode($numerodedia)] . $naipes[NaipeSemanaFrode($numerodedia)];
	$s_mes = $cartas[Mes($numerodedia)] . $naipes[EstacaoFrode($dia, $ano)];
	$s_ano = $cartas[CartaAnoFrode($ano)] . $naipes[NaipeAnoFrode($ano)];
	$s_frode = $s_dia . $s_semana . $s_mes . $s_ano;
    return $s_frode; //formato de retorno dia semana mes ano sempre numero/naipe
    }
//RECEBE DATA ORIGINAL
function ImprimeCalendarioFrode($dia, $mes, $ano){ 
	echo "ImprimeCalendarioFrode</br>";

    $cartas = array("de As","de Dois","de Tres","de Quatro","de Cinco",
                          "de Seis","de Sete","de Oito","de Nove","de Dez",
                          "de Valete","de Dama","de Rei","do Curinga");
    $naipes = array(" de ouros"," de paus"," de copas"," de espadas");
    $numerodedia = 0;
    
    $numerodedia = DiaDoAno($dia,$mes,$ano);
    if($numerodedia == -1)return -1;
    
	$numerodedia = CorrigeDiaFrode($numerodedia ,$ano );
		
	echo "\n\tCalendario de Paciencia de Frode" . "</br>";
    echo "\n\t---------------------------------\n" . "</br>";
    
    if($numerodedia < 365){ //imprime dias
              echo "\tDia de " . $cartas[CartaDiaFrode($numerodedia)] 
              . $naipes[NaipeDiaFrode($numerodedia)] . " ";
              }
    else if($numerodedia == 365){ //excecão a regra pelos dias do curinga
                   echo "\tDia " . $cartas[13] . " ";
                   }
    else if($numerodedia == 366) echo "\tDuplo dia " . $cartas[13] . " " ;
        	
    echo "\tSemana de " . $cartas[CartaSemanaFrode($numerodedia)] 
         . $naipes[NaipeSemanaFrode($numerodedia)] . " " ;
	
    echo "\tMes de " . $cartas[Mes($numerodedia)] 
         . " estacao" . $naipes[EstacaoFrode($dia, $ano)] . " " ;
	
    echo "\tAno de " . $cartas[CartaAnoFrode($ano)] 
         . $naipes[NaipeAnoFrode($ano)] . " " ; 
	
	echo "\n\t" . $dia . "/" . $mes . "/" . $ano 
         . " e dia numero " . $numerodedia . " " ;
    }

function CartaDiaFrode($dia){
	return ($dia-=1) % 13; // dia decrementando por causa da natureza da array de char
	}

function NaipeDiaFrode($dia){
	return (($dia-=1) / 13) % 4; // dia decrementando por causa da natureza da array de char
	}

function CartaSemanaFrode($dia){
    return ($dia / 7) % 13;
	}

function NaipeSemanaFrode($dia){
	return (($dia / 7)/ 13) % 4;
	}	

function Mes($dia){ //segue o sistema de mes de 28 dias de frode
    $dia = (($dia-=1) / 28) % 13; // dia decrementando por causa da natureza da array de char
	return $dia;
	}

function EstacaoFrode($dia, $ano){ //DIA NORMAL SEM CONVERSAO
	$biss = 0;                //marcador de ano bissexto
	if(AnoBissexto($ano-1)) $biss = 1;      //ano - 1 se anoterio e bissexto
	if ($dia <= (62-$biss)) return 1;       //Verão 22/12 339 paus 1
    else if ($dia <= (154-$biss)) return 2; //Outono 21/3 63 copas 2
    else if ($dia <= (247-$biss)) return 3; //Inverno 22/6 155 espadas 3
    else if ($dia <= (338-$biss)) return 0; //Primavera 23/9 248 ouros 0
    else if ($dia <= (367-$biss)) return 1; //Verão 22/12 339 paus 1
    }

function CartaAnoFrode($ano){ //ANO NORMAL
		$ano = CorrigeAnoFrode($ano);
		return $ano % 13; 
		}

function NaipeAnoFrode($ano){ //ANO NORMAL
		$ano = CorrigeAnoFrode($ano);
		return ($ano / 13) % 4; 
		}

function CorrigeAnoFrode ($ano){ //ANO NORMAL
         $ano = $ano - 1790; //1970 é o ano que frode chegou na ilha
         return $ano;
         }

function CorrigeDiaFrode($dia, $ano){ //ANO E DIA NORMAIS
			if($dia > 60) $dia = $dia - 60; //frode chegou na ilha no dia 17 de janeiro
			else $dia = $dia + 305;
			if(AnoBissexto($ano-1)) $dia++; //se o ano anterior foi bissexto
			return $dia;
			}
	
function AnoBissexto($ano){ //ANO NORMAL
	if ((!($ano%4))||((!($ano%100))&&(!($ano&400)))) return 1; //eh ano bissexto
	else return 0;
}

function DiaDoAno($dia,$mes,$ano){ //DIA, MES e ANO NORMAIS
    $contador = 0;
    $biss = 0;
    
     if (AnoBissexto($ano)) $biss = 1;

    if ($dia<1){ // Verifica se dia não é negativo
		return -1;
		}
    
    if (($mes<1)||($mes>12)){ // Veifica se mes está correto
		return -1;
		}

    if (($ano<1790)||($ano>9999)){ //Verifica se o ano esta dentro dos padrões
		return -1;
		}

    if (($mes==1)||($mes==3)||($mes==5)||($mes==7)||($mes==8)||($mes==10)||($mes==12)){
               if ($dia>31){
				return -1;
				}
    }

    if (($mes==4)||($mes==6)||($mes==9)||($mes==11)){
               if ($dia>30){
				return -1;
				}
    }

    if ($mes==2){
               if ($biss != 0){

                    if ($dia>29){
						return -1;
						}
               }
               else{
                    if ($dia>28){
						return -1;
						}
               }
    }

    switch ($mes)
    /* Simplismente a cada mes soma-se os dias do mes 
    anterior, mais os dia enviados pelo ''dia'' */
    {
           case 1: //31
                $contador = $dia;
           break;
           case 2: //28
                $contador = 31 + $dia;
           break;
           case 3: //31
                $contador = 59 + $biss + $dia;
           break;
           case 4: //30
                $contador = 90 + $biss + $dia;
           break;
           case 5: //31
                $contador = 120 + $biss + $dia;
           break;
           case 6: //30
                $contador = 151 + $biss + $dia;
           break;
           case 7: //31
                $contador = 181 + $biss + $dia;
           break;
           case 8: //31
                $contador = 212 + $biss + $dia;
           break;
           case 9: //30
                $contador = 243 + $biss + $dia;
           break;
           case 10: //31
                $contador = 273 + $biss + $dia;
           break;
           case 11: //30
                $contador = 304 + $biss + $dia;
           break;
           case 12: //31
                $contador = 334 + $biss + $dia;
           break;
    }
    return ($contador);
}

echo "</body></html>";

?>