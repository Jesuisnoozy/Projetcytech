Attack Attackbuilder(int num) {
	Attack att;
	switch(num) { // attaque normale (0-99) ; attaque spC)ciale (100-199) ; attaque normale (200-299)
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
	 default:
		printf("ERREUR: Mauvais numero saisie pour le switchcase Attackbuilder\n");
		exit(1);
	}
	return att;
}
