#!/bin/sh

if [ $# -le 1 ]
then
	make
	make bonus
	
	if [ $# -eq 1 ]
	then
		NBR_TESTS=$1
	else
		NBR_TESTS=5 #default value
	fi

	echo "Test with 5 numbers"
	while [ $NBR_TESTS -ge 1 ]
	do
		ARG=`ruby -e "puts (0..4).to_a.shuffle.join(' ')"`
		NBR=$(./push_swap $ARG | wc -l)
		RES=$(./push_swap $ARG | ./checker $ARG)
		echo "$NBR -> $RES"
		if [ $RES == "KO" ]
		then
			echo "\tyour program failed to sort $ARG"
		fi
		NBR_TESTS=$((NBR_TESTS-1))
	done

	if [ $# -eq 1 ]
	then
		NBR_TESTS=$1
	else
		NBR_TESTS=5 #default value
	fi

	echo "Test with 10 numbers"
	while [ $NBR_TESTS -ge 1 ]
	do
		ARG=`ruby -e "puts (0..9).to_a.shuffle.join(' ')"`
		NBR=$(./push_swap $ARG | wc -l)
		RES=$(./push_swap $ARG | ./checker $ARG)
		echo "$NBR -> $RES"
		if [ $RES == "KO" ]
		then
			echo "\tyour program failed to sort $ARG"
		fi
		NBR_TESTS=$((NBR_TESTS-1))
	done

	if [ $# -eq 1 ]
	then
		NBR_TESTS=$1
	else
		NBR_TESTS=5 #default value
	fi

	echo "Test with 50 numbers"
	while [ $NBR_TESTS -ge 1 ]
	do
		ARG=`ruby -e "puts (0..49).to_a.shuffle.join(' ')"`
		NBR=$(./push_swap $ARG | wc -l)
		RES=$(./push_swap $ARG | ./checker $ARG)
		echo "$NBR -> $RES"
		if [ $RES == "KO" ]
		then
			echo "\tyour program failed to sort $ARG"
		fi
		NBR_TESTS=$((NBR_TESTS-1))
	done

	if [ $# -eq 1 ]
	then
		NBR_TESTS=$1
	else
		NBR_TESTS=5 #default value
	fi

	echo "Test with 100 numbers"
	while [ $NBR_TESTS -ge 1 ]
	do
		ARG=`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`
		NBR=$(./push_swap $ARG | wc -l)
		RES=$(./push_swap $ARG | ./checker $ARG)
		echo "$NBR -> $RES"
		if [ $RES == "KO" ]
		then
			echo "\tyour program failed to sort $ARG"
		fi
		NBR_TESTS=$((NBR_TESTS-1))
	done

	if [ $# -eq 1 ]
	then
		NBR_TESTS=$1
	else
		NBR_TESTS=5 #default value
	fi

	echo "Test with 500 numbers"
	while [ $NBR_TESTS -ge 1 ]
	do
		ARG=`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`
		NBR=$(./push_swap $ARG | wc -l)
		RES=$(./push_swap $ARG | ./checker $ARG)
		echo "$NBR -> $RES"
		if [ $RES == "KO" ]
		then
			echo "\tyour program failed to sort $ARG"
		fi
		NBR_TESTS=$((NBR_TESTS-1))
	done
elif [ $# -eq 2 ]
then
	NBR_TESTS=$1
	MIN=6000
	MAX=0
	echo "Test with $2 numbers"
	while [ $NBR_TESTS -ge 1 ]
	do
		ARG=`ruby -e "puts (1..$2).to_a.shuffle.join(' ')"`
		NBR=$(./push_swap $ARG | wc -l)
		RES=$(./push_swap $ARG | ./checker_Mac $ARG)
		echo "$NBR -> $RES"
		if [ $RES == "KO" ]
		then
			echo "\tyour program failed to sort $ARG"
		fi
		if [ MIN -ge $((NBR)) ]
		then
			MIN=$NBR
		fi
		if [ MAX -le $NBR ]
		then
			MAX=$NBR
		fi
		NBR_TESTS=$((NBR_TESTS-1))
	done
	echo $MIN
	echo $MAX
else
	echo "wrong nbr of args."
fi