#version 330 core
//Primera linea SIEMPRE es la version
//Objetivo: establecer valores de atributos de salida

//Atributos de entrada (Desde el vertex shader)
in vec4 fragmentColor;

//Atributos de salida
//Primero define la version de visualizacion del fragmento
out vec4 salidaColor;

void main() {
	salidaColor = fragmentColor;
}