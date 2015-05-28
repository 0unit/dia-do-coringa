#include "DiaDoCuringa.h"

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;

int main(){

	auto dia = 0;
	auto mes = 0;
	auto ano = 0;

	do {
		cout << "\n\tEntre com dia mes e ano (separados por espaco):" << endl;
		cout << "\tDigite -1 para terminar" << endl;
		cout << "\t$>";

		cin >> dia;
		if (dia == -1) return 0;
		cin >> mes >> ano;
		auto ddc = new DiaDoCuringa(dia,mes,ano);
		ddc->ImprimeCalendarioFrode(dia, mes, ano);
		cout << "\n\tSimples -- " << ddc->frodeSimples << endl;
	} while (dia != -1);
	return(0);
}