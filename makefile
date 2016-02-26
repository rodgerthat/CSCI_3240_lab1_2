main: main.c
	gcc  -Wall  --std=c11  -pedantic  *.c  -o labDataRepresentation-norris
	#(echo "6"; echo "3")  | ./labDataRepresentation-norris  > output6_3.txt
	#diff  ./labDataRepresentation-answerKey6_3.txt  output6_3.txt
	#(echo "8"; echo "4")  | ./labDataRepresentation-norris  > output8_4.txt
	#diff  --side-by-side  ./labDataRepresentation-answerKey6_3.txt  output6_3.txt
