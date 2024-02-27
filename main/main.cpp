/**
·*·@file·main·cpp
·*·@author·Samuel·Ramirez·
·*·@brief·Clasico_Automotriz·
·*·@version·1.0·
·*·@date·2024-02-22·
**
**
*/

#include <iostream>

using namespace std;

void verbienvenida();
void verTipoV();
void verMarca();


int opcion;
char resp;
int opcion10, opcion11;//Variables que guardan los datos de seleccion del usuario en Ford y Chevrolet
int opcion12, opcion13;//Variables que guardan los datos de seleccion del usuario en Ferrari y Lamborghini
int opcion14, opcion15;//Variables que guardan los datos de seleccion del usuario en Toyota y Mazda
int opcion16, opcion17;
int opcion18, opcion19;

//-----------------*---------------------*------------------------*--------------------------*-------------------------*---------------------------*	

class Carro {
private:
    string modelos[20];
    string motores[20];
    string colores[20]; 
    int HP[20];
    int precios[20];
    string anecdotas[20];
public:
    Carro(string, string, string, int, int, int);
    void imprimir(int); 
    void historia();
    void setAnecdota(string anecdota, int indice){ // Se define la funcion setAnecdota para acceder al arreglo y que llama a setAnecdota()
        anecdotas[indice] = anecdota; // anecdota: es para establecer la anecdota y la variable "indice" colocara la posicion en donde se guardara el arreglo
    }
    
    string getAnecdota(int indice){// Recibe el índice como parámetro y retorna un string porque va a obtener la anécdota en esa posición.
        return anecdotas[indice]; //Dentro del método retornamos el valor de anecdotas[indice] para devolver la anécdota.
    }//setAnecdota permite guardar anécdotas en el arreglo, y getAnecdota permite luego acceder a ellas por su índice.
};

//-----------------*---------------------*------------------------*--------------------------*-------------------------*---------------------------*	

// Inicializar más anécdotas...

void setAnecdotas(Carro &miCarro) { //funcion setAnecdotas aca se guardaran las anecdotas de cada vehiculo en su arreglo 

/*Ford-150*/miCarro.setAnecdota("\n""El primer Ford F-150 fue introducido en 1975 como parte de la segunda generacion""\n""de las camionetas Serie F de Ford. Su nombre original era Ford F-100, pero con""\n""algunas mejoras y redisenos se decidio cambiarlo a F-150 para reflejar que ahora""\n""podia transportar mas carga, unos 1,500 lbs (680 kg) de capacidad.""\n""""\n""Un dato interesante es que el F-150 original se ensamblo en la historica planta""\n""River Rouge de Ford en Michigan. Eventualmente, este modelo se convertiria en el""\n""vehiculo mas vendido de Estados Unidos durante decadas, ganandose el apodo de el""\n""rostro de Ford.""\n", 0); 
   
/*Mustang*/miCarro.setAnecdota("\n""El Boss 429 nace con el objetivo de poder homologar el impresionante motor Sem'Hemi 429""\n""de Ford para poder competir en NASCAR. A partir de ahi se construye casi de forma artesanal""\n""un Mustang especial para albergar este enorme motor. La produccion es tan limitada que solo""\n""se fabrican 1359 unidades entre 1969 y 1970.""\n""""\n""Uno de los datos mas interesantes es que, originalmente, el motor Boss 429 fue disenado con""\n""735 caballos de fuerza en mente. Pero no fue sino hasta diciembre de 1970 cuando se libero""\n""una version mas potente en las pistas de NASCAR llamado Super Boss 429 que alcanzaba los 760 HP.""\n""" , 1);
    
/*Corvette*/miCarro.setAnecdota("\n""La idea de crear un deportivo americano comenzo justo después de la Segunda Guerra Mundial, cuando GM""\n""quiso experimentar con nuevos materiales como la fibra de vidrio, creando en 1953 el prototipo EX-122""\n""conocido luego como Corvette.Un dato interesante es que originalmente iba a llamarse Opel American,""\n""pero como finalmente se decidio producirlo en GM USA, paso a llamarse Chevrolet Corvette.""\n""""\n""Otro dato es que ese primer ano solo se vendieron 300 unidades cuando la meta era vender 10 veces mas""\n""autos. Asi nacio el Corvette C1, un auto con gran potencial deportivo pero que aun le faltaban mejoras""\n""y potencia. Seria en 1955 cuando recibiria un imponente y nuevo motor V8, comenzando a forjar su leyenda""\n""como el deportivo americano por excelencia, agil, elegante y capaz de competir contra marcas europeas.""\n",2);
	
/*Camaro*/miCarro.setAnecdota("\n""Cuando fue lanzado, el Camaro logro combinar un diseno atletico y aerodinamico con opciones de potentes""\n""motores como el SS 396 V8 de 325 caballos de fuerza. Esto le permitio ser un exito de ventas y de""\n""competicion en carreras. Para 1969 se introdujo el paquete Z28 con un impresionante motor V8 de alto""\n""desempeno de 350 pulgadas cubicas destinado para competir en la nueva serie Trans-Am. El Camaro Z28""\n""domino las pistas logrando el campeonato y dando origen al legendario nombre Z28 que perdura hasta hoy.""\n""Originalmente iba a llamarse Panther pero finalmente se bautizo como Camaro.""\n""""\n""Luego de una pausa en produccion entre 2002-2009, el Camaro fue relanzado con un agresivo y moderno""\n""diseno que rendia homenaje a las primeras generaciones. El mas reciente Camaro ZL1 de 2022 entrega""\n""nada menos que 650 caballos de fuerza.""\n",3);

/*GTO250*/miCarro.setAnecdota("\n""Solo se fabricaron 39 unidades del 250 GTO entre 1962 y 1964. Debuto en 1962 y rapidamente comenzo a arrasar""\n""en las pistas, ganando el campeonato del mundo de constructores GT en 3 anos consecutivos: 1962,1963 y 1964.""\n""Esto le dio una reputacion legendaria de dominio que aumento su ya de por si alto valor.""\n""""\n""Un dato tecnico interesante es que el chasis del 250 GTO de 1962 estaba hecho de una novedosa aleacion de""\n""acero con soldaduras especiales en los puntos criticos, confiriendole mucha rigidez y bajo peso. Hoy en""\n""dia, el Ferrari 250 GTO de 1962 es considerado el Santo Grial de los autos deportivos y se han pagado mas""\n""de $70 millones de dolares por un ejemplar en perfectas condiciones. Un verdadero mito sobre 4 ruedas de la""\n""historia automotriz.""\n",4);	

/*F-40*/miCarro.setAnecdota("\n""Se desarrollo para conmemorar los 40 años de Ferrari y ser el supercar de calle mas veloz del mundo en esa epoca.""\n""Solo se fabricaron 1,311 unidades entre 1987-1992 convirtiendolo en un auto extremadamente raro y valioso.""\n""""\n""Su diseno se enfoco completamente en performance aerodinamica de punta. Por ello se fabrico con kevlar, fibra de""\n""carbono, aluminio y lexan para reducir el peso a solo 1100 kg. Esto le daba una increible relacion peso-potencia""\n""de 1 hp por cada 2.3 kg!""\n""""\n""Un dato tecnico crucial es que el 70% de toda la traccion del F40 estaba en las ruedas traseras. Esto le daba una""\n""aceleracion demoledora pero requeria pericia para controlar a esta impresionante bestia de potencia en el asfalto.""\n", 5);	

/*Miura*/miCarro.setAnecdota("\n""El Miura fue concebido en secreto por el ingeniero Dallara y algunos diseñadores junior sin que Ferruccio""\n""Lamborghini estuviera inicialmente enterado del proyecto. Cuando finalmente se lo presentaron, el sorprendente""\n""diseno lo cautivo para aprobar su produccion. Uno de los principales desafios tecnicos que enfrento Dallara""\n""fue conseguir que el enorme motor V12 transversal cupiera junto a la caja de cambios sin invadir demasiado el""\n""habitaculo.""\n""""\n""El innovador diseno del chasis lo logro, aunque dejaba poco espacio interior. Un dato tecnico clave es que""\n""incorporaba una novedosa suspension trasera independiente que le daba un excelente desempeno en curvas a altas""\n""velocidades. El chasis era muy liviano, pesando solo 1,158 kg.""\n", 6);

/*Countach*/miCarro.setAnecdota("\n""Fue presentado en el Salon del Automovil de Ginebra de 1971 causando gran conmocion por su diseno futurista""\n""de lineas angulares como de nave espacial, que rompia todas las reglas estilisticas de la epoca. Este diseno""\n""vanguardista se debio al disenador Marcello Gandini y le valio ser elegido como el auto de produccion mas""\n""hermoso de todos los tiempos por una revista inglesa especializada. Las puertas de tijera que se abrian hacia""\n""arriba se volvieron legendario.""\n""""\n""Un dato tecnico interesante es que originalmente el prototipo se iba a llamar Countach que en dialecto piamontes""\n""significa una expresion de asombro. Al dueno Ferruccio Lamborghini le gusto tanto que decidio dejarlo como nombre""\n""definitivo. El Countach se fabrico durante 16 anos con varias iteraciones, siendo uno de los Lamborghini mas""\n""exitosos de la historia con casi 2,000 unidades vendidas.""\n",7);

/*Supra*/miCarro.setAnecdota("\n""La 4ta generacion del nuevo Supra fue completamente rediseñado por Isao Tsuzuki, se quitaron los faros""\n""retractiles, se le dio una carroceria mucho mas resistente, mas pesada que las anteriores y mas redondeada.""\n""Lo verdaderamente iconico de esta generacion fue el motor 2JZ desarrollado por YAMAHA. Los 6 cilindros y dos""\n""turbocompresores generaban 320 HP (324 CV; 239 kW) a las 5600 rpm y un par maximo de 43,5 kg·m (427 N·m; 315 lb·pie)""\n""a las 4000 rpm.""\n""""\n""Uno de los aspectos mas importantes fue enfocarse en aerodinamica y estabilidad a alta velocidad. Se emplearon paneles""\n""de aluminio y de fibra de carbono para reducir peso. Tambien se hicieron extensas pruebas en tuneles de viento para""\n""pulir cada detalle. Sin duda, el Toyota Supra de cuarta generacion se convirtio en un clasico moderno muy buscado por""\n""su impresionante ingenieria mecanica y una conduccion fenomenal.", 8);

/*AE86*/miCarro.setAnecdota("\n""Este iconico modelo surgio como una version coupe deportiva del popular Toyota Corolla Levin, aprovechando""\n""la plataforma del Corolla revitalizada, se trata de una variante de traccion trasera. Algo que lo hacia especial""\n""era su avanzada suspension trasera independiente y su chasis reforzado, que le permitian un manejo y derrapes""\n""controlados muy superiores respecto al estandar de la epoca. Aunque su potencia no parecia extraordinaria, al""\n""ser un auto liviano de menos de 1,000 kg, gozaba de una buena relacion peso-potencia, con aceleraciones de""\n""0 a 100 km/h en menos de 9 segundos.""\n""""\n""Este pequeno pero agil coupe de traccion trasera supo granjearse un estatus de culto como plataforma ideal para""\n""modificaciones y competencia amateur, siendo hoy en dia un codiciado modelo de coleccion entre entusiastas del""\n""drifting y las carreras de Japon.""\n", 9);

/*RX7-FD*/miCarro.setAnecdota("\n""La Mazda RX-7 FD es la tercera y ultima generacion del iconico deportivo RX-7 de Mazda. Fue producida entre""\n""los años 1991 y 2002 y es considerada por muchos como una de las mejores generaciones del RX-7.La Mazda RX-7""\n""FD es la tercera y ultima generacion del iconico deportivo RX-7 de Mazda. Fue producida entre los anos 1991 y 2002""\n""y es considerada por muchos como una de las mejores generaciones del RX-7.Se lanzo en 1991 con un motor rotativo""\n""twin-turbo de 1.3 litros que producia 255 caballos de fuerza. Era increiblemente liviano y potente para la epoca.""\n""""\n""Su diseno estuvo a cargo del famoso disenador Mazda, Tom Matano. El diseno fluido y aerodinamico le valio el apodo""\n""de Bala de Mazda. Fue uno de los primeros coches de produccion en utilizar luces direccionales delanteras de xenon.""\n""Su avanzada suspension y chasis le permitian una maniobrabilidad y agarre envidiables. Era famoso por su capacidad""\n""de doblar y manejar a altas velocidades. Mazda solo fabrico alrededor de 68,000 unidades de la RX-7 FD antes de""\n""descontinuarla en 2002. Hoy en dia es un auto iconico y muy buscado por los coleccionistas.""\n",10);

/*MX5*/miCarro.setAnecdota("\n""Fue presentado en el Salon del Automovil de Chicago de 1989. Causo sensacion por su diseno retro inspirado en los""\n""roadsters britanicos de los anos 60. Su diseno fue encabezado por Matasaburo Maeda, ingeniero jefe de Mazda.""\n""El objetivo era recrear la experiencia de conduccion de los roadsters britanicos a un precio asequible. La revista""\n""Road & Track titulo su revision del MX-5 Miata en 1990 como el auto del siglo. Gano el premio al Auto del Ano en""\n""Japon y Europa. Su chasis y suspension estaban basados en el conocido sedan 323 de Mazda. Pero fueron refinados""\n""para proveer una experiencia de manejo agil y balanceada.""\n""""\n""Mazda priorizo poner el peso lo mas bajo y centrado posible para mejorar el manejo. La miradas fue Todo el motor,""\n""nada mas. El Miata MX-5 sigue produciendose hasta el dia de hoy, manteniendose fiel a la filosofia que lo vio""\n""nacer en 1989. Ya lleva mas de 1 millon de unidades vendidas globalmente.""\n",11);

/*CSL*/miCarro.setAnecdota("\n""CSL significa Coupe Sport Leichtbau (Coupe Sport Liviano). Pesaba aproximadamente 200kg menos que el coupe standard""\n""mediante el uso extensivo de fibra de vidrio en capot, maletero y puertas. Se desarrollo especificamente para""\n""competir en carreras, inspirando su diseno en el 3.0 CSL que gano Sebring y otras 6 horas de resistencia en los""\n""anos previos. Era un verdadero homologation special. Sus distintivos alerones traseros semejando alas de murcielago""\n""le valieron el apodo de Batmobile. Tambien tenia una la gran boca frontal para enfriar los frenos. BMW solo produjo""\n""1.265 unidades del 3.0 CSL callejero.""\n""""\n""Pero tambien construyo 86 versiones de carrera aun mas livianas y potentes, dominando el Campeonato Europeo de""\n""Turismos desde 1973 hasta 1979. El 3.0 CSL es considerado hoy como uno de los grandes BMW clasicos de la decada""\n""de los 70. Es muy valorado entre coleccionistas y su precio de venta puede superar los $250,000 dolares o mas.""\n",12);

/*507*/miCarro.setAnecdota("\n""Fue disenado por el conde Albrecht Goertz, bajo peticion del importador de BMW en Estados Unidos, que queria un auto ""\n""deportivo para competir con el Mercedes 300SL. Se fabricaron solo 252 unidades del 507. Inicialmente se planeaba una""\n""produccion de 5,000 autos, pero su alto precio (alrededor de $9,000 dolares en 1956) limito las ventas. Montaba""\n""un motor V8 de aluminio de 3.2 litros y 150 hp, que le permitia alcanzar 217 km/h. Las carrocerias eran""\n""fabricadas a mano en aluminio por los especialistas de carroceria Baur. El 507 impresiono en carreras como las""\n""Mille Miglia, pero no fue un exito comercial.""\n""""\n""Su fabricacion ceso en 1959 despues de generar grandes perdidas para BMW. Su valor historico fue reconocido anos""\n""despues. Hoy un BMW 507 en buen estado puede costar mas de $2 millones de dolares en subastas de autos clasicos.""\n""Menos de 200 unidades se estiman aun existentes.""\n",13);

/*R8 Coupet*/miCarro.setAnecdota("\n""Audi R8 Coupe GT es una edicion limitada y exclusiva del superdeportivo Audi R8 producida en 2011, que constituye""\n""una pieza muy buscada para coleccionistas. Solo se fabricaron 333 unidades, vendidas exclusivamente en Europa. Su""\n""produccion se baso en el R8 Plus 5.2 FSI, pero con mejoras como eliminacion del asiento trasero para un aligeramiento""\n""de peso, sistema de suspension sports adaptive dampening y un lujoso interior de cuero nappa fino. En el exterior""\n""exhibe un aleron trasero fijo de carbono y un splitter delantero mas pronunciado para aumentar el""\n""apoyo aerodinamico a altas velocidades.""\n""""\n""Cada unidad tenía una placa interior personalizada indicando el numero de unidad limitada y la firma de Frank Lamberty,""\n""jefe de diseno de Audi Sport GmbH. Se convirtió en un codiciado auto de coleccion, que hoy puede costar mas de""\n""medio millon de euros en el mercado. Definitivamente, un Audi iconico que quedara en la historia.""\n",14);

/*Quattro*/miCarro.setAnecdota("\n""El Audi Quattro es uno de los autos mas emblematicos y revolucionarios de la historia. Fue presentado en el Salon del""\n""Automovil de Genes en 1980 y fue el primer auto en serie en incorporar la traccion integral. Gracias a eso domino el""\n""Campeonato Mundial de Rally durante anos. Con el Quattro, Audi logro multiples titulos en el Campeonato Mundial de""\n""Rally. Consiguio 23 victorias de rally entre 1980 y 1986 guiado por leyendas como Michele Mouton, Stig Blomqvist o""\n""Walter Röhrl. Se fabricaron 11,452 unidades del Quattro original entre 1980 y 1991. Inicialmente estaba previsto""\n""vender solo 400 autos para homologarlo en competencias, pero la demanda obligo a aumentar su produccion.""\n""""\n""En homenaje al dominio del Audi Quattro, la Federacion Internacional del Automovil cambio el reglamento del campeonato""\n""de rally en 1987 para eliminar los motores turbo y limitar la traccion total. Definitivamente un auto adelantado""\n""a su epoca que revoluciono el mundo del rally y la industria automotriz con su traccion integral.Todo un hito historico""\n""de Audi.""\n",15);

/*Renault 4*/miCarro.setAnecdota("\n""El Renault 4 es un icono de la industria automotriz francesa y mundial. Algunos datos importantes sobre su historia.""\n""Fue presentado en el Salón del Automóvil de París de 1961. Destacaba por ser el primer vehículo de tracción delantera""\n""de Renault, montando el motor y la transmisión en el frente y uno de los modelos más vendidos en la historia de""\n""Renault con más de 8 millones de unidades fabricadas entre 1961 y 1992.Destacaba por su robustez y fiabilidad.""\n""Construcción reforzada para soportar malas condiciones de camino. Muchas unidades todavía siguen funcionando hoy en día.""\n""""\n""Apodado el Alférez: era popular entre oficinas de correo, empresas de agua, telefonía por su capacidad de carga y""\n""múltiples usos tanto de trabajo como familiares. Participó en el Rally París Argel de 1971 donde se fabricó una versión""\n""llamada Renault 4 GTL, de mayor potencia y prestaciones para competir. Inspirador de diseños posteriores, el Renault 4""\n""fue toda una institución para los franceses. Cambió la movilidad doméstica con su concepto accesible y funcional para""\n""todos.""\n",16);

/*Renault 5*/miCarro.setAnecdota("\n""El Renault 5 es uno de los autos mas iconicos de la historia de la marca francesa. Algunos datos emblematicos de este""\n""popular hatchback. Presentado en 1972 en el Salon del Automovil de Paris, el R5 fue el primer hatchback grande de""\n"" produccion a nivel mundial, estableciendo el segmento de los superminis. Su gran exito se debio a un diseno atrevido""\n""y moderno creado por Michel Boue que rompia con disenos mas cuadrados. Se le apodo Le car por su perfil cuna.""\n""Fue uno de los primeros autos masivos en utilizar materiales sinteticos y plasticos para aligerar el peso.""\n""""\n""La motorización básica era un motor Cleon de 4 cilindros refrigerado por agua. Durante los anos 70 mostro gran""\n""capacidad sportiva triunfando en múltiples ediciones del prestigioso Rally de Montecarlo en su categoria. Tuvo un""\n""protagonismo importante en lacultura popular, apareciendo en peliculas, canciones y adquiriendo popularidad en mercados""\n""tan diversos como Colombia, Argentina o Japon. Definitivamente, uno de los grandes referentes de la industria""\n""automotriz de las decadas de 1970/80 con un impacto de legado unico.""\n",17);

/*Type57*/miCarro.setAnecdota("\n""El Bugatti Type 57 SC Atlantic es un automovil iconico que incluso hoy despierta la imaginacion de entusiastas y""\n""coleccionistas. Fue disenado por Jean Bugatti, hijo del fundador Ettore Bugatti. Entre 1936 y 1940 se fabricaron""\n""unicamente 730 unidades del Type 57 y sus variantes. La carroceria Atlantic era tan innovadora como aerodinamica.""\n""Construida enteramente en aluminio pulido con la parte central caracteristicamente carenada y con dos protuberancias""\n""a los lados parecidas a aletas. Solo se fabricaron 4 unidades del exclusivo Type 57 SC Atlantic, de las cuales hoy""\n""solo quedan 2 unidades.""\n""""\n""Una esta en el museo Mullin en California y la otra en manos de Ralph Lauren tras haber sido vendida por $40 millones""\n""de dolares en 2010. Los Atlantic entraron en la historia participando en carreras como las 24 Horas de Le Mans.""\n""Son considerados verdaderas obras maestras de la carroceria, diseno y mecanica. Actualmente figuran entre los autos""\n""mas caros y valiosos de todos los tiempos, alcanzando cifras bien por encima de los 100 millones de dolares.""\n", 18);

/*Veyron*/miCarro.setAnecdota("\n""El Bugatti Veyron es uno de los autos mas impresionantes de la historia moderna. Fue presentado por Bugatti en el""\n""Salon del Automovil de Tokio en octubre de 2005. Podia alcanzar una velocidad maxima de 407 km/h, convirtiendose""\n""durante varios anos en el auto de produccion mas rapido del mundo. El desarrollo del Veyron comenzo con Volkswagen""\n""Group en 2001 y se invirtieron mas de 6 billones de euros en crear tanto la planta de produccion como el auto.""\n""Incorporaba tecnologias de ultima generacion para la epoca como sistema de traccion total, caja de cambio automatica""\n""de doble embrague, suspension neumatica adaptativa y frenos de alto desempeno.""\n""""\n""Con un precio inicial de 1 millon de euros, el Veyron se convirtio en el auto de produccion serie mas costoso en venta""\n""por aquellos anos, solo superado por variantes aun mas exclusivas como el Mansory Linea Vivere. Sin dudas, el Veyron""\n""elevo significativamente el liston de lo que un auto podia lograr combinando potencia, lujo y exclusividad. Todo un""\n""parteaguas para la industria.""\n", 19);

  
}

//-----------------*---------------------*------------------------*--------------------------*-------------------------*---------------------------*	

Carro::Carro(string modelo1, string motor1, string color1, int HP1, int precio1, int indice) { //Creacion del Constructor
    modelos[indice] = modelo1;
    motores[indice] = motor1;
    colores[indice] = color1;
    HP[indice] = HP1;
    precios[indice] = precio1;   
   
}

//-----------------*---------------------*------------------------*--------------------------*-------------------------*---------------------------*	

void Carro::imprimir(int indice) {
	
    cout << "--> Caracteristicas: "<<endl<<"\n"">> Modelo: " << modelos[indice] << endl;
    cout << ">> Motor: " << motores[indice] << endl;
    cout << ">> Caballos de Fuerza: " << HP[indice] <<" HP"<<endl; 
    cout << ">> Colores: " << colores[indice] << endl;
    cout << ">> Precio: " << precios[indice] <<" $ " <<endl;
    
}

//-----------------*---------------------*------------------------*--------------------------*-------------------------*---------------------------*	

int main () {
	
	verbienvenida();
	Carro miCarro = Carro("","","",0,0,0); // En esta linea se crea o instancia el objeto miCarro de la clase Carro antes de poder utilizarlo si no existiera, al tratar de llamar a setAnecdotas(miCarro), daría un error porque miCarro no estaría definido aún. Esto se debe a que setAnecdotas() recibe como parámetro un objeto de la clase Carro. Si ese objeto no ha sido creado aún, no se puede pasar a la función.
	setAnecdotas(miCarro); //Esta función define previamente en el código para inicializar las anécdotas de cada vehículo dentro del objeto miCarro.
	  
	do{
			
    verTipoV();
	verMarca();

//-----------------*---------------------*------------------------*--------------------------*-------------------------*---------------------------*	
  
    //Creacion de Objectos
 
    Carro F150 = Carro("F-150", "V6", "Gris", 400, 20000, 0);
    Carro Mustang = Carro("Ford Mustang Boss 429 - 1969", "V8 - 7.0L", "Varios", 375, 400000, 1);
    Carro Corvette = Carro("Corvette C1 - 1953","6 Cilindros en Linea - 3.9L","Blanco, Rojo, Azul, Negro", 150, 200000, 2);
    Carro Camaro = Carro("Camaro - 1967", "6 Cilindros en Linea - 3.8L", "Varios", 275, 100000, 3);
    Carro GTO250 = Carro("Ferrari GTO 250 - 1962", "V12 - 3.0L", "Rojo", 300, 52000000, 4);
    Carro F40 = Carro("Ferrari F40 - 1987", "V8 - 2.9L", "Rojo", 478, 2500000, 5);//precio en dolares
 	Carro Miura = Carro("Miura - 1966", "V12 - 3.9L", "Naranja, Verde, Rojo, Amarillo", 350, 4200000, 6);//precio en dolares
 	Carro Countach = Carro("Countach - 1974", "V12 - 4L", "Rojo", 375, 850000, 7);
    Carro Supra = Carro("Toyota Supra A80 - 1993", "6 Cilindros en linea - 3.0 L", "Blanco, Rojo, Azul, Gris", 320, 120000, 8); //dolares
    Carro AE86 = Carro("Toyota AE86", "4 Cilindros en linea - 1.6L", "Blanco,Verde,Gris,Azul,Negro", 128, 45000, 9);//Dolares
	Carro RX7 = Carro("Mazda RX7 FD - 1993", "Rotativo Wankel de 2 Rotores - 1.3L", "Rojo, Blanco, Azul, Verde", 212, 60000, 10);
    Carro MX5 = Carro ("Mazda MIATA MX-5 - 1990", "4 Cilindros en Linea - 1.6L","Rojo, Plata, Blanco, Azul, Amarillo", 116, 25000, 11); 
    Carro CSL = Carro("BMW CSL - 1972", "6 Cilindros en Linea - 3.0L", "Varios", 206, 300000, 12);
    Carro BMW507 = Carro("BMW 507 - 1956", "V8 - 3.0L", "Negro, Gris, Azul, Blanco, Rojo", 150, 5000000 , 13);
    Carro R8 = Carro("Audi R8 Coupe GT - 2011", "V10 - 5.2L", "Blanco, Gris, Azul, Verde ", 560, 200000, 14);
    Carro Quattro = Carro("Audi Quattro - 1980", "5 Cilindros en Linea - 2.1L", "Rojo, Blanco, Gris, Plata, Negro", 306, 250000, 15);
    Carro Ren4 = Carro("Renault 4 - 1961", "4 Cilindros en Linea - 747cc", "Azul, Rojo, Blanco, Verde, Naranja", 21, 19300, 16);
    Carro Ren5 = Carro("Renault 5 - 1972", "4 cilindros en linea - 956cc", "Azul, Amarillo. Rojo, Blanco, Verde", 34, 17000, 17);
    Carro Type57 = Carro("Bugatti Type 57 SC Atrantic - 1938", "8 Cilindros en linea 3.0L", "Negro, Azul Oscuro", 210, 160000000, 18);
    Carro Veyron = Carro("Bugatti Veyron - 2005", "W16 - 8L", "Varios", 1001, 1450000, 19);
 
 //-----------------*---------------------*------------------------*--------------------------*-------------------------*---------------------------*	

    switch(opcion10) { //FORD
        case 1: 
        cout << miCarro.getAnecdota(0)<<endl;
            F150.imprimir(0);
            break;

        case 2:
        	cout << miCarro.getAnecdota(1)<<endl;
            Mustang.imprimir(1); 
            break;
            
        default:
            cout << "";
    }
    
     
	 switch(opcion11) { // CHEVROLET
        case 1: 
        	cout<< miCarro.getAnecdota(2)<<endl;
            Corvette.imprimir(2);
			break;

        case 2:
        	cout<< miCarro.getAnecdota(3)<<endl;
            Camaro.imprimir(3); 
            break;

        default:
            cout << "";
    }
    
//-----------------*---------------------*------------------------*--------------------------*-------------------------*---------------------------*	

	switch(opcion12) { // Ferrari
        case 1: 
        	cout<< miCarro.getAnecdota(4)<<endl;
            GTO250.imprimir(4);
            break;

        case 2:
           	cout<< miCarro.getAnecdota(5)<<endl;
            F40.imprimir(5); 
            break;

        default:
            cout << "";
    }
	

	switch(opcion13) { // Lamborghini
        case 1: 
        	cout<< miCarro.getAnecdota(6)<<endl;
            Miura.imprimir(6);
            break;

        case 2:
            cout<< miCarro.getAnecdota(7)<<endl;
			Countach.imprimir(7); 
            break;

        default:
            cout << "";
    }
	
//-----------------*---------------------*------------------------*--------------------------*-------------------------*---------------------------*	
    
    	switch(opcion14) { // Toyota
        case 1: 
         	cout<< miCarro.getAnecdota(8)<<endl;
            Supra.imprimir(8);
            break;

        case 2:
        	cout<< miCarro.getAnecdota(9)<<endl;
            AE86.imprimir(9); 
            break;

        default:
            cout << "";
    }

    
    	switch(opcion15) { // Mazda
        case 1: 
        	cout<< miCarro.getAnecdota(10)<<endl;
            RX7.imprimir(10);
            break;

        case 2:
        	cout<< miCarro.getAnecdota(11)<<endl;
            MX5.imprimir(11); 
            break;

        default:
            cout << "";
    }

//-----------------*---------------------*------------------------*--------------------------*-------------------------*---------------------------*	
    
    	switch(opcion16) { //BMW
        case 1: 
       		cout<< miCarro.getAnecdota(12)<<endl;
            CSL.imprimir(12);
            break;

        case 2:
        	cout<< miCarro.getAnecdota(13)<<endl;
            BMW507.imprimir(13); 
            break;

        default:
            cout << "";
    }
	
	
    	switch(opcion17) { // Audi
        case 1: 
        	cout<< miCarro.getAnecdota(14)<<endl;
            R8.imprimir(14);
            break;

        case 2:
        	cout<< miCarro.getAnecdota(15)<<endl;
            Quattro.imprimir(15); 
            break;

        default:
            cout << "";
    }
    
//-----------------*---------------------*------------------------*--------------------------*-------------------------*---------------------------*	
    
    	switch(opcion18) { //Renault
        case 1: 
        	cout<< miCarro.getAnecdota(16)<<endl;
            Ren4.imprimir(16);
            break;

        case 2:
        	cout<< miCarro.getAnecdota(17)<<endl;
            Ren5.imprimir(17); 
            break;

        default:
            cout << "";
    }
 
 
    	switch(opcion19) { //Bugatti
        case 1: 
        	cout<< miCarro.getAnecdota(18)<<endl;
            Type57.imprimir(18);
            break;

        case 2:
        	cout<< miCarro.getAnecdota(19)<<endl;
            Veyron.imprimir(19); 
            
            break;

        default:
            cout << "";
    }
    	
//-----------------*---------------------*------------------------*--------------------------*-------------------------*---------------------------*	
    
	cout<<"\n"; 
	cout << "¿Desea ver las caracteristicas de otro vehiculo? (S/N): ";
    cin >> resp;

    if(resp == 'N' || resp == 'n') {
    	
     cout<<"FINALIZA EL PROGRAMA"<<endl;
	 
	  break;
    }
    system("cls");
    
   // Reiniciar variables
   opcion = 0;
   opcion10 = -1;
   opcion11 = -1;
   opcion12 = -1;
   opcion13 = -1;
   opcion14 = -1;
   opcion15 = -1;
   opcion16 = -1;
   opcion17 = -1;
   opcion18 = -1;
   opcion19 = -1;
   
   }while(true);
 
	return 0;
}

//-----------------*---------------------*------------------------*--------------------------*-------------------------*---------------------------*	
	
void verbienvenida() {
	
	cout<<"\n";
	cout<<"Bienvenidos a Wiki classic cars, su enciclopedia definitiva de vehiculos clasicos. Aqui encontrara fascinantes"<<endl;
	cout<<"relatos sobre los iconicos automoviles del siglo XX que marcaron epoca con su diseno y su ingenieria innovadora."<<endl;
	cout<<"Asi que arranque su motor para recorrer este emocionante viaje por la historia del automovil."<<endl;
	cout<<"\n";
     
}

//-----------------*---------------------*------------------------*--------------------------*-------------------------*---------------------------*	
	
void verTipoV(){

do{
    cout << "Elige el tipo de vehiculo: " << endl;
    cout<<"\n";
    cout << ">> 1. Americano" << endl;
    cout << ">> 2. Italiano" << endl;
    cout << ">> 3. Japones" << endl;
    cout << ">> 4. Aleman" << endl;
    cout << ">> 5. Frances" << endl;
    cin >> opcion;
    break;
    }while(true); 
    system("cls");
}

//-----------------*---------------------*------------------------*--------------------------*-------------------------*---------------------------*	

void verMarca(){
    
    int opcion1;  //variable, opcion1 guarda datos de vehiculos americanos
    int opcion2;  //variable, opcion2 guarda datos de vehiculos italianos
    int opcion3;  //variable, opcion3 guarda datos de vehiculos japoneses
    int opcion4;
    int opcion5;
    
	if(opcion == 1){
    cout<<"//////////VEHICULOS AMERICANOS//////////"<<endl;
    cout<<"\n";
	cout<<"Elige una opcion:"<<endl;
	cout<<"\n";
    cout << ">> 1. Ford" << endl;
    cout << ">> 2. Chevrolet" << endl;
    cin>>opcion1;
    }else if(opcion == 2){
    cout<<"//////////VEHICULOS ITALIANOS//////////"<<endl;
    cout<<"\n";
	cout<<"Elige una opcion:"<<endl;
	cout<<"\n";	
    cout << ">> 1. Ferrari" << endl;
    cout << ">> 2. Lamborghini" << endl;
    cin>>opcion2;   
    }else if(opcion == 3){
	cout<<"//////////VEHICULOS JAPONESES//////////"<<endl;
    cout<<"\n";
	cout<<"Elige una opcion:"<<endl;
	cout<<"\n";
    cout << ">> 1. Toyota" << endl;
    cout << ">> 2. Mazda" << endl;
    cin>>opcion3;   
    }else if(opcion == 4){
    cout<<"//////////VEHICULOS ALEMANES//////////"<<endl;
    cout<<"\n";
	cout<<"Elige una opcion:"<<endl;
	cout<<"\n";
    cout << ">> 1. BMW" << endl;
    cout << ">> 2. Audi" << endl;
    cin>>opcion4;
    }else if(opcion == 5){
    cout<<"//////////VEHICULOS FRANCESES//////////"<<endl;
    cout<<"\n";
	cout<<"Elige una opcion:"<<endl;
	cout<<"\n";
    cout << ">> 1. Renault" << endl;
    cout << ">> 2. Bugatti" << endl; //p.d el fundador es italiano
    cin>>opcion5;
    }
   system("cls");

//-----------------*---------------------*------------------------*--------------------------*-------------------------*---------------------------*	
  
	if(opcion1 == 1){
    cout<<"//////////VEHICULOS AMERICANOS//////////"<<endl;
    cout<<"\n";
	cout<<"Elige una opcion:"<<endl;
	cout<<"\n";
    cout << ">> 1. Ford-150" << endl;
    cout << ">> 2. Ford Mustang Boss 429" << endl;
    cin>>opcion10;
    }else if(opcion1 == 2){
    cout<<"//////////VEHICULOS AMERICANOS//////////"<<endl;
    cout<<"\n";
	cout<<"Elige una opcion:"<<endl;
	cout<<"\n";
    cout << ">> 1. Corvette" << endl;
    cout << ">> 2. Camaro" << endl;
	cin>>opcion11;	
	}
	
	system("cls"); 
	
//-----------------*---------------------*------------------------*--------------------------*-------------------------*---------------------------*		

	if(opcion2 == 1){
    cout<<"//////////VEHICULOS ITALIANOS//////////"<<endl;
    cout<<"\n";
	cout<<"Elige una opcion:"<<endl;
	cout<<"\n";		
    cout << ">> 1. Ferrari 250 GTO" << endl; //Ferrari
    cout << ">> 2. Ferrari F40" << endl;	
    cin>>opcion12;	
    }else if(opcion2 == 2){
    cout<<"//////////VEHICULOS ITALIANOS//////////"<<endl;
    cout<<"\n";	
    cout<<"Elige una opcion:"<<endl;
	cout<<"\n";
    cout << ">> 1. Lamborghini Miura" << endl; //Lamborghini
    cout << ">> 2. Lamborghini Countach" << endl;
	cin>>opcion13;	
	}	
    system("cls"); 
    
//-----------------*---------------------*------------------------*--------------------------*-------------------------*---------------------------*		

	if(opcion3 == 1){
    cout<<"//////////VEHICULOS JAPONESES//////////"<<endl;
    cout<<"\n";
	cout<<"Elige una opcion:"<<endl;
	cout<<"\n";		
    cout << ">> 1. Toyota Supra" << endl; //Ferrari
    cout << ">> 2. Toyota Corolla AE86" << endl;	
    cin>>opcion14;	
    }else if(opcion3 == 2){
    cout<<"//////////VEHICULOS JAPONESES//////////"<<endl;
    cout<<"\n";	
    cout<<"Elige una opcion:"<<endl;
	cout<<"\n";
    cout << ">> 1. Mazda RX7" << endl; //Lamborghini
    cout << ">> 2. Mazda MX-5" << endl;
	cin>>opcion15;	
	}	
    system("cls"); 
    	
//-----------------*---------------------*------------------------*--------------------------*-------------------------*---------------------------*		

	if(opcion4 == 1){
    cout<<"//////////VEHICULOS ALEMANES//////////"<<endl;
    cout<<"\n";
	cout<<"Elige una opcion:"<<endl;
	cout<<"\n";		
    cout << ">> 1. BMW CSL" << endl; // BMW
    cout << ">> 2. BMW 507" << endl;	
    cin>>opcion16;	
    }else if(opcion4 == 2){
    cout<<"//////////VEHICULOS ALEMANES//////////"<<endl;
    cout<<"\n";	
    cout<<"Elige una opcion:"<<endl;
	cout<<"\n";
    cout << ">> 1. Audi R8" << endl; //AUDI
    cout << ">> 2. Audi Quattro" << endl;
	cin>>opcion17;	
	}	
    system("cls"); 
    
//-----------------*---------------------*------------------------*--------------------------*-------------------------*---------------------------*		
  
	if(opcion5 == 1){
    cout<<"//////////VEHICULOS FRANCESES//////////"<<endl;
    cout<<"\n";
	cout<<"Elige una opcion:"<<endl;
	cout<<"\n";		
    cout << ">> 1. Renault 4" << endl; //Renault
    cout << ">> 2. Renault 5" << endl;	
    cin>>opcion18;	
    }else if(opcion5 == 2){
    cout<<"//////////VEHICULOS FRANCESES//////////"<<endl;
    cout<<"\n";	
    cout<<"Elige una opcion:"<<endl;
	cout<<"\n";
    cout << ">> 1. Bugatti Type 57 SC Atrantic" << endl; //Bugatti
    cout << ">> 2. Bugatti Veyron" << endl;
	cin>>opcion19;	
	}	
    system("cls"); 
    	
//-----------------*---------------------*------------------------*--------------------------*-------------------------*---------------------------*		
   
}
    






