#  STATEMENTS / CONSIGNAS tps_laboratorio_1
-------------------------------------------------ENG-------------------------------------------------------

Statement of TP 1:

We must form a team to compete in the next World Cup.
The formation of the starting team will be 1-4-4-2 (goalkeeper, defenders, midfielders and
front).
Keep in mind that we cannot exceed the maximum number of 22 players and
no more than two per position, that is, in total we should have 2 archers, 8 defenders,
8 midfielders and 4 forwards (taking starters and substitutes into account).
Campus will have a maintenance cost, which will be composed of:
Transportation, Lodging and Food Expenses. The user shall bear all expenses.
Note: from these 3 values the maintenance expense arises.
Players can develop their activities in any of the 6 confederations:
AFC in Asia; CAF in Africa; CONCACAF in the North zone; CONMEBOL in South America;
UEFA in Europe; OFC in Oceania.
The composition of the menu will be:
1. Income of maintenance costs.
Note: The user will be able to choose which expense he wishes to enter.
The program must report the amount of each expense that has been charged so far:  Lodging cost -> $0
 Cost of food -> $0
 Transportation cost -> $0
2. Loading of players:
Note: At the time of data loading we must enter the jersey number, position,
confederation in which he is playing.
The user will be able to choose which position he wishes to enter.
The program must report the number of players in each position that has been loaded up to
the moment:
 Archers -> 0
 Defenders -> 0
 Midfielders -> 0
Forwards -> 0
3. Perform all calculations.
Note: in this section only the values of the requested data will be calculated, they should NOT be
print, just inform that the following calculations were carried out correctly:
to. Calculate the average number of players in each market.
b. Calculate the cost of maintenance.
c. If the majority of the squad is made up of players from the European confederation, the cost
maintenance receives a 35% increase.
4. Report all results.
Note: All the data calculated in the previous point must be printed and if the cost of
received an increase, the original value must be reported, the value of the increase
and the updated value with the added increase.
5. Exit.

Statement of TP 2:

FIFA requires a program that manages the players of each confederation of
soccer. At the moment there are only 6 confederations and it is known that the list of players
associated with FIFA cannot exceed 3000 players.
The system should have the following menu options:
1. PLAYER REGISTRATION: A player must be allowed to enter, calculating automatically
the ID number. The rest of the fields will be requested from the user, when entering
the confederation, the complete list of available confederations should be displayed and
your choice will be by id number.
*Note: the player id must be auto-incremental, unique and autonomous, that is, not
must not depend on the position of an array nor be calculated based on finding the largest id
that has a player inside the array.
2. PLAYER REMOVAL: The complete list of players must be displayed (ordered by
ID) with all your data and you can choose one by entering the Id Number and
will remove the player from the system.
3. PLAYER MODIFICATION: The complete list of players should be displayed
(ordered by ID) with all your data and you can choose one by entering the Number of
Id, allowing to modify: name, position, jersey number, confederation,
salary, years of contract.
This process must have its own menu allowing you to choose which field you want
Modify.
4. REPORTS:
★ List of players ordered alphabetically by name
confederation and player name. (It is ordering by double criteria, it is
ordered by name of the confederation and in case of equality it is ordered by
Player's name).
★ List of confederations with their players.
★ Total and average of all salaries and how many players earn more than
average salary.
★ Inform the confederation with the greatest number of years of total contracts.
★ Report percentage of players for each confederation.
★ Inform which is the region with the most players and the list of them.
This process must have its own menu allowing you to choose which report you want to see.
5. EXIT: The user must be asked for confirmation before closing the program.

Statement of TP 3:

FIFA requires a program that manages the players of the 32 National Teams of
football that will participate in the Qatar 2022 World Cup. Each team cannot exceed 22 players called up.
For this task, a solution must be developed using the functions of the
LinkedList library. The entities that represent the player and the
selection with all its associated data in such a way that they allow
interact with the already defined structures.
The system should have the following menu options:
1. LOADING FILES: The .csv files of players and selections must be read
2. PLAYER REGISTRATION: A player must be allowed to enter, calculating automatically
the number of Id, the id of the selection must remain at 0. The rest of the fields will be
will prompt the user.
Note: the player id must be auto-incremental, unique, autonomous and must persist, that is
This means that its value should not be reset every time the execution of the program is restarted.
program, it must not depend on the position of an array/list or be calculated based on
search for the largest id that a player has within the array/list. The first available id
for manual loading it is the 371.
3. PLAYER MODIFICATION: The complete list of players with
all your data and you can choose one, allowing you to modify only: name,
age, position, nationality.
This process must have its own menu allowing you to choose which field you want
Modify.
4. PLAYER REMOVAL: The complete list of players must be shown with all their
data, you can choose one and the player will be removed from the system.
Note: if the player to be dropped was summoned to a NATIONAL TEAM, in said NATIONAL TEAM
the summons counter must be decreased by 1.
5. LISTINGS:
TO ALL PLAYERS.
B) ALL THE NATIONAL TEAMS.
C) CALLED PLAYERS (only).
This process must have its own menu allowing you to choose which list you want to see.
6. SUMMON PLAYERS:
A) SUMMON: as long as the player is not summoned in another team and the
selection to which it will be summoned has not reached the maximum amount of
summoned, the player must be associated with the id of the selection and in said selection
the summons counter must be increased by 1. At the moment of having to
choose which data to enter a list with the available options should be displayed
B) REMOVE FROM THE NATIONAL TEAM: The list of summoned players must be shown,
You can choose one, the selection id will be set to 0, leaving the player available
for a new call and the called counter must be decreased by 1
of said selection.
7. SORT AND LIST:
A) PLAYERS BY NATIONALITY.
B) TEAMS BY CONFEDERATION.
C) PLAYERS BY AGE.
D) PLAYERS BY NAME.
This process must have its own menu allowing to choose by which criteria the
would you like to order.
8. GENERATE BINARY FILE: Generate and save in binary a new list that
contains the players summoned from a confederation entered by the user.
9. LOAD BINARY FILE: The data of the generated file must be read and printed
at point 8.
10. SAVE .CSV FILES: All the files must be saved in their respective files.
Changes made to players and teams.
11. EXIT: Ends the execution of the program after user confirmation, if
changes were made to the files and these were not saved should be reported
before allowing exit.

-------------------------------------------------ESP-------------------------------------------------------

Enunciado de TP 1:

Debemos conformar un equipo para competir en el próximo mundial.
La formación del equipo titular será 1-4-4-2 (arquero, defensores, mediocampistas y
delanteros).
Hay que tener presente que no podemos superar la cantidad máxima de 22 jugadores y
no más de dos por posición, es decir, en total deberíamos tener 2 arqueros, 8 defensores,
8 mediocampistas y 4 delanteros (teniendo en cuenta titulares y suplentes).
Dicho plantel contara con un costo de mantenimiento, que va a estar compuesto por:
Gastos de Transporte, Hospedaje y Comida. El usuario deberá cargar todos los gastos.
Nota: de estos 3 valores surge el gasto de mantenimiento.
Los jugadores pueden desarrollar sus actividades en cualquiera de las 6 confederaciones:
AFC en Asia; CAF en África; CONCACAF en zona del Norte; CONMEBOL en Sudamérica;
UEFA en Europa; OFC en Oceanía.

La composición del menú será:
1. Ingreso de los costos de Mantenimiento.
Nota: El usuario podrá elegir qué gasto desea ingresar.
El programa deberá informar el monto de cada gasto que se haya cargado hasta el momento:  Costo de hospedaje -> $0
 Costo de comida -> $0
 Costo de transporte -> $0
2. Carga de jugadores:
Nota: Al momento de la carga de datos debemos ingresar número de camiseta, posición,
confederación en la que está jugando.
El usuario podrá elegir qué posición desea ingresar.
El programa deberá informar la cantidad de jugadores en cada posición que se haya cargado hasta
el momento:
 Arqueros -> 0
 Defensores -> 0
 Mediocampistas -> 0
 Delanteros -> 0
3. Realizar todos los cálculos.
Nota: en esta sección solo se calcularan los valores de los datos solicitados, NO se deberán
imprimir, solo informar que se realizaron correctamente los siguientes caculos:
a. Calcular el promedio de jugadores de cada mercado.
b. Calcular el costo de mantenimiento.
c. Si la mayoría del plantel está compuesta por jugadores de la confederación europea el costo
de mantenimiento recibe un aumento del 35%.
4. Informar todos los resultados.
Nota: Se deberá imprimir todos los datos calculados en el punto anterior y si el costo de
mantenimiento recibió un aumento se debe informar el valor original, el valor del aumento
y el valor actualizado con el aumento agregado.
5. Salir.

Enunciado de TP 2:

La FIFA requiere un programa que administre los jugadores de cada confederación de
fútbol. Por el momento solo existen 6 confederaciones y se sabe que la lista de jugadores
asociados a la FIFA no puede sobrepasar los 3000 jugadores.
El sistema deberá tener el siguiente menú de opciones:
1. ALTA DE JUGADOR: Se debe permitir ingresar un jugador calculando automáticamente
el número de Id. El resto de los campos se le pedirá al usuario, al momento de ingresar
la confederación se deberá mostrar la lista completa de confederaciones disponibles y
su elección será mediante número de id.
*Nota: el id del jugador debe ser autoincremental , único y autónomo, es decir, no
debe depender de la posición de un array ni calcularse en base a buscar el mayor id
que tenga un jugador dentro del array.
2. BAJA DE JUGADOR: Se deberá mostrar la lista completa de jugadores (ordenada por
ID) con todos sus datos y se podrá elegir uno ingresando el Número de Id y se
eliminará el jugador del sistema.
3. MODIFICACIÓN DE JUGADOR: Se deberá mostrar la lista completa de jugadores
(ordenada por ID) con todos sus datos y se podrá elegir uno ingresando el Número de
Id, permitiendo modificar: nombre, posicion, numero de camiseta, confederación,
salario,años de contrato.
Este proceso debe contar con menú propio permitiendo elegir qué campo se desea
modificar.
4. INFORMES:
★ Listado de los jugadores ordenados alfabéticamente por nombre de
confederación y nombre de jugador. (Es ordenamiento por doble criterio, se
ordena por nombre de la confederación y en caso de igualdad se ordena por
nombre del jugador).
★ Listado de confederaciones con sus jugadores.
★ Total y promedio de todos los salarios y cuántos jugadores cobran más del
salario promedio.
★ Informar la confederación con mayor cantidad de años de contratos total.
★ Informar porcentaje de jugadores por cada confederación.
★ Informar cual es la región con más jugadores y el listado de los mismos.
Este proceso debe contar con menú propio permitiendo elegir qué informe se desea ver.
5. SALIR: Se deberá pedir confirmación al usuario antes de cerrar el programa.

Enunciado de TP 3:

La FIFA requiere un programa que administre los jugadores de las 32 Selecciones de
fútbol que participarán del mundial de Qatar 2022. Cada selección no puede superar los 22 jugadores convocados.
Para esta tarea se deberá desarrollar una solución utilizando las funciones de la
biblioteca LinkedList. Se deberán modelar las entidades que representan al jugador y la
selección con todos sus datos asociados de tal manera que las mismas permitan
interactuar con las estructuras ya definidas.
El sistema deberá tener el siguiente menú de opciones:
1. CARGA DE ARCHIVOS: Se deben leer los archivos .csv de jugadores y selecciones
2. ALTA DE JUGADOR: Se debe permitir ingresar un jugador calculando automáticamente
el número de Id, el id de la selección debe quedar en 0. El resto de los campos se le
pedirá al usuario.
Nota: el id del jugador debe ser autoincremental, único, autónomo y debe persistir, es
decir, que su valor no debe reiniciarse cada vez que se reinicie la ejecución del
programa, no debe depender de la posición de un array/lista ni calcularse en base a
buscar el mayor id que tenga un jugador dentro del array/lista. El primer id disponible
para la carga manual es el 371.
3. MODIFICACIÓN DE JUGADOR: Se deberá mostrar la lista completa de jugadores con
todos sus datos y se podrá elegir uno, permitiendo modificar solamente: nombre,
edad, posición, nacionalidad.
Este proceso debe contar con menú propio permitiendo elegir qué campo se desea
modificar.
4. BAJA DE JUGADOR: Se deberá mostrar la lista completa de jugadores con todos sus
datos, se podrá elegir uno y se eliminará el jugador del sistema.
Nota: si el jugador a dar de baja estaba convocado a una selección, en dicha selección
se debe disminuir en 1 el contador de convocados.
5. LISTADOS:
A) TODOS LOS JUGADORES.
B) TODAS LAS SELECCIONES.
C) JUGADORES CONVOCADOS (únicamente).
Este proceso debe contar con menú propio permitiendo elegir qué listado se desea ver.
6. CONVOCAR JUGADORES:
A) CONVOCAR: siempre y cuando el jugador no esté convocado en otra selección y la
selección a donde será convocado no haya llegado a la cantidad máxima de
convocados, se deberá asociar al jugador el id de la selección y en dicha selección
se deberá aumentar el contador de convocados en 1. Al momento de tener que
elegir qué dato ingresar se deberá mostrar un listado con las opciones disponibles.
B) QUITAR DE LA SELECCIÓN: Se deberá mostrar el listado de jugadores convocados,
se podrá elegir uno, se pondrá el id de selección en 0 dejando al jugador disponible
para una nueva convocatoria y se deberá disminuir en 1 el contador de convocados
de dicha selección.
7. ORDENAR Y LISTAR:
A) JUGADORES POR NACIONALIDAD.
B) SELECCIONES POR CONFEDERACIÓN.
C) JUGADORES POR EDAD.
D) JUGADORES POR NOMBRE.
Este proceso debe contar con menú propio permitiendo elegir por cuál criterio se
desea ordenar.
8. GENERAR ARCHIVO BINARIO: Generar y guardar en binario una nueva lista que
contenga los jugadores convocados de una confederación ingresada por el usuario.
9. CARGAR ARCHIVO BINARIO: Se deberá leer e imprimir los datos del archivo generado
en el punto 8.
10. GUARDAR ARCHIVOS .CSV: Se deberá guardar en sus respectivos archivos todos los
cambios realizados en jugadores y selecciones.
11. SALIR: Termina la ejecución del programa previa confirmación del usuario, si se
realizaron cambios en los archivos y estos no fueron guardados debería informarse
antes de permitir la salida.
