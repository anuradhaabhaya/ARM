ARM
=== 

Projet ARM ISTY - INI2  




Les rapports doivent être individuels (un rapport par étudiant). Sauf mention contraire spécifiée avec le noyau, dans un groupe, un étudiant étudiera les performances en L1, un autre en L2 et le troisième en RAM. Pour les groupes de 4, le quatrième étudiera les performances en L3.    

Les mesures seront faites sur vos machines personnelles.   

Le sujet est en trois parties, la dernière étant hors barème (mais pouvant vous rapporter des points bonus).   

TRES IMPORTANT : Pour toutes les parties, vous devez justifier vos choix. Vous devez notamment expliquer pourquoi vous avez fait ainsi et pas autrement, et comment vous l'avez fait.   

Partie I
========
1) Ecrivez un driver permettant de mesurer la performance du noyau  
2) Compilez le noyau avec gcc -O2  
3) Mesurez la performance du noyau  
4) Recommencez avec gcc -O3, gcc -O3 -march=native, icc -O2, icc -O3 et icc -O3 -xHost.  
5) Recommencez avec d'autres options d'optimisation qui vous sembleraient pertinentes (vous devrez les chercher dans la documentation de gcc et d'icc), que vous pourrez combiner entre elles...  

Partie II
=========
Pour cette partie, sauf mention contraire précisée avec le noyau, vous compilerez avec gcc -O2.

1) Mesurez la performance du noyau   
2) Analysez le noyau avec MAQAO  et likwid-perfctr    
3) Identifiez le goulet d'étranglement (ce qui limite les performances)   
4) Proposez une optimisation (au niveau source)  
5) Recommencez (rebouclez à l'étape 1) tant que vous arrivez à améliorer les performances. Vous pouvez soit repartir du noyau non optimisé, soit d'un noyau précédemment optimisé    

La nature itérative de cette partie doit transparaître dans vos rapports autant que possible.   

Notamment, dites en quoi MAQAO et likwid-perfctr vous ont aidé pour les étapes 3 et 4. Dans le cas contraire, nous apprécierions que vous critiquiez (de façon justifiée et si possible constructive) ces outils avec preuves à l'appui.   

Pour l'étape 4, vous trouverez une liste assez exhaustive de transformations de boucles : http://en.wikipedia.org/wiki/Loop_optimization#Optimization_via_a_sequence_of_loop_transformations   

MAQAO permet l'analyse statique de codes x86. Il sera fourni sous forme d'un binaire exécutable uniquement sous Linux x86_64.

likwid-perfctr permet de mesurer, pendant l'exécution d'un programme, des compteurs matériels indiquant le comportement dynamique de ce dernier vis à vis de la mémoire, des unités de calcul... Page web officielle : http://code.google.com/p/likwid/wiki/LikwidPerfCtr

Partie III
==========
Cette partie est réservée aux plus courageux. Elle pourrait vous faire gagner jusqu'à 3 points supplémentaires.

1) Utilisez des directives OpenMP pour paralléliser votre noyau.
2) Utilisez des intrinsics pour écrire/optimiser le code (niveau avancé), voire modifiez directement l'assembleur (niveau expert).

