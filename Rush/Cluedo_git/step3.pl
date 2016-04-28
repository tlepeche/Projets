change_state(droite,Loup,Chevre,Chou,gauche,Loup,Chevre,Chou).
change_state(gauche,Loup,Chevre,Chou,droite,Loup,Chevre,Chou).
change_state(droite,droite,Chevre,Chou,gauche,gauche,Chevre,Chou).
change_state(gauche,gauche,Chevre,Chou,droite,droite,Chevre,Chou).
change_state(droite,Loup,droite,Chou,gauche,Loup,gauche,Chou).
change_state(gauche,Loup,gauche,Chou,droite,Loup,droite,Chou).
change_state(droite,Loup,Chevre,droite,gauche,Loup,Chevre,gauche).
change_state(gauche,Loup,Chevre,gauche,droite,Loup,Chevre,droite).


illegal(droite,gauche,gauche,_).
illegal(gauche,droite,droite,_).
illegal(droite,_,gauche,gauche).
illegal(gauche,_,droite,droite).

solve([(droite,droite,droite,droite)|L],Path) :-
	reverse([(droite,droite,droite,droite)|L],Path).

solve([(Peon,Loup,Chevre,Chou)|L],Path) :-
	change_state(Peon,Loup,Chevre,Chou,Peon0,Loup0,Chevre0,Chou0),
	\+ illegal(Peon0,Loup0,Chevre0,Chou0),
	\+ member((Peon0,Loup0,Chevre0,Chou0),L),
	solve([(Peon0 ,Loup0 ,Chevre0 ,Chou0),(Peon,Loup,Chevre,Chou)|L],Path).

resolve :-
	solve([(gauche,gauche,gauche,gauche)],L),
	afficher_init,
	afficher_res(L),
	!.


afficher_res([X,Y]) :-
	afficher([X],[Y]),
	writenl(''),
	afficher([Y],[Y]),
	!.

afficher_res([X,Y|Z]) :-
	afficher([X],[Y]),
	writenl(''),
	append([Y],Z,L),
	afficher_res(L).

afficher([(Peon,Loup,Chevre,Chou)],[(Peon0,Loup0,Chevre0,Chou0)]) :-
	afficher_mouv(Peon, Peon0, 'Peon'),
	afficher_mouv(Loup,Loup0,'Loup'),
	afficher_mouv(Chevre,Chevre0,'Chevre'),
	afficher_mouv(Chou,Chou0,'Chou').

afficher_mouv(X,Y,C) :-
	X == gauche, Y == gauche,
	write('Est sur la rive gauche     : '), writenl(C);
	X == gauche, Y == droite,
	write('Va vers la rive droite     : '), writenl(C);
	X == droite, Y == gauche,
	write('Revient sur la rive gauche : '), writenl(C);
	X == droite, Y == droite,
	write('Est sur la rive droite     : '), writenl(C).

afficher_init :-
	writenl('Est sur la rive gauche     : Peon'),
	writenl('Est sur la rive gauche     : Loup'),
	writenl('Est sur la rive gauche     : Chevre'),
	writenl('Est sur la rive gauche     : Chou'), nl.
