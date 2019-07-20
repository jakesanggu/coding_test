testfile=14502.cpp

test: $(testfile)
	g++ -g -o test $(testfile) -std=c++14

case:
	@read casenum;\
	cat ./cases/$$casenum | ./test;

clean:
	rm test
