couple(marc, anne).
couple(luc, betty).
couple(jules, lisa).
couple(leon, sylvie).
couple(loic, eve).
couple(paul, julie).
hom(gerard).
hom(jean).
hom(jacques).
hom(herve).
fem(valerie).

parent(jules, marc).
parent(jean, marc).
parent(lisa, luc).
parent(leon, marc).
parent(loic, luc).
parent(gerard, luc).
parent(jacques, jules).
parent(herve, leon).
parent(paul, loic).
parent(julie, leon).
parent(valerie, loic).

homme(X) :- hom(X).
homme(X) :- couple(X, _).

femme(X) :- fem(X).
femme(X) :- couple(_, X).

mari_de(X, Y) :- couple(X, Y).

femme_de(X, Y) :- couple(Y, X).

enfant_de(X, Y) :- parent(X, Y).
enfant_de(X, Z) :- parent(X, Y), couple(Y, Z).

beaupere_de(X, Z) :- couple(Z, Y), enfant_de(Y, X), homme(X).

bellemere_de(Z, X) :- couple(X, Y), enfant_de(Y, Z), femme(Z).

ancetre_de(X, Y) :- enfant_de(Y, X).
ancetre_de(X, Z) :- enfant_de(Y, X), ancetre_de(Y, Z).