#ifndef AC_DATASTORAGE_H_INCLUDED
#define AC_DATASTORAGE_H_INCLUDED

#endif // AC_DATASTORAGE_H_INCLUDED

char nombres[20][20] = {"AGUSTIN","BARBARA","CECILIA","DIEGO","DIEGO","DARIO","DARIO","ESTEBAN","ESTEBAN","FERNANDA","GRACIELA","HECTOR","IGOR","JOAQUIN","LAUTARO","MARCELA","NICOLAS","NICOLAS","PAULA","RICARDO"};
char apellidos[20][20] = {"GONZALEZ","RODRIGUEZ","GOMEZ","FERNANDEZ","LOPEZ","DIAZ","MARTINEZ","PEREZ","GARCIA","SANCHEZ","ROMERO","SOSA","TORRES","PEREZ","GARCIA","GOMEZ","LOPEZ","TORRES","CORIA","DI BENEDETTO"};
char sexos [20] = {'m','f','f','m','m','m','m','m','m','f','f','m','m','m','m','f','m','m','f','m'};
int ids[20] = {1000,1001,1002,1003,1004,1005,1006,1007,1008,1009,1010,1011,1012,1013,1014,1015,1016,1017,1018,1019};
int legajos [20] = {1793,1324,2973,2948,3923,3001,4189,4320,5500,5990,6777,6310,7100,7777,8000,8912,9123,9677,4900,2111};
int dnis [20] = {30513640, 33339046, 11268226, 15802999, 23382297, 48257807, 35206208, 44487966, 29580244, 42814125, 42910229, 32849735, 46945672, 19021714, 36780668, 49095401, 16643540, 42667124, 49883938, 31031339};
char nombresCompletos [40][20] = {"AGUSTIN GONZALEZ","BARBARA RODRIGUEZ","CECILIA GOMEZ","DIEGO FERNANDEZ","DIEGO LOPEZ","DARIO DIAZ","DARIO MARTINEZ","ESTEBAN PEREZ","ESTEBAN GARCIA","FERNANDA SANCHEZ","GRACIELA ROMERO","HECTOR SOSA","IGOR TORRES","JOAQUIN PEREZ","LAUTARO GARCIA","MARCELA GOMEZ","NICOLAS LOPEZ","NICOLAS TORRES","PAULA CORIA","RICARDO DI BENEDETTO"};
int edades [20] = {18,20,22,24,26,28,30,35,39,41,45,50,47,19,21,22,25,25,30,33};
float sueldos [20] = {144400, 380700, 457000, 433600, 454500, 457000, 101200,  53000, 118400, 454500, 411300, 57200, 65900, 119300, 214800, 39900, 61300, 276600, 292300};
int days [100] = {3,5,14,1,28,2,18,3,8,22,19,29,2,4,17,9,23,8,6,14,8,25,20,1,25,10,27,23,13,25,7,7,25,19,23,23,5,27,5,14,11,23,4,1,5,7,12,27,29,20,17,1,1,10,29,14,19,29,24,19,18,25,19,26,22,18,19,6,1,11,21,29,10,14,26,1,5,29,23,6,9,22,14,12,6,8,1,4,19,16,25,6,6,23,21,27,21,14,16,22};
int months [100] = {1,9,8,10,6,4,6,11,4,2,12,5,3,6,5,9,7,6,5,10,12,1,12,4,9,7,2,10,7,5,11,5,2,3,3,8,4,6,9,7,3,9,6,8,8,2,5,7,8,9,12,1,1,4,3,6,3,7,8,6,2,4,8,9,6,2,1,12,1,10,9,12,1,4,10,5,8,3,7,9,7,6,6,5,8,2,12,9,5,11,11,6,11,11,11,11,5,1,7,11};
int years [100] = {2008,2010,2017,1990,1991,1996,1993,1991,2002,2002,1991,2003,2003,2011,1998,1991,2019,2010,2019,2002,1999,2015,1997,1998,2013,2004,1995,1997,2001,1991,2000,2011,1991,1991,1997,1990,2015,2011,1995,2001,2015,2002,1997,1997,2007,2000,2019,2008,2015,2009,1993,2016,1994,2005,1999,2017,1992,1995,1993,2009,2015,2013,1990,1993,2018,2012,1997,2013,2014,1997,2005,1994,2003,1996,1992,2015,1997,2020,2006,2007,2020,2007,1998,2014,1994,2012,2000,1995,2004,1990,2004,2012,2020,2020,2015,1999,2007,2020,1993,2018};
int idsSector [20] = {1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5};
char nombresOrquesta [20][100]= {"Capilla de la Corte de San Petersburgo",
"Capilla Sinfónica Estatal de Rusia",
"Orquesta del Capitolio de Toulouse",
"Orquesta Sinfónica de Castilla y León",
"Orquesta Sinfónica de Chicago",
"Orquesta Sinfónica de Cincinnati",
"Orquesta de Cleveland",
"Orquesta Sinfónica Columbia",
"Orquesta Real del Concertgebouw",
"Orquesta Sinfónica Nacional de Costa Rica",
"Orquesta Sinfónica de Madrid",
"Orquesta Sinfónica MDR",
"Orquesta Estatal de Mecklemburgo",
"Orquesta Sinfónica de México",
"Orquesta Sinfónica del Estado de México",
"Orquesta Millennium",
"Orquesta Sinfónica de Montreal",
"Orquesta del Mozarteum de Salzburgo",
"Orquesta Sinfónica de la Región de Murcia",
"Museumsorchester de Fráncfort"
};
char ciudades [20][100]= {
"Ferndale Mobile Court, Quebec",
"Emerson, Maryland",
"Dundas, Connecticut",
"Glensted, Missouri",
"Tioga Valley, Missouri",
"Rock Canyon, Connecticut",
"Tours, Mississippi",
"Huff Creek, Rhode Island",
"Isle La Motte, Missouri",
"Dodge, Georgia",
"Moretown, Georgia",
"Black Butte, Kansas",
"Arolokovik, Georgia",
"Kymulga, Georgia",
"La Plaine Estates, Connecticut",
"Ross, Connecticut",
"Heizer, Britsh Columbia",
"La Marque, Britsh Columbia",
"Center, South Carolina",
"Uhland, Kentucky"
};
int idsTipoOrquesta [20] = {1,1,3,2,3,1,2,3,2,1,1,3,2,3,3,2,1,3,2,1};
int idsInstrumentos [20]  = {10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29};
int idsMusico [20] = {5000,5001,5002,5003,5004,5005,5006,5007,5008,5009,5010,5011,5012,5013,5014,5015,5016,5017,5018,5019};
char nombresInstrumento [20][30] = {"Piano","Bateria","Violin","Viola","Bajo","Triangulo","Flauta","Flautin","Oboe","Xilofon","Violin","Violin","Viola","Flauta","Trompeta","Trombon","Flauta","Guitarra","Xilofon Metalico","Piano"};
int idsTipoInstrumento [20] = {1,2,3,4,1,2,3,4,1,2,3,4,4,4,3,2,3,2,1,2};
int idsMoto [20] = {100000,100001,100002,100003,100004,100005,100006,100007,100008,100009,100010,100011,100012,100013,100014,100015,100016,100017,100018,100019};
char marcasMoto [20][50]= {
"Kawasaki",
"Ducati",
"Harley-Davidson",
"Suzuki",
"KTM",
"BMW Motorrad",
"Triumph",
"Victoria",
"Kawasaki",
"Ducati",
"Harley-Davidson",
"Suzuki",
"KTM",
"BMW Motorrad",
"Triumph",
"Victoria",
"Harley-Davidson",
"Suzuki",
"KTM",
"BMW Motorrad"
};
int cilindradas [20] = {50, 125, 500, 600, 750, 50, 125, 500, 600, 750,125,125,125,50,600,600,600,500,750,750};
int tiposMoto [20] = {1003,1002,1003,1000,1001,1002,1003,1000,1001,1002,1003,1000,1001,1002,1003,1000,1000,1003,1003,1001};
int idsColor [20] = {10000,10001,10002,10003,10004,10000,10001,10002,10003,10004,10000,10001,10002,10003,10004,10000,10001,10002,10003,10004};
int idsServicio [20] = {20001,20002,20002,20003,20000,20000,20000,20001,20003,20002,20001,20002,20002,20003,20000,20000,20000,20001,20003,20002};
int idsTrabajo [20] = {100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119};
int idsCliente [20] = {10000000,10000001,10000002,10000003,10000004,10000005,10000006,10000007,10000008,10000009,10000010,10000011,10000012,10000013,10000014,10000015,10000016,10000017,10000018,10000019};

