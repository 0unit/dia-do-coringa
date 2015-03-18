<?php
//($ddia,$mmes,$aano)
// Trocar no http://**********************SITE****************************/gerador_rss.php
// pelo endereco correto do site
define('LINKSITE',"http://**********************SITE****************************/gerador_rss.php");

//recebendo o dia
$ddia = date('j');
$mmes = date('n');
$aano = date('Y');

//RECEBE DATA ORIGINAL
function FrodeSimples($dia,$mes,$ano){ 
    $cartas = array("1","2","3","4","5","6","7","8","9","10","J","Q","K","JO");
    $naipes = array("O","P","C","E");
    
    $numerodedia = DiaDoAno($dia,$mes,$ano);
    if($numerodedia == -1){
	return "00000000";
    } else {
    	$numerodedia = CorrigeDiaFrode($numerodedia , $ano );
    }   
    if($numerodedia < 365){ //imprime dias
              $s_dia = $cartas[(($numerodedia-=1) % 13)] . $naipes[((($numerodedia-=1) / 13) % 4)];
    }
    else if($numerodedia >= 365){
	$s_dia = $cartas[13];
    }
	$s_semana = $cartas[(($numerodedia / 7) % 13)] . $naipes[((($numerodedia / 7)/ 13) % 4)];
	$s_mes = $cartas[((($numerodedia-=1) / 28) % 13)] . $naipes[EstacaoFrode($dia, $ano)];
	$s_ano = $cartas[(($ano - 1790) % 13)] . $naipes[((($ano - 1790) / 13) % 4)];
	//formato de retorno dia semana mes ano sempre numero/naipe
	return $s_dia . $s_semana . $s_mes . $s_ano; 
    }

//RECEBE DATA ORIGINAL
function ImprimeCalendarioFrode($dia, $mes, $ano){ 
    $cartas = array("as","dois","tres","quatro","cinco", "seis","sete","oito","nove","dez", "Valete","Dama","Rei","do Curinga");
    $naipes = array(" de ouros"," de paus"," de copas"," de espadas");
  
    $numerodedia = DiaDoAno($dia,$mes,$ano);
    if($numerodedia == -1){ return -1; }
    $numerodedia = CorrigeDiaFrode($numerodedia ,$ano );	
    if($numerodedia < 365){ //imprime dias
             	$final = "Dia " . $cartas[(($numerodedia-=1) % 13)] . $naipes[((($numerodedia-=1) / 13) % 4)] . " ";
             }
    else if($numerodedia == 365){ 
		$final = "Dia " . $cartas[13] . " ";
             }
    else if($numerodedia == 366){
		$final = "Duplo dia " . $cartas[13] . " " ;
	     }
    $final .= ", Semana " . $cartas[(($numerodedia / 7) % 13)] . $naipes[((($numerodedia / 7)/ 13) % 4)] . " " ;
    $final .= ", Mes " . $cartas[((($numerodedia-=1) / 28) % 13)]  . " na estacao" . $naipes[EstacaoFrode($dia, $ano)] . " " ;
    $final .= ", Ano " . $cartas[(($ano - 1790) % 13)] . $naipes[((($ano - 1790) / 13) % 4)] . " " ; 
    $final .=  " e dia numero " . $numerodedia . " - ";
    return $final;
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
    
     if (AnoBissexto($ano)){ $biss = 1; }
     if ($dia<1){ return -1; }
     if (($mes<1)||($mes>12)){ return -1; }
     if (($ano<1790)||($ano>9999)){ return -1; }
     if (($mes==1)||($mes==3)||($mes==5)||($mes==7)||($mes==8)||($mes==10)||($mes==12)){ 
        if ($dia>31){ return -1; }
     }
     if (($mes==4)||($mes==6)||($mes==9)||($mes==11)){
        if ($dia>30){ return -1; }
     }

     if ($mes==2){
       if ($biss != 0){
            if ($dia>29){
		return -1;
	    }
       } else {
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



// Intanciamos/chamamos a classe
$rss = new SimpleXMLElement('<?xml version="1.0" encoding="UTF-8"?><rss></rss>');
$rss->addAttribute('version', '2.0');

// Cria o elemento <channel> dentro de <rss>
$canal = $rss->addChild('channel');
// Adiciona sub-elementos ao elemento <channel>
$canal->addChild('title','Calendario do Curinga');
$canal->addChild('link', 'http://localhost/pcd/rss.xml');
$canal->addChild('description', 'Calendario de Frode');

// Cria um elemento <item> dentro de <channel>
$item = $canal->addChild('item');
// Adiciona sub-elementos ao elemento <item>
$item->addChild('title',ImprimeCalendarioFrode($ddia,$mmes,$aano) . FrodeSimples($ddia,$mmes,$aano));
$item->addChild('link', LINKSITE);
$item->addChild('description',ImprimeCalendarioFrode($ddia,$mmes,$aano) . FrodeSimples($ddia,$mmes,$aano));
//Sat, 07 Sep 2002 00:00:01 GMT
$autodia = date('Y') . date ('M') . date('d');
$item->addChild('guid', LINKSITE  . $autodia);
$item->addChild('pubDate', date('r'));

// Entrega o conteúdo do RSS completo:
echo $rss->asXML();
exit;

?>
