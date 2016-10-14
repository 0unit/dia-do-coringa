
def EhAnoBissexto(ano: Int) : Boolean = {
  (!(ano % 4 == 0) & !(ano % 100 == 0)) & (!(ano % 400 == 0))
}

def CorrigeDiaFrode(dia: Int, ano: Int) : Int = {
  if (dia > 60)  dia - 60
  else dia + 305
}

def CorrigeDiaFrodeVerificaBissexto(dia: Int, ano: Int): Int = {
  if (EhAnoBissexto(ano - 1)) CorrigeDiaFrode(dia, ano) + 1
  CorrigeDiaFrode(dia, ano)
}

def CorrigeAnoFrode(ano: Int) : Int = {
  ano - 1790
}

def NaipeAnoFrode(ano: Int): Int = {
  (CorrigeAnoFrode(ano) / 13) % 4
}

def CartaAnoFrode(ano: Int): Int = {
  CorrigeAnoFrode(ano) % 13
}

def IntAnoBissexto(ano: Int) : Int = {
  if (EhAnoBissexto(ano)) 1
  0
}

def EstacoesFrode(dia: Int, ano: Int) : Int = {
  val biss = IntAnoBissexto(ano - 1)
  if (dia <= (62 - biss)) 1
  else if (dia <= (154 - biss)) 2
  else if (dia <= (247 - biss)) 3
  else if (dia <= (338 - biss)) 0
  else if (dia <= (367 - biss)) 1
  1 //HIRO tá errado
}

def Mes(dia: Int): Int = {
  ((dia - 1) / 28) % 13
}

def NaipeSemanaFrode(dia: Int) : Int = {
  ((dia / 7)/ 13) % 4
}

def CartaSemanaFrode(dia: Int): Int = {
  (dia / 7) % 13
}

def NaipeDiaFrode(dia: Int) : Int ={
  ((dia - 1) / 13) % 4; // dia decrementando por causa da natureza da array de char
}

def CartaDiaFrode(dia: Int): Int = {
  (dia - 1) % 13; // dia decrementando por causa da natureza da array de char
}

def EhDataValida(dia: Int, mes: Int, ano: Int): Boolean = {
  if ((dia < 1) | ((mes < 1)||(mes > 12)) |
    ((ano < 1790)||(ano > 9999)) |
    (((mes == 1)||(mes == 3)||(mes == 5)||(mes == 7)||(mes == 8)||(mes == 10 )||(mes == 12)) & (dia > 31)) |
    (((mes == 4)||(mes == 6)||(mes == 9)||(mes ==11)) & (dia > 30)) |
    (((mes == 2) & !EhAnoBissexto(ano)) && (dia > 29)) | ((mes == 2) & EhAnoBissexto(ano)) && (dia > 28)) false
  else true
}

def DiaDoAno(dia: Int, mes: Int, ano: Int): Int = {
  if (!EhDataValida(dia, mes, ano)) 0
  val biss = IntAnoBissexto(ano)
  def ContaPorMes(m: Int) : Int = m match {
    case 1 => dia
    case 2 => dia + 31
    case 3 => dia + 59 + biss
    case 4 => dia + 90 + biss
    case 5 => dia + 120 + biss
    case 6 => dia + 151 + biss
    case 7 => dia + 181 + biss
    case 8 => dia + 212 + biss
    case 9 => dia + 243 + biss
    case 10 => dia + 273 + biss
    case 11 => dia + 304 + biss
    case 12 => dia + 334 + biss
  }
  ContaPorMes(mes)
}

def FrodeSimples(dia: Int, mes: Int, ano: Int) : String = { //RECEBE DATA ORIGINAL
  val cartas = List("1","2","3","4","5","6","7","8","9","10","J","Q","K","JO")
  val naipes = List("O","P","C","E")
  val numerodedia = CorrigeDiaFrode( DiaDoAno(dia,mes,ano) , ano )

  val s_dia = if(numerodedia < 365) cartas(CartaDiaFrode(numerodedia)) + naipes(NaipeDiaFrode(numerodedia))
              else  cartas(13)
  val s_semana = cartas(CartaSemanaFrode(numerodedia)) + naipes(NaipeSemanaFrode(numerodedia))
  val s_mes = cartas(Mes(numerodedia)) + naipes(EstacoesFrode(dia, ano))
  val s_ano = cartas(CartaAnoFrode(ano)) + naipes(NaipeAnoFrode(ano))
  val s_frode = s_dia + s_semana + s_mes + s_ano
  return s_frode //formato de retorno dia semana mes ano sempre numero/naipe
}

def ImprimeCalendarioFrode(dia: Int, mes: Int, ano: Int) { //RECEBE DATA ORIGINAL
  val cartas = List("de As","de Dois","de Tres","de Quatro","de Cinco",
    "de Seis","de Sete","de Oito","de Nove","de Dez",
    "de Valete","de Dama","de Rei","do Curinga")
  val naipes = List(" de ouros"," de paus"," de copas"," de espadas")

  val numerodedia = CorrigeDiaFrode( DiaDoAno(dia,mes,ano) , ano )

  println("\n\tCalendario de Paciencia de Frode")
  println("\n\t---------------------------------\n")

  if(numerodedia < 365){ //imprime dias
    println("\tDia de " + cartas(CartaDiaFrode(numerodedia)) + naipes(NaipeDiaFrode(numerodedia)))
  }
  else if(numerodedia == 365){ //excecão a regra pelos dias do curinga
    println("\tDia " + cartas(13))
  }
  else if(numerodedia == 366) {
    println("\tDuplo dia " + cartas(13))
  }

  println("\tSemana de " + cartas(CartaSemanaFrode(numerodedia)) + naipes(NaipeSemanaFrode(numerodedia)))
  println("\tMes de " + cartas(Mes(numerodedia)) + " estacao" + naipes(EstacoesFrode(dia, ano)))
  println("\tAno de " + cartas(CartaAnoFrode(ano)) + naipes(NaipeAnoFrode(ano)))
  println("\n\t" + dia + "/" + mes + "/" + ano + " e dia numero " + numerodedia)
}

import scala.io._

object InputMain {
  var dia, mes, ano = 0
  var numerodedia = 0
  var tmp_dia, tmp_mes, tmp_ano = 0
  println("Entre com dia mes e ano (separados por enter) e precione ctrl-c")
  println("\n\tEntre com dia mes e ano (separados por espaco):")


  val input = Source.fromInputStream(System.in)
  val lines = input.getLines.toList

  ImprimeCalendarioFrode(lines(1).toInt,lines(2).toInt,lines(3).toInt);
  println("\n\tSimples -- " + FrodeSimples(dia,mes,ano));
}