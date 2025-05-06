
#include "./inc/termcode.h"

te_t editor;

char *filename;
text_t text;


int main(int argc , char **argv , char **envp)
{
	
	if(argc!=2)
	{
		write(STDERR_FILENO , "Usage : ./termcode <filename>\n" , 30);
		return 0 ;
	}

	filename = ft_strdup(argv[1]);

	int fd = open(filename , O_CREAT | O_RDONLY );

	if(fd==-1)
	{
		write(STDERR_FILENO , "Error : Failed openning the file\n" , 33 );
		return 0 ;
	}

	if(tgetent(editor.term_type , getenv("TERM"))==-1)
		write(STDERR_FILENO ,"Error : Cannot retrieve terminal type" , 37 );

	init_env(&editor , envp );
	
	output_content(fd , &editor , &text );
	close(fd);
	
	termcode_readKey(&editor , envp , &text , filename);
	fflush(stdout);
	free_all(&editor , &text);
}
