#pragma once

class DataFrode
{
public:
	int diaNumero;
	int semanaNumero;
	int mesNumero;
	int anoNumero;
	int bix;
	int antes_bix;
	int numeroDias;
	int diaNaipe;
	int semanaNaipe;
	int estacaoNaipe;
	int anoNaipe;

	DataFrode()
	{
		DataFrode::DataFrode(1,3,1790);
	}

	DataFrode(int _dia, int _mes, int _ano)
	{
		bix = ((!(_ano % 4)) || ((!(_ano % 100)) && (!(_ano & 400)))) ? 1 : 0;
		antes_bix = ((!((_ano - 1) % 4)) || ((!((_ano - 1) % 100)) && (!((_ano - 1) & 400)))) ? 1 : 0;
		numeroDias = diaDoAno(_dia, _mes, _ano);
		diaNumero = (numeroDias - 1) % 13; //TODO: verificar a necessidade de usar numeroDias - 1 (antes erapor causa de um array de char)
		diaNaipe = ((numeroDias - 1) / 13) % 4;
		semanaNumero = (numeroDias / 7) % 13;
		semanaNaipe = ((numeroDias / 7) / 13) % 4;
		mesNumero = ((numeroDias - 1) / 28) % 13;
		estacaoNaipe = qualEstacaoNaipe(numeroDias);
		anoNumero = (_ano - 1790) % 13;
		anoNaipe = ((_ano - 1790) / 13) % 4;
	}

	DataFrode(DataFrode &outro){
		diaNumero = outro.diaNumero;
		semanaNumero = outro.semanaNumero;
		mesNumero = outro.mesNumero;
		anoNumero = outro.anoNumero;
		bix = outro.bix;
		antes_bix= outro.antes_bix;
		numeroDias = outro.numeroDias;
		diaNaipe = outro.diaNaipe;
		outro.semanaNaipe = outro.semanaNaipe;
		estacaoNaipe = outro.estacaoNaipe;
		anoNaipe = anoNaipe = outro.anoNaipe;
	}

	~DataFrode()
	{

	}
protected:
	int DataFrode::qualEstacaoNaipe(int dia){
		if (dia <= (62 - antes_bix)) return 1; //Verăo 22/12 339 paus 1
		else if (dia <= (154 - bix)) return 2; //Outono 21/3 63 copas 2
		else if (dia <= (247 - bix)) return 3; //Inverno 22/6 155 espadas 3
		else if (dia <= (338 - bix)) return 0; //Primavera 23/9 248 ouros 0
		else if (dia <= (367 - bix)) return 1; //Verăo 22/12 339 paus 1
	}

	int DataFrode::diaDoAno(int dia, int mes, int ano){
		int contador = 0;
		if ((mes<1) || (mes>12)){ 
			return -1;
		}
		if ((ano<1790) || (ano>9999)){
			return -1;
		}
		if ((mes == 1) || (mes == 3) || (mes == 5) || (mes == 7) || (mes == 8) || (mes == 10) || (mes == 12)){
			if (dia>31){
				return -1;
			}
		}
		if ((mes == 4) || (mes == 6) || (mes == 9) || (mes == 11)){
			if (dia>30){
				return -1;
			}
		}
		if (mes == 2){
			if (bix){
				if (dia>29){
					return -1;
				}
			}
			else{
				if (dia>28){
					return -1;
				}
			}
		}
		switch (mes){
		case 1: //31
			contador = dia;
			break;
		case 2: //28
			contador = 31 + dia;
			break;
		case 3: //31
			contador = 59 + bix + dia;
			break;
		case 4: //30
			contador = 90 + bix + dia;
			break;
		case 5: //31
			contador = 120 + bix + dia;
			break;
		case 6: //30
			contador = 151 + bix + dia;
			break;
		case 7: //31
			contador = 181 + bix + dia;
			break;
		case 8: //31
			contador = 212 + bix + dia;
			break;
		case 9: //30
			contador = 243 + bix + dia;
			break;
		case 10: //31
			contador = 273 + bix + dia;
			break;
		case 11: //30
			contador = 304 + bix + dia;
			break;
		case 12: //31
			contador = 334 + bix + dia;
			break;
		}
		contador = (contador > 60)? contador - 60 : contador + 305;
		if (antes_bix) contador++; //se ano anteriro for bix
		return contador;
	}
};

