/*
Nome: Classe Dia do Curinga
Autor: Jeison Cardoso
Copyright: GPL v2
*/

#ifndef DDCURINGA_H
#define DDCURINGA_H

class DDCuringa {
	public:
			DDCuringa(unsigned int = 1, unsigned int = 3, unsigned int = 1789);
			unsigned int getDia();
			unsigned int getNaipeDia();
			unsigned int getCartaDia();
			unsigned int getMes();
			unsigned int getNaipeMes();
			unsigned int getCartaMes();
			unsigned int getAno();
			unsigned int getNaipeAno();
			unsigned int getCartaAno();
			unsigned int getNaipeSemana();
			unsigned int getCartaSemana();
			unsigned int getNumeroDias();
			void setAno(unsigned int);
			void setMes(unsigned int);
			void setDia(unsigned int);
	private:
			unsigned int numdia;
			unsigned int ddia;
			unsigned int dmes;
			unsigned int dano;
			unsigned int cdia;
			unsigned int ndia;
			unsigned int csemana;
			unsigned int nsemana;
			unsigned int cmes;
			unsigned int nmes;
			unsigned int cano;
			unsigned int nano;
			void setNumeroDias(unsigned int, unsigned int, unsigned int);
			bool eBissexto(unsigned int);
			unsigned int rotacionaData(unsigned int, unsigned int);
			unsigned int rotacionaAno(unsigned int);
			void naipeAno(unsigned int);
			void cartaAno(unsigned int);
			void naipeMes(unsigned int, unsigned int);
			void cartaMes(unsigned int);
			void naipeSemana(unsigned int);
			void cartaSemana(unsigned int);
			void naipeDia(unsigned int);
			void cartaDia(unsigned int);
	};

#endif
