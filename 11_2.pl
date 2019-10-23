go:-
          hypothesis(Disease),
          write("The System suggests that the patient has "),
          write(Disease),
          write("disease."),nl,
          undo;
          write("System is unable to suggest "),nl,undo.
          
hypothesis(cold):-
symptom(fever),
symptom(cough),
symptom(headache),nl,
write("Take Azithramycin"),nl,
write("Take steam"),nl,!.

hypothesis(influenza):-
symptom(fever),
symptom(throat_infection),
symptom(runny_nose),nl,
write("Take Tamiflu"),nl,
write("Do gargling"),nl,!.

hypothesis(malaria):-
symptom(fever),
symptom(throat_infection),
symptom(vomiting),nl,
symptom(bodyache),nl,
write("Take Quinine"),nl,
write("Take bed rest!"),nl,!.

hypothesis(chicken_pox):-
symptom(fever),
symptom(rash),
symptom(bodyache),nl,
write("Take chickenpox vaccine"),nl,
write("Avoid public contact for few days!"),nl,!.

hypothesis(measles):-
symptom(fever),
symptom(rash),
symptom(conjunctivitis),nl,
write("Take measles vaccine"),nl,
write("Take bed rest!"),nl,!.

hypothesis(dengue):-
symptom(fever),
symptom(headache),nl,
symptom(rash),nl,
write("Take paracetamol"),nl,
write("Take bed rest!"),nl,!.

hypothesis(typhoid):-
symptom(fever),
symptom(abdominal_pain),
symptom(appetite_loss),nl,
symptom(diarrhea),nl,
write("Take Amhicillin"),nl,
write("Take balanced diet!"),nl,!.

ask(Question):-
write("Do the patient have symptom "),
write(Question),
write("?."),nl,
read(Response),
((Response==yes;Response=y)->assert(yes(Question));assert(no(Question)),fail).
:-dynamic yes/1,no/1.
          
symptom(S):-
(yes(S)->true;(no(S)->fail;ask(S))).          
          
undo:-retract(yes(_)),fail.
undo:-retract(no(_)),fail.
undo.
