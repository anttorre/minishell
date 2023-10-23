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

<!-- readline, rl_clear_history, rl_on_new_line,
rl_replace_line, rl_redisplay, add_history,
printf, malloc, free, write, access, open, read,
close, fork, wait, waitpid, wait3, wait4, signal,
sigaction, kill, exit, getcwd, chdir, stat,
lstat, fstat, unlink, execve, dup, dup2, pipe,
opendir, readdir, closedir, strerror, perror,
isatty, ttyname, ttyslot, ioctl, getenv, tcsetattr,
tcgetattr, tgetent, tgetflag, tgetnum, tgetstr,
tgoto, tputs -->

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

	El valor del pid puede ser:
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


##
**Prototipo:** **
**Definición:**

##
**Prototipo:** **
**Definición:**

##
**Prototipo:** **
**Definición:**

##
**Prototipo:** **
**Definición:**

##
**Prototipo:** **
**Definición:**

##
**Prototipo:** **
**Definición:**

##
**Prototipo:** **
**Definición:**

##
**Prototipo:** **
**Definición:**

##
**Prototipo:** **
**Definición:**

##
**Prototipo:** **
**Definición:**

##
**Prototipo:** **
**Definición:**

##
**Prototipo:** **
**Definición:**

##
**Prototipo:** **
**Definición:**

##
**Prototipo:** **
**Definición:**

##
**Prototipo:** **
**Definición:**