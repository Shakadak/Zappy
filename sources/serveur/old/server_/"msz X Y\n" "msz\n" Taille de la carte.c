
//fonctions:
"pex #n\n" - Un joueur expulse.
"pbc #n M\n" Un joueur fait un broadcast.
"pic X Y L #n #n …\n" - Premier joueur lance l’incantation pour tous les 
suivants sur la case. 
"pfk #n\n" - Le joueur pond un œuf. 
"enw #e #n X Y\n" - L’œuf a été pondu sur la case par le joueur. 
"pdr #n i\n" - Le joueur jette une ressource. 
"pgt #n i\n" - Le joueur prend une ressource. 

//automation:
"bct X Y q q q q q q q\n" "bct X Y\n" Contenu d’une case de la carte. 
//"bct X Y q q q q q q q\n" * nbr_cases "mct\n" Contenu de la carte (toutes les cases). 
"ppo #n X Y O\n" "ppo #n\n" Position d’un joueur. 
"plv #n L\n" "plv #n\n" Niveau d’un joueur. 
"pin #n X Y q q q q q q q\n" "pin #n\n" Inventaire d’un joueur. 
"pdi #n\n" - Le joueur est mort de faim. 
"eht #e\n" - L’œuf éclot.
"ebo #e\n" - Un joueur s’est connecté pour l’œuf. 
"edi #e\n" - L’œuf éclos est mort de faim. 
"seg N\n" - Fin du jeu. L’équipe donnée remporte la partie. 
"smg M\n" - Message du serveur. 
"sbp\n" - Mauvais paramètres pour la commande. 

//echange
"sgt T\n" "sgt\n" Demande de l’unité de temps courante sur le 
serveur. 
"sgt T\n" "sst T\n" Modification de l’unité de temps sur le serveur. 

//initialisation:
"msz X Y\n" "msz\n" Taille de la carte. 
"tna N\n" * nbr_equipes "tna\n" Nom des équipes. 
"bct X Y q q q q q q q\n" "bct X Y\n" Contenu d’une case de la carte. 


//connect "pnw #n X Y O L N\n" - Connexion d’un nouveau joueur. 
