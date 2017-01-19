# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    README.txt                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhismans <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/19 11:49:18 by hhismans          #+#    #+#              #
#    Updated: 2017/01/19 12:00:24 by hhismans         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

L'algo fonctionne mais n'est pas optimise du tout (temps "raisonable" jusque 12 tetraminos).
Au final je rentre plus tot que prevu du coup je finirai quand je reviens pour l'opti, on en parlera a deux.

En ce qui concerne ta partie, tu peux regarder a la ligne 136 de main.c.
j'utilise la fonction init() qui est hardcode pour l'instant.
Elle me cree une liste chainee de bricks, mais rentree a la main dans le code
Maintenant faut que ces brique vienne du fichier rentree en argument :p.
(exemple de prototype : 
t_bricks *init(char *filepath); //passer direct agrv 1
t_bricks *init(int **tab); // calculer ton tableau/les erreur plausible puis l'utiliser ici

enfin bref, comme tu le sens tant que les bricks sont dans la liste... bricks (et ouai !)
Bon courage.

cf : fillit.h pour la structure t_bricks
