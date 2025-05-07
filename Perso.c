ot Characterbuilder(int num) {
	Bot a;
	switch(num) {
	// defence, agilite, points de vie, att normale, att speciale, att unique)
	case 1:
		a=Builder(25, 5, 200, 0, 100, 200);
		a.name=malloc(sizeof(char)*4);
		if(a.name==NULL) {
			exit(1);
		}
		strcpy(a.name, "Bob");
		break;
	case 1000:
		a=Builder(5, 50, 150, 0, 100, 200);
		a.name=malloc(sizeof(char)*5);
		if(a.name==NULL) {
			exit(1);
		}
		strcpy(a.name, "Test");
		break;
	case 1001:
		a=Builder(5, 50, 150, 1, 101, 201);
		a.name=malloc(sizeof(char)*11);
		if(a.name==NULL) {
			exit(1);
		}
		strcpy(a.name, "TestPoison");
		break;
	case 1002:
		a=Builder(5, 50, 150, 2, 102, 202);
		a.name=malloc(sizeof(char)*14);
		if(a.name==NULL) {
			exit(1);
		}
		strcpy(a.name, "TestMaxHealth");
		break;
	default:
		printf("ERREUR: Mauvais numC)ro saisie pour le switchcase Characterbuilder\n");
		exit(1);
	}
	return a;
}
