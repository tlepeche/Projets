liste_maisons([
maison(_, _, _, _, _),
maison(_, _, _, _, _),
maison(_, _, _, _, _),
maison(_, _, _, _, _),
maison(_, _, _, _, _)
]).

afficher_liste([H|T]) :- writenl(H), afficher_liste(T).
afficher_liste([]).

appartient_a(X, [X|_]).
appartient_a(X, [_|T]) :- appartient_a(X, T).

est_a_gauche_de(A, B, [A, B | _]).
est_a_gauche_de(A, B, [_|T]) :- est_a_gauche_de(A, B, T).

est_a_cote_de(A, B, [A, B | _]).
est_a_cote_de(A, B, [B, A | _]).
est_a_cote_de(A, B, [_| T]) :- est_a_cote_de(A, B, T).

resolve :-
liste_maisons(MAISONS),
appartient_a(maison(rouge, anglais, _, _, _), MAISONS),
appartient_a(maison(_, suedois, _, _, chiens), MAISONS),
appartient_a(maison(_, danois, the, _, _), MAISONS),
est_a_gauche_de(maison(verte, _, _, _, _), maison(blanche, _, _, _, _), MAISONS),
appartient_a(maison(verte, _, cafe, _, _), MAISONS),
appartient_a(maison(_, _, _, pall_mall, oiseaux), MAISONS),
appartient_a(maison(jaune, _, _, dunhill, _), MAISONS),
MAISONS = [_, _, maison(_, _, lait, _, _), _, _],
MAISONS = [maison(_, norvegien, _, _, _), _, _, _, _],
est_a_cote_de(maison(_, _, _, blend, _), maison(_, _, _, _, chats), MAISONS),
est_a_cote_de(maison(_, _, _, _, cheval), maison(_, _, _, dunhill, _), MAISONS),
appartient_a(maison(_, _, biere, blue_master, _), MAISONS),
appartient_a(maison(_, allemand, _, prince, _), MAISONS),
est_a_cote_de(maison(_, norvegien, _, _, _), maison(bleue, _, _, _, _), MAISONS),
est_a_cote_de(maison(_, _, _, blend, _), maison(_, _, eau, _, _), MAISONS),
appartient_a(maison(_, _, _, _, poisson), MAISONS),
afficher_liste(MAISONS).