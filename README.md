# Corewar

Objectif: Créer une arène virtuelle dans laquelle vont s'affronter des programmes, les champions, écrits dans un langage assembleur spécifique.

•	Partie 1 : L'assembleur
L'assembleur permet de compiler des programmes afin qu'ils deviennent compréhensibles par la VM. Il est donc utilisé pour transformer en bytecode les champions conçus par les joueurs. Usage: ./asm [-vab] <source-file.s>
L'asm génère un fichier ".cor" à partir des fichiers ".s" écrit par le joueur qui pourra être lu par la VM.

•	Partie 2 : La machine virtuelle (VM)
La machine virtuelle constitue l'environnement où vont s'affronter les champions. Elle ne peut exécuter qu'un jeu d'instructions prédéterminées, écrites en bytecode. La mémoire circulaire de la VM constitue l'arène dans laquelle sont chargés les champions.
![start](https://user-images.githubusercontent.com/29833564/44538805-bef06980-a702-11e8-8e76-68500f9da807.png)

Les processus de chaque champions sont ensuite exécutés tour à tour de manière équitable, en tenant compte du nombre de cycles nécessaires à l'exécution de chaque instruction.
![middle](https://user-images.githubusercontent.com/29833564/44538804-bef06980-a702-11e8-9b8d-7bf221c90aa4.png)

La partie continue jusqu'à ce qu'il n'y ait plus aucun process en vie. La VM détermine alors le vainqueur, qui est le dernier champion à avoir été déclaré vivant.
![end](https://user-images.githubusercontent.com/29833564/44538803-bef06980-a702-11e8-9cd7-9d4ceac15f58.png)


