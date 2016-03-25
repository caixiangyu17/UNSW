likes(mary, pear).
likes(mary, grapes).
likes(tim, mango).
likes(tim, apple).
likes(jane, apple).
likes(jane, mango).
likes(leo, grapes).
likes(leo, watermelon).
likes(leo, mango).
test1(Id, List, Ans) :-
		sumsq_even(List, Ans1),
		Ans1 is Ans -> 
		writef('test%d..................pass\n', [Id]);
		writef('test%d..................failed\n', [Id]).

test2(Id, What, List, true) :-
		all_like(What, List) ->
		writef('test%d..................pass\n', [Id]);
		writef('test%d..................failed\n', [Id]).
test2(Id, What, List, false) :-
		all_like(What, List) ->
		writef('test%d..................failed\n', [Id]);
		writef('test%d................. pass\n', [Id]).
test3(Id, Start, End, false) :-
		sqrt_table(Start, End, Result) ->
		writef('test%d..................failed\n', [Id]);
		writef('test%d................. pass\n', [Id]),
		!.
test3(Id, Start, End, Ans) :-
		sqrt_table(Start, End, Result),
		Result == Ans ->
		writef('test%d..................pass\n', [Id]);
		writef('test%d................. failed\n', [Id]).
test4(Id, List, Ans) :-
		chop_down(List, Result),
		Result == Ans ->
		writef('test%d..................pass\n', [Id]);
		writef('test%d................. failed\n', [Id]).
test5(Id, Value, Tree, Ans) :-
		tree_eval(Value, Tree, Eval),
		Eval == Ans ->
		writef('test%d..................pass\n', [Id]);
		writef('test%d................. failed\n', [Id]).
test(1) :-
		writeln('------------Q1-------------'),
		test1(1, [1,3,5,2,-4,6,8,-7], 120),
		test1(2, [1,2,3,4], 20),
		test1(3, [1,5,3,7], 0),
		test1(4, [], 0).

test(2) :-
		writeln('------------Q2-------------'),
		test2(1, apple, [mary, tim], false),
		test2(2, grapes, [mary, tim], false),
		test2(3, pear, [], true),
		test2(4, apple, [tim], true), 
		test2(5, mango, [tim, leo], true),
		test2(6, mango, [tim, leo, mary], false).

test(3) :-
		writeln('------------Q3-------------'),
		test3(1, 7, 4, [[7, 2.6457513110645907], [6, 2.449489742783178], [5, 2.23606797749979], [4, 2.0]] ),
		test3(2, 4, 4, [[4, 2.0]]),
		test3(3, 3, 4, false).

test(4) :-
		writeln('------------Q4-------------'),
		test4(1, [1,3,7,6,5,10,9], [1,3,5,9]),
		test4(2, [1,2,3,4,5], [1,2,3,4,5]),
		test4(3, [], []),
		test4(4, [5,4,3,2,1], [1]),
		test4(5, [5,4,3,2,2], [2,2]),
		test4(6, [102,101,100,101,102,101,102,101,0,-1,-2,-1], [100,101,101,101,-2,-1]).

test(5):-
		writeln('------------Q5-------------'),
		test5(1, 2, tree(tree(empty,z,empty),
		'+',tree(tree(empty,1,empty),
		'/',tree(empty,z,empty))), 2.5),
		test5(2, 5, tree(tree(empty,z,empty),
		'+',tree(tree(empty,1,empty),
		'/',tree(empty,z,empty))), 5.2),
		test5(3, 100, tree(empty, 1, empty), 1),
		test5(4, 100, tree(empty, z, empty), 100),
		test5(5, 6,tree(tree(empty, 7, empty),
		'+', tree(tree(empty, 5, empty),
		'-', tree(empty, 3, empty))), 9),
		test5(6, 6,tree(tree(empty, z, empty),
		'+', tree(tree(empty, 5, empty),
		'-', tree(empty, 3, empty))), 8),
		test5(7, 20, empty, 0).

test(all) :-
		test(1),	
		test(2),	
		test(3),	
		test(4),	
		test(5).	


