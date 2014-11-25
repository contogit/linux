flex -i analyseur.l
gcc -c lex.yy.c
gcc -c analyseur.c
gcc -o hbase  lex.yy.o analyseur.o
