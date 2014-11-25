#include "analyseur.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typetoken token;
boolean follow_token=false ;


int main(int argc, char * argv){

token = _lire_token();

if (_create()  == true){

	printf("Syntaxe correcte \n");

	}	

else {
printf("erreurs syntaxiques\n");
}

return 0; 
}


///////////////////////// _lire_token() 
typetoken _lire_token() {

	if (follow_token){
	follow_token = false; // RAZ du marqueur de sur-lecture
	return token; // renvoie du token déjà lu !
	}

	else{
	return (typetoken) yylex();
	}
}


// CREATE  --> create idf LISTE_CF enter
boolean _create(){
boolean resultat;

	if(token==CREATE){	
		token=_lire_token();
		if(token==IDF){
			token = _lire_token();
			if(_liste_cf()){
				token=_lire_token();
				if(token==FOLLOW){ resultat=true;
				}else resultat=false;
			}else resultat=false;
		}else resultat=false;
	}else resultat=false;
return resultat;
}


// LISTE_CF --> ',' CF LISTE_CFAUX
boolean _liste_cf(){
boolean resultat;

	if(token==VIRG){

		token=_lire_token();
		if(_cf()){

			token=_lire_token();
			if(_liste_cfaux())	resultat = true;
			else resultat=false;
		}
		else resultat=false;
	}
	else resultat=false;


return resultat;
}


// LISTE_CFAUX --> LISTE_CF | epsilon
// NULLABLE(LISTE_FAUX)=true
// FOLLOW(LISTE_CFAUX)='Enter'
boolean _liste_cfaux(){
boolean resultat;

	if(token==FOLLOW){
		follow_token=true;
		resultat=true;
		
	}
	else if(_liste_cf()){
		resultat=true;
	}
	else	resultat=false;

return resultat;
}


// CF --> '{' LISTE_DESC_CF'}' 
//    -->  idf
boolean _cf(){
boolean resultat;

if(token==ACCOOPEN){

		token=_lire_token();
		if(_liste_desc_cf()){

					token=_lire_token();
					if(token==ACCOCLOSE) resultat=true;
					else resultat=false;

			}
			else resultat=false;

}
else if(token==IDF){
	resultat=true;
}
else resultat=false;


return resultat;
}

//LISTE_DESC_CF -->  DESC_CF '=>' idf   LISTE_DESC_CFAUX
boolean _liste_desc_cf(){
boolean resultat;
	if(_desc_cf()){
		token=_lire_token();
		if(token==ASSIGN){
			token=_lire_token();
			if (token==IDF){ 
				token=_lire_token();
				if(_liste_desc_cfaux())resultat=true;
				else resultat=false;
			}else resultat=false;
		}else resultat=false;
	}

	else resultat=false;

return resultat;
}

// LISTE_DESC_CFAUX --> ',' LISTE_DESC_CF | epsilon
// NULLABLE(LISTE_DESC_CFAUX)=true
// FOLLOW(LISTE_DESC_CFAUX)='}'
boolean _liste_desc_cfaux(){
boolean resultat;
	if(token==ACCOCLOSE){
		follow_token=true;
		resultat = true;
	}else if(token==VIRG){
		token=_lire_token();
		if(_liste_desc_cf()){
		resultat=true;
	        }else resultat=false;
	}else resultat= false;
}

//DESC_CF --> NAME | DATA_BLOCK_ENCODING | ... |...|...
boolean _desc_cf(){
boolean resultat;

	if(token==NAME 
	|| token == VERSIONS
	|| token == DATA_BLOCK_ENCODING
	|| token == BLOOMFILTER
	|| token == REPLICATION_SCOPE
	|| token == COMPRESSION
	|| token == MIN_VERSIONS
	|| token == TTL
	|| token == KEEP_DELETED_CELLS
	|| token == BLOCKSIZE
	|| token == IN_MEMORY
	|| token == BLOCKCACHE){
		
		resultat=true;
		
	}
	else	resultat=false;

return resultat;
}





