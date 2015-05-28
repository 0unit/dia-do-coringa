#pragma once
class DataGregoriana
{
public:
	unsigned int dia;
	unsigned int mes;
	unsigned int ano;
	bool bix;

	DataGregoriana()
	{
		dia = 0;
		mes = 0;
		ano = 0;
		bix = 0;
	}
	//recebe os valores da data do clendario gregoriano
	DataGregoriana(unsigned int _dia, unsigned int  _mes, unsigned int _ano){
		dia = _dia;
		mes = _mes;
		ano = _ano;
		bix = ((!(_ano % 4)) || ((!(_ano % 100)) && (!(_ano & 400)))) ? true : false;
	}

	DataGregoriana(const DataGregoriana& outro)
	{
		dia = outro.dia;
		mes = outro.mes;
		ano = outro.ano;
		bix = outro.bix;
	}
	~DataGregoriana()
	{

	}
};

