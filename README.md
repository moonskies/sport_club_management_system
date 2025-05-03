scrieti aici ce alte modificari credeti ca r fi bune


----------------------------------------------
29 april -cata

DOMAIN
User  
// ID_user, vector<int> IDS_field, vector<int> IDS_equipment
// get_id_user, get_field_user, get_equipment_user

Field 
//ID_field, type_field, condition_field, max_players_field 
// get_id_field, get_type_field, get_condition_field
Equipment 
//ID_equipment, type_equipment, condition_equipmnent
// get_id_equipment, get_type_equipment, get_condition_equipmnent, get_quantity_equipment

REPO
User_repository   
// vector<User>
//
Field_repository 
// vector<Field>
//
Equipment_repository 
// vector<Equipment>
// 

CONTROLLER

User_controller
// user
// add_user, field_reservation, equipment_reservation
Field_controller
// field
// get_field_table 
Equipment_controller
//equipment
//equipment_table

UI

1. rezervare teren
// userul alege un tip de teren. o sa i se asigneze un teren de acel tip cu un anumit ID

//optional alege daca meciul e privat sau nu, adica daca se mai pot inscrie si alti jucatori
//optional daca e privat sa spectatezi meciul ar costa X lei.
2. rezervare echipament
// trebuie sa verificam daca ID_user a rezervat un teren inainte.
// alege tipul echipamentului alege n bucati. i se asigneaza n bucati echipament cu n id uri diferite.

3. cauta un meci
//optional userul poate sa inscrie la un meci sa joace, daca meciul este public
//optional scriem cate locuri mai sunt disponibile
4. spectateaza un meci
//optional poti spectata pe gratis un meci public, sau pe bani un meci privat.
//optional scriem cati specatori is deja
 





(polimorfism intrefield si equipment)

plus alte chestii
daca field-ul nu e ocupat ID_user e zero
-----------------------------------------------

