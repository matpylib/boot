go:-
	write('good morning!'),
	nl,
	hypothesis(Disease),
	write('Hello bro, you have '),
	write(Disease).

hypothesis(cold):-
	symptom(fever),
	symptom(cough),nl,
	write("Please take anticold tablets"),nl,!.
	
hypothesis(malaria):-
	symptom(fever),
	symptom(sweating),
	symptom(headache),nl,
	write("Please take Quinine"),nl,!.

symptom(S):-
	write("Do you have symptom "),
	write(S),
	write(" (y/n) ?"),nl,
	read(Response),nl,
	(Response == 'y' -> true ; fail).
	
	
	
