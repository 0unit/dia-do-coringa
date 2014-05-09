

#include <iostream>
#include <string>
#include "ddcuringa.h"
using std::cin;
using std::string;
using std::cout;
using std::endl;

int main(){

	unsigned int dia, mes, ano = 1;	
    int tmp_dia, tmp_mes, tmp_ano = 0;
    
	//DDCuringa teste(1,1,1790);

do {
	cout << "\n\tEntre com dia mes e ano (separados por espaco):" << endl;
	cout << "\tDigite -1 para terminar"<< endl;
	cout << "\t2 para mudar dia"<< endl;
	cout << "\t3 para mudar o mes"<< endl;
	cout << "\t4 para mudar o ano"<< endl;
	cout << "\t$>";
    
    cin >> tmp_dia;
    
	switch(tmp_dia){
		case -1:
			return 0;
		break;
		case 2:
			cout << "\n\t_";
			cin >> tmp_mes;
			teste.setDia(tmp_mes);
		break;
		case 3:
			cout << "\n\t_";
			cin >> tmp_mes;
			teste.setMes(tmp_mes);
		break;
		case 4:
			cout << "\n\t_";
			cin >> tmp_mes;
			teste.setAno(tmp_mes);
		break;
	}

    cout << "\n\t Data " << teste.getDia() << "/" << teste.getMes() << "/" << teste.getAno() << endl;
	cout << "\t Dia " << teste.getCartaDia() << teste.getNaipeDia() << endl;
	cout << "\t Sem " << teste.getCartaSemana() << teste.getNaipeSemana() << endl;
	cout << "\t Mes "<< teste.getCartaMes() << teste.getNaipeMes() << endl;
	cout << "\t Ano "<< teste.getCartaAno() << teste.getNaipeAno() << endl;

cout << "\n\t" << teste.getDia() << "/" << teste.getMes() << "/" << teste.getAno() << "-" << teste.getNumeroDias() << endl;
    
    } while (tmp_dia != -1);

	return 0;
}
