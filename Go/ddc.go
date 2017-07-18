package main

import (
	"bufio"
	"os"
	"fmt"
	"strconv"
	"strings"
)

func EhAnoBissexto(ano int) bool {
	return (!(ano%4 == 0) && !(ano%100 == 0)) && (!(ano%400 == 0))
}

func CorrigeDiaFrode(dia int, ano int) int {
	if dia > 60 {
		return dia - 60
	}
	return dia + 305
}

func CorrigeDiaFrodeVerificaBissexto(dia int, ano int) int {
	if (EhAnoBissexto(ano - 1)) {
		return CorrigeDiaFrode(dia, ano) + 1
	}
	return CorrigeDiaFrode(dia, ano)
}

func CorrigeAnoFrode(ano int) int {
	return ano - 1790
}

func NaipeAnoFrode(ano int) int {
	return (CorrigeAnoFrode(ano) / 13) % 4
}

func CartaAnoFrode(ano int) int {
	return CorrigeAnoFrode(ano) % 13
}

func IntAnoBissexto(ano int) int {
	if (EhAnoBissexto(ano)) {
		return 1
	}
	return 0
}

func EstacoesFrode(dia int, ano int) int {
	biss := IntAnoBissexto(ano - 1)
	if (dia <= (62 - biss)) {
		return 1
	}
	if (dia <= (154 - biss)) {
		return 2
	}
	if (dia <= (247 - biss)) {
		return 3
	}
	if (dia <= (338 - biss)) {
		return 0
	}
	if (dia <= (367 - biss)) {
		return 1
	}
	return 1 //HIRO tá errado
}

func Mes(dia int) int {
	return ((dia - 1) / 28) % 13
}

func NaipeSemanaFrode(dia int) int {
	return ((dia / 7) / 13) % 4
}

func CartaSemanaFrode(dia int) int {
	return (dia / 7) % 13
}

func NaipeDiaFrode(dia int) int {
	return ((dia - 1) / 13) % 4 // dia decrementando por causa da natureza da array de char
}

func CartaDiaFrode(dia int) int {
	return (dia - 1) % 13 // dia decrementando por causa da natureza da array de char
}

func EhDataValida(dia int, mes int, ano int) bool {
	return !((dia < 1) ||
		((mes < 1) || (mes > 12)) ||
		((ano < 1790) || (ano > 9999)) ||
		(((mes == 1) || (mes == 3) || (mes == 5) || (mes == 7) || (mes == 8) || (mes == 10 ) || (mes == 12)) && (dia > 31)) ||
		(((mes == 4) || (mes == 6) || (mes == 9) || (mes == 11)) && (dia > 30)) ||
		(((mes == 2) && !EhAnoBissexto(ano)) && (dia > 29)) || ((mes == 2) && EhAnoBissexto(ano)) && (dia > 28))
}

func DiaDoAno(dia int, mes int, ano int) int {
	if !EhDataValida(dia, mes, ano) {
		return 0
	}
	return ContaPorMes(dia, mes, ano)
}

func ContaPorMes(dia int, mes int, ano int) int {
	biss := IntAnoBissexto(ano)
	switch mes {
	case 1:
		return dia
	case 2:
		return dia + 31
	case 3:
		return dia + 59 + biss
	case 4:
		return dia + 90 + biss
	case 5:
		return dia + 120 + biss
	case 6:
		return dia + 151 + biss
	case 7:
		return dia + 181 + biss
	case 8:
		return dia + 212 + biss
	case 9:
		return dia + 243 + biss
	case 10:
		return dia + 273 + biss
	case 11:
		return dia + 304 + biss
	case 12:
		return dia + 334 + biss
	}
	return 0
}

func FrodeSimples(dia int, mes int, ano int) string { //RECEBE DATA ORIGINAL
	cartas := [...]string{"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "JO"}
	naipes := [...]string{"O", "P", "C", "E"}
	numerodedia := CorrigeDiaFrode(DiaDoAno(dia, mes, ano), ano)

	var s_dia = ""
	if (numerodedia < 365) {
		s_dia = cartas[CartaDiaFrode(numerodedia)] + naipes[NaipeDiaFrode(numerodedia)]
	}
	s_dia = cartas[13]

	s_semana := cartas[CartaSemanaFrode(numerodedia)] + naipes[NaipeSemanaFrode(numerodedia)]
	s_mes := cartas[Mes(numerodedia)] + naipes[EstacoesFrode(dia, ano)]

	s_ano := cartas[CartaAnoFrode(ano)] + naipes[NaipeAnoFrode(ano)]
	s_frode := s_dia + s_semana + s_mes + s_ano

	return s_frode //formato de retorno dia semana mes ano sempre numero/naipe
}

func ImprimeCalendarioFrode(dia int, mes int, ano int) { //RECEBE DATA ORIGINAL
	cartas := [...]string{"de As", "de Dois", "de Tres", "de Quatro", "de Cinco",
						  "de Seis", "de Sete", "de Oito", "de Nove", "de Dez",
						  "de Valete", "de Dama", "de Rei", "do Curinga"}
	naipes := [...]string{" de ouros", " de paus", " de copas", " de espadas"}

	numerodedia := CorrigeDiaFrode(DiaDoAno(dia, mes, ano), ano)

	fmt.Println("\n\tCalendario de Paciencia de Frode")
	fmt.Println("\n\t---------------------------------\n")

	if (numerodedia < 365) { //imprime dias
		fmt.Println("\tDia de " + cartas[CartaDiaFrode(numerodedia)] + naipes[NaipeDiaFrode(numerodedia)])
	}
	if (numerodedia == 365) { //excecão a regra pelos dias do curinga
		fmt.Println("\tDia " + cartas[13])
	}
	if (numerodedia == 366) {
		fmt.Println("\tDuplo dia " + cartas[13])
	}

	fmt.Println("\tSemana de " + cartas[CartaSemanaFrode(numerodedia)] + naipes[NaipeSemanaFrode(numerodedia)])
	fmt.Println("\tMes de " + cartas[Mes(numerodedia)] + " estacao" + naipes[EstacoesFrode(dia, ano)])
	fmt.Println("\tAno de " + cartas[CartaAnoFrode(ano)] + naipes[NaipeAnoFrode(ano)])
	fmt.Println("\n\t" + strconv.Itoa(dia) + "/" + strconv.Itoa(mes) + "/" + strconv.Itoa(ano) + " e dia numero " + strconv.Itoa(numerodedia))
}

func main() {
	fmt.Println("Entre com dia mes e ano (separados por enter) e precione ctrl-c")
	fmt.Println("\n\tEntre com dia mes e ano (separados por espaco):")
	reader := bufio.NewReader(os.Stdin)
	text, _ := reader.ReadString('\n')
	fmt.Println(text)
	newText := strings.Replace(text, "\n", " ", -1)
	args := strings.Split(newText, " ")
	dia, _ := strconv.Atoi(args[0])
	mes, _ := strconv.Atoi(args[1])
	ano, _ := strconv.Atoi(args[2])
	ImprimeCalendarioFrode(dia, mes, ano);
	fmt.Println("\n\tSimples -- " + FrodeSimples(dia, mes, ano));
}
