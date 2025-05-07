ot Characterbuilder(int num) {
	Bot a;
	switch(num) {
	// defence, agilite, points de vie, att normale, att speciale, att unique)
	case 1:
		a=Builder(25, 5, 200, 0, 100, 200);
		a.name=malloc(sizeof(char)*9);
		if(a.name==NULL) {
			exit(1);
		}
		strcpy(a.name, "Forgeron");
		break;// très bonne défense
	case 2:
		a=Builder(75, 25, 120, 0, 100, 200);
		a.name=malloc(sizeof(char)*7);
		if(a.name==NULL) {
			exit(1);
		}
		strcpy(a.name, " Oracle);
		break;// très bonne agilité

	case 3:
		a=Builder(45, 50, 225, 0, 100, 200);
		a.name=malloc(sizeof(char)*9);
		if(a.name==NULL) {
			exit(1);
		}
		strcpy(a.name, "Magicien ");
		break;// haut taux de PV
		
        case 4:
		a=Builder(2, 50, 240, 0, 100, 200);
		a.name=malloc(sizeof(char)*7);
		if(a.name==NULL) {
			exit(1);
		}
		strcpy(a.name, "Rôdeur");
		break;// Tout++ car trop d'aura enfaite
	case 5:
		a=Builder(80, 35, 180, 0, 100, 200);
		a.name=malloc(sizeof(char)*13);
		if(a.name==NULL) {
			exit(1);
		}
		strcpy(a.name, "Nécromancien");
		break;// PV/agilité+

	case 6:
		a=Builder(30, 40, 200, 0, 100, 200);
		a.name=malloc(sizeof(char)*6);
		if(a.name==NULL) {
			exit(1);
		}
		strcpy(a.name, "Clerc");
		break;// PV++

	case 7:
		a=Builder(0, 50, 100, 0, 100, 200);
		a.name=malloc(sizeof(char)*14);
		if(a.name==NULL) {
			exit(1);
		}
		strcpy(a.name, "Illusionniste");
		break;//  défense/agilité++



	case 8:
		a=Builder(90, 10, 190, 0, 100, 200);
		a.name=malloc(sizeof(char)*7);
		if(a.name==NULL) {
			exit(1);
		}
		strcpy(a.name, "Druide);
		break;
		
	case 9:
		a=Builder(5, 30, 135, 0, 100, 200);
		a.name=malloc(sizeof(char)*11);
		if(a.name==NULL) {
			exit(1);
		}
		strcpy(a.name, "Invocateur");
		break;

	case 10:
		a=Builder(5, 45, 225, 0, 100, 200);
		a.name=malloc(sizeof(char)*9);
		if(a.name==NULL) {
			exit(1);
		}
		strcpy(a.name, "Champion");
		break;

	case 11:
		a=Builder(66, 37, 111, 0, 100, 200);
		a.name=malloc(sizeof(char)*11);
		if(a.name==NULL) {
			exit(1);
		}
		strcpy(a.name, "Explorateur");
		break;

	case 12:
		a=Builder(100, 39, 168, 0, 100, 200);
		a.name=malloc(sizeof(char)*14);
		if(a.name==NULL) {
			exit(1);
		}
		strcpy(a.name, "Chronomancien");
		break;

	case 13:
		a=Builder(15, 30, 175, 0, 100, 200);
		a.name=malloc(sizeof(char)*9);
		if(a.name==NULL) {
			exit(1);
		}
		strcpy(a.name, "Assassin");
		break;

	case 14:
		a=Builder(73, 18, 190, 0, 100, 200);
		a.name=malloc(sizeof(char)*5);
		if(a.name==NULL) {
			exit(1);
		}
		strcpy(a.name, "Juge");
		break;

	case 15:
		a=Builder(55, 34, 250, 0, 100, 200);
		a.name=malloc(sizeof(char)*13);
		if(a.name==NULL) {
			exit(1);
		}
		strcpy(a.name, "Empoisonneur");
		break;

	case 16:
		a=Builder(5, 0, 187, 0, 100, 200);
		a.name=malloc(sizeof(char)*11);
		if(a.name==NULL) {
			exit(1);
		}
		strcpy(a.name, "Sentinelle");
		break;

	
	default:
		printf("ERREUR: Mauvais numC)ro saisie pour le switchcase Characterbuilder\n");
		exit(1);
	}
	return a;
}
