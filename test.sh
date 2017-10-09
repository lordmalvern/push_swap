# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/08 22:09:41 by bpuschel          #+#    #+#              #
#    Updated: 2017/10/08 22:43:52 by bpuschel         ###   ########.fr        #
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
SUM="0"
while [ $i -lt 100 ]
do
	j="0"
	declare -a ARR1
	while [ $j -lt 5 ]
	do
		ARR1[$j]=$RANDOM
		ARR1=(`echo "${ARR1[*]}" | tr ' ' '\n' | awk '!a[$0]++' | tr '\n' ' '`);
		if [ "$j" -gt "$[${#ARR1[*]}- 1]" ]
		then j=$[${#ARR1[*]} - 1]
		fi;
		j=$[$j+1]
	done;
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
	then echo "Exceeded max instructions on list: ${ARG3}\n"
		OVER=$[$OVER+1]
	fi;
	if [ "$NUM3" -gt "12" ];
	then echo "Number of instructions: ${RED}${NUM3}${NC}\n";
	else echo "Number of instructions: ${GREEN}${NUM3}${NC}\n";
	fi;
	if [ "$RES3" == "KO" ]
	then echo "KO on list: ${ARG3}\n"
	fi;
	if [ "$RES3" == "Error" ]
	then echo "Error on list ${ARG3}\n"
	fi;
	if [ "$RES3" == "OK" ];
	then OK=$[$OK+1]
	else KO=$[$KO+1]
	fi;
	SUM=$[$SUM+$NUM3]
	i=$[$i+1]
done
AVG=$[$SUM/100]
echo "Average number of instructions: ${AVG}\n"
echo "Number of lists exceeding max: ${OVER}\nMax instructions done: ${MAX}\nMin instructions: ${MIN}\nTotal OKs: ${OK}\nTotal KOs: ${KO}\n"
echo "100 Random Numbers 100 Times:\n"
i="0"
MAX="0"
MIN="100000000000"
OK="0"
KO="0"
OVER="0"
SUM="0"
while [ $i -lt 100 ]
do
	j="0"
	declare -a ARR2
	while [ $j -lt 100 ]
	do
		ARR2[$j]=$RANDOM
		ARR2=(`echo "${ARR2[*]}" | tr ' ' '\n' | awk '!a[$0]++' | tr '\n' ' '`);
		if [ "$j" -gt "$[${#ARR2[*]}- 1]" ]
		then j=$[${#ARR2[*]}- 1]
		fi;
		j=$[$j+1]
	done;
	ARG3=`echo ${ARR2[*]}`
	NUM3=`./push_swap $ARG3 | wc -l`
	RES3=`./push_swap $ARG3 | ./checker $ARG3`
	if [ "$NUM3" -gt "$MAX" ];
	then MAX="$NUM3"
	fi;
	if [ "$NUM3" -lt "$MIN" ]
	then MIN="$NUM3"
	fi;
	if [ "$NUM3" -gt "700" ]
	then echo "${RED}Exceeded max instructions on list: ${ARG3}${NC}\n"
		OVER=$[$OVER+1]
	fi;
	if [ "$NUM3" -gt "700" ];
	then echo "Number of instructions: ${RED}${NUM3}${NC}\n";
	else echo "Number of instructions: ${GREEN}${NUM3}${NC}\n";
	fi;
	if [ "$RES3" == "KO" ]
	then echo "${RED}KO on list: ${ARG3}${NC}\n"
	fi;
	if [ "$RES3" == "Error" ]
	then echo "${RED}Error on list ${ARG3}${NC}\n"
	fi;
	if [ "$RES3" == "OK" ];
	then OK=$[$OK+1]
	else KO=$[$KO+1]
	fi;
	SUM=$[$SUM+$NUM3]
	i=$[$i+1]
done
AVG=$[$SUM/100]
echo "Average number of instructions: ${AVG}\n"
echo "Number of lists exceeding max: ${OVER}\nMax instructions done: ${MAX}\nMin instructions done: ${MIN}\nTotal OKs: ${OK}\nTotal KOs: ${KO}\n"
echo "500 Random Numbers 100 Times:\n"
i="0"
MAX="0"
MIN="100000000000"
OK="0"
KO="0"
OVER="0"
SUM="0"
while [ $i -lt 100 ]
do
	j="0"
	declare -a ARR2
	while [ $j -lt 500 ]
	do
		ARR2[$j]=$RANDOM
		ARR2=(`echo "${ARR2[*]}" | tr ' ' '\n' | awk '!a[$0]++' | tr '\n' ' '`);
		if [ "$j" -gt "$[${#ARR2[*]}- 1]" ]
		then j=$[${#ARR2[*]}- 1]
		fi;
		j=$[$j+1]
	done;
	ARG3=`echo ${ARR2[*]}`
	NUM3=`./push_swap $ARG3 | wc -l`
	RES3=`./push_swap $ARG3 | ./checker $ARG3`
	if [ "$NUM3" -gt "$MAX" ];
	then MAX="$NUM3"
	fi;
	if [ "$NUM3" -lt "$MIN" ]
	then MIN="$NUM3"
	fi;
	if [ "$NUM3" -gt "5300" ]
	then echo "${RED}Exceeded max instructions on list: ${ARG3}${NC}\n"
		OVER=$[$OVER+1]
	fi;
	if [ "$NUM3" -gt "5300" ];
	then echo "Number of instructions: ${RED}${NUM3}${NC}\n";
	else echo "Number of instructions: ${GREEN}${NUM3}${NC}\n";
	fi;
	if [ "$RES3" == "KO" ]
	then echo "${RED}KO on list: ${ARG3}${NC}\n"
	fi;
	if [ "$RES3" == "Error" ]
	then echo "${RED}Error on list ${ARG3}${NC}\n"
	fi;
	if [ "$RES3" == "OK" ];
	then OK=$[$OK+1]
	else KO=$[$KO+1]
	fi;
	SUM=$[$SUM+$NUM3]
	i=$[$i+1]
done
AVG=$[$SUM/100]
echo "Average number of instructions: ${AVG}\n"
echo "Number of lists exceeding max: ${OVER}\nMax instructions done: ${MAX}\nMin instructions done: ${MIN}\nTotal OKs: ${OK}\nTotal KOs: ${KO}\n"
echo "${GREEN}-----TESTS COMPLETE-----${NC}\n"
