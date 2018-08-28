# Corewar

## Objectif

Créer une arène virtuelle dans laquelle vont s'affronter des programmes, les champions, écrits dans un langage assembleur spécifique.

## Partie 1 : L'assembleur

L'assembleur permet de compiler des programmes afin qu'ils deviennent compréhensibles par la VM. Il est donc utilisé pour transformer en bytecode les champions conçus par les joueurs. L'asm génère un fichier ".cor" à partir du fichier ".s" écrit par le joueur, qui pourra être lu par la VM.

*Usage: ./asm [-vab] <source-file.s>*

## Partie 2 : La machine virtuelle (VM)

La machine virtuelle constitue l'environnement où vont s'affronter les champions. Elle comporte une mémoire circulaire de 4096 octets et ne peut exécuter qu'un jeu d'instructions prédéterminées, écrites en bytecode. Les champions sont chargés en mémoire au début de la partie.

![start](https://user-images.githubusercontent.com/29833564/44538805-bef06980-a702-11e8-8e76-68500f9da807.png)

Les processus de chaque champions sont ensuite exécutés tour à tour de manière équitable, en tenant compte du nombre de cycles nécessaire à l'exécution de chaque instruction. Les processus des joueurs peuvent écrire dans l'arène, stocker une valeur dans un registre, ou encore se dupliquer. Ils doivent régulièrement faire des "live" pour ne pas être mis à mort.

![middle](https://user-images.githubusercontent.com/29833564/44538804-bef06980-a702-11e8-9b8d-7bf221c90aa4.png)

La partie se déroule jusqu'à ce qu'il n'y ait plus aucun processus en vie. La VM détermine alors le vainqueur, qui est le dernier champion à avoir été déclaré vivant.

*Usage: ./corewar [-a -d N -s N -v N | -visu] [-n N] <champion1.cor> [-n N] <champion2.cor> <...>*
