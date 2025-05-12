#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <errno.h>
#include<unistd.h>
#define NAMESIZE 21
#define BUNNY 14

//Regular text
#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"

//Regular bold text
#define BBLK "\e[1;30m"
#define BRED "\e[1;31m"
#define BGRN "\e[1;32m"
#define BYEL "\e[1;33m"
#define BBLU "\e[1;34m"
#define BMAG "\e[1;35m"
#define BCYN "\e[1;36m"
#define BWHT "\e[1;37m"

//Regular underline text
#define UBLK "\e[4;30m"
#define URED "\e[4;31m"
#define UGRN "\e[4;32m"
#define UYEL "\e[4;33m"
#define UBLU "\e[4;34m"
#define UMAG "\e[4;35m"
#define UCYN "\e[4;36m"
#define UWHT "\e[4;37m"

//Regular background
#define BLKB "\e[40m"
#define REDB "\e[41m"
#define GRNB "\e[42m"
#define YELB "\e[43m"
#define BLUB "\e[44m"
#define MAGB "\e[45m"
#define CYNB "\e[46m"
#define WHTB "\e[47m"

//High intensty background
#define BLKHB "\e[0;100m"
#define REDHB "\e[0;101m"
#define GRNHB "\e[0;102m"
#define YELHB "\e[0;103m"
#define BLUHB "\e[0;104m"
#define MAGHB "\e[0;105m"
#define CYNHB "\e[0;106m"
#define WHTHB "\e[0;107m"

//High intensty text
#define HBLK "\e[0;90m"
#define HRED "\e[0;91m"
#define HGRN "\e[0;92m"
#define HYEL "\e[0;93m"
#define HBLU "\e[0;94m"
#define HMAG "\e[0;95m"
#define HCYN "\e[0;96m"
#define HWHT "\e[0;97m"

//Bold high intensity text
#define BHBLK "\e[1;90m"
#define BHRED "\e[1;91m"
#define BHGRN "\e[1;92m"
#define BHYEL "\e[1;93m"
#define BHBLU "\e[1;94m"
#define BHMAG "\e[1;95m"
#define BHCYN "\e[1;96m"
#define BHWHT "\e[1;97m"

//Reset
#define RESETT "\e[0m"
#define CRESET "\e[0m"
#define COLOR_RESET "\e[0m"

typedef struct {
	char *name;
	int damage, focusdamage, heal, focusheal, poison, stun, confused;
} Attack;

typedef struct {
	char *name;
	int agility, pvmax, stamina, poison, stun, confused, pv, dead, utiliunique, chosen;
	float defence;
	Attack normal, special, unique;
} Bot;


Attack Attackbuilder(int num) {
	Attack att;
	switch(num) { // attaque normal (0-99) ; attaque special (100-199) ; attaque unique (200-299)
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
		att.name=malloc(sizeof(char)*16);
		if(att.name==NULL) {
			exit(1);
		}
		strcpy(att.name, "Couteau Ombreux");
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
		strcpy(att.name, "FlC(che Spectrale");
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
		strcpy(att.name, "Rayon SacrC)");
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
		strcpy(att.name, "Dague Ambre");
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
		strcpy(att.name, "PiC(ge Sylvestre");
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
		strcpy(att.name, "Souffle CendrC)");
		break;


	case 108:
		att.damage=0;
		att.focusdamage=0;
		att.heal=10;
		att.focusheal=60;
		att.poison=1;
		att.stun=1;
		att.confused=1;
		att.name=malloc(sizeof(char)*20);
		if(att.name==NULL) {
			exit(1);
		}
		strcpy(att.name, "Benediction Aubeuse");
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
		if(att.name==NULL) {
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
		att.name=malloc(sizeof(char)*20);
		if(att.name==NULL) {
			exit(1);
		}
		strcpy(att.name, "Jugement en Acier");
		break;


	case 204:
		att.damage=0;
		att.focusdamage=80;
		att.heal=0;
		att.focusheal=0;
		att.poison=1;
		att.stun=0;
		att.confused=1;
		att.name=malloc(sizeof(char)*19);
		if(att.name==NULL) {
			exit(1);
		}
		strcpy(att.name, "Tempete des ombres");
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
		strcpy(att.name, "Oeil du Faucon");
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
		strcpy(att.name, "ComC(te Ardente");
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
		strcpy(att.name, "Cauchemar RC)el");
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
		strcpy(att.name, "Marque du NC)ant");
		break;

	default:
		printf("ERREUR: Mauvais numero saisie pour le switchcase Attackbuilder\n");
		exit(1);
	}
	return att;
}

Bot Builder(float defen, int agil, int health, int norm, int spec, int uniq, int chosen) {
	Bot a;
	a.defence=1-(defen/100);
	a.agility=agil;
	a.pvmax=health;
	a.normal=Attackbuilder(norm);
	a.special=Attackbuilder(spec);
	a.unique=Attackbuilder(uniq);
	a.pv=health;
	a.poison=0;
	a.stun=0;
	a.confused=0;
	a.stamina=2;
	a.dead=0;
	a.utiliunique=0;
	a.chosen=chosen;
	return a;
}

Bot Characterbuilder(int num) {
	Bot a;
	switch(num) {
	// defence, agility, points de vie, att normal, att special, att unique)
	case 1:
		a=Builder(25, 5, 200, 0, 100, 200, num);
		a.name=malloc(sizeof(char)*9);
		if(a.name==NULL) {
			exit(1);
		}
		strcpy(a.name, "Forgeron");
		break;// trC(s bonne dC)fense
	case 2:
		a=Builder(75, 25, 120, 0, 100, 200, num);
		a.name=malloc(sizeof(char)*7);
		if(a.name==NULL) {
			exit(1);
		}
		strcpy(a.name, "Oracle");
		break;// trC(s bonne agilitC)

	case 3:
		a=Builder(45, 50, 225, 0, 100, 200, num);
		a.name=malloc(sizeof(char)*9);
		if(a.name==NULL) {
			exit(1);
		}
		strcpy(a.name, "Magicien ");
		break;// haut taux de PV

	case 4:
		a=Builder(2, 50, 240, 0, 100, 200, num);
		a.name=malloc(sizeof(char)*7);
		if(a.name==NULL) {
			exit(1);
		}
		strcpy(a.name, "Raideur");
		break;// Tout++ car trop d'aura enfaite
	case 5:
		a=Builder(80, 35, 180, 5, 105, 209, num);
		a.name=malloc(sizeof(char)*13);
		if(a.name==NULL) {
			exit(1);
		}
		strcpy(a.name, "Necromancien");
		break;// PV/agilitC)+

	case 6:
		a=Builder(30, 40, 200, 0, 100, 200, num);
		a.name=malloc(sizeof(char)*6);
		if(a.name==NULL) {
			exit(1);
		}
		strcpy(a.name, "Clerc");
		break;// PV++

	case 7:
		a=Builder(0, 50, 100, 0, 100, 200, num);
		a.name=malloc(sizeof(char)*14);
		if(a.name==NULL) {
			exit(1);
		}
		strcpy(a.name, "Illusionniste");
		break;//  dC)fense/agilitC)++



	case 8:
		a=Builder(90, 10, 190, 0, 100, 200, num);
		a.name=malloc(sizeof(char)*7);
		if(a.name==NULL) {
			exit(1);
		}
		strcpy(a.name, "Druide");
		break;

	case 9:
		a=Builder(5, 30, 135, 0, 100, 200, num);
		a.name=malloc(sizeof(char)*11);
		if(a.name==NULL) {
			exit(1);
		}
		strcpy(a.name, "Invocateur");
		break;

	case 10:
		a=Builder(5, 45, 225, 0, 100, 200, num);
		a.name=malloc(sizeof(char)*9);
		if(a.name==NULL) {
			exit(1);
		}
		strcpy(a.name, "Champion");
		break;

	case 11:
		a=Builder(66, 37, 111, 0, 100, 200, num);
		a.name=malloc(sizeof(char)*11);
		if(a.name==NULL) {
			exit(1);
		}
		strcpy(a.name, "Explorateur");
		break;

	case 12:
		a=Builder(50, 39, 168, 0, 100, 200, num);
		a.name=malloc(sizeof(char)*14);
		if(a.name==NULL) {
			exit(1);
		}
		strcpy(a.name, "Chronomancien");
		break;

	case 13:
		a=Builder(15, 30, 175, 0, 100, 200, num);
		a.name=malloc(sizeof(char)*9);
		if(a.name==NULL) {
			exit(1);
		}
		strcpy(a.name, "Assassin");
		break;

	case 14:
		a=Builder(35, 18, 190, 0, 100, 200, num);
		a.name=malloc(sizeof(char)*5);
		if(a.name==NULL) {
			exit(1);
		}
		strcpy(a.name, "Juge");
		break;

	case 15:
		a=Builder(55, 34, 250, 0, 100, 200, num);
		a.name=malloc(sizeof(char)*13);
		if(a.name==NULL) {
			exit(1);
		}
		strcpy(a.name, "Empoisonneur");
		break;

	case 16:
		a=Builder(5, 0, 187, 0, 100, 200, num);
		a.name=malloc(sizeof(char)*11);
		if(a.name==NULL) {
			exit(1);
		}
		strcpy(a.name, "Sentinelle");
		break;

	case 1000:
		a=Builder(5.0, 0, 250, 0, 100, 200, num);
		a.name=malloc(sizeof(char)*5);
		if(a.name==NULL) {
			exit(1);
		}
		strcpy(a.name, "Test");
		break;
	case 1001:
		a=Builder(5.0, 5, 150, 1, 101, 201, num);
		a.name=malloc(sizeof(char)*11);
		if(a.name==NULL) {
			exit(1);
		}
		strcpy(a.name, "TestPoison");
		break;
	case 1002:
		a=Builder(5.0, 20, 150, 2, 102, 202, num);
		a.name=malloc(sizeof(char)*14);
		if(a.name==NULL) {
			exit(1);
		}
		strcpy(a.name, "TestMaxHealth");
		break;
	case 100:
		a=Builder(90.0, 100, 250, 0, 100, 200, num);
		a.name=malloc(sizeof(char)*10);
		if(a.name==NULL) {
			exit(1);
		}
		strcpy(a.name, "GOD");
		break;
	default:
		printf("ERREUR: Mauvais numero saisie pour le switchcase Characterbuilder\n");
		exit(1);
	}
	return a;
}

int MinMax(int *x, int a, int b, int c) {
	int max=-1000;
	if(a>max && a!=0) {
		max=a;
		*x=1;
	}
	if(b>max && b!=0) {
		max=b;
		*x=2;
	}
	if(c>max && c!=0) {
		max=c;
		*x=3;
	}
	if(max==-1000) {
		printf("ERREUR: variable 'max' pour le switchcase MinMax\n");
		exit(1);
	}
	return max;
}

int CheckPerso1(int choix, Bot *ja, Bot*jb, Bot *jc) {
	switch(choix) {
	case 1:
		if(ja->dead==1 || ja->stun==1) {
			return 1;
		} else {
			return 0;

		}
	case 2:
		if(jb->dead==1 || jb->stun==1) {
			return 1;
		} else {
			return 0;

		}
	case 3:
		if(jc->dead==1 || jc->stun==1) {
			return 1;
		} else {
			return 0;

		}
	default:
		return 1;
	}
}
int CheckPerso2(int choix, Bot *ja, Bot*jb, Bot *jc) {
	switch(choix) {
	case 1:
		if(ja->dead==1) {
			return 1;
		} else {
			return 0;

		}
	case 2:
		if(jb->dead==1) {
			return 1;
		} else {
			return 0;

		}
	case 3:
		if(jc->dead==1) {
			return 1;
		} else {
			return 0;

		}
	default:
		return 1;
	}
}

int CheckStamina(int choixP, int choixA, Bot *ja, Bot*jb, Bot *jc) {
	if(choixP==1) {
		switch(choixA) {
		case 1:
			if(ja->stamina<1) {
				return 1;
			} else {
				return 0;
			}
		case 2:
			if(ja->stamina<=7) {
				return 1;
			} else {
				return 0;
			}
		case 3:
			if(ja->utiliunique==1) {
				return 1;
			} else {
				return 0;
			}
		default:
			return 1;
		}
	} else if(choixP==2) {
		switch(choixA) {
		case 1:
			if(jb->stamina<1) {
				return 1;
			} else {
				return 0;
			}
		case 2:
			if(jb->stamina<=7) {
				return 1;
			} else {
				return 0;
			}
		case 3:
			if(jb->utiliunique==1) {
				return 1;
			} else {
				return 0;
			}
		default:
			return 1;
		}
	} else if(choixP==3) {
		switch(choixA) {
		case 1:
			if(jc->stamina<1) {
				return 1;
			} else {
				return 0;
			}
		case 2:
			if(jc->stamina<=7) {
				return 1;
			} else {
				return 0;
			}
		case 3:
			if(jc->utiliunique==1) {
				return 1;
			} else {
				return 0;
			}
		default:
			return 1;
		}
	} else {
		printf("ERREUR: saisie choixP fonction CheckStamina");
		exit(1);
	}
}

int Dodge(int choixD, Bot *ra, Bot *rb, Bot *rc) { // return 0 => dodged
	int x;
	x=rand()%101;
	switch(choixD) {
	case 1:
		if(x>ra->agility) {
			return 1;
		} else {
			return 0;
		}
		break;
	case 2:
		if(x>rb->agility) {
			return 1;
		} else {
			return 0;
		}
		break;
	case 3:
		if(x>rc->agility) {
			return 1;
		} else {
			return 0;
		}
		break;
	default:
		printf("ERREUR: Mauvais numero saisie pour le switchcase Dodge\n");
		exit(1);
	}
}

void Computer(int *dif, int *choixP, int *choixA, int *choixD, Bot *ra, Bot *rb, Bot *rc, Bot *ja, Bot *jb, Bot *jc) {
	int chance=rand()%101;
	int proba, wtf, wtp;  // \(^-^)/
	int aa=4;
	int ab=4;
	int ac=4;
	int x; // attaquant selectionne
	int y=MinMax(&x, ra->stamina, rb->stamina, rc->stamina); // Max stamina
	int z; // joueur vise
	int v=-MinMax(&z, -(ja->pv), -(jb->pv), -(jc->pv)); // Min pv joueur vise
	switch(*dif) {
	case 1:
		proba=100-60;
		break;
	case 2:
		proba=100-40;
		break;
	case 3:
		proba=100-20;
		break;
	default:
		printf("ERREUR: Variable (pointeur) *dif pour le switchcase Computer\n");
		exit(1);
	}
	if(chance>=proba || (ra->stamina==rb->stamina && ra->stamina==rc->stamina)) {
		do {
			*choixP=(rand()%3)+1;
		}
		while(CheckPerso1(*choixP, ra, rb, rc));

		do {
			*choixA=(rand()%3)+1;
		}
		while(CheckStamina(*choixP, *choixA, ra, rb, rc));

		do {
			*choixD=(rand()%3)+1;
		}
		while(CheckPerso2(*choixD, ja, jb, jc));

	} else {                 ///////
		if(ra->pv<=50 && ra->utiliunique!=1) {
			*choixP=1;
			*choixA=2;
			do {
				*choixD=(rand()%3)+1;
			}
			while(CheckPerso2(*choixD, ja, jb, jc));
		} else if(rb->pv<=50 && rb->utiliunique!=1) {
			*choixP=1;
			*choixA=2;
			do {
				*choixD=(rand()%3)+1;
			}
			while(CheckPerso2(*choixD, ja, jb, jc));
		} else if(rc->pv<=50 && rc->utiliunique!=1) {
			*choixP=1;
			*choixA=2;
			do {
				*choixD=(rand()%3)+1;
			}
			while(CheckPerso2(*choixD, ja, jb, jc));
		} else if(ra->pv<=50 && ra->stamina>=8) {
			*choixP=1;
			*choixA=2;
			do {
				*choixD=(rand()%3)+1;
			}
			while(CheckPerso2(*choixD, ja, jb, jc));
		} else if(rb->pv<=50 && rb->stamina>=8) {
			*choixP=1;
			*choixA=2;
			do {
				*choixD=(rand()%3)+1;
			}
			while(CheckPerso2(*choixD, ja, jb, jc));
		} else if(rc->pv<=50 && rc->stamina>=8) {
			*choixP=1;
			*choixA=2;
			do {
				*choixD=(rand()%3)+1;
			}
			while(CheckPerso2(*choixD, ja, jb, jc));
		} else if(z==1) {
			if(ja->pv<ra->normal.damage && ra->stamina>2) {
				aa=1;
			} else if(ja->pv<ra->special.damage && ra->stamina>7) {
				aa=2;
			} else {
				aa=3;
			}
			if(ja->pv<rb->normal.damage && rb->stamina>2) {
				ab=1;
			} else if(ja->pv<rb->special.damage && rb->stamina>7) {
				ab=2;
			} else {
				ab=3;
			}
			if(ja->pv<rc->normal.damage && rc->stamina>2) {
				ac=1;
			} else if(ja->pv<rc->special.damage && rc->stamina>7) {
				ac=2;
			} else {
				ac=3;
			}
			wtf=-MinMax(&wtp, -aa, -ab, -ac);
			if(wtf<3) {
				*choixP=wtp;
				*choixA=wtf;
				*choixD=z;
			} else {
				if(y>8 && x!=0) {
					if(x==1) {
						aa=2;
						ab=0;
						ac=0;
					} else if(x==2) {
						aa=0;
						ab=2;
						ac=0;
					} else {
						aa=0;
						ab=0;
						ac=2;
					}
					if(aa==2 && ab!=2 && ac!=2) {
						*choixP=1;
						*choixA=2;
						*choixD=z;
					} else if(aa!=2 && ab==2 && ac!=2) {
						*choixP=2;
						*choixA=2;
						*choixD=z;
					} else if(aa!=2 && ab!=2 && ac==2) {
						*choixP=3;
						*choixA=2;
						*choixD=z;
					} else if((aa==2 && ab==2) || (aa==2 && ac==2) || (aa==2 && ab==2 && ac==2)) {
						*choixP=1;
						*choixA=2;
						*choixD=z;
					} else {
						*choixP=2;
						*choixA=2;
						*choixD=z;
					}
				} else {
					*choixP=x;
					*choixA=1;
					*choixD=z;
				}
			}
		} else if(z==2) {
			if(jb->pv<ra->normal.damage && ra->stamina>2) {
				aa=1;
			} else if(jb->pv<ra->special.damage && ra->stamina>7) {
				aa=2;
			} else {
				aa=3;
			}
			if(jb->pv<rb->normal.damage && rb->stamina>2) {
				ab=1;
			} else if(jb->pv<rb->special.damage && rb->stamina>7) {
				ab=2;
			} else {
				ab=3;
			}
			if(jb->pv<rc->normal.damage && rc->stamina>2) {
				ac=1;
			} else if(jb->pv<rc->special.damage && rc->stamina>7) {
				ac=2;
			} else {
				ac=3;
			}
			wtf=-MinMax(&wtp, -aa, -ab, -ac);
			if(wtf<3) {
				*choixP=wtp;
				*choixA=wtf;
				*choixD=z;
			} else {
				if(y>8 && x!=0) {
					if(x==1) {
						aa=2;
						ab=0;
						ac=0;
					} else if(x==2) {
						aa=0;
						ab=2;
						ac=0;
					} else {
						aa=0;
						ab=0;
						ac=2;
					}
					if(aa==2 && ab!=2 && ac!=2) {
						*choixP=1;
						*choixA=2;
						*choixD=z;
					} else if(aa!=2 && ab==2 && ac!=2) {
						*choixP=2;
						*choixA=2;
						*choixD=z;
					} else if(aa!=2 && ab!=2 && ac==2) {
						*choixP=3;
						*choixA=2;
						*choixD=z;
					} else if((aa==2 && ab==2) || (aa==2 && ac==2) || (aa==2 && ab==2 && ac==2)) {
						*choixP=1;
						*choixA=2;
						*choixD=z;
					} else {
						*choixP=2;
						*choixA=2;
						*choixD=z;
					}
				} else {
					*choixP=x;
					*choixA=1;
					*choixD=z;
				}
			}
		} else {
			if(jc->pv<ra->normal.damage && ra->stamina>2) {
				aa=1;
			} else if(jc->pv<ra->special.damage && ra->stamina>7) {
				aa=2;
			} else {
				aa=3;
			}
			if(jc->pv<rb->normal.damage && rb->stamina>2) {
				ab=1;
			} else if(jc->pv<rb->special.damage && rb->stamina>7) {
				ab=2;
			} else {
				ab=3;
			}
			if(jc->pv<rc->normal.damage && rc->stamina>2) {
				ac=1;
			} else if(jc->pv<rc->special.damage && rc->stamina>7) {
				ac=2;
			} else {
				ac=3;
			}
			wtf=-MinMax(&wtp, -aa, -ab, -ac);
			if(wtf<3) {
				*choixP=wtp;
				*choixA=wtf;
				*choixD=z;
			} else {
				if(y>8 && x!=0) {
					if(x==1) {
						aa=2;
						ab=0;
						ac=0;
					} else if(x==2) {
						aa=0;
						ab=2;
						ac=0;
					} else {
						aa=0;
						ab=0;
						ac=2;
					}
					if(aa==2 && ab!=2 && ac!=2) {
						*choixP=1;
						*choixA=2;
						*choixD=z;
					} else if(aa!=2 && ab==2 && ac!=2) {
						*choixP=2;
						*choixA=2;
						*choixD=z;
					} else if(aa!=2 && ab!=2 && ac==2) {
						*choixP=3;
						*choixA=2;
						*choixD=z;
					} else if((aa==2 && ab==2) || (aa==2 && ac==2) || (aa==2 && ab==2 && ac==2)) {
						*choixP=1;
						*choixA=2;
						*choixD=z;
					} else {
						*choixP=2;
						*choixA=2;
						*choixD=z;
					}
				} else {
					*choixP=x;
					*choixA=1;
					*choixD=z;
				}
			}
		}
	}
}
void AffichAttaque(int *choixP, Bot *aa, Bot *ab, Bot *ac) {
	int k=0;
	if(*choixP==1) {
		printf(BWHT"|1:");
		for(int i=0; i<strlen(aa->normal.name); i++) {
			printf("%c", *(aa->normal.name+i));
			k=i;
		}
		for(int i=k; i<20; i++) {
			printf(" ");
		}
		printf("2:");
		for(int i=0; i<strlen(aa->special.name); i++) {
			printf("%c", *(aa->special.name+i));
			k=i;
		}
		for(int i=k; i<20; i++) {
			printf(" ");
		}
		printf("3:");
		for(int i=0; i<strlen(aa->unique.name); i++) {
			printf("%c", *(aa->unique.name+i));
			k=i;
		}
		for(int i=k; i<20; i++) {
			printf(" ");
		}
		printf("4:RETOUR"RESETT" en arriere");
		printf("\n|    dmg:%d", aa->normal.focusdamage);
		if(aa->normal.focusdamage==0) {
			printf("                  ");
		} else {
			printf("                 ");
		}
		printf("dmg:%d", aa->special.focusdamage);
		if(aa->special.focusdamage==0) {
			printf("                  ");
		} else {
			printf("                 ");
		}
		printf("dmg:%d\n", aa->unique.focusdamage);
		printf("| AOEdmg:%d", aa->normal.damage);
		if(aa->normal.damage==0) {
			printf("               ");
		} else {
			printf("              ");
		}
		printf("AOEdmg:%d", aa->special.damage);
		if(aa->special.damage==0) {
			printf("               ");
		} else {
			printf("              ");
		}
		printf("AOEdmg:%d\n", aa->unique.damage);
		printf("|   heal:%d", aa->normal.focusheal);
		if(aa->normal.focusheal==0) {
			printf("                 ");
		} else {
			printf("                ");
		}
		printf("heal:%d", aa->special.focusheal);
		if(aa->special.focusheal==0) {
			printf("                 ");
		} else {
			printf("                ");
		}
		printf("heal:%d\n", aa->unique.focusheal);
		printf("|AOEheal:%d", aa->normal.heal);
		if(aa->normal.heal==0) {
			printf("              ");
		} else {
			printf("             ");
		}
		printf("AOEheal:%d", aa->special.heal);
		if(aa->special.heal==0) {
			printf("              ");
		} else {
			printf("             ");
		}
		printf("AOEheal:%d\n", aa->unique.heal);
		printf("effet:\n" GRN "| poison:" RESETT "%d" GRN "             poison:" RESETT "%d" GRN "             poison:" RESETT "%d\n", aa->normal.poison, aa->special.poison, aa->unique.poison);
		printf(YEL"|   stun:" RESETT "%d" YEL "               stun:" RESETT "%d" YEL "               stun:" RESETT "%d\n", aa->normal.stun, aa->special.stun, aa->unique.stun);
		printf(MAG"| confus:" RESETT "%d" MAG "             confus:" RESETT "%d" MAG "             confus:" RESETT "%d\n", aa->normal.confused, aa->special.confused, aa->unique.confused);
	} else if(*choixP==2) {
		printf(BWHT"|1:");
		for(int i=0; i<strlen(ab->normal.name); i++) {
			printf("%c", *(ab->normal.name+i));
			k=i;
		}
		for(int i=k; i<20; i++) {
			printf(" ");
		}
		printf("2:");
		for(int i=0; i<strlen(ab->special.name); i++) {
			printf("%c", *(ab->special.name+i));
			k=i;
		}
		for(int i=k; i<20; i++) {
			printf(" ");
		}
		printf("3:");
		for(int i=0; i<strlen(ab->unique.name); i++) {
			printf("%c", *(ab->unique.name+i));
			k=i;
		}
		for(int i=k; i<20; i++) {
			printf(" ");
		}
		printf("4:RETOUR"RESETT" en arriere");
		printf("\n|    dmg:%d", ab->normal.focusdamage);
		if(ab->normal.focusdamage==0) {
			printf("                  ");
		} else {
			printf("                 ");
		}
		printf("dmg:%d", ab->special.focusdamage);
		if(ab->special.focusdamage==0) {
			printf("                  ");
		} else {
			printf("                 ");
		}
		printf("dmg:%d\n", ab->unique.focusdamage);
		printf("| AOEdmg:%d", ab->normal.damage);
		if(ab->normal.damage==0) {
			printf("               ");
		} else {
			printf("              ");
		}
		printf("AOEdmg:%d", ab->special.damage);
		if(ab->special.damage==0) {
			printf("               ");
		} else {
			printf("              ");
		}
		printf("AOEdmg:%d\n", ab->unique.damage);
		printf("|   heal:%d", ab->normal.focusheal);
		if(ab->normal.focusheal==0) {
			printf("                 ");
		} else {
			printf("                ");
		}
		printf("heal:%d", ab->special.focusheal);
		if(ab->special.focusheal==0) {
			printf("                 ");
		} else {
			printf("                ");
		}
		printf("heal:%d\n", ab->unique.focusheal);
		printf("|AOEheal:%d", ab->normal.heal);
		if(ab->normal.heal==0) {
			printf("              ");
		} else {
			printf("             ");
		}
		printf("AOEheal:%d", ab->special.heal);
		if(ab->special.heal==0) {
			printf("              ");
		} else {
			printf("             ");
		}
		printf("AOEheal:%d\n", ab->unique.heal);
		printf("effet:\n" GRN "| poison:" RESETT "%d" GRN "             poison:" RESETT "%d" GRN "             poison:" RESETT "%d\n", ab->normal.poison, ab->special.poison, ab->unique.poison);
		printf(YEL"|   stun:" RESETT "%d" YEL "               stun:" RESETT "%d" YEL "               stun:" RESETT "%d\n", ab->normal.stun, ab->special.stun, ab->unique.stun);
		printf(MAG"| confus:" RESETT "%d" MAG "             confus:" RESETT "%d" MAG "             confus:" RESETT "%d\n", ab->normal.confused, ab->special.confused, ab->unique.confused);
	} else {
		printf(BWHT"|1:");
		for(int i=0; i<strlen(ac->normal.name); i++) {
			printf("%c", *(ac->normal.name+i));
			k=i;
		}
		for(int i=k; i<20; i++) {
			printf(" ");
		}
		printf("2:");
		for(int i=0; i<strlen(ac->special.name); i++) {
			printf("%c", *(ac->special.name+i));
			k=i;
		}
		for(int i=k; i<20; i++) {
			printf(" ");
		}
		printf("3:");
		for(int i=0; i<strlen(ac->unique.name); i++) {
			printf("%c", *(ac->unique.name+i));
			k=i;
		}
		for(int i=k; i<20; i++) {
			printf(" ");
		}
		printf("4:RETOUR"RESETT" en arriere");
		printf("\n|    dmg:%d", ac->normal.focusdamage);
		if(ac->normal.focusdamage==0) {
			printf("                  ");
		} else {
			printf("                 ");
		}
		printf("dmg:%d", ac->special.focusdamage);
		if(ac->special.focusdamage==0) {
			printf("                  ");
		} else {
			printf("                 ");
		}
		printf("dmg:%d\n", ac->unique.focusdamage);
		printf("| AOEdmg:%d", ac->normal.damage);
		if(ac->normal.damage==0) {
			printf("               ");
		} else {
			printf("              ");
		}
		printf("AOEdmg:%d", ac->special.damage);
		if(ac->special.damage==0) {
			printf("               ");
		} else {
			printf("              ");
		}
		printf("AOEdmg:%d\n", ac->unique.damage);
		printf("|   heal:%d", ac->normal.focusheal);
		if(ac->normal.focusheal==0) {
			printf("                 ");
		} else {
			printf("                ");
		}
		printf("heal:%d", ac->special.focusheal);
		if(ac->special.focusheal==0) {
			printf("                 ");
		} else {
			printf("                ");
		}
		printf("heal:%d\n", ac->unique.focusheal);
		printf("|AOEheal:%d", ac->normal.heal);
		if(ac->normal.heal==0) {
			printf("              ");
		} else {
			printf("             ");
		}
		printf("AOEheal:%d", ac->special.heal);
		if(ac->special.heal==0) {
			printf("              ");
		} else {
			printf("             ");
		}
		printf("AOEheal:%d\n", ac->unique.heal);

		printf("effet:\n" GRN "| poison:" RESETT "%d" GRN "             poison:" RESETT "%d" GRN "             poison:" RESETT "%d\n", ac->normal.poison, ac->special.poison, ac->unique.poison);
		printf(YEL"|   stun:" RESETT "%d" YEL "               stun:" RESETT "%d" YEL "               stun:" RESETT "%d\n", ac->normal.stun, ac->special.stun, ac->unique.stun);
		printf(MAG"| confus:" RESETT "%d" MAG "             confus:" RESETT "%d" MAG "             confus:" RESETT "%d\n", ac->normal.confused, ac->special.confused, ac->unique.confused);
	}
}

void AffichBunny(int x) {
	switch(x) {
	case 1:
		printf("\\{x u O}-|    ");
		break;
	case 2:
		printf("/{^ - ^}_/    ");
		break;
	case 3:
		printf("\\(.___.)-  }X)");
		break;
	case 4:
	    printf("/{O___o}\\     ");
		break;
	case 5:
        printf("/{^ . ~}/     ");
		break;
	case 6:
        printf("\\{-___-}-[X]  ");
		break;
	case 7:
        printf("/{' V ^}_|    ");
		break;
	case 8:
        printf("/[o _ o]--#   ");
		break;
	case 9:
        printf("\\[' v ']/     ");
		break;
	case 10:
        printf("|(' _ .)~~/   ");
		break;
	case 11:
        printf("/{-  .-}~D    ");
		break;
	case 12:
        printf("/{* - *}~$ zap");
		break;
	case 13:
        printf("'( .-. )'     ");
		break;
	case 14:
        printf("({o . o})     ");
		break;
	case 15:
        printf("/{. O .}/     ");
		break;
	case 16:
        printf("\\{  -_.}~|Z|  ");
		break;
	case 69:
	    printf(" {X . X}      ");
	    break;
	case 100:
	    printf("/{  oWo}~BAM  ");
	    break;
	default:
		printf("\\{? w ?}/     ");
	}
}

void Affichage(int l, int c, int lp, int cp, int mode, Bot *ja, Bot *jb, Bot *jc, Bot *ba, Bot *bb, Bot *bc, char *nameA, char *nameB) { // (ligne, colonne, ligne position, colonne position,...)
	int x=0;
	int y=0;
	int i=0;
	int k=0;
	if(lp>l) {
		return;
	}
	if(cp>=c) {
		printf("|\n");
		Affichage(l, c, lp+1, 1, mode, ja, jb, jc, ba, bb, bc, nameA, nameB);
	} else if(lp==1) {
		printf("________________________________________________________________________________________________________________________\n");
		Affichage(l, c, lp+1, 1, mode, ja, jb, jc, ba, bb, bc, nameA, nameB);
	} else if(lp==3) {
		printf("|_______________________________________________________[]___[]________________________________________________________|\n");
		Affichage(l, c, lp+1, 1, mode, ja, jb, jc, ba, bb, bc, nameA, nameB);
	} else if(lp==l) {
		printf("|_______________________________________________________[]___[]________________________________________________________|\n");
		Affichage(l, c, lp+1, 1, mode, ja, jb, jc, ba, bb, bc, nameA, nameB);
	} else if(cp==1) {
		printf("|");
		Affichage(l, c, lp, 2, mode, ja, jb, jc, ba, bb, bc, nameA, nameB);
	} else if(lp==2 && cp==4) {
		for(int i=0; i<strlen(nameA); i++) {
			printf("%c", *(nameA+i));
		}
		Affichage(l, c, lp, cp+strlen(nameA), mode, ja, jb, jc, ba, bb, bc, nameA, nameB);
	} else if(lp==2 && cp==(97-strlen(nameB))) {
		for(int i=0; i<strlen(nameB); i++) {
			printf("%c", *(nameB+i));
		}
		Affichage(l, c, lp, cp+strlen(nameB), mode, ja, jb, jc, ba, bb, bc, nameA, nameB);
	} else if(lp==2 && cp==59) {
		printf("V-S");
		Affichage(l, c, lp, cp+3, mode, ja, jb, jc, ba, bb, bc, nameA, nameB);
	} else if(lp>3 && lp<l && (cp==57 || cp==58 || cp==62 || cp==63)) {
		printf("|");
		Affichage(l, c, lp, cp+1, mode, ja, jb, jc, ba, bb, bc, nameA, nameB);
	} else if(lp>4 && lp<l && (cp==59 || cp==60 || cp==61)) {
		printf("X");
		Affichage(l, c, lp, cp+1, mode, ja, jb, jc, ba, bb, bc, nameA, nameB);
	} else if((lp==9 || lp==15) && (cp==3 || cp==75)) {
		printf("_________");
		Affichage(l, c, lp, cp+9, mode, ja, jb, jc, ba, bb, bc, nameA, nameB);
	} else if(lp==6 && cp==2) {
		printf("STA: %d", ja->stamina);
		if(ja->stamina<10) {
			printf(" ");
		}
		Affichage(l, c, lp, cp+7, mode, ja, jb, jc, ba, bb, bc, nameA, nameB);
	} else if(lp==12 && cp==2) {
		printf("STA: %d", jb->stamina);
		if(jb->stamina<10) {
			printf(" ");
		}
		Affichage(l, c, lp, cp+7, mode, ja, jb, jc, ba, bb, bc, nameA, nameB);
	} else if(lp==18 && cp==2) {
		printf("STA: %d", jc->stamina);
		if(jc->stamina<10) {
			printf(" ");
		}
		Affichage(l, c, lp, cp+7, mode, ja, jb, jc, ba, bb, bc, nameA, nameB);
	} else if(lp==6 && cp==76) {
		printf("STA: %d", ba->stamina);
		if(ba->stamina<10) {
			printf(" ");
		}
		Affichage(l, c, lp, cp+7, mode, ja, jb, jc, ba, bb, bc, nameA, nameB);
	} else if(lp==12 && cp==76) {
		printf("STA: %d", bb->stamina);
		if(bb->stamina<10) {
			printf(" ");
		}
		Affichage(l, c, lp, cp+7, mode, ja, jb, jc, ba, bb, bc, nameA, nameB);
	} else if(lp==18 && cp==76) {
		printf("STA: %d", bc->stamina);
		if(bc->stamina<10) {
			printf(" ");
		}
		Affichage(l, c, lp, cp+7, mode, ja, jb, jc, ba, bb, bc, nameA, nameB);
	} else if(lp==4 && cp==4) { ////
		printf( BBLU "1: ");
		for(int i=0; i<strlen(ja->name); i++) {
			printf("%c", *(ja->name+i));
		}
		printf(RESETT);
		Affichage(l, c, lp, cp+strlen(ja->name)+3, mode, ja, jb, jc, ba, bb, bc, nameA, nameB);
	} else if(lp==4 && cp==77) {
		printf( BRED "1: ");
		for(int i=0; i<strlen(ba->name); i++) {
			printf("%c", *(ba->name+i));
		}
		printf(RESETT);
		Affichage(l, c, lp, cp+strlen(ba->name)+3, mode, ja, jb, jc, ba, bb, bc, nameA, nameB);
	} else if(lp==5 && cp==3) {
		x=ja->pv;
		y=ja->pvmax;
		if(ja->poison==1) {
			printf(GRN);
		}
		printf("PV: ");
		while(x>=20) {
			printf("[]");
			x-=20;
			i+=20;
			k+=2;
		}
		if(x>=10) {
			printf("[");
			x-=10;
			i+=10;
			k+=1;
		}
		while(i<y) {
			printf("-");
			i+=10;
			k+=1;
		}
		printf(" (%d)",ja->pv);
		if(ja->pv<100) {
			printf(" ");
		}
		if(ja->pv<10) {
			printf(" ");
		}
		if(ja->poison==1) {
			printf(RESETT);
		}
		Affichage(l, c, lp, cp+4+k+6, mode, ja, jb, jc, ba, bb, bc, nameA, nameB);
	} else if(lp==5 && cp==76) {
		x=ba->pv;
		y=ba->pvmax;
		if(ba->poison==1) {
			printf(GRN);
		}
		printf("PV: ");
		while(x>=20) {
			printf("[]");
			x-=20;
			i+=20;
			k+=2;
		}
		if(x>=10) {
			printf("[");
			x-=10;
			i+=10;
			k+=1;
		}
		while(i<y) {
			printf("-");
			i+=10;
			k+=1;
		}
		printf(" (%d)",ba->pv);
		if(ba->pv<100) {
			printf(" ");
		}
		if(ba->pv<10) {
			printf(" ");
		}
		if(ba->poison==1) {
			printf(RESETT);
		}
		Affichage(l, c, lp, cp+4+k+6, mode, ja, jb, jc, ba, bb, bc, nameA, nameB);
	} else if(lp==10 && cp==4) { ////
		printf( BBLU "2: ");
		for(int i=0; i<strlen(jb->name); i++) {
			printf("%c", *(jb->name+i));
		}
		printf(RESETT);
		Affichage(l, c, lp, cp+strlen(jb->name)+3, mode, ja, jb, jc, ba, bb, bc, nameA, nameB);
	} else if(lp==10 && cp==77) {
		printf( BRED "2: ");
		for(int i=0; i<strlen(bb->name); i++) {
			printf("%c", *(bb->name+i));
		}
		printf(RESETT);
		Affichage(l, c, lp, cp+strlen(bb->name)+3, mode, ja, jb, jc, ba, bb, bc, nameA, nameB);
	} else if(lp==11 && cp==3) {
		x=jb->pv;
		y=jb->pvmax;
		if(jb->poison==1) {
			printf(GRN);
		}
		printf("PV: ");
		while(x>=20) {
			printf("[]");
			x-=20;
			i+=20;
			k+=2;
		}
		if(x>=10) {
			printf("[");
			x-=10;
			i+=10;
			k+=1;
		}
		while(i<y) {
			printf("-");
			i+=10;
			k+=1;
		}
		printf(" (%d)",jb->pv);
		if(jb->pv<100) {
			printf(" ");
		}
		if(jb->pv<10) {
			printf(" ");
		}
		if(jb->poison==1) {
			printf(RESETT);
		}
		Affichage(l, c, lp, cp+4+k+6, mode, ja, jb, jc, ba, bb, bc, nameA, nameB);
	} else if(lp==11 && cp==76) {
		x=bb->pv;
		y=bb->pvmax;
		if(bb->poison==1) {
			printf(GRN);
		}
		printf("PV: ");
		while(x>=20) {
			printf("[]");
			x-=20;
			i+=20;
			k+=2;
		}
		if(x>=10) {
			printf("[");
			x-=10;
			i+=10;
			k+=1;
		}
		while(i<y) {
			printf("-");
			i+=10;
			k+=1;
		}
		printf(" (%d)",bb->pv);
		if(bb->pv<100) {
			printf(" ");
		}
		if(bb->pv<10) {
			printf(" ");
		}
		if(bb->poison==1) {
			printf(RESETT);
		}
		Affichage(l, c, lp, cp+4+k+6, mode, ja, jb, jc, ba, bb, bc, nameA, nameB);
	} else if(lp==16 && cp==4) { ////
		printf( BBLU "3: ");
		for(int i=0; i<strlen(jc->name); i++) {
			printf("%c", *(jc->name+i));
		}
		printf(RESETT);
		Affichage(l, c, lp, cp+strlen(jc->name)+3, mode, ja, jb, jc, ba, bb, bc, nameA, nameB);
	} else if(lp==16 && cp==77) {
		printf( BRED "3: ");
		for(int i=0; i<strlen(bc->name); i++) {
			printf("%c", *(bc->name+i));
		}
		printf(RESETT);
		Affichage(l, c, lp, cp+strlen(bc->name)+3, mode, ja, jb, jc, ba, bb, bc, nameA, nameB);
	} else if(lp==17 && cp==3) {
		x=jc->pv;
		y=jc->pvmax;
		if(jc->poison==1) {
			printf(GRN);
		}
		printf("PV: ");
		while(x>=20) {
			printf("[]");
			x-=20;
			i+=20;
			k+=2;
		}
		if(x>=10) {
			printf("[");
			x-=10;
			i+=10;
			k+=1;
		}
		while(i<y) {
			printf("-");
			i+=10;
			k+=1;
		}
		printf(" (%d)",jc->pv);
		if(jc->pv<100) {
			printf(" ");
		}
		if(jc->pv<10) {
			printf(" ");
		}
		if(jc->poison==1) {
			printf(RESETT);
		}
		Affichage(l, c, lp, cp+4+k+6, mode, ja, jb, jc, ba, bb, bc, nameA, nameB);
	} else if(lp==17 && cp==76) {
		x=bc->pv;
		y=bc->pvmax;
		if(bc->poison==1) {
			printf(GRN);
		}
		printf("PV: ");
		while(x>=20) {
			printf("[]");
			x-=20;
			i+=20;
			k+=2;
		}
		if(x>=10) {
			printf("[");
			x-=10;
			i+=10;
			k+=1;
		}
		while(i<y) {
			printf("-");
			i+=10;
			k+=1;
		}
		printf(" (%d)",bc->pv);
		if(bc->pv<100) {
			printf(" ");
		}
		if(bc->pv<10) {
			printf(" ");
		}
		if(bc->poison==1) {
			printf(RESETT);
		}
		Affichage(l, c, lp, cp+4+k+6, mode, ja, jb, jc, ba, bb, bc, nameA, nameB);
	} else if(lp==7 && cp==20 || lp==13 && cp==20 || lp==19 && cp==20 || lp==7 && cp==90 || lp==13 && cp==90 || lp==19 && cp==90) {
		printf(" (\\___/) ");
		Affichage(l, c, lp, cp+9, mode, ja, jb, jc, ba, bb, bc, nameA, nameB);
	} else if(lp==8 && cp==20) {
		if(ja->dead==0) {
			AffichBunny(ja->chosen);
		} else {
			AffichBunny(69);
		}
		Affichage(l, c, lp, cp+BUNNY, mode, ja, jb, jc, ba, bb, bc, nameA, nameB);
	} else if(lp==14 && cp==20) {
		if(jb->dead==0) {
			AffichBunny(jb->chosen);
		} else {
			AffichBunny(69);
		}
		Affichage(l, c, lp, cp+BUNNY, mode, ja, jb, jc, ba, bb, bc, nameA, nameB);
	} else if(lp==20 && cp==20) {
		if(jc->dead==0) {
			AffichBunny(jc->chosen);
		} else {
			AffichBunny(69);
		}
		Affichage(l, c, lp, cp+BUNNY, mode, ja, jb, jc, ba, bb, bc, nameA, nameB);
	} else if(lp==8 && cp==90) {
		if(ba->dead==0) {
			AffichBunny(ba->chosen);
		} else {
			AffichBunny(69);
		}
		Affichage(l, c, lp, cp+BUNNY, mode, ja, jb, jc, ba, bb, bc, nameA, nameB);
	} else if(lp==14 && cp==90) {
		if(bb->dead==0) {
			AffichBunny(bb->chosen);
		} else {
			AffichBunny(69);
		}
		Affichage(l, c, lp, cp+BUNNY, mode, ja, jb, jc, ba, bb, bc, nameA, nameB);
	} else if(lp==20 && cp==90) {
		if(bc->dead==0) {
			AffichBunny(bc->chosen);
		} else {
			AffichBunny(69);
		}
		Affichage(l, c, lp, cp+BUNNY, mode, ja, jb, jc, ba, bb, bc, nameA, nameB);
	} else {
		printf(" ");
		Affichage(l, c, lp, cp+1, mode, ja, jb, jc, ba, bb, bc, nameA, nameB);

	}
}

int AffichPersoAttaque(int sexy, Bot *a){
    *a=Characterbuilder(sexy);
    int k=0;
    int crashBandicoot=0;
        printf("\n|Nom du Bunny: ");
        for(int i=0; i<strlen(a->name); i++) {
			printf("%c", *(a->name+i));
		}
	    printf("PV: %d\n", a->pvmax);
	    printf("Agilite: %d  (pourcentage de chance d'esquiver une attaque-> x100) \n", a->agility);
	    printf("defence: %d  (reduction de degat-> attaque*defence)\n", a->pvmax);
        printf(BWHT"|1:");
		for(int i=0; i<strlen(a->normal.name); i++) {
			printf("%c", *(a->normal.name+i));
			k=i;
		}
		for(int i=k; i<20; i++) {
			printf(" ");
		}
		printf("2:");
		for(int i=0; i<strlen(a->special.name); i++) {
			printf("%c", *(a->special.name+i));
			k=i;
		}
		for(int i=k; i<20; i++) {
			printf(" ");
		}
		printf("3:");
		for(int i=0; i<strlen(a->unique.name); i++) {
			printf("%c", *(a->unique.name+i));
			k=i;
		}
		for(int i=k; i<20; i++) {
			printf(" ");
		}
		printf("4:RETOUR"RESETT" en arriere");
		printf("\n|    dmg:%d", a->normal.focusdamage);
		if(a->normal.focusdamage==0) {
			printf("                  ");
		} else {
			printf("                 ");
		}
		printf("dmg:%d", a->special.focusdamage);
		if(a->special.focusdamage==0) {
			printf("                  ");
		} else {
			printf("                 ");
		}
		printf("dmg:%d\n", a->unique.focusdamage);
		printf("| AOEdmg:%d", a->normal.damage);
		if(a->normal.damage==0) {
			printf("               ");
		} else {
			printf("              ");
		}
		printf("AOEdmg:%d", a->special.damage);
		if(a->special.damage==0) {
			printf("               ");
		} else {
			printf("              ");
		}
		printf("AOEdmg:%d\n", a->unique.damage);
		printf("|   heal:%d", a->normal.focusheal);
		if(a->normal.focusheal==0) {
			printf("                 ");
		} else {
			printf("                ");
		}
		printf("heal:%d", a->special.focusheal);
		if(a->special.focusheal==0) {
			printf("                 ");
		} else {
			printf("                ");
		}
		printf("heal:%d\n", a->unique.focusheal);
		printf("|AOEheal:%d", a->normal.heal);
		if(a->normal.heal==0) {
			printf("              ");
		} else {
			printf("             ");
		}
		printf("AOEheal:%d", a->special.heal);
		if(a->special.heal==0) {
			printf("              ");
		} else {
			printf("             ");
		}
		printf("AOEheal:%d\n", a->unique.heal);

		printf("effet:\n" GRN "| poison:" RESETT "%d" GRN "             poison:" RESETT "%d" GRN "             poison:" RESETT "%d\n", a->normal.poison, a->special.poison, a->unique.poison);
		printf(YEL"|   stun:" RESETT "%d" YEL "               stun:" RESETT "%d" YEL "               stun:" RESETT "%d\n", a->normal.stun, a->special.stun, a->unique.stun);
		printf(MAG"| confus:" RESETT "%d" MAG "             confus:" RESETT "%d" MAG "             confus:" RESETT "%d\n", a->normal.confused, a->special.confused, a->unique.confused);
		do{
		    printf(BWHT"(Selectionez:1  Retour:2)---> "RESETT);
		    scanf("%d\n", &crashBandicoot);
		}
		while(crashBandicoot!=1 && crashBandicoot!=2);
	return crashBandicoot;
}

void AffichPersoChoix(int l, int c, int lp, int cp, Bot *a) {//(27, 120, 1, 1, Bunny);
	int k=0;
	if(lp>l) {
		return;
	}
	if(cp>=c) {
		printf("|\n");
		AffichPersoChoix(l, c, lp+1, 1, a);
	} else if(lp==1) {
		printf("________________________________________________________________________________________________________________________\n");
		AffichPersoChoix(l, c, lp+1, 1, a);
	} else if(lp==l) {
		printf("|_______________________________________________________[]___[]________________________________________________________|\n");
		AffichPersoChoix(l, c, lp+1, 1, a);
	} else if(cp==1) {
		printf("|");
		AffichPersoChoix(l, c, lp, 2, a);
	} else if(lp>1 && lp<l && (cp==57 || cp==58 || cp==62 || cp==63)) {
		printf("|");
		AffichPersoChoix(l, c, lp, cp+1, a);
	} else if(lp>2 && lp<l && (cp==59 || cp==60 || cp==61)) {
		printf("X");
		AffichPersoChoix(l, c, lp, cp+1, a);
	} else if(lp==2 && (cp==47 || cp==71)) {
		printf("|");
		AffichPersoChoix(l, c, lp, cp+1, a);
	} else if(lp==2 && cp==48) {
		printf( UBLU "Selection" RESETT );
		AffichPersoChoix(l, c, lp, cp+9, a);
	} else if(lp==2 && cp==59) {
		printf( UWHT "des" RESETT );
		AffichPersoChoix(l, c, lp, cp+3, a);
	} else if(lp==2 && cp==64) {
		printf( URED "raiders" RESETT );
		AffichPersoChoix(l, c, lp, cp+7, a);
	} else if(lp==4 && cp==40 || lp==10 && cp==40 || lp==16 && cp==40 || lp==22 && cp==40 || lp==4 && cp==70 || lp==10 && cp==70 || lp==16 && cp==70 || lp==22 && cp==70){
		printf(" (\\___/) ");
		AffichPersoChoix(l, c, lp, cp+9, a);
	} else if(lp==7 && cp==30 || lp==13 && cp==30 || lp==19 && cp==30 || lp==25 && cp==30 || lp==7 && cp==80 || lp==13 && cp==80 || lp==19 && cp==80 || lp==25 && cp==80){
		printf(" (\\___/) ");
		AffichPersoChoix(l, c, lp, cp+9, a);
	} else if(lp==5 && cp==40) {
		AffichBunny(1);
		AffichPersoChoix(l, c, lp, cp+BUNNY, a);
	} else if(lp==8 && cp==30) {
		AffichBunny(2);
		AffichPersoChoix(l, c, lp, cp+BUNNY, a);
	} else if(lp==11 && cp==40) {
		AffichBunny(3);
		AffichPersoChoix(l, c, lp, cp+BUNNY, a);
	} else if(lp==14 && cp==30) {
		AffichBunny(4);
		AffichPersoChoix(l, c, lp, cp+BUNNY, a);
	} else if(lp==17 && cp==40) {
		AffichBunny(5);
		AffichPersoChoix(l, c, lp, cp+BUNNY, a);
	} else if(lp==20 && cp==30) {
		AffichBunny(6);
		AffichPersoChoix(l, c, lp, cp+BUNNY, a);
	} else if(lp==23 && cp==40) {
		AffichBunny(7);
		AffichPersoChoix(l, c, lp, cp+BUNNY, a);
	} else if(lp==26 && cp==30) {
		AffichBunny(8);
		AffichPersoChoix(l, c, lp, cp+BUNNY, a);
	} else if(lp==5 && cp==70) {
		AffichBunny(9);
		AffichPersoChoix(l, c, lp, cp+BUNNY, a);
	} else if(lp==8 && cp==80) {
		AffichBunny(10);
		AffichPersoChoix(l, c, lp, cp+BUNNY, a);
	} else if(lp==11 && cp==70) {
		AffichBunny(11);
		AffichPersoChoix(l, c, lp, cp+BUNNY, a);
	} else if(lp==14 && cp==80) {
		AffichBunny(12);
		AffichPersoChoix(l, c, lp, cp+BUNNY, a);
	} else if(lp==17 && cp==70) {
		AffichBunny(13);
		AffichPersoChoix(l, c, lp, cp+BUNNY, a);
	} else if(lp==20 && cp==80) {
		AffichBunny(14);
		AffichPersoChoix(l, c, lp, cp+BUNNY, a);
	} else if(lp==23 && cp==70) {
		AffichBunny(15);
		AffichPersoChoix(l, c, lp, cp+BUNNY, a);
	} else if(lp==26 && cp==80) {
		AffichBunny(16);
		AffichPersoChoix(l, c, lp, cp+BUNNY, a);
	} else if(lp==3 && cp==2) {
		printf( BWHT "1:Forgeron" RESETT );
		AffichPersoChoix(l, c, lp, cp+10, a);
	} else if(lp==6 && cp==2) {
		printf( BWHT "2:Oracle" RESETT );
		AffichPersoChoix(l, c, lp, cp+8, a);
	} else if(lp==9 && cp==2) {
		printf( BWHT "3:Magicien" RESETT );
		AffichPersoChoix(l, c, lp, cp+10, a);
	} else if(lp==12 && cp==2) {
		printf( BWHT "4:Raideur" RESETT );
		AffichPersoChoix(l, c, lp, cp+9, a);
	} else if(lp==15 && cp==2) {
		printf( BWHT "5:Necromancien" RESETT );
		AffichPersoChoix(l, c, lp, cp+14, a);
	} else if(lp==18 && cp==2) {
		printf( BWHT "6:Clerc" RESETT );
		AffichPersoChoix(l, c, lp, cp+7, a);
	} else if(lp==21 && cp==2) {
		printf( BWHT "7:Illusionniste" RESETT );
		AffichPersoChoix(l, c, lp, cp+15, a);
	} else if(lp==24 && cp==2) {
		printf( BWHT "8:Druide" RESETT );
		AffichPersoChoix(l, c, lp, cp+8, a);
		//////
	} else if(lp==3 && cp==(108)) {
		printf( BWHT "Invocateur:9" RESETT );
		AffichPersoChoix(l, c, lp, cp+12, a);
	} else if(lp==6 && cp==109) {
		printf( BWHT "Champion:10" RESETT );
		AffichPersoChoix(l, c, lp, cp+11, a);
	} else if(lp==9 && cp==106) {
		printf( BWHT "Explorateur:11" RESETT );
		AffichPersoChoix(l, c, lp, cp+14, a);
	} else if(lp==12 && cp==104) {
		printf( BWHT "Chronomancien:12" RESETT );
		AffichPersoChoix(l, c, lp, cp+16, a);
	} else if(lp==15 && cp==109) {
		printf( BWHT "Assassin:13" RESETT );
		AffichPersoChoix(l, c, lp, cp+11, a);
	} else if(lp==18 && cp==113) {
		printf( BWHT "Juge:14" RESETT );
		AffichPersoChoix(l, c, lp, cp+7, a);
	} else if(lp==21 && cp==105) {
		printf( BWHT "Empoisonneur:15" RESETT );
		AffichPersoChoix(l, c, lp, cp+15, a);
	} else if(lp==24 && cp==107) {
		printf( BWHT "Sentinelle:16" RESETT );
		AffichPersoChoix(l, c, lp, cp+13, a);
	} else {
		printf(" ");
		AffichPersoChoix(l, c, lp, cp+1, a);
	}
}

void Turn(int who, int mo, int *dif, int *choixP, int *choixA, int *choixD, Bot *aa, Bot *ab, Bot *ac, Bot *da, Bot *db, Bot *dc, char *nameA, char *nameB) {
	// choixP= selection du personnage, choixA= choix de l'attaque, choixD= choix du personnage affecte)
	if((mo==0 && who==1) || (mo==1 && who==1) || (mo==1 && who==0)) {
		Affichage(21, 120, 1, 1, mo, aa, ab, ac, da, db, dc, nameA, nameB);
		do {
			printf("|Choisir son personnage (1,2,3): ");
			scanf("%d", choixP);
		}
		while(CheckPerso1(*choixP, aa, ab, ac));
		Affichage(21, 120, 1, 1, mo, aa, ab, ac, da, db, dc, nameA, nameB);
		AffichAttaque(choixP, aa, ab, ac);
		do {
			printf("Choisir son attaque: ");
			scanf("%d", choixA);
			if(*choixA==4) {
				Turn(who, mo, dif, choixP, choixA, choixD, aa, ab, ac, da, db, dc, nameA, nameB);
				return;
			}
		}
		while(CheckStamina(*choixP, *choixA, aa, ab, ac));
		do {
			printf("Choisir le personnage affecte (1,2,3): ");
			scanf("%d", choixD);
			if(*choixD==4) {
				Turn(who, mo, dif, choixP, choixA, choixD, aa, ab, ac, da, db, dc, nameA, nameB);
				return;
			}
		}
		while(CheckPerso2(*choixD, da, db, dc));
	} else {
		Computer(dif, choixP, choixA, choixD, aa, ab, ac, da, db, dc);
		// l'IA qui va choisir l'attaque si 'who' est different de 0 et mo==0
		printf("\nCOMPUTER:\n==============\nP:%d A:%d D:%d\n==============\n", *choixP, *choixA, *choixD);
		sleep(1);
	}
	switch(*choixP) {
	case 1:
		if (aa->confused==1) {
			if(rand()%2) {
				printf("confused\n");
				break;
			}
		}
		switch(*choixA) {
		case 1:
			aa->stamina-=2;
			if(aa->normal.damage!=0) {
				da->pv=da->pv-(aa->normal.damage*da->defence);
				db->pv=db->pv-(aa->normal.damage*db->defence);
				dc->pv=dc->pv-(aa->normal.damage*dc->defence);
			}
			if(aa->normal.heal!=0) {
				aa->pv=aa->pv+aa->normal.heal;
				ab->pv=ab->pv+aa->normal.heal;
				ac->pv=ac->pv+aa->normal.heal;
				aa->poison=0;
				ab->poison=0;
				ac->poison=0;
			}
			switch(*choixD) {
			case 1:
				if(Dodge(*choixD, da, db, dc)==1) {
					da->pv=da->pv-(aa->normal.focusdamage*da->defence);
					if(aa->normal.poison==1) {
						da->poison=1;
					}
				} else {
					printf("Coup rate!!!\n");
				}
				if(aa->normal.focusheal!=0) {
					aa->poison=0;
					aa->pv=aa->pv+aa->normal.focusheal;
				}
				break;
			case 2:
				if(Dodge(*choixD, da, db, dc)==1) {
					db->pv=db->pv-(aa->normal.focusdamage*db->defence);
					if(aa->normal.poison==1) {
						db->poison=1;
					}
				} else {
					printf("Coup rate!!!\n");
				}
				if(aa->normal.focusheal!=0) {
					ab->poison=0;
					ab->pv=ab->pv+aa->normal.focusheal;
				}
				break;
			case 3:
				if(Dodge(*choixD, da, db, dc)==1) {
					dc->pv=dc->pv-(aa->normal.focusdamage*dc->defence);
					if(aa->normal.poison==1) {
						dc->poison=1;
					}
				} else {
					printf("Coup rate!!!\n");
				}
				if(aa->normal.focusheal!=0) {
					ac->poison=0;
					ac->pv=ac->pv+aa->normal.focusheal;
				}
				break;
			}
			break;
		case 2:
			aa->stamina-=8;
			if(aa->special.damage!=0) {
				da->pv=da->pv-(aa->special.damage*da->defence);
				db->pv=db->pv-(aa->special.damage*db->defence);
				dc->pv=dc->pv-(aa->special.damage*dc->defence);
			}
			if(aa->special.heal!=0) {
				aa->pv=aa->pv+aa->special.heal;
				ab->pv=ab->pv+aa->special.heal;
				ac->pv=ac->pv+aa->special.heal;
				aa->poison=0;
				ab->poison=0;
				ac->poison=0;
			}
			switch(*choixD) {
			case 1:
				if(Dodge(*choixD, da, db, dc)==1) {
					da->pv=da->pv-(aa->special.focusdamage*da->defence);
					if(aa->special.poison==1) {
						da->poison=1;
					}
				} else {
					printf("Coup rate!!!\n");
				}
				if(aa->special.focusheal!=0) {
					aa->poison=0;
					aa->pv=aa->pv+aa->special.focusheal;
				}
				break;
			case 2:
				if(Dodge(*choixD, da, db, dc)==1) {
					db->pv=db->pv-(aa->special.focusdamage*db->defence);
					if(aa->special.poison==1) {
						db->poison=1;
					}
				} else {
					printf("Coup rate!!!\n");
				}
				if(aa->special.focusheal!=0) {
					ab->poison=0;
					ab->pv=ab->pv+aa->special.focusheal;
				}
				break;
			case 3:
				if(Dodge(*choixD, da, db, dc)==1) {
					dc->pv=dc->pv-(aa->special.focusdamage*dc->defence);
					if(aa->special.poison==1) {
						dc->poison=1;
					}
				} else {
					printf("Coup rate!!!\n");
				}
				if(aa->special.focusheal!=0) {
					ac->poison=0;
					ac->pv=ac->pv+aa->special.focusheal;
				}
				break;
			}
			break;
		case 3:
			aa->utiliunique=1;
			if(aa->unique.damage!=0) {
				da->pv=da->pv-(aa->unique.damage*da->defence);
				db->pv=db->pv-(aa->unique.damage*db->defence);
				dc->pv=dc->pv-(aa->unique.damage*dc->defence);
			}
			if(aa->unique.heal!=0) {
				aa->pv=aa->pv+aa->unique.heal;
				ab->pv=ab->pv+aa->unique.heal;
				ac->pv=ac->pv+aa->unique.heal;
				aa->poison=0;
				ab->poison=0;
				ac->poison=0;
			}
			switch(*choixD) {
			case 1:
				if(Dodge(*choixD, da, db, dc)==1) {
					da->pv=da->pv-(aa->unique.focusdamage*da->defence);
					if(aa->unique.poison==1) {
						da->poison=1;
					}
				} else {
					printf("Coup rate!!!\n");
				}
				if(aa->unique.focusheal!=0) {
					aa->poison=0;
					aa->pv=aa->pv+aa->unique.focusheal;
				}
				break;
			case 2:
				if(Dodge(*choixD, da, db, dc)==1) {
					db->pv=db->pv-(aa->unique.focusdamage*db->defence);
					if(aa->unique.poison==1) {
						db->poison=1;
					}
				} else {
					printf("Coup rate!!!\n");
				}
				if(aa->unique.focusheal!=0) {
					ab->poison=0;
					ab->pv=ab->pv+aa->unique.focusheal;
				}
				break;
			case 3:
				if(Dodge(*choixD, da, db, dc)==1) {
					dc->pv=dc->pv-(aa->unique.focusdamage*dc->defence);
					if(aa->unique.poison==1) {
						dc->poison=1;
					}
				} else {
					printf("Coup rate!!!\n");
				}
				if(aa->unique.focusheal!=0) {
					ac->poison=0;
					ac->pv=ac->pv+aa->unique.focusheal;
				}
				break;
			}
			break;
		}
		break;
	case 2:
		if (ab->confused==1) {
			if(rand()%2) {
				printf("confused\n");
				break;
			}
		}
		switch(*choixA) {
		case 1:
			ab->stamina-=2;
			if(ab->normal.damage!=0) {
				da->pv=da->pv-(ab->normal.damage*da->defence);
				db->pv=db->pv-(ab->normal.damage*db->defence);
				dc->pv=dc->pv-(ab->normal.damage*dc->defence);
			}
			if(ab->normal.heal!=0) {
				aa->pv=aa->pv+ab->normal.heal;
				ab->pv=ab->pv+ab->normal.heal;
				ac->pv=ac->pv+ab->normal.heal;
				aa->poison=0;
				ab->poison=0;
				ac->poison=0;
			}
			switch(*choixD) {
			case 1:
				if(Dodge(*choixD, da, db, dc)==1) {
					da->pv=da->pv-(ab->normal.focusdamage*da->defence);
					if(ab->normal.poison==1) {
						da->poison=1;
					}
				} else {
					printf("Coup rate!!!\n");
				}
				if(ab->normal.focusheal!=0) {
					aa->poison=0;
					aa->pv=aa->pv+ab->normal.focusheal;
				}
				break;
			case 2:
				if(Dodge(*choixD, da, db, dc)==1) {
					db->pv=db->pv-(ab->normal.focusdamage*db->defence);
					if(ab->normal.poison==1) {
						db->poison=1;
					}
				} else {
					printf("Coup rate!!!\n");
				}
				if(ab->normal.focusheal!=0) {
					ab->poison=0;
					ab->pv=ab->pv+ab->normal.focusheal;
				}
				break;
			case 3:
				if(Dodge(*choixD, da, db, dc)==1) {
					dc->pv=dc->pv-(ab->normal.focusdamage*dc->defence);
					if(ab->normal.poison==1) {
						dc->poison=1;
					}
				} else {
					printf("Coup rate!!!\n");
				}
				if(ab->normal.focusheal!=0) {
					ac->poison=0;
					ac->pv=ac->pv+ab->normal.focusheal;
				}
				break;
			}
			break;
		case 2:
			ab->stamina-=8;
			if(ab->special.damage!=0) {
				da->pv=da->pv-(ab->special.damage*da->defence);
				db->pv=db->pv-(ab->special.damage*db->defence);
				dc->pv=dc->pv-(ab->special.damage*dc->defence);
			}
			if(ab->special.heal!=0) {
				aa->pv=aa->pv+ab->special.heal;
				ab->pv=ab->pv+ab->special.heal;
				ac->pv=ac->pv+ab->special.heal;
				aa->poison=0;
				ab->poison=0;
				ac->poison=0;
			}
			switch(*choixD) {
			case 1:
				if(Dodge(*choixD, da, db, dc)==1) {
					da->pv=da->pv-(ab->special.focusdamage*da->defence);
					if(ab->special.poison==1) {
						da->poison=1;
					}
				} else {
					printf("Coup rate!!!\n");
				}
				if(ab->special.focusheal!=0) {
					aa->poison=0;
					aa->pv=aa->pv+ab->special.focusheal;
				}
				break;
			case 2:
				if(Dodge(*choixD, da, db, dc)==1) {
					db->pv=db->pv-(ab->special.focusdamage*db->defence);
					if(ab->special.poison==1) {
						db->poison=1;
					}
				} else {
					printf("Coup rate!!!\n");
				}
				if(ab->special.focusheal!=0) {
					ab->poison=0;
					ab->pv=ab->pv+ab->special.focusheal;
				}
				break;
			case 3:
				if(Dodge(*choixD, da, db, dc)==1) {
					dc->pv=dc->pv-(ab->special.focusdamage*dc->defence);
					if(ab->special.poison==1) {
						dc->poison=1;
					}
				} else {
					printf("Coup rate!!!\n");
				}
				if(ab->special.focusheal!=0) {
					ac->poison=0;
					ac->pv=ac->pv+ab->special.focusheal;
				}
				break;
			}
			break;
		case 3:
			ab->utiliunique=1;
			if(ab->unique.damage!=0) {
				da->pv=da->pv-(ab->unique.damage*da->defence);
				db->pv=db->pv-(ab->unique.damage*db->defence);
				dc->pv=dc->pv-(ab->unique.damage*dc->defence);
			}
			if(ab->unique.heal!=0) {
				aa->pv=aa->pv+ab->unique.heal;
				ab->pv=ab->pv+ab->unique.heal;
				ac->pv=ac->pv+ab->unique.heal;
				aa->poison=0;
				ab->poison=0;
				ac->poison=0;
			}
			switch(*choixD) {
			case 1:
				if(Dodge(*choixD, da, db, dc)==1) {
					da->pv=da->pv-(ab->unique.focusdamage*da->defence);
					if(ab->unique.poison==1) {
						da->poison=1;
					}
				} else {
					printf("Coup rate!!!\n");
				}
				if(ab->unique.focusheal!=0) {
					aa->poison=0;
					aa->pv=aa->pv+ab->unique.focusheal;
				}
				break;
			case 2:
				if(Dodge(*choixD, da, db, dc)==1) {
					db->pv=db->pv-(ab->unique.focusdamage*db->defence);
					if(ab->unique.poison==1) {
						db->poison=1;
					}
				} else {
					printf("Coup rate!!!\n");
				}
				if(ab->unique.focusheal!=0) {
					ab->poison=0;
					ab->pv=ab->pv+ab->unique.focusheal;
				}
				break;
			case 3:
				if(Dodge(*choixD, da, db, dc)==1) {
					dc->pv=dc->pv-(ab->unique.focusdamage*dc->defence);
					if(ab->unique.poison==1) {
						dc->poison=1;
					}
				} else {
					printf("Coup rate!!!\n");
				}
				if(ab->unique.focusheal!=0) {
					ac->poison=0;
					ac->pv=ac->pv+ab->unique.focusheal;
				}
				break;
			}
			break;
		}
		break;
	case 3:
		if (aa->confused==1) {
			if(rand()%2) {
				printf("confused\n");
				break;
			}
		}
		switch(*choixA) {
		case 1:
			ac->stamina-=2;
			if(ac->normal.damage!=0) {
				da->pv=da->pv-(ac->normal.damage*da->defence);
				db->pv=db->pv-(ac->normal.damage*db->defence);
				dc->pv=dc->pv-(ac->normal.damage*dc->defence);
			}
			if(ac->normal.heal!=0) {
				aa->pv=aa->pv+ac->normal.heal;
				ab->pv=ab->pv+ac->normal.heal;
				ac->pv=ac->pv+ac->normal.heal;
				aa->poison=0;
				ab->poison=0;
				ac->poison=0;
			}
			switch(*choixD) {
			case 1:
				if(Dodge(*choixD, da, db, dc)==1) {
					da->pv=da->pv-(ac->normal.focusdamage*da->defence);
					if(ac->normal.poison==1) {
						da->poison=1;
					}
				} else {
					printf("Coup rate!!!\n");
				}
				if(ac->normal.focusheal!=0) {
					aa->poison=0;
					aa->pv=aa->pv+ac->normal.focusheal;
				}
				break;
			case 2:
				if(Dodge(*choixD, da, db, dc)==1) {
					db->pv=db->pv-(ac->normal.focusdamage*db->defence);
					if(ac->normal.poison==1) {
						db->poison=1;
					}
				} else {
					printf("Coup rate!!!\n");
				}
				if(ac->normal.focusheal!=0) {
					ab->poison=0;
					ab->pv=ab->pv+ac->normal.focusheal;
				}
				break;
			case 3:
				if(Dodge(*choixD, da, db, dc)==1) {
					dc->pv=dc->pv-(ac->normal.focusdamage*dc->defence);
					if(ac->normal.poison==1) {
						dc->poison=1;
					}
				} else {
					printf("Coup rate!!!\n");
				}
				if(ac->normal.focusheal!=0) {
					ac->poison=0;
					ac->pv=ac->pv+ac->normal.focusheal;
				}
				break;
			}
			break;
		case 2:
			ac->stamina-=8;
			if(ac->special.damage!=0) {
				da->pv=da->pv-(ac->special.damage*da->defence);
				db->pv=db->pv-(ac->special.damage*db->defence);
				dc->pv=dc->pv-(ac->special.damage*dc->defence);
			}
			if(ac->special.heal!=0) {
				aa->pv=aa->pv+ac->special.heal;
				ab->pv=ab->pv+ac->special.heal;
				ac->pv=ac->pv+ac->special.heal;
				aa->poison=0;
				ab->poison=0;
				ac->poison=0;
			}
			switch(*choixD) {
			case 1:
				if(Dodge(*choixD, da, db, dc)==1) {
					da->pv=da->pv-(ac->special.focusdamage*da->defence);
					if(ac->special.poison==1) {
						da->poison=1;
					}
				} else {
					printf("Coup rate!!!\n");
				}
				if(ac->special.focusheal!=0) {
					aa->poison=0;
					aa->pv=aa->pv+ac->special.focusheal;
				}
				break;
			case 2:
				if(Dodge(*choixD, da, db, dc)==1) {
					db->pv=db->pv-(ac->special.focusdamage*db->defence);
					if(ac->special.poison==1) {
						db->poison=1;
					}
				} else {
					printf("Coup rate!!!\n");
				}
				if(ac->special.focusheal!=0) {
					ab->poison=0;
					ab->pv=ab->pv+ac->special.focusheal;
				}
				break;
			case 3:
				if(Dodge(*choixD, da, db, dc)==1) {
					dc->pv=dc->pv-(ac->special.focusdamage*dc->defence);
					if(ac->special.poison==1) {
						dc->poison=1;
					}
				} else {
					printf("Coup rate!!!\n");
				}
				if(ac->special.focusheal!=0) {
					ac->poison=0;
					ac->pv=ac->pv+ac->special.focusheal;
				}
				break;
			}
			break;
		case 3:
			ac->utiliunique=1;
			if(ac->unique.damage!=0) {
				da->pv=da->pv-(ac->unique.damage*da->defence);
				db->pv=db->pv-(ac->unique.damage*db->defence);
				dc->pv=dc->pv-(ac->unique.damage*dc->defence);
			}
			if(ac->unique.heal!=0) {
				aa->pv=aa->pv+ac->unique.heal;
				ab->pv=ab->pv+ac->unique.heal;
				ac->pv=ac->pv+ac->unique.heal;
				aa->poison=0;
				ab->poison=0;
				ac->poison=0;
			}
			switch(*choixD) {
			case 1:
				if(Dodge(*choixD, da, db, dc)==1) {
					da->pv=da->pv-(ac->unique.focusdamage*da->defence);
					if(ac->unique.poison==1) {
						da->poison=1;
					}
				} else {
					printf("Coup rate!!!\n");
				}
				if(ac->unique.focusheal!=0) {
					aa->poison=0;
					aa->pv=aa->pv+ac->unique.focusheal;
				}
				break;
			case 2:
				if(Dodge(*choixD, da, db, dc)==1) {
					db->pv=db->pv-(ac->unique.focusdamage*db->defence);
					if(ac->unique.poison==1) {
						db->poison=1;
					}
				} else {
					printf("Coup rate!!!\n");
				}
				if(ac->unique.focusheal!=0) {
					ab->poison=0;
					ab->pv=ab->pv+ac->unique.focusheal;
				}
				break;
			case 3:
				if(Dodge(*choixD, da, db, dc)==1) {
					dc->pv=dc->pv-(ac->unique.focusdamage*dc->defence);
					if(ac->unique.poison==1) {
						dc->poison=1;
					}
				} else {
					printf("Coup rate!!!\n");
				}
				if(ac->unique.focusheal!=0) {
					ac->poison=0;
					ac->pv=ac->pv+ac->unique.focusheal;
				}
				break;
			}
			break;
		}
		break;
	}
}





void Checkup(Bot *ja, Bot *jb, Bot *jc, Bot *ra, Bot *rb, Bot *rc) {
	if(ja->poison==1) {
		ja->pv=ja->pv-10;
	}
	if(jb->poison==1) {
		jb->pv=jb->pv-10;
	}
	if(jc->poison==1) {
		jc->pv=jc->pv-10;
	}
	if(ra->poison==1) {
		ra->pv=ra->pv-10;
	}
	if(rb->poison==1) {
		rb->pv=rb->pv-10;
	}
	if(rc->poison==1) {
		rc->pv=rc->pv-10;
	}
	if(ja->pv<=0) {
		ja->dead=1;
	}
	if(jb->pv<=0) {
		jb->dead=1;
	}
	if(jc->pv<=0) {
		jc->dead=1;
	}
	if(ra->pv<=0) {
		ra->dead=1;
	}
	if(rb->pv<=0) {
		rb->dead=1;
	}
	if(rc->pv<=0) {
		rc->dead=1;
	}
	if(ja->dead==1) {
		ja->pv=0;
		ja->stamina=-1;
	}
	if(jb->dead==1) {
		jb->pv=0;
		jb->stamina=-1;
	}
	if(jc->dead==1) {
		jc->pv=0;
		jc->stamina=-1;
	}
	if(ra->dead==1) {
		ra->pv=0;
		ra->stamina=-1;
	}
	if(rb->dead==1) {
		rb->pv=0;
		rb->stamina=-1;
	}
	if(rc->dead==1) {
		rc->pv=0;
		rc->stamina=-1;
	}
	if(ja->pv>=ja->pvmax) {
		ja->pv=ja->pvmax;
	}
	if(jb->pv>=jb->pvmax) {
		jb->pv=jb->pvmax;
	}
	if(jc->pv>=jc->pvmax) {
		jc->pv=jc->pvmax;
	}
	if(ra->pv>=ra->pvmax) {
		ra->pv=ra->pvmax;
	}
	if(rb->pv>=rb->pvmax) {
		rb->pv=rb->pvmax;
	}
	if(rc->pv>=rc->pvmax) {
		rc->pv=rc->pvmax;
	}
	ja->stamina+=1;
	jb->stamina+=1;
	jc->stamina+=1;
	ra->stamina+=1;
	rb->stamina+=1;
	rc->stamina+=1;
	if(ja->stamina>16) {
		ja->stamina=16;
	}
	if(jb->stamina>16) {
		jb->stamina=16;
	}
	if(jc->stamina>16) {
		jc->stamina=16;
	}
	if(ra->stamina>16) {
		ra->stamina=16;
	}
	if(rb->stamina>16) {
		rb->stamina=16;
	}
	if(rc->stamina>16) {
		rc->stamina=16;
	}
	printf("\n\n\n");
}


int main() {
	int fin=0;
	int choixD=0;
	int choixA=0;
	int choixP=0;
	int sexy=0;
	int crashBandicoot=0;
	Bot ja=Characterbuilder(1000);
	Bot jb=Characterbuilder(1000);
	Bot jc=Characterbuilder(1000);
	Bot ba=Characterbuilder(1000);
	Bot bb=Characterbuilder(1000);
	Bot bc=Characterbuilder(1000);
	int dif=0;
	int mode=0;
	char *nameA=malloc(sizeof(char)*NAMESIZE);
	if(nameA==NULL) {
		exit(1);
	}
	printf("Nom du joueur A (20 caracteres MAX sans espace)--> ");
	scanf("%s", nameA);
	do {
		printf("Choisir solo: 0 ou Multijoueur: 1 |--> ");
		scanf("%d\n", &mode);
	}
	while(mode!=1 && mode!=0);
	char *nameB=malloc(sizeof(char)*NAMESIZE);
	if(nameB==NULL) {
		exit(1);
	}
	if(mode==1) {
		printf("Nom du joueur B (20 caracteres MAX sans espace)--> ");
		scanf("%s\n", nameB);
	    printf("Joueur A choisie son premier personnage... \n");
	    AffichPersoChoix(27, 120, 1, 1, &ja);
	    printf("Joueur B choisie son premier personnage... \n");
		AffichPersoChoix(27, 120, 1, 1, &ba);
		printf("Joueur A choisie son deuxieme personnage... \n");
		AffichPersoChoix(27, 120, 1, 1, &jb);
		printf("Joueur B choisie son deuxieme personnage... \n");
		AffichPersoChoix(27, 120, 1, 1, &bb);
		printf("Joueur A choisie son troixieme personnage... \n");
		AffichPersoChoix(27, 120, 1, 1, &jc);
		printf("Joueur B choisie son troixieme personnage... \n");
		AffichPersoChoix(27, 120, 1, 1, &bc);
	} else {
		do {
			printf("Choisir sa difficulte (1, 2 ou 3)--> ");
			scanf("%d", &dif);
		}
		while(dif!=1 && dif!=2 && dif!=3);
		nameB="Computer";
		printf("Le joueur choisie son premier personnage... \n");
		AffichPersoChoix(27, 120, 1, 1, &ja);
		do{
		    printf("Selectioner un Buny pour les détailes (1-16): ");
		    scanf("%d\n", &sexy);
		}
		while(sexy!=1 && sexy!=2 && sexy!=3 && sexy!=4 && sexy!=5 && sexy!=6 && sexy!=7 && sexy!=8 && sexy!=9 && sexy!=10 && sexy!=11 && sexy!=12 && sexy!=13 && sexy!=14 && sexy!=15 && sexy!=16 && sexy!=100);
		crashBandicoot=AffichPersoAttaque(sexy, a);
	    if(crashBandicoot==2){
	        AffichPersoChoix(27, 120, 1, 1, &ja);
	    }
		printf("Le joueur choisie son deuxieme personnage... \n");
		AffichPersoChoix(27, 120, 1, 1, &jb);
		printf("Le joueur choisie son troixieme personnage... \n");
		AffichPersoChoix(27, 120, 1, 1, &jc);
	}
	do {
		Turn(1, mode, &dif, &choixP, &choixA, &choixD, &ja, &jb, &jc, &ba, &bb, &bc, nameA, nameB);
		Checkup(&ja, &jb, &jc, &ba, &bb, &bc);
		if((ja.dead==1 && jb.dead==1 && jc.dead==1) || (ba.dead==1 && bb.dead==1 && bc.dead==1)) {
			fin=1;
		} else {
			fin=0;
		}
		Turn(0, mode, &dif, &choixP, &choixA, &choixD, &ba, &bb, &bc, &ja, &jb, &jc, nameA, nameB);
		Checkup(&ja, &jb, &jc, &ba, &bb, &bc);
		if((ja.dead==1 && jb.dead==1 && jc.dead==1) || (ba.dead==1 && bb.dead==1 && bc.dead==1)) {
			fin=1;
		} else {
			fin=0;
		}
	}
	while(fin==0);
	if(ja.dead==1 && jb.dead==1 && jc.dead==1 && ba.dead==1 && bb.dead==1 && bc.dead==1) {
		printf("Egalite\n");
		exit(0);
	} else if(ja.dead==1 && jb.dead==1 && jc.dead==1) {
		printf("Le joueur A a perdu\n");
		exit(0);
	} else if(ba.dead==1 && bb.dead==1 && bc.dead==1) {
		printf("Le joueur B a perdu\n");
		exit(0);
	}
	free(nameA);
	free(nameB);
	return 0;
}
