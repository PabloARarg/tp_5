##Implementacion de una calculadora simple
- Autor: Rivas Pablo
- .gitignore (macOS, windows, linux, visualstudiocode)
- Para crear el archivo ejecutable se ejecuta el comando **make** en la terminal.
- Para para limpiar se ejecuta el comando **make clean** desde terminal.
- Para crear la documentacion se ejecuta el comando **make doc** desde terminal.
	IPORTANTE: Para doxygen 1.9.1
- Para correr el Programa se ejecuta el archivo app.elf en carpeta bin:
	./build/bin/app.elf o escribir **make run** desde terminal.
/////////////////////////////////////////////////////////////////////////////////////////////////////////
-PARA ENRTRAR EN EL MODDO DEBUG VS-Code:
	- Se añade en el parametro -g en el makefile en la linea 46 -> añade banderas de debug como en el makefile de  este proyecto
	- Se configura el .json de lunch cambiando la direccion del archivo de salida con las banderas-> en este caso se llama app.elf
	- Se inicia el modo debug con desde la pestaña->
- Para configurara los define se añade un parametro -D y nombre en el makefile por ejemplo (-DPEPE) fila 46 de este mmakefile