package main

import (
	"testing"
)

func Test_ehAnoBissexto(t *testing.T) {
	tests := []struct {
		name string
		ano  int
		want bool
	}{
		{name: "nao eh bissexto", ano: 1997, want: false},
		{name: "eh bissexto", ano: 2012, want: true},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := ehAnoBissexto(tt.ano); got != tt.want {
				t.Errorf("ehAnoBissexto() = %v, want %v", got, tt.want)
			}
		})
	}
}

func Test_intAnoBissexto(t *testing.T) {
	tests := []struct {
		name string
		ano  int
		want int
	}{
		{name: "nao eh bissexto", ano: 1997, want: 0},
		{name: "eh bissexto", ano: 2012, want: 1},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := intAnoBissexto(tt.ano); got != tt.want {
				t.Errorf("intAnoBissexto() = %v, want %v", got, tt.want)
			}
		})
	}
}
