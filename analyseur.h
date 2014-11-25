#ifndef ANALYSEUR_ZZ_H
#define ANALYSEUR_ZZ_H


typedef enum {

STATUS,
VERSION,
WHOAMI,
SIMPLE,
SUMMARY,
DETAILED,
CREATE,
NAME,
VERSIONS,
DATA_BLOCK_ENCODING,
BLOOMFILTER,
ROW,
REPLICATION_SCOPE,
COMPRESSION,
NONE,
MIN_VERSIONS,
TTL,
FOREVER,
KEEP_DELETED_CELLS,
BLOCKSIZE,
IN_MEMORY,
BLOCKCACHE,
TRUE,
FALSE,
VIRG,
ACCOOPEN,
ACCOCLOSE,
ASSIGN,
IDF,
NUMBER,
FOLLOW
} typetoken;
#endif


typedef enum {false=0, true=1} boolean;

boolean _create( ); /* create*/ 
boolean _liste_cf( ); /* LISTE_CF*/ 
boolean _cf( ); /* CF */ 
boolean _liste_cfaux( ); /* LISTE_CFAUX */ 
boolean _desc_cf( ); /* DECL_AUX */ 
boolean _liste_desc_cf(); /*LISTE_DESC_CF*/
boolean _liste_desc_cfaux(); /*LISTE_DESC_CFAUX*/


extern int yylex();

typetoken _lire_token() ;
