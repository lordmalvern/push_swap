# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/08 22:09:41 by bpuschel          #+#    #+#              #
#    Updated: 2017/08/27 15:21:01 by bpuschel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#!/bin/sh

make re || exit
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

echo "${GREEN}---BEGINNING OF TESTS---${NC}\n"
ARG1="2 1 0"
echo "Simple:\n"
NUM1=`./push_swap $ARG1 | wc -l`
if [ "$NUM1" -gt "3" ];
then echo "Number of instructions: ${RED}${NUM1}${NC}\n";
else echo "Number of instructions: ${GREEN}${NUM1}${NC}\n";
fi
RES1=`./push_swap $ARG1 | ./checker $ARG1`
if [ "$RES1" == "OK" ];
then echo "Result: ${GREEN}${RES1}${NC}\n";
else echo "Result: ${RED}${RES1}${NC}\n";
fi;
ARG2="1 5 2 4 3"
echo "Simple 2:\n"
NUM2=`./push_swap $ARG2 | wc -l`
if [ "$NUM2" -gt "12" ];
then echo "Number of instructions: ${RED}${NUM2}${NC}\n";
else echo "Number of instructions: ${GREEN}${NUM2}${NC}\n";
fi;
RES2=`./push_swap $ARG2 | ./checker $ARG2`
if [ "$RES2" == "OK" ];
then echo "Result: ${GREEN}${RES2}${NC}\n";
else echo "Result: ${RED}${RES2}${NC}\n";
fi;
echo "5 Random Numbers 100 Times:\n"
i="0"
MAX="0"
MIN="100000000000"
OK="0"
KO="0"
OVER="0"
while [ $i -lt 100 ]
do
	ARR1[0]=$RANDOM
	ARR1[1]=$RANDOM
	ARR1[2]=$RANDOM
	ARR1[3]=$RANDOM
	ARR1[4]=$RANDOM
	ARG3=`echo ${ARR1[*]}`
	NUM3=`./push_swap $ARG3 | wc -l`
	RES3=`./push_swap $ARG3 | ./checker $ARG3`
	if [ "$NUM3" -gt "$MAX" ];
	then MAX="$NUM3"
	fi;
	if [ "$NUM3" -lt "$MIN" ]
	then MIN="$NUM3"
	fi;
	if [ "$NUM3" -gt "12" ]
	then echo "Exceeded max instructions on list: ${ARG3}\nNumber of instructions: ${NUM3}\n"
		OVER=$[$OVER+1]
	fi;
	if [ "$RES3" == "KO" ]
	then echo "KO on list: ${ARG3}\n"
	fi;
	if [ "$RES3" == "OK" ];
	then OK=$[$OK+1]
	else KO=$[$KO+1]
	fi;
	i=$[$i+1]
done
echo "Number of lists exceeding max: ${OVER}\nMax instructions done: ${MAX}\nMin instructions: ${MIN}\nTotal OKs: ${OK}\nTotal KOs: ${KO}\n"
