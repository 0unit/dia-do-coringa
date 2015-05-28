#include "DiaDoCuringa.h"

DiaDoCuringa::DiaDoCuringa()
{
	DiaDoCuringa::DiaDoCuringa(1, 3, 1790);
}

DiaDoCuringa::DiaDoCuringa(int _dia, int _mes, int _ano)
{
	dia = _dia;
	mes = _mes;
	ano = _ano;
	DiaDoCuringa::FrodeSimples(dia, mes, ano);
}

DiaDoCuringa::DiaDoCuringa(DiaDoCuringa &outro)
{
	dia = outro.dia;
	mes = outro.mes;
	ano = outro.ano;
	DiaDoCuringa::FrodeSimples(outro.dia, outro.mes, outro.ano);
}


DiaDoCuringa::~DiaDoCuringa()
{
}

void DiaDoCuringa::FrodeSimples(int dia, int mes, int ano){ //RECEBE DATA ORIGINAL
	const auto frode = new DataFrode(dia, mes, ano);
	const string cartas[14] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "JO" };
	const string naipes[4] = { "O", "P", "C", "E" };
	string s_frode;

	if (frode->numeroDias < 365){ //imprime dias
		s_frode = cartas[frode->diaNumero] + naipes[frode->diaNaipe];
	}
	else if (frode->numeroDias == 365) s_frode = cartas[13];
	else if (frode->numeroDias == 366) s_frode = cartas[13];

	s_frode += cartas[frode->semanaNumero] + naipes[frode->semanaNaipe];
	s_frode += cartas[frode->mesNumero] + naipes[frode->estacaoNaipe];
	s_frode += cartas[frode->anoNumero] + naipes[frode->anoNaipe];
	frodeSimples = s_frode;
	delete(frode);
}

void DiaDoCuringa::ImprimeCalendarioFrode(int dia, int mes, int ano){ //RECEBE DATA ORIGINAL
	const auto frode = new DataFrode(dia, mes, ano);
	string cartas[14] = { "de As", "de Dois", "de Tres", "de Quatro", "de Cinco"
						  ,"de Seis", "de Sete", "de Oito", "de Nove", "de Dez"
						  ,"de Valete", "de Dama", "de Rei", "do Curinga" };
	string naipes[4] = { " de ouros", " de paus", " de copas", " de espadas" };
	cout << "\n\tCalendario de Paciencia de Frode";
	cout << "\n\t---------------------------------\n" << endl;
	if (frode->numeroDias < 365){ //imprime dias
		cout << "\tDia de " << cartas[ frode->diaNumero ] << naipes[ frode->diaNaipe ] << endl;
	}
	else if (frode->numeroDias == 365){ //excecăo a regra pelos dias do curinga
		cout << "\tDia " << cartas[13] << endl;
	}
	else if (frode->numeroDias == 366){
		cout << "\tDuplo dia " << cartas[13] << endl;
	}
	cout << "\tSemana de " << cartas[ frode->semanaNumero ] << naipes[ frode->semanaNaipe ] << endl;
	cout << "\tMes de " << cartas[frode->mesNumero ] << " estacao" << naipes[ frode->estacaoNaipe ] << endl;
	cout << "\tAno de " << cartas[ frode->anoNumero ] << naipes[ frode->anoNaipe ] << endl;
	cout << "\n\t" << dia << "/" << mes << "/" << ano << " e dia numero " << frode->numeroDias << endl;
	delete(frode);
}