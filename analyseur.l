%{
	#include "analyseur.h"
%}
%option noyywrap

%%

"status"				{return STATUS;}
"version"				{return VERSION;}
"whoami"				{return WHOAMI;}

"simple"				{return SIMPLE;}
"summary"				{return SUMMARY;}
"detailed"				{return DETAILED;}


"create"				{return CREATE;}		
"NAME"					{return NAME;}
"VERSIONS"				{return VERSIONS;}
"DATA_BLOCK_ENCODING"			{return DATA_BLOCK_ENCODING;}
"BLOOMFILTER"				{return BLOOMFILTER;}		
"ROW"					{return ROW;}
"REPLICATION_SCOPE"			{return REPLICATION_SCOPE;}
"COMPRESSION"				{return COMPRESSION;}
"NONE"					{return NONE;}
"MIN_VERSIONS"				{return MIN_VERSIONS;}
"TTL" 					{return TTL;}
"FOREVER"				{return FOREVER;} 
"KEEP_DELETED_CELLS" 			{return KEEP_DELETED_CELLS;}
"BLOCKSIZE"          			{return BLOCKSIZE;}               
"IN_MEMORY" 				{return IN_MEMORY;}
"BLOCKCACHE"				{return BLOCKCACHE;}

"true"					{return TRUE;}                       
"false"					{return FALSE;} 

","					{return VIRG;}
"{"					{return ACCOOPEN;}
"}"					{return ACCOCLOSE;}
"=>"					{return ASSIGN;}
\47[a-zA-Z][a-zA-Z0-9]*\47		{return IDF;}
[0-9]+					{return NUMBER;}
[\n]					{return FOLLOW;}
[ \t]


%%


