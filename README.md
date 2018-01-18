# Simu_balle
## Cédric THOMAS & Hugo LORANT


##Description 

Ce projet consiste à simuler la position d'une balle à travers divers cas de figure : En premier calculer toutes les positions et en faire un fichier csv pour tracer des courbes sur un tableur. Ensuite une simulation d'une balle qui tombe et rebondi sur Terre. Une simulation de la gravitation dans l'espace d'une balle qui gravite autour de planètes. Et enfin le comportement d'une chaîne de balle reliées entres elles par des ressorts. Des informations sont données dans un fichier de configuration. 


## Utilisation 

Si vous êtes sous linux il faut compiler avec gcc de la façon suivante : ```gcc -Wall *.c -o "nomDuFichier" -lm -lSDL```

Il est impératif d'avoir la bibliothèque SDL d'installée sur votre ordinateur. Le -Wall est juste là au cas où il y aurait une erreur lié à votre machine puisque nos codes compilent sans warning ou erreurs. 

Une fois compilé, exepté pour le programme 1 (CSV) vous aurez besoin de des exécuter de la façon suivante : ```./"nomDuFichier" balle.txt```
Le fichier balle.txt est nativement présent dans les dossiers des programmes et contient les informations essentielles au bon déroulement des simulations.  Vous pouvez lui donner n'importe quel nom sauf dans le programme 1( CSV) le nom est défini dans le code.
