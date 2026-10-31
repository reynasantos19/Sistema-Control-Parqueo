Sistema de Control de Parqueo - Mundo Encantado

Este proyecto consiste en un sistema para controlar un parqueo de 50 espacios. Fue realizado utilizando C++ y también cuenta con una página web donde se pueden registrar vehículos, consultar los espacios ocupados y disponibles y llevar un control de las entradas y salidas.

Objetivo

Crear un programa que ayude a llevar el control de los vehículos que ingresan y salen del parqueo, evitando que dos vehículos ocupen el mismo espacio.

Funciones del programa en C++

Registrar la entrada de un vehículo.
Asignar un espacio a cada vehículo.
Registrar la salida de un vehículo.
Liberar los espacios cuando un vehículo sale.
Consultar cuáles espacios están libres y ocupados.
Evitar que se registre otro vehículo en un espacio ocupado.
Guardar los datos para recuperarlos al iniciar nuevamente el programa.

Funciones de la página web

Ver un resumen del parqueo.
Registrar entradas y salidas de vehículos.
Calcular el cobro según el tiempo de permanencia.
Consultar los espacios disponibles y ocupados.
Ver el historial de movimientos.
Consultar los ingresos del día y los ingresos acumulados.
Cambiar entre modo día y modo noche.

Tarifa de parqueo

La primera hora tiene un costo de Q5.
Por cada 12 minutos adicionales completos se cobra Q1.

Archivos del proyecto

src/main.cpp: contiene el menú principal.
src/espacios.cpp: se encarga de los espacios del parqueo.
src/entrada.cpp: contiene el registro de entradas.
src/salida.cpp: contiene el registro de salidas.
web/index.html: contiene la estructura de la página.
web/estilos.css: contiene los estilos y colores.
web/script.js: contiene las funciones de la página web.
datos_parqueo.txt: guarda los datos de los vehículos registrados.
respaldo/: contiene copias de los archivos del programa.
pruebas/: carpeta para las pruebas realizadas.

Herramientas utilizadas

C++
HTML
CSS
JavaScript
Visual Studio Code
Git y GitHub

Cómo ejecutar el programa

Primero se debe abrir Git Bash en la carpeta del proyecto y escribir los siguientes comandos:

g++ src/main.cpp src/espacios.cpp src/entrada.cpp src/salida.cpp -o parqueo.exe

./parqueo.exe

Guardado de información

En C++ los datos de los vehículos se guardan en el archivo datos_parqueo.txt.

En la página web se utiliza localStorage, que permite conservar los registros aunque se actualice el navegador.

Autoría

Proyecto realizado de forma individual por Reyna Oralia Santos García para el curso de Algoritmos de Ingeniería en Sistemas.

Repositorio de GitHub

https://github.com/reynasantos19/Sistema-Control-Parqueo