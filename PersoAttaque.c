Attack Attackbuilder(int num) {
	Attack att;
	switch(num) { // attaque normale (0-99) ; attaque speciale (100-199) ; attaque unique (200-299)
        case 0:
		att.damage=0;
		att.focusdamage=50;
		att.heal=0;
		att.focusheal=0;
		att.poison=0;
		att.stun=0;
		att.confused=0;
		att.name=malloc(sizeof(char)*12);
		if(att.name==NULL) {
			exit(1);
		}
		strcpy(att.name, "Coup Simple");
		break;
	case 1:
		att.damage=0;
		att.focusdamage=30;
		att.heal=0;
		att.focusheal=0;
		att.poison=1;
		att.stun=0;
		att.confused=0;
		att.name=malloc(sizeof(char)*16);
		if(att.name==NULL) {
			exit(1);
		}
		strcpy(att.name, "Coup Empoisonne");
		break;
	case 2:
		att.damage=0;
		att.focusdamage=0;
		att.heal=0;
		att.focusheal=30;
		att.poison=0;
		att.stun=0;
		att.confused=0;
		att.name=malloc(sizeof(char)*12);
		if(att.name==NULL) {
			exit(1);
		}
		strcpy(att.name, "Soin simple");
		break;
		
        case 3:
		att.damage=0;
		att.focusdamage=35;
		att.heal=0;
		att.focusheal=0;
		att.poison=0;
		att.stun=1;
		att.confused=0;
		att.name=malloc(sizeof(char)*19);
		if(att.name==NULL) {
			exit(1);
		}
		strcpy(att.name, "Frappe du Destrier");
		break;

	case 4:
		att.damage=0;
		att.focusdamage=40;
		att.heal=0;
		att.focusheal=0;
		att.poison=0;
		att.stun=0;
		att.confused=0;
		att.name=malloc(sizeof(char)*16);
		if(att.name==NULL) {
			exit(1);
		}
		strcpy(att.name, "Orbe Arcanique");
		break;
		
	case 5:
		att.damage=0;
		att.focusdamage=35;
		att.heal=0;
		att.focusheal=0;
		att.poison=0;
		att.stun=0;
		att.confused=0;
		att.name=malloc(sizeof(char)*19);
		if(att.name==NULL) {
			exit(1);
		}
		strcpy(att.name, "Couteau de l’Ombre");
		break;

	case 6:
		att.damage=0;
		att.focusdamage=25;
		att.heal=0;
		att.focusheal=0;
		att.poison=0;
		att.stun=0;
		att.confused=0;
		att.name=malloc(sizeof(char)*17);
		if(att.name==NULL) {
			exit(1);
		}
		strcpy(att.name, "Flèche Spectrale");
		break;

	case 7:
		att.damage=0;
		att.focusdamage=30;
		att.heal=0;
		att.focusheal=0;
		att.poison=0;
		att.stun=0;
		att.confused=0;
		att.name=malloc(sizeof(char)*14);
		if(att.name==NULL) {
			exit(1);
		}
		strcpy(att.name, "Flamme Vorace");
		break;


	case 8:
		att.damage=0;
		att.focusdamage=40;
		att.heal=0;
		att.focusheal=0;
		att.poison=0;
		att.stun=0;
		att.confused=1;
		att.name=malloc(sizeof(char)*12);
		if(att.name==NULL) {
			exit(1);
		}
		strcpy(att.name, "Rayon Sacré");
		break;


	case 9:
		att.damage=0;
		att.focusdamage=0;
		att.heal=0;
		att.focusheal=0;
		att.poison=0;
		att.stun=1;
		att.confused=1;
		att.name=malloc(sizeof(char)*12);
		if(att.name==NULL) {
			exit(1);
		}
		strcpy(att.name, "Reflet Trompeur");
		break;

	case 10:
		att.damage=0;
		att.focusdamage=10;
		att.heal=0;
		att.focusheal=0;
		att.poison=1;
		att.stun=0;
		att.confused=1;
		att.name=malloc(sizeof(char)*12);
		if(att.name==NULL) {
			exit(1);
		}
		strcpy(att.name, "Dague d’Ambre");
		break;
		
	case 100:
		att.damage=0;
		att.focusdamage=75;
		att.heal=0;
		att.focusheal=0;
		att.poison=0;
		att.stun=0;
		att.confused=0;
		att.name=malloc(sizeof(char)*12);
		if(att.name==NULL) {
			exit(1);
		}
		strcpy(att.name, "Coup double");
		break;
	case 101:
		att.damage=0;
		att.focusdamage=75;
		att.heal=0;
		att.focusheal=0;
		att.poison=0;
		att.stun=0;
		att.confused=0;
		att.name=malloc(sizeof(char)*19);
		if(att.name==NULL) {
			exit(1);
		}
		strcpy(att.name, "Coup double poison");
		break;
	case 102:
		att.damage=0;
		att.focusdamage=0;
		att.heal=25;
		att.focusheal=50;
		att.poison=0;
		att.stun=0;
		att.confused=0;
		att.name=malloc(sizeof(char)*12);
		if(att.name==NULL) {
			exit(1);
		}
		strcpy(att.name, "Soin double");
		break;
        
       case 103:
		att.damage=30;
		att.focusdamage=40;
		att.heal=0;
		att.focusheal=0;
		att.poison=0;
		att.stun=1;
		att.confused=0;
		att.name=malloc(sizeof(char)*14);
		if(att.name==NULL) {
			exit(1);
		}
		strcpy(att.name, "Mur de Lances");
		break;

	case 104:
		att.damage=0;
		att.focusdamage=0;
		att.heal=45;
		att.focusheal=0;
		att.poison=0;
		att.stun=1;
		att.confused=0;
		att.name=malloc(sizeof(char)*16);
		if(att.name==NULL) {
			exit(1);
		}
		strcpy(att.name, "Sceau du Savoir");
		break;

	case 105:
		att.damage=0;
		att.focusdamage=30;
		att.heal=0;
		att.focusheal=0;
		att.poison=1;
		att.stun=1;
		att.confused=0;
		att.name=malloc(sizeof(char)*15);
		if(att.name==NULL) {
			exit(1);
		}
		strcpy(att.name, "Voile Nocturne");
		break;

	case 106:
		att.damage=0;
		att.focusdamage=20;
		att.heal=0;
		att.focusheal=0;
		att.poison=1;
		att.stun=1;
		att.confused=1;
		att.name=malloc(sizeof(char)*15);
		if(att.name==NULL) {
			exit(1);
		}
		strcpy(att.name, "Piège Sylvestre");
		break;
		
	case 107:
		att.damage=0;
		att.focusdamage=55;
		att.heal=0;
		att.focusheal=0;
		att.poison=1;
		att.stun=1;
		att.confused=1;
		att.name=malloc(sizeof(char)*15);
		if(att.name==NULL) {
			exit(1);
		}
		strcpy(att.name, "Souffle Cendré");
		break;


	case 108:
		att.damage=0;
		att.focusdamage=0;
		att.heal=10;
		att.focusheal=60;
		att.poison=1;
		att.stun=1;
		att.confused=1;
		att.name=malloc(sizeof(char)*22);
		if(att.name==NULL) {
			exit(1);
		}
		strcpy(att.name, "Bénédiction de l’Aube");
		break;


	case 109:
		att.damage=0;
		att.focusdamage=20;
		att.heal=0;
		att.focusheal=0;
		att.poison=0;
		att.stun=1;
		att.confused=1;
		att.name=malloc(sizeof(char)*17);
		if(att.name==NULL) {
			exit(1);
		}
		strcpy(att.name, "Brume Hypnotique");
		break;

	case 110:
		att.damage=15;
		att.focusdamage=60;
		att.heal=0;
		att.focusheal=0;
		att.poison=0;
		att.stun=0;
		att.confused=1;
		att.name=malloc(sizeof(char)*16);
		if(att.name==NULL) {
			exit(1);
		}
		strcpy(att.name, "Main des Morts");
		break;

		
	case 200:
		att.damage=0;
		att.focusdamage=150;
		att.heal=0;
		att.focusheal=0;
		att.poison=0;
		att.stun=0;
		att.confused=0;
		att.name=malloc(sizeof(char)*12);
		if(att.name==NULL) {
			exit(1);
		}
		strcpy(att.name, "Coup triple");
		break;

		
    case 201:
        att.damage=0;
        att.focusdamage=100;
        att.heal=0;
        att.focusheal=0;
        att.poison=0;
        att.stun=0;
        att.confused=0;
        att.name=malloc(sizeof(char)*19);
        if(att.name==NULL){ 
            exit(1);
        }
        strcpy(att.name, "Coup triple poison");
        break;

		
    case 202:
		att.damage=0;
		att.focusdamage=0;
		att.heal=30;
		att.focusheal=75;
		att.poison=0;
		att.stun=0;
		att.confused=0;
		att.name=malloc(sizeof(char)*12);
		if(att.name==NULL) {
			exit(1);
		}
		strcpy(att.name, "Soin triple");
		break;

		
     case 203:
		att.damage=0;
		att.focusdamage=110;
		att.heal=0;
		att.focusheal=0;
		att.poison=0;
		att.stun=1;
		att.confused=0;
		att.name=malloc(sizeof(char)*17);
		if(att.name==NULL) {
			exit(1);
		}
		strcpy(att.name, "Jugement d’Acier");
		break;
		

	case 204:
		att.damage=0;
		att.focusdamage=80;
		att.heal=0;
		att.focusheal=0;
		att.poison=1;
		att.stun=0;
		att.confused=1;
		att.name=malloc(sizeof(char)*17);
		if(att.name==NULL) {
			exit(1);
		}
		strcpy(att.name, "Tempête des Éons");
		break;
		

	case 205:
		att.damage=0;
		att.focusdamage=100;
		att.heal=0;
		att.focusheal=0;
		att.poison=0;
		att.stun=1;
		att.confused=1;
		att.name=malloc(sizeof(char)*16);
		if(att.name==NULL) {
			exit(1);
		}
		strcpy(att.name, "Danse des Lames");
		break;


	case 206:
		att.damage=90;
		att.focusdamage=0;
		att.heal=0;
		att.focusheal=0;
		att.poison=0;
		att.stun=0;
		att.confused=0;
		att.name=malloc(sizeof(char)*15);
		if(att.name==NULL) {
			exit(1);
		}
		strcpy(att.name, "Œil du Faucon");
		break;

	case 207:
		att.damage=10;
		att.focusdamage=105;
		att.heal=0;
		att.focusheal=0;
		att.poison=0;
		att.stun=0;
		att.confused=0;
		att.name=malloc(sizeof(char)*15);
		if(att.name==NULL) {
			exit(1);
		}
		strcpy(att.name, "Comète Ardente");
		break;


	case 208:
		att.damage=0;
		att.focusdamage=120;
		att.heal=0;
		att.focusheal=0;
		att.poison=0;
		att.stun=1;
		att.confused=0;
		att.name=malloc(sizeof(char)*15);
		if(att.name==NULL) {
			exit(1);
		}
		strcpy(att.name, "Jugement Divin");
		break;

	case 209:
		att.damage=0;
		att.focusdamage=110;
		att.heal=0;
		att.focusheal=0;
		att.poison=0;
		att.stun=1;
		att.confused=0;
		att.name=malloc(sizeof(char)*15);
		if(att.name==NULL) {
			exit(1);
		}
		strcpy(att.name, "Cauchemar Réel");
		break;


	case 210:
		att.damage=0;
		att.focusdamage=100;
		att.heal=0;
		att.focusheal=0;
		att.poison=1;
		att.stun=1;
		att.confused=1;
		att.name=malloc(sizeof(char)*16);
		if(att.name==NULL) {
			exit(1);
		}
		strcpy(att.name, "Marque du Néant");
		break;


	
	 default:
		printf("ERREUR: Mauvais numero saisie pour le switchcase Attackbuilder\n");
		exit(1);
	}
	return att;
}
