# snake_game
snake game 


Documentation : Développement du Snake en C (Mode Projet)
Introduction
Ce projet consiste en la création d'un jeu Snake classique en mode console. L'objectif pédagogique est de maîtriser la gestion d'un environnement de rendu textuel, la logique de collision, et l'utilisation de Git/GitHub pour le versionnage.

Architecture du Code
Le programme suit une boucle de jeu standard (Game Loop) :

Setup() : Initialisation des variables (score, position du serpent, premier fruit).

Draw() : Rendu graphique en ASCII. Utilisation de goToXY pour éviter le scintillement (flicker).

Input() : Capture asynchrone des touches (Z, Q, S, D).

Logic() : Mise à jour des coordonnées, gestion de la croissance de la queue et détection des collisions (murs ou corps).Documentation : Développement du Snake en C (Mode Projet)
Introduction
Ce projet consiste en la création d'un jeu Snake classique en mode console. L'objectif pédagogique est de maîtriser la gestion d'un environnement de rendu textuel, la logique de collision, et l'utilisation de Git/GitHub pour le versionnage.

Architecture du Code
Le programme suit une boucle de jeu standard (Game Loop) :

Setup() : Initialisation des variables (score, position du serpent, premier fruit).

Draw() : Rendu graphique en ASCII. Utilisation de goToXY pour éviter le scintillement (flicker).

Input() : Capture asynchrone des touches (Z, Q, S, D).

Logic() : Mise à jour des coordonnées, gestion de la croissance de la queue et détection des collisions (murs ou corps).



-----------------------------------------------------------------------------------------------------------


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


C'est un excellent projet pour pratiquer la manipulation des structures de données et la gestion du matériel. Cependant, petit point d'attention : votre code actuel utilise des bibliothèques spécifiques à Windows (`windows.h`, `conio.h`). Pour le faire fonctionner sur **EndeavourOS (Linux)**, il faudra effectuer quelques ajustements (remplacer `Sleep` par `usleep` et simuler `kbhit`).

Voici la documentation complète structurée pour votre projet Git.

---

## 1. Documentation : Développement du Snake en C (Mode Projet)

### Introduction

Ce projet consiste en la création d'un jeu Snake classique en mode console. L'objectif pédagogique est de maîtriser la gestion d'un environnement de rendu textuel, la logique de collision, et l'utilisation de **Git/GitHub** pour le versionnage.

### Architecture du Code

Le programme suit une boucle de jeu standard (*Game Loop*) :

1. **Setup()** : Initialisation des variables (score, position du serpent, premier fruit).
2. **Draw()** : Rendu graphique en ASCII. Utilisation de `goToXY` pour éviter le scintillement (flicker).
3. **Input()** : Capture asynchrone des touches (Z, Q, S, D).
4. **Logic()** : Mise à jour des coordonnées, gestion de la croissance de la queue et détection des collisions (murs ou corps).

### Flux de Travail Git (Workflow)

Pour ce projet, nous adoptons une approche structurée :

* **Main Branch** : Version stable et jouable.
* **Features Branches** : Développement de fonctionnalités spécifiques (ex: `feat/logic-collision`, `feat/linux-port`).
* **Commits** : Messages clairs (ex: `fix: correction du bug de collision sur les bords`).

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

Note : Pour Linux, assurez-vous d'avoir adapté les fonctions `Sleep()` en `usleep()` et d'utiliser une alternative à `conio.h`.

```bash
gcc -o snake snake.c

```

### Lancement

```bash
./snake

```

## 🎮 Commandes

* **fleche haut / Z** : Haut
* **fleche gauche / Q** : Gauche
* **fleche bas / S** : Bas
* ** fleche droite / D** : Droite
* **X** : Quitter le jeu

```

---

## 3. Résumé : Projet snake game

Projet de jeu Snake en langage C utilisant la console pour l'affichage graphique en caractères ASCII. Le système gère les déplacements du serpent, la génération aléatoire de nourriture et l'évolution de la taille du serpent à chaque point marqué. Le score est mis à jour en temps réel et affiché sous la zone de jeu, avec une gestion fluide des entrées clavier pour diriger l'entité.

La logique du jeu intègre deux conditions de défaite critiques : la collision avec les bordures de la fenêtre et l'autocollision du serpent avec sa propre queue. Le développement a été structuré de manière modulaire (Setup, Draw, Input, Logic) pour faciliter la maintenance et l'évolution du code. L'utilisation de Git et GitHub a permis un versionnage efficace du projet, assurant le suivi des modifications et la gestion du code source. Le rendu visuel a été optimisé par une gestion directe du curseur (goToXY) afin d'éliminer le scintillement de l'écran, offrant ainsi une expérience de jeu fluide sur terminal.

---

### 💡 Conseil pour votre environnement Linux (EndeavourOS)
Comme votre code utilise `windows.h`, il ne compilera pas nativement sur votre système. Voici les deux changements rapides à faire :
1.  **Sommeil** : Remplacez `#include <windows.h>` par `#include <unistd.h>` et utilisez `usleep(40000);` au lieu de `Sleep(40);`.
2.  **Entrées clavier** : `conio.h` n'existe pas sous Linux. Pour un mode projet propre, je vous conseille d'utiliser la bibliothèque **ncurses** (`sudo pacman -S ncurses`), qui est le standard Linux pour faire des interfaces textuelles et des jeux en console.

```



----------------------------------------------------


Puisque tu es sur **EndeavourOS** (basé sur Arch Linux), ton code actuel ne compilera pas directement car il contient des bibliothèques réservées à Windows (`windows.h` et `conio.h`).

Pour que ton projet fonctionne sur ton système, voici la marche à suivre en deux étapes : d'abord adapter le code, puis utiliser le terminal pour le compiler.

---

### 1. Adaptation du code pour Linux

Ouvre ton fichier `snake.c` et remplace les parties spécifiques à Windows par des équivalents Linux. Voici les changements nécessaires :

* **Remplacer les headers :**
* Supprime `#include <windows.h>` et `#include <conio.h>`.
* Ajoute `#include <unistd.h>` (pour la fonction sleep).
* Ajoute `#include <termios.h>` et `#include <fcntl.h>` (pour remplacer `_kbhit()`).


* **Remplacer `Sleep(40)` :**
Utilise `usleep(40000);` (le temps est en microsecondes sous Linux).
* **Remplacer `system("cls")` :**
Utilise `system("clear");`.

---

### 2. Compilation et Lancement

Une fois le code adapté, ouvre ton terminal dans le dossier du projet et utilise les commandes suivantes :

#### A. Installer le compilateur (si tu ne l'as pas déjà)

```bash
sudo pacman -S base-devel

```

#### B. Compiler le programme

On utilise `gcc` (GNU Compiler Collection). On donne un nom au fichier de sortie avec l'option `-o`.

```bash
gcc snake.c -o snake_game

```

#### C. Lancer le jeu

Une fois la compilation réussie, un fichier exécutable nommé `snake_game` sera créé. Lance-le avec :

```bash
./snake_game

```

---

### 💡 Astuce pour Git

Comme tu travailles en "mode projet", n'oublie pas d'ajouter ton fichier exécutable dans ton `.gitignore` pour ne pas envoyer le binaire sur GitHub, seulement ton code source :

```bash
echo "snake_game" >> .gitignore
git add snake.c .gitignore
git commit -m "feat: adaptation du code pour Linux et script de compilation"
git push origin main

```

**Note :** Si tu trouves que la gestion du clavier est trop complexe sans `conio.h`, la solution "pro" sur Linux est d'utiliser la bibliothèque **ncurses** (`sudo pacman -S ncurses`). Elle gère nativement le clavier et l'affichage console sans scintillement.
