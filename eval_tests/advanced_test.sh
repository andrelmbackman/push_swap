#!/bin/bash

GREEN='\033[0;32m'
RED='\033[0;31m'
BLUE='\033[0;34m'
YELLOW='\033[0;33m'
NC='\033[0m'
TIME='0.5'

echo -e -n "${BLUE}\nChecking with 100 random integers"
sleep $TIME
echo -n ' *'
sleep $TIME
echo -n ' *'
sleep $TIME
echo -e " *${NC}"

COUNT=1
POINTS=5
while (( $COUNT <= 100 ))
do
	ARG=$(python3 rand_nums.py -100 100 100)
	CHECK1=$(../push_swap $ARG | wc -l | tr -d " ")
	CHECK2=$(../push_swap $ARG | ../checker $ARG)
	if [ "$CHECK2" != "OK" ]; then
		echo -e "${RED}Error${NC}"
		echo "${CHECK2}: output should be \"OK\""
	else
		echo "count: ${CHECK1}"
	fi
	if [ $CHECK1 -ge 1500 ] && [ $POINTS -ge 0 ]; then
		POINTS=0
	elif [ $CHECK1 -ge 1300 ] && [ $POINTS -ge 1 ]; then
		POINTS=1
	elif [ $CHECK1 -ge 1100 ] && [ $POINTS -ge 2 ]; then
		POINTS=2
	elif [ $CHECK1 -ge 900 ] && [ $POINTS -ge 3 ]; then
		POINTS=3
	elif [ $CHECK1 -ge 700 ] && [ $POINTS -ge 4 ]; then
		POINTS=4
	elif [ $POINTS -ge 5 ]; then
		POINTS=5
	fi
	COUNT=$(( $COUNT + 1))
done

echo -e "${GREEN}points: ${POINTS}${NC}"

echo -e -n "${BLUE}\nChecking with 500 random integers [ INT_MIN - INT_MAX ]"
sleep $TIME
echo -n ' *'
sleep $TIME
echo -n ' *'
sleep $TIME
echo -e " *${NC}"

COUNT=1
POINTS=5
while (( $COUNT <= 100 ))
do
	ARG=$(python3 rand_nums.py -2147483648 2147483647 500)
	CHECK1=$(../push_swap $ARG | wc -l | tr -d " ")
	CHECK2=$(../push_swap $ARG | ../checker $ARG)
	if [ "$CHECK2" != "OK" ]; then
		echo -e "${RED}Error${NC}"
		echo "${CHECK2}: output should be \"OK\""
	else
		echo "count: ${CHECK1}"
	fi
	if [ $CHECK1 -ge 11500 ] && [ $POINTS -ge 0 ]; then
		POINTS=0
	elif [ $CHECK1 -ge 10000 ] && [ $POINTS -ge 1 ]; then
		POINTS=1
	elif [ $CHECK1 -ge 8500 ] && [ $POINTS -ge 2 ]; then
		POINTS=2
	elif [ $CHECK1 -ge 7000 ] && [ $POINTS -ge 3 ]; then
		POINTS=3
	elif [ $CHECK1 -ge 5500 ] && [ $POINTS -ge 4 ]; then
		POINTS=4
	elif [ $POINTS -ge 5 ]; then
		POINTS=5
	fi
	COUNT=$(( $COUNT + 1))
done
echo -e "${GREEN}points: ${POINTS}${NC}"