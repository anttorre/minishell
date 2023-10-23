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