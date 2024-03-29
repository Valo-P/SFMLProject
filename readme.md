# SFMLProject

SFMLProject est un projet simple qui utilise la bibliothèque SFML.

## Prérequis

Avant de commencer, assurez-vous d'avoir satisfait aux exigences suivantes :

* Vous disposez d'une machine Linux/Mac. Les instructions ci-dessous sont pour Linux/Mac, et peuvent nécessiter des ajustements pour d'autres systèmes d'exploitation.

* Vous avez installé la dernière version de SFML. 

```bash
sudo apt-get install libsfml-dev
```

Ou vous pouvez la télécharger depuis le [site officiel de SFML](https://www.sfml-dev.org/download.php).

Dans le CMakeLists.txt, remplacer le répertoire vers le chemin ou est installé SFML. (Ligne 5)
```bash
set(SFML_DIR "/usr/lib/x86_64-linux-gnu/cmake/SFML")
```

* Vous avez installé GCC.

```bash
sudo apt-get install gcc
```

* Vous avez installé CMake et Make.

```bash
sudo apt-get install cmake
sudo apt-get install make
```

## Installation de SFMLProject

Pour installer SFMLProject, suivez ces étapes :

1. Clonez le dépôt :

```bash
git clone https://github.com/Valo-P/SFMLProject.git
```

2. Naviguez vers le répertoire du projet :

```bash
cd SFMLProject
```

3. Construisez le projet :

```bash
mkdir build
cd build
cmake ..
make
```

## Exécution du SFMLProject

Pour exécuter SFMLProject, naviguez vers le répertoire bin/ et exécutez l'exécutable SFMLProject :

```bash
cd bin
./SFMLProject
```