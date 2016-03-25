sumsq_even([], 0).	

sumsq_even([H|T], Sum) :-
	1 is H mod 2 ->
	%if odd, ignore the Head
	sumsq_even(T, Rest),
	Sum is Rest;
	%else add H*H to the Rest
	sumsq_even(T, Rest),
	Sum is H*H + Rest.


all_like(What, []).

all_like(What, [H|T]) :-
	all_like(What, T),
	findall(Who, likes(Who, What), List),
	member(H, List).
	
		

sqrt_table(N,N,R) :-
		Temp is sqrt(N),
		TempList =[N, Temp],
		R =[TempList].
sqrt_table(N,M,R) :-
		N>M->
		Next is N - 1,
		sqrt_table(Next, M, R1),
		Temp is sqrt(N),
		TempList =[N, Temp],
		R =[TempList|R1].		
		
		
chop_down([], []).

chop_down([E], NewList) :-
		NewList = [E].	

chop_down([E1, E2 | Tail], NewList) :-
		is_successive(E1, E2)->
		chop_down([E2 | Tail], TempList),
		NewList = TempList;
		chop_down([E2 | Tail], TempList),
		NewList = [E1|TempList].

is_successive(E1, E2) :-
		E1 is E2 + 1.


tree_eval(Value, tree(L, +, R), Eval) :-
		tree_eval(Value, L, EvalLeft),
		tree_eval(Value, R, EvalRight),
		Eval is EvalLeft + EvalRight,	
		!.
tree_eval(Value, tree(L, -, R), Eval) :-
		tree_eval(Value, L, EvalLeft),
		tree_eval(Value, R, EvalRight),
		Eval is EvalLeft - EvalRight,	
		!.
tree_eval(Value, tree(L, *, R), Eval) :-
		tree_eval(Value, L, EvalLeft),
		tree_eval(Value, R, EvalRight),
		Eval is EvalLeft * EvalRight,	
		!.
tree_eval(Value, tree(L, /, R), Eval) :-
		tree_eval(Value, L, EvalLeft),
		tree_eval(Value, R, EvalRight),
		Eval is EvalLeft / EvalRight,	
		!.
tree_eval(Value, tree(L, z, R), Eval) :-
		tree_eval(Value, L, EvalLeft),
		tree_eval(Value, R, EvalRight),
		Eval is Value,	
		!.
tree_eval(Value, tree(L, V, R), Eval) :-
		tree_eval(Value, L, EvalLeft),
		tree_eval(Value, R, EvalRight),
		Eval is V,	
		!.

tree_eval(Value, empty, Eval) :-
		Eval = 0,
		!.
tree_eval(Value, V, Eval) :-
		Eval = V.

	

