BiTree:BiTreeEx.o BiTree.o

	gcc -o BiTree BiTreeEx.o BiTree.o



BiTreeEx.o:BiTreeEx.c BiTree.h

	gcc -g -c BiTreeEx.c



BiTree.o:BiTree.h BiTree.c

	gcc -g -c BiTree.c 
