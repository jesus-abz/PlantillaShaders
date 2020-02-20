// PlantillaGraficos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <stdio.h>
#include <stdlib.h>

#define GLEW_STATIC

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <iostream>

using namespace std;

void dibujarPoligono() {
    glBegin(GL_POLYGON);

    glColor3f(0.4f, 0.4f, 0.9f);

    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.5f, 0.0f);
    glVertex3f(0.2f, 0.3f, 0.0f);
    glVertex3f(0.2f, -0.4f, 0.0f);
    glVertex3f(0.7f, -0.6f, 0.0f);

    glEnd();
}

void dibujarTrianguloContinuo() {
    glBegin(GL_TRIANGLE_STRIP);

    glColor3f(1.0f, 0.4f, 0.0f);

    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.1f, 0.1f, 0.0f);
    glVertex3f(0.2f, 0.0f, 0.0f);
    
    glColor3f(0.5f, 0.3f, 1.0f);

    glVertex3f(0.2f, 0.15f, 0.0f);

    glEnd();
}

void dibujarLineaContinua() {
    glBegin(GL_LINE_STRIP);

    glColor3f(0.1f, 0.3f, 0.75f);

    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.2f, 0.0f);
    glVertex3f(0.4f, 0.2f, 0.0f);
    glVertex3f(0.2f, 0.3f, 0.0f);

    glEnd();
}

void dibujarLineas() {
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.4f, 0.6f);

    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.2f, -0.4f, 0.0f);

    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.2f, 0.4f, 0.0f);

    glEnd();
}

void dibujarTriangulos() {
    //establecemos el tipo de primitiva

    glBegin(GL_TRIANGLES);

    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-0.9f, 0.9f, 0.0f);
    glVertex3f(-0.9f, -0.9f, 0.0f);
    glVertex3f(0.9f, 0.9f, 0.0f);

    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.9f, -0.9f, 0.0f);
    glVertex3f(-0.9f, -0.9f, 0.0f);
    glVertex3f(0.9f, 0.9f, 0.0f);

    //establecemos el color
    /*glColor3f(1.0f, 0.0f, 0.0f);
    //enviar vertices
    glVertex3f(0.0f, 0.8f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -0.5f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.3f, -0.9f, 0.0f);*/

    //especificar que dejamos de dibujar
    glEnd();
}

void dibujar() {
    dibujarPoligono();
}

int main()
{
    //declarar una ventana
    GLFWwindow* window;

    //si no se pudo iniciar GLFW terminamos ejecucion
    if (!glfwInit()){
        exit(EXIT_FAILURE);
    }
    //si se pudo iniciar GLFW iniciamos la ventana
    window = glfwCreateWindow(600, 600, "Ventana", NULL, NULL);

    //si no se pudo crear la ventana, terminamos la ejecucion
    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    //establecemos la ventana como contexto
    glfwMakeContextCurrent(window);

    //una vez establecido el contexto se activan las funciiones moderna (gpu)
    glewExperimental = true;

    GLenum errores = glewInit();
    if (errores != GLEW_OK) {
        glewGetErrorString(errores);
    }

    const GLubyte* versionGL = glGetString(GL_VERSION);
    cout << "Version OpenGL: " << versionGL;

    //ciclo de dibujo (Draw Loop)
    while (!glfwWindowShouldClose(window)) {
        //establecer region de dibujo
        glViewport(0, 0, 600, 600);
        //establecemos el color de borrado
        //valores RGBA
        glClearColor(1, 0.8, 0, 1);
        //borrar!
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //actualizar valores y dibujar
        dibujar();

        glfwPollEvents();

        glfwSwapBuffers(window);
    }
    //despues del ciclo de dibujo eliminemos la venta y procesos de glfw
    glfwDestroyWindow(window);
    glfwTerminate();
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
