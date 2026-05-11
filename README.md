# snake_game


# Snake Game - Console Edition (C Language)

Ce projet est une implémentation légère du célèbre jeu **Snake** développée en langage C. Il fonctionne directement dans le terminal en utilisant des caractères ASCII.

## 🎯 Objectif du Projet
L'objectif est de diriger le serpent (`O`) pour manger des fruits (`*`) afin d'augmenter son score. Le jeu s'arrête si le serpent touche les bords ou sa propre queue.

## 🛠️ Installation et Utilisation (Linux / EndeavourOS)

### Prérequis
Vous aurez besoin de `gcc` (le compilateur C). Sur EndeavourOS, installez-le via :
```bash
sudo pacman -S base-devel


-------------------------------------------------------


### Architecture du Code

Le programme suit une boucle de jeu standard (*Game Loop*) :

1. **Setup()** : Initialisation des variables (score, position du serpent, premier fruit).
2. **Draw()** : Rendu graphique en ASCII. Utilisation de `goToXY` pour éviter le scintillement (flicker).
3. **Input()** : Capture asynchrone des touches (Z, Q, S, D).
4. **Logic()** : Mise à jour des coordonnées, gestion de la croissance de la queue et détection des collisions (murs ou corps).

### Flux de Travail Git (Workflow)

---

## 2. README.md (Format Markdown)

```markdown
# Snake Game - Console Edition (C Language)

Ce projet est une implémentation légère du célèbre jeu **Snake** développée en langage C. Il fonctionne directement dans le terminal en utilisant des caractères ASCII.

## 🎯 Objectif du Projet
L'objectif est de diriger le serpent (`O`) pour manger des fruits (`*`) afin d'augmenter son score. Le jeu s'arrête si le serpent touche les bords ou sa propre queue.

## 🛠️ Installation et Utilisation (Linux / EndeavourOS)

### Prérequis
Vous aurez besoin de `gcc` (le compilateur C). Sur EndeavourOS, installez-le via :
```bash
sudo pacman -S base-devel

```

### Compilation


```bash
gcc -o snake snake.c

```

### Lancement

```bash
./snake

```

## 🎮 Commandes

* ** Z** : Haut
* **Q** : Gauche
* **S** : Bas
* ** D** : Droite
* **X** : Quitter le jeu
