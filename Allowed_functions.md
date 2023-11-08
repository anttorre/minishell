<!-- **************************************************************************** -->
<!--                                                                              -->
<!--                                                         :::      ::::::::    -->
<!--    Funciones.txt                                      :+:      :+:    :+:    -->
<!--                                                     +:+ +:+         +:+      -->
<!--    By: anttorre <atormora@gmail.com>              +#+  +:+       +#+         -->
<!--                                                 +#+#+#+#+#+   +#+            -->
<!--    Created: 2023/10/19 14:57:19 by anttorre          #+#    #+#              -->
<!--    Updated: 2023/10/19 14:58:04 by anttorre         ###   ########.fr        -->
<!--                                                                              -->
<!-- **************************************************************************** -->

##READLINE

**Prototipo:** *readline (const char * prompt);*
**Definición:** lee una linea de la terminal y la devuelve usando el parametro como mensaje. Si es NULL o vacio no se emite el mensaje y la linea devuelta reserva un malloc(3); se debe liberar cuando se termina. La linea retornada no tiene el salto de linea al final.

##RL_CLEAR_HISTORY

**Prototipo:** *void rl_clear_history (void)*
**Definición:** Limpia el historico eliminando todas las entradas de la misma manera que clear_history() de la libreria History, difiere de esta por que libera datos privados que readline guarda en la lista del historial.

##RL_ON_NEW_LINE

**Prototipo:** *int rl_on_new_line (void)*
**Definición:** Indica a las funciones de actualización que hemos pasado a una nueva línea (vacía), normalmente después de mostrar una nueva línea.

##RL_REPLACE_LINE

**Prototipo:** *void rl_replace_line (const char * text, int clear_undo)*
**Definición:** reemplaza el contenido de rl_line_buffer con texto si clear_undo no es cero, la lista de deshacer asociada de la linea actual se borra.

##RL_REDISPLAY

**Prototipo:** *void rl_redisplay(void)*
**Definición:** cambia lo que hay puesto en pantalla para reflejar el contenido actual de rl_line_buffer

##ADD_HISTORY

**Prototipo:** *void add_history(const char * line)*
**Definición:** añade al historico la linea que se ha leido con readline

##WAITPID

**Prototipo:** *pid_t waitpid(pid_t pid, int * _Nullable wstatus, int options)*
**Definición:** llamada al sistema que suspende la ejecucion de la llamada al proceso hasta que un proceso hijo especificado en el argumento pid cambia su estado

	El valor del pid puede ser:ioctl, getenv, tcsetattr,
tcgetattr, tgetent, tgetflag, tgetnum, tgetstr,
tgoto, tputs
    1) < -1   espera por procesos hijos cuyo ID group es igual al valor absoluto del pid.
   	2) -1     espera por cualquier proceso hijo.
    3) 0      espera por cualquier proceso hijo cuyo ID de grupo de procesos sea igual al del proceso que hace la llamada en ese momento.
    4) > 0    meaning wait for the child whose process ID is equal to the value of pid.

	Los valores van seguido de un OR con estas constantes:
	1) WNOHANG
	retorna inmediatamente si ningun hijo ha hecho exit.
	2) WUNTRACED
  	también devuelve si un hijo se ha detenido (pero no ha sido rastreado mediante ptrace(2)).  El estado de los hijos rastreados que se han detenido se proporciona incluso si no se especifica esta opción.
    3) WCONTINUED
	también devuelve si un hijo detenido ha sido reanudado por la entrega de SIGCONT.

#####EQUIVALENCIAS
	WAIT
	waitpid (-1, &wstatus, 0);
	WAIT3
	waitpid(-1, status, options);
	WAIT4
	waitpid(pid, status, options);


##SIGNAL

**Prototipo:** *sighandler_t signal(int signum, sighandler_t handler);*
**Definición:** manda señales a los procesos

##SIGACTION

**Prototipo:** *int sigaction(int signum, const struct sigaction *_Nullable restrict act, struct sigaction *_Nullable restrict oldact);*
**Definición:** Examina y cambia una señal

##KILL

**Prototipo:** *int kill(pid_t pid, int sig)*
**Definición:** envia una señal a un proceso

##GETCWD

**Prototipo:** *char *getcwd(char buf[.size], size_t size)*
**Definición:** coge el directorio de trabajo actual

##CHDIR

**Prototipo:** *int chdir(const char *path)*
**Definición:** cambia el directorio actual de trabajo a un directorio especificado en el path.

##STAT

**Prototipo:** *int stat(const char *path, struct stat *buf)*
**Definición:** La función  stat  se utiliza para obtener información sobre un archivo especificado por su ruta. Proporciona detalles como el tamaño del archivo, los permisos, la última fecha de acceso y modificación, entre otros.

##LSTAT

**Prototipo:** *int lstat(const char *path, struct stat *buf)*
**Definición:**  La función  lstat  es similar a  stat , pero se utiliza para obtener información sobre un enlace simbólico en lugar del archivo al que apunta. Esto significa que  lstat  devuelve información sobre el enlace simbólico en sí, en lugar de seguir el enlace y obtener información sobre el archivo al que apunta.


##FSTAT
**Prototipo:** *int fstat(int fd, struct stat *buf)*
**Definición:** La función  fstat  se utiliza para obtener información sobre un archivo abierto identificado por su descriptor de archivo. A diferencia de  stat  y  lstat , que toman una ruta de archivo como argumento,  fstat  toma un descriptor de archivo como argumento y proporciona información sobre el archivo asociado a ese descriptor.

##OPENDIR

**Prototipo:** *DIR *opendir(const char *name)*
**Definición:** Para abrir un directorio y obtener un puntero a él. Esta función permite al programador acceder a los archivos y subdirectorios contenidos en ese directorio específico. Una vez abierto el directorio, se pueden utilizar otras funciones como readdir para leer los contenidos del directorio y obtener información sobre los archivos y subdirectorios dentro de él.

##READDIR
**Prototipo:** *struct dirent *readdir(DIR *directorio)*
**Definición:** Recibe como argumento un puntero al directorio abierto (obtenido previamente con opendir) y devuelve un puntero a una estructura dirent que contiene información sobre la entrada leída.

	struct dirent {
    	ino_t d_ino;         // número de inodo del archivo
    	off_t d_off;         // desplazamiento a la siguiente entrada
   		unsigned short d_reclen; // longitud de esta entrada
    	unsigned char d_type;    // tipo de archivo
    	char d_name[256];    // nombre del archivo
};

##CLOSEDIR

**Prototipo:** *int closedir(DIR *dir)*
**Definición:** Cierra el directorio que se le pasa por parametro devuelve un entero. 

##ISATTY

**Prototipo:** *int isatty(int fd)*
**Definición:** Para determinar si un descriptor de archivo está asociado con un terminal interactivo. Retorna un valor distinto de cero si el descriptor de archivo es un terminal, y retorna 0 si no lo es. Esta función es útil para realizar acciones específicas dependiendo de si la entrada o salida estándar está redirigida a un archivo o si se está interactuando directamente con un terminal.

##TTYNAME

**Prototipo:** *char *ttyname(int fd)*
**Definición:** Para obtener el nombre del terminal asociado con un descriptor de archivo específico. Recibe como argumento el descriptor de archivo  fd  y devuelve un puntero a una cadena de caracteres que representa el nombre del terminal. Si el descriptor de archivo no está asociado con un terminal, la función devuelve NULL. 

##TTYSLOT

**Prototipo:** *int ttyslot(void)*
**Definición:** La función ttyslot devuelve un entero que representa el número de la ranura del terminal asociado al proceso. Este número se utiliza para identificar el terminal en el sistema. 

##IOCTL
**Prototipo:** *int ioctl(int fd, unsigned long request, ...)*
**Definición:** La función ioctl se utiliza para controlar y manipular dispositivos y archivos especiales en sistemas UNIX. Permite enviar comandos y recibir información específica del dispositivo o archivo asociado.

##GETENV

**Prototipo:** *char * getenv(const char * name)*
**Definición:** La función getenv se utiliza para obtener el valor de una variable de entorno específica en un programa. Recibe como argumento el nombre de la variable de entorno que se desea obtener y devuelve un puntero a una cadena de caracteres que contiene el valor de la variable.

##TCSETATTR

**Prototipo:** *int tcsetattr(int fd, int optional_actions, const struct termios * termios_p)*
**Definición:** Se utiliza para establecer los parámetros de configuración de un terminal. Recibe como argumentos el descriptor de archivo del terminal, las acciones opcionales que se desean realizar y una estructura termios que contiene los parámetros de configuración. 

- TCSANOW: los cambios se aplican inmediatamente. 
- TCSADRAIN: los cambios se aplican después de que se hayan transmitido todos los datos pendientes de enviar. 
- TCSAFLUSH: los cambios se aplican después de que se hayan transmitido todos los datos pendientes de enviar y se hayan descartado todos los datos pendientes de recibir. 

##TCGETATTR

**Prototipo:** *int tcgetattr(int fd, struct termios * termios_p)*
**Definición:** Para obtener los parámetros de configuración actuales de un terminal. Recibe como argumento el descriptor de archivo del terminal y un puntero a una estructura termios donde se almacenarán los parámetros obtenidos. 

##TGETENT

**Prototipo:** *int tgetent(char * bp, const char * name)*
**Definición:**
 En el manejo de la biblioteca terminfo para obtener las capacidades y características de un terminal específico. Recibe como argumento un puntero a un búfer de caracteres y el nombre del archivo de descripción del terminal. 

##TGETFLAG

**Prototipo:** *int tgetflag(const char * capname)*
**Definición:**
 Se utiliza en la biblioteca terminfo para obtener el valor de una bandera (flag) específica del terminal. Recibe como argumento el nombre de la bandera que se desea obtener.

##TGETNUM

**Prototipo:** *int tgetnum(const char * capname)*
**Definición:**
 Se utiliza en la biblioteca terminfo para obtener el valor numérico de una capacidad específica del terminal. Recibe como argumento el nombre de la capacidad que se desea obtener. 

##TGETSTR

**Prototipo:** *char *tgetstr(const char * capname, char ** area)*
**Definición:**
 Se utiliza en la biblioteca terminfo para obtener una secuencia de escape específica del terminal. Recibe como argumento el nombre de la capacidad que se desea obtener y un puntero a un área de memoria donde se almacenará la secuencia de escape. 

##TGOTO

**Prototipo:** *char * tgoto(const char * capname, int col, int row)*
**Definición:**
 Se utiliza en la biblioteca terminfo para generar una secuencia de escape que mueve el cursor a una posición específica en el terminal. Recibe como argumentos el nombre de la capacidad que se desea utilizar, la columna y la fila a la que se desea mover el cursor.

##TPUTS
**Prototipo:** *int tputs(const char * str, int affcnt, int (* putc)(int))*
**Definición:** Se utiliza en la biblioteca terminfo para enviar una secuencia de escape al terminal. Recibe como argumentos una cadena de caracteres que representa la secuencia de escape, un contador de afectación y una función que se utiliza para enviar caracteres al terminal. 