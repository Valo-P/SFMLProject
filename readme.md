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

git clone https://github.com/Valo-P/SFMLProject.git

2. Naviguez vers le répertoire du projet :

cd SFMLProject

3. Construisez le projet :

mkdir build
cd build
cmake ..
make

## Exécution du SFMLProject

Pour exécuter SFMLProject, naviguez vers le répertoire bin/ et exécutez l'exécutable SFMLProject :

cd bin
./SFMLProject