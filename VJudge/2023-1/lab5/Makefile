run-%:
	g++ -g $*.cpp
	./a.out < input/$*.txt
debug-%:
	g++ -g $*.cpp
	gbd -ex "run < input/$*.txt" ./a.out
