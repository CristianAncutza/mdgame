# Sega game project

para proyectos de cero

instalar gdk + genesis plugin de vs code


--CODIGO--

ejecutar ctrl+p (me costo un huevo hacer que esos comandos funcionen)

task clean
task run

para proyectos avanzados en vscode el comando compile & run no
funciona, hay que copiarlo a un cmd externo para que funcione

%GDK%\bin\make -f %GDK%\makefile.gen release && START /B gens %CD%/out/rom.bin

el rom lo genera en carpeta out


para el error _HINT borrar carpeta boot

para agregar recursos se ponen en resources.res dentro de la carpeta res y se compila el proyecto con ctrl+shift+p

---MUSICA Y SONIDO---


para convertir vgm a xgm

carpeta bin de sgdk xgmtool test.vgm test.xgm

--para poner sonido en el codigo--

XGM soundtrack "xgm/x-men.xgm"

XGM_setLoopNumber(0);
SND_startPlay_XGM(soundtrack);


---GAME PROJECTS---

juego aventura  
1 personaje
4 enemigos comunes + 1 jefe
3 canciones
10 efectos de sonido
una intro



