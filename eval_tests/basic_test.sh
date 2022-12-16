#!/bin/bash

GREEN='\033[0;32m'
RED='\033[0;31m'
BLUE='\033[0;34m'
YELLOW='\033[0;33m'
NC='\033[0m'
TIME='0.2'

make -C ../
sleep $TIME
echo -e -n "${BLUE}\nChecking Norminette"
sleep $TIME
echo -n ' *'
sleep $TIME
echo -n ' *'
sleep $TIME
echo -e " *${NC}"
CHECK=$(norminette ../src | grep -i error)
if [ "$CHECK" != "" ]; then
	echo -e "${RED}Error${NC}"
	echo "${CHECK}"
else
	echo -e "${GREEN}OK${NC}"
fi
CHECK=$(norminette ../includes | grep -i error)
sleep $TIME
if [ "$CHECK" != "" ]; then
	echo -e "${RED}Error${NC}"
	echo "${CHECK}"
else
	echo -e "${GREEN}OK${NC}"
fi
CHECK=$(norminette ../libft | grep -i error)
sleep $TIME
if [ "$CHECK" != "" ]; then
	echo -e "${RED}Error${NC}"
	echo "${CHECK}"
else
	echo -e "${GREEN}OK${NC}"
fi
sleep $TIME


echo -e -n "${BLUE}\nError checks"
sleep $TIME
echo -n ' *'
sleep $TIME
echo -n ' *'
sleep $TIME
echo -e " *${NC}"
sleep $TIME

CHECK=$(../checker)
if [ "$CHECK" != "" ]; then
	echo -e "${RED}Error${NC}"
	echo "${CHECK}: output should be empty when given no parameters"
else
	echo -e "${GREEN}OK${NC}"
fi
CHECK=$(../checker x 2>&1)
if [ "$CHECK" != "Error" ]; then
	echo -e "${RED}Error${NC}"
	echo "${CHECK}: output should display \"Error\" on the stderr [ ./checker x ]"
else
	echo -e "${GREEN}OK${NC}"
fi
sleep $TIME

CHECK=$(../push_swap)
if [ "$CHECK" != "" ]; then
	echo -e "${RED}Error${NC}"
	echo "${CHECK}: output should be empty when given no parameters"
else
	echo -e "${GREEN}OK${NC}"
fi
CHECK=$(../push_swap x 2>&1)
if [ "$CHECK" != "Error" ]; then
	echo -e "${RED}Error${NC}"
	echo "${CHECK}: output should display \"Error\" on the stderr[ ./push_swap x ]"
else
	echo -e "${GREEN}OK${NC}"
fi
sleep $TIME

CHECK=$(../checker 1 42 1 2>&1)
if [ "$CHECK" != "Error" ]; then
	echo -e "${RED}Error${NC}"
	echo "${CHECK}: output should display \"Error\" on the stderr [ ./checker 1 42 1 ]"
else
	echo -e "${GREEN}OK${NC}"
fi
CHECK=$(../checker 1 2 3 2147483647 2147483648 2>&1)
if [ "$CHECK" != "Error" ]; then
	echo -e "${RED}Error${NC}"
	echo "${CHECK}: output should display \"Error\" on the stderr [ ./checker 1 2 3 2147483647 2147483648 ]"
else
	echo -e "${GREEN}OK${NC}"
fi
sleep $TIME

CHECK=$(echo -n "pp" | ../checker 2 1 3 2>&1)
if [ "$CHECK" != "Error" ]; then
	echo -e "${RED}Error${NC}"
	echo "${CHECK}: output should display \"Error\" on the stderr [ echo -n \"pp\" | ./checker 2 1 3 ]"
else
	echo -e "${GREEN}OK${NC}"
fi
CHECK=$(echo -n "  sa  " | ../checker 2 1 3 2>&1)
if [ "$CHECK" != "Error" ]; then
	echo -e "${RED}Error${NC}"
	echo "${CHECK}: output should display \"Error\" on the stderr [ echo -n \"  sa \" | ./checker 2 1 3 ]"
else
	echo -e "${GREEN}OK${NC}"
fi
sleep $TIME

CHECK=$(printf "sa\npb\nrrr" | ../checker 0 9 1 8 2 7 3 6 4 5)
if [ "$CHECK" != "KO" ]; then
	echo -e "${RED}Error${NC}"
	echo "${CHECK}: should display \"KO\" [ printf \"sa\npb\nrrr\" | ./checker 0 9 1 8 2 7 3 6 4 5 ]"
else
	echo -e "${GREEN}OK${NC}"
fi
CHECK=$(printf "ss\npb\npb\nrrr" | ../checker 99 98 97 96 95 94 93 92 91 0 1 2 3)
if [ "$CHECK" != "KO" ]; then
	echo -e "${RED}Error${NC}"
	echo "${CHECK}: should display \"KO\" [ printf \"ss\npb\npb\nrrr\" | ./checker 99 98 97 96 95 94 93 92 91 0 1 2 3 ]"
else
	echo -e "${GREEN}OK${NC}"
fi
CHECK=$(printf "sa\npb\npb\nsb\nrr" | ../checker  9 10 1 2 3)
if [ "$CHECK" != "KO" ]; then
	echo -e "${RED}Error${NC}"
	echo "${CHECK}: should display \"KO\" [ printf \"sa\npb\npb\nsb\nrr\" | ./checker  9 10 1 2 3 ]"
else
	echo -e "${GREEN}OK${NC}"
fi

echo -e -n "${BLUE}\nBasic tests"
sleep $TIME
echo -n ' *'
sleep $TIME
echo -n ' *'
sleep $TIME
echo -e " *${NC}"
sleep $TIME

CHECK=$(echo -n | ../checker 0 1 2)
if [ "$CHECK" != "OK" ]; then
	echo -e "${RED}Error${NC}"
	echo "${CHECK}: should display \"OK\" [ ./checker 0 1 2 ]"
else
	echo -e "${GREEN}OK${NC}"
fi
CHECK=$(echo -n "sa" | ../checker 1 0 2)
if [ "$CHECK" != "OK" ]; then
	echo -e "${RED}Error${NC}"
	echo "${CHECK}: should display \"OK\" [ echo -n \"sa\" | ./checker 1 0 2 ]"
else
	echo -e "${GREEN}OK${NC}"
fi
sleep $TIME

CHECK=$(printf "pb\nra\npb\nra\nsa\nra\npa\npa" | ../checker  0 9 1 8 2)
if [ "$CHECK" != "OK" ]; then
	echo -e "${RED}Error${NC}"
	echo "${CHECK}: should display \"OK\" [ printf \"pb\nra\npb\nra\nsa\nra\npa\npa\" | ../checker  0 9 1 8 2 ]"
else
	echo -e "${GREEN}OK${NC}"
fi
CHECK=$(printf "rra\npb\nsa\npa" | ../checker 42 -42 73 -73)
if [ "$CHECK" != "OK" ]; then
	echo -e "${RED}Error${NC}"
	echo "${CHECK}: should display \"OK\" [ printf \"rra\npb\nsa\npa\" | ../checker 42 -42 73 -73 ]"
else
	echo -e "${GREEN}OK${NC}"
fi
CHECK=$(printf "ra\nra\npb\npb\nss\nra\npa\npa" | ../checker 9000 8000 -8000 -9000 7000)
if [ "$CHECK" != "OK" ]; then
	echo -e "${RED}Error${NC}"
	echo "${CHECK}: should display \"OK\" [ printf \"ra\nra\npb\npb\nss\nra\npa\npa\" | ../checker 9000 8000 -8000 -9000 7000 ]"
else
	echo -e "${GREEN}OK${NC}"
fi
sleep $TIME

CHECK=$(../push_swap 42)
if [ "$CHECK" != "" ]; then
	echo -e "${RED}Error${NC}"
	echo "${CHECK} != \"\" [ ../push_swap 42 ]"
else
	echo -e "${GREEN}OK${NC}"
fi
CHECK=$(../push_swap 0 1 2 3)
if [ "$CHECK" != "" ]; then
	echo -e "${RED}Error${NC}"
	echo "${CHECK} != \"\" [ ../push_swap 0 1 2 3 ]"
else
	echo -e "${GREEN}OK${NC}"
fi
CHECK=$(../push_swap 0 1 2 3 4 5 6 7 8 9)
if [ "$CHECK" != "" ]; then
	echo -e "${RED}Error${NC}"
	echo "${CHECK} != \"\" [ ../push_swap 0 1 2 3 4 5 6 7 8 9 ]"
else
	echo -e "${GREEN}OK${NC}"
fi
sleep $TIME

ARG="2 1 0"
CHECK1=$(../push_swap $ARG | ../checker $ARG)
CHECK2=$(../push_swap $ARG | wc -l | tr -d " ")
if [ "$CHECK1" != "OK" ]; then
	echo -e "${RED}Error${NC}"
	echo "./push_swap 2 1 0 | ./checker 2 1 0 did not print OK"
else
	echo -e "${GREEN}OK${NC}"
fi
CHECK3=$(../push_swap $ARG)
if [ "$CHECK2" != "2" ] && [ "$CHECK2" != "3" ]; then
	echo -e "${RED}Error${NC}"
	echo "./push_swap 2 1 0 failed by not giving 2 or 3 instructions:"
	echo "${CHECK3}"
else
	echo -e "${GREEN}OK${NC}"
fi