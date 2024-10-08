# Exercice 1
## Question 2
Dans le premier cas, on a nos 3 variables pi, e et p qui en mémoire du début à la fin. 
Lors des appels de print_bool, une variable p sera initialisée puis libérée après l'appel.

Dans le second cas, on a nos variables globales et dans le main qui resterontr jusqu'à la fin : x, y. p et z.
Lors de l'appel de f, il y aura les variables locales x et y qui seront présentes le temps de l'exécution de f. 

## Question 4
nmax est tout le temps la même
n et *nmax sont prédictibles
&nmax &n est imprévisible

## Question 5
```
Debut de l'appel de f(0, _)
n = 0
&n = ?
nmax = adresse de N
*nmax = 2
&nmax = ?
Debut de l'appel de f(1, _)
n = 1
&n = ?
nmax = adresse de N
*nmax = 2
&nmax = ?
Debut de l'appel de f(2, _)
n = 2
&n = ?
nmax = adresse de N
*nmax = 2
&nmax = ?
Fin de l'appel de f(2, _)
Fin de l'appel de f(1, _)
Fin de l'appel de f(0, _)
```