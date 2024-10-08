## Question 3
- 1er cas :

Ici, la fonction `plus_petit` retourne la **valeur** la plus petite entre x et y, pas une **adresse**. Or la fonction `incremente` prend un pointeur en argument.
> Il y aura une erreur de type et le comportement ne sera, de toute facon, pas le bon.

---

- 2ème cas :

`x` et `y` sont des variables `locales` de `plus_petit`. Cela signifie que leurs adresses sont invalide en dehors de la fonction..

Cela revient donc à retourner un pointeur vers des variables qui n'existent plus.

---

- 3ème cas :

Pas de problème.

---

- 4ème cas :

`plus_petit` renvoie l'adresse d'une variable **locale**, elle sera alors détruite lors du renvoi de la fonction on aura donc le même problème que dans le 2ème cas.