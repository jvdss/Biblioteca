P=a
bash solvestress.sh ${P}
bash solvestress.sh ${P}2
bash solvestress.sh gen
for ((i = 1; ; i++)) do
	./gen.out $i > in
	./${P}.out < in > out
	./${P}2.out < in > out2
	if (! cmp -s out out2) then
		echo "--> entrada:"
		cat in
		echo "--> saida1:"
		cat out
		echo "--> saida2:"
		cat out2
		break;
	fi
	echo $i
done
