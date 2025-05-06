#ifndef TERMCODE_H
#define TERMCODE_H

#define BUFF_SIZE 2048
#define PIECE_SIZE 10


#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include <termcap.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>

#include "get_next_line.h"




typedef struct term_editor_s{
	struct termios old_termios;
	struct termios configured_terminal;
	char *term_type;
	char *term_buffer;
	char *cursor_motion_str;
	char *tgoto_str;
	char *buff_ptr;
	int posx;
	int posy;
	int *line_len;
	int len_cap;
	int len_len;
} te_t;


typedef struct Line
{
	char *buffer;
	int len;
	int cap;	
}	line_t;

typedef struct Text
{
	line_t line;
	struct Text *next;
} 	text_t;

//basic utils
int max(int a , int b);
int min(int a , int b);

//string utils
void ft_strcpy(char *src , size_t len , char *dest);

//env utils
void init_env(te_t *editor , char **envp );
void clear_screen(char **envp);
void init_text(text_t *text);
void termcode_readKey(te_t *editor, char **envp , text_t *text , char *filename);
void my_putchar(char c , te_t *editor , text_t *text );
void move_cursor_up(te_t *editor);
void move_cursor_down(te_t *editor);
void move_cursor_right(te_t *editor);
void move_cursor_left(te_t *editor);
void redraw_line(te_t *editor , char *content , int len);
void erase_char(te_t *editor , text_t *text);
void make_newline(char c, te_t *editor , text_t *text);
void redraw_under(te_t *editor , text_t *text);
void save(te_t *editor , text_t *text , char *filename);
void remove_line(te_t *editor , text_t *text);
void free_all(te_t *editor , text_t *text);

//file management utils
void output_content(int fd , te_t *editor , text_t *text);


#endif
