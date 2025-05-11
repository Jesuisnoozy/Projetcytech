#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <errno.h>
#define NAMESIZE 21
typedef struct {
	char *name;
	int damage, focusdamage, heal, focusheal, poison, stun, confused;
} Attack;

typedef struct {
	char *name;
	int agility, pvmax, stamina, poison, stun, confused, pv, dead, utiliunique;
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

Bot Builder(float defen, int agil, int health, int norm, int spec, int uniq) {
	Bot a;
	a.defence=defen/100;
	a.agility=agil;
	a.pvmax=health;
	a.normal=Attackbuilder(norm);
	a.special=Attackbuilder(spec);
	a.unique=Attackbuilder(uniq);
	a.pv=health;
	a.poison=0;
	a.stun=0;
	a.confused=0;
	a.stamina=4;
	a.dead=0;
	a.utiliunique=0;
	return a;
}

Bot Characterbuilder(int num) {
	Bot a;
	switch(num) {
	// defence, agility, points de vie, att normal, att special, att unique)
	case 1:
		a=Builder(25, 5, 200, 0, 100, 200);
		a.name=malloc(sizeof(char)*4);
		if(a.name==NULL) {
			exit(1);
		}
		strcpy(a.name, "Bob");
		break;
	
	case 1000:
		a=Builder(5, 0, 150, 0, 100, 200);
		a.name=malloc(sizeof(char)*5);
		if(a.name==NULL) {
			exit(1);
		}
		strcpy(a.name, "Test");
		break;
	case 1001:
		a=Builder(5, 20, 150, 1, 101, 201);
		a.name=malloc(sizeof(char)*11);
		if(a.name==NULL) {
			exit(1);
		}
		strcpy(a.name, "TestPoison");
		break;
	case 1002:
		a=Builder(5, 20, 150, 2, 102, 202);
		a.name=malloc(sizeof(char)*14);
		if(a.name==NULL) {
			exit(1);
		}
		strcpy(a.name, "TestMaxHealth");
		break;
	case 1003:
		a=Builder(5, 80, 150, 0, 100, 200);
		a.name=malloc(sizeof(char)*10);
		if(a.name==NULL) {
			exit(1);
		}
		strcpy(a.name, "DodgeTest");
		break;
	default:
		printf("ERREUR: Mauvais numero saisie pour le switchcase Characterbuilder\n");
		exit(1);
	}
	return a;
}

int MinMax(int *x, int a, int b, int c){
    int max=-1000;
    if(a>max && a!=0){
        max=a;
        *x=1;
    }
    if(b>max && b!=0){
        max=b;
        *x=2;
    }
    if(c>max && c!=0){
        max=c;
        *x=3;
    }
    if(max==-1000){ 
        printf("ERREUR: variable 'max' pour le switchcase MinMax\n");
        exit(1);
    }
    return max;
}

int CheckPerso1(int choix, Bot *ja, Bot*jb, Bot *jc){
    switch(choix){
    case 1:
        if(ja->dead==1 || ja->stun==1){
            return 1;
        }else{ 
            return 0;
            
        }
    case 2:
        if(jb->dead==1 || jb->stun==1){
            return 1;
        }else{ 
            return 0;
            
        }
    case 3:
        if(jc->dead==1 || jc->stun==1){
            return 1;
        }else{ 
            return 0;
            
        }
    default:
        return 1;
    }
}
int CheckPerso2(int choix, Bot *ja, Bot*jb, Bot *jc){
    switch(choix) {
    case 1:
        if(ja->dead==1){
            return 1;
        }else{ 
            return 0;
            
        }
    case 2:
        if(jb->dead==1){
            return 1;
        }else{ 
            return 0;
            
        }
    case 3:
        if(jc->dead==1){
            return 1;
        }else{ 
            return 0;
            
        }
    default:
        return 1;
    }
}

int CheckStamina(int choix, Bot *ja, Bot*jb, Bot *jc) {
    switch(choix) {
    case 1: 
        if(ja->stamina<2){
            return 1;
        }else if((ja->dead==1 && jb->dead==1) || (ja->dead==1 && jc->dead==1) || (jb->dead==1 && jb->dead==1) || (ja->dead==1 && jb->dead==1 && jc->dead==1)){
            return 1; // bug fixed (._.)
        }else{
            return 0;
        }
    case 2: 
        if(ja->stamina<7){
            return 1;
        }else{
            return 0;
        }  
    case 3: 
        if(ja->utiliunique==1){
            return 1;
        }else{
            return 0;
        }
    default:
        return 1;
    }
}

int Dodge(int choixD, Bot *ra, Bot *rb, Bot *rc){ // return 0 => dodged
    float x;
    x=rand()%101;
    switch(choixD){
    case 1:
        if(x>ra->agility){
            return 1;
        }else{
            return 0;
        }
    break;
    case 2:
        if(x>rb->agility){
            return 1;
        }else{
            return 0;
        }
    break;
    case 3:
        if(x>rc->agility){
            return 1;
        }else{
            return 0;
        }
    break;
    default:
        printf("ERREUR: Mauvais numero saisie pour le switchcase Dodge\n");
		exit(1);
    }
}

void Computer(int *dif, int *choixP, int *choixA, int *choixD, Bot *ra, Bot *rb, Bot *rc, Bot *ja, Bot *jb, Bot *jc){
    int wtf, wtp;  // \(^-^)/
    int aa=4;
    int ab=4;
    int ac=4;
    int x; // attaquant séléctionné
    int y=MinMax(&x, ra->stamina, rb->stamina, rc->stamina); // Max stamina
    int z; // joueur visé
    int v=-MinMax(&z, -(ja->pv), -(jb->pv), -(jc->pv)); // Min pv joueur visé
    switch(*dif){
        case 1:
        do {
            *choixP=(rand()%3)+1;
		}
		while(CheckPerso1(*choixP, ra, rb, rc));
		do {
			*choixA=(rand()%3)+1;
		}
		while(CheckStamina(*choixA, ra, rb, rc));
		do {
			*choixD=(rand()%3)+1;
		}
		while(CheckPerso2(*choixD, ja, jb, jc));
        break;
        case 2:
        *choixP=(rand()%3)+1;
        *choixA=(rand()%3)+1;
        *choixD=(rand()%3)+1;
        break;
        case 3:
        if(z==1){
            if(ja->pv<ra->normal.damage && ra->stamina>2){
                aa=1;
            }else if(ja->pv<ra->special.damage && ra->stamina>7){
                aa=2;
            }else{
                aa=3;
            }
            if(ja->pv<rb->normal.damage && rb->stamina>2){
                ab=1;
            }else if(ja->pv<rb->special.damage && rb->stamina>7){
                ab=2;
            }else{
                ab=3;
            }
            if(ja->pv<rc->normal.damage && rc->stamina>2){
                ac=1;
            }else if(ja->pv<rc->special.damage && rc->stamina>7){
                ac=2;
            }else{
                ac=3;
            }
            wtf=-MinMax(&wtp, -aa, -ab, -ac);
            if(wtf<3){
                *choixP=wtp;
                *choixA=wtf;
                *choixD=z;
            }else{
                if(y>8 && x!=0){
                    if(x==1){
                    aa=2;
                    ab=0;
                    ac=0;
                }else if(x==2){
                    aa=0;
                    ab=2;
                    ac=0;
                }else{
                    aa=0;
                    ab=0;
                    ac=2;
                }
                if(aa==2 && ab!=2 && ac!=2){
                    *choixP=1;
                    *choixA=2;
                    *choixD=z;
                }else if(aa!=2 && ab==2 && ac!=2){
                    *choixP=2;
                    *choixA=2;
                    *choixD=z;
                }else if(aa!=2 && ab!=2 && ac==2){
                    *choixP=3;
                    *choixA=2;
                    *choixD=z;
                }else if((aa==2 && ab==2) || (aa==2 && ac==2) || (aa==2 && ab==2 && ac==2)){
                    *choixP=1;
                    *choixA=2;
                    *choixD=z;
                }else{
                    *choixP=2;
                    *choixA=2;
                    *choixD=z;
                }
                }else{
                    *choixP=x;
                    *choixA=1;
                    *choixD=z;
                }
            }
        }else if(z==2){
            if(jb->pv<ra->normal.damage && ra->stamina>2){
                aa=1;
            }else if(jb->pv<ra->special.damage && ra->stamina>7){
                aa=2;
            }else{
                aa=3;
            }
            if(jb->pv<rb->normal.damage && rb->stamina>2){
                ab=1;
            }else if(jb->pv<rb->special.damage && rb->stamina>7){
                ab=2;
            }else{
                ab=3;
            }
            if(jb->pv<rc->normal.damage && rc->stamina>2){
                ac=1;
            }else if(jb->pv<rc->special.damage && rc->stamina>7){
                ac=2;
            }else{
                ac=3;
            }
            wtf=-MinMax(&wtp, -aa, -ab, -ac);
            if(wtf<3){
                *choixP=wtp;
                *choixA=wtf;
                *choixD=z;
            }else{
                if(y>8 && x!=0){
                    if(x==1){
                    aa=2;
                    ab=0;
                    ac=0;
                }else if(x==2){
                    aa=0;
                    ab=2;
                    ac=0;
                }else{
                    aa=0;
                    ab=0;
                    ac=2;
                }
                if(aa==2 && ab!=2 && ac!=2){
                    *choixP=1;
                    *choixA=2;
                    *choixD=z;
                }else if(aa!=2 && ab==2 && ac!=2){
                    *choixP=2;
                    *choixA=2;
                    *choixD=z;
                }else if(aa!=2 && ab!=2 && ac==2){
                    *choixP=3;
                    *choixA=2;
                    *choixD=z;
                }else if((aa==2 && ab==2) || (aa==2 && ac==2) || (aa==2 && ab==2 && ac==2)){
                    *choixP=1;
                    *choixA=2;
                    *choixD=z;
                }else{
                    *choixP=2;
                    *choixA=2;
                    *choixD=z;
                }
                }else{
                    *choixP=x;
                    *choixA=1;
                    *choixD=z;
                }
            }
        }else{
            if(jc->pv<ra->normal.damage && ra->stamina>2){
                aa=1;
            }else if(jc->pv<ra->special.damage && ra->stamina>7){
                aa=2;
            }else{
                aa=3;
            }
            if(jc->pv<rb->normal.damage && rb->stamina>2){
                ab=1;
            }else if(jc->pv<rb->special.damage && rb->stamina>7){
                ab=2;
            }else{
                ab=3;
            }
            if(jc->pv<rc->normal.damage && rc->stamina>2){
                ac=1;
            }else if(jc->pv<rc->special.damage && rc->stamina>7){
                ac=2;
            }else{
                ac=3;
            }
            wtf=-MinMax(&wtp, -aa, -ab, -ac);
            if(wtf<3){
                *choixP=wtp;
                *choixA=wtf;
                *choixD=z;
            }else{
                if(y>8 && x!=0){
                    if(x==1){
                    aa=2;
                    ab=0;
                    ac=0;
                }else if(x==2){
                    aa=0;
                    ab=2;
                    ac=0;
                }else{
                    aa=0;
                    ab=0;
                    ac=2;
                }
                if(aa==2 && ab!=2 && ac!=2){
                    *choixP=1;
                    *choixA=2;
                    *choixD=z;
                }else if(aa!=2 && ab==2 && ac!=2){
                    *choixP=2;
                    *choixA=2;
                    *choixD=z;
                }else if(aa!=2 && ab!=2 && ac==2){
                    *choixP=3;
                    *choixA=2;
                    *choixD=z;
                }else if((aa==2 && ab==2) || (aa==2 && ac==2) || (aa==2 && ab==2 && ac==2)){
                    *choixP=1;
                    *choixA=2;
                    *choixD=z;
                }else{
                    *choixP=2;
                    *choixA=2;
                    *choixD=z;
                }
                }else{
                    *choixP=x;
                    *choixA=1;
                    *choixD=z;
                }
            }
        }
        break;
        default:
        printf("ERREUR: Mauvais numero saisie pour le switchcase Computer\n");
		exit(1);
    }
}

void Turn(int who, int *dif, int *choixP, int *choixA, int *choixD, Bot *aa, Bot *ab, Bot *ac, Bot *da, Bot *db, Bot *dc) {
    // choixP= selection du personnage, choixA= choix de l'attaque, choixD= choix du personnage affectC)
	if(who==0) {
		do {
			printf("Choisir son personnage (1, 2 ou 3)\n");
			scanf("%d", choixP);
		}
		while(CheckPerso1(*choixP, aa, ab, ac));
		do {
			printf("Choisir son attaque (1, 2 ou 3)\n");
			scanf("%d", choixA);
		}
		while(CheckStamina(*choixA, aa, ab, ac));
		do {
			printf("Choisir le personnage affecte (1, 2 ou 3)\n");
			scanf("%d", choixD);
		}
		while(CheckPerso2(*choixD, da, db, dc));
	} else { 
	    Computer(dif, choixP, choixA, choixD, aa, ab, ac, da, db, dc);
	    // l'IA qui va choisir l'attaque si 'who' est different de 0
	    printf("P:%d A:%d D:%d\n", *choixP, *choixA, *choixD);
	}
	switch(*choixP) {
	case 1:
	if (aa->confused==1){ 
	    if(rand()%2){ break; 
	    }
	}
		switch(*choixA) {
		case 1:
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
			    if(Dodge(*choixD, da, db, dc)){
				da->pv=da->pv-(aa->normal.focusdamage*da->defence);
			    if(aa->normal.poison==1) {
			    da->poison=1;
				}    
			    }
				if(aa->normal.focusheal!=0){
				   aa->poison=0; 
				   aa->pv=aa->pv+aa->normal.focusheal;
				}
				break;
			case 2:
			    if(Dodge(*choixD, da, db, dc)){
				db->pv=db->pv-(aa->normal.focusdamage*db->defence);
			    if(aa->normal.poison==1) {
			    db->poison=1;
				}    
			    }
				if(aa->normal.focusheal!=0){
				   ab->poison=0;
				   ab->pv=ab->pv+aa->normal.focusheal;
				}
				break;
			case 3:
			    if(Dodge(*choixD, da, db, dc)){
				dc->pv=dc->pv-(aa->normal.focusdamage*dc->defence);
			    if(aa->normal.poison==1) {
			    dc->poison=1;
				}    
			    }
				if(aa->normal.focusheal!=0){
				   ac->poison=0;
				   ac->pv=ac->pv+aa->normal.focusheal;
				}
				break;
			}
			break;
		case 2:
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
			    if(Dodge(*choixD, da, db, dc)){
				da->pv=da->pv-(aa->special.focusdamage*da->defence);
			    if(aa->special.poison==1) {
			    da->poison=1;
			    }    
			    }
				if(aa->special.focusheal!=0){
				   aa->poison=0;
				   aa->pv=aa->pv+aa->special.focusheal;
				}
				break;
			case 2:
			    if(Dodge(*choixD, da, db, dc)){
				db->pv=db->pv-(aa->special.focusdamage*db->defence);
			    if(aa->special.poison==1) {
			    db->poison=1;
			    }    
			    }
				if(aa->special.focusheal!=0){
				   ab->poison=0;
				   ab->pv=ab->pv+aa->special.focusheal;
				}
				break;
			case 3:
			    if(Dodge(*choixD, da, db, dc)){
				dc->pv=dc->pv-(aa->special.focusdamage*dc->defence);
			    if(aa->special.poison==1) {
			    dc->poison=1;
			    }    
			    }
				if(aa->special.focusheal!=0){
				   ac->poison=0;
				   ac->pv=ac->pv+aa->special.focusheal;
				}
				break;
			}
			break;
		case 3:
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
			    if(Dodge(*choixD, da, db, dc)){
				da->pv=da->pv-(aa->unique.focusdamage*da->defence);
			    if(aa->unique.poison==1) {
			    da->poison=1;
			    }    
			    }
				if(aa->unique.focusheal!=0){
				   aa->poison=0;
				   aa->pv=aa->pv+aa->unique.focusheal;
				}
				break;
			case 2:
			    if(Dodge(*choixD, da, db, dc)){
				db->pv=db->pv-(aa->unique.focusdamage*db->defence);
			    if(aa->unique.poison==1) {
			    db->poison=1;
			    }    
			    }
				if(aa->unique.focusheal!=0){
				   ab->poison=0;
				   ab->pv=ab->pv+aa->unique.focusheal;
				}
				break;
			case 3:
			    if(Dodge(*choixD, da, db, dc)){
				dc->pv=dc->pv-(aa->unique.focusdamage*dc->defence);
			    if(aa->unique.poison==1) {
			    dc->poison=1;
			    }    
			    }
				if(aa->unique.focusheal!=0){
				   ac->poison=0;
				   ac->pv=ac->pv+aa->unique.focusheal;
				}
				break;
			}
			break;
		}
		break;
	case 2:
	if (ab->confused==1){ 
	    if(rand()%2){ break; 
	    }
	}
		switch(*choixA) {
		case 1:
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
			    if(Dodge(*choixD, da, db, dc)){
				da->pv=da->pv-(ab->normal.focusdamage*da->defence);
			    if(ab->normal.poison==1) {
			    da->poison=1;
			    }    
			    }
				if(ab->normal.focusheal!=0){
				   aa->poison=0;
				   aa->pv=aa->pv+ab->normal.focusheal;
				}
				break;
			case 2:
			    if(Dodge(*choixD, da, db, dc)){
				db->pv=db->pv-(ab->normal.focusdamage*db->defence);
			    if(ab->normal.poison==1) {
			    db->poison=1;
			    }    
			    }
				if(ab->normal.focusheal!=0){
				   ab->poison=0;
				   ab->pv=ab->pv+ab->normal.focusheal;
				}
				break;
			case 3:
			    if(Dodge(*choixD, da, db, dc)){
				dc->pv=dc->pv-(ab->normal.focusdamage*dc->defence);
			    if(ab->normal.poison==1) {
			    dc->poison=1;
			    }    
			    }
				if(ab->normal.focusheal!=0){
				   ac->poison=0;
				   ac->pv=ac->pv+ab->normal.focusheal;
				}
				break;
			}
			break;
		case 2:
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
			    if(Dodge(*choixD, da, db, dc)){
				da->pv=da->pv-(ab->special.focusdamage*da->defence);
			    if(ab->special.poison==1) {
			    da->poison=1;
			    }    
			    }
				if(ab->special.focusheal!=0){
				   aa->poison=0;
				   aa->pv=aa->pv+ab->special.focusheal;
				}
				break;
			case 2:
			    if(Dodge(*choixD, da, db, dc)){
				db->pv=db->pv-(ab->special.focusdamage*db->defence);
			    if(ab->special.poison==1) {
			    db->poison=1;
			    }    
			    }
				if(ab->special.focusheal!=0){
				   ab->poison=0;
				   ab->pv=ab->pv+ab->special.focusheal;
				}
				break;
			case 3:
			    if(Dodge(*choixD, da, db, dc)){
				dc->pv=dc->pv-(ab->special.focusdamage*dc->defence);
			    if(ab->special.poison==1) {
			    dc->poison=1;
			    }    
			    }
				if(ab->special.focusheal!=0){
				   ac->poison=0;
				   ac->pv=ac->pv+ab->special.focusheal;
				}
				break;
			}
			break;
		case 3:
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
			    if(Dodge(*choixD, da, db, dc)){
				da->pv=da->pv-(ab->unique.focusdamage*da->defence);
			    if(ab->unique.poison==1) {
			    da->poison=1;
			    }    
			    }
				if(ab->unique.focusheal!=0){
				   aa->poison=0;
				   aa->pv=aa->pv+ab->unique.focusheal;
				}
				break;
			case 2:
			    if(Dodge(*choixD, da, db, dc)){
				db->pv=db->pv-(ab->unique.focusdamage*db->defence);
			    if(ab->unique.poison==1) {
			    db->poison=1;
			    }    
			    }
				if(ab->unique.focusheal!=0){
				   ab->poison=0;
				   ab->pv=ab->pv+ab->unique.focusheal;
				}
				break;
			case 3:
			    if(Dodge(*choixD, da, db, dc)){
				dc->pv=dc->pv-(ab->unique.focusdamage*dc->defence);
			    if(ab->unique.poison==1) {
			    dc->poison=1;
			    }    
			    }
				if(ab->unique.focusheal!=0){
				   ac->poison=0;
				   ac->pv=ac->pv+ab->unique.focusheal;
				}
				break;
			}
			break;
		}
		break;
	case 3:
	if (aa->confused==1){ 
	    if(rand()%2){ break; 
	    }
	}
		switch(*choixA) {
		case 1:
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
			    if(Dodge(*choixD, da, db, dc)){
				da->pv=da->pv-(ac->normal.focusdamage*da->defence);
			    if(ac->normal.poison==1) {
			    da->poison=1;
			    }    
			    }
				if(ac->normal.focusheal!=0){
				   aa->poison=0;
				   aa->pv=aa->pv+ac->normal.focusheal;
				}
				break;
			case 2:
			    if(Dodge(*choixD, da, db, dc)){
				db->pv=db->pv-(ac->normal.focusdamage*db->defence);
			    if(ac->normal.poison==1) {
			    db->poison=1;
		      	}    
			    }
				if(ac->normal.focusheal!=0){
				   ab->poison=0;
				   ab->pv=ab->pv+ac->normal.focusheal;
				}
				break;
			case 3:
			    if(Dodge(*choixD, da, db, dc)){
				dc->pv=dc->pv-(ac->normal.focusdamage*dc->defence);
			    if(ac->normal.poison==1) {
			    dc->poison=1;
			    }    
			    }
				if(ac->normal.focusheal!=0){
				   ac->poison=0;
				   ac->pv=ac->pv+ac->normal.focusheal;
				}
				break;
			}
			break;
		case 2:
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
			    if(Dodge(*choixD, da, db, dc)){
				da->pv=da->pv-(ac->special.focusdamage*da->defence);
			    if(ac->special.poison==1) {
			    da->poison=1;
			    }    
			    }
				if(ac->special.focusheal!=0){
				   aa->poison=0;
				   aa->pv=aa->pv+ac->special.focusheal;
				}
				break;
			case 2:
			    if(Dodge(*choixD, da, db, dc)){
				db->pv=db->pv-(ac->special.focusdamage*db->defence);
			    if(ac->special.poison==1) {
			    db->poison=1;
			    }    
			    }
				if(ac->special.focusheal!=0){
				   ab->poison=0;
			       ab->pv=ab->pv+ac->special.focusheal;
				}
				break;
			case 3:
			    if(Dodge(*choixD, da, db, dc)){
				dc->pv=dc->pv-(ac->special.focusdamage*dc->defence);
			    if(ac->special.poison==1) {
			    dc->poison=1;
			    }    
			    }
				if(ac->special.focusheal!=0){
				   ac->poison=0;
				   ac->pv=ac->pv+ac->special.focusheal;
				}
				break;
			}
			break;
		case 3:
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
			    if(Dodge(*choixD, da, db, dc)){
				da->pv=da->pv-(ac->unique.focusdamage*da->defence);
			    if(ac->unique.poison==1) {
			    da->poison=1;
			    }    
			    }
				if(ac->unique.focusheal!=0){
				   aa->poison=0;
				   aa->pv=aa->pv+ac->unique.focusheal;
				}
				break;
			case 2:
			    if(Dodge(*choixD, da, db, dc)){
				db->pv=db->pv-(ac->unique.focusdamage*db->defence);
			    if(ac->unique.poison==1) {
			    db->poison=1;
			    }   
			    }
				if(ac->unique.focusheal!=0){
				   ab->poison=0;
				   ab->pv=ab->pv+ac->unique.focusheal;
				}
				break;
			case 3:
			    if(Dodge(*choixD, da, db, dc)){
				dc->pv=dc->pv-(ac->unique.focusdamage*dc->defence);
			    if(ac->unique.poison==1) {
			    dc->poison=1;
			    }    
			    }
				if(ac->unique.focusheal!=0){
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
	if(ja->pv>=ja->pvmax){
		ja->pv=ja->pvmax;
	}
	if(jb->pv>=jb->pvmax){
		jb->pv=jb->pvmax;
	}
	if(jc->pv>=jc->pvmax){
		jc->pv=jc->pvmax;
	}
	if(ra->pv>=ra->pvmax){
		ra->pv=ra->pvmax;
	}
	if(rb->pv>=rb->pvmax){
		rb->pv=rb->pvmax;
	}
	if(rc->pv>=rc->pvmax){
		rc->pv=rc->pvmax;
	}
	if(ja->dead==1 && jb->dead==1 && jc->dead==1 && ra->dead==1 && rb->dead==1 && rc->dead==1) {
		printf("EgalitC)\n");
		exit(1);
	}
	if(ja->dead==1 && jb->dead==1 && jc->dead==1) {
		printf("Le joueur A a perdu\n");
		exit(1);
	}
	if(ra->dead==1 && rb->dead==1 && rc->dead==1) {
		printf("Le joueur B a perdu\n");
		exit(1);
	}
	ja->stamina+=1;
	jb->stamina+=1;
	jc->stamina+=1;
	ra->stamina+=1;
	rb->stamina+=1;
	rc->stamina+=1;
}

int main() {
    int choixD=0;
    int choixA=0;
    int choixP=0;
	Bot ja=Characterbuilder(1000);
	Bot jb=Characterbuilder(1000);
	Bot jc=Characterbuilder(1000);
	Bot ba=Characterbuilder(1000);
	Bot bb=Characterbuilder(1000);
	Bot bc=Characterbuilder(1000);
	int dif=0;
	do {
			printf("Choisir sa difficulté (1, 2 ou 3)\n");
			scanf("%d", &dif);
		}
		while(dif!=1 && dif!=2 && dif!=3);

    printf("===========================================================\n");
	for(int i=0; i<strlen(ja.name); i++) { // print name
		printf("%c", *(ja.name+i));
	}
	for(int i=0; i<strlen(ja.normal.name); i++) {
		printf("%c", *(ja.normal.name+i));
	}
	printf("\n%d\n",ja.special.focusdamage);
	printf("\n%d\n",ba.pv);
	printf("\nJA HEALTH BEFORE: %d\n",ja.pv);
	printf("===========================================================\n");
	// Turn(0, &dif, &choixP, &choixA, &choixD, &ja, &jb, &jc, &ba, &bb, &bc);
	Turn(1, &dif, &choixP, &choixA, &choixD, &ba, &bb, &bc, &ja, &jb, &jc);
	printf("\n%d\n",ba.pv);
	printf("\nJA HEALTH AFTER Turn: %d\n",ja.pv);
	Checkup(&ja, &jb, &jc, &ba, &bb, &bc);
	printf("\n%d\n",ba.pv);
	printf("\nJA HEALTH AFTER Checkup: %d\n",ja.pv);
	printf("\nJB HEALTH AFTER Checkup: %d\n",jb.pv);
	printf("\nJC HEALTH AFTER Checkup: %d\n",jc.pv);
	printf("\nBotA HEALTH AFTER Checkup: %d\n",ba.pv);
	printf("\nBotB HEALTH AFTER Checkup: %d\n",bb.pv);
	printf("\nBotC HEALTH AFTER Checkup: %d\n",bc.pv);
	
	return 0;
}
