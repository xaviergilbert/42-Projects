all:
	make -C ./assembler/
	make -C ./vm/
	mv ./assembler/asm .
	mv ./vm/corewar .

clean:
	make -C ./vm/ clean
	make -C ./assembler/ clean

fclean:
	make -C ./vm/ fclean
	make -C ./assembler/ fclean
	rm asm
	rm corewar

re: fclean all
