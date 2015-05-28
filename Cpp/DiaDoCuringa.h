/*
Name: Dia do Curinga
  Copyright : GPL v2
		  Author : Jeison Cardoso
			   Date : 11 / 01 / 08 03 : 21 - 21 / 04 / 09 22 : 09
				  Description : Um conversor para o calendario ficticio do livro de Jostein
								Gaarder "O Dia do Curinga".Tendo como base um baralho.

								364 dias representados cada um por uma carta
								52 semanas, uma para cada carta
								13 meses, um para cada numero
								28 dias em cada mes
								O dia 365 é o um dia extra o dia do curinga
								A cada quatro anos a dois dias extras o Duplo dia do curinga

								A contagem dos anos começa em 1790, o dia em 17, e o mes em janeito a data
								em que o personagem chegou na ilha.
								A contagem de semanas e dias começa entçao em 17 / 1 / 1790

								!Năo está no livro é coisa da minha cabeça e leva em conta o hemisfério sul!
								As estaçőes do ano săo marcados por diferentes naipes assim fornecendo os
								naipes dos meses.
								* outono é paus;
*verăo e ouros;
*primavera é copas;
*inverno é espadas;

A primeira semana do ano 1790 é semana de ás de ouros
A ordem dos naipes é ouros->paus->espadas->copas

Ás de espadas dá azar : )
*/

#pragma once
#include <iostream>
#include <string>
#include "DataFrode.h"


using std::cout;
using std::endl;
using std::cin;
using std::string;

class DiaDoCuringa
{
public:
	DiaDoCuringa();
	DiaDoCuringa(int _dia, int _mes, int _ano);
	DiaDoCuringa(DiaDoCuringa &outro);
	~DiaDoCuringa();
	string frodeSimples;
	void ImprimeCalendarioFrode(int dia, int mes, int ano);
private:
	int dia, mes, ano;
	void FrodeSimples(int dia, int mes, int ano);
};

