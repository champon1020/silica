all:
	@make cmd
	@make dl
	@make test

cmd: cmd.c
	gcc cmd.c -o ../../tasks/cmd

dl: dl.c
	gcc dl.c -o ../../tasks/dl

test: test.c
	gcc test.c -o ../../tasks/test
