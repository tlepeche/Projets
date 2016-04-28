resolve(N) :-
	X is 2^N-1,
	write('It will take '),
	write(X),
	writenl(' move(s) to solve this problem'),
	move(N, left, center, right, 1),
	writenl('----------').


move(1,X,Y,_,A) :- 
	write('Move '),
	write(A),
	write(' : move top disk from '), 
	write(X), 
	write(' to '), 
	writenl(Y).


move(N,X,Y,Z,A) :- 
	N>1, 
	M is N-1, 
	move(M,X,Z,Y,A + 1), 
	move(1,X,Y,_,A),
	move(M,Z,Y,X,A + 1).